#include <afxwin.h>
#include "resource.h"
class CMyDlg : public CDialog {
public:
	DECLARE_MESSAGE_MAP()
	enum { IDD = IDD_DIALOG1 };//��ŶԻ�����Դid
public:
	afx_msg void OnOK();
	CMyDlg() : CDialog(IDD) {
	}
};
BEGIN_MESSAGE_MAP(CMyDlg, CDialog)
	ON_COMMAND(IDOK, OnOK)
END_MESSAGE_MAP()
void CMyDlg::OnOK() {
	CDialog::OnOK();
}
class CMyWinApp : public CWinApp {
public:
	virtual BOOL InitInstance();
};
BOOL CMyWinApp::InitInstance() {
	CMyDlg dlg;//ջ�ռ�
	m_pMainWnd = &dlg;
	int nRet = dlg.DoModal();//�ڲ��Ի��򴰿���Ϣѭ����������
	return FALSE;//����ִ��MFC���а��ŵ�Run������Ϣѭ��
}
CMyWinApp theApp;