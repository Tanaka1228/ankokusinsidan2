#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト : 主人公
class CObjHero : public CObj
{
public:
	CObjHero(float x,float y);
	~CObjHero() {};
	void Init();        //イニシャライズ
	void Action();      //アクション
	void Draw();        //ドロー

	float GetX();     //位置情報X取得用
	float GetY();     //位置情報Y取得用
	
	float GetX2() { return m_x; }   //位置情報X2取得用　当たり判定
	float GetY2() { return m_y; }   //位置情報Y2取得用
	  //位置情報Y2取得用
	float GetVX() { return m_vx; }   //位置情報VX取得用
	float GetVY() { return m_vy; }   //位置情報VY取得用

	//m_x,m_yはアクションゲーム指南書で言う、m_px,m_pyです。

	void SetX(float x);//位置情報X変更用
	void SetY(float y);//位置情報Y変更用
	void SetX2(float x)  { m_x = x; }
	void SetY2(float y)  { m_y = y; }
	void SetVY(float vy) { m_vy = vy; }
	void SetVX(float vx) { m_vx = vx; }
	
	void SetUp(bool b) { m_hit_up = b; }
	void SetDown(bool b) { m_hit_down = b; }
	void SetLeft(bool b) { m_hit_left = b; }
	void SetRight(bool b) { m_hit_right = b; }

	bool GetUp() { return m_hit_up; }
	bool GetDown() { return m_hit_down; }
	bool GetLeft() { return m_hit_left; }
	bool GetRight(){ return m_hit_right; }

	float GetB();//弾丸の向き
	int Get_Gun() { return m_gun; }//銃を構えているか構えていないかを返す
	int Get_Gun_Kama() { return gun_Kama; ; }//構えているかのフラグ
	int Get_GunType() { return gun_type; }//銃の種類を返す
	int Get_Gun_Type_Flag() { return gun_type_flag; }//銃の種類フラグ

	int Get_AniFlame() { return m_ani_frame; }

	int Get_M_Bullet() { return m_bullet; }//弾丸数　リボルバー
	int Get_M_Bullet_Held() { return m_bullet_held; }//弾丸所持数

	int Get_M_Ass_Bullet() { return ass_bullet; }//弾丸数　アサルト
	int Get_M_Ass_Bullet_Held() { return ass_bullet_held; }//弾丸所持数

	int GetBT() { return m_block_type; }//主人公が踏んでいるブロックの種類
	void SetBT(int t) { m_block_type = t; }


private:
	float m_px; //位置
	float m_py;
	float m_x;  //主人公機のx方向移動用変数
	float m_y;  //主人公機のy方向移動用変数
	float m_vx; //移動ベクトル
	float m_vy; //移動ベクトル
	float m_posture; //横姿勢
	bool m_f; //弾丸発射制御用
	bool m_ass_f;

	//---------------------------------------------------

	int m_ani_time=0; //向きアニメーションフレーム動作間隔
	int m_ani_frame=0; //向き描画フレーム


	//---------------------------------------------------
	//正面アニメーション
	int m_ani_time1 = 0; //アニメーションフレーム動作間隔
	int m_ani_frame1=0; //描画フレーム


	//背面アニメーション
	int m_ani_time2 = 0; //アニメーションフレーム動作間隔
	int m_ani_frame2 = 0; //描画フレーム

	//右アニメーション
	int m_ani_time3 = 0; //アニメーションフレーム動作間隔
	int m_ani_frame3 = 0; //描画フレーム

	//左アニメーション
	int m_ani_time4 = 0; //アニメーションフレーム動作間隔
	int m_ani_frame4 = 0; //描画フレーム

	//----------------------------------------------------

	int m_hp;//主人公のHP
	int m_gun;//銃の向き
	int gun_type;//銃の種類
	int gun_Kama;//銃を構える
	int gun_type_flag;

	//---------------------------------------------------

	int ass_bullet;//アサルト弾丸の弾数
	int ass_bullet_held;//アサルト弾丸の所持数
	int m_bullet;//弾丸の弾数 リボルバー
	int m_bullet_held;//弾丸の所持数　リボルバー

	//---------------------------------------------------
	//blockとの衝突状態確認用
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

	//踏んでいるblockの種類を確認用
	int m_block_type;
};