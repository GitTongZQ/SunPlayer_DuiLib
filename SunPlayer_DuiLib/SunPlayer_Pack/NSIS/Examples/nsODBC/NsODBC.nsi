/*nsODBC Test
By Ansifa*/
!AddPluginDir "..\..\Plugins"
OutFile "nsODBC Test.EXE"
Section
	;����ϵͳDSN������foo_DB�����ݿ��ļ�$EXEDIR\foo.mdb
nsODBC::AddSysDSN "Microsoft Access Driver (*.mdb)" "DSN=foo_DB" "DBQ=$EXEDIR\foo.mdb"

	;ɾ������Ϊfoo_DB��ϵͳDSN
;nsODBC::RemoveSysDSN "Microsoft Access Driver (*.mdb)" "DSN=foo_DB"

;	�����У� [DriverName] Parameters pairs follows: [DSN=XXX] [UID=0x777] ...
;	����ʹ�÷����μ�������ַ��
;	http://support.microsoft.com/kb/126606/EN-US/
SectionEnd
