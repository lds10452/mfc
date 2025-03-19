#include <afxwin.h>
#include "resource.h"

/// <注意>
/// 运行会报错，因为这里需要一个字符串资源，作为窗口的标题，添加一个字符串资源即可，值必须是61443，id为AFX_IDS_UNTITLED
/// </注意>

class CMyDoc : public CDocument {
	DECLARE_DYNCREATE(CMyDoc)
};
IMPLEMENT_DYNCREATE(CMyDoc, CDocument)

class CMyView : public CView {
	DECLARE_DYNCREATE(CMyView)
public:
	virtual void OnDraw(CDC* pDC);
};
IMPLEMENT_DYNCREATE(CMyView, CView)
void CMyView::OnDraw(CDC* pDC) {
	pDC->TextOut(100, 100, "我是视图窗口");
}

class CMyFrameWnd : public CFrameWnd {
	DECLARE_DYNCREATE(CMyFrameWnd)
};
IMPLEMENT_DYNCREATE(CMyFrameWnd, CFrameWnd)

class CMyWinApp : public CWinApp {
public:
	virtual BOOL InitInstance();
};
BOOL CMyWinApp::InitInstance() {
	CSingleDocTemplate* pTemplate = new CSingleDocTemplate(IDR_MENU1,
		RUNTIME_CLASS(CMyDoc),
		RUNTIME_CLASS(CMyFrameWnd),
		RUNTIME_CLASS(CMyView));
	AddDocTemplate(pTemplate);
	OnFileNew();
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}
CMyWinApp theApp;




