#include <afxwin.h>
class CMyFrameWnd : public CFrameWnd {
public:
	virtual LRESULT WindowProc(UINT msgID, WPARAM wParam, LPARAM);
};
LRESULT CMyFrameWnd::WindowProc(UINT msgID, WPARAM wParam, LPARAM lParam) {
	//此函数内部的this为pFrame
	switch (msgID) {
	case WM_CREATE:
		AfxMessageBox("WM_CREATE消息被处理");
		break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps = { 0 };
		HDC hdc = ::BeginPaint(this->m_hWnd, &ps);
		::TextOut(hdc, 100, 100, "hello", 5);
		::EndPaint(m_hWnd, &ps);
	}
	break;
	}
	return CFrameWnd::WindowProc(msgID, wParam, lParam);
}
class CMyWinApp : public CWinApp {
public:
	virtual BOOL InitInstance();
};

CMyWinApp theApp;//爆破点

BOOL CMyWinApp::InitInstance() {
	CMyFrameWnd* pFrame = new CMyFrameWnd;
	pFrame->Create(NULL, "MFCCreate");
	m_pMainWnd = pFrame;
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	return TRUE;
}