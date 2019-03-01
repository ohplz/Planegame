#pragma once
#include "GameObject.h"

class CShield :public CGameObject
{
public:
	CShield(int x,int y);
	~CShield(void);
	BOOL Draw(CDC* pDC, BOOL bPause);

	static BOOL LoadImage();

	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + SHIELD_HEIGHT, m_ptPos.y + SHIELD_HEIGHT));
	}

private:
	static const int SHIELD_HEIGHT = 30;
	static CImageList m_Images;

};

