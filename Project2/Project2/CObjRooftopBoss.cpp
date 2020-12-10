//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"CObjRooftopBoss.h"
#include"UtilityModule.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjRooftopBoss::CObjRooftopBoss(float x, float y)
{
	m_x = x;
	m_y = y;
}


//イニシャライズ
void CObjRooftopBoss::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;
	m_time = 0;
	m_timeboss = 0;
	m_hp = 18;


	//当たり判定用HitBoxを作成
	Hits::SetHitBox(this, m_x, m_y, 232, 232, ELEMENT_ENEMY, OBJ_ROOF_TOP_BOSS, 1);
}

//アクション
void CObjRooftopBoss::Action()
{
	//病院の屋上の情報
	CObjRooftop* rooftop = (CObjRooftop*)Objs::GetObj(OBJ_ROOF_TOP);

	m_time++;
	m_timeboss++;
	if (m_time > 50)
	{

		m_time = 0;

		//誘導弾丸作成
		CObjHomingBullet* obj_homing_bullet = new CObjHomingBullet(m_x, m_y); //誘導弾オブジェクト作成
		Objs::InsertObj(obj_homing_bullet, OBJ_HOMING_BULLET, 4); //誘導弾丸登録


	}
	if (m_timeboss > 100)
	{
		m_timeboss = 0;

		//19発動時発射
		CObjAngleBullet* obj_b;
		for (int i = 0; i < 360; i += 20)
		{
			//角度iで角度弾丸発射
			obj_b = new CObjAngleBullet(m_x, m_y, i, 5.0f);
			Objs::InsertObj(obj_b, OBJ_ANGLE_BULLET, 4);
		}
	}
	

	//移動方向
	m_vx = 0.0f;
	m_vy = 0.0f;

	//移動ベクトルの正規化
	UnitVec(&m_vy, &m_vx);

	//速度を付ける。
	m_vx *= 1.5f;
	m_vy *= 1.5f;

	//移動ベクトルを座標に加算する
	m_x += m_vx;
	m_y += m_vy;

	//HitBoxの内容を更新
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x + rooftop->GetScroll(), m_y + rooftop->GetScroll2());


	//ホーミング敵機が完全に領域外に出たら敵機を破棄する
	bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 2655.0f, 1057.0f);
	if (check == false)
	{
		this->SetStatus(false);//自身に削除命令
		Hits::DeleteHitBox(this);

		return;
	}

	//弾丸と接触してるかどうか調べる
	if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	{
		
		m_hp -= 1;
	}
	if (m_hp < 0)//HPが０になったら破棄
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		Sleep(400);
		//Scene::SetScene(new CSceneFin());
	}
}

//ドロー
void CObjRooftopBoss::Draw()
{
	//描画カラー情報　R=RED G=Green B=Blue A=alpha(透過情報)
	float c[4] = { 3.0f,3.0f,3.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f; //y
	src.m_left = 0.0f; //x
	src.m_right = 139.0f; //x
	src.m_bottom = 131.0f; //y

	//病院の屋上の情報
	CObjRooftop* rooftop = (CObjRooftop*)Objs::GetObj(OBJ_ROOF_TOP);

	dst.m_top = 0.0f + m_y + rooftop->GetScroll2();
	dst.m_left = 32.0f + 200.0f + m_x + rooftop->GetScroll();
	dst.m_right = 0.0f + m_x + rooftop->GetScroll();
	dst.m_bottom = 32.0f + 200.0f + m_y + rooftop->GetScroll2();

	//0番目に登録したグラフィックをstc・dst・cの情報を元に描画
	Draw::Draw(1, &src, &dst, c, 0.0f);
}