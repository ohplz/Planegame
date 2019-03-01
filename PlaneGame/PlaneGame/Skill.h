#pragma once
#include "GameObject.h"

class CSkill :public CGameObject
{
public:
	CSkill(void);
	~CSkill(void);
	BOOL Draw(CDC* pDC, BOOL bPause);
	static BOOL LoadImage();
	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + 10, m_ptPos.y + SkillLogo_HEIGHT));
	}
private:
	static const int SkillLogo_HEIGHT = 14;
	static CImageList m_Images;
};

