#pragma once
//使用するヘッダー
#include"GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：弾丸
class CObjGun : public CObj
{
public:
	CObjGun();
	~CObjGun() {};
	void Init();     //イニシャライズ
	void Action();  //アクション
	void Draw();   //ドロー

private:
	int m_f;//弾丸制御
	int m_gun;//銃の向き
	int m_bullet;//弾丸の数
	int m_bullet_held;//弾丸の所持数
	int m_ani_frame;//銃向き

};
