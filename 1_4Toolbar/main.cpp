#include <afxwin.h>
#include "resource.h"
#include <afxext.h>
class CMyFrameWnd : public CFrameWnd {
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnNew();
	afx_msg void OnSet();
	afx_msg int OnCreate(LPCREATESTRUCT pcs);
public:
	CToolBar toolbar;
};
BEGIN_MESSAGE_MAP(CMyFrameWnd, CFrameWnd)
	ON_COMMAND(ID_SET, OnSet)
	ON_COMMAND(ID_NEW, OnNew)
	ON_WM_CREATE()
END_MESSAGE_MAP()
void CMyFrameWnd::OnSet() {
	AfxMessageBox("��ɫ���߰�ť�����");
}
int CMyFrameWnd::OnCreate(LPCREATESTRUCT pcs) {
	toolbar.CreateEx(this, TBSTYLE_FLAT/*ƽ����ť*/, WS_CHILD | WS_VISIBLE | CBRS_ALIGN_TOP | CBRS_GRIPPER/*���϶��ֱ�*/);
	toolbar.LoadToolBar(IDR_TOOLBAR1);
	toolbar.EnableDocking(CBRS_ALIGN_ANY);//��ͣ��λ��
	this->EnableDocking(CBRS_ALIGN_ANY);//����ͣ��λ��
	this->DockControlBar(&toolbar, AFX_IDW_DOCKBAR_BOTTOM);//����ͣ��λ��
	return CFrameWnd::OnCreate(pcs);
}
void CMyFrameWnd::OnNew() {
	AfxMessageBox("�½��˵�����");
}
class CMyWinApp : public CWinApp {
public:
	virtual BOOL InitInstance();
};
BOOL CMyWinApp::InitInstance() {
	CMyFrameWnd* pFrame = new CMyFrameWnd;
	pFrame->Create(NULL, "MFCToolBar", WS_OVERLAPPEDWINDOW, CFrameWnd::rectDefault,
		NULL, (CHAR*)IDR_MENU1);
	m_pMainWnd = pFrame;
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	return TRUE;
}
CMyWinApp theApp;