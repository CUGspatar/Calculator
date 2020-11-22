
// CaculatorDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Caculator.h"
#include "CaculatorDlg.h"
#include "afxdialogex.h"
#include "stack.cpp"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCaculatorDlg 对话框



CCaculatorDlg::CCaculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CACULATOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCaculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCaculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON0, &CCaculatorDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON1, &CCaculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCaculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CCaculatorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CCaculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CCaculatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CCaculatorDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CCaculatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CCaculatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CCaculatorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTONpi, &CCaculatorDlg::OnBnClickedButtonpi)
	ON_BN_CLICKED(IDC_BUTTONpoint, &CCaculatorDlg::OnBnClickedButtonpoint)
	ON_BN_CLICKED(IDC_BUTTONadd, &CCaculatorDlg::OnBnClickedButtonadd)
	ON_BN_CLICKED(IDC_BUTTONsubtract, &CCaculatorDlg::OnBnClickedButtonsubtract)
	ON_BN_CLICKED(IDC_BUTTONmultiply, &CCaculatorDlg::OnBnClickedButtonmultiply)
	ON_BN_CLICKED(IDC_BUTTONdivide, &CCaculatorDlg::OnBnClickedButtondivide)
	ON_BN_CLICKED(IDC_BUTTONopen_paren, &CCaculatorDlg::OnBnClickedButtonopenparen)
	ON_BN_CLICKED(IDC_BUTTONclose_paren, &CCaculatorDlg::OnBnClickedButtoncloseparen)
	ON_BN_CLICKED(IDC_BUTTONsqrt, &CCaculatorDlg::OnBnClickedButtonsqrt)
	ON_BN_CLICKED(IDC_BUTTONpow, &CCaculatorDlg::OnBnClickedButtonpow)
	ON_BN_CLICKED(IDC_BUTTONpercent, &CCaculatorDlg::OnBnClickedButtonpercent)
	ON_BN_CLICKED(IDC_BUTTONfactorial, &CCaculatorDlg::OnBnClickedButtonfactorial)
	ON_BN_CLICKED(IDC_BUTTONclear, &CCaculatorDlg::OnBnClickedButtonclear)
	ON_BN_CLICKED(IDC_BUTTONresult, &CCaculatorDlg::OnBnClickedButtonresult)
	ON_BN_CLICKED(IDC_BUTTONbackspace, &CCaculatorDlg::OnBnClickedButtonbackspace)
	ON_COMMAND(ID_32772, &CCaculatorDlg::OnButtonAbout)
	ON_COMMAND(ID_32773, &CCaculatorDlg::OnButtonHelp)
END_MESSAGE_MAP()


// CCaculatorDlg 消息处理程序

BOOL CCaculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCaculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCaculatorDlg::OnPaint()
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
HCURSOR CCaculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//数字按键 0
void CCaculatorDlg::OnBnClickedButton0()
{
	// TODO: 在此添加控件通知处理程序代码
	//判断是否满足可输入条件
	if (!input.IsEmpty())
	{	//如果已输入的不为空，则需要做判断，'0'不能直接接在右括号')'或者圆周率Π'P'或者阶乘符'!'后
		if (input[input.GetLength() - 1] == ')' || input[input.GetLength() - 1] == 'P' || input[input.GetLength() - 1] == '!')
			return;//不满足可输入条件，此次按键动作失效
	}
	//满足可输入条件
	input += _T("0");//在已输入的文本后加上'0'
	SetDlgItemText(IDC_EDITinput, input);//更新输入框中的文本
}

//数字按键 1
void CCaculatorDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//判断是否满足可输入条件
	if (!input.IsEmpty())
	{	//如果已输入的不为空，则需要做判断，'1'不能直接接在右括号')'或者圆周率Π'P'或者阶乘符'!'后
		if (input[input.GetLength() - 1] == ')' || input[input.GetLength() - 1] == 'P' || input[input.GetLength() - 1] == '!')
			return;//不满足可输入条件，此次按键动作失效
	}
	//满足可输入条件
	input += _T("1");//在已输入的文本后加上'1'
	SetDlgItemText(IDC_EDITinput, input);//更新输入框中的文本
}

//数字按键 2
void CCaculatorDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	//判断是否满足可输入条件
	if (!input.IsEmpty())
	{	//如果已输入的不为空，则需要做判断，'2'不能直接接在右括号')'或者圆周率Π'P'或者阶乘符'!'后
		if (input[input.GetLength() - 1] == ')' || input[input.GetLength() - 1] == 'P' || input[input.GetLength() - 1] == '!')
			return;//不满足可输入条件，此次按键动作失效
	}
	//满足可输入条件
	input += _T("2");//在已输入的文本后加上'2'
	SetDlgItemText(IDC_EDITinput, input);//更新输入框中的文本
}

//数字按键 3
void CCaculatorDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	//判断是否满足可输入条件
	if (!input.IsEmpty())
	{	//如果已输入的不为空，则需要做判断，'3'不能直接接在右括号')'或者圆周率Π'P'或者阶乘符'!'后
		if (input[input.GetLength() - 1] == ')' || input[input.GetLength() - 1] == 'P' || input[input.GetLength() - 1] == '!')
			return;//不满足可输入条件，此次按键动作失效
	}
	//满足可输入条件
	input += _T("3");//在已输入的文本后加上'3'
	SetDlgItemText(IDC_EDITinput, input);//更新输入框中的文本
}

//数字按键 4
void CCaculatorDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	//判断是否满足可输入条件
	if (!input.IsEmpty())
	{	//如果已输入的不为空，则需要做判断，'4'不能直接接在右括号')'或者圆周率Π'P'或者阶乘符'!'后
		if (input[input.GetLength() - 1] == ')' || input[input.GetLength() - 1] == 'P' || input[input.GetLength() - 1] == '!')
			return;//不满足可输入条件，此次按键动作失效
	}
	//满足可输入条件
	input += _T("4");//在已输入的文本后加上'4'
	SetDlgItemText(IDC_EDITinput, input);//更新输入框中的文本
}

//数字按键 5
void CCaculatorDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	//判断是否满足可输入条件
	if (!input.IsEmpty())
	{	//如果已输入的不为空，则需要做判断，'5'不能直接接在右括号')'或者圆周率Π'P'或者阶乘符'!'后
		if (input[input.GetLength() - 1] == ')' || input[input.GetLength() - 1] == 'P' || input[input.GetLength() - 1] == '!')
			return;//不满足可输入条件，此次按键动作失效
	}
	//满足可输入条件
	input += _T("5");//在已输入的文本后加上'5'
	SetDlgItemText(IDC_EDITinput, input);//更新输入框中的文本
}

//数字按键 6
void CCaculatorDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	//判断是否满足可输入条件
	if (!input.IsEmpty())
	{	//如果已输入的不为空，则需要做判断，'6'不能直接接在右括号')'或者圆周率Π'P'或者阶乘符'!'后
		if (input[input.GetLength() - 1] == ')' || input[input.GetLength() - 1] == 'P' || input[input.GetLength() - 1] == '!')
			return;//不满足可输入条件，此次按键动作失效
	}
	//满足可输入条件
	input += _T("6");//在已输入的文本后加上'6'
	SetDlgItemText(IDC_EDITinput, input);//更新输入框中的文本
}

//数字按键 7
void CCaculatorDlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	//判断是否满足可输入条件
	if (!input.IsEmpty())
	{	//如果已输入的不为空，则需要做判断，'7'不能直接接在右括号')'或者圆周率Π'P'或者阶乘符'!'后
		if (input[input.GetLength() - 1] == ')' || input[input.GetLength() - 1] == 'P' || input[input.GetLength() - 1] == '!')
			return;//不满足可输入条件，此次按键动作失效
	}
	//满足可输入条件
	input += _T("7");//在已输入的文本后加上'7'
	SetDlgItemText(IDC_EDITinput, input);//更新输入框中的文本
}

//数字按键 8
void CCaculatorDlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	//判断是否满足可输入条件
	if (!input.IsEmpty())
	{	//如果已输入的不为空，则需要做判断，'8'不能直接接在右括号')'或者圆周率Π'P'或者阶乘符'!'后
		if (input[input.GetLength() - 1] == ')' || input[input.GetLength() - 1] == 'P' || input[input.GetLength() - 1] == '!')
			return;//不满足可输入条件，此次按键动作失效
	}
	//满足可输入条件
	input += _T("8");//在已输入的文本后加上'8'
	SetDlgItemText(IDC_EDITinput, input);//更新输入框中的文本
}

//数字按键 9
void CCaculatorDlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	//判断是否满足可输入条件
	if (!input.IsEmpty())
	{	//如果已输入的不为空，则需要做判断，'9'不能直接接在右括号')'或者圆周率Π'P'或者阶乘符'!'后
		if (input[input.GetLength() - 1] == ')' || input[input.GetLength() - 1] == 'P' || input[input.GetLength() - 1] == '!')
			return;//不满足可输入条件，此次按键动作失效
	}
	//满足可输入条件
	input += _T("9");//在已输入的文本后加上'9'
	SetDlgItemText(IDC_EDITinput, input);//更新输入框中的文本
}

//数字按键 Π(P)
void CCaculatorDlg::OnBnClickedButtonpi()
{
	// TODO: 在此添加控件通知处理程序代码
	//判断是否满足可输入条件
	if (!input.IsEmpty())
	{	//如果已输入的不为空，则需要做判断，'P'不能直接接在右括号')'或者数字0-9或者阶乘符'!'后
		if (input[input.GetLength() - 1] == ')' || (input[input.GetLength() - 1] >= '0' && input[input.GetLength() - 1] <= '9') || input[input.GetLength() - 1] == '!')
			return;//不满足可输入条件，此次按键动作失效
	}
	//满足可输入条件
	input += _T("P");//在已输入的文本后加上'P'
	SetDlgItemText(IDC_EDITinput, input);//更新输入框中的文本
}

//符号按键 .(小数点)
void CCaculatorDlg::OnBnClickedButtonpoint()
{
	// TODO: 在此添加控件通知处理程序代码
	//判断是否满足可输入条件
	if (input.IsEmpty())
		return; //小数点必须接在其他字符之后，已输入的为空,不满足可输入条件，此次按键动作失效
	else//已输入的不为空
	{	
		if (! (input[input.GetLength()-1] >= '0' && input[input.GetLength()-1] <= '9'))
			return;//小数点前面只可能是数字，已输入的不满足可输入条件，此次按键动作失效
		else//小数点前面是数字，但需要判断一个数字不可能有两个小数点
		{
			int len = input.GetLength();
			while (len)
			{
				if (input[len - 1] >= '0' && input[len - 1] <= '9')
					len--;
				else if (input[len - 1] == '.')
					return;
				else
					break;
			}
		}
	}
	//满足可输入条件
	input += _T(".");//在已输入的文本后加上'.'
	SetDlgItemText(IDC_EDITinput, input);//更新输入框中的文本
}

//算数符按键 +
void CCaculatorDlg::OnBnClickedButtonadd()
{
	// TODO: 在此添加控件通知处理程序代码
	//判断是否满足可输入条件
	if (input.IsEmpty())
		return;//加号必须接在其他字符之后，已输入的为空,不满足可输入条件，此次按键动作失效
	else if (!(input[input.GetLength() - 1] >= '0' && input[input.GetLength() - 1] <= '9' || input[input.GetLength() - 1] == ')' || input[input.GetLength() - 1] == 'P' || input[input.GetLength() - 1] == '!'))
		return;//加号前面只可能是数字0-9和Π或者右括号')'或者阶乘符'!'，已输入的不满足可输入条件，此次按键动作失效
	//满足可输入条件
	input += _T("+");//在已输入的文本后加上'+'
	SetDlgItemText(IDC_EDITinput, input);//更新输入框中的文本
}

//算数符按键 -
void CCaculatorDlg::OnBnClickedButtonsubtract()
{
	// TODO: 在此添加控件通知处理程序代码
	//判断是否满足可输入条件
	if (input.IsEmpty())
		return;//减号必须接在其他字符之后，已输入的为空,不满足可输入条件，此次按键动作失效
	else if (!(input[input.GetLength() - 1] >= '0' && input[input.GetLength() - 1] <= '9' || input[input.GetLength() - 1] == ')' || input[input.GetLength() - 1] == 'P' || input[input.GetLength() - 1] == '!'))
		return;//减号前面只可能是数字0-9和Π或者右括号')'或者阶乘符'!'，已输入的不满足可输入条件，此次按键动作失效
	//满足可输入条件
	input += _T("-");//在已输入的文本后加上'-'
	SetDlgItemText(IDC_EDITinput, input);//更新输入框中的文本
}

//算数符按键 *
void CCaculatorDlg::OnBnClickedButtonmultiply()
{
	// TODO: 在此添加控件通知处理程序代码
	//判断是否满足可输入条件
	if (input.IsEmpty())
		return;//乘号必须接在其他字符之后，已输入的为空,不满足可输入条件，此次按键动作失效
	else if (!(input[input.GetLength() - 1] >= '0' && input[input.GetLength() - 1] <= '9' || input[input.GetLength() - 1] == ')' || input[input.GetLength() - 1] == 'P' || input[input.GetLength() - 1] == '!'))
		return;//乘号前面只可能是数字0-9和Π或者右括号')'或者阶乘符'!'，已输入的不满足可输入条件，此次按键动作失效
	//满足可输入条件
	input += _T("*");//在已输入的文本后加上'*'
	SetDlgItemText(IDC_EDITinput, input);//更新输入框中的文本
}

//算数符按键 /
void CCaculatorDlg::OnBnClickedButtondivide()
{
	// TODO: 在此添加控件通知处理程序代码
	//判断是否满足可输入条件
	if (input.IsEmpty())
		return;//除号必须接在其他字符之后，已输入的为空,不满足可输入条件，此次按键动作失效
	else if (!(input[input.GetLength() - 1] >= '0' && input[input.GetLength() - 1] <= '9' || input[input.GetLength() - 1] == ')' || input[input.GetLength() - 1] == 'P' || input[input.GetLength() - 1] == '!'))
		return;//除号前面只可能是数字0-9和Π或者右括号')'或者阶乘符'!'，已输入的不满足可输入条件，此次按键动作失效
	//满足可输入条件
	input += _T("/");//在已输入的文本后加上'/'
	SetDlgItemText(IDC_EDITinput, input);//更新输入框中的文本
}

//符号按键 (
void CCaculatorDlg::OnBnClickedButtonopenparen()
{
	// TODO: 在此添加控件通知处理程序代码
	//判断是否满足可输入条件
	if (!input.IsEmpty())
	{	//如果已输入的不为空，则需要做判断，左括号'('不能直接接在数字0-9和Π或者小数点'.'或者右括号')'或者阶乘符'!'后
		char temp = input[input.GetLength() - 1];
		if ((temp >= '0' && temp <= '9') || temp == '.' || temp == 'P' || temp == ')' || temp == '!')
			return;//不满足可输入条件，此次按键动作失效
	}
	//满足可输入条件
	input += _T("(");//在已输入的文本后加上'('
	SetDlgItemText(IDC_EDITinput, input);//更新输入框中的文本
}

//符号按键 )
void CCaculatorDlg::OnBnClickedButtoncloseparen()
{
	// TODO: 在此添加控件通知处理程序代码
	//判断是否满足可输入条件
	if (input.IsEmpty())
		return;//右括号')'必须接在其他字符后，已输入的为空，不满足可输入条件，此次按键动作失效
	else
	{	//如果已输入的不为空，则需要做判断，右括号')'只能直接接在数字0-9和Π或者右括号')'或者阶乘符'!'后
		char temp = input[input.GetLength() - 1];
		if (!((temp >= '0' && temp <= '9') || temp == 'P' || temp == ')' || temp == '!'))
			return;//不满足可输入条件，此次按键动作失效
	}
	//满足可输入条件
	input += _T(")");//在已输入的文本后加上')'
	SetDlgItemText(IDC_EDITinput, input);//更新输入框中的文本
}

//算数符按键 √(S)
void CCaculatorDlg::OnBnClickedButtonsqrt()
{
	// TODO: 在此添加控件通知处理程序代码
	//判断是否满足可输入条件
	if (!input.IsEmpty())
	{	//如果已输入的不为空，则需要做判断，根号'S'只能直接接在加减乘除'+''-''*''/'或者根号'S'或者左括号'('后
		char temp = input[input.GetLength() - 1];
		if (!(temp == '+' || temp == '-' || temp == '*' || temp == '/' || temp == 'S' || temp == '('))
			return;//不满足可输入条件，此次按键动作失效
	}
	//满足可输入条件
	input += _T("S");//在已输入的文本后加上'S'
	SetDlgItemText(IDC_EDITinput, input);//更新输入框中的文本
}

//算数符按键 ^
void CCaculatorDlg::OnBnClickedButtonpow()
{
	// TODO: 在此添加控件通知处理程序代码
	//判断是否满足可输入条件
	if (input.IsEmpty())
		return;//次方'^'必须接在其他字符后，已输入的为空，不满足可输入条件，此次按键动作失效
	else
	{	//如果已输入的不为空，则需要做判断，次方'^'只能直接接在数字0-9和Π或者左括号'('后
		char temp = input[input.GetLength() - 1];
		if (!((temp >= '1' && temp <= '9') || temp == 'P' || temp==')'))
			return;//不满足可输入条件，此次按键动作失效
	}
	//满足可输入条件
	input += _T("^");//在已输入的文本后加上'^'
	SetDlgItemText(IDC_EDITinput, input);//更新输入框中的文本
}

//算数符按键 !
void CCaculatorDlg::OnBnClickedButtonfactorial()
{
	// TODO: 在此添加控件通知处理程序代码
	//判断是否满足可输入条件
	if (input.IsEmpty())
		return;//阶乘符'!'必须接在其他字符后，已输入的为空，不满足可输入条件，此次按键动作失效
	else
	{	//如果已输入的不为空，则需要做判断，阶乘符'!'只能直接接在数字0-9和Π或者右括号')'后
		char temp = input[input.GetLength() - 1];
		if (!((temp >= '0' && temp <= '9') || temp == 'P' || temp == ')'))
			return;//不满足可输入条件，此次按键动作失效
	}
	//满足可输入条件
	input += _T("!");//在已输入的文本后加上'!'
	SetDlgItemText(IDC_EDITinput, input);//更新输入框中的文本
}

//清除按键 C
void CCaculatorDlg::OnBnClickedButtonclear()
{
	// TODO: 在此添加控件通知处理程序代码
	if (input.IsEmpty()&&output.IsEmpty())
		return;//如果输入框和结果框为空则无需清除
	else
	{	//如果不为空则清除输入框和结果框里的内容
		input = output ="";
		SetDlgItemText(IDC_EDITinput, input);
		SetDlgItemText(IDC_EDIToutput, output);
	}
}

//算数符按键 %
void CCaculatorDlg::OnBnClickedButtonpercent()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItemText(IDC_EDITinput, input);//将输入框中的表达式存入input中
	char ch[100];
	char postexp[100];
	//CString input转char ch[100]
	char* tmpch;
	int wLen = WideCharToMultiByte(CP_ACP, 0, input, -1, NULL, 0, NULL, NULL);
	tmpch = new char[wLen + 1];
	WideCharToMultiByte(CP_ACP, 0, input, -1, tmpch, wLen, NULL, NULL);
	for (int i = 0; i < wLen; ++i)
		ch[i] = tmpch[i];

	Postexp pt;
	Compvalue cv;
	ErrorControl ec;
	if (ec.judge(ch)) {//如果输入的符合规范，此表达式正确，可进行计算
		//将字符数组ch里存的中缀表达式转成后缀表达式存入字符数组postexp中
		pt.trans(ch, postexp);
		//计算后缀表达式的值并将结果以CString类型返回
		double percent = _wtof(cv.compvalue(postexp)) * 100;
		output.Format(_T("%lf"), percent);
		output += '%';
		SetDlgItemText(IDC_EDIToutput, output);//将存在output中的最终结果显示在结果框中
	}
	else//如果输入的不符合规范，此表达式错误，无法计算
	{
		output = "错误";
		SetDlgItemText(IDC_EDIToutput, output);//在结果框中提示"错误"
	}
}

//结果按键
void CCaculatorDlg::OnBnClickedButtonresult()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItemText(IDC_EDITinput, input);//将输入框中的表达式存入input中
	char ch[100];
	char postexp[100];
	//CString input转char ch[100]
	char* tmpch;
	int wLen = WideCharToMultiByte(CP_ACP, 0, input, -1, NULL, 0, NULL, NULL);
	tmpch = new char[wLen + 1];
	WideCharToMultiByte(CP_ACP, 0, input, -1, tmpch, wLen, NULL, NULL);
	for (int i = 0; i < wLen; ++i)
		ch[i] = tmpch[i];

	Postexp pt;
	Compvalue cv;
	ErrorControl ec;
	if (ec.judge(ch)) {//如果输入的符合规范，此表达式正确，可进行计算
		//将字符数组ch里存的中缀表达式转成后缀表达式存入字符数组postexp中
		pt.trans(ch, postexp);
		//计算后缀表达式的值并将结果以CString类型返回，存入output中
		output = cv.compvalue(postexp);
		SetDlgItemText(IDC_EDIToutput, output);//将存在output中的最终结果显示在结果框中
	}
	else//如果输入的不符合规范，此表达式错误，无法计算
	{
		output = "错误";
		SetDlgItemText(IDC_EDIToutput, output);//在结果框中提示"错误"
	}
}

//退格按键
void CCaculatorDlg::OnBnClickedButtonbackspace()
{
	// TODO: 在此添加控件通知处理程序代码
	if (input.IsEmpty())
		return;//如果输入框为空则无需清除
	else
	{	//如果不为空则退格删除一个输入框里的字符
		input.Delete(input.GetLength() - 1);
		SetDlgItemText(IDC_EDITinput, input);
	}
}

//关于菜单
void CCaculatorDlg::OnButtonAbout()
{
	// TODO: 在此添加命令处理程序代码
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();
}

//帮助菜单
void CCaculatorDlg::OnButtonHelp()
{
	// TODO: 在此添加命令处理程序代码
	MessageBox(_T("注意：\n\
在输入框中\n\
\tP代表圆周率π\n\
\tS代表根号√\n\
运算部分规则\n\
\t阶乘号!只能对整数阶乘\n\
\t根号√不能直接接在次方 ^ 后，需要加括号\n\
\t百分号 % 是对最终结果取百分号，不参与表达式运算\n\
结果小数点后面保留六位\n"),_T("帮助"));
}
