#pragma once
//使用するヘッダーファイル
#include"GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ゲームタイトル
class CSceneEnd : public CScene
{
public:
	CSceneEnd();
	~CSceneEnd();
	void InitScene();
	void Scene();
	void Action();
private:

};