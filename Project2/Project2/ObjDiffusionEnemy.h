#pragma once
//使用するヘッダー
#include"GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト : 敵機
class CObjDiffusionEnemy : public CObj
{
public:
	CObjDiffusionEnemy(float x, float y);//コンストラクタ位置情報	をもらう
	~CObjDiffusionEnemy() {};
	void Init(); //イニシャライズ
	void Action(); //アクション
	void Draw(); //ドロー
private:
	float m_x; //敵機のx方向の位置
	float m_y; //敵機のy方向の位置
	float m_vx;//敵機移動ベクトルX
	float m_vy;//敵機移動ベクトルY
	int   m_time;//拡散敵機の角度弾丸をウツ間隔用変数

};
