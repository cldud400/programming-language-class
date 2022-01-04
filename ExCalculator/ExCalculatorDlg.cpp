﻿
// ExCalculatorDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "ExCalculator.h"
#include "ExCalculatorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CExCalculatorDlg 대화 상자



CExCalculatorDlg::CExCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_EXCALCULATOR_DIALOG, pParent)
	, m_LcdNum(0)
	, m_Op2(0)
	, m_Op1(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_LCD, m_Lcd);
	DDX_Text(pDX, IDC_EDIT_LCD, m_LcdNum);
	DDX_Text(pDX, IDC_EDIT_OP2, m_Op2);
	DDX_Text(pDX, IDC_EDIT_OP1, m_Op1);
}

BEGIN_MESSAGE_MAP(CExCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTT_D2, &CExCalculatorDlg::OnBnClickedButtD2)
	ON_BN_CLICKED(IDC_BUTT_D1, &CExCalculatorDlg::OnBnClickedButtD1)
	ON_BN_CLICKED(IDC_BUTT_D0, &CExCalculatorDlg::OnBnClickedButtD0)
	ON_BN_CLICKED(IDC_BUTT_D3, &CExCalculatorDlg::OnBnClickedButtD3)
	ON_BN_CLICKED(IDC_BUTT_D4, &CExCalculatorDlg::OnBnClickedButtD4)
	ON_BN_CLICKED(IDC_BUTT_D5, &CExCalculatorDlg::OnBnClickedButtD5)
	ON_BN_CLICKED(IDC_BUTT_D6, &CExCalculatorDlg::OnBnClickedButtD6)
	ON_BN_CLICKED(IDC_BUTT_D7, &CExCalculatorDlg::OnBnClickedButtD7)
	ON_BN_CLICKED(IDC_BUTT_D8, &CExCalculatorDlg::OnBnClickedButtD8)
	ON_BN_CLICKED(IDC_BUTT_D9, &CExCalculatorDlg::OnBnClickedButtD9)
	ON_BN_CLICKED(IDC_BUTT_DOT, &CExCalculatorDlg::OnBnClickedButtDot)
	ON_BN_CLICKED(IDC_BUTT_DIV, &CExCalculatorDlg::OnBnClickedButtDiv)
	ON_BN_CLICKED(IDC_BUTT_MULT, &CExCalculatorDlg::OnBnClickedButtMult)
	ON_BN_CLICKED(IDC_BUTT_SUB, &CExCalculatorDlg::OnBnClickedButtSub)
	ON_BN_CLICKED(IDC_BUTT_ADD, &CExCalculatorDlg::OnBnClickedButtAdd)
	ON_BN_CLICKED(IDC_BUTT_EQ, &CExCalculatorDlg::OnBnClickedButtEq)
	ON_BN_CLICKED(IDC_BUTT_AC, &CExCalculatorDlg::OnBnClickedButtAc)
	ON_BN_CLICKED(IDC_BUTT_BSP, &CExCalculatorDlg::OnBnClickedButtBsp)
	ON_BN_CLICKED(IDC_BUTT_SIGNCHNGE, &CExCalculatorDlg::OnBnClickedButtSignchnge)
	ON_BN_CLICKED(IDC_BUTT_FACTORIAL, &CExCalculatorDlg::OnBnClickedButtFactorial)
	ON_BN_CLICKED(IDC_BUTT_SQUARE, &CExCalculatorDlg::OnBnClickedButtSquare)
	ON_BN_CLICKED(IDC_BUTT_Sin, &CExCalculatorDlg::OnBnClickedButtSin)
	ON_BN_CLICKED(IDC_BUTT_COS, &CExCalculatorDlg::OnBnClickedButtCos)
	ON_BN_CLICKED(IDC_BUTT_LOG, &CExCalculatorDlg::OnBnClickedButtLog)
	ON_BN_CLICKED(IDC_BUTT_EXP, &CExCalculatorDlg::OnBnClickedButtExp)
END_MESSAGE_MAP()


// CExCalculatorDlg 메시지 처리기

BOOL CExCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CExCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CExCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CExCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CExCalculatorDlg::AddDigit(char numkey)
{
	CString str, tmp;
	tmp.Format("%c", numkey);
	m_Lcd.GetWindowTextA(str);
	if (str == '0'||keyflag==0)
		str = tmp;
	else
		str = str + tmp;
	m_Lcd.SetWindowTextA(str);
	keyflag = 1;
}

void CExCalculatorDlg::OnBnClickedButtD2()
{
	AddDigit('2');
}


void CExCalculatorDlg::OnBnClickedButtD1()
{
	AddDigit('1');
}


void CExCalculatorDlg::OnBnClickedButtD0()
{
	AddDigit('0');
}


void CExCalculatorDlg::OnBnClickedButtD3()
{
	AddDigit('3');
}


void CExCalculatorDlg::OnBnClickedButtD4()
{
	AddDigit('4');
}


void CExCalculatorDlg::OnBnClickedButtD5()
{
	AddDigit('5');
}


void CExCalculatorDlg::OnBnClickedButtD6()
{
	AddDigit('6');
}


void CExCalculatorDlg::OnBnClickedButtD7()
{
	AddDigit('7');
}


void CExCalculatorDlg::OnBnClickedButtD8()
{
	AddDigit('8');
}


void CExCalculatorDlg::OnBnClickedButtD9()
{
	AddDigit('9');
}


void CExCalculatorDlg::OnBnClickedButtDot()
{
	CString str, tmp;
	if (dotflag == 0) {
		tmp.Format("%c", '.');
		m_Lcd.GetWindowTextA(str);
		if (keyflag == 0) {
			str = '0';
			keyflag = 1;
		}
		str = str + tmp;
		m_Lcd.SetWindowTextA(str);
		dotflag = 1;

	}
}


void CExCalculatorDlg::OnBnClickedButtDiv()
{
	setOperator(4);
}


void CExCalculatorDlg::OnBnClickedButtMult()
{
	setOperator(3);
}


void CExCalculatorDlg::OnBnClickedButtSub()
{
	setOperator(2);
}


void CExCalculatorDlg::OnBnClickedButtAdd()
{
	setOperator(1);
}

void CExCalculatorDlg::setOperator(int opnum)
{
	UpdateData(TRUE);
	m_Op1 = m_LcdNum;
	UpdateData(FALSE);
	keyflag = 0;
	dotflag = 0;
	myoperator = opnum;
}


void CExCalculatorDlg::OnBnClickedButtEq()
{
	double result;
	UpdateData(TRUE);
	m_Op2 = m_LcdNum;
	switch (myoperator) {
		case 1:
			result = m_Op1 + m_Op2; break;
		case 2:
			result = m_Op1 - m_Op2; break;
		case 3:
			result = m_Op1 * m_Op2; break;
		case 4:
			result = m_Op1 / m_Op2; break;
		case 5:
			result = pow(m_Op1,m_Op2); break;
		/*case 6:
			result = pow(log10(m_Op1),m_Op2); break;*/
		default:
			result = 0; break;
	}
	m_LcdNum = result;
	UpdateData(FALSE);
	keyflag = 0;
	dotflag = 0;
	myoperator = 0;
}


void CExCalculatorDlg::OnBnClickedButtAc()
{
	m_Lcd.SetWindowTextA("");
	dotflag = 0;
	keyflag = 0;
}


void CExCalculatorDlg::OnBnClickedButtBsp()
{
	CString str, bmp;
	m_Lcd.GetWindowTextA(str);
	int a = str.GetLength();
	if (a > 1) {
		char b = str[a - 1];
		if (b == '.') dotflag = 0;
		str.Delete(a - 1, 1);
		m_Lcd.SetWindowTextA(str);
	}

	else {
		m_Lcd.SetWindowTextA("0");
	}// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CExCalculatorDlg::OnBnClickedButtSignchnge()
{
	UpdateData(TRUE);
	m_LcdNum = -m_LcdNum;
	UpdateData(FALSE);
}


void CExCalculatorDlg::OnBnClickedButtFactorial()
{
	UpdateData(TRUE);
	double factVal = m_LcdNum;
	double factTotal = 1;
	if (factVal == 0)
		factTotal = 1;
	else {
		while (factVal > 0) {
			factTotal = factTotal * factVal;
			factVal--;
		}
	}
	m_LcdNum = factTotal;
	UpdateData(FALSE);
	dotflag = 0;
	keyflag = 0;
}


void CExCalculatorDlg::OnBnClickedButtSquare()
{
	UpdateData(TRUE);
	m_Op1 = m_LcdNum;
	m_LcdNum = m_Op1 * m_Op1;
	UpdateData(FALSE);
	dotflag = 0;
	keyflag = 0;// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CExCalculatorDlg::OnBnClickedButtSin()
{
	UpdateData(TRUE);
	double n;
	double pi = 3.1415926535897932386;
	m_Op1 = m_LcdNum;
	n = m_Op1 * pi / 180;
	m_LcdNum = sin(n);
	UpdateData(FALSE);
	dotflag = 0;
	keyflag = 0;// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CExCalculatorDlg::OnBnClickedButtCos()
{
	UpdateData(TRUE);
	double n;
	double pi = 3.1415926535897932386;
	m_Op1 = m_LcdNum;
	n = m_Op1 * pi / 180;
	m_LcdNum = cos(n);
	UpdateData(FALSE);
	dotflag = 0;
	keyflag = 0;// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CExCalculatorDlg::OnBnClickedButtLog()
{
	/*setOperator(6);*/
	/*UpdateData(TRUE);
	m_Op1 = m_LcdNum;
	m_LcdNum = log10(m_Op1);
	UpdateData(FALSE);
	dotflag = 0;
	keyflag = 0;*/  // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CExCalculatorDlg::OnBnClickedButtExp()
{
	
	setOperator(5);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
