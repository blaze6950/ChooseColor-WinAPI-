#include "SliderControlDlg.h"


int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrev, LPTSTR lpszCmdLine, int nCmdShow)
{
	INITCOMMONCONTROLSEX icc = {sizeof(INITCOMMONCONTROLSEX)};
	icc.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&icc);
	CSliderControlDlg dlg;
	return DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), NULL, CSliderControlDlg::DlgProc);
}