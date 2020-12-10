#pragma once
//使用するヘッダ―
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：タイトル
class CObjTitleBackground : public CObj
{
public:
	CObjTitleBackground () {};
	~CObjTitleBackground () {};
	void Init();
	void Action();
	void Draw();
private:
	
};