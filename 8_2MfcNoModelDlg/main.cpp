#include <afxwin.h>
#include "resource.h"
class CMyDlg : public CDialog {
	DECLARE_MESSAGE_MAP()
public:
	void OnZjwOK();
	void OnZjwCancel();
};
BEGIN_MESSAGE_MAP(CMyDlg, CDialog)
	ON_COMMAND(IDOK, OnZjwOK)
	ON_COMMAND(IDCANCEL, OnZjwCancel)
END_MESSAGE_MAP()
void CMyDlg::OnZjwCancel() {
	//	CDialog::OnCancel( );
	this->DestroyWindow();
}
void CMyDlg::OnZjwOK() {
	//	CDialog::OnOK();//只能将无模式对话框隐藏，并没有销毁。
	::DestroyWindow(this->m_hWnd);
}
class CMyWinApp : public CWinApp {
public:
	virtual BOOL InitInstance();
};
BOOL CMyWinApp::InitInstance() {
	CMyDlg* pdlg = new CMyDlg;
	pdlg->Create(IDD_DIALOG1);
	m_pMainWnd = pdlg;
	pdlg->ShowWindow(SW_SHOW);
	return TRUE;
}
CMyWinApp theApp;
