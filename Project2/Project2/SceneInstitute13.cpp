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
#include"ObjInstitute13.h"



//コンストラクタ
CSceneInstitute13::CSceneInstitute13()
{
}

//デストラクタ
CSceneInstitute13::~CSceneInstitute13()
{
}



//ゲームステージ初期化メソッド
void CSceneInstitute13::InitScene()
{
	//外部グラフィックファイルを読み込み0番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"Hero.png", 0, TEX_SIZE_512);//主人公グラフィック

	//外部グラフィックファイルを読み込み1番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"ハンドガン.png", 2, TEX_SIZE_512);//ハンドガングラフィック

	//外部グラフィックファイルを読み込み3番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"弾丸＿右.png", 3, TEX_SIZE_512);//弾丸グラフィック

	//外部グラフィックファイルを読み込み5番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"研究所地下そざ.png", 5, TEX_SIZE_512);//弾丸グラフィック//外部グラフィックファイルを読み込み5番に登録(512×512ピクセル)あまり関係ないらしい

	//外部グラフィックファイルを読み込み10番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImageW(L"武器商売ロボット.png", 6, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み6番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"研究所床.png", 30, TEX_SIZE_512);//弾丸グラフィック//外部グラフィックファイルを読み込み5番に登録(512×512ピクセル)あまり関係ないらしい

		//外部グラフィックファイルを読み込み6番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"研究所地下２階.png", 8, TEX_SIZE_512);//弾丸グラフィック//外部グラフィックファイルを読み込み5番に登録(512×512ピクセル)あまり関係ないらしい

	//モブオブジェクト追加
	CObjInstMob* objinstmob = new CObjInstMob();//モブ
	Objs::InsertObj(objinstmob, OBJ_INST_MOB, 6);

	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero(400, 280); //主人公オブジェクト作成
	Objs::InsertObj(obj, OBJ_HERO, 5); //作った主人公オブジェクトをオブジェクトマネージャーに登録

	//銃オブジェクト作成
	CObjGun* objg = new CObjGun();
	Objs::InsertObj(objg, OBJ_GUN, 6);

	//研究所オブジェクト作成
	CObjInstitute13* obji = new CObjInstitute13(); //研究所オブジェクト作成
	Objs::InsertObj(obji, OBJ_INSTITUTE13, 4); //作った研究所オブジェクトをオブジェクトマネージャーに登録

		//マップ図
	CObjMap* objm = new CObjMap();//マップ図
	Objs::InsertObj(objm, OBJ_MAP, 6);

	//音楽情報の読み込み
	Audio::LoadAudio(0, L"game_maoudamashii_7_event45.wav", SOUND_TYPE::BACK_MUSIC);//Loop

	//バックミュージックスタート
	float v = Audio::VolumeMaster(0);//マスターボリュームを下げる
	v = Audio::VolumeMaster(1.0 - v);

	Audio::Start(0);//音楽スタート
}


//ゲームステージ実行中メソッド
void CSceneInstitute13::Scene()
{
}