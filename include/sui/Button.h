// 华勤科技版权所有 2010-2011
// 
// 文件名：Button.h
// 功  能：实现Win32标准的按钮，支持三态切换。
// 
// 作  者：汪荣
// 时  间：2010-07-02
// 
// ============================================================================

# ifndef _UIBUTTON_H_
# define _UIBUTTON_H_

#include <sui/sharpuiconfig.h>
#include <suic/framework/uicontentcontrol.h>

namespace ui
{

/// <summary>
///  选择事件，用于CheckButton以及其派生类
/// </summary>
class SHARPUI_API CheckedEventArg : public suic::RoutedEventArg
{
public:

    CheckedEventArg(bool val) 
        : bChecked(val)
        , RoutedEventArg(suic::ObjectPtr())
    {
    }

    bool IsChecked() 
    { 
        return bChecked; 
    }

public:

    // 选择标志
    bool bChecked;
};

class ButtonBase;

/// <summary>
/// 按钮点击事件代理对象
/// </summary>
typedef delegate<void(suic::Element*)> ClickEventHandler;

/// <summary>
/// 按钮的基类，接收点击事件的类可从其派生
/// </summary>
class SHARPUI_API ButtonBase : public suic::ContentControl
{
public:

    ButtonBase();
    virtual ~ButtonBase();

    DeclareAbstractTypeofInfo(ButtonBase, suic::ContentControl)

    // 鼠标点击事件
    ClickEventHandler Click;

    /// <summary>
    ///     鼠标单击事件
    /// </summary>
    /// <remarks>
    ///     仅仅鼠标左键释放后光标在元素之内才触发
    ///     此方法会调用Click外部注册事件
    /// </remarks>
    /// <param name="e">事件</param>
    /// <returns>无</returns>
    virtual void OnClick(suic::RoutedEventArg& e);

protected:

    suic::Size MeasureOverride(const suic::Size& size);

    void OnRender(suic::DrawingContext * drawing);

    void OnMouseMove(suic::MouseEventArg& e);
    void OnMouseLeftButtonDown(suic::MouseEventArg& e);
    void OnMouseLeftButtonUp(suic::MouseEventArg& e);
    void OnMouseLeftButtonDbclk(suic::MouseEventArg& e);
};

/// <summary>
/// 按钮实现，支持组合样式定义
/// </summary>
class SHARPUI_API Button : public ButtonBase
{
public:

    Button();
    virtual ~Button();

    DeclareTypeofInfo(Button, ButtonBase)

    virtual void OnInitialized();

protected:

    void OnRender(suic::DrawingContext * drawing);
    void OnKeyDown(suic::KeyboardEventArg& e);
    void OnMouseLeftButtonDown(suic::MouseEventArg& e);

protected:

    int nOffset;
};

typedef suic::shared<Button> ButtonPtr;

/// <summary>
/// 系统最小化按钮，实现单击最小化窗口
/// </summary>
class SHARPUI_API SystemMinButton : public Button
{
public:

    SystemMinButton();
    virtual ~SystemMinButton();

    DeclareTypeofInfo(SystemMinButton, Button)

    virtual void OnClick(suic::RoutedEventArg& e);
};

/// <summary>
/// 系统最大化和还原按钮，单击是可最大化或还原窗口
/// </summary>
class SHARPUI_API SystemMaxButton : public Button
{
public:

    SystemMaxButton();
    virtual ~SystemMaxButton();

    DeclareTypeofInfo(SystemMaxButton, Button)

    virtual void OnLoaded(suic::LoadedEventArg& e);
    virtual void OnClick(suic::RoutedEventArg& e);
    virtual void OnRender(suic::DrawingContext * drawing);

    virtual suic::Size MeasureOverride(const suic::Size& size);
};

/// <summary>
/// 系统关闭按钮，实现单击关闭窗口
/// </summary>
class SHARPUI_API SystemCloseButton : public Button
{
public:

    SystemCloseButton();
    virtual ~SystemCloseButton();

    DeclareTypeofInfo(SystemCloseButton, Button)

    virtual void OnClick(suic::RoutedEventArg& e);
};

}

# endif
