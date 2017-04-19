#pragma once
#include "stdafx.h"
#include <vector>
using namespace std;

class CFileUtil
{
public:
	CFileUtil(void);
	~CFileUtil(void);
public:

	//�򿪶Ի��� lpstrFilter�������ַ���   hwndOwner��������  fileNames�������ļ�·��;ʹ��ʾ��CFileUtil::OpenFile(L"mp3�ļ�\0*.mp3\0", m_hWnd, m_VecFileNames);
	static BOOL OpenFile(LPCWSTR lpstrFilter, HWND hwndOwner,vector<CDuiString> &fileNames, bool IsMulti = true);

	//����ļ��� path��·��  hwndOwner:������  tile:���ڱ���
	static BOOL BrowseDir(CDuiString &path,HWND hwndOwner,CDuiString title);

	//��һ��·����ѡ��һ���ļ�
	static void OpenDir(HWND hwndOwner,CDuiString path,CDuiString fileName);
};

