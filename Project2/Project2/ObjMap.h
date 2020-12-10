#pragma once
//使用するヘッダー
#include"GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト : 敵機
class CObjMap : public CObj
{
public:
	CObjMap();//コンストラクタ位置情報	をもらう
	~CObjMap() {};
	void Init(); //イニシャライズ
	void Action(); //アクション
	void Draw(); //ドロー
private:
	int m_sp;//会話
	int key_flag;//会話のフラグ
	bool sp_flag;//会話のグラフィックのフラグ

	bool m_key_control;//会話キー制御
};