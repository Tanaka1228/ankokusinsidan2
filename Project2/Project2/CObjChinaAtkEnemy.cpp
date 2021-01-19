//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"CObjChinaAtkEnemy.h"
#include"UtilityModule.h"
#include"GameL/Audio.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjChinaAtkEnemy::CObjChinaAtkEnemy(float x, float y,int id)
{
	m_id = id;
	m_x = x;
	m_y = y;
}

//イニシャライズ
void CObjChinaAtkEnemy::Init()
{

	m_vx = 0.0f;
	m_vy = 0.0f;
	m_time = 0.0f;

	//　弾丸が敵に当たった　音楽情報の読み込み
	Audio::LoadAudio(6, L"金属.wav", EFFECT);//単発


	if (m_id == 1)
	{
		//当たり判定用HitBoxを作成
		Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_ENEMY, OBJ_CHINA_ATK_ENEMY, 1);
	}
	if (m_id == 2)
	{
		//当たり判定用HitBoxを作成
		Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_ENEMY, OBJ_CHINA_ATK_ENEMY, 1);
	}
	if (m_id == 3)
	{
		//当たり判定用HitBoxを作成
		Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_ENEMY, OBJ_CHINA_ATK_ENEMY, 1);
	}
	if (m_id == 4)
	{
		//当たり判定用HitBoxを作成
		Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_ENEMY, OBJ_CHINA_ATK_ENEMY, 1);
	}
	if (m_id == 5)
	{
		//当たり判定用HitBoxを作成
		Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_ENEMY, OBJ_CHINA_ATK_ENEMY, 1);
	}
	if (m_id == 6)
	{
		//当たり判定用HitBoxを作成
		Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_ENEMY, OBJ_CHINA_ATK_ENEMY, 1);
	}
	if (m_id == 7)
	{
		//当たり判定用HitBoxを作成
		Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_ENEMY, OBJ_CHINA_ATK_ENEMY, 1);
	}
	if (m_id == 8)
	{
		//当たり判定用HitBoxを作成
		Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_ENEMY, OBJ_CHINA_ATK_ENEMY, 1);
	}
	if (m_id == 9)
	{
		//当たり判定用HitBoxを作成
		Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_ENEMY, OBJ_CHINA_ATK_ENEMY, 1);
	}
}

//アクション
void CObjChinaAtkEnemy::Action()
{
	//------------------------------------------------
	//チャイナタウンボス戦フィールドの情報
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

	//----------------------------------------------

	//チャイナタウン雑魚
	if (m_id == 1) {
		m_time++;//1加算

		if (m_time > 60)//弾丸を発射する間隔
		{
			m_time = 0;

			//弾丸敵機オブジェクト
			CObjBulletEnemy* obj_bullte_enemy = new CObjBulletEnemy(m_x, m_y, 3);
			Objs::InsertObj(obj_bullte_enemy, OBJ_BULLET_ENEMY, 4);
		}


		//敵機が完全に領域外に出たら敵機を破棄する
		bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 4000.0f, 3000.0f);
		if (check == false)
		{
			this->SetStatus(false);//自身に削除命令
			Hits::DeleteHitBox(this);

			return;
		}

		//HitBoxの内容を更新
		CHitBox* hit = Hits::GetHitBox(this);
		hit->SetPos(m_x + chinatown->GetScroll(), m_y + chinatown->GetScroll2());

		//弾丸と接触してるかどうか調べる
		if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
			Audio::Start(5);
		}
	}
	//チャイナタウンボスの雑魚
	if (m_id == 2) {
		m_time++;//1加算

		if (m_time > 100)//弾丸を発射する間隔
		{
			m_time = 0;

			//弾丸敵機オブジェクト
			CObjBulletEnemy* obj_bullte_enemy = new CObjBulletEnemy(m_x, m_y, 1);
			Objs::InsertObj(obj_bullte_enemy, OBJ_BULLET_ENEMY, 4);
		}


		//敵機が完全に領域外に出たら敵機を破棄する
		bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 3072.0f, 2752.0f);
		if (check == false)
		{
			this->SetStatus(false);//自身に削除命令
			Hits::DeleteHitBox(this);

			return;
		}

		//HitBoxの内容を更新
		CHitBox* hit = Hits::GetHitBox(this);
		hit->SetPos(m_x + chinatownboss->GetScroll(), m_y + chinatownboss->GetScroll2());

		//弾丸と接触してるかどうか調べる
		if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
			Audio::Start(5);
		}
	}
	//チャイナタウン b の雑魚
	if (m_id == 3)
		{
			m_time++;//1加算

			if (m_time > 100)//弾丸を発射する間隔
			{
				m_time = 0;

				//弾丸敵機オブジェクト
				CObjBulletEnemy* obj_bullet_enemy = new CObjBulletEnemy(m_x, m_y, 4);
				Objs::InsertObj(obj_bullet_enemy, OBJ_BULLET_ENEMY, 4);
			}


			//敵機が完全に領域外に出たら敵機を破棄する
			bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 3000.0f, 3000.0f);
			if (check == false)
			{
				this->SetStatus(false);//自身に削除命令
				Hits::DeleteHitBox(this);

				return;
			}

			//HitBoxの内容を更新
			CHitBox* hit = Hits::GetHitBox(this);
			hit->SetPos(m_x + chinatownb->GetScroll(), m_y + chinatownb->GetScroll2());

			//弾丸と接触してるかどうか調べる
			if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
			{
				this->SetStatus(false);
				Hits::DeleteHitBox(this);
				Audio::Start(5);
			}
		}
	//チャイナタウン c の雑魚
	if (m_id == 4)
		{
			m_time++;//1加算

			if (m_time > 100)//弾丸を発射する間隔
			{
				m_time = 0;

				//弾丸敵機オブジェクト
				CObjBulletEnemy* obj_bullet_enemy = new CObjBulletEnemy(m_x, m_y, 5);
				Objs::InsertObj(obj_bullet_enemy, OBJ_BULLET_ENEMY, 4);
			}


			//敵機が完全に領域外に出たら敵機を破棄する
			bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 3000.0f, 3000.0f);
			if (check == false)
			{
				this->SetStatus(false);//自身に削除命令
				Hits::DeleteHitBox(this);

				return;
			}

			//HitBoxの内容を更新
			CHitBox* hit = Hits::GetHitBox(this);
			hit->SetPos(m_x + chinatownc->GetScroll(), m_y + chinatownc->GetScroll2());

			//弾丸と接触してるかどうか調べる
			if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
			{
				this->SetStatus(false);
				Hits::DeleteHitBox(this);
				Audio::Start(5);
			}
		}
	//病院一階 の雑魚
	if (m_id == 5)
	{
		m_time++;//1加算

		if (m_time > 100)//弾丸を発射する間隔
		{
			m_time = 0;

			//弾丸敵機オブジェクト
			CObjBulletEnemy* obj_bullet_enemy = new CObjBulletEnemy(m_x, m_y, 6);
			Objs::InsertObj(obj_bullet_enemy, OBJ_BULLET_ENEMY, 4);
		}


		//敵機が完全に領域外に出たら敵機を破棄する
		bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 3000.0f, 3000.0f);
		if (check == false)
		{
			this->SetStatus(false);//自身に削除命令
			Hits::DeleteHitBox(this);

			return;
		}

		//HitBoxの内容を更新
		CHitBox* hit = Hits::GetHitBox(this);
		hit->SetPos(m_x + hospital->GetScroll(), m_y + hospital->GetScroll2());

		//弾丸と接触してるかどうか調べる
		if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
			Audio::Start(5);
		}
	}
	//病院2階 の雑魚
	if (m_id == 6)
	{
		m_time++;//1加算

		if (m_time > 100)//弾丸を発射する間隔
		{
			m_time = 0;

			//弾丸敵機オブジェクト
			CObjBulletEnemy* obj_bullet_enemy = new CObjBulletEnemy(m_x, m_y, 7);
			Objs::InsertObj(obj_bullet_enemy, OBJ_BULLET_ENEMY, 4);
		}


		//敵機が完全に領域外に出たら敵機を破棄する
		bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 3000.0f, 3000.0f);
		if (check == false)
		{
			this->SetStatus(false);//自身に削除命令
			Hits::DeleteHitBox(this);

			return;
		}

		//HitBoxの内容を更新
		CHitBox* hit = Hits::GetHitBox(this);
		hit->SetPos(m_x + hospital2->GetScroll(), m_y + hospital2->GetScroll2());

		//弾丸と接触してるかどうか調べる
		if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
			Audio::Start(5);
		}
	}
	//病院3階 の雑魚
	if (m_id == 7)
	{
		m_time++;//1加算

		if (m_time > 100)//弾丸を発射する間隔
		{
			m_time = 0;

			//弾丸敵機オブジェクト
			CObjBulletEnemy* obj_bullet_enemy = new CObjBulletEnemy(m_x, m_y, 8);
			Objs::InsertObj(obj_bullet_enemy, OBJ_BULLET_ENEMY, 4);
		}


		//敵機が完全に領域外に出たら敵機を破棄する
		bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 3000.0f, 3000.0f);
		if (check == false)
		{
			this->SetStatus(false);//自身に削除命令
			Hits::DeleteHitBox(this);

			return;
		}

		//HitBoxの内容を更新
		CHitBox* hit = Hits::GetHitBox(this);
		hit->SetPos(m_x + hospital3->GetScroll(), m_y + hospital3->GetScroll2());

		//弾丸と接触してるかどうか調べる
		if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
			Audio::Start(5);
		}
	}
	//病院屋上 の雑魚
	if (m_id == 8)
	{
		m_time++;//1加算

		if (m_time > 100)//弾丸を発射する間隔
		{
			m_time = 0;

			//弾丸敵機オブジェクト
			CObjBulletEnemy* obj_bullet_enemy = new CObjBulletEnemy(m_x, m_y, 9);
			Objs::InsertObj(obj_bullet_enemy, OBJ_BULLET_ENEMY, 4);
		}


		//敵機が完全に領域外に出たら敵機を破棄する
		bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 3000.0f, 3000.0f);
		if (check == false)
		{
			this->SetStatus(false);//自身に削除命令
			Hits::DeleteHitBox(this);

			return;
		}

		//HitBoxの内容を更新
		CHitBox* hit = Hits::GetHitBox(this);
		hit->SetPos(m_x + rooftop->GetScroll(), m_y + rooftop->GetScroll2());

		//弾丸と接触してるかどうか調べる
		if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
			Audio::Start(5);
		}
	}
	//チャイナタウンｄ の雑魚
	if (m_id == 9)
	{
		m_time++;//1加算

		if (m_time > 100)//弾丸を発射する間隔
		{
			m_time = 0;

			//弾丸敵機オブジェクト
			CObjBulletEnemy* obj_bullet_enemy = new CObjBulletEnemy(m_x, m_y, 10);
			Objs::InsertObj(obj_bullet_enemy, OBJ_BULLET_ENEMY, 4);
		}


		//敵機が完全に領域外に出たら敵機を破棄する
		bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 3000.0f, 3000.0f);
		if (check == false)
		{
			this->SetStatus(false);//自身に削除命令
			Hits::DeleteHitBox(this);

			return;
		}

		//HitBoxの内容を更新
		CHitBox* hit = Hits::GetHitBox(this);
		hit->SetPos(m_x + chinatownd->GetScroll(), m_y + chinatownd->GetScroll2());

		//弾丸と接触してるかどうか調べる
		if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
			Audio::Start(5);
		}
	}
}

//ドロー
void CObjChinaAtkEnemy::Draw()
{
	//チャイナタウンボス戦フィールドの情報
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


	//描画カラー情報　R=RED G=Green B=Blue A=alpha(透過情報)
	float c[4] = { 0.5f,2.5f,1.5f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置


	//切り取り位置の設定
	src.m_top = 0.0f; //y
	src.m_left = 0.0f; //x
	src.m_right = 139.0f; //x
	src.m_bottom = 131.0f; //y

	if (chinatown != nullptr) {
		if (m_id == 1) {
			//表示位置の設定
			dst.m_top = 0.0f + m_y + chinatown->GetScroll2();
			dst.m_left = 32.0f + 32.0f + m_x + chinatown->GetScroll();
			dst.m_right = 0.0f + m_x + chinatown->GetScroll();
			dst.m_bottom = 32.0f + 32.0f + m_y + chinatown->GetScroll2();

			//1番目に登録したグラフィックをstc・dst・cの情報を元に描画
			Draw::Draw(1, &src, &dst, c, 0.0f);
		}
	}
	if (chinatownboss != nullptr) {
		if (m_id == 2) {
			//表示位置の設定
			dst.m_top = 0.0f + m_y + chinatownboss->GetScroll2();
			dst.m_left = 32.0f + 32.0f + m_x + chinatownboss->GetScroll();
			dst.m_right = 0.0f + m_x + chinatownboss->GetScroll();
			dst.m_bottom = 32.0f + 32.0f + m_y + chinatownboss->GetScroll2();

			//1番目に登録したグラフィックをstc・dst・cの情報を元に描画
			Draw::Draw(1, &src, &dst, c, 0.0f);
		}
	}
	if (chinatownb != nullptr)
	{
		if (m_id == 3)
		{
			//表示位置の設定
			dst.m_top = 0.0f + m_y + chinatownb->GetScroll2();
			dst.m_left = 32.0f + 32.0f + m_x + chinatownb->GetScroll();
			dst.m_right = 0.0f + m_x + chinatownb->GetScroll();
			dst.m_bottom = 32.0f + 32.0f + m_y + chinatownb->GetScroll2();

			//1番目に登録したグラフィックをstc・dst・cの情報を元に描画
			Draw::Draw(1, &src, &dst, c, 0.0f);
		}
	}
	if (chinatownc != nullptr)
	{
		if (m_id == 4)
		{
			//表示位置の設定
			dst.m_top = 0.0f + m_y + chinatownc->GetScroll2();
			dst.m_left = 32.0f + 32.0f + m_x + chinatownc->GetScroll();
			dst.m_right = 0.0f + m_x + chinatownc->GetScroll();
			dst.m_bottom = 32.0f + 32.0f + m_y + chinatownc->GetScroll2();

			//1番目に登録したグラフィックをstc・dst・cの情報を元に描画
			Draw::Draw(1, &src, &dst, c, 0.0f);
		}
	}
	if (hospital != nullptr)
	{
		if (m_id == 5)
		{
			//表示位置の設定
			dst.m_top = 0.0f + m_y + hospital->GetScroll2();
			dst.m_left = 32.0f + 32.0f + m_x + hospital->GetScroll();
			dst.m_right = 0.0f + m_x + hospital->GetScroll();
			dst.m_bottom = 32.0f + 32.0f + m_y + hospital->GetScroll2();

			//1番目に登録したグラフィックをstc・dst・cの情報を元に描画
			Draw::Draw(11, &src, &dst, c, 0.0f);
		}
	}
	if (hospital2 != nullptr)
	{
		if (m_id == 6)
		{
			//表示位置の設定
			dst.m_top = 0.0f + m_y + hospital2->GetScroll2();
			dst.m_left = 32.0f + 32.0f + m_x + hospital2->GetScroll();
			dst.m_right = 0.0f + m_x + hospital2->GetScroll();
			dst.m_bottom = 32.0f + 32.0f + m_y + hospital2->GetScroll2();

			//1番目に登録したグラフィックをstc・dst・cの情報を元に描画
			Draw::Draw(11, &src, &dst, c, 0.0f);
		}
	}
	if (hospital3 != nullptr)
	{
		if (m_id == 7)
		{
			//表示位置の設定
			dst.m_top = 0.0f + m_y + hospital3->GetScroll2();
			dst.m_left = 32.0f + 32.0f + m_x + hospital3->GetScroll();
			dst.m_right = 0.0f + m_x + hospital3->GetScroll();
			dst.m_bottom = 32.0f + 32.0f + m_y + hospital3->GetScroll2();

			//1番目に登録したグラフィックをstc・dst・cの情報を元に描画
			Draw::Draw(11, &src, &dst, c, 0.0f);
		}
	}
	if (rooftop != nullptr)
	{
		if (m_id ==8)
		{
			//表示位置の設定
			dst.m_top = 0.0f + m_y + rooftop->GetScroll2();
			dst.m_left = 32.0f + 32.0f + m_x + rooftop->GetScroll();
			dst.m_right = 0.0f + m_x + rooftop->GetScroll();
			dst.m_bottom = 32.0f + 32.0f + m_y + rooftop->GetScroll2();

			//1番目に登録したグラフィックをstc・dst・cの情報を元に描画
			Draw::Draw(1, &src, &dst, c, 0.0f);
		}
	}
	if (chinatownd != nullptr)
	{
		if (m_id == 9)
		{
			//表示位置の設定
			dst.m_top = 0.0f + m_y + chinatownd->GetScroll2();
			dst.m_left = 32.0f + 32.0f + m_x + chinatownd->GetScroll();
			dst.m_right = 0.0f + m_x + chinatownd->GetScroll();
			dst.m_bottom = 32.0f + 32.0f + m_y + chinatownd->GetScroll2();

			//1番目に登録したグラフィックをstc・dst・cの情報を元に描画
			Draw::Draw(1, &src, &dst, c, 0.0f);
		}
	}

}