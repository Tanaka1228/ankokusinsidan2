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
#include "SceneChinaTown_b.h"



//コンストラクタ
CSceneChinaTown_b::CSceneChinaTown_b()
{
}

//デストラクタ
CSceneChinaTown_b::~CSceneChinaTown_b()
{
}



//ゲームステージ初期化メソッド
void CSceneChinaTown_b::InitScene()
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

	//外部グラフィックファイルを読み込み16番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"チャイナタウンのボス戦フィールド.png", 16, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み17番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"チャイナタウンボス戦フィールドの素材.png", 17, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み3番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"看板.png", 5, TEX_SIZE_512);//グラフィック

	//外部グラフィックファイルを読み込み10番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"武器商売ロボット.png", 6, TEX_SIZE_512);


	//外部グラフィックファイルを読み込み10番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"会話.png", 8, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み13番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"病院の屋上の素材.png", 7, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み5番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"マップb.png", 18, TEX_SIZE_512);

	//　銃　音楽情報の読み込み
	Audio::LoadAudio(1, L"se_maoudamashii_battle_gun01.wav", EFFECT);//単発

	//音楽情報の読み込み
	Audio::LoadAudio(0, L"game_maoudamashii_7_event23.wav", SOUND_TYPE::BACK_MUSIC);//Loop

	//　敵爆発　音楽情報の読み込み
	Audio::LoadAudio(5, L"se_maoudamashii_explosion05.wav", EFFECT);//単発

	//バックミュージックスタート
	float v = Audio::VolumeMaster(0);//マスターボリュームを下げる
	v = Audio::VolumeMaster(0.9f - v);

	Audio::Start(0);//音楽スタート

	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero(400, 280); //主人公オブジェクト作成
	Objs::InsertObj(obj, OBJ_HERO, 3); //作った主人公オブジェクトをオブジェクトマネージャーに登録

	//モブオブジェクト追加
	CObjChinaMob* objchinamob = new CObjChinaMob();//モブ
	Objs::InsertObj(objchinamob, OBJ_CHINA_MOB, 6);

	//チャイナタウンオブジェクト作成
	CObjChinaTown_b* objc = new CObjChinaTown_b(); //チャイナタウンオブジェクト作成
	Objs::InsertObj(objc, OBJ_CHINA_TOWN_B, 1); //作ったチャイナタウンオブジェクトをオブジェクトマネージャーに登録

	//銃オブジェクト作成
	CObjGun* objg = new CObjGun();
	Objs::InsertObj(objg, OBJ_GUN, 4);

	//会話の背景オブジェクト作成
	CObjSpBack* objsp = new CObjSpBack(); //会話の背景作成
	Objs::InsertObj(objsp, OBJ_SP_BACK, 5); //作った会話の背景オブジェクトをオブジェクトマネージャーに登録

	CObjMap* objm = new CObjMap();//マップ図
	Objs::InsertObj(objm, OBJ_MAP, 7);
}


//ゲームステージ実行中メソッド
void CSceneChinaTown_b::Scene()
{
}
