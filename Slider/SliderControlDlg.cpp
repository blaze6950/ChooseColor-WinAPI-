#include "SliderControlDlg.h"

CSliderControlDlg* CSliderControlDlg::ptr = NULL;

CSliderControlDlg::CSliderControlDlg(void)
{
	ptr = this;
}

void CSliderControlDlg::Cls_OnClose(HWND hwnd)
{
	EndDialog(hwnd, 0);
}

BOOL CSliderControlDlg::Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam) 
{
	hDialog = hwnd;
	hRed = GetDlgItem(hDialog, IDC_SLIDER1);
	hGreen = GetDlgItem(hDialog, IDC_SLIDER2);
	hBlue = GetDlgItem(hDialog, IDC_SLIDER3);
	hResult = GetDlgItem(hDialog, IDC_PROGRESS1);
	SendMessage(hRed, TBM_SETRANGE, TRUE, MAKELPARAM(MIN, MAX));
	SendMessage(hGreen, TBM_SETRANGE, TRUE, MAKELPARAM(MIN, MAX));
	SendMessage(hBlue, TBM_SETRANGE, TRUE, MAKELPARAM(MIN, MAX));
	return TRUE;
}

void CSliderControlDlg::Cls_OnHScroll(HWND hwnd, HWND hwndCtl, UINT code, int pos)
{
	static int red = 0, green = 0, blue = 0;
	int nCurrrentPosition = SendMessage(hwndCtl, TBM_GETPOS, 0, 0);
	if (hwndCtl == hRed)
	{
		red = nCurrrentPosition;
	}
	else if (hwndCtl == hGreen)
	{
		green = nCurrrentPosition;
	}
	else{
		blue = nCurrrentPosition;
	}
	SendMessage(hResult, PBM_SETBKCOLOR, 0, RGB(red,green,blue));
}


BOOL CALLBACK CSliderControlDlg::DlgProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message)
	{
		HANDLE_MSG(hwnd, WM_CLOSE, ptr->Cls_OnClose);
		HANDLE_MSG(hwnd, WM_INITDIALOG, ptr->Cls_OnInitDialog);
		HANDLE_MSG(hwnd, WM_HSCROLL, ptr->Cls_OnHScroll);
	}
	return FALSE;
}