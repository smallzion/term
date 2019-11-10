
// Chatting bot builderDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "Chatting bot builder.h"
#include "Chatting bot builderDlg.h"
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


// CChattingbotbuilderDlg 대화 상자



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


// CChattingbotbuilderDlg 메시지 처리기

BOOL CChattingbotbuilderDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	CRect rt; // 리스트 컨트롤의 크기를 가져올 변수

	m_ListCtrl.GetWindowRect(&rt);
	m_ListCtrl.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT); // 리스트 컨트롤에 선표시 및 Item 선택시 한행 전체 선택

	m_ListCtrl.InsertColumn(1, TEXT("질문"), LVCFMT_CENTER, rt.Width()*0.5); // 첫번째
	m_ListCtrl.InsertColumn(2, TEXT("답변"), LVCFMT_CENTER, rt.Width()*0.5); // 두번째

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CChattingbotbuilderDlg::OnPaint()
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
	BrInfo.lpszTitle = _T("파일이 저장될 폴더를 선택하세요");
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
		CString strText = _T("질문을 입력해주세요.");
	}
}


void CChattingbotbuilderDlg::OnBnClickedEXIST_builder()
{
	static TCHAR BASED_CODE szFilter[] = _T("python파일(*.py) | *.py;|모든파일(*.*)|*.*||");
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}




void CChattingbotbuilderDlg::OnBnClickedInsert()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int count = m_ListCtrl.GetItemCount();

	for (int i = count; i >= 0; i--)
	{
		if (m_ListCtrl.GetItemState(i, LVIS_SELECTED) != 0)
		{
			m_ListCtrl.DeleteItem(i);
		}
	}
}
