#pragma once
//使用するヘッダー
#include"GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：弾丸
class CObjBulletEnemy : public CObj
{
public:
	CObjBulletEnemy(float x,float y);
	~CObjBulletEnemy(){};
	void Init();     //イニシャライズ
	void Action();  //アクション
	void Draw();   //ドロー
private:
	float m_x;  //オブジェクトの位置X
	float m_y;  //オブジェクトの位置Y
	float m_vx; //オブジェクトの移動用ベクトルX
	float m_vy; //オブジェクトの移動用ベクトルY
};

