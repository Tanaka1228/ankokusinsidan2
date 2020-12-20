//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL\HitBoxManager.h"
#include"GameHead.h"
#include"ObjHero.h"
#include"CObjBullet.h"
#include"UtilityModule.h"
#include"GameL/DrawFont.h"
#include"GameL/Audio.h"

//使用するネームスペース
using namespace GameL;


//位置情報X変更用
void CObjHero::SetX(float x) 
{
	m_x = x;
}

//位置情報Y変更用
void CObjHero::SetY(float y)
{
	m_y = y;
}
float CObjHero::GetB()//弾丸向き取得用
{
	return m_ani_frame;
}
//位置情報X取得用
float CObjHero::GetX()
{
	return m_x;
	
}
//位置情報Y取得用
float CObjHero::GetY()
{
	return m_y;
}



//コンストラクタ
CObjHero::CObjHero(float x, float y)
{
	m_x = x;
	m_y = y;


	//　選択　音楽情報の読み込み
	Audio::LoadAudio(3, L"足音.wav", EFFECT);//単発

	//　銃を構える　音楽情報の読み込み
	Audio::LoadAudio(7, L"構え.wav", EFFECT);//単発

	//　敵の弾丸が主人公に接触SE　音楽情報の読み込み
	Audio::LoadAudio(8, L"主人公ダメージ.wav", EFFECT);//単発

	//外部グラフィックファイルを読み込み0番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"HP.png", 50, TEX_SIZE_512);//主人公グラフィック
	//外部グラフィックファイルを読み込み0番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"HP字.png", 51, TEX_SIZE_512);//主人公グラフィック

}

//イニシャライズ
void CObjHero::Init()
{
	m_px = 0.0f; //位置
	m_py = 0.0f;
	m_vx = 0.0f; //移動ベクトル
	m_vy = 0.0f; //移動ベクトル
	m_posture = 0.0f; //右向き0.0f 左向き1.0f


	m_ani_time=0; //向きフレーム
    m_ani_frame=0; //向き描画フレーム

	//-----------------------------------------------------------------
	//正面アニメーション
	m_ani_time1 = 0; //アニメーションフレーム動作間隔
    m_ani_frame1=0; //静止フレームを初期にする

	//背面アニメーション
	m_ani_time2 = 0; //アニメーションフレーム動作間隔
	m_ani_frame2 = 0; //静止フレームを初期にする

	//右アニメーション
	m_ani_time3= 0; //アニメーションフレーム動作間隔
	m_ani_frame3 = 0; //静止フレームを初期にする

	//左アニメーション
	m_ani_time4= 0; //アニメーションフレーム動作間隔
	m_ani_frame4= 0; //静止フレームを初期にする

	//------------------------------------------------------------------
	m_hp =256.0f;//主人公のHP
	//--------------------------------------------------------------------
	m_f = true; //弾丸発射制御
	m_ass_f = true;
	m_gun = 0;//銃の構えているか　0が構えていない 　1が構えている
	gun_type = 0;//　0がリボルバー 1がアサルト
	
	m_bullet_held = 30;//弾丸の所持数
	gun_Kama = 1;//銃を構えるフラグ
	gun_type_flag = 1;//銃の種類フラグ
	//ass_bullet = 30;//アサルト弾丸数
	//ass_bullet_held = 150;//アサルト弾丸所持数

	//---------------------------------------------------------------

	//blockとの衝突状態確認用
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	m_block_type = 0; //踏んでいるblockの種類を確認用


	//当たり判定用HitBoxを作成
	Hits::SetHitBox(this, m_x, m_y, 34, 34, ELEMENT_PLAYER, OBJ_HERO, 1);
}

int CObjHero::m_bullet = 6;//弾丸の弾数　リボルバー

//アクション
void CObjHero::Action()
{
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);//拠点
	CObjChinaMob* chinamob = (CObjChinaMob*)Objs::GetObj(OBJ_CHINA_MOB);//チャイナタウンのモブ
	CObjInstMob* instmob = (CObjInstMob*)Objs::GetObj(OBJ_INST_MOB);//研究所のモブ
	CObjHosMob* hosmob = (CObjHosMob*)Objs::GetObj(OBJ_HOS_MOB);//病院のモブ
	CObjDrugMob* drugmob = (CObjDrugMob*)Objs::GetObj(OBJ_DRUG_MOB);//チャイナタウンのモブ
	CObjHeroine* heroine = (CObjHeroine*)Objs::GetObj(OBJ_HEROINE);//ヒロイン


	CObjChinaTown* chinatown = (CObjChinaTown*)Objs::GetObj(OBJ_CHINA_TOWN);//チャイナタウンA
	CObjChinaTownBoss* chinatownboss = (CObjChinaTownBoss*)Objs::GetObj(OBJ_CHINA_TOWN_BOSS);//チャイナタウンボス
	CObjChinaTown_b* chinatown_b = (CObjChinaTown_b*)Objs::GetObj(OBJ_CHINA_TOWN_B);//チャイナタウンのB
	CObjChinaEvent* chinaevent = (CObjChinaEvent*)Objs::GetObj(OBJ_CHINA_EVENT);//チャイナタウンのイベント

	CObjInstitute* inst = (CObjInstitute*)Objs::GetObj(OBJ_INSTITUTE);//研究所1階
	CObjInstitute13A* inst13a = (CObjInstitute13A*)Objs::GetObj(OBJ_INSTITUTE13A);//研究所地下2階
	CObjInstituteBoss* instituteboss = (CObjInstituteBoss*)Objs::GetObj(OBJ_INSTITUTE_BOSS);//研究所BOSS

	CObjHospital* hospital = (CObjHospital*)Objs::GetObj(OBJ_HOSPITAL);//病院の一階
	CObjHospital2* hospital2 = (CObjHospital2*)Objs::GetObj(OBJ_HOSPITAL2);//病院の二階
	CObjRooftop* rooftop = (CObjRooftop*)Objs::GetObj(OBJ_ROOF_TOP);//病院の屋上

	CObjDrugCampany* drug = (CObjDrugCampany*)Objs::GetObj(OBJ_DRUG_CAMPANY);//製薬会社の一階

	//移動ベクトルの破棄
	m_vx = 0.0f;
	m_vy = 0.0f;
	if (!block) {
		if (Input::GetVKey('A') == true)
		{
			if (gun_Kama == 1)
			{
				Audio::Start(7);

				if (m_gun == 1)
				{
					m_gun = 0;//構えていない
				}
				else if (m_gun == 0)
				{
					m_gun = 1;//構えている
				}

				gun_Kama = 0;
			}


		}
		else
		{
			gun_Kama = 1;
		}
	}

	if (m_bullet > 0)//弾数が0以上なら --------------リボルバー--------------------------------------------
	{
		//主人公の弾丸発射
		if (Input::GetVKey('Z') == true && m_gun == 1 && gun_type == 0)
		{


			if (m_f == true)
			{


				m_bullet -= 1;

				if (m_ani_frame == 2)//右
				{
					//弾丸オブジェクト作成
					CObjBullet* obj_b = new CObjBullet(m_x + 0.0f, m_y + 0.0f); //弾丸オブジェクト作成
					Objs::InsertObj(obj_b, OBJ_BULLET, 4); //作った弾丸オブジェクトをオブジェクトマネージャーに登録

					Audio::Start(1);
				}
				if (m_ani_frame == 3)//左
				{
					//弾丸オブジェクト作成
					CObjBullet* obj_b = new CObjBullet(m_x + 0.0f, m_y + 0.0f); //弾丸オブジェクト作成
					Objs::InsertObj(obj_b, OBJ_BULLET, 4);

					Audio::Start(1);
				}
				if (m_ani_frame == 1)//後ろ
				{
					//弾丸オブジェクト作成
					CObjBullet* obj_b = new CObjBullet(m_x + 0.0f, m_y + 0.0f); //弾丸オブジェクト作成
					Objs::InsertObj(obj_b, OBJ_BULLET, 4);

					Audio::Start(1);
				}
				if (m_ani_frame == 0)//前
				{
					//弾丸オブジェクト作成
					CObjBullet* obj_b = new CObjBullet(m_x + 0.0f, m_y + 0.0f); //弾丸オブジェクト作成
					Objs::InsertObj(obj_b, OBJ_BULLET, 4);

					Audio::Start(1);
				}



				m_f = false;
			}
		}
		else
		{
			m_f = true;
		}
	}//------------------------------------------------------------------------------------------------------


	//リボルバーのリロード
	if (Input::GetVKey(VK_SPACE) == true && m_bullet_held > 0)//リロード
	{

		if (m_bullet == 6)
		{
			m_bullet_held -= 0;
			if (m_bullet_held >= 0) {
				m_bullet += 0;
			}

		}
		if (m_bullet == 5)
		{
			m_bullet_held -= 1;
			if (m_bullet_held >= 0) {
				m_bullet += 1;
			}
		}
		if (m_bullet == 4)
		{
			m_bullet_held -= 2;
			if (m_bullet_held >= 0) {
				m_bullet += 2;
			}
		}
		if (m_bullet == 3)
		{
			m_bullet_held -= 3;
			if (m_bullet_held >= 0) {
				m_bullet += 3;
			}
		}
		if (m_bullet == 2)
		{
			m_bullet_held -= 4;
			if (m_bullet_held >= 0) {
				m_bullet += 4;
			}
		}
		if (m_bullet == 1)
		{
			m_bullet_held -= 5;
			if (m_bullet_held >= 0) {
				m_bullet += 5;
			}
		}
		if (m_bullet == 0)
		{
			m_bullet_held -= 6;
			if (m_bullet_held >= 0) {
				m_bullet += 6;
			}
		}

	}
	

		//----------主人公右移動(アニメーション)-----------------------
		if (Input::GetVKey(VK_RIGHT) == true) //主人公移動キー 右
		{

			m_x += 5.0f;
			m_vx += m_x;
			m_posture = 0.0f;
			m_ani_frame = 2;
			m_ani_time3 += 1;

			//動くと会話終了--------
			if (chinatown != nullptr||chinatownboss!=nullptr)
			{
				chinamob->SetSp_flag(false);
				chinamob->SetM_sp(0);
			}
			if (hospital != nullptr || hospital2 != nullptr || rooftop != nullptr) {
				hosmob->SetSp_flag(false);
				hosmob->SetM_sp(0);
			}
			if (drug != nullptr) {
				drugmob->SetSp_flag(false);
				drugmob->SetM_sp(0);
			}
			if (inst != nullptr || inst13a != nullptr || instituteboss != nullptr)
			{
				instmob->SetSp_flag(false);
				instmob->SetM_sp(0);
			}
			if (block != nullptr) {
				heroine->SetSp_flag(false);
				heroine->SetM_sp(0);
			}
			//----------------------------
		}
		else
		{
			m_ani_time3 = 0;
			m_ani_frame3 = 0;
		}
		if (m_ani_time3 > 2)
		{
			m_ani_frame3 += 1;
			m_ani_time3 = 0;
		}
		if (m_ani_frame3 == 2)
		{
			Audio::Start(3);
			m_ani_frame3 = 0;
		}
		//--------------------------------------------------------------------

		//----------主人公左移動(アニメーション)-----------------------
		if (Input::GetVKey(VK_LEFT) == true) //主人公移動キー 左
		{
			m_x -= 5.0f;
			m_vx -= m_x;
			m_posture = 1.0f;
			m_ani_frame = 3;
			m_ani_time4 += 1;


			//動くと会話終了--------
			if (chinatown != nullptr || chinatownboss != nullptr)
			{
				chinamob->SetSp_flag(false);
				chinamob->SetM_sp(0);
			}
			if (hospital != nullptr || hospital2 != nullptr || rooftop != nullptr) {
				hosmob->SetSp_flag(false);
				hosmob->SetM_sp(0);
			}
			if (drug != nullptr) {
				drugmob->SetSp_flag(false);
				drugmob->SetM_sp(0);
			}
			if (inst != nullptr || inst13a != nullptr || instituteboss != nullptr)
			{
				instmob->SetSp_flag(false);
				instmob->SetM_sp(0);
			}
			if (block != nullptr) {
				heroine->SetSp_flag(false);
				heroine->SetM_sp(0);
			}
			//-----------------------------

		}
		else
		{
			m_ani_time4 = 0;
			m_ani_frame4 = 0;
		}
		if (m_ani_time4 > 2)
		{
			m_ani_frame4 += 1;
			m_ani_time4 = 0;
		}
		if (m_ani_frame4 == 2)
		{
			Audio::Start(3);
			m_ani_frame4 = 0;
		}
		//-------------------------------------------------------------------

		//----------主人公上移動(アニメーション)-----------------------
		if (Input::GetVKey(VK_UP) == true) //主人公移動キー ↑
		{
			m_y -= 5.0f;
			m_vy -= m_y;
			m_ani_frame = 1;
			m_ani_time2 += 1;

			//動くと会話終了--------
			if (chinatown != nullptr || chinatownboss != nullptr)
			{
				chinamob->SetSp_flag(false);
				chinamob->SetM_sp(0);
			}
			if (hospital != nullptr || hospital2 != nullptr || rooftop != nullptr) {
				hosmob->SetSp_flag(false);
				hosmob->SetM_sp(0);
			}
			if (drug != nullptr) {
				drugmob->SetSp_flag(false);
				drugmob->SetM_sp(0);
			}
			if (inst != nullptr || inst13a != nullptr || instituteboss != nullptr)
			{
				instmob->SetSp_flag(false);
				instmob->SetM_sp(0);
			}
			if (block != nullptr) {
				heroine->SetSp_flag(false);
				heroine->SetM_sp(0);
			}
			//-----------------------------
		
		}
		else
		{
			m_ani_time2 = 0;
			m_ani_frame2 = 0;
		}
		if (m_ani_time2 > 3)
		{
			m_ani_frame2 += 1;
			m_ani_time2 = 0;
		}
		if (m_ani_frame2 == 3)
		{
			Audio::Start(3);
			m_ani_frame2 = 0;
		}
		//---------------------------------------------------------------

		//----------主人公下移動(アニメーション)-----------------------
		if (Input::GetVKey(VK_DOWN) == true) //主人公移動キー ↓
		{
			m_y += 5.0f;
			m_vy += m_y;
			m_ani_frame = 0;
			m_ani_time1 += 1;

			//動くと会話終了--------
			if (chinatown != nullptr || chinatownboss != nullptr)
			{
				chinamob->SetSp_flag(false);
				chinamob->SetM_sp(0);
			}
			if (hospital != nullptr || hospital2 != nullptr || rooftop != nullptr) {
				hosmob->SetSp_flag(false);
				hosmob->SetM_sp(0);
			}
			if (drug != nullptr) {
				drugmob->SetSp_flag(false);
				drugmob->SetM_sp(0);
			}
			if (inst != nullptr || inst13a != nullptr || instituteboss != nullptr)
			{
				instmob->SetSp_flag(false);
				instmob->SetM_sp(0);
			}
			if (block != nullptr) {
				heroine->SetSp_flag(false);
				heroine->SetM_sp(0);
			}
			//-----------------------------
		}
		else
		{
			m_ani_time1 = 0;
			m_ani_frame1 = 0;
		}
		if (m_ani_time1 > 3)
		{
			m_ani_frame1 += 1;
			m_ani_time1 = 0;
		}
		if (m_ani_frame1 == 3)
		{
			Audio::Start(3);
			m_ani_frame1 = 0;
		}

		//移動ベクトルの正規化
		UnitVec(&m_vy, &m_vx);

		//HitBoxの内容を更新
		CHitBox* hit = Hits::GetHitBox(this); //作成したHitBox更新用の入り口を取り出す
		hit->SetPos(m_x, m_y);                //入り口から新しい位置(主人公機の位置)情報に置き換える


		//敵機オブジェクトと接触したら主人公機削除
		if (hit->CheckElementHit(ELEMENT_ENEMY) == true)
		{
			Audio::Start(8);
			m_hp -= 25.6;
		}

		if (m_hp <= 0)//HPが０になったら破棄
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);

			//主人公消滅でゲームオーバーに移行する
			Scene::SetScene(new CSceneGameOver());
		}
}

//ドロー
void CObjHero::Draw()
{
	int AniData1[3] = //正面向き情報を登録
	{
		0,1,2,
	};
	int AniData2[3] = //背面向き情報を登録
	{
		0,1,2,
	};
	int AniData3[2] = //右向き情報を登録
	{
		0,1,
	};
	int AniData4[2] = //左向き情報を登録
	{
		0,1,
	};

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;
	
	


	//主人公
	if (m_ani_frame == 2) //右
	{

		//切り取り位置の設定
		src.m_top = 64.0f;   //y
		src.m_left = 0.0f + AniData3[m_ani_frame3] * 32.0f; //x
		src.m_right = 32.0f + AniData3[m_ani_frame3] * 32.0f; //x
		src.m_bottom = 96.0f; //y


	}
	if (m_ani_frame == 1) //上
	{
		//切り取り位置の設定
		src.m_top = 32.0f;   //y
		src.m_left = 0.0f + AniData2[m_ani_frame2] * 32.0f; //x
		src.m_right = 32.0f + AniData2[m_ani_frame2] * 32.0f; //x
		src.m_bottom = 64.0f; //y
	}

	if (m_ani_frame == 0) //前
	{
		//切り取り位置の設定
		src.m_top = 0.0f;   //y
		src.m_left = 0.0f+AniData1[m_ani_frame1]*32.0f; //x
		src.m_right = 32.0f+AniData1[m_ani_frame1]*32.0f; //x
		src.m_bottom =32.0f; //y
	}

	if (m_ani_frame == 3)//左
	{
		//切り取り位置の設定
		src.m_top = 96.0f;   //y
		src.m_left = 0.0f + AniData4[m_ani_frame4] * 32.0f; //x
		src.m_right = 32.0f + AniData4[m_ani_frame4] * 32.0f; //x
		src.m_bottom =128.0f; //y
	}

	//表示位置の設定
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 40.0f + m_x;
	dst.m_bottom = 38.0f + m_y;

	Draw::Draw(0, &src, &dst, c, 0.0f);


	//---HP------------------
	//切り取り位置の設定
	src.m_top = 107.0f;   //y
	src.m_left = 0.0f; //x
	src.m_right = 256.0f; //x
	src.m_bottom = 151.0f; //y

	//表示位置の設定
	dst.m_top = 24.0f;
	dst.m_left = 0.0f;
	dst.m_right = 0.0f+m_hp;
	dst.m_bottom = 64.0f;

	Draw::Draw(50, &src, &dst, c, 0.0f);
	//------------------------------------
	//---HP枠------------------
	//切り取り位置の設定
	src.m_top = 107.0f;   //y
	src.m_left = 256.0f; //x
	src.m_right = 512.0f; //x
	src.m_bottom = 151.0f; //y

	//表示位置の設定
	dst.m_top = 24.0f;
	dst.m_left = 0.0f;
	dst.m_right = 0.0f+256.0f;
	dst.m_bottom = 64.0f;

	Draw::Draw(50, &src, &dst, c, 0.0f);
	//------------------------------------
	//---HP字------------------
	//切り取り位置の設定
	src.m_top = 21.0f;   //y
	src.m_left =9.0f; //x
	src.m_right = 52.0f; //x
	src.m_bottom = 39.0f; //y

	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 32.0f;
	dst.m_bottom = 25.0f;

	Draw::Draw(51, &src, &dst, c, 0.0f);
	//------------------------------------

}
