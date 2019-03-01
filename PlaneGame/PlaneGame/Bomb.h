#pragma once
#include "gameobject.h"

class CBomb :
	public CGameObject
{
public:
	CBomb(int x,int y,int n);
	~CBomb(void);

	BOOL Draw(CDC* pDC,BOOL bPause);

	static BOOL LoadImage();

	CRect GetRect()
	{
		return CRect(m_ptPos,CPoint(m_ptPos.x+10,m_ptPos.y+BOMB_HEIGHT));
	}
private:
	static const int BOMB_HEIGHT = 36;
	static CImageList m_Images;
	int m_n;

};
