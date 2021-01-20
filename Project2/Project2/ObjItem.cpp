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
CObjItem::CObjItem(float x, float y,int id)
{
	m_id = id;

	if (m_id ==1) //チャイナA
	{
		m_x = x;
		m_y = y;
	}
	if (m_id==2)//チャイナボス
	{
		m_x = x;
		m_y = y;
	}
	if (m_id ==3)//病院屋上
	{
		m_x = x;
		m_y = y;
	}
	if (m_id == 4)//研究所ボス前
	{
		m_x = x;
		m_y = y;
	}
	//　主人公がアイテム接触SE　音楽情報の読み込み
	Audio::LoadAudio(9, L"弾丸アイテム.wav", EFFECT);//単発
}


//イニシャライズ
void CObjItem::Init()
{


	if (m_id == 1) //チャイナA
	{
		//当たり判定用HitBoxを作成
		Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ITEM, OBJ_ITEM, 1);
	}

	if (m_id == 2) //チャイナボス
	{
		//当たり判定用HitBoxを作成
		Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ITEM, OBJ_ITEM, 1);
	}
	if (m_id == 3) //病院屋上
	{
		//当たり判定用HitBoxを作成
		Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ITEM, OBJ_ITEM, 1);
	}
	if (m_id == 4) //研究所ボス前
	{
		//当たり判定用HitBoxを作成
		Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ITEM, OBJ_ITEM, 1);
	}
	item_flag = false;
}

int CObjItem::m_bullet_item = 0;//弾丸の所持数

//アクション
void CObjItem::Action()
{
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);//拠点
	CObjChinaTown* chinatown = (CObjChinaTown*)Objs::GetObj(OBJ_CHINA_TOWN);//チャイナタウン
	CObjChinaTownBoss* chinatownboss = (CObjChinaTownBoss*)Objs::GetObj(OBJ_CHINA_TOWN_BOSS);//チャイナタウンボス
	CObjRooftop* rooftop = (CObjRooftop*)Objs::GetObj(OBJ_ROOF_TOP);//病院の屋上
	CObjInstitute13A* inst13a = (CObjInstitute13A*)Objs::GetObj(OBJ_INSTITUTE13A);//研究所地下2階



	if (m_id == 1) //チャイナA
	{
		//HitBoxの内容を更新
		CHitBox* hit = Hits::GetHitBox(this);
		hit->SetPos(m_x + chinatown->GetScroll(), m_y + chinatown->GetScroll2());

		//弾丸と接触してるかどうか調べる
		if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
		{
			Set_M_Bullet_Item(8);
			Set_M_Bullet_Item_Flag(true);
			Audio::Start(9);

			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}
	}
	if (m_id == 2) //チャイナボス
	{
		//HitBoxの内容を更新
		CHitBox* hit = Hits::GetHitBox(this);
		hit->SetPos(m_x + chinatownboss->GetScroll(), m_y + chinatownboss->GetScroll2());

		//弾丸と接触してるかどうか調べる
		if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
		{
			Set_M_Bullet_Item(8);
			Set_M_Bullet_Item_Flag(true);
			Audio::Start(9);

			this->SetStatus(false);
			Hits::DeleteHitBox(this);
			
		}
	}
	if (m_id == 3) //病院屋上
	{
		//HitBoxの内容を更新
		CHitBox* hit = Hits::GetHitBox(this);
		hit->SetPos(m_x + rooftop->GetScroll(), m_y + rooftop->GetScroll2());

		//弾丸と接触してるかどうか調べる
		if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
		{
			Set_M_Bullet_Item(8);
			Set_M_Bullet_Item_Flag(true);
			Audio::Start(9);

			this->SetStatus(false);
			Hits::DeleteHitBox(this);

		}
	}
	if (m_id == 4) //研究所ボス前
	{
		//HitBoxの内容を更新
		CHitBox* hit = Hits::GetHitBox(this);
		hit->SetPos(m_x + inst13a->GetScroll(), m_y + inst13a->GetScroll2());

		//弾丸と接触してるかどうか調べる
		if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
		{
			Set_M_Bullet_Item(8);
			Set_M_Bullet_Item_Flag(true);
			Audio::Start(9);

			this->SetStatus(false);
			Hits::DeleteHitBox(this);

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

	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	CObjChinaTown* chinatown = (CObjChinaTown*)Objs::GetObj(OBJ_CHINA_TOWN);
	CObjChinaTownBoss* chinatownboss = (CObjChinaTownBoss*)Objs::GetObj(OBJ_CHINA_TOWN_BOSS);
	CObjRooftop* rooftop = (CObjRooftop*)Objs::GetObj(OBJ_ROOF_TOP);//病院の屋上
	CObjInstitute13A* inst13a = (CObjInstitute13A*)Objs::GetObj(OBJ_INSTITUTE13A);//研究所地下2階


	if (chinatownboss!=nullptr)//弾丸アイテム
	{
		//切り取り位置の設定
		src.m_top = 24.0f;   //y
		src.m_left = 30.0f; //x
		src.m_right = 226.0f; //x
		src.m_bottom = 222.0f; //y

		//表示位置の設定
		dst.m_top =0.0f + m_y + chinatownboss->GetScroll2();
		dst.m_left =0.0f + m_x + chinatownboss->GetScroll();
		dst.m_right =32.0f + m_x + chinatownboss->GetScroll();
		dst.m_bottom =32.0f + m_y + chinatownboss->GetScroll2();

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
	if (rooftop != nullptr)//弾丸アイテム
	{
		//切り取り位置の設定
		src.m_top = 24.0f;   //y
		src.m_left = 30.0f; //x
		src.m_right = 226.0f; //x
		src.m_bottom = 222.0f; //y

		//表示位置の設定
		dst.m_top = 0.0f + m_y + rooftop->GetScroll2();
		dst.m_left = 0.0f + m_x + rooftop->GetScroll();
		dst.m_right = 32.0f + m_x + rooftop->GetScroll();
		dst.m_bottom = 32.0f + m_y + rooftop->GetScroll2();

		//描画
		Draw::Draw(12, &src, &dst, c, 0.0f);
	}
	if (inst13a != nullptr)//弾丸アイテム
	{
		//切り取り位置の設定
		src.m_top = 24.0f;   //y
		src.m_left = 30.0f; //x
		src.m_right = 226.0f; //x
		src.m_bottom = 222.0f; //y

		//表示位置の設定
		dst.m_top = 0.0f + m_y + inst13a->GetScroll2();
		dst.m_left = 0.0f + m_x + inst13a->GetScroll();
		dst.m_right = 32.0f + m_x + inst13a->GetScroll();
		dst.m_bottom = 32.0f + m_y + inst13a->GetScroll2();

		//描画
		Draw::Draw(9, &src, &dst, c, 0.0f);
	}
}

