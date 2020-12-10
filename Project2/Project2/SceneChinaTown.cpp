//STLのデバック機能をOFFにする
#define _SECURE_SCL (0);
#define _HAS_ITERATOR_DEBUGGING (0);

//GameLで使用するヘッダー
#include"GameL\SceneObjManager.h"
#include"GameL\DrawFont.h"
#include"GameL/DrawTexture.h"

//使用するネームスペース
using namespace GameL;

//使用するヘッダー
#include"GameHead.h"
#include "SceneChinaTown.h"

extern int ChinaTown_Hero_x;

//コンストラクタ
CSceneChinaTown::CSceneChinaTown()
{
}

//デストラクタ
CSceneChinaTown::~CSceneChinaTown()
{
}



//ゲームステージ初期化メソッド
void CSceneChinaTown::InitScene()
{
	//外部グラフィックファイルを読み込み0番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"Hero.png", 0, TEX_SIZE_512);//主人公グラフィック

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
	Draw::LoadImage(L"製薬会社　床.png", 5, TEX_SIZE_512);//グラフィック

	//外部グラフィックファイルを読み込み10番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"武器商売ロボット.png", 6, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み10番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"会話.png", 7, TEX_SIZE_512);


	//外部グラフィックファイルを読み込み5番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"マップa.png", 15, TEX_SIZE_512);

	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero(400, 280); //主人公オブジェクト作成
	Objs::InsertObj(obj, OBJ_HERO, 5); //作った主人公オブジェクトをオブジェクトマネージャーに登録


	//チャイナタウンオブジェクト作成
	CObjChinaTown* objc = new CObjChinaTown(); //チャイナタウンオブジェクト作成
	Objs::InsertObj(objc, OBJ_CHINA_TOWN, 4); //作ったチャイナタウンオブジェクトをオブジェクトマネージャーに登録

	//会話の背景オブジェクト作成
	CObjSpBack* objsp = new CObjSpBack(); //会話の背景作成
	Objs::InsertObj(objsp, OBJ_SP_BACK, 5); //作った会話の背景オブジェクトをオブジェクトマネージャーに登録

	//銃オブジェクト作成
	CObjGun* objg = new CObjGun();
	Objs::InsertObj(objg, OBJ_GUN, 6);

	//チャイナタウンモブオブジェクト作成
	CObjChinaMob* objm = new CObjChinaMob(); //チャイナタウンモブオブジェクト作成
	Objs::InsertObj(objm, OBJ_CHINA_MOB, 6); //作ったチャイナタウンオブジェクトをオブジェクトマネージャーに登録

	CObjMap* objma = new CObjMap();//マップ図
	Objs::InsertObj(objma, OBJ_MAP, 7);
}


//ゲームステージ実行中メソッド
void CSceneChinaTown::Scene()
{
}
