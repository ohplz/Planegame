#pragma once
#include "GameObject.h"

class CBasicBoss :public CGameObject
{
public:
	CBasicBoss(void);
	~CBasicBoss(void);
	BOOL Draw(CDC* pDC, BOOL bPause);

	static BOOL LoadImage();

	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + BasicBoss_WIDTH, m_ptPos.y + BasicBoss_HEIGHT));
	}

	int GetMontion() const
	{
		return m_nMotion;
	}
	//是否可以开火发射子弹
	BOOL Fired();
	int BasicBossLifeNum = 10;//BasicBoss生命值
	int BasicBossLifeFlag = 0;//判断是否显示血条用
private:
	static const int BasicBoss_WIDTH = 80;
	static const int BasicBoss_HEIGHT = 61;
	static CImageList m_Images;
	int    m_nMotion;//方向 1->向下 0->停止 -1->向上
	//图像索引
	int m_nImgIndex;
	//速度
	int m_V;
	int    m_nWait;//发射延时


};

