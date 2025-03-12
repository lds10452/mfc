#include <afxwin.h>
#include "resource.h"

class CMyFrameWnd : public CFrameWnd {
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT pcs);
	afx_msg void OnNew();
	afx_msg void OnInitMenuPopup(CMenu* pPopup, UINT nPos, BOOL i);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint pt);
public:
	CMenu menu;
};

BEGIN_MESSAGE_MAP(CMyFrameWnd, CFrameWnd)
//	ON_COMMAND( ID_NEW, OnNew )
	ON_WM_CREATE()
	ON_WM_INITMENUPOPUP()
	ON_WM_CONTEXTMENU()
END_MESSAGE_MAP()

void CMyFrameWnd::OnContextMenu(CWnd* pWnd, CPoint pt) {
//	HMENU hPopup = ::GetSubMenu(menu.m_hMenu,0);
//	::TrackPopupMenu( hPopup, TPM_LEFTALIGN|TPM_TOPALIGN, pt.x, pt.y,
//										0, this->m_hWnd, NULL );
	CMenu* pPopup = menu.GetSubMenu(0);//获取菜单栏第一个项的下拉菜单
	pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_TOPALIGN, pt.x, pt.y, pWnd/*this*/); //pWnd===this
}

void CMyFrameWnd::OnInitMenuPopup(CMenu* pPopup, UINT nPos, BOOL i) {
//	pPopup->CheckMenuItem( ID_NEW, MF_CHECKED );
	::CheckMenuItem(pPopup->m_hMenu, ID_NEW, MF_CHECKED);//下拉菜单弹出后该菜单项会被选中
}

void CMyFrameWnd::OnNew() {
	AfxMessageBox("框架类处理了新建菜单项被点击");
}

int CMyFrameWnd::OnCreate(LPCREATESTRUCT pcs) {
	menu.LoadMenu(IDR_MENU1);//menu不能是局部变量，不然点击菜单项会崩溃
//	this->SetMenu( &menu );
	::SetMenu(this->m_hWnd, menu.m_hMenu);
	return CFrameWnd::OnCreate(pcs);
}

class CMyWinApp : public CWinApp {
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL InitInstance();
	afx_msg void OnNew();
};

BEGIN_MESSAGE_MAP(CMyWinApp, CWinApp)
	ON_COMMAND(ID_NEW, OnNew)//仅仅command消息可以在这里设置
END_MESSAGE_MAP()

void CMyWinApp::OnNew() {
	AfxMessageBox("应用程序类处理了新建被点击");//如果框架窗口也添加了处理函数，优先调框架窗口的
}

BOOL CMyWinApp::InitInstance() {
	CMyFrameWnd* pFrame = new CMyFrameWnd;
	pFrame->Create(NULL, "MFCCreate");
	m_pMainWnd = pFrame;
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	return TRUE;
}

CMyWinApp theApp;
