
// MFCApplication1Dlg.h: 헤더 파일
//

#pragma once


// CMFCApplication1Dlg 대화 상자
class CMFCApplication1Dlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCApplication1Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int nSw = 0;
	int nBw = 0;
	void AddDigit(char numkey);
	int dotflag = 0;
	int keyflag = 0;
	int myoperator = 0;
	void setOperator(int opnum);
	CEdit m_123;
	CEdit m_1234;
	CEdit m_12345;

	double m_1;
	double m_3;

	double m_4;
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton13();
	afx_msg void OnBnClickedButton14();
	afx_msg void OnBnClickedButton15();
	afx_msg void OnBnClickedButton17();
	CEdit m_11;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton16();
	afx_msg void OnBnClickedButton19();
	CEdit m_33;

	afx_msg void OnEnChangeEdit5();
	afx_msg void OnEnChangeEdit6();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnBnClickedButton18();
	CEdit m_44;
	afx_msg void OnBnClickedButton4();
	CString m_55;
};
