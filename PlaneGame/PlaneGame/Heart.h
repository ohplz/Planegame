#pragma once
#include "GameObject.h"

class CHeart :public CGameObject
{
public:
	CHeart(int x,int y);
	~CHeart(void);

	BOOL Draw(CDC* pDC, BOOL bPause);

	static BOOL LoadImage();

	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + HEART_HEIGHT, m_ptPos.y + HEART_HEIGHT));
	}

private:
	static const int HEART_HEIGHT = 40;
	static CImageList m_Images;

};

