#include "FileUtil.h"
#include <commdlg.h>
#include <shlobj.h>
#include <shellapi.h>


CFileUtil::CFileUtil(void)
{
}


CFileUtil::~CFileUtil(void)
{
}

BOOL CFileUtil::OpenFile(LPCWSTR lpstrFilter, HWND hwndOwner, vector<CDuiString> &fileNames, bool IsMulti)
{
	DWORD dwFlag = IsMulti ? OFN_ALLOWMULTISELECT : 0;
	TCHAR szFileName[MAX_PATH * 101 + 1] = _T("");

	OPENFILENAME openfilename = {0};

	ZeroMemory(&openfilename, sizeof(OPENFILENAME));

	CDuiString s_title;

	openfilename.lStructSize       = sizeof(OPENFILENAME);
	openfilename.hwndOwner         = hwndOwner;
	openfilename.hInstance         = NULL;
	openfilename.lpstrFilter       = lpstrFilter;
	openfilename.lpstrCustomFilter = NULL;
	openfilename.nMaxCustFilter    = 0L;
	openfilename.nFilterIndex      = 1L;
	openfilename.lpstrFile         = szFileName;
	openfilename.nMaxFile          = MAX_PATH * 101 + 1;
	openfilename.lpstrFileTitle    = NULL;
	openfilename.nMaxFileTitle     = 0;
	openfilename.lpstrInitialDir   = NULL ;
	openfilename.lpstrTitle        = s_title;
	openfilename.nFileOffset       = 0;
	openfilename.nFileExtension    = 0;
	openfilename.lpstrDefExt       = _T("*.*");
	openfilename.lCustData         = 0;
	openfilename.Flags             = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_READONLY | OFN_EXPLORER | dwFlag;
	
	// �������ļ��ĶԻ���
	CDuiString str;

	if (::GetOpenFileName(&openfilename))
	{
		LPTSTR p = szFileName;
		CDuiString TempPath;
		if (*p != NULL)
		{
			TempPath =  p;
			p    += TempPath.GetLength() + 1;
		}

		if (*p == NULL)
		{
		//	TempPath = TempPath.Left(TempPath.ReverseFind(L'\\'));
			fileNames.push_back(TempPath);
		}


		while (*p != NULL)
		{
			CDuiString str = p;

			p += str.GetLength() + 1;

			fileNames.push_back(TempPath + _T("\\") + str);
		}

		return TRUE;
	}
	else
	{
		return FALSE;
	}

}

BOOL CFileUtil::BrowseDir(CDuiString &path,HWND hwndOwner,CDuiString title)
{
	TCHAR szPathName[MAX_PATH]; 
	BROWSEINFO bInfo={0};  
	bInfo.hwndOwner=hwndOwner;//������  
	bInfo.lpszTitle=title;  
	bInfo.ulFlags=BIF_RETURNONLYFSDIRS |BIF_USENEWUI/*����һ���༭�� �û������ֶ���д·�� �Ի�����Ե�����С֮���..*/|  
		BIF_UAHINT/*��TIPS��ʾ*/ |BIF_NONEWFOLDERBUTTON /*�����½��ļ��а�ť*/;  
	LPITEMIDLIST lpDlist;  
	lpDlist=SHBrowseForFolder(&bInfo);  
	if (lpDlist!=NULL)//������ȷ����ť  
	{  
		SHGetPathFromIDList(lpDlist,szPathName); 
		path.Format(_T("%s"),szPathName);  
		return TRUE;
	}else
	{
		return FALSE;
	}
}

void CFileUtil::OpenDir(HWND hwndOwner,CDuiString path,CDuiString fileName)
{
	CDuiString str;
	str.Format(L"/select,%s",path);
	str.Append(L"\\");
	str.Append(fileName);
	ShellExecute(hwndOwner,_T("open"),_T("Explorer.exe"),str,NULL,SW_SHOWNORMAL);
}

