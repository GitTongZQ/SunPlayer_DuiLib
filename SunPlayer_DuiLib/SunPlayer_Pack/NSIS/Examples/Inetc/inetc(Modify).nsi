;��ԭ�����е����ؽ��������м��Ƶ������棬����������ԭ����ȡ����ť��
;�������Ȱ�PluginsĿ¼�е�inetc(Modify).dll������Ϊinetc.dll�ٱ��롣

XPStyle on
Name "Inetc Test"
OutFile "Inetc.exe"

!include "MUI.nsh"

!insertmacro MUI_PAGE_WELCOME
!insertmacro MUI_PAGE_INSTFILES
!insertmacro MUI_LANGUAGE "English"

ShowInstDetails nevershow

Section "Dummy Section" SecDummy
  inetc::get /TRANSLATE "�������� %s" "��������..." �� �� ʱ s "����ɣ�%dkB (%d%%) ��С��%dkB  �ٶȣ�%d.%01dkB/s" "(ʣ�ࣺ%d %s%s)" 'http://appldnld.apple.com/iTunes10/041-6239.20120611.Cdre4/iTunesSetup.exe' '$TEMP\iTunesSetup.exe'
  ExecWait '$TEMP\iTunesSetup.exe /quiet /norestart' $R1
  Delete "$TEMP\iTunesSetup.exe"
SectionEnd


