
// Chatting bot builderDlg.h : ��� ����
//

#pragma once
#include "afxcmn.h"


// CChattingbotbuilderDlg ��ȭ ����
class CChattingbotbuilderDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CChattingbotbuilderDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHATTINGBOTBUILDER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedbuilder();
	afx_msg void OnBnClickedEXIST_builder();
	afx_msg void OnLbnSelchangeList();
	CListCtrl m_ListCtrl; //����Ʈ ��Ʈ�� ����
};
