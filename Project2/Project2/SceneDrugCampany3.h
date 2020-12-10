#pragma once


//使用するヘッダーファイル
#include"GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ステージ
class CSceneDrugCampany3 :public CScene
{
public:
	CSceneDrugCampany3();//コンストラクタ
	~CSceneDrugCampany3();//デストラクタ
	void InitScene();//ゲームステージ初期化メソッド
	void Scene();//ゲームステージ実行中メソッド
private:

};
