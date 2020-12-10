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
#include"ObjInstitute8.h"



//コンストラクタ
CSceneInstitute8::CSceneInstitute8()
{
}

//デストラクタ
CSceneInstitute8::~CSceneInstitute8()
{
}



//ゲームステージ初期化メソッド
void CSceneInstitute8::InitScene()
{
	//外部グラフィックファイルを読み込み0番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"Hero.png", 0, TEX_SIZE_512);//主人公グラフィック

	//外部グラフィックファイルを読み込み1番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"ハンドガン.png", 2, TEX_SIZE_512);//ハンドガングラフィック

	//外部グラフィックファイルを読み込み3番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"弾丸＿右.png", 3, TEX_SIZE_512);//弾丸グラフィック

	//外部グラフィックファイルを読み込み5番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"研究所地下そざ.png", 5, TEX_SIZE_512);//弾丸グラフィック//外部グラフィックファイルを読み込み5番に登録(512×512ピクセル)あまり関係ないらしい

	//外部グラフィックファイルを読み込み6番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"研究所床.png", 30, TEX_SIZE_512);//弾丸グラフィック//外部グラフィックファイルを読み込み5番に登録(512×512ピクセル)あまり関係ないらしい



	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero(400, 280); //主人公オブジェクト作成
	Objs::InsertObj(obj, OBJ_HERO, 4); //作った主人公オブジェクトをオブジェクトマネージャーに登録

	//銃オブジェクト作成
	CObjGun* objg = new CObjGun();
	Objs::InsertObj(objg, OBJ_GUN, 5);

	//研究所オブジェクト作成
	CObjInstitute8* obji = new CObjInstitute8(); //研究所オブジェクト作成
	Objs::InsertObj(obji, OBJ_INSTITUTE1, 3); //作った研究所オブジェクトをオブジェクトマネージャーに登録

		//音楽情報の読み込み
	Audio::LoadAudio(0, L"game_maoudamashii_7_event45.wav", SOUND_TYPE::BACK_MUSIC);//Loop

	//バックミュージックスタート
	float v = Audio::VolumeMaster(0);//マスターボリュームを下げる
	v = Audio::VolumeMaster(1.0 - v);

	Audio::Start(0);//音楽スタート
}


//ゲームステージ実行中メソッド
void CSceneInstitute8::Scene()
{
}
