
// Chatting bot builderDlg.h : 헤더 파일
//

#pragma once
#include "afxcmn.h"


// CChattingbotbuilderDlg 대화 상자
class CChattingbotbuilderDlg : public CDialogEx
{
// 생성입니다.
public:
	CChattingbotbuilderDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHATTINGBOTBUILDER_DIALOG };
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
	afx_msg void OnBnClickedbuilder();
	afx_msg void OnBnClickedEXIST_builder();
	afx_msg void OnLbnSelchangeList();
	CListCtrl m_ListCtrl; //리스트 컨트롤 변수
};
