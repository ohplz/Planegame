#include "stdafx.h"
#include "Boss.h"
#include "resource.h"

CImageList CBoss::m_Images;

CBoss::CBoss()
{
	//确定y位置
	m_ptPos.y = 100;

	//随机确定图像索引
	m_nImgIndex = rand() % 2;

	//根据图像索引确定方向
	m_nMotion = 1;
	m_nMotionX = 1;
	m_nMotionY = 1;
	m_ptPos.x = 255;

	//确定速度
	m_V = 3;

	m_nWait = 0;
}


CBoss::~CBoss()
{
}
BOOL CBoss::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_Boss, RGB(0, 0, 0), 200, 200, 1);
}
BOOL CBoss::Draw(CDC* pDC, BOOL bPause)
{
	m_nWait++;
	if (m_nWait>2)
		m_nWait = 0;

	if (!bPause)
	{
		m_ptPos.x = m_ptPos.x + m_nMotionX * m_V;
		m_ptPos.y = m_ptPos.y + m_nMotionY * m_V;
	}

	if (m_ptPos.x >= GAME_WIDTH - Boss_WIDTH  || m_ptPos.x <= 0)

		m_nMotionX = -m_nMotionX;
	if (m_ptPos.y >= GAME_HEIGHT - 500 || m_ptPos.y <= 0)
		m_nMotionY = -m_nMotionY;


	m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);


	return TRUE;
}
BOOL CBoss::Fired()
{
	if (m_nWait == 0)
		return TRUE;
	else
		return FALSE;
}
