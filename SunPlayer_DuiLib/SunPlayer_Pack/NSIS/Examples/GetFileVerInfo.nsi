!include "FileVerInfo.nsh"

Name "GetFileVerInfo"
Caption "$(^Name)"
OutFile "GetFileVerInfo.exe"
XPStyle on

Function .onGUIInit

  StrCpy $0 "�ļ� $WINDIR\notepad.exe �İ汾��Ϣ��$\r$\n"

  ${GetProductName} "$WINDIR\notepad.exe" $R0
  StrCpy $0 "$0$\r$\n - ��Ʒ���� (ProductName): $R0"

  ${GetComments} "$WINDIR\notepad.exe" $R0
  StrCpy $0 "$0$\r$\n - ��ע (Comments): $R0"

  ${GetCompanyName} "$WINDIR\notepad.exe" $R0
  StrCpy $0 "$0$\r$\n - ��˾ (CompanyName): $R0"

  ${GetLegalCopyright} "$WINDIR\notepad.exe" $R0
  StrCpy $0 "$0$\r$\n - ��Ȩ (LegalCopyright): $R0"

  ${GetFileDescription} "$WINDIR\notepad.exe" $R0
  StrCpy $0 "$0$\r$\n - ���� (FileDescription): $R0"

  ${GetFileVersion} "$WINDIR\notepad.exe" $R0
  StrCpy $0 "$0$\r$\n - �ļ��汾 (FileVersion): $R0"

  ${GetProductVersion} "$WINDIR\notepad.exe" $R0
  StrCpy $0 "$0$\r$\n - ��Ʒ�汾 (ProductVersion): $R0"

  ${GetInternalName} "$WINDIR\notepad.exe" $R0
  StrCpy $0 "$0$\r$\n - �ڲ����� (InternalName): $R0"

  ${GetLegalTrademarks} "$WINDIR\notepad.exe" $R0
  StrCpy $0 "$0$\r$\n - �Ϸ��̱� (LegalTrademarks): $R0"

  ${GetOriginalFilename} "$WINDIR\notepad.exe" $R0
  StrCpy $0 "$0$\r$\n - Դ�ļ��� (OriginalFilename): $R0"

  ${GetPrivateBuild} "$WINDIR\notepad.exe" $R0
  StrCpy $0 "$0$\r$\n - �������ڲ��汾˵�� (PrivateBuild): $R0"

  ${GetSpecialBuild} "$WINDIR\notepad.exe" $R0
  StrCpy $0 "$0$\r$\n - �����ڲ��汾˵�� (SpecialBuild): $R0"

  ${GetUserDefined} "ProductBuild" "$WINDIR\notepad.exe" $R0
  StrCpy $0 "$0$\r$\n - ProductBuild (�Զ���汾��): $R0"

  MessageBox MB_OK|MB_ICONINFORMATION $0

  Quit

FunctionEnd

Section -Main

SectionEnd