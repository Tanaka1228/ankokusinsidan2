#pragma once

//使用するヘッダーファイル
#include"GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ステージ
class CSceneHospitalRoom2 :public CScene
{
public:
	CSceneHospitalRoom2();//コンストラクタ
	~CSceneHospitalRoom2();//デストラクタ
	void InitScene();//ゲームステージ初期化メソッド
	void Scene();//ゲームステージ実行中メソッド
private:

};