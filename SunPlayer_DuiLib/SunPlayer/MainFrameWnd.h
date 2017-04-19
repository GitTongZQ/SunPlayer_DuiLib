#pragma once
#include "MediaPlay.h"

class CMainFrameWnd :
	public WindowImplBase
{
public:
	CMainFrameWnd();
	~CMainFrameWnd();

	virtual CDuiString GetSkinFile()	{ return _T("MainWnd.xml"); }
	virtual LPCTSTR GetWindowClassName(void) const override	{ return _T("MainFrameWnd"); }

	virtual void InitWindow() override;
	LRESULT OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) override;
	virtual void OnFinalMessage(HWND hWnd) override;
	virtual void OnClick(TNotifyUI& msg) override;
	virtual void Notify(TNotifyUI& msg) override;
	virtual LRESULT OnLButtonDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) override;
	virtual LRESULT OnMouseMove(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) override;
	virtual LRESULT OnLButtonUp(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) override;
	virtual LRESULT OnSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) override;
	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) override;
	virtual LRESULT HandleCustomMessage(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) override;


protected:
	LRESULT OnTimer(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnMenuClick(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnRButtonUp(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);	
	// ˫����ͣ����
	LRESULT OnLButtonDClick(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	void OnValueChanged(TNotifyUI& msg);
	void OnShowMenu(TNotifyUI &msg);
	bool IsPointInControl(POINT pt);
	void SetupPlayingUI();
	void ShowPlayBtn(bool bShow = true);
	void OnFFPlayerMSG(WPARAM wParam, LPARAM lParam);
	void SetTimeText(LONGLONG position, LONGLONG duration);
	// ���ļ�
	void OnOpen();
	// ��ͣ����
	void OnPause();
	// ����
	void OnPlay();
	// ֹͣ
	void OnStop();
	// ��һ��
	void OnNext();
	// ��һ��
	void OnPrevious();
	// ǰ��
	void OnForward();
	// ����
	void OnBackward();
	// ���Ž��ȵ���
	void Seek();
	// ��������
	void Volume();
	// ����
	void OnMute(bool bMute = true);
	// ����������ǰ
	void OnPin(bool bPin = true);
	// ȫ��
	void OnFullScreen(bool bFull = true);
	void UpdateFullBtns();


private:
	// ����������ʱλ��
	POINT m_LPoint;
	// �Ƿ�����ƶ�
	bool m_bMove;
	// ����
	int m_nAudioVolume;
	bool m_bMaxed;
	CMediaPlay m_player;
	CHorizontalLayoutUI *m_pAreaTitle;
	CHorizontalLayoutUI *m_pAreaCtrl;
	CHorizontalLayoutUI *m_pAreaPlay;
	CVerticalLayoutUI *m_pAreaLogo;
	CLabelUI *m_pLblTime;
	CLabelUI *m_pLblTitle;
	CSliderUI *m_pSliderPlay;
	CSliderUI *m_pSliderVolume;
	CButtonUI *m_pBtnPlay;
	CButtonUI *m_pBtnPause;
	CButtonUI *m_pBtnNext;
	CButtonUI *m_pBtnPrevious;	
	CButtonUI *m_pBtnBackward;
	CButtonUI *m_pBtnForward;
	CButtonUI *m_pBtnMute;
	CButtonUI *m_pBtnMuted;
	CButtonUI *m_pBtnDock;
	CButtonUI *m_pBtnDocked;
	CButtonUI *m_pBtnFull;
	CButtonUI *m_pBtnFull2;
	CButtonUI *m_pBtnExitFull;
	CButtonUI *m_pBtnExitFull2;
	CButtonUI *m_pBtnMenu;
	CMenuWnd *m_pMenu;
	CMenuElementUI *m_MenuVideoGDI;
	CMenuElementUI *m_MenuVideoD3D;

	CStdStringPtrMap m_MenuCheckInfo; //����˵��ĵ�ѡ��ѡ��Ϣ
};

