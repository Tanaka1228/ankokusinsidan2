#pragma once
//使用するヘッダーファイル
#include"GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ゲームタイトル
class CObjGameOver : public CObj
{
public:
	CObjGameOver() {};
	~CObjGameOver() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー
private:
	bool m_key_flag;//キーフラグ

	float m_key_uy;//矢印キーの位置ｘ
	float m_key_dy;//矢印キーの位置 y
	float m_key_enter;//決定

	int m_x;
	int m_y;//カーソル移動

};