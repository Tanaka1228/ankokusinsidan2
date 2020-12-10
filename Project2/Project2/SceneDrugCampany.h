#pragma once


//使用するヘッダーファイル
#include"GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ステージ
class CSceneDrugCampany :public CScene
{
public:
	CSceneDrugCampany();//コンストラクタ
	~CSceneDrugCampany();//デストラクタ
	void InitScene();//ゲームステージ初期化メソッド
	void Scene();//ゲームステージ実行中メソッド
private:

};