#include <afxwin.h>
#include <afxext.h>
#include "resource.h"
class CMyDoc : public CDocument {
};

class CMyView : public CView {
	DECLARE_DYNCREATE(CMyView) //动态创建机制
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnDraw(CDC* pDC);
	afx_msg int OnCreate(LPCREATESTRUCT pcs);
};
IMPLEMENT_DYNCREATE(CMyView, CView)
BEGIN_MESSAGE_MAP(CMyView, CView)
	ON_WM_CREATE()
END_MESSAGE_MAP()

int CMyView::OnCreate(LPCREATESTRUCT pcs) {
	return CView::OnCreate(pcs); //将文档类对象和视图类对象建立关联关系。
}

void CMyView::OnDraw(CDC* pDC) {
	pDC->TextOut(100, 100, "我是视图窗口");
}

class CMyFrameWnd : public CFrameWnd {
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT pcs);
	afx_msg void OnPaint();
	virtual BOOL OnCreateClient(LPCREATESTRUCT pcs, CCreateContext* pContext);//实现窗口切分
	CSplitterWnd split;//不规则框架窗口
};
BEGIN_MESSAGE_MAP(CMyFrameWnd, CFrameWnd)
	ON_WM_PAINT()
	ON_WM_CREATE()
END_MESSAGE_MAP()

BOOL CMyFrameWnd::OnCreateClient(LPCREATESTRUCT pcs, CCreateContext* pContext) {
	//创建两个视图窗口
	split.CreateStatic(this, 1, 2);
	split.CreateView(0, 0, RUNTIME_CLASS(CMyView), CSize(100, 100), pContext);
	split.CreateView(0, 1, pContext->m_pNewViewClass, CSize(100, 100), pContext);
	return TRUE;
}

void CMyFrameWnd::OnPaint() {
	PAINTSTRUCT ps = { 0 };
	HDC hdc = ::BeginPaint(this->m_hWnd, &ps);
	::TextOut(hdc, 200, 200, "我是框架窗口客户区", strlen("我是框架窗口客户区"));
	::EndPaint(this->m_hWnd, &ps);
}

int CMyFrameWnd::OnCreate(LPCREATESTRUCT pcs) {
	return CFrameWnd::OnCreate(pcs);//动态创建视图类对象，并创建视图窗口
}

class CMyWinApp : public CWinApp {
public:
	virtual BOOL InitInstance();
};

BOOL CMyWinApp::InitInstance() {
	CMyFrameWnd* pFrame = new CMyFrameWnd;
	CMyDoc* pDoc = new CMyDoc;

	CCreateContext cct;
	cct.m_pCurrentDoc = pDoc;//文档类对象地址
	cct.m_pNewViewClass = RUNTIME_CLASS(CMyView);//&CMyView::classCMyView

	pFrame->LoadFrame(IDR_MENU1, WS_OVERLAPPEDWINDOW, NULL, &cct);//演示内部实现流程
	m_pMainWnd = pFrame;
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	return TRUE;
}
CMyWinApp theApp;



