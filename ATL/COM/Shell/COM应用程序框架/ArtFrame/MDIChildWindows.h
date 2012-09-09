// This file was generated by WTL Dialog wizard 
// MDIChildWindows.h : Declaration of the CMDIChildWindows

#pragma once

#include "resource.h"       // main symbols
#include <atlddx.h>
#include <atlframe.h>
#include <atlcrack.h>
// CMDIChildWindows

class CMDIChildWindows : 
	public CDialogImpl<CMDIChildWindows>,
	public CWinDataExchange<CMDIChildWindows>,
	public CDialogResize<CMDIChildWindows>	
{
protected:
	CListViewCtrl m_wndListCtrl;
public:
	CMDIChildWindows();
	~CMDIChildWindows();
	enum { IDD = IDD_MDICHILDWINDOWS };

    BEGIN_MSG_MAP(CMDIChildWindows)
		MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
        COMMAND_HANDLER(IDOK, BN_CLICKED, OnClickedOK)
        COMMAND_HANDLER(IDCANCEL, BN_CLICKED, OnClickedCancel)
		COMMAND_ID_HANDLER_EX(IDC_Activate, OnButActivate)
		COMMAND_ID_HANDLER_EX(IDC_SAVE, OnButSave)
		COMMAND_ID_HANDLER_EX(IDOK, OnIdok)
		CHAIN_MSG_MAP(CDialogResize<CMDIChildWindows>)
    END_MSG_MAP()

	BEGIN_DDX_MAP(CMDIChildWindows)
		DDX_CONTROL_HANDLE(IDC_List_Windows, m_wndListCtrl)
	END_DDX_MAP()

	BEGIN_DLGRESIZE_MAP(CMDIChildWindows)
	END_DLGRESIZE_MAP()

    // Handler prototypes:
    //  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    //  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
    //  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);
	LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnClickedOK(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
	LRESULT OnClickedCancel(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
	LRESULT OnButActivate(WORD wNotifyCode, WORD wID, HWND hWndCtl);
	LRESULT OnButSave(WORD wNotifyCode, WORD wID, HWND hWndCtl);
	LRESULT OnIdok(WORD wNotifyCode, WORD wID, HWND hWndCtl);
	int InitListCtrl(void);
	int DataToListCtrl(void);
};


