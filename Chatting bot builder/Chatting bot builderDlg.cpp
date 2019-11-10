
// Chatting bot builderDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "Chatting bot builder.h"
#include "Chatting bot builderDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
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


// CChattingbotbuilderDlg ��ȭ ����



CChattingbotbuilderDlg::CChattingbotbuilderDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CHATTINGBOTBUILDER_DIALOG, pParent)
	, m_strQ(_T(""))
	, m_strA(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChattingbotbuilderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST, m_ListCtrl);
	DDX_Text(pDX, IDC_EDIT_Q, m_strQ);
	DDX_Text(pDX, IDC_EDIT_A, m_strA);
}

BEGIN_MESSAGE_MAP(CChattingbotbuilderDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(NEW_builder, &CChattingbotbuilderDlg::OnBnClickedbuilder)
	ON_BN_CLICKED(EXIST_builder, &CChattingbotbuilderDlg::OnBnClickedEXIST_builder)
	ON_LBN_SELCHANGE(IDC_LIST, &CChattingbotbuilderDlg::OnLbnSelchangeList)
	ON_BN_CLICKED(IDC_INSERT, &CChattingbotbuilderDlg::OnBnClickedInsert)
	ON_BN_CLICKED(IDC_DELETE, &CChattingbotbuilderDlg::OnBnClickedDelete)
END_MESSAGE_MAP()


// CChattingbotbuilderDlg �޽��� ó����

BOOL CChattingbotbuilderDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	CRect rt; // ����Ʈ ��Ʈ���� ũ�⸦ ������ ����

	m_ListCtrl.GetWindowRect(&rt);
	m_ListCtrl.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT); // ����Ʈ ��Ʈ�ѿ� ��ǥ�� �� Item ���ý� ���� ��ü ����

	m_ListCtrl.InsertColumn(1, TEXT("����"), LVCFMT_CENTER, rt.Width()*0.5); // ù��°
	m_ListCtrl.InsertColumn(2, TEXT("�亯"), LVCFMT_CENTER, rt.Width()*0.5); // �ι�°

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CChattingbotbuilderDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CChattingbotbuilderDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CChattingbotbuilderDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CChattingbotbuilderDlg::OnBnClickedbuilder()
{
	BROWSEINFO BrInfo;
	TCHAR szBuffer[512];                                   

	::ZeroMemory(&BrInfo, sizeof(BROWSEINFO));
	::ZeroMemory(szBuffer, 512);

	BrInfo.hwndOwner = GetSafeHwnd();
	BrInfo.lpszTitle = _T("������ ����� ������ �����ϼ���");
	BrInfo.ulFlags = BIF_NEWDIALOGSTYLE | BIF_EDITBOX | BIF_RETURNONLYFSDIRS;
	LPITEMIDLIST pItemIdList = ::SHBrowseForFolder(&BrInfo);
	::SHGetPathFromIDList(pItemIdList, szBuffer);				

	CString str;
	str.Format(_T("%s"), szBuffer);
	if (pItemIdList != NULL)
	{
		AfxMessageBox(str);
		GetDlgItem(IDC_LIST)->ShowWindow(TRUE);
		GetDlgItem(EXIST_builder)->ShowWindow(FALSE);
		GetDlgItem(NEW_builder)->ShowWindow(FALSE);
		GetDlgItem(IDC_INSERT)->ShowWindow(TRUE);
		GetDlgItem(IDC_DELETE)->ShowWindow(TRUE);
		GetDlgItem(IDC_Q)->ShowWindow(TRUE);
		GetDlgItem(IDC_A)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_Q)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_A)->ShowWindow(TRUE);
		CString strText = _T("������ �Է����ּ���.");
	}
}


void CChattingbotbuilderDlg::OnBnClickedEXIST_builder()
{
	static TCHAR BASED_CODE szFilter[] = _T("python����(*.py) | *.py;|�������(*.*)|*.*||");
	CFileDialog dlg(TRUE, _T("*.py"), _T("test"), OFN_HIDEREADONLY, szFilter);
	if (IDOK == dlg.DoModal())
	{
		CString pathName = dlg.GetPathName();
		MessageBox(pathName);
		GetDlgItem(IDC_LIST)->ShowWindow(TRUE);
		GetDlgItem(EXIST_builder)->ShowWindow(FALSE);
		GetDlgItem(NEW_builder)->ShowWindow(FALSE);
		GetDlgItem(IDC_INSERT)->ShowWindow(TRUE);
		GetDlgItem(IDC_DELETE)->ShowWindow(TRUE);
		GetDlgItem(IDC_Q)->ShowWindow(TRUE);
		GetDlgItem(IDC_A)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_Q)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_A)->ShowWindow(TRUE);
	}
}


void CChattingbotbuilderDlg::OnLbnSelchangeList()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}




void CChattingbotbuilderDlg::OnBnClickedInsert()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(true);
	int nitemNum = m_ListCtrl.GetItemCount();
	CString str_q = m_strQ;
	CString str_a = m_strA;

	m_ListCtrl.InsertItem(nitemNum, str_q, rand() % 5);
	m_ListCtrl.SetItemText(nitemNum, 1, str_a);

	m_strQ = _T("");
	m_strA = _T("");
	
	UpdateData(false);
}


void CChattingbotbuilderDlg::OnBnClickedDelete()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int count = m_ListCtrl.GetItemCount();

	for (int i = count; i >= 0; i--)
	{
		if (m_ListCtrl.GetItemState(i, LVIS_SELECTED) != 0)
		{
			m_ListCtrl.DeleteItem(i);
		}
	}
}
