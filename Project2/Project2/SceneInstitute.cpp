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
#include "ObjInstitute.h"



//コンストラクタ
CSceneInstitute::CSceneInstitute()
{
}

//デストラクタ
CSceneInstitute::~CSceneInstitute()
{
}



//ゲームステージ初期化メソッド
void CSceneInstitute::InitScene()
{
	//外部グラフィックファイルを読み込み0番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"Hero.png", 0, TEX_SIZE_512);//主人公グラフィック

		//外部グラフィックファイルを読み込み1番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"Enemy1.png", 1, TEX_SIZE_512);//敵グラフィック

	//外部グラフィックファイルを読み込み1番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"ハンドガン.png", 2, TEX_SIZE_512);//ハンドガングラフィック

	//外部グラフィックファイルを読み込み3番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"弾丸＿右.png", 3, TEX_SIZE_512);//弾丸グラフィック

	//外部グラフィックファイルを読み込み4番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"チャイナタウン.png", 4, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み5番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"研究所地下そざ.png", 5, TEX_SIZE_512);//弾丸グラフィック//外部グラフィックファイルを読み込み5番に登録(512×512ピクセル)あまり関係ないらしい
	
		//外部グラフィックファイルを読み込み10番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"武器商売ロボット.png", 6, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み6番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"研究所床.png",30, TEX_SIZE_512);//弾丸グラフィック//外部グラフィックファイルを読み込み5番に登録(512×512ピクセル)あまり関係ないらしい

	//外部グラフィックファイルを読み込み6番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"研究所１階.png", 7, TEX_SIZE_512);//弾丸グラフィック//外部グラフィックファイルを読み込み5番に登録(512×512ピクセル)あまり関係ないらしい

	//外部グラフィックファイルを読み込み10番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"会話.png", 8, TEX_SIZE_512);

	//　銃　音楽情報の読み込み
	Audio::LoadAudio(1, L"se_maoudamashii_battle_gun01.wav", EFFECT);//単発

		//　敵爆発　音楽情報の読み込み
	Audio::LoadAudio(5, L"se_maoudamashii_explosion05.wav", EFFECT);//単発

	//音楽情報の読み込み
	Audio::LoadAudio(0, L"bgm_maoudamashii_cyber22.wav", SOUND_TYPE::BACK_MUSIC);//Loop

	//バックミュージックスタート
	float v = Audio::VolumeMaster(0);//マスターボリュームを下げる
	v = Audio::Volume(0.4 - v,0);

	Audio::Start(0);//音楽スタート

	//モブオブジェクト追加
	CObjInstMob* objinstmob = new CObjInstMob();//モブ
	Objs::InsertObj(objinstmob, OBJ_INST_MOB, 6);

	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero(400, 280); //主人公オブジェクト作成
	Objs::InsertObj(obj, OBJ_HERO, 3); //作った主人公オブジェクトをオブジェクトマネージャーに登録

		//マップ図
	CObjMap* objm = new CObjMap();//マップ図
	Objs::InsertObj(objm, OBJ_MAP, 7);

	//銃オブジェクト作成
	CObjGun* objg = new CObjGun();
	Objs::InsertObj(objg, OBJ_GUN, 4);

	//研究所オブジェクト作成
	CObjInstitute* obji = new CObjInstitute(); //研究所オブジェクト作成
	Objs::InsertObj(obji, OBJ_INSTITUTE, 1); //作った研究所オブジェクトをオブジェクトマネージャーに登録

	//会話の背景オブジェクト作成
	CObjSpBack* objsp = new CObjSpBack(); //会話の背景作成
	Objs::InsertObj(objsp, OBJ_SP_BACK, 5); //作った会話の背景オブジェクトをオブジェクトマネージャーに登録



}


//ゲームステージ実行中メソッド
void CSceneInstitute::Scene()
{
}
