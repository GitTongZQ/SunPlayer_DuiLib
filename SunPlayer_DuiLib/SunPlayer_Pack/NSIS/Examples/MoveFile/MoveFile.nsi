;Unicode��Ansi�汾ͨ���ƶ������ļ�(��)dll by ���벻��
;ʾ���ű� by �����

;ע:�ļ���·���벻Ҫ��\��β
;0=�����ļ�/�ļ��� 
;1=�ƶ��ļ�/�ļ��� 
;? u=������ɺ�����ж��dll����ε��ÿ������һ��ʱ��

!define PRODUCT_NAME "�ƶ������ļ�(��)"

SetCompressor lzma

Name "${PRODUCT_NAME}"
OutFile "${PRODUCT_NAME}.exe"
SilentInstall silent
Section
    Strcpy $R1 "$EXEDIR\abc"
    Strcpy $R2 "$EXEDIR\123"
	  StrCmp $R1 $R2 +6 +1   ;���Ŀ¼��ͬ��ת��
    System::Call 'MoveFile::MoveFile_Ex(i1,mR1,mR2)m.R0 ? u'
    StrCmp $R0 "error" +2 +1
    StrCmp $R0 "��" +1 +2
		MessageBox MB_ICONINFORMATION|MB_OK "ʧ�ܣ�"
		MessageBox MB_ICONINFORMATION|MB_OK "�ɹ���"
SectionEnd

Function .onInit
 	InitPluginsDir
	File /oname=$PLUGINSDIR\MoveFile.dll "${NSISDIR}\Plugins\MoveFile.dll"
  System::Call 'kernel32::LoadLibraryA(m "$PLUGINSDIR\MoveFile.dll")'  ;��DLL���ص��ڴ�
FunctionEnd
