//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameHead.h"
#include"CObjBulletEnemy.h"
#include"UtilityModule.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjBulletEnemy::CObjBulletEnemy(float x, float y)//コンストラクタで受け取った情報を変数に送る
{
	m_x = x;
	m_y = y;
	
}

//イニシャライズ
void CObjBulletEnemy::Init()
{
	CObjChinaTownBoss* chinatownboss = (CObjChinaTownBoss*)Objs::GetObj(OBJ_CHINA_TOWN_BOSS);//チャイナタウンボス
	if (chinatownboss!=nullptr)
	{
		m_vx = -1.0f;
		m_vy = -1.0f;
	}

	//m_vx = -1.0f;
	//m_vy = 0.0f;

	//当たり判定用HitBoxを作成
	Hits::SetHitBox(this, m_x, m_y, 30, 20, ELEMENT_ENEMY, OBJ_BULLET_ENEMY, 1);
}

//アクション
void CObjBulletEnemy::Action()
{
	//チャイナタウンBOSSの情報
	CObjChinaTownBoss* chinatownboss = (CObjChinaTownBoss*)Objs::GetObj(OBJ_CHINA_TOWN_BOSS);

	if (chinatownboss != nullptr)
	{
		//移動
		m_x += m_vx * 5.0f;
		m_y += m_vy * 5.0f;

		//弾丸のHitBox更新用ポインター取得
		CHitBox* hit = Hits::GetHitBox(this); //HitBoxの位置を弾丸の位置に更新
		hit->SetPos(m_x + chinatownboss->GetScroll(), m_y + chinatownboss->GetScroll2());


		//敵機が完全に領域外に出たら敵機を破棄する
		bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 3000.0f, 2500.0f);
		if (check == false)
		{
			this->SetStatus(false);//自身に削除命令
			Hits::DeleteHitBox(this);
		}

		//敵機オブジェクトと接触したら弾丸削除
		if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
		{
			this->SetStatus(false);   //自身に削除命令を出す。
			Hits::DeleteHitBox(this); //弾丸が所有するHitBoxに削除する。
		}
	}
	
}

//ドロー
void CObjBulletEnemy::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	//切り取り位置の設定　
	//弾丸を左向きにしている
	src.m_top = 0.0f;   //y
	src.m_left = 126.0f;  //x
	src.m_right = 96.0f; //x 
	src.m_bottom = 32.0f; //y

	//チャイナタウンBOSSの情報
	CObjChinaTownBoss* chinatownboss = (CObjChinaTownBoss*)Objs::GetObj(OBJ_CHINA_TOWN_BOSS);
	
	if (chinatownboss != nullptr)
	{
		//表示位置の設定
		dst.m_top = -10.0f + m_y + chinatownboss->GetScroll2();
		dst.m_left = -5.0f + m_x + chinatownboss->GetScroll();
		dst.m_right = 45.0f + m_x + chinatownboss->GetScroll();
		dst.m_bottom = 32.0f + m_y + chinatownboss->GetScroll2();

		Draw::Draw(3, &src, &dst, c, 0.0f);
	}
	

	
}