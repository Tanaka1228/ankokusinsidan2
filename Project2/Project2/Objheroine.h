#pragma once
//使用するヘッダー
#include"GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト : 敵機
class CObjHeroine : public CObj
{
public:
	CObjHeroine();//コンストラクタ位置情報	をもらう
	~CObjHeroine() {};
	void Init(); //イニシャライズ
	void Action(); //アクション
	void Draw(); //ドロー

	bool Sp_Flag() { return sp_flag; }//会話の背景
	void SetSp_flag(int s) { sp_flag = s; }

	bool GetM_sp() { return  m_sp; }//会話の順番
	void SetM_sp(int m) { m_sp = m; }

private:
	int m_sp;//会話
	int key_flag;//会話のフラグ
	bool sp_flag;//会話のグラフィックのフラグ

	bool m_key_control;//会話キー制御
};