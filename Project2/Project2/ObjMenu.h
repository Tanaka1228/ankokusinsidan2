#pragma once
//使用するヘッダ―
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：タイトル
class CObjMenu : public CObj
{
public:
	CObjMenu(){};
	~CObjMenu() {};
	void Init();
	void Action();
	void Draw();
private:
	
};
