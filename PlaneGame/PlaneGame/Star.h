#pragma once
#include "GameObject.h"

class CStar :public CGameObject
{
public:
	CStar(int x,int y);
	~CStar(void);

	BOOL Draw(CDC* pDC, BOOL bPause);

	static BOOL LoadImage();

	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + STAR_HEIGHT, m_ptPos.y + STAR_HEIGHT));
	}

private:
	static const int STAR_HEIGHT = 30;
	static CImageList m_Images;

};

