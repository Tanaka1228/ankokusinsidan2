//STLデバッグ機能をOFFにする
#define _SECURE_SCL	(0)  
#define _HAS_ITERATOR_DEBUGGING	(0)  

//GameLで使用するヘッダー
#include"GameL\SceneObjManager.h"
#include"GameL\DrawFont.h"
#include"GameL/DrawTexture.h"
#include"GameL/Audio.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include"SceneMain.h"
#include"GameHead.h"

//コンストラクタ
CSceneEnd::CSceneEnd()
{

}


//デストラクタ
CSceneEnd::~CSceneEnd()
{

}

//ゲームメイン初期化メソッド
void CSceneEnd::InitScene()
{
	//音楽情報の読み込み
	//Audio::LoadAudio(0, L".wav", SOUND_TYPE::BACK_MUSIC);//Loop

	//バックミュージックスタート
	//float v = Audio::VolumeMaster(0);//マスターボリュームを下げる
	//v = Audio::VolumeMaster(1.0 - v);

	//Audio::Start(0);//音楽スタート

	//タイトルオブジェクト作成
	//CObjEnd* obj = new CObjEnd();
	//Objs::InsertObj(obj, OBJ_END, 10);

}

//ゲームメイン実行中メソッド
void CSceneEnd::Scene()
{

}