//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameHead.h"
#include"CObjAngleBullet.h"
#include"UtilityModule.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjAngleBullet::CObjAngleBullet(float x, float y,float r,float speed)//コンストラクタで受け取った情報を変数に送る
{
	m_x = x;
	m_y = y;
	m_r = r;
	m_speed = speed;
}

//イニシャライズ
void CObjAngleBullet::Init()
{

	m_vx = cos(3.14f / 180.0f * m_r);
	m_vy = sin(3.14f / 180.0f * m_r);

	//当たり判定用HitBoxを作成
	Hits::SetHitBox(this, m_x, m_y, 30, 22, ELEMENT_ENEMY, OBJ_ANGLE_BULLET, 1);//位置x 位置ｙ 横幅w 縦幅h
}

//アクション
void CObjAngleBullet::Action()
{
	//病院の屋上の情報
	CObjRooftop* rooftop = (CObjRooftop*)Objs::GetObj(OBJ_ROOF_TOP);
	//主人公機と誘導弾丸で角度をとる
	CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	//チャイナタウンBOSSの情報
	CObjChinaTownBoss* chinatownboss = (CObjChinaTownBoss*)Objs::GetObj(OBJ_CHINA_TOWN_BOSS);
	//研究所BOSSの情報
	CObjInstituteBoss* instituteboss = (CObjInstituteBoss*)Objs::GetObj(OBJ_INSTITUTE_BOSS);

	if (rooftop != nullptr)
	{
		
     	
			//移動
			m_x += m_vx * m_speed;
			m_y -= m_vy * m_speed;

			//弾丸のHitBox更新用ポインター取得
			CHitBox* hit = Hits::GetHitBox(this); //HitBoxの位置を弾丸の位置に更新
			hit->SetPos(m_x + rooftop->GetScroll(), m_y + rooftop->GetScroll2());


			//敵機が完全に領域外に出たら敵機を破棄する
			bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 2500.0f, 2500.0f);
			if (check == false)
			{
				this->SetStatus(false);//自身に削除命令
				Hits::DeleteHitBox(this);
			}

			//主人公機オブジェクトと接触したら弾丸削除
			if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
			{
				this->SetStatus(false);   //自身に削除命令を出す。
				Hits::DeleteHitBox(this); //弾丸が所有するHitBoxに削除する。
			}
		
	}
	if (chinatownboss != nullptr)
	{
		
			//移動
			m_x += m_vx * m_speed;
			m_y -= m_vy * m_speed;

			//弾丸のHitBox更新用ポインター取得
			CHitBox* hit = Hits::GetHitBox(this); //HitBoxの位置を弾丸の位置に更新
			hit->SetPos(m_x + chinatownboss->GetScroll(), m_y + chinatownboss->GetScroll2());


			//敵機が完全に領域外に出たら敵機を破棄する
			bool check = CheckWindow(m_x, m_y, 0.0f, 0.0f, 3000.0f, 2500.0f);
			if (check == false)
			{
				this->SetStatus(false);//自身に削除命令
				Hits::DeleteHitBox(this);
			}

			//主人公機オブジェクトと接触したら弾丸削除
			if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
			{
				this->SetStatus(false);   //自身に削除命令を出す。
				Hits::DeleteHitBox(this); //弾丸が所有するHitBoxに削除する。
			}
	}
	if (instituteboss != nullptr)
	{

		//移動
		m_x += m_vx * m_speed;
		m_y -= m_vy * m_speed;

		//弾丸のHitBox更新用ポインター取得
		CHitBox* hit = Hits::GetHitBox(this); //HitBoxの位置を弾丸の位置に更新
		hit->SetPos(m_x + instituteboss->GetScroll(), m_y + instituteboss->GetScroll2());


		//敵機が完全に領域外に出たら敵機を破棄する
		bool check = CheckWindow(m_x, m_y, 0.0f, 0.0f, 3000.0f, 2500.0f);
		if (check == false)
		{
			this->SetStatus(false);//自身に削除命令
			Hits::DeleteHitBox(this);
		}

		//主人公機オブジェクトと接触したら弾丸削除
		if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
		{
			this->SetStatus(false);   //自身に削除命令を出す。
			Hits::DeleteHitBox(this); //弾丸が所有するHitBoxに削除する。
		}



	}
}

//ドロー
void CObjAngleBullet::Draw()
{

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	//切り取り位置の設定　グラフィックを作っていない
	src.m_top = 12.0f;   //y
	src.m_left = 8.0f;  //x
	src.m_right = 26.0f; //x 
	src.m_bottom = 19.0f; //y

	////表示位置の設定
	//dst.m_top = 5.0f + m_y;//縦の位置変更
	//dst.m_left = 0.0f + m_x;
	//dst.m_right = 30.0f + m_x;
	//dst.m_bottom = 19.0f + m_y;
//病院の屋上の情報
	CObjRooftop* rooftop = (CObjRooftop*)Objs::GetObj(OBJ_ROOF_TOP);

	//チャイナタウンBOSSの情報
	CObjChinaTownBoss* chinatownboss = (CObjChinaTownBoss*)Objs::GetObj(OBJ_CHINA_TOWN_BOSS);

	//研究所BOSSの情報
	CObjInstituteBoss* instituteboss = (CObjInstituteBoss*)Objs::GetObj(OBJ_INSTITUTE_BOSS);

	if (rooftop != nullptr)
	{
		//表示位置の設定
		dst.m_top = 0.0f + m_y + rooftop->GetScroll2();
		dst.m_left = 0.0f + m_x + rooftop->GetScroll();
		dst.m_right = 45.0f + m_x + rooftop->GetScroll();
		dst.m_bottom = 32.0f + m_y + rooftop->GetScroll2();

		Draw::Draw(3, &src, &dst, c, m_r);
	}

	if (chinatownboss != nullptr)
	{
		//表示位置の設定
		dst.m_top = 0.0f + m_y + chinatownboss->GetScroll2();
		dst.m_left = 0.0f + m_x + chinatownboss->GetScroll();
		dst.m_right = 45.0f + m_x + chinatownboss->GetScroll();
		dst.m_bottom = 32.0f + m_y + chinatownboss->GetScroll2();

		Draw::Draw(3, &src, &dst, c, m_r);
	}
	if (instituteboss != nullptr)
	{
		//表示位置の設定
		dst.m_top = 0.0f + m_y + instituteboss->GetScroll2();
		dst.m_left = 0.0f + m_x + instituteboss->GetScroll();
		dst.m_right = 45.0f + m_x + instituteboss->GetScroll();
		dst.m_bottom = 32.0f + m_y + instituteboss->GetScroll2();

		Draw::Draw(3, &src, &dst, c, m_r);
	}
}