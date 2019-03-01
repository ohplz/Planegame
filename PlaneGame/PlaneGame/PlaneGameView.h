// PlaneGameView.h : CPlaneGameView 类的接口
//


#pragma once

class CMyPlane;
class CLifeLogo;
class CPlaneGameView : public CView
{

	enum ObjType{ enEnemy, enBomb, enBall, enExplosion, enBasicBoss, enBasicBossBall, enStar, enHeart, enShield, enBoss, enBossBall, enHPLogo, enLifeLogo, enStarNumLogo,enSkill };

protected: // 仅从序列化创建
	CPlaneGameView();
	DECLARE_DYNCREATE(CPlaneGameView)

// 属性
public:
	CPlaneGameDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CPlaneGameView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	//内存DC
	CDC*        m_pMemDC;
	//设备DC
	CClientDC*  m_pDC;
	//内存位图
	CBitmap*    m_pMemBitmap;


protected:
	//初始化游戏
	BOOL InitGame();
	//结束游戏
	void StopGame();

	//刷新游戏的帧画面
	void UpdateFrame(CDC* pMemDC);
	CDC m_cacheDC;//缓冲DC
	CBitmap m_cacheCBitmap;//缓冲位图
	int y = 0;

	void AI();

	//获得键的状态1->down
	int GetKey(int nVirtKey)
	{
		return (GetKeyState(nVirtKey) & 0x8000)? 1 : 0;
	}
	
	CMyPlane*  m_pMe;
	CLifeLogo* m_Life1 = NULL;
	CLifeLogo* m_Life2 = NULL;
	CLifeLogo* m_Life3 = NULL;

	CObList    m_ObjList[15];
	int PlayerScoreNum = 0;
	int PlaneLifeNum = 15;//飞机生命值
	int PlaneLife = 3;//飞机生命数
	int Planeflag = 0;//升级战机用
	int flag = 0;//绘制开始界面用flag
	int UnbeatableFlag = 0;//判定无敌模式用
	int BossFlag = 0;//使boss只产生一个
	int StarNum = 0;//星星数
	int StorageStarNum = 0;//存储星星数
	int StorageBossLifeNum = 0;//存储Boss生命值
	int n = 0;
	int ChapterFlag = 1;//关卡数
	int flag1 = 0;//控制Boss发射子弹的频率
	int LogoFlag = 0;//使logo只能产生一次
	int SuperFlag = 0;
	int MusicFlag = 0;
	int BossDieFlag = 0;
// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	bool DrawBG(CDC* pDC, UINT bmpID, CRect DestRect);
};

#ifndef _DEBUG  // PlaneGameView.cpp 中的调试版本
inline CPlaneGameDoc* CPlaneGameView::GetDocument() const
   { return reinterpret_cast<CPlaneGameDoc*>(m_pDocument); }
#endif

