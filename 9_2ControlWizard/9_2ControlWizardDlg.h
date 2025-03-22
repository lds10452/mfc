
// 9_2ControlWizardDlg.h: 头文件
//

#pragma once


// CMy92ControlWizardDlg 对话框
class CMy92ControlWizardDlg : public CDialogEx
{
// 构造
public:
	CMy92ControlWizardDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY9_2CONTROLWIZARD_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CButton m_btn;
	afx_msg void OnClickedButton1();
	CEdit m_edit;
	CString m_str;
	afx_msg void OnChangeEdit1();
	CButton m_check;
	afx_msg void OnClickedButton2();
	CButton m_btn2;
	afx_msg void OnClickedCheck1();
	CButton m_radio1;
	CButton m_radio2;
	afx_msg void OnClickedRadio1();
	afx_msg void OnClickedRadio2();
	CStatic m_group;
	CStatic m_st;
	CStatic m_pictureControl;
};
