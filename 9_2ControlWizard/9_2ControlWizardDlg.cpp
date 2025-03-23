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
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_COMBO4, m_combox4);
	DDX_Control(pDX, IDC_TREE1, m_tree);
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
	ON_CBN_SELCHANGE(IDC_COMBO4, &CMy92ControlWizardDlg::OnCbnSelchangeCombo4)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &CMy92ControlWizardDlg::OnDblclkList1)
	ON_BN_CLICKED(IDC_BUTTON7, &CMy92ControlWizardDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMy92ControlWizardDlg::OnBnClickedButton8)
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

	//-----------------------------------------------
	m_combox4.AddString("图标");
	m_combox4.AddString("小图标");
	m_combox4.AddString("列表");
	m_combox4.AddString("报表");
	m_combox4.SetCurSel(0);

	m_list.InsertColumn(0, "名称", LVCFMT_LEFT, 150);
	m_list.InsertColumn(1, "修改日期", LVCFMT_LEFT, 150);
	m_list.InsertColumn(2, "类型", LVCFMT_LEFT, 150);
	m_list.InsertColumn(3, "大小", LVCFMT_LEFT, 150);
	m_list.SetExtendedStyle(LVS_EX_GRIDLINES);//经纬线

	CImageList* pImgLst = new CImageList;
	pImgLst->Create(IDB_BITMAP2, 24, 1, RGB(255, 255, 255));

	m_list.SetImageList(pImgLst, LVSIL_NORMAL);//将图像链表应用在列表控件的图标风格中
	m_list.SetImageList(pImgLst, LVSIL_SMALL);//将图像链表应用在列表控件的其他风格中

	ShowFile("c:");
	/*//测试数据
		m_list.InsertItem( 0, "目录", 0 );
		m_list.SetItemText( 0, 1, "2100.5.7" );
		m_list.SetItemText( 0, 2, "Dir" );
		m_list.SetItemText( 0, 3, "3M" );

		m_list.InsertItem( 1, "文件", 1 );
		m_list.SetItemText( 1, 1, "2100.12.17" );
		m_list.SetItemText( 1, 2, "File" );
		m_list.SetItemText( 1, 3, "13K" );*/
	//---------------------------------------------------------

	CImageList* pImgTree = new CImageList;
	pImgTree->Create(IDB_BITMAP1, 12, 1, RGB(255, 255, 255));

	m_tree.SetImageList(pImgTree, LVSIL_NORMAL);

	HTREEITEM nRoot = m_tree.InsertItem("达内集团", 0, 1, NULL);
	m_tree.InsertItem("中关村中心", 2, 3, nRoot);
	m_tree.InsertItem("亚运村中心", 2, 3, nRoot);
	m_tree.InsertItem("天坛中心", 2, 3, nRoot);
	m_tree.SetItemHeight(25);
	//--------------------------------------------
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMy92ControlWizardDlg::ShowFile(CString path) {
	m_list.DeleteAllItems();
	CString strPath = path;
	strPath += "/*.*";
	CFileFind find;//文件搜索类对象
	BOOL goFind = find.FindFile(strPath); //开启查找
	int i = 0;
	while (goFind) {
		goFind = find.FindNextFile();//找到当前文件，将文件信息保存find对象的成员变量中
		CString filename = find.GetFileName();
		CString* filepath = new CString;
		*filepath = find.GetFilePath();
		if (find.IsDirectory()) {
			m_list.InsertItem(i, filename, 0);
			m_list.SetItemData(i, (DWORD_PTR)filepath);
		}
		else {
			m_list.InsertItem(i, filename, 1);
		}
		i++;
	}
	find.Close();
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


void CMy92ControlWizardDlg::OnCbnSelchangeCombo4()
{
	switch (m_combox4.GetCurSel()) {
	case 0://图标
		m_list.ModifyStyle(LVS_SMALLICON | LVS_LIST | LVS_REPORT, LVS_ICON);
		break;
	case 1://小图标
		m_list.ModifyStyle(LVS_ICON | LVS_LIST | LVS_REPORT, LVS_SMALLICON);
		break;
	case 2://列表
		m_list.ModifyStyle(LVS_ICON | LVS_SMALLICON | LVS_REPORT, LVS_LIST);
		break;
	case 3://报表
		m_list.ModifyStyle(LVS_ICON | LVS_LIST | LVS_SMALLICON, LVS_REPORT);
		break;
	}
}


void CMy92ControlWizardDlg::OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	*pResult = 0;
	DWORD_PTR nData = m_list.GetItemData(pNMItemActivate->iItem);//双击选项
	CString* filepath = (CString*)nData;
	if (filepath != NULL)
		ShowFile(*filepath);
}


void CMy92ControlWizardDlg::OnBnClickedButton7()
{
	m_tree.DeleteItem(m_tree.GetSelectedItem());
}


void CMy92ControlWizardDlg::OnBnClickedButton8()
{
	AfxMessageBox(m_tree.GetItemText(m_tree.GetSelectedItem()));
}
