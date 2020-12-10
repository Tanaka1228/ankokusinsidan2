#pragma once
//使用するヘッダー
#include"GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト : 敵機
class CObjInstMob : public CObj
{
public:
	CObjInstMob();//コンストラクタ位置情報	をもらう
	~CObjInstMob() {};
	void Init(); //イニシャライズ
	void Action(); //アクション
	void Draw(); //ドロー
	bool Sp_Flag() { return sp_flag; }
private:
	int m_sp;//会話
	int m_save_sp;//セーブ制御
	int key_flag;//会話のフラグ
	bool sp_flag;//会話のグラフィックのフラグ

	bool m_key_control;//会話キー制御

	int mob_flag;
};