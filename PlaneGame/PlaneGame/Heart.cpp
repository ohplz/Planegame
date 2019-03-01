#include "stdafx.h"
#include "Heart.h"
#include "resource.h"

CImageList CHeart::m_Images;

CHeart::CHeart(int x, int y) :CGameObject(x, y)
{
}


CHeart::~CHeart()
{
}
BOOL CHeart::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_HEART, RGB(0, 0, 0), 40, 40, 2);
}
BOOL CHeart::Draw(CDC* pDC, BOOL bPause)
{
	if (!bPause)
	{
		m_ptPos.y = m_ptPos.y + 8;
	}

	if (m_ptPos.y > GAME_HEIGHT + HEART_HEIGHT)
		return FALSE;
	if (m_ptPos.y < -HEART_HEIGHT)
		return FALSE;

	m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);

	return TRUE;
}