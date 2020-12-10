#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
#include"GameL\SceneManager.h"
//使用するネームスペース
using namespace GameL;

//定数化
#define MAP_X_MAX (50)//病院の配列要素数
#define MAP_Y_MAX (25)


//オブジェクト：ブロック&背景
class CObjHospital3:public CObj
{
public:
	CObjHospital3() {};
	~CObjHospital3() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー

	void SetScroll(float s) { mx_scroll = s; }
	float GetScroll() { return mx_scroll; }

	void SetScroll2(float s) { my_scroll = s; }
	float GetScroll2() { return my_scroll; }

	bool GetMap() { return map_flag2; }
private:
	int m_map3[MAP_Y_MAX][MAP_X_MAX];//マップ情報(仮)

	float mx_scroll; //左右スクロール用
	float my_scroll; //左右スクロール用

	bool map_flag;
	bool map_flag2;

};