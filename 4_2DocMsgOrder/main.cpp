#include <afxwin.h>
#include <afxext.h>
#include "resource.h"

class CMyDoc : public CDocument {
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnNew();
	CString str;
};
BEGIN_MESSAGE_MAP(CMyDoc, CDocument)
	ON_COMMAND(ID_NEW, OnNew)
END_MESSAGE_MAP()

void CMyDoc::OnNew() {
	this->str = "hello world"; //���ܵ������ݡ�
//	this->UpdateAllViews( NULL );//ˢ�º�����ĵ������this��������������ͼ����
// 
	//this->m_viewList;
	POSITION pos = this->GetFirstViewPosition(); //GetFirstXXXPosition��ȡthis->m_viewListͷ�ڵ�ĵ�����λ��
	CView* pView = this->GetNextView(pos);   //GetNextXXX
	this->UpdateAllViews(pView);//ˢ�º�����ĵ������this�������ĳ���pViewָ�����ͼ����
}

class CMyView : public CView {
	DECLARE_DYNCREATE(CMyView) //��̬��������
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnDraw(CDC* pDC);
	afx_msg int OnCreate(LPCREATESTRUCT pcs);
	afx_msg void OnNew();
};
IMPLEMENT_DYNCREATE(CMyView, CView)
BEGIN_MESSAGE_MAP(CMyView, CView)
	//	ON_COMMAND( ID_NEW, OnNew )
	ON_WM_CREATE()
END_MESSAGE_MAP()

void CMyView::OnNew() {
	AfxMessageBox("��ͼ�ദ���WM_COMMAND��Ϣ");
}

int CMyView::OnCreate(LPCREATESTRUCT pcs) {
	return CView::OnCreate(pcs); //���ĵ���������ͼ�������������ϵ��
}

void CMyView::OnDraw(CDC* pDC) {
	//	CMyDoc* pDoc = (CMyDoc*)this->m_pDocument;
	CMyDoc* pDoc = (CMyDoc*)this->GetDocument();
	pDC->TextOut(100, 100, pDoc->str);
}

class CMyFrameWnd : public CFrameWnd {
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT pcs);
	afx_msg void OnPaint();
	virtual BOOL OnCreateClient(LPCREATESTRUCT pcs, CCreateContext* pContext);
	CSplitterWnd split;//�������ܴ���
	afx_msg void OnNew();
};
BEGIN_MESSAGE_MAP(CMyFrameWnd, CFrameWnd)
	//	ON_COMMAND( ID_NEW, OnNew)
	ON_WM_PAINT()
	ON_WM_CREATE()
END_MESSAGE_MAP()

void CMyFrameWnd::OnNew() {
	AfxMessageBox("����ദ�����½������");
}

BOOL CMyFrameWnd::OnCreateClient(LPCREATESTRUCT pcs, CCreateContext* pContext) {
	//����������ͼ����
	split.CreateStatic(this, 1, 2);
	split.CreateView(0, 0, RUNTIME_CLASS(CMyView), CSize(100, 100), pContext);
	split.CreateView(0, 1, pContext->m_pNewViewClass, CSize(100, 100), pContext);
	m_pViewActive = (CView*)split.GetPane(0, 0);
	return TRUE;
}

void CMyFrameWnd::OnPaint() {
	PAINTSTRUCT ps = { 0 };
	HDC hdc = ::BeginPaint(this->m_hWnd, &ps);
	::TextOut(hdc, 200, 200, "���ǿ�ܴ��ڿͻ���", strlen("���ǿ�ܴ��ڿͻ���"));
	::EndPaint(this->m_hWnd, &ps);
}

int CMyFrameWnd::OnCreate(LPCREATESTRUCT pcs) {
	return CFrameWnd::OnCreate(pcs);//��̬������ͼ����󣬲�������ͼ����
}

class CMyWinApp : public CWinApp {
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL InitInstance();
	afx_msg void OnNew();
};
BEGIN_MESSAGE_MAP(CMyWinApp, CWinApp)
	//	ON_COMMAND( ID_NEW, OnNew )
END_MESSAGE_MAP()

void CMyWinApp::OnNew() {
	AfxMessageBox("Ӧ�ó����ദ����WM_COMMAND��Ϣ");
}
BOOL CMyWinApp::InitInstance() {
	CMyFrameWnd* pFrame = new CMyFrameWnd;
	CMyDoc* pDoc = new CMyDoc;

	CCreateContext cct;
	cct.m_pCurrentDoc = pDoc;//�ĵ�������ַ
	cct.m_pNewViewClass = RUNTIME_CLASS(CMyView);//&CMyView::classCMyView

	pFrame->LoadFrame(IDR_MENU1, WS_OVERLAPPEDWINDOW, NULL, &cct);
	m_pMainWnd = pFrame;
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	return TRUE;
}
CMyWinApp theApp;



