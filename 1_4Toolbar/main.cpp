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
	AfxMessageBox("绿色工具按钮被点击");
}
int CMyFrameWnd::OnCreate(LPCREATESTRUCT pcs) {
	toolbar.CreateEx(this, TBSTYLE_FLAT/*平滑按钮*/, WS_CHILD | WS_VISIBLE | CBRS_ALIGN_TOP | CBRS_GRIPPER/*加拖动手柄*/);
	toolbar.LoadToolBar(IDR_TOOLBAR1);
	toolbar.EnableDocking(CBRS_ALIGN_ANY);//想停靠位置
	this->EnableDocking(CBRS_ALIGN_ANY);//允许停靠位置
	this->DockControlBar(&toolbar, AFX_IDW_DOCKBAR_BOTTOM);//最终停靠位置
	return CFrameWnd::OnCreate(pcs);
}
void CMyFrameWnd::OnNew() {
	AfxMessageBox("新建菜单项被点击");
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