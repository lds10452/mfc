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
	CString m_strEdit;//�������Ͷ���
	CEdit m_ctrlEdit;//�ؼ����Ͷ���
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
	AfxMessageBox("˫���˰�ť");
}
void CMyDlg::OnBtn1() {//�ؼ�--�����ݶ���
	UpdateData(TRUE);
	AfxMessageBox(m_strEdit);
}
void CMyDlg::OnBtn2() {//���ݶ���--���ؼ�
	m_strEdit = "hello world";
	UpdateData(FALSE);
}
void CMyDlg::DoDataExchange(CDataExchange* pDX) {
	DDX_Text(pDX, IDC_EDIT1, m_strEdit);//����һϵ��DDX_xxx�����������Զ���ӣ�
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
	CMyDlg dlg;//ջ�ռ�
	m_pMainWnd = &dlg;
	int nRet = dlg.DoModal();
	return FALSE;//����ִ��MFC���а��ŵ�Run����
}
CMyWinApp theApp;