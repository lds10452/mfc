#include <afxwin.h>
#include "resource.h"
class CMyDlg : public CDialog {
public:
	DECLARE_MESSAGE_MAP()
	enum { IDD = IDD_DIALOG1 };
public:
	afx_msg void OnOK();
	afx_msg void OnBtn1();
	afx_msg void OnBtn2();
	afx_msg void OnDblClk();
	CMyDlg() : CDialog(IDD) {
	}
public:
	CString m_strEdit;//数据类型对象
	CEdit m_ctrlEdit;//控件类型对象
	virtual void DoDataExchange(CDataExchange* pDX);
};
BEGIN_MESSAGE_MAP(CMyDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, OnBtn1)
	ON_BN_CLICKED(IDC_BUTTON2, OnBtn2)
	/*	{ WM_COMMAND, (WORD)BN_CLICKED, (WORD)IDC_BUTTON2, (WORD)IDC_BUTTON2, AfxSigCmd_v,
			(static_cast< AFX_PMSG > (OnBtn1)) },*/
	ON_BN_CLICKED(IDOK, OnOK)
	ON_BN_DOUBLECLICKED(IDC_BUTTON2, OnDblClk)
	/*	{ WM_COMMAND, (WORD)BN_DOUBLECLICKED, (WORD)IDC_BUTTON2, (WORD)IDC_BUTTON2, AfxSigCmd_v,
			(static_cast< AFX_PMSG > (OnDblClk)) },*/
END_MESSAGE_MAP()
void CMyDlg::OnDblClk() {
	AfxMessageBox("双击了按钮");
}
void CMyDlg::OnBtn1() {//控件--》数据对象
	UpdateData(TRUE);
	AfxMessageBox(m_strEdit);
}
void CMyDlg::OnBtn2() {//数据对象--》控件
	m_strEdit = "hello world";
	UpdateData(FALSE);
}
void CMyDlg::DoDataExchange(CDataExchange* pDX) {
	DDX_Text(pDX, IDC_EDIT1, m_strEdit);//调用一系列DDX_xxx函数（类向导自动添加）
	DDX_Control(pDX, IDC_EDIT1, m_ctrlEdit);
}
void CMyDlg::OnOK() {
	m_ctrlEdit.MoveWindow(0, 0, 200, 200);
	//	CDialog::OnOK();
}
class CMyWinApp : public CWinApp {
public:
	virtual BOOL InitInstance();
};
BOOL CMyWinApp::InitInstance() {
	CMyDlg dlg;//栈空间
	m_pMainWnd = &dlg;
	int nRet = dlg.DoModal();
	return FALSE;//不再执行MFC库中安排的Run函数
}
CMyWinApp theApp;