// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             //  �� Windows ͷ�ļ����ų�����ʹ�õ���Ϣ
// Windows ͷ�ļ�: 
#include <windows.h>

// C ����ʱͷ�ļ�
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�
#include "Resource.h"
#ifdef _DEBUG
#include "vld.h"
#endif

#include "SunFun.h"
#include "MyOutputDebugString.h"

#include "../ffplayer/ffplayer.h"

#include "../DuiLib/UIlib.h"
using namespace DuiLib;

#define PROGRESSTIMER						666

#define safe_delete(p) do{ delete p; p=NULL; } while(false) 
