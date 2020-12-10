#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：ブロック＆背景
class CObjBlock :public CObj
{
public:
	CObjBlock() {};
	~CObjBlock() {};
	void Init(); //イニシャライズ
	void Action(); //アクション
	void Draw(); //ドロー

	bool GetMap() { return map_flag2; }
private:
	int m_map[25][25]; //マップ情報(仮）

	bool map_flag;
	bool map_flag2;


};