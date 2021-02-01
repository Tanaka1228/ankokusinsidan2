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
#include "SceneHospital2.h"



//コンストラクタ
CSceneHospital2::CSceneHospital2()
{
}

//デストラクタ
CSceneHospital2::~CSceneHospital2()
{
}



//ゲームステージ初期化メソッド
void CSceneHospital2::InitScene()
{
	//外部グラフィックファイルを読み込み0番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"Hero.png", 0, TEX_SIZE_512);//主人公グラフィック

	//外部グラフィックファイルを読み込み5番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"病院マップ.png", 1, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み1番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"ハンドガン.png", 2, TEX_SIZE_512);//ハンドガングラフィック

	//外部グラフィックファイルを読み込み3番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"弾丸＿右.png", 3, TEX_SIZE_512);//弾丸グラフィック

	//外部グラフィックファイルを読み込み4番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"病院.png", 4, TEX_SIZE_512);//病院グラフィック

	//外部グラフィックファイルを読み込み13番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"病院の屋上の素材.png", 5, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み6番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"病院床.png", 6, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み5番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"エレベーター.png", 7, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み1番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"Enemy1.png", 11, TEX_SIZE_512);//敵グラフィック

	//　銃　音楽情報の読み込み
	Audio::LoadAudio(1, L"se_maoudamashii_battle_gun01.wav", EFFECT);//単発

	//音楽情報の読み込み
	Audio::LoadAudio(0, L"bgm_maoudamashii_healing06.wav", SOUND_TYPE::BACK_MUSIC);//Loop

	//爆発
	Audio::LoadAudio(5, L"se_maoudamashii_explosion05.wav", EFFECT);//単発

	//　ドア　音楽情報の読み込み
	Audio::LoadAudio(4, L"ドア.wav", EFFECT);//単発

		//バックミュージックスタート
	float v = Audio::VolumeMaster(0);//マスターボリュームを下げる
	v = Audio::VolumeMaster(0.6 - v);

	Audio::Start(0);//音楽スタート

	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero(400, 280); //主人公オブジェクト作成
	Objs::InsertObj(obj, OBJ_HERO, 2); //作った主人公オブジェクトをオブジェクトマネージャーに登録

	//マップ図
	CObjMap* objm = new CObjMap();//マップ図
	Objs::InsertObj(objm, OBJ_MAP, 4);

	//銃オブジェクト作成
	CObjGun* objg = new CObjGun();
	Objs::InsertObj(objg, OBJ_GUN, 3);

	//病院オブジェクト作成
	CObjHospital2* objh = new CObjHospital2(); //病院オブジェクト作成
	Objs::InsertObj(objh, OBJ_HOSPITAL2, 1); //作った病院オブジェクトをオブジェクトマネージャーに登録


}


//ゲームステージ実行中メソッド
void CSceneHospital2::Scene()
{
}
