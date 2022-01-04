﻿
// ExCalculatorDlg.h: 헤더 파일
//

#pragma once


// CExCalculatorDlg 대화 상자
class CExCalculatorDlg : public CDialogEx
{
// 생성입니다.
public:
	CExCalculatorDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EXCALCULATOR_DIALOG };
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
	void AddDigit(char numkey);
	int dotflag = 0;
	int keyflag = 0;
	int myoperator = 0;
	void setOperator(int opnum);
	CEdit m_Lcd;
	afx_msg void OnBnClickedButtD2();
	afx_msg void OnBnClickedButtD1();
	afx_msg void OnBnClickedButtD0();
	afx_msg void OnBnClickedButtD3();
	afx_msg void OnBnClickedButtD4();
	afx_msg void OnBnClickedButtD5();
	afx_msg void OnBnClickedButtD6();
	afx_msg void OnBnClickedButtD7();
	afx_msg void OnBnClickedButtD8();
	afx_msg void OnBnClickedButtD9();
	afx_msg void OnBnClickedButtDot();
	double m_LcdNum;
	double m_Op2;
	double m_Op1;
	afx_msg void OnBnClickedButtDiv();
	afx_msg void OnBnClickedButtMult();
	afx_msg void OnBnClickedButtSub();
	afx_msg void OnBnClickedButtAdd();
	afx_msg void OnBnClickedButtEq();
	afx_msg void OnBnClickedButtAc();
	afx_msg void OnBnClickedButtBsp();
	afx_msg void OnBnClickedButtSignchnge();
	afx_msg void OnBnClickedButtFactorial();
	afx_msg void OnBnClickedButtSquare();
	afx_msg void OnBnClickedButtSin();
	afx_msg void OnBnClickedButtCos();
	afx_msg void OnBnClickedButtLog();
	afx_msg void OnBnClickedButtExp();
};
