#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
#include"GameL\SceneManager.h"
//使用するネームスペース
using namespace GameL;


//オブジェクト：ブロック&背景
class CObjInstitute14 :public CObj
{
public:
	CObjInstitute14() {};
	~CObjInstitute14() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー

	void SetScroll(float s) { mx_scroll = s; }
	float GetScroll() { return mx_scroll; }

	void SetScroll2(float s) { my_scroll = s; }
	float GetScroll2() { return my_scroll; }

	bool GetMap() { return map_flag2; }
private:
	int m_map[60][60];//マップ情報(仮)

	float mx_scroll; //左右スクロール用
	float my_scroll; //左右スクロール用

	bool map_flag;
	bool map_flag2;

};