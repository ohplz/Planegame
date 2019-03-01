#include "stdafx.h"
#include "BossBall.h"
#include "resource.h"

CImageList CBossBall::m_Images;

CBossBall::CBossBall(int x, int y, int nMontion, int n) :CGameObject(x, y), m_nMotion(nMontion), m_n(n)
{
}


CBossBall::~CBossBall(void)
{
}
BOOL CBossBall::Draw(CDC* pDC, BOOL bPause)
{
	if (!bPause)
	{

		if (m_n == 1)
		{
			m_ptPos.y = m_ptPos.y + m_nMotion * 10;
			m_ptPos.x = m_ptPos.x - m_nMotion * 5;
		}
		else if (m_n == 2)
		{
			m_ptPos.y = m_ptPos.y + m_nMotion * 10;
		}
		else if (m_n == 3)
		{
			m_ptPos.y = m_ptPos.y + m_nMotion * 10;
			m_ptPos.x = m_ptPos.x + m_nMotion * 5;
		}
	}

	if (m_ptPos.y > GAME_HEIGHT + BossBall_HEIGHT)
		return FALSE;
	if (m_ptPos.y < -BossBall_HEIGHT)
		return FALSE;

	
    m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);
	return TRUE;
}

BOOL CBossBall::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_BOSSBALL, RGB(0, 0, 0), 15, 15, 1);
}