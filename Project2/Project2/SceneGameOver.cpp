//STLデバッグ機能をOFFにする
#define _SECHURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include"GameL\SceneObjManager.h"
#include"GameL\DrawFont.h"
#include"GameL/Audio.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include"SceneGameOver.h"
#include"GameHead.h"

//コンストラクタ
CSceneGameOver::CSceneGameOver()
{

}

//デストラクタ
CSceneGameOver::~CSceneGameOver()
{

}

//ゲームメイン初期化メソッド
void CSceneGameOver::InitScene()
{


	//音楽情報の読み込み
	//Audio::LoadAudio(0, L".wav", SOUND_TYPE::BACK_MUSIC);//Loop

	//バックミュージックスタート
	//float v = Audio::VolumeMaster(0);//マスターボリュームを下げる
	//v = Audio::VolumeMaster(1.0 - v);

	//Audio::Start(0);//音楽スタート

	//ゲームオーバーオブジェクト作成
	CObjGameOver* obj = new CObjGameOver();
	Objs::InsertObj(obj, OBJ_GAME_OVER, 10);
}

//実行中メソッド
void CSceneGameOver::Scene()
{
	
}
