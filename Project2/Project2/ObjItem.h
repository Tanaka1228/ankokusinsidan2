#pragma once
//使用するヘッダー
#include"GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト : 敵機
class CObjItem : public CObj
{
public:
	CObjItem(float x, float y);//コンストラクタ位置情報	をもらう
	~CObjItem() {};
	void Init(); //イニシャライズ
	void Action(); //アクション
	void Draw(); //ドロー

	static int Get_M_Bullet_Item() { return m_bullet_item; }//弾丸所持数をわたす
	void Set_M_Bullet_Item(int b) { m_bullet_item = b; };

private:
	float m_x; //Itemのx方向の位置
	float m_y; //Itemのy方向の位置

	static int m_bullet_item;//弾丸の所持数　リボルバー

};