//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameHead.h"
#include"CObjAssBullet.h"
#include"ObjHero.h"
#include"UtilityModule.h"


//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjAssBullet::CObjAssBullet(float x, float y)//コンストラクタで受け取った情報を変数に送る
{
	
	ass_m_x = x;//アサルト
	ass_m_y = y;
	ass_m_vx = 0.0f;//速度用変数
	ass_m_vy = 0.0f;

	m_Xpos = 0;//0は左
	m_Ypos = 0;//0は上
}


//イニシャライズ
void CObjAssBullet::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;
	ass_m_vx = 0.0f;//速度用変数
	ass_m_vy = 0.0f;

	m_eff.m_top = 32;
	m_eff.m_left = 0;
	m_eff.m_right = 32;
	m_eff.m_bottom = 64;
	m_ani = 0;
	m_ani_time = 0;
	m_del = false;


	//当たり判定用HitBoxを作成
	Hits::SetHitBox(this, ass_m_x, ass_m_y, 25, 22, ELEMENT_PLAYER, OBJ_ASS_BULLET, 1);
}

//アクション
void CObjAssBullet::Action()
{
	CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float bx = obj->GetB();

	if (m_del == true)
	{
		//アニメ～しょんRECT情報
		RECT_F ani_src[4] =
		{
			{32,0,32,64},
			{32,32,64,64},
			{32,64,96,64},
			{32,96,128,64},
		};

		//アニメーションのコマ間隔制御
		if (m_ani_time > 2)
		{
			m_ani++;//アニメーションのコマを1つ進める
			m_ani_time = 0;

			m_eff = ani_src[m_ani];//アニメーションのRECT配列からm_ani番目のRECT情報を取得
		}
		else
		{
			m_ani_time++;
		}

		//着弾アニメーション終了で本当にオブジェクトの破棄
		if (m_ani == 4)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}

		return;//消滅処理は、ここでアクションメソッドを終了させる
	}



	if (bx == 2)
	{
		ass_m_vx += 3.0f;
		ass_m_x += ass_m_vx;
		m_Xpos = 0.0f;
	}
	else if (bx == 3)
	{
		ass_m_vx -= 3.0f;
		ass_m_x += ass_m_vx;
		m_Xpos = 1.0f;
	}
	else if (bx == 1)
	{
		ass_m_vy -= 3.0f;
		ass_m_y += ass_m_vx;
		m_Ypos = 0.0f;
	}
	else if (bx == 0)
	{
		ass_m_vy += 3.0f;
		ass_m_y += ass_m_y;
		m_Ypos = 1.0f;
	}

	//弾丸のHitBox更新用ポインター取得
	CHitBox* hit = Hits::GetHitBox(this); //HitBoxの位置を弾丸の位置に更新
	hit->SetPos(ass_m_x, ass_m_y);



	//敵機が完全に領域外に出たら敵機を破棄する
	bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 800.0f, 600.0f);
	if (check == false)
	{
		this->SetStatus(false);//自身に削除命令
		Hits::DeleteHitBox(this);
	}

	//敵機オブジェクトと接触したら弾丸削除
	if (hit->CheckObjNameHit(OBJ_ENEMY) != nullptr)
	{
		this->SetStatus(false);   //自身に削除命令を出す。
		Hits::DeleteHitBox(this); //弾丸が所有するHitBoxに削除する。
	}
	//オブジェクト情報群と当たり判定行い、当たっていれば削除
   /*  for (int i = 0; i < 6; i++)
	 {
		 if (hit->CheckObjNameHit(data_base[i]) != nullptr)
		 {
			 m_del = true;
			 hit->SetInvincibility(true);
		}
	}*/

}

//ドロー
void CObjAssBullet::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);

	//表示位置の設定
	dst.m_top = (32.0f - 32.0f * m_Ypos) + ass_m_y;//縦の位置変更
	dst.m_left = (32.0f * m_Xpos) + ass_m_x;
	dst.m_right = (32.0f - 32.0f * m_Xpos) + ass_m_x;
	dst.m_bottom = (32.0f * m_Ypos) + ass_m_y;


	if (m_del == true)
	{
		//着弾アニメーション描画
		Draw::Draw(14, &m_eff, &dst, c, 0.0f);
	}
	else
	{


		//切り取り位置の設定　
		src.m_top = 0.0f;   //y
		src.m_left = 0.0f;  //x
		src.m_right = 32.0f; //x 
		src.m_bottom = 32.0f; //y

		Draw::Draw(3, &src, &dst, c, 0.0f);
	}

}