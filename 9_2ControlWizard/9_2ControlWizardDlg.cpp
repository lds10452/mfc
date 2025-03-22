//////////////
// cbutton
// cedit
// 复选框
// 单选框
// group
// 文本静态框（label）
// 图像静态框
/////////////

#include "pch.h"
#include "framework.h"
#include "9_2ControlWizard.h"
#include "9_2ControlWizardDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy92ControlWizardDlg 对话框



CMy92ControlWizardDlg::CMy92ControlWizardDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY9_2CONTROLWIZARD_DIALOG, pParent)
	, m_str(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy92ControlWizardDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, m_btn);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
	DDX_Text(pDX, IDC_EDIT1, m_str);
	DDX_Control(pDX, IDC_CHECK1, m_check);
	DDX_Control(pDX, IDC_BUTTON2, m_btn2);
	DDX_Control(pDX, IDC_RADIO1, m_radio1);
	DDX_Control(pDX, IDC_RADIO2, m_radio2);
	DDX_Control(pDX, IDC_GROUP, m_group);
	DDX_Control(pDX, IDC_ST, m_st);
	DDX_Control(pDX, IDC_PS, m_pictureControl);
}

BEGIN_MESSAGE_MAP(CMy92ControlWizardDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMy92ControlWizardDlg::OnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, &CMy92ControlWizardDlg::OnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMy92ControlWizardDlg::OnClickedButton2)
	ON_BN_CLICKED(IDC_CHECK1, &CMy92ControlWizardDlg::OnClickedCheck1)
	ON_BN_CLICKED(IDC_RADIO1, &CMy92ControlWizardDlg::OnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CMy92ControlWizardDlg::OnClickedRadio2)
END_MESSAGE_MAP()


// CMy92ControlWizardDlg 消息处理程序

BOOL CMy92ControlWizardDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
//	m_btn.MoveWindow(0, 0, 100, 100);
	m_btn.SetWindowText("button");

	//	m_edit.SetWindowText("hello world");
	m_str = "hello";
	UpdateData(false);

	m_check.SetCheck(true);

	m_radio1.SetCheck(true);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMy92ControlWizardDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMy92ControlWizardDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy92ControlWizardDlg::OnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	char text[256];
	m_edit.GetWindowText(text, 256);
	AfxMessageBox(text);
}

void CMy92ControlWizardDlg::OnChangeEdit1()
{
//	char text[256];
//	m_edit.GetWindowText(text, 256);
	UpdateData(true);
	m_btn.SetWindowText(m_str);
}

void CMy92ControlWizardDlg::OnClickedButton2()
{
	if (m_check.GetCheck())
		m_check.SetCheck(false);
	else
		m_check.SetCheck(true);

	m_st.SetWindowText("hello");

	m_pictureControl.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP1)));
}


void CMy92ControlWizardDlg::OnClickedCheck1()
{
	int state = m_check.GetCheck();
	CString str;
	str.Format("%d", state);
	m_btn2.SetWindowText(str);
}


void CMy92ControlWizardDlg::OnClickedRadio1()
{
	m_radio1.SetCheck(true);
	m_radio2.SetCheck(false);
}


void CMy92ControlWizardDlg::OnClickedRadio2()
{
	m_radio1.SetCheck(false);
	m_radio2.SetCheck(true);
}
