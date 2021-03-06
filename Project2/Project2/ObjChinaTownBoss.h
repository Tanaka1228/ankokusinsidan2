#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
#include"GameL\SceneManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：ブロック＆背景
class CObjChinaTownBoss :public CObj
{
public:
	CObjChinaTownBoss() {};
	~CObjChinaTownBoss() {};
	void Init(); //イニシャライズ
	void Action(); //アクション
	void Draw(); //ドロー

	void SetScroll(float s) { mx_scroll = s; }
	float GetScroll() { return mx_scroll; }//X

	void SetScroll2(float s) { my_scroll = s; }
	float GetScroll2() { return my_scroll; }//Y

	bool GetMap() { return map_flag; }

	
private:

	int m_map[100][100]; //マップ情報

	float mx_scroll; //左右スクロール用
	float my_scroll; //左右スクロール用

	bool map_flag;



};
