#pragma once
#include "GameObject.h"
class CStarNumLogo :
	public CGameObject
{
public:
public:
	CStarNumLogo(void);
	~CStarNumLogo(void);
	BOOL Draw(CDC* pDC, BOOL bPause);
	static BOOL LoadImage();
	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + 10, m_ptPos.y + HPLogo_HEIGHT));
	}
private:
	static const int HPLogo_HEIGHT = 14;
	static CImageList m_Images;
};

