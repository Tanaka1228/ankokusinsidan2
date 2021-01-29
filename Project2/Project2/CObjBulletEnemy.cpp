//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameHead.h"
#include"CObjBulletEnemy.h"
#include"UtilityModule.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjBulletEnemy::CObjBulletEnemy(float x, float y,int id)//コンストラクタで受け取った情報を変数に送る
{
	m_id = id;
	m_x = x;
	m_y = y;
	m_vx = 0;
	m_vy = 0;
}

//イニシャライズ
void CObjBulletEnemy::Init()
{
	m_r = 0.0f;
		
		if (m_id==1)
		{
			m_vx = -1.0f;
			m_vy = -1.0f;
			//当たり判定用HitBoxを作成
			Hits::SetHitBox(this, m_x, m_y, 30, 20, ELEMENT_ENEMY, OBJ_BULLET_ENEMY, 1);
		}
		if (m_id==2)
		{
			m_vx = +1.0f;
			m_vy = -1.0f;
			//当たり判定用HitBoxを作成
			Hits::SetHitBox(this, m_x, m_y, 30, 20, ELEMENT_ENEMY, OBJ_BULLET_ENEMY, 1);
		}
		if (m_id == 3)//チャイナタウンの雑魚
		{
			m_vx = -1.0f;
			m_vy = 0.0f;
			//当たり判定用HitBoxを作成
			Hits::SetHitBox(this, m_x, m_y, 30, 20, ELEMENT_ENEMY, OBJ_BULLET_ENEMY, 1);
		}
		if (m_id == 4)//チャイナタウンbの雑魚
		{
			m_vx = -1.0f;
			m_vy = 0.0f;
			//当たり判定用HitBoxを作成
			Hits::SetHitBox(this, m_x, m_y, 30, 20, ELEMENT_ENEMY, OBJ_BULLET_ENEMY, 1);
		}
		if (m_id == 5)//チャイナタウンcの雑魚
		{
			m_vx = -1.0f;
			m_vy = 0.0f;
			//当たり判定用HitBoxを作成
			Hits::SetHitBox(this, m_x, m_y, 30, 20, ELEMENT_ENEMY, OBJ_BULLET_ENEMY, 1);
		}
		if (m_id == 6)//病院１階の雑魚
		{
			m_vx = -1.0f;
			m_vy = 0.0f;
			//当たり判定用HitBoxを作成
			Hits::SetHitBox(this, m_x, m_y, 30, 20, ELEMENT_ENEMY, OBJ_BULLET_ENEMY, 1);
		}
		if (m_id == 7)//病院２階の雑魚
		{
			m_vx = -1.0f;
			m_vy = 0.0f;
			//当たり判定用HitBoxを作成
			Hits::SetHitBox(this, m_x, m_y, 30, 20, ELEMENT_ENEMY, OBJ_BULLET_ENEMY, 1);
		}
		if (m_id == 8)//病院3階の雑魚
		{
			m_vx = -1.0f;
			m_vy = 0.0f;
			//当たり判定用HitBoxを作成
			Hits::SetHitBox(this, m_x, m_y, 30, 20, ELEMENT_ENEMY, OBJ_BULLET_ENEMY, 1);
		}
		if (m_id == 9)//病院屋上の雑魚
		{
			m_vx = -1.0f;
			m_vy = 0.0f;
			//当たり判定用HitBoxを作成
			Hits::SetHitBox(this, m_x, m_y, 30, 20, ELEMENT_ENEMY, OBJ_BULLET_ENEMY, 1);
		}
		if (m_id == 10)//D
		{
			m_vx = -1.0f;
			m_vy = 0.0f;
			//当たり判定用HitBoxを作成
			Hits::SetHitBox(this, m_x, m_y, 30, 20, ELEMENT_ENEMY, OBJ_BULLET_ENEMY, 1);
		}
		if (m_id == 11)//製薬会社一階
		{
			m_vx = 0.0f;
			m_vy = +1.0f;
			//当たり判定用HitBoxを作成
			Hits::SetHitBox(this, m_x, m_y, 30, 20, ELEMENT_ENEMY, OBJ_BULLET_ENEMY, 1);
		}
		if (m_id == 12)//製薬会社2階
		{
			m_vx = 0.0f;
			m_vy = +1.0f;
			//当たり判定用HitBoxを作成
			Hits::SetHitBox(this, m_x, m_y, 30, 20, ELEMENT_ENEMY, OBJ_BULLET_ENEMY, 1);
		}
}

//アクション
void CObjBulletEnemy::Action()
{
	CObjChinaTownBoss* chinatownboss = (CObjChinaTownBoss*)Objs::GetObj(OBJ_CHINA_TOWN_BOSS);
	//チャイナタウンの情報
	CObjChinaTown* chinatown = (CObjChinaTown*)Objs::GetObj(OBJ_CHINA_TOWN);
	//チャイナタウンbの情報
	CObjChinaTown_b* chinatownb = (CObjChinaTown_b*)Objs::GetObj(OBJ_CHINA_TOWN_B);
	//チャイナタウンcの情報
	CObjChinaTown_c* chinatownc = (CObjChinaTown_c*)Objs::GetObj(OBJ_CHINA_TOWN_C);
	//チャイナタウンdの情報
	CObjChinaTown_d* chinatownd = (CObjChinaTown_d*)Objs::GetObj(OBJ_CHINA_TOWN_D);
	CObjHospital* hospital = (CObjHospital*)Objs::GetObj(OBJ_HOSPITAL);//病院の一階
	CObjHospital2* hospital2 = (CObjHospital2*)Objs::GetObj(OBJ_HOSPITAL2);//病院の2階
	CObjHospital3* hospital3 = (CObjHospital3*)Objs::GetObj(OBJ_HOSPITAL3);//病院の3階
	CObjRooftop* rooftop = (CObjRooftop*)Objs::GetObj(OBJ_ROOF_TOP);//病院の屋上
	CObjDrugCampany* drug = (CObjDrugCampany*)Objs::GetObj(OBJ_DRUG_CAMPANY);//製薬会社の一階
	CObjDrugCampany2* drug2 = (CObjDrugCampany2*)Objs::GetObj(OBJ_DRUG_CAMPANY2);//製薬会社の2階



		if (m_id == 1)
		{
			//移動
			m_x += m_vx * 5.0f;
			m_y += m_vy * 5.0f;

			//弾丸のHitBox更新用ポインター取得
			CHitBox* hit = Hits::GetHitBox(this); //HitBoxの位置を弾丸の位置に更新
			hit->SetPos(m_x + chinatownboss->GetScroll(), m_y + chinatownboss->GetScroll2());


			//敵機が完全に領域外に出たら敵機を破棄する
			bool check = CheckWindow(m_x, m_y, 1600.0f, -32.0f, 3000.0f, 2500.0f);
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
		if (m_id == 2)
		{

			//移動
			m_x += m_vx * 5.0f;
			m_y += m_vy * 5.0f;

			//弾丸のHitBox更新用ポインター取得
			CHitBox* hit = Hits::GetHitBox(this); //HitBoxの位置を弾丸の位置に更新
			hit->SetPos(m_x + chinatownboss->GetScroll(), m_y + chinatownboss->GetScroll2());


			//敵機が完全に領域外に出たら敵機を破棄する
			bool check = CheckWindow(m_x, m_y, 0.0f, -32.0f, 3000.0f, 2500.0f);
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
		if (m_id == 3)
		{
			
			//移動
			m_x += m_vx * 8.0f;
			m_y += m_vy * 8.0f;

			//弾丸のHitBox更新用ポインター取得
			CHitBox* hit = Hits::GetHitBox(this); //HitBoxの位置を弾丸の位置に更新
			hit->SetPos(m_x + chinatown->GetScroll(), m_y + chinatown->GetScroll2());


			//敵機が完全に領域外に出たら敵機を破棄する
			bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 3000.0f, 3000.0f);
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
		//チャイナタウンB
		if (m_id == 4)
		{
			//角度加算
			m_r += 12.0f;

			//360°で初期値に戻す
			if (m_r > 360.0f)
				m_r = 0.0f;

			//移動方向
			m_vx = -1.0f;
			m_vy = sin(3.14 / 180.0f * m_r);//sinθを求めてm_vyに入れる

			//移動
			m_x += m_vx * 8.0f;
			m_y += m_vy * 8.0f;

			//弾丸のHitBox更新用ポインター取得
			CHitBox* hit = Hits::GetHitBox(this); //HitBoxの位置を弾丸の位置に更新
			hit->SetPos(m_x + chinatownb->GetScroll(), m_y + chinatownb->GetScroll2());


			//敵機が完全に領域外に出たら敵機を破棄する
			bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 3000.0f, 3000.0f);
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
		//チャイナタウンC
		if (m_id == 5)
		{
			//角度加算
			m_r += 8.0f;

			//360°で初期値に戻す
			if (m_r > 360.0f)
				m_r = 0.0f;

			//移動方向
			m_vx = -1.0f;
			m_vy = sin(3.14 / 180.0f * m_r);//sinθを求めてm_vyに入れる
			//移動
			m_x += m_vx * 8.0f;
			m_y += m_vy * 8.0f;

			//弾丸のHitBox更新用ポインター取得
			CHitBox* hit = Hits::GetHitBox(this); //HitBoxの位置を弾丸の位置に更新
			hit->SetPos(m_x + chinatownc->GetScroll(), m_y + chinatownc->GetScroll2());


			//敵機が完全に領域外に出たら敵機を破棄する
			bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 3000.0f, 3000.0f);
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
		//病院一階
		if (m_id == 6)
		{
			//移動
			m_x -= m_vx * 12.0f;
			m_y += m_vy * 12.0f;

			//弾丸のHitBox更新用ポインター取得
			CHitBox* hit = Hits::GetHitBox(this); //HitBoxの位置を弾丸の位置に更新
			hit->SetPos(m_x + hospital->GetScroll(), m_y + hospital->GetScroll2());


			//敵機が完全に領域外に出たら敵機を破棄する
			bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 1500.0f, 3000.0f);
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
		//病院2階
		if (m_id == 7)
		{
			//移動
			m_x -= m_vx * 12.0f;
			m_y += m_vy * 12.0f;

			//弾丸のHitBox更新用ポインター取得
			CHitBox* hit = Hits::GetHitBox(this); //HitBoxの位置を弾丸の位置に更新
			hit->SetPos(m_x + hospital2->GetScroll(), m_y + hospital2->GetScroll2());


			//敵機が完全に領域外に出たら敵機を破棄する
			bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 1500.0f, 3000.0f);
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
		//病院3階
		if (m_id == 8)
		{
			//移動
			m_x += m_vx * 12.0f;
			m_y += m_vy * 12.0f;

			//弾丸のHitBox更新用ポインター取得
			CHitBox* hit = Hits::GetHitBox(this); //HitBoxの位置を弾丸の位置に更新
			hit->SetPos(m_x + hospital3->GetScroll(), m_y + hospital3->GetScroll2());


			//敵機が完全に領域外に出たら敵機を破棄する
			bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 1500.0f, 3000.0f);
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
		//病院屋上
		if (m_id == 9)
		{
			//移動
			m_x -= m_vx * 12.0f;
			m_y += m_vy * 12.0f;

			//弾丸のHitBox更新用ポインター取得
			CHitBox* hit = Hits::GetHitBox(this); //HitBoxの位置を弾丸の位置に更新
			hit->SetPos(m_x + rooftop->GetScroll(), m_y + rooftop->GetScroll2());


			//敵機が完全に領域外に出たら敵機を破棄する
			bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 3000.0f, 3000.0f);
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
		//チャイナタウンｄ
		if (m_id == 10)
		{
			//移動
			m_x += m_vx * 12.0f;
			m_y += m_vy * 12.0f;

			//弾丸のHitBox更新用ポインター取得
			CHitBox* hit = Hits::GetHitBox(this); //HitBoxの位置を弾丸の位置に更新
			hit->SetPos(m_x + chinatownd->GetScroll(), m_y + chinatownd->GetScroll2());


			//敵機が完全に領域外に出たら敵機を破棄する
			bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 3000.0f, 3000.0f);
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
		//製薬会社一階
		if (m_id == 11)
		{
			//移動
			m_x += m_vx * 12.0f;
			m_y += m_vy * 12.0f;

			//弾丸のHitBox更新用ポインター取得
			CHitBox* hit = Hits::GetHitBox(this); //HitBoxの位置を弾丸の位置に更新
			hit->SetPos(m_x + drug->GetScroll(), m_y + drug->GetScroll2());


			//敵機が完全に領域外に出たら敵機を破棄する
			bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 3000.0f, 3000.0f);
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
		//製薬会社2階
		if (m_id == 12)
		{
			//移動
			m_x += m_vx * 12.0f;
			m_y += m_vy * 12.0f;

			//弾丸のHitBox更新用ポインター取得
			CHitBox* hit = Hits::GetHitBox(this); //HitBoxの位置を弾丸の位置に更新
			hit->SetPos(m_x + drug2->GetScroll(), m_y + drug2->GetScroll2());


			//敵機が完全に領域外に出たら敵機を破棄する
			bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 3000.0f, 3000.0f);
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

	//チャイナタウンの情報
	CObjChinaTown* chinatown = (CObjChinaTown*)Objs::GetObj(OBJ_CHINA_TOWN);
	//チャイナタウンBOSSの情報
	CObjChinaTownBoss* chinatownboss = (CObjChinaTownBoss*)Objs::GetObj(OBJ_CHINA_TOWN_BOSS);
	CObjChinaAtkEnemy* chinaatkenemy = (CObjChinaAtkEnemy*)Objs::GetObj(OBJ_CHINA_ATK_ENEMY);
	CObjChinaAtkEnemy2* chinaatkenemy2 = (CObjChinaAtkEnemy2*)Objs::GetObj(OBJ_CHINA_ATK_ENEMY2);
	//チャイナタウンbの情報
	CObjChinaTown_b* chinatownb = (CObjChinaTown_b*)Objs::GetObj(OBJ_CHINA_TOWN_B);
	//チャイナタウンcの情報
	CObjChinaTown_c* chinatownc = (CObjChinaTown_c*)Objs::GetObj(OBJ_CHINA_TOWN_C);
	//チャイナタウンdの情報
	CObjChinaTown_d* chinatownd = (CObjChinaTown_d*)Objs::GetObj(OBJ_CHINA_TOWN_D);
	CObjHospital* hospital = (CObjHospital*)Objs::GetObj(OBJ_HOSPITAL);//病院の一階
	CObjHospital2* hospital2 = (CObjHospital2*)Objs::GetObj(OBJ_HOSPITAL2);//病院の2階
	CObjHospital3* hospital3 = (CObjHospital3*)Objs::GetObj(OBJ_HOSPITAL3);//病院の3階
	CObjRooftop* rooftop = (CObjRooftop*)Objs::GetObj(OBJ_ROOF_TOP);//病院の屋上
	CObjDrugCampany* drug = (CObjDrugCampany*)Objs::GetObj(OBJ_DRUG_CAMPANY);//製薬会社の一階
	CObjDrugCampany2* drug2 = (CObjDrugCampany2*)Objs::GetObj(OBJ_DRUG_CAMPANY2);//製薬会社の2階



	if (chinatownboss != nullptr)
	{
		if (m_id==1)
		{
			//表示位置の設定
			dst.m_top = -10.0f + m_y + chinatownboss->GetScroll2();
			dst.m_left = -5.0f + m_x + chinatownboss->GetScroll();
			dst.m_right = 45.0f + m_x + chinatownboss->GetScroll();
			dst.m_bottom = 32.0f + m_y + chinatownboss->GetScroll2();

			Draw::Draw(3, &src, &dst, c, 0.0f);
		}
		if (m_id==2)
		{
			//表示位置の設定
			dst.m_top = -10.0f + m_y + chinatownboss->GetScroll2();
			dst.m_left = -5.0f + m_x + chinatownboss->GetScroll();
			dst.m_right = 45.0f + m_x + chinatownboss->GetScroll();
			dst.m_bottom = 32.0f + m_y + chinatownboss->GetScroll2();

			Draw::Draw(3, &src, &dst, c, 0.0f);
		}
	}
	if (chinatown != nullptr)
	{
		if (m_id == 3)
		{
			//表示位置の設定
			dst.m_top = -10.0f + m_y + chinatown->GetScroll2();
			dst.m_left = -5.0f + m_x + chinatown->GetScroll();
			dst.m_right = 45.0f + m_x + chinatown->GetScroll();
			dst.m_bottom = 32.0f + m_y + chinatown->GetScroll2();

			Draw::Draw(3, &src, &dst, c, 90.0f);
		}
	}
	if (chinatownb != nullptr)
	{
		if (m_id == 4)
		{
			//表示位置の設定
			dst.m_top = -10.0f + m_y + chinatownb->GetScroll2();
			dst.m_left = -5.0f + m_x + chinatownb->GetScroll();
			dst.m_right = 45.0f + m_x + chinatownb->GetScroll();
			dst.m_bottom = 32.0f + m_y + chinatownb->GetScroll2();

			Draw::Draw(3, &src, &dst, c, 90.0f);
		}
	}
	if (chinatownc != nullptr)
	{
		if (m_id == 5)
		{
			//表示位置の設定
			dst.m_top = -10.0f + m_y + chinatownc->GetScroll2();
			dst.m_left = -5.0f + m_x + chinatownc->GetScroll();
			dst.m_right = 45.0f + m_x + chinatownc->GetScroll();
			dst.m_bottom = 32.0f + m_y + chinatownc->GetScroll2();

			Draw::Draw(3, &src, &dst, c, 90.0f);
		}
	}
	if (hospital != nullptr)
	{
		if (m_id == 6)
		{
			//表示位置の設定
			dst.m_top = -10.0f + m_y + hospital->GetScroll2();
			dst.m_left = -5.0f + m_x + hospital->GetScroll();
			dst.m_right = 45.0f + m_x + hospital->GetScroll();
			dst.m_bottom = 32.0f + m_y + hospital->GetScroll2();

			Draw::Draw(3, &src, &dst, c, 90.0f);
		}
	}
	if (hospital2 != nullptr)
	{
		if (m_id == 7)
		{
			//表示位置の設定
			dst.m_top = -10.0f + m_y + hospital2->GetScroll2();
			dst.m_left = -5.0f + m_x + hospital2->GetScroll();
			dst.m_right = 45.0f + m_x + hospital2->GetScroll();
			dst.m_bottom = 32.0f + m_y + hospital2->GetScroll2();

			Draw::Draw(3, &src, &dst, c, 90.0f);
		}
	}
	if (hospital3 != nullptr)
	{
		if (m_id == 8)
		{
			//表示位置の設定
			dst.m_top = -10.0f + m_y + hospital3->GetScroll2();
			dst.m_left = -5.0f + m_x + hospital3->GetScroll();
			dst.m_right = 45.0f + m_x + hospital3->GetScroll();
			dst.m_bottom = 32.0f + m_y + hospital3->GetScroll2();

			Draw::Draw(3, &src, &dst, c, 90.0f);
		}
	}
	if (rooftop != nullptr)
	{
		if (m_id ==9)
		{
			//表示位置の設定
			dst.m_top = -10.0f + m_y + rooftop->GetScroll2();
			dst.m_left = -5.0f + m_x + rooftop->GetScroll();
			dst.m_right = 45.0f + m_x + rooftop->GetScroll();
			dst.m_bottom = 32.0f + m_y + rooftop->GetScroll2();

			Draw::Draw(3, &src, &dst, c, 90.0f);
		}
	}
	if (chinatownd != nullptr)
	{
		if (m_id == 10)
		{
			//表示位置の設定
			dst.m_top = -10.0f + m_y + chinatownd->GetScroll2();
			dst.m_left = -5.0f + m_x + chinatownd->GetScroll();
			dst.m_right = 45.0f + m_x + chinatownd->GetScroll();
			dst.m_bottom = 32.0f + m_y + chinatownd->GetScroll2();

			Draw::Draw(3, &src, &dst, c, 90.0f);
		}
	}
	if (drug != nullptr)
	{
		if (m_id == 11)
		{
			//表示位置の設定
			dst.m_top = -10.0f + m_y + drug->GetScroll2();
			dst.m_left = -5.0f + m_x + drug->GetScroll();
			dst.m_right = 45.0f + m_x + drug->GetScroll();
			dst.m_bottom = 32.0f + m_y + drug->GetScroll2();

			Draw::Draw(3, &src, &dst, c, 180.0f);
		}
	}
	if (drug2 != nullptr)
	{
		if (m_id == 12)
		{
			//表示位置の設定
			dst.m_top = -10.0f + m_y + drug2->GetScroll2();
			dst.m_left = -5.0f + m_x + drug2->GetScroll();
			dst.m_right = 45.0f + m_x + drug2->GetScroll();
			dst.m_bottom = 32.0f + m_y + drug2->GetScroll2();

			Draw::Draw(3, &src, &dst, c, 180.0f);
		}
	}
}