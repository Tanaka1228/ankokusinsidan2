#pragma once
//使用するヘッダー
#include"GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：弾丸
class CObjAngleBullet : public CObj
{
public:
	CObjAngleBullet(float x, float y,float r,float speed);
	~CObjAngleBullet() {};
	void Init();     //イニシャライズ
	void Action();  //アクション
	void Draw();   //ドロー
private:
	float m_x;  //弾丸のX方向の位置用変数
	float m_y;  //弾丸のY方向の位置用変数
	float m_vx; //オブジェクトの移動用ベクトルX
	float m_vy; //オブジェクトの移動用ベクトルY
	float m_speed;//速度
	float m_r;//移動する角度
};
