#pragma once
#include "GameObject.h"

class CLifeLogo :public CGameObject
{
public:
	CLifeLogo(int n);
	~CLifeLogo(void);
	BOOL Draw(CDC* pDC, BOOL bPause);
	static BOOL LoadImage();
	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + 10, m_ptPos.y + LifeLogo_HEIGHT));
	}
private:
	static const int LifeLogo_HEIGHT = 25;
	static CImageList m_Images;
	int m_n;
};

