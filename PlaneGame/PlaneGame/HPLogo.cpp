#include "stdafx.h"
#include "HPLogo.h"
#include "resource.h"


CImageList CHPLogo::m_Images;

CHPLogo::CHPLogo(void)
{
	m_ptPos.x = 0;
	m_ptPos.y = 10;
}


CHPLogo::~CHPLogo(void)
{
}
BOOL CHPLogo::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_HPLOGO, RGB(0, 0, 0), 35, 19, 1);
}
BOOL CHPLogo::Draw(CDC* pDC, BOOL bPause)
{
	m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);
	return TRUE;
}