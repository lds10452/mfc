#include <afxwin.h>
#include "resource.h"
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
	pDC->TextOut(100, 100, "������ͼ����");
}
class CMyChild : public CMDIChildWnd {
	DECLARE_DYNCREATE(CMyChild)
};
IMPLEMENT_DYNCREATE(CMyChild, CMDIChildWnd)
class CMyFrameWnd : public CMDIFrameWnd { //�Լ�������ܴ�����Ķ���
};
class CMyWinApp : public CWinApp {//�Լ���Ӧ�ó�����Ķ���
public:
	virtual BOOL InitInstance();
};
BOOL CMyWinApp::InitInstance() {
	CMyFrameWnd* pFrame = new CMyFrameWnd;
	pFrame->LoadFrame(IDR_MENU1);
	m_pMainWnd = pFrame;
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();

	CMultiDocTemplate* pTemplate = new CMultiDocTemplate(IDR_MENU2,
		RUNTIME_CLASS(CMyDoc),
		RUNTIME_CLASS(CMyChild),
		RUNTIME_CLASS(CMyView));
	AddDocTemplate(pTemplate);

	OnFileNew();//�����ĵ�����󣬴����ӿ������󣬴����ӿ�ܴ��ڣ�������ͼ����󣬴�����ͼ���ڣ��ĵ���������ͼ��������
	OnFileNew();//�����ĵ�����󣬴����ӿ������󣬴����ӿ�ܴ��ڣ�������ͼ����󣬴�����ͼ���ڣ��ĵ���������ͼ��������
	OnFileNew();//�����ĵ�����󣬴����ӿ������󣬴����ӿ�ܴ��ڣ�������ͼ����󣬴�����ͼ���ڣ��ĵ���������ͼ��������

	return TRUE;
}
CMyWinApp theApp;






