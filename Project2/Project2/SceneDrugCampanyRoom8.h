#pragma once


//使用するヘッダーファイル
#include"GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ステージ
class CSceneDrugCampanyRoom8 :public CScene
{
public:
	CSceneDrugCampanyRoom8();//コンストラクタ
	~CSceneDrugCampanyRoom8();//デストラクタ
	void InitScene();//ゲームステージ初期化メソッド
	void Scene();//ゲームステージ実行中メソッド
private:

};
