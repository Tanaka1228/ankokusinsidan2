#pragma once


//使用するヘッダーファイル
#include"GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ステージ
class CSceneDrugCampanyRoom1 :public CScene
{
public:
	CSceneDrugCampanyRoom1();//コンストラクタ
	~CSceneDrugCampanyRoom1();//デストラクタ
	void InitScene();//ゲームステージ初期化メソッド
	void Scene();//ゲームステージ実行中メソッド
private:

};
