
// MFCApplication1Dlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
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


// CMFCApplication1Dlg 대화 상자



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
	, m_1(0)
	, m_3(0)
	, m_4(0)
	, m_55(_T("^"))
	, nSw(1)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT2, m_123);
	DDX_Control(pDX, IDC_EDIT5, m_1234);
	DDX_Control(pDX, IDC_EDIT6, m_12345);
	//  DDX_Text(pDX, IDC_EDIT1, m_1);
	//  DDX_Text(pDX, IDC_EDIT3, m_3);
	DDX_Text(pDX, IDC_EDIT1, m_1);
	DDX_Text(pDX, IDC_EDIT3, m_3);
	//  DDX_Control(pDX, IDC_EDIT4, m_5);
	DDX_Text(pDX, IDC_EDIT4, m_4);
	DDX_Control(pDX, IDC_EDIT1, m_11);
	DDX_Control(pDX, IDC_EDIT3, m_33);
	//  DDX_Text(pDX, IDC_EDIT2, m_22);
	//DDX_Control(pDX, IDC_EDIT4, m_44);
	DDX_Control(pDX, IDC_EDIT4, m_44);
	DDX_Text(pDX, IDC_EDIT5, m_55);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication1Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplication1Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCApplication1Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON9, &CMFCApplication1Dlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CMFCApplication1Dlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CMFCApplication1Dlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON13, &CMFCApplication1Dlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &CMFCApplication1Dlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON15, &CMFCApplication1Dlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON17, &CMFCApplication1Dlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication1Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCApplication1Dlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON12, &CMFCApplication1Dlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON16, &CMFCApplication1Dlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON19, &CMFCApplication1Dlg::OnBnClickedButton19)
	ON_EN_CHANGE(IDC_EDIT5, &CMFCApplication1Dlg::OnEnChangeEdit5)
	ON_EN_CHANGE(IDC_EDIT6, &CMFCApplication1Dlg::OnEnChangeEdit6)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication1Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication1Dlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT4, &CMFCApplication1Dlg::OnEnChangeEdit4)
	ON_BN_CLICKED(IDC_BUTTON18, &CMFCApplication1Dlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication1Dlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 메시지 처리기

BOOL CMFCApplication1Dlg::OnInitDialog()
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

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCApplication1Dlg::OnPaint()
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
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
void CMFCApplication1Dlg::AddDigit(char numkey)
{
	CString str, tmp;
	tmp.Format("%c", numkey);
	switch (nSw)
	{
	case 1:
		m_11.GetWindowTextA(str);
		if (str == '0' || keyflag == 0)
			str = tmp; 
		else
			str = str + tmp;
		m_11.SetWindowTextA(str);
		keyflag = 1;
		break;
	case 2:
		m_33.GetWindowTextA(str);
		if (str == '0' || keyflag == 0)
			str = tmp;
		else
			str = str + tmp;
		m_33.SetWindowTextA(str);
		keyflag = 1;
		break;
	}
}

void CMFCApplication1Dlg::setOperator(int opnum)
{
	UpdateData(TRUE);
	UpdateData(FALSE);

	myoperator = opnum;
}



void CMFCApplication1Dlg::OnBnClickedButton5()
{
	AddDigit('1');// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCApplication1Dlg::OnBnClickedButton6()
{
	AddDigit('2');// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCApplication1Dlg::OnBnClickedButton7()
{
	AddDigit('3');// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCApplication1Dlg::OnBnClickedButton9()
{
	AddDigit('4');// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCApplication1Dlg::OnBnClickedButton10()
{
	AddDigit('5');// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCApplication1Dlg::OnBnClickedButton11()
{
	AddDigit('6');// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCApplication1Dlg::OnBnClickedButton13()
{
	AddDigit('7');// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCApplication1Dlg::OnBnClickedButton14()
{
	AddDigit('8'); // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCApplication1Dlg::OnBnClickedButton15()
{
	AddDigit('9');// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCApplication1Dlg::OnBnClickedButton17()
{
	AddDigit('0');	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCApplication1Dlg::OnBnClickedButton2()
{
	setOperator(4);
	m_123.SetWindowTextA("/");// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCApplication1Dlg::OnBnClickedButton8()
{
	setOperator(3);
	m_123.SetWindowTextA("*");// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCApplication1Dlg::OnBnClickedButton12()
{
	setOperator(2);
	m_123.SetWindowTextA("-");// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCApplication1Dlg::OnBnClickedButton16()
{
	setOperator(1);
	m_123.SetWindowTextA("+");// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCApplication1Dlg::OnBnClickedButton19()
{
	double result;
	UpdateData(TRUE);
	switch (myoperator) {
	case 1:
		result = m_1 + m_3; break;
	case 2:
		result = m_1 - m_3; break;
	case 3:
		result = m_1 * m_3; break;
	case 4:
		result = m_1 / m_3; break;
	default:
		result = 0;
	}
	m_4 = result;
	UpdateData(FALSE);
	keyflag = 0;
	dotflag = 0;
// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCApplication1Dlg::OnEnChangeEdit5()
{
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCApplication1Dlg::OnEnChangeEdit6()
{
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCApplication1Dlg::OnBnClickedButton3()
{
	if (nBw == 0)
	{
		nSw = 1;
		m_1234.SetWindowTextA("^");
		m_12345.SetWindowTextA("");
		nBw =1 ;
		dotflag = 0;
		keyflag = 0;
	}

	else if (nBw == 1)
	{
		nSw = 2;
		m_12345.SetWindowTextA("^");
		m_1234.SetWindowTextA("");
		nBw =0;
		dotflag = 0;
		keyflag = 0;
	}
}



void CMFCApplication1Dlg::OnBnClickedButton1()
{
	CString str, bmp;
	if (nSw == 2)
	{
		m_33.GetWindowTextA(str);
		int a = str.GetLength();
		if (a > 1) {
			char b = str[a - 1];
			if (b == '.') dotflag = 0;
			str.Delete(a - 1, 1);
			m_33.SetWindowTextA(str);
		}

		else {
			m_33.SetWindowTextA("0");
		}
	}
	if (nSw == 1)
	{
		m_11.GetWindowTextA(str);
		int a = str.GetLength();
		if (a > 1) {
			char b = str[a - 1];
			if (b == '.') dotflag = 0;
			str.Delete(a - 1, 1);
			m_11.SetWindowTextA(str);
		}

		else {
			m_11.SetWindowTextA("0");
		}
	}
}


void CMFCApplication1Dlg::OnEnChangeEdit4()
{
	
}


void CMFCApplication1Dlg::OnBnClickedButton18()
{
	CString str, tmp;
	switch(nSw)
	{
	case 1:
		if (dotflag == 0) {
			tmp.Format("%c", '.');
			m_11.GetWindowTextA(str);
			if (keyflag == 0) {
				str = '0';
				keyflag = 1;
			}
			str = str + tmp;
			m_11.SetWindowTextA(str);
			dotflag = 1;
		}
		break;
	case 2:
		{
			if (dotflag == 0) {
				tmp.Format("%c", '.');
				m_33.GetWindowTextA(str);
				if (keyflag == 0) {
					str = '0';
					keyflag = 1;
				}
				str = str + tmp;
				m_33.SetWindowTextA(str);
				dotflag = 1;
			}

		}
		break;
	}
}


void CMFCApplication1Dlg::OnBnClickedButton4()
{
	UpdateData(TRUE);

	m_1 = m_4;
	m_3 = 0;
	m_4 = 0;

	UpdateData(FALSE);

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
