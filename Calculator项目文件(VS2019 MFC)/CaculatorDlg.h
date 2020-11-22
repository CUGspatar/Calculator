
// CaculatorDlg.h: 头文件
//

#pragma once


// CCaculatorDlg 对话框
class CCaculatorDlg : public CDialogEx
{
// 构造
public:
	CCaculatorDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CACULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:

	afx_msg void OnBnClickedButton0();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButtonpi();
	afx_msg void OnBnClickedButtonpoint();
	afx_msg void OnBnClickedButtonadd();
	afx_msg void OnBnClickedButtonsubtract();
	afx_msg void OnBnClickedButtonmultiply();
	afx_msg void OnBnClickedButtondivide();
	afx_msg void OnBnClickedButtonopenparen();
	afx_msg void OnBnClickedButtoncloseparen();
	afx_msg void OnBnClickedButtonsqrt();
	afx_msg void OnBnClickedButtonpow();
	afx_msg void OnBnClickedButtonpercent();
	afx_msg void OnBnClickedButtonfactorial();
	afx_msg void OnBnClickedButtonclear();
	afx_msg void OnBnClickedButtonresult();
	afx_msg void OnBnClickedButtonbackspace();

	CString input;// 记录输入的表达式
	CString output;// 记录输出的结果

	afx_msg void OnButtonAbout();
	afx_msg void OnButtonHelp();
	afx_msg void OnEnChangeEditoutput();
};
