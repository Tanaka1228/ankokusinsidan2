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
CSceneTitle::CSceneTitle()
{

}


//デストラクタ
CSceneTitle::~CSceneTitle()
{

}

//ゲームメイン初期化メソッド
void CSceneTitle::InitScene()
{
	//タイトルオブジェクト作成
	CObjTitle* obj = new CObjTitle();
	Objs::InsertObj(obj, OBJ_TITLE, 10);

	//外部グラフィックファイルを読み込み0番に登録(512×512ピクセル)
	Draw::LoadImage(L"Sifi_town3_4n-480x270.png", 4, TEX_SIZE_512);//titleバックグリーン
	Draw::LoadImage(L"メニュー画面 - コピー - コピー.png", 6, TEX_SIZE_512);//カーソル	
	Draw::LoadImage(L"女の子正面.png", 5, TEX_SIZE_512);//カーソル	
	
	//音楽情報の読み込み
	//Audio::LoadAudio(0, L".wav", SOUND_TYPE::BACK_MUSIC);//Loop

	//バックミュージックスタート
	//float Volume = Audio::VolumeMaster(-0.8f);//マスターボリュームを下げる
	//Audio::Start(0);//音楽スタート

	//オブジェクト作成
	CObjTitleBackground* back = new CObjTitleBackground();
	Objs::InsertObj(back, OBJ_TITLE_BACKGROUND, 4), (back, OBJ_TITLE_BACKGROUND, 6),(back, OBJ_TITLE_BACKGROUND, 5);

}

//ゲームメイン実行中メソッド
void CSceneTitle::Scene()
{

}