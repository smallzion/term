
// Chatting bot builder.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CChattingbotbuilderApp:
// �� Ŭ������ ������ ���ؼ��� Chatting bot builder.cpp�� �����Ͻʽÿ�.
//

class CChattingbotbuilderApp : public CWinApp
{
public:
	CChattingbotbuilderApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CChattingbotbuilderApp theApp;