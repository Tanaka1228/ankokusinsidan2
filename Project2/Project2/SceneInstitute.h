#pragma once

//使用するヘッダーファイル
#include"GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ステージ
class CSceneInstitute :public CScene
{
public:
	CSceneInstitute();//コンストラクタ
	~CSceneInstitute();//デストラクタ
	void InitScene();//ゲームステージ初期化メソッド
	void Scene();//ゲームステージ実行中メソッド
private:

};