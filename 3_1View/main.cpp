#include <afxwin.h>
#include "resource.h"

class CMyView : public CView {
	DECLARE_MESSAGE_MAP()
public:
	void OnDraw(CDC* pDC);//����ʵ�֣�����Ϊ�����࣬�ú����ᱻ����OnPaint�ڲ�����
	afx_msg void OnPaint();//������OnPaint���Ͳ�����ø���OnPaint���Ͳ������OnDraw
	afx_msg void OnNew();//���Բ˵������˳����ͼ->���->Ӧ�ó���
};

BEGIN_MESSAGE_MAP(CMyView, CView)
	ON_COMMAND( ID_NEW, OnNew )
	ON_WM_PAINT()
END_MESSAGE_MAP()

void CMyView::OnNew() {
	AfxMessageBox("��ͼ�ദ����WM_COMMAND��Ϣ");
}

void CMyView::OnPaint() {
	PAINTSTRUCT ps = { 0 };
	HDC hdc = ::BeginPaint(this->m_hWnd, &ps);
	::TextOut(hdc, 200, 200, "CMyView::OnPaint", strlen("CMyView::OnPaint"));
	::EndPaint(this->m_hWnd, &ps);
}

void CMyView::OnDraw(CDC* pDC) {
	pDC->TextOut(100, 100, "CMyView::OnDraw");
}

class CMyFrameWnd : public CFrameWnd {
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg int OnCreate(LPCREATESTRUCT pcs);
	afx_msg void OnNew();
};

BEGIN_MESSAGE_MAP(CMyFrameWnd, CFrameWnd)
	ON_WM_PAINT()
	ON_COMMAND( ID_NEW, OnNew )
	ON_WM_CREATE()
END_MESSAGE_MAP()

void CMyFrameWnd::OnNew() {
	AfxMessageBox("����ദ����WM_COMMAND��Ϣ");
}

int CMyFrameWnd::OnCreate(LPCREATESTRUCT pcs) {//��λ�ô�����ͼ����
	CMyView* pView = new CMyView;
	pView->Create(NULL, "MFCView", WS_CHILD | WS_VISIBLE | WS_BORDER, CRect(0, 0, 200, 200), this,
		AFX_IDW_PANE_FIRST);
	this->m_pViewActive = pView;//���û��ͼ���ڣ�������Ҫ�����ȷ��
	return CFrameWnd::OnCreate(pcs);
}

void CMyFrameWnd::OnPaint() {
	PAINTSTRUCT ps = { 0 };
	HDC hdc = ::BeginPaint(this->m_hWnd, &ps);
	::TextOut(hdc, 100, 100, "���ǿ�ܴ��ڿͻ���", strlen("���ǿ�ܴ��ڿͻ���"));
	::EndPaint(this->m_hWnd, &ps);
}

class CMyWinApp : public CWinApp {
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL InitInstance();
	afx_msg void OnNew();
};

BEGIN_MESSAGE_MAP(CMyWinApp, CWinApp)
	ON_COMMAND(ID_NEW, OnNew)
END_MESSAGE_MAP()

void CMyWinApp::OnNew() {
	AfxMessageBox("Ӧ�ó����ദ����WM_COMMAND��Ϣ");
}

BOOL CMyWinApp::InitInstance() {
	CMyFrameWnd* pFrame = new CMyFrameWnd;
	pFrame->Create(NULL, "MFCView", WS_OVERLAPPEDWINDOW, CFrameWnd::rectDefault,
		NULL, (CHAR*)IDR_MENU1);
	this->m_pMainWnd = pFrame;
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	return TRUE;
}
CMyWinApp theApp;