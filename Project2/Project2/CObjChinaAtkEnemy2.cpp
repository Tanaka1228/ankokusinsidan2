//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"CObjChinaAtkEnemy2.h"
#include"UtilityModule.h"
#include"GameL/Audio.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjChinaAtkEnemy2::CObjChinaAtkEnemy2(float x, float y,int id)
{
	m_id = id;
	m_x = x;
	m_y = y;
}

//イニシャライズ
void CObjChinaAtkEnemy2::Init()
{

	m_vx = 0.0f;
	m_vy = 0.0f;
	m_time = 0.0f;

	if (m_id == 1)
	{
		//当たり判定用HitBoxを作成
		Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_ENEMY, OBJ_CHINA_ATK_ENEMY2, 1);
	}
}

//アクション
void CObjChinaAtkEnemy2::Action()
{
	//チャイナタウンボス戦フィールドの情報
	CObjChinaTownBoss* chinatownboss = (CObjChinaTownBoss*)Objs::GetObj(OBJ_CHINA_TOWN_BOSS);

	if (m_id == 1) {
		m_time++;//1加算

		if (m_time > 100)//弾丸を発射する間隔
		{
			m_time = 0;

			//弾丸敵機オブジェクト
			CObjBulletEnemy* obj_bullte_enemy = new CObjBulletEnemy(m_x, m_y, 2);
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
	
}

//ドロー
void CObjChinaAtkEnemy2::Draw()
{
	//チャイナタウンボス戦フィールドの情報
	CObjChinaTownBoss* chinatownboss = (CObjChinaTownBoss*)Objs::GetObj(OBJ_CHINA_TOWN_BOSS);
	//チャイナタウンbの情報
	CObjChinaTown_b* chinatownb = (CObjChinaTown_b*)Objs::GetObj(OBJ_CHINA_TOWN_B);


	//描画カラー情報　R=RED G=Green B=Blue A=alpha(透過情報)
	float c[4] = { 0.5f,2.5f,1.5f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f; //y
	src.m_left = 0.0f; //x
	src.m_right = 139.0f; //x
	src.m_bottom = 131.0f; //y

	if (m_id == 1) {
		//表示位置の設定
		dst.m_top = 0.0f + m_y + chinatownboss->GetScroll2();
		dst.m_left = 32.0f + 32.0f + m_x + chinatownboss->GetScroll();
		dst.m_right = 0.0f + m_x + chinatownboss->GetScroll();
		dst.m_bottom = 32.0f + 32.0f + m_y + chinatownboss->GetScroll2();

		//0番目に登録したグラフィックをstc・dst・cの情報を元に描画
		Draw::Draw(1, &src, &dst, c, 0.0f);
	}

}