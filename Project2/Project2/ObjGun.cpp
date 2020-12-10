//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameL/SceneObjManager.h"
#include"GameL/SceneManager.h"
#include"GameHead.h"
#include"ObjGun.h"
#include"UtilityModule.h"
#include"GameL/WinInputs.h"
#include"GameL/DrawFont.h"
//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjGun::CObjGun()//コンストラクタで受け取った情報を変数に送る
{
	
}


//イニシャライズ
void CObjGun::Init()
{
	m_ani_frame = 2;
	m_bullet = 6;
	m_bullet_held = 30;
	m_f =true;
}

//アクション
void CObjGun::Action()
{
	CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	m_ani_frame = obj->Get_AniFlame();
	//m_bullet = obj->Get_M_Bullet();//弾丸数
	//m_bullet_held = obj->Get_M_Bullet_Held();//所持数
}

//ドロー
void CObjGun::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	m_ani_frame = obj->Get_AniFlame();//主人公の向きの情報

	if (obj->Get_Gun()== 1)//ハンドガン
	{
		Font::StrDraw(L"構えている", obj->GetX(), -32 + obj->GetY(), 16, c);

		if (m_ani_frame == 2)
		{
			float c[4] = { 1.0f,1.0f,1.0f,1.0f };
			RECT_F src;
			RECT_F dst;

			//切り取り位置の設定
			src.m_top = 0.0f;   //y
			src.m_left = 0.0f; //x
			src.m_right = 32.0f; //x
			src.m_bottom = 32.0f; //y

			//表示位置の設定
			dst.m_top = 10.0f + obj->GetY();
			dst.m_left = 20.0f + obj->GetX();
			dst.m_right = 60.0f + obj->GetX();
			dst.m_bottom = 50.0f + obj->GetY();

			Draw::Draw(2, &src, &dst, c, 0.0f);
		}
		else if (m_ani_frame == 3)//左
		{
			//切り取り位置の設定
			src.m_top = 0.0f;   //y
			src.m_left = 33.0f; //x
			src.m_right = 61.0f; //x
			src.m_bottom = 18.0f; //y

			//表示位置の設定
			dst.m_top = 10.0f + obj->GetY();
			dst.m_left = -28.0f + obj->GetX();
			dst.m_right = 0.0f + 9.0f + obj->GetX();
			dst.m_bottom = 32.0f + obj->GetY();

			Draw::Draw(2, &src, &dst, c, 0.0f);
		}
		else if (m_ani_frame == 0)//正面
		{
			//切り取り位置の設定
			src.m_top = 3.0f;   //y
			src.m_left = 74.0f; //x
			src.m_right = 83.0f; //x
			src.m_bottom = 21.0f; //y

			//表示位置の設定
			dst.m_top = 10.0f + obj->GetY();
			dst.m_left = 5.0f + obj->GetX();
			dst.m_right = 20.0f + obj->GetX();
			dst.m_bottom = 32.0f + obj->GetY();

			Draw::Draw(2, &src, &dst, c, 0.0f);
		}
	}
	else if (obj->Get_Gun() == 0)
	{
		Font::StrDraw(L"構えていない", obj->GetX(), -32 + obj->GetY(), 16, c);

		if (Input::GetVKey('Z') == true)
		{
			Font::StrDraw(L"キックテスト", obj->GetX(), 32 + obj->GetY(), 16, c);
		}
	}

	//リボルバー
	if (obj->Get_GunType() == 0)
	{
		wchar_t guntype0[32];
		swprintf_s(guntype0, L"リボルバー : %d / 6", obj->Get_M_Bullet());
		Font::StrDraw(guntype0, 10, 560, 22, c);// X  Y 大きさ 

		wchar_t strb0[64];
		swprintf_s(strb0, L"弾丸所持数 : %d発", obj->Get_M_Bullet_Held());
		Font::StrDraw(strb0, 300.0f, 560, 22, c);// X  Y  大きさ 

	}
	//アサルト
	if (obj->Get_GunType() == 1)
	{
		wchar_t guntype1[32];
		swprintf_s(guntype1, L"アサルト : %d / 30", obj->Get_M_Ass_Bullet());
		Font::StrDraw(guntype1, 10, 560, 22, c);// X  Y 大きさ 

		wchar_t strb1[64];
		swprintf_s(strb1, L"弾丸所持数 : %d発", obj->Get_M_Ass_Bullet_Held());
		Font::StrDraw(strb1, 300.0f, 560, 22, c);// X  Y  大きさ 

	}
}