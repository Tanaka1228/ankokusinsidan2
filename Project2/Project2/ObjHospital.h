#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
#include"GameL\SceneManager.h"
//使用するネームスペース
using namespace GameL;


//定数化
#define MAP_X_MAX_1F (50)//病院の配列要素数
#define MAP_Y_MAX_1F (26)


//オブジェクト：ブロック&背景
class CObjHospital :public CObj
{
public:
	CObjHospital() {};
	~CObjHospital() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー

	void SetScroll(float s) { mx_scroll = s; }
	float GetScroll() { return mx_scroll; }

	void SetScroll2(float s) { my_scroll = s; }
	float GetScroll2() { return my_scroll; }

	bool GetMap() { return map_flag2; }

private:
	int m_map[MAP_Y_MAX_1F][MAP_X_MAX_1F];//マップ情報

	float mx_scroll; //左右スクロール用
	float my_scroll; //左右スクロール用

	int m_key_control;//会話制御
	int	key_flag;//会話フラグ
	int m_sp;//会話の種類フラグ

	bool map_flag;
	bool map_flag2;

};