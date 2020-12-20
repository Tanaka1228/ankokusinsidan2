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

private:
	float m_x; //Itemのx方向の位置
	float m_y; //Itemのy方向の位置
};