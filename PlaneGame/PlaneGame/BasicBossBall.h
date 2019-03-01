#pragma once
#include "GameObject.h"

class CBasicBossBall :public CGameObject
{
public:
	CBasicBossBall(int x, int y, int nMontion,int n);
	~CBasicBossBall(void);

	BOOL Draw(CDC* pDC, BOOL bPause);

	static BOOL LoadImage();

	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + BasicBossBall_HEIGHT, m_ptPos.y + BasicBossBall_HEIGHT));
	}
private:
	static const int BasicBossBall_HEIGHT = 15;
	static CImageList m_Images;
	int    m_nMotion;
	int    m_n;
};

