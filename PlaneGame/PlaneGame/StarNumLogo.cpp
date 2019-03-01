#include "stdafx.h"
#include "StarNumLogo.h"
#include "resource.h"


CImageList CStarNumLogo::m_Images;

CStarNumLogo::CStarNumLogo(void)
{
	m_ptPos.x = 0;
	m_ptPos.y = 75;
}


CStarNumLogo::~CStarNumLogo(void)
{
}
BOOL CStarNumLogo::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_STARNUMLOGO, RGB(0, 0, 0), 30, 30, 1);
}
BOOL CStarNumLogo::Draw(CDC* pDC, BOOL bPause)
{
	m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);
	return TRUE;
}