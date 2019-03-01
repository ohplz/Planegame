#pragma once
#include "GameObject.h"

class CBossBall :public CGameObject
{
public:
	CBossBall(int x, int y, int nMontion, int n);
	~CBossBall(void);

	BOOL Draw(CDC* pDC, BOOL bPause);

	static BOOL LoadImage();

	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + BossBall_HEIGHT, m_ptPos.y + BossBall_HEIGHT));
	}
private:
	static const int BossBall_HEIGHT = 15;
	static CImageList m_Images;
	int    m_nMotion;
	int    m_n;
	int time;
	int appear1;
	int number1;
	int flag = 0;
};

