#pragma once
//使用するヘッダーファイル
#include"GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ゲームタイトル
class CSceneFin : public CScene
{
public:
	CSceneFin();
	~CSceneFin();
	void InitScene();
	void Scene();
	void Action();
private:

};