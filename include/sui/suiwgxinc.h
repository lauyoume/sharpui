// 华勤科技版权所有 2010-2011
// 
// 文件名：sharpuiinc.h
// 功  能：定义界面库的配置文件信息。
// 
// 作  者：汪荣
// 时  间：2010-07-02
// 
// ============================================================================

# ifndef _SHARPUIINC_H_
# define _SHARPUIINC_H_

#include <suic/suicoreinc.h>

#ifndef SHARPUI_LIB

#ifdef SUIWGX_EXPORTS
#define SHARPUI_API __declspec(dllexport)
#else
#define SHARPUI_API __declspec(dllimport)
#endif

#else

#define SHARPUI_API

#endif

//---------------------------------------------------

#ifndef SHARPUI_LIB

#ifdef _DEBUG
#pragma comment(lib, "suiwgxud.lib")
#else
#pragma comment(lib, "suiwgxu.lib")
#endif

#else

#ifdef _DEBUG
#pragma comment(lib, "suiwgxsud.lib")
#else
#pragma comment(lib, "suiwgxsu.lib")
#endif

#endif

//---------------------------------------------------

#include <sui/animatebox.h>
#include <sui/button.h>
#include <sui/captionbar.h>
#include <sui/wrappanel.h>
#include <sui/stackpanel.h>
#include <sui/stacklayout.h>
#include <sui/tabpanel.h>
#include <sui/progressbar.h>
#include <sui/checkbutton.h>
#include <sui/radiobutton.h>
#include <sui/scrollbar.h>
#include <sui/slider.h>
#include <sui/textblock.h>
#include <sui/itemscontrol.h>
#include <sui/combobox.h>
#include <sui/textbox.h>
#include <sui/label.h>
#include <sui/passwordbox.h>
#include <sui/listbox.h>
#include <sui/messagebox.h>
#include <sui/imagebox.h>
#include <sui/listview.h>
#include <sui/treeview.h>
#include <sui/scrollviewer.h>
#include <sui/menuitem.h>
#include <sui/menu.h>
#include <sui/separator.h>
#include <sui/tabcontrol.h>
#include <sui/tabitem.h>
#include <sui/ToolBarItem.h>

#include <sui/webbrowser.h>
#include <sui/filebrowser.h>
#include <sui/dirbrowser.h>

void SHARPUI_API uiInitialize();
void SHARPUI_API uiUninitialize();

# endif
