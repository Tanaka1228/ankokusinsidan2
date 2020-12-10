#pragma once

//使用するヘッダーファイル
#include"GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ステージ
class CSceneXRayRoom :public CScene
{
public:
	CSceneXRayRoom();//コンストラクタ
	~CSceneXRayRoom();//デストラクタ
	void InitScene();//ゲームステージ初期化メソッド
	void Scene();//ゲームステージ実行中メソッド
private:

};