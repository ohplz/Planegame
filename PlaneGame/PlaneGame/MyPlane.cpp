#include "StdAfx.h"
#include "MyPlane.h"
#include "resource.h"

CImageList CMyPlane::m_Images;
CImageList CMyPlane::p_Images;

CMyPlane::~CMyPlane(void)
{
}
CMyPlane::CMyPlane(void):m_nHorMotion(0),m_nVerMotion(0)
{
	m_nWait = 0;
	m_ptPos.x = 255;
	m_ptPos.y = 600;
	appear1 = 0;
	number1 = 0;
	time = 0;
}

BOOL CMyPlane::Fired()
{
	if(m_nWait==0)
		return TRUE;
	else
		return FALSE;

}
BOOL CMyPlane::LoadImage()
{
	return CGameObject::LoadImage(m_Images,IDB_BITMAP5,RGB(0,0,0),65,54,1);
}
BOOL CMyPlane::LoadImageShield()
{
	return CGameObject::LoadImage(p_Images, IDB_BITMAP9, RGB(0, 0, 0), 100, 100, 1);
}
BOOL CMyPlane::Draw(CDC* pDC,BOOL bPause)
{
	m_nWait++;
	if(m_nWait>3)
		m_nWait=0;
	
	if(!bPause)
	{
		m_ptPos.x = m_ptPos.x + m_nHorMotion*10;
		m_ptPos.y = m_ptPos.y - m_nVerMotion*10;
	}
    time++;
	if (ShieldFlag == 1)
	{
		p_Images.Draw(pDC, 0, CPoint(m_ptPos.x - 18, m_ptPos.y - 22), ILD_TRANSPARENT);
		if (time % 3 == 0)
			appear1++;
	}
	if (appear1 == 4)
	{
		number1++;
		appear1 = 0;
	}
	if (number1 == 12)
	{
		appear1 = 0;
		number1 = 0;
		ShieldFlag = 0;
		ShieldFlag1 = 0;
		RFlag = 0;
	}
	if(m_ptPos.x>=GAME_WIDTH-PLANE_WIDTH)
		m_ptPos.x =GAME_WIDTH-PLANE_WIDTH;
	if(m_ptPos.x<=0)
		m_ptPos.x=0;

	if(m_ptPos.y<=0)
		m_ptPos.y =0;

	if(m_ptPos.y>=GAME_HEIGHT-PLANE_HEIGHT)
		m_ptPos.y=GAME_HEIGHT-PLANE_HEIGHT;


	m_Images.Draw(pDC,0,m_ptPos,ILD_TRANSPARENT);
	
		
	return TRUE;
}