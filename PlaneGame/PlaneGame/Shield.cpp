#include "stdafx.h"
#include "Shield.h"
#include "resource.h"

CImageList CShield::m_Images;

CShield::CShield(int x, int y) :CGameObject(x, y)
{
}


CShield::~CShield()
{
}
BOOL CShield::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_SHIELD, RGB(0, 0, 0), 40, 40, 2);
}
BOOL CShield::Draw(CDC* pDC, BOOL bPause)
{
	if (!bPause)
	{
		m_ptPos.y = m_ptPos.y + 9;
	}

	if (m_ptPos.y > GAME_HEIGHT + SHIELD_HEIGHT)
		return FALSE;
	if (m_ptPos.y < -SHIELD_HEIGHT)
		return FALSE;

	m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);

	return TRUE;
}