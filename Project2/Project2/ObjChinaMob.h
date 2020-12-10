#pragma once
//使用するヘッダー
#include"GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト : 敵機
class CObjChinaMob : public CObj
{
public:
	CObjChinaMob();//コンストラクタ位置情報	をもらう
	~CObjChinaMob() {};
	void Init(); //イニシャライズ
	void Action(); //アクション
	void Draw(); //ドロー

	bool Sp_Flag() { return sp_flag; }
private:
	int m_sp;//会話
	int m_save_sp;//セーブ制御
	int key_flag;//会話のフラグ
	int mob_flag;//ケビン,マイケル、トーマス

	
	bool sp_flag;//会話のグラフィックのフラグ

	bool m_key_control;//会話キー制御

	int m_time;//時間
};