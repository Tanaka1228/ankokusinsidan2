//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL\HitBoxManager.h"
#include"GameHead.h"
#include"ObjHero.h"
#include"CObjBullet.h"
#include"UtilityModule.h"
#include"GameL/DrawFont.h"


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
	m_hp = 10;//主人公のHP
	//--------------------------------------------------------------------
	m_f = true; //弾丸発射制御
	m_ass_f = true;
	m_gun = 0;//銃の構えているか　0が構えていない 　1が構えている
	gun_type = 0;//　0がリボルバー 1がアサルト
	m_bullet = 6;//弾丸の弾数　リボルバー
	m_bullet_held = 30;//弾丸の所持数
	gun_Kama = 1;//銃を構えるフラグ
	gun_type_flag = 1;//銃の種類フラグ
	ass_bullet = 30;//アサルト弾丸数
	ass_bullet_held = 150;//アサルト弾丸所持数

	//---------------------------------------------------------------

	//当たり判定用HitBoxを作成
	Hits::SetHitBox(this, m_x, m_y, 34, 34, ELEMENT_PLAYER, OBJ_HERO, 1);

	//blockとの衝突状態確認用
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	m_block_type = 0; //踏んでいるblockの種類を確認用
}

//アクション
void CObjHero::Action()
{
	//移動ベクトルの破棄
	m_vx = 0.0f;
	m_vy = 0.0f;
	if (Input::GetVKey('A') == true)
	{
		if (gun_Kama == 1)
		{

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

	if (Input::GetVKey('Q') == true&&m_gun==1)//武器の種類を変える
	{
		if (gun_type_flag == 1)
		{
			//リボルバー
			if (gun_type == 0)
			{
				gun_type = 1;
			}
			//アサルト
			else if (gun_type == 1)
			{
				gun_type = 0;
			}
			gun_type_flag = 0;
		}
	}
	else
	{
		gun_type_flag = 1;
	}
	

	if (m_bullet > 0)//弾数が0以上なら --------------リボルバー--------------------------------------------
	{
		//主人公の弾丸発射
		if (Input::GetVKey('Z') == true && m_gun == 1&&gun_type==0)
		{
			

			if (m_f == true)
			{
			

				m_bullet -= 1;

				if (m_ani_frame == 2)//右
				{
					//弾丸オブジェクト作成
					CObjBullet* obj_b = new CObjBullet(m_x + 0.0f, m_y + 0.0f); //弾丸オブジェクト作成
					Objs::InsertObj(obj_b, OBJ_BULLET, 4); //作った弾丸オブジェクトをオブジェクトマネージャーに登録
				}
				if (m_ani_frame == 3)//左
				{
					//弾丸オブジェクト作成
					CObjBullet* obj_b = new CObjBullet(m_x + 0.0f, m_y + 0.0f); //弾丸オブジェクト作成
					Objs::InsertObj(obj_b, OBJ_BULLET, 4);
				}
				if (m_ani_frame == 1)//後ろ
				{
					//弾丸オブジェクト作成
					CObjBullet* obj_b = new CObjBullet(m_x + 0.0f, m_y + 0.0f); //弾丸オブジェクト作成
					Objs::InsertObj(obj_b, OBJ_BULLET, 4);
				}
				if (m_ani_frame == 0)//前
				{
					//弾丸オブジェクト作成
					CObjBullet* obj_b = new CObjBullet(m_x + 0.0f, m_y + 0.0f); //弾丸オブジェクト作成
					Objs::InsertObj(obj_b, OBJ_BULLET, 4);
				}



				m_f = false;
	       	}
		}
		else
		{
			m_f = true;
		}
	}//------------------------------------------------------------------------------------------------------



	if (ass_bullet > 0)//弾数が0以上なら   ------------アサルト-------------------------------------------------------
	{
		//主人公の弾丸発射
		if (Input::GetVKey('Z') == true && m_gun == 1 && gun_type == 1)
		{
			

				ass_bullet -= 1;

				if (m_ani_frame == 2)//右
				{
					//弾丸オブジェクト作成
					CObjBullet* obj_b = new CObjBullet(m_x + 0.0f, m_y + 0.0f); //弾丸オブジェクト作成
					Objs::InsertObj(obj_b, OBJ_BULLET, 4); //作った弾丸オブジェクトをオブジェクトマネージャーに登録
				}
				if (m_ani_frame == 3)//左
				{
					//弾丸オブジェクト作成
					CObjBullet* obj_b = new CObjBullet(m_x + 0.0f, m_y + 0.0f); //弾丸オブジェクト作成
					Objs::InsertObj(obj_b, OBJ_BULLET, 4);
				}
				if (m_ani_frame == 1)//後ろ
				{
					//弾丸オブジェクト作成
					CObjBullet* obj_b = new CObjBullet(m_x + 0.0f, m_y + 0.0f); //弾丸オブジェクト作成
					Objs::InsertObj(obj_b, OBJ_BULLET, 4);
				}
				if (m_ani_frame == 0)//前
				{
					//弾丸オブジェクト作成
					CObjBullet* obj_b = new CObjBullet(m_x + 0.0f, m_y + 0.0f); //弾丸オブジェクト作成
					Objs::InsertObj(obj_b, OBJ_BULLET, 4);
				}
			
			
		}
		

	}//------------------------------------------------------------------------------------------------------

	//リボルバーのリロード
	if (Input::GetVKey(VK_SPACE) == true && m_bullet_held > 0)//リロード
	{

		if ( m_bullet== 6)
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
	//アサルトのリロード
	if (Input::GetVKey(VK_SPACE) == true && ass_bullet_held > 0)//リロードアサルト
	{
		if (ass_bullet == 30)
		{
			ass_bullet_held -= 0;
			if (ass_bullet_held > 0) {
				ass_bullet += 0;
			}
		}
		if (ass_bullet == 29)
		{
			ass_bullet_held -= 1;
			if (ass_bullet_held > 0) {
				ass_bullet += 1;
			}
		}
		if (ass_bullet == 28)
		{
			ass_bullet_held -= 2;
			if (ass_bullet_held > 0) {
				ass_bullet += 2;
			}
		}
		if (ass_bullet == 27)
		{
			ass_bullet_held -= 3;
			if (ass_bullet_held > 0) {
				ass_bullet += 3;
			}
		}
		if (ass_bullet == 26)
		{
			ass_bullet_held -= 4;
			if (ass_bullet_held > 0) {
				ass_bullet += 4;
			}
		}
		if (ass_bullet == 25)
		{
			ass_bullet_held -= 5;
			if (ass_bullet_held > 0) {
				ass_bullet += 5;
			}
		}
		if (ass_bullet == 24)
		{
			ass_bullet_held -= 6;
			if (ass_bullet_held > 0) {
				ass_bullet += 6;
			}
		}
		if (ass_bullet == 23)
		{
			ass_bullet_held -= 7;
			if (ass_bullet_held > 0) {
				ass_bullet += 7;
			}
		}
		if (ass_bullet == 22)
		{
			ass_bullet_held -= 8;
			if (ass_bullet_held > 0) {
				ass_bullet += 8;
			}
		}
		if (ass_bullet == 21)
		{
			ass_bullet_held -= 9;
			if (ass_bullet_held > 0) {
				ass_bullet += 9;
			}
		}
		if (ass_bullet == 20)
		{
			ass_bullet_held -= 10;
			if (ass_bullet_held > 0) {
				ass_bullet += 10;
			}
		}
		if (ass_bullet == 19)
		{
			ass_bullet_held -= 11;
			if (ass_bullet_held > 0) {
				ass_bullet += 11;
			}
		}
		if (ass_bullet == 18)
		{
			ass_bullet_held -= 12;
			if (ass_bullet_held > 0) {
				ass_bullet += 12;
			}
		}
		if (ass_bullet == 17)
		{
			ass_bullet_held -= 13;
			if (ass_bullet_held > 0) {
				ass_bullet += 13;
			}
		}
		if (ass_bullet == 16)
		{
			ass_bullet_held -= 14;
			if (ass_bullet_held > 0) {
				ass_bullet += 14;
			}
		}
		if (ass_bullet == 15)
		{
			ass_bullet_held -= 15;
			if (ass_bullet_held > 0) {
				ass_bullet += 15;
			}
		}
		if (ass_bullet == 14)
		{
			ass_bullet_held -= 16;
			if (ass_bullet_held > 0) {
				ass_bullet += 16;
			}
		}
		if (ass_bullet == 13)
		{
			ass_bullet_held -= 17;
			if (ass_bullet_held > 0) {
				ass_bullet += 17;
			}
		}
		if (ass_bullet == 12)
		{
			ass_bullet_held -= 18;
			if (ass_bullet_held > 0) {
				ass_bullet += 18;
			}
		}
		if (ass_bullet == 11)
		{
			ass_bullet_held -= 19;
			if (ass_bullet_held > 0) {
				ass_bullet += 19;
			}
		}
		if (ass_bullet == 10)
		{
			ass_bullet_held -= 20;
			if (ass_bullet_held > 0) {
				ass_bullet += 20;
			}
		}
		if (ass_bullet == 9)
		{
			ass_bullet_held -= 21;
			if (ass_bullet_held > 0) {
				ass_bullet += 21;
			}
		}
		if (ass_bullet == 8)
		{
			ass_bullet_held -= 22;
			if (ass_bullet_held > 0) {
				ass_bullet +=22;
			}
		}
		if (ass_bullet == 7)
		{
			ass_bullet_held -= 23;
			if (ass_bullet_held > 0) {
				ass_bullet += 23;
			}
		}
		if (ass_bullet == 6)
		{
			ass_bullet_held -= 24;
			if (ass_bullet_held > 0) {
				ass_bullet += 24;
			}
		}
		if (ass_bullet == 5)
		{
			ass_bullet_held -= 25;
			if (ass_bullet_held > 0) {
				ass_bullet += 25;
			}
		}
		if (ass_bullet == 4)
		{
			ass_bullet_held -= 26;
			if (ass_bullet_held > 0) {
				ass_bullet += 26;
			}
		}
		if (ass_bullet == 3)
		{
			ass_bullet_held -= 27;
			if (ass_bullet_held > 0) {
				ass_bullet += 27;
			}
		}
		if (ass_bullet == 2)
		{
			ass_bullet_held -= 28;
			if (ass_bullet_held > 0) {
				ass_bullet += 28;
			}
		}
		if (ass_bullet == 1)
		{
			ass_bullet_held -= 29;
			if (ass_bullet_held > 0) {
				ass_bullet += 29;
			}
		}
		if (ass_bullet == 0)
		{
			ass_bullet_held -= 30;
			if (ass_bullet_held >= 0) {
				ass_bullet += 30;
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
		if (m_gun == 1)//武器を構えたら移動速度低下
		{
			m_x -= 2;
			m_vx -= m_x;
		}
		
		
	}
	else
	{
		m_ani_time3= 0;
		m_ani_frame3 = 0;
	}
	if (m_ani_time3 > 2)
	{
		m_ani_frame3+= 1;
		m_ani_time3 = 0;
	}
	if (m_ani_frame3 == 2)
	{
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
		if (m_gun == 1)//武器を構えたら移動速度低下
		{
			m_x += 2;
			m_vx -= m_x;
		}
		
		
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
		m_ani_frame4= 0;
	}
	//-------------------------------------------------------------------

	//----------主人公上移動(アニメーション)-----------------------
	if (Input::GetVKey(VK_UP) == true) //主人公移動キー ↑
	{
		m_y -= 5.0f;
		m_vy -= m_y;
		m_ani_frame = 1;
		m_ani_time2 += 1;
		if (m_gun == 1)//武器を構えたら移動速度低下
		{
			m_y += 2;
			m_vy -= m_y;
		}
	
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
		m_ani_frame2 = 0;
	}
	//---------------------------------------------------------------

	//----------主人公下移動(アニメーション)-----------------------
	if (Input::GetVKey(VK_DOWN) == true) //主人公移動キー ↓
	{
		m_y+= 5.0f;
		m_vy += m_y;
		m_ani_frame = 0;
		m_ani_time1 += 1;
		if (m_gun == 1)//武器を構えたら移動速度低下
		{
			m_y -= 2;
			m_vy -= m_y;
		}
		
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
		m_ani_frame1 = 0;
	}
	//--------------------------------------------------------------------



	//移動ベクトルの正規化
	UnitVec(&m_vy, &m_vx);

	//HitBoxの内容を更新
	CHitBox* hit = Hits::GetHitBox(this); //作成したHitBox更新用の入り口を取り出す
	hit->SetPos(m_x, m_y);                //入り口から新しい位置(主人公機の位置)情報に置き換える


	//敵機オブジェクトと接触したら主人公機削除
	if (hit->CheckElementHit(ELEMENT_ENEMY) ==true)
	{
		m_hp -= 1;
	
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
	dst.m_right = 36.0f + m_x;
	dst.m_bottom = 34.0f + m_y;

	Draw::Draw(0, &src, &dst, c, 0.0f);


	//wchar_t str[32];
	//swprintf_s(str, L"弾数 : %d / 6", m_bullet);
	//Font::StrDraw(str, 10, 560, 22, c);// X  Y 大きさ 
	
	//主人公のHP表示
	wchar_t strHP[32];
	swprintf_s(strHP, L"HP : %d", m_hp);
	Font::StrDraw(strHP, 10, 5, 28, c);// X  Y 大きさ 

	
}

////表示位置の設定
//dst.m_top = 0.0f + m_y;
//dst.m_left = (64.0f * m_posture) + m_x;
//dst.m_right = (64.0f - 64.0f * m_posture) + m_x;
//dst.m_bottom = 32.0f + 50.0f + m_y;