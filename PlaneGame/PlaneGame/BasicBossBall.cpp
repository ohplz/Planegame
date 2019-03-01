#include "stdafx.h"
#include "BasicBossBall.h"
#include "resource.h"

CImageList CBasicBossBall::m_Images;

CBasicBossBall::CBasicBossBall(int x, int y, int nMontion, int n) :CGameObject(x, y), m_nMotion(nMontion), m_n(n)
{
}

CBasicBossBall::~CBasicBossBall(void)
{
}


BOOL CBasicBossBall::Draw(CDC* pDC, BOOL bPause)
{
	if (!bPause)
	{
				if (m_n == 1)
					m_ptPos.y = m_ptPos.y + m_nMotion * 10;
				if (m_n == 2)
				{
					m_ptPos.y = m_ptPos.y + m_nMotion * 6;
					m_ptPos.x = m_ptPos.x + m_nMotion * 8;
				}
				if (m_n == 3)
				{
					m_ptPos.y = m_ptPos.y - m_nMotion * 6;
					m_ptPos.x = m_ptPos.x + m_nMotion * 8;
				}
				if (m_n == 4)
				{
					m_ptPos.y = m_ptPos.y + m_nMotion * 6;
					m_ptPos.x = m_ptPos.x - m_nMotion * 8;
				}
				if (m_n == 5)
				{
					m_ptPos.y = m_ptPos.y - m_nMotion * 6;
					m_ptPos.x = m_ptPos.x - m_nMotion * 8;
				}
				if (m_n == 6)
				{
					m_ptPos.y = m_ptPos.y - m_nMotion * 10;
				}
				if (m_n == 7)
				{
					m_ptPos.x = m_ptPos.x + m_nMotion * 10;
				}
				if (m_n == 8)
				{
					m_ptPos.x = m_ptPos.x - m_nMotion * 10;
				}
	}

	if (m_ptPos.y > GAME_HEIGHT + BasicBossBall_HEIGHT)
		return FALSE;
	if (m_ptPos.y < -BasicBossBall_HEIGHT)
		return FALSE;

	m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);

	return TRUE;
}

BOOL CBasicBossBall::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_BasicBossBall, RGB(0, 0, 0), 15, 15, 1);
}