/*
Email��ַ��ʽУ����ʾ��
by Ansifa
*/
OutFile "Email validation Test.EXE"
Name "Email validation Test"
Section
EmailValidation::EmailValidation pippo@gino.com
pop $R0
StrCmp $R0 "failed" +1 +3
MessageBox MB_OK 'Email��ַ��ʽ����ȷ'
Goto +2
MessageBox MB_OK 'Email��ַ��ʽ��ȷ'
SectionEnd
