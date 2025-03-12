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
	CMenu* pPopup = menu.GetSubMenu(0);//��ȡ�˵�����һ����������˵�
	pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_TOPALIGN, pt.x, pt.y, pWnd/*this*/); //pWnd===this
}

void CMyFrameWnd::OnInitMenuPopup(CMenu* pPopup, UINT nPos, BOOL i) {
//	pPopup->CheckMenuItem( ID_NEW, MF_CHECKED );
	::CheckMenuItem(pPopup->m_hMenu, ID_NEW, MF_CHECKED);//�����˵�������ò˵���ᱻѡ��
}

void CMyFrameWnd::OnNew() {
	AfxMessageBox("����ദ�����½��˵�����");
}

int CMyFrameWnd::OnCreate(LPCREATESTRUCT pcs) {
	menu.LoadMenu(IDR_MENU1);//menu�����Ǿֲ���������Ȼ����˵�������
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
	ON_COMMAND(ID_NEW, OnNew)//����command��Ϣ��������������
END_MESSAGE_MAP()

void CMyWinApp::OnNew() {
	AfxMessageBox("Ӧ�ó����ദ�����½������");//�����ܴ���Ҳ����˴����������ȵ���ܴ��ڵ�
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
