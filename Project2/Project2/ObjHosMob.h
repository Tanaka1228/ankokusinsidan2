#pragma once
//使用するヘッダー
#include"GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト : 敵機
class CObjHosMob : public CObj
{
public:
	CObjHosMob();//コンストラクタ位置情報	をもらう
	~CObjHosMob() {};
	void Init(); //イニシャライズ
	void Action(); //アクション
	void Draw(); //ドロー

	bool Sp_Flag() { return sp_flag; }//会話の背景
	void SetSp_flag(bool s) { sp_flag = s; }

	int GetM_sp() { return  m_sp; }//会話の順番
	void SetM_sp(int m) { m_sp = m; }

private:
	int m_sp;//会話
	int m_save_sp;//セーブ制御
	int key_flag;//会話のフラグ
	bool sp_flag;//会話のグラフィックのフラグ

	bool m_key_control;//会話キー制御

	int mob_flag;

	bool Save_sp;
};