#include "StdAfx.h"
#include "Bomb.h"
#include "resource.h"


CImageList CBomb::m_Images;


CBomb::CBomb(int x, int y, int n) :CGameObject(x, y), m_n(n)
{

}

CBomb::~CBomb(void)
{
}
BOOL CBomb::LoadImage()
{
	return CGameObject::LoadImage(m_Images,IDB_BITMAP3,RGB(0,0,0),15,36,1);
}
BOOL CBomb::Draw(CDC* pDC,BOOL bPause)
{
	if(!bPause)
	{
		if (m_n == 1 || m_n == 2)
		{
			m_ptPos.y = m_ptPos.y - 20;
		}
		else if (m_n == 3)
		{
			m_ptPos.y = m_ptPos.y - 20;
			m_ptPos.x = m_ptPos.x - 3;
		}
		else if (m_n == 4)
		{
			m_ptPos.y = m_ptPos.y - 20;
			m_ptPos.x = m_ptPos.x + 3;
		}
		
	}
	if(m_ptPos.y < -BOMB_HEIGHT)
		return FALSE;

	m_Images.Draw(pDC,0,m_ptPos,ILD_TRANSPARENT);

	return TRUE;
}