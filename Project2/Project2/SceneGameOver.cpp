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
	//外部グラフィックファイルを読み込み0番に登録(512×512ピクセル)
	Draw::LoadImage(L"Sifi_town3_4n-480x270.png", 4, TEX_SIZE_512);//titleバックグリーン
	Draw::LoadImage(L"メニュー画面 - コピー - コピー.png", 6, TEX_SIZE_512);//カーソル	
	Draw::LoadImage(L"Hero.png", 5, TEX_SIZE_512);//カーソル	

	//音楽情報の読み込み
	Audio::LoadAudio(0, L".game_maoudamashii_7_event30.wav", SOUND_TYPE::BACK_MUSIC);//Loop

	//　選択　音楽情報の読み込み
	Audio::LoadAudio(1, L"決定.wav", EFFECT);//単発

	//バックミュージックスタート
	float v = Audio::VolumeMaster(0);//マスターボリュームを下げる
	v = Audio::VolumeMaster(0.4 - v);

	//Audio::Start(0);//音楽スタート

	//ゲームオーバーオブジェクト作成
	CObjGameOver* obj = new CObjGameOver();
	Objs::InsertObj(obj, OBJ_GAME_OVER, 1);
}

//実行中メソッド
void CSceneGameOver::Scene()
{
	
}
