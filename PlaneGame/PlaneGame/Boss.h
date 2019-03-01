#pragma once
#include "GameObject.h"

class CBoss :public CGameObject
{
public:
	CBoss(void);
	~CBoss(void);
	BOOL Draw(CDC* pDC, BOOL bPause);

	static BOOL LoadImage();

	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + Boss_HEIGHT, m_ptPos.y + Boss_HEIGHT));
	}

	int GetMontion() const
	{
		return m_nMotion;
	}
	//是否可以开火发射子弹
	BOOL Fired();
	int BossLifeNum = 900;//Boss生命值
	int BossLifeFlag = 0;//判断是否显示血条用
private:
	static const int Boss_HEIGHT = 200;
	static const int Boss_WIDTH = 200;
	static CImageList m_Images;
	int    m_nMotion;//方向 1->向下 0->停止 -1->向上
	//图像索引
	int m_nImgIndex;
	//速度
	int m_V;
	int    m_nWait;//发射延时
	int   m_nMotionX;
	int   m_nMotionY;

};

