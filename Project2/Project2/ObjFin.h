#pragma once
//使用するヘッダ―
#include"GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：タイトル
class CObjFin : public CObj
{
public:
	CObjFin() {};
	~CObjFin() {};
	void Init();
	void Action();
	void Draw();
private:
	bool m_key_flag;//キーフラグ

};