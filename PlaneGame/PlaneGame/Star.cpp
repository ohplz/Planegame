#include "stdafx.h"
#include "Star.h"
#include "resource.h"

CImageList CStar::m_Images;
CStar::CStar(int x, int y) :CGameObject(x, y)
{

}


CStar::~CStar()
{
}
BOOL CStar::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_STAR, RGB(0, 0, 0), 30, 30, 2);
}
BOOL CStar::Draw(CDC* pDC, BOOL bPause)
{
	if (!bPause)
	{
		m_ptPos.y = m_ptPos.y + 10;
	}

	if (m_ptPos.y > GAME_HEIGHT + STAR_HEIGHT)
		return FALSE;
	if (m_ptPos.y < -STAR_HEIGHT)
		return FALSE;

	m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);

	return TRUE;
}