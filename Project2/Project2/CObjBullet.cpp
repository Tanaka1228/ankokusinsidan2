//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameHead.h"
#include"CObjBullet.h"
#include"ObjHero.h"
#include"UtilityModule.h"


//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjBullet::CObjBullet(float x, float y)//コンストラクタで受け取った情報を変数に送る
{
	m_x = x;//リボルバー
	m_y = y;
	m_vx = 0.0f;//速度用変数
	m_vy = 0.0f;

	ass_m_x = x;//アサルト
	ass_m_y = y;
	ass_m_vx = 0.0f;//速度用変数
	ass_m_vy = 0.0f;

	m_Xpos = 0;//0は左
	m_Ypos = 0;//0は上
}


//イニシャライズ
void CObjBullet::Init()
{
	m_eff.m_top = 32;
	m_eff.m_left = 0;
	m_eff.m_right = 32;
	m_eff.m_bottom = 64;
	m_ani = 0;
	m_ani_time = 0;
	m_del = false;
	bx = 0;

	//当たり判定用HitBoxを作成
	Hits::SetHitBox(this, m_x, m_y, 25, 22, ELEMENT_PLAYER, OBJ_BULLET, 1);
}

//アクション
void CObjBullet::Action()
{
	CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	bx = obj->GetB();

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


	//右
	if (bx == 2)
	{
		m_vx += 7.0f;
		m_x += m_vx;
		m_Xpos = 0.0f;
	}
	//左
	if (bx == 3)
	{
		m_vx -= 7.0f;
		m_x   += m_vx;
		m_Xpos = 1.0f;
	}
	//上
	if (bx == 1)
	{
		m_vy -= 7.0f;
		m_y += m_vy;
		m_Ypos =1.0f;
	}
	//下
	if (bx == 0)
	{
		m_vy += 7.0f;
		m_y += m_vy;
		m_Ypos = 0.0f;
	}

	//弾丸のHitBox更新用ポインター取得
	CHitBox* hit = Hits::GetHitBox(this); //HitBoxの位置を弾丸の位置に更新
	hit->SetPos(m_x, m_y);

	

	//敵機が完全に領域外に出たら敵機を破棄する
	bool check = CheckWindow(m_x, m_y, 100.0f, 50.0f, 700.0f, 550.0f);
	if (check == false)
	{
		this->SetStatus(false);//自身に削除命令
		Hits::DeleteHitBox(this);
		return;
	}

	//当たり判定を行うオブジェクト情報群
	int data_base[4] =
	{
		OBJ_CHINA_ATK_ENEMY,
		OBJ_CHINA_TOWN_BOSS_BOSS,
		OBJ_INSTITUTE_BOSS_BOSS,
		OBJ_ROOF_TOP_BOSS,

	};


	//オブジェクト情報群当たり判定を行いと接触したら弾丸削除
	for (int i = 0; i < 4; i++)
	{
		if (hit->CheckObjNameHit(data_base[i]) != nullptr)
		{
			this->SetStatus(false);   //自身に削除命令を出す。
			Hits::DeleteHitBox(this); //弾丸が所有するHitBoxに削除する。

			return;
		}
	}

}

//ドロー
void CObjBullet::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);

	if (bx == 2 ||bx == 3) 
	{
			//切り取り位置の設定　
			src.m_top = 0.0f;   //y
			src.m_left = 0.0f;  //x
			src.m_right = 32.0f; //x 
			src.m_bottom = 32.0f; //y

			//表示位置の設定
			dst.m_top = (32.0f - 32.0f) + m_y;//縦の位置変更
			dst.m_left = (32.0f * m_Xpos) + m_x;
			dst.m_right = (32.0f - 32.0f * m_Xpos) + m_x;
			dst.m_bottom = 32.0f + m_y;

			Draw::Draw(3, &src, &dst, c, 0.0f);
		
	}
	if (bx == 0 || bx == 1)
	{
		
			//切り取り位置の設定　
			src.m_top = 0.0f;   //y
			src.m_left = 32.0f;  //x
			src.m_right = 64.0f; //x 
			src.m_bottom =32.0f; //y


			//表示位置の設定
			dst.m_top = (32.0f - 32.0f * m_Ypos) + m_y;//縦の位置変更
			dst.m_left = 32.0f + m_x;
			dst.m_right = (32.0f - 32.0f) + m_x;
			dst.m_bottom = (32.0f * m_Ypos) + m_y;

			Draw::Draw(3, &src, &dst, c, 0.0f);
		
	}
}