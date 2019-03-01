#include "stdafx.h"
#include "LifeLogo.h"
#include "resource.h"


CImageList CLifeLogo::m_Images;

CLifeLogo::CLifeLogo(int n) :m_n(n)
{
	m_ptPos.x = 25+m_n*30;
	m_ptPos.y = 33;
}


CLifeLogo::~CLifeLogo(void)
{
}
BOOL CLifeLogo::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_LIFELOGO, RGB(0, 0, 0), 25, 25, 1);
}
BOOL CLifeLogo::Draw(CDC* pDC, BOOL bPause)
{

	m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);
	return TRUE;
}