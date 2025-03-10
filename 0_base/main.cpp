#include <afxwin.h>
class CMyFrameWnd : public CFrameWnd {
};
class CMyWinApp : public CWinApp {
public:
	CMyWinApp()
	{
	}
	virtual BOOL InitInstance() {//此函数内部的this为&theApp
		CMyFrameWnd* pFrame = new CMyFrameWnd;
		pFrame->Create(NULL, "MFCBase");
		this->m_pMainWnd = pFrame;
		pFrame->ShowWindow(SW_SHOW);
		pFrame->UpdateWindow();
		return TRUE;
	}
};
CMyWinApp theApp;//爆破点