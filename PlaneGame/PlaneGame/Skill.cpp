#include "stdafx.h"
#include "Skill.h"
#include "resource.h"


CImageList CSkill::m_Images;

CSkill::CSkill(void)
{
	m_ptPos.x = 0;
	m_ptPos.y = 150;
}


CSkill::~CSkill(void)
{
}
BOOL CSkill::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_SKILLLOGO, RGB(0, 0, 0), 42, 164, 1);
}
BOOL CSkill::Draw(CDC* pDC, BOOL bPause)
{
	m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);
	return TRUE;
}