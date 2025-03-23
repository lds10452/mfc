//////////////
// cbutton
// cedit
// 复选框
// 单选框
// group
// 文本静态框（label）
// 图像静态框
// 组合框、列表框？
// 滑块slider、进度条？
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
	DDX_Control(pDX, IDC_COMBO1, m_simple);
	DDX_Control(pDX, IDC_COMBO2, m_dropdown);
	DDX_Control(pDX, IDC_COMBO3, m_droplist);
	DDX_Control(pDX, IDC_SLIDER1, m_slider);
	DDX_Control(pDX, IDC_PROGRESS1, m_pro);
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
	ON_CBN_SELCHANGE(IDC_COMBO2, &CMy92ControlWizardDlg::OnCbnSelchangeCombo2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMy92ControlWizardDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMy92ControlWizardDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMy92ControlWizardDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMy92ControlWizardDlg::OnBnClickedButton6)
	ON_CBN_EDITCHANGE(IDC_COMBO1, &CMy92ControlWizardDlg::OnEditchangeCombo1)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &CMy92ControlWizardDlg::OnCustomdrawSlider1)
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

	for (int i = 0; i < 100; i++) {
		char szItem[256];
		sprintf_s(szItem, "Item%d", i);
		m_simple.AddString(szItem);//追加选项
		m_simple.SetItemData(i, 1000 + i);

		m_dropdown.AddString(szItem);
		m_droplist.AddString(szItem);
	}
	m_simple.SetCurSel(99);
	m_dropdown.SetCurSel(99);
	m_droplist.SetCurSel(99);

	m_slider.SetRange(0, 100);
	m_slider.SetPos(50);
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


void CMy92ControlWizardDlg::OnCbnSelchangeCombo2()
{
	int index = m_dropdown.GetCurSel();
	m_simple.SetCurSel(index);
	m_droplist.SetCurSel(index);
}


void CMy92ControlWizardDlg::OnBnClickedButton3()
{
	m_simple.ResetContent();
	m_dropdown.ResetContent();
	m_droplist.ResetContent();
}


void CMy92ControlWizardDlg::OnBnClickedButton4()
{
	m_simple.DeleteString(m_simple.GetCurSel());
	m_dropdown.DeleteString(m_dropdown.GetCurSel());
	m_droplist.DeleteString(m_droplist.GetCurSel());
}


void CMy92ControlWizardDlg::OnBnClickedButton5()
{
	CString str;
	m_simple.GetLBText(m_simple.GetCurSel(), str);
	AfxMessageBox(str);
}


void CMy92ControlWizardDlg::OnBnClickedButton6()
{
	DWORD data = m_simple.GetItemData(m_simple.GetCurSel());
	CString str;
	str.Format("附加数据：%d", data);
	AfxMessageBox(str);
}


void CMy92ControlWizardDlg::OnEditchangeCombo1()
{
	AfxMessageBox("文本被修改");
}


void CMy92ControlWizardDlg::OnCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	int pos=m_slider.GetPos();
	CString str;
	str.Format("滑块位置:%d", pos);
	this->SetWindowText(str);

	m_pro.SetPos(pos);
	*pResult = 0;
}
