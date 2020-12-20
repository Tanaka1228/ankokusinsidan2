//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameL/DrawFont.h"
#include"GameL/WinInputs.h"
#include"GameL/UserData.h"
#include"GameL/Audio.h"

#include"GameHead.h"
#include"ObjItem.h"
#include"UtilityModule.h"
#include<fstream>


//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjItem::CObjItem(float x, float y)
{
	m_x = x;
	m_y = y;
}


//イニシャライズ
void CObjItem::Init()
{
	//当たり判定用HitBoxを作成
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ITEM, OBJ_ITEM, 1);
}

//アクション
void CObjItem::Action()
{
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);//拠点
	CObjChinaTown* chinatown = (CObjChinaTown*)Objs::GetObj(OBJ_CHINA_TOWN);//チャイナタウン
	CObjChinaTownBoss* chinatownboss = (CObjChinaTownBoss*)Objs::GetObj(OBJ_CHINA_TOWN_BOSS);//チャイナタウンボス
	CObjChinaTown_b* chinatown_b = (CObjChinaTown_b*)Objs::GetObj(OBJ_CHINA_TOWN_B);//チャイナタウンのB

	if (block != nullptr) 
	{
		//HitBoxの内容を更新
		CHitBox* hit = Hits::GetHitBox(this);
		hit->SetPos(m_x + block->GetScroll(), m_y + block->GetScroll2());

		//弾丸と接触してるかどうか調べる
		if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
			//Audio::Start(5);
		}
	}


	if (chinatown != nullptr)
	{
		//HitBoxの内容を更新
		CHitBox* hit = Hits::GetHitBox(this);
		hit->SetPos(m_x + chinatown->GetScroll(), m_y + chinatown->GetScroll2());

		//弾丸と接触してるかどうか調べる
		if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
			//Audio::Start(5);
		}
	}
}

//ドロー
void CObjItem::Draw()
{
	////描画カラー情報　R=RED G=Green B=Blue A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);//拠点
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	CObjChinaTown* chinatown = (CObjChinaTown*)Objs::GetObj(OBJ_CHINA_TOWN);
	CObjChinaTownBoss* chinatownboss = (CObjChinaTownBoss*)Objs::GetObj(OBJ_CHINA_TOWN_BOSS);
	CObjChinaTown_b* chinatown_b = (CObjChinaTown_b*)Objs::GetObj(OBJ_CHINA_TOWN_B);//チャイナタウンのB

	if (block!=nullptr)//弾丸アイテム
	{
		//切り取り位置の設定
		src.m_top = 24.0f;   //y
		src.m_left = 30.0f; //x
		src.m_right = 226.0f; //x
		src.m_bottom = 222.0f; //y

		//表示位置の設定
		dst.m_top =32.0f + block->GetScroll2();
		dst.m_left =32.0f + block->GetScroll();
		dst.m_right =32.0f + 32.0f+block->GetScroll();
		dst.m_bottom =32.0f+ 32.0f + block->GetScroll2();

		//描画
		Draw::Draw(12, &src, &dst, c, 0.0f);
	}

	if (chinatown!= nullptr)//弾丸アイテム
	{
		//切り取り位置の設定
		src.m_top = 24.0f;   //y
		src.m_left = 30.0f; //x
		src.m_right = 226.0f; //x
		src.m_bottom = 222.0f; //y

		//表示位置の設定
		dst.m_top = 0.0f + m_y + chinatown->GetScroll2();
		dst.m_left = 0.0f + m_x + chinatown->GetScroll();
		dst.m_right = 32.0f + m_x + chinatown->GetScroll();
		dst.m_bottom = 32.0f+m_y + chinatown->GetScroll2();

		//描画
		Draw::Draw(12, &src, &dst, c, 0.0f);
	}
}

