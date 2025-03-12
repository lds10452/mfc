#include <afxwin.h>

class CMyFrameWnd : public CFrameWnd {
	DECLARE_MESSAGE_MAP()
//protected:
//	static const AFX_MSGMAP* PASCAL GetThisMessageMap();
//	virtual const AFX_MSGMAP* GetMessageMap() const;
public:
	LRESULT OnCreate(WPARAM wParam, LPARAM lParam);
	LRESULT OnPaint(WPARAM wParam, LPARAM lParam);
};

BEGIN_MESSAGE_MAP(CMyFrameWnd, CFrameWnd)
	ON_MESSAGE(WM_PAINT, OnPaint)
	ON_MESSAGE( WM_CREATE, OnCreate )
END_MESSAGE_MAP()

//const AFX_MSGMAP* CMyFrameWnd::GetMessageMap() const
//{
//	return GetThisMessageMap();
//}
//const AFX_MSGMAP* PASCAL CMyFrameWnd::GetThisMessageMap()
//{
//	static const AFX_MSGMAP_ENTRY _messageEntries[] =
//	{
////-------------------------------------------------------------------------------------------
//		{ WM_CREATE, 0, 0, 0, AfxSig_lwl, (AFX_PMSG)(AFX_PMSGW)
//			(static_cast<LRESULT(AFX_MSG_CALL CWnd::*)(WPARAM, LPARAM)> (&OnCreate)) },
////---------------------------------------------------------------------------------------
//		{0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0 }
//	};
//	static const AFX_MSGMAP messageMap = { &CFrameWnd::GetThisMessageMap, &_messageEntries[0] };
//	return &messageMap;
//}

LRESULT CMyFrameWnd::OnPaint(WPARAM wParam, LPARAM lParam) {
	PAINTSTRUCT ps = { 0 };
	HDC hdc = ::BeginPaint(this->m_hWnd, &ps);
	::TextOut(hdc, 100, 100, "hello", 5);
	::EndPaint(m_hWnd, &ps);
	return 0;
}

LRESULT CMyFrameWnd::OnCreate(WPARAM wParam, LPARAM lParam) {
	AfxMessageBox("WM_CREATE");
	return 0;
}

class CMyWinApp : public CWinApp {
public:
	virtual BOOL InitInstance();
};
CMyWinApp theApp;//±¬ÆÆµã
BOOL CMyWinApp::InitInstance() {
	CMyFrameWnd* pFrame = new CMyFrameWnd;
	pFrame->Create(NULL, "MFCCreate");
	m_pMainWnd = pFrame;
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	return TRUE;
}
