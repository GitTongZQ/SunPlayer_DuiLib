; ��װ�����ʼ���峣��
!define PRODUCT_NAME "�ı�����������"
!define PRODUCT_VERSION "by �򵥹�����"
!define PRODUCT_PUBLISHER "My company, Inc."
!define PRODUCT_WEB_SITE "http://www.jjdd925.com"

SetCompressor /SOLID lzma
SetCompressorDictSize 32

Name "${PRODUCT_NAME} ${PRODUCT_VERSION}"
OutFile "�ı�����������.exe"
;InstallDir "$PROGRAMFILES\Hello Word"
Icon "Setup.ico"
SilentInstall silent
BrandingText " "
Section
  strcpy $R1 "$EXEDIR\hosts.txt"
  strcpy $R2 "1234567890"
  #### m=�ı��� i=������  (m,m,i)�������� (R1,R2,1) ������Ϣ ####  by ���벻��
  System::Call 'Stringplug::Text_ReplaceText_Ex(m,i,i,m,m)(R1,,,"CCTV","jjdd")m.R0 '  ## �ı�_�滻_Ex ����
  MessageBox MB_ICONINFORMATION|MB_OK $R0
SectionEnd

Function .onInit
  InitPluginsDir
  File /oname=$PLUGINSDIR\StringPlug.dll "StringPlug.dll"
  #��������ʱ�Զ���DLL���ص��ڴ�
  System::Call 'kernel32::LoadLibraryA(m "$PLUGINSDIR\StringPlug.dll")'
FunctionEnd

Function .onGUIEnd
  System::Free
FunctionEnd

