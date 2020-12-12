//STLのデバック機能をOFFにする
#define _SECURE_SCL (0);
#define _HAS_ITERATOR_DEBUGGING (0);

//GameLで使用するヘッダー
#include"GameL\SceneObjManager.h"
#include"GameL\DrawFont.h"
#include"GameL/DrawTexture.h"
#include"GameL/Audio.h"

//使用するネームスペース
using namespace GameL;

//使用するヘッダー
#include"GameHead.h"
#include "SceneDrugCampanyRoom9.h"



//コンストラクタ
CSceneDrugCampanyRoom9::CSceneDrugCampanyRoom9()
{
}

//デストラクタ
CSceneDrugCampanyRoom9::~CSceneDrugCampanyRoom9()
{
}



//ゲームステージ初期化メソッド
void CSceneDrugCampanyRoom9::InitScene()
{
	//外部グラフィックファイルを読み込み0番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"Hero.png", 0, TEX_SIZE_512);//主人公グラフィック

	//外部グラフィックファイルを読み込み1番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"ハンドガン.png", 2, TEX_SIZE_512);//ハンドガングラフィック

	//外部グラフィックファイルを読み込み3番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"弾丸＿右.png", 3, TEX_SIZE_512);//弾丸グラフィック

	//外部グラフィックファイルを読み込み3番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"製薬会社.png", 4, TEX_SIZE_512);//グラフィック

	//外部グラフィックファイルを読み込み3番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"製薬会社　床.png", 5, TEX_SIZE_512);//グラフィック

	//　銃　音楽情報の読み込み
	Audio::LoadAudio(1, L"se_maoudamashii_battle_gun01.wav", EFFECT);//単発

	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero(400, 280); //主人公オブジェクト作成
	Objs::InsertObj(obj, OBJ_HERO, 4); //作った主人公オブジェクトをオブジェクトマネージャーに登録

	//銃オブジェクト作成
	CObjGun* objg = new CObjGun();
	Objs::InsertObj(objg, OBJ_GUN, 5);

	//製薬会社オブジェクト作成
	CObjDrugCampanyRoom9* objd = new CObjDrugCampanyRoom9(); //製薬会社オブジェクト作成
	Objs::InsertObj(objd, OBJ_DRUG_CAMPANY_ROOM9, 3); //作った製薬会社オブジェクトをオブジェクトマネージャーに登録

	//音楽情報の読み込み
	Audio::LoadAudio(0, L"bgm_maoudamashii_cyber19.wav", SOUND_TYPE::BACK_MUSIC);//Loop

	//バックミュージックスタート
	float v = Audio::VolumeMaster(0);//マスターボリュームを下げる
	v = Audio::VolumeMaster(1.0 - v);

	Audio::Start(0);//音楽スタート
}


//ゲームステージ実行中メソッド
void CSceneDrugCampanyRoom9::Scene()
{
}