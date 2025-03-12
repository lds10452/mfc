#include <afxwin.h>
#define WM_MYMESSAGE WM_USER+1001 //�Զ�����Ϣ
class CMyFrameWnd : public CFrameWnd {
	DECLARE_MESSAGE_MAP()
public:
	int OnCreate(LPCREATESTRUCT pcs);
	void OnPaint();
	void OnMouseMove(UINT nKey, CPoint pt);
	LRESULT OnMyMessage(WPARAM wParam, LPARAM lParam);
	int m_x;
	int m_y;
};
BEGIN_MESSAGE_MAP(CMyFrameWnd, CFrameWnd)
	ON_WM_CREATE()//��׼��Ϣ
	ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
	ON_MESSAGE(WM_MYMESSAGE, OnMyMessage)//�Զ�����Ϣ
END_MESSAGE_MAP()

LRESULT CMyFrameWnd::OnMyMessage(WPARAM wParam, LPARAM lParam) {
	CString str;
	str.Format("wParam=%d,lParam=%d", wParam, lParam);
	AfxMessageBox(str);
	return 0;
}
void CMyFrameWnd::OnMouseMove(UINT nKey, CPoint pt) {
	m_x = pt.x;
	m_y = pt.y;
	::InvalidateRect(this->m_hWnd, NULL, TRUE);
}
void CMyFrameWnd::OnPaint() {
	PAINTSTRUCT ps = { 0 };
	HDC hdc = ::BeginPaint(this->m_hWnd, &ps);
	::TextOut(hdc, m_x, m_y, "hello", 5);
	::EndPaint(m_hWnd, &ps);
}
int CMyFrameWnd::OnCreate(LPCREATESTRUCT pcs) {
	AfxMessageBox("WM_CREATE��Ϣ������");
	::PostMessage(this->m_hWnd, WM_MYMESSAGE, 1, 2);//�����Զ�����Ϣ
	return CFrameWnd::OnCreate(pcs);
}
class CMyWinApp : public CWinApp {
public:
	virtual BOOL InitInstance();
};
CMyWinApp theApp;//���Ƶ�
BOOL CMyWinApp::InitInstance() {
	CMyFrameWnd* pFrame = new CMyFrameWnd;
	pFrame->Create(NULL, "MFCCreate");
	m_pMainWnd = pFrame;
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	return TRUE;
}
