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
#include "SceneDrugCampany.h"



//コンストラクタ
CSceneDrugCampany::CSceneDrugCampany()
{
}

//デストラクタ
CSceneDrugCampany::~CSceneDrugCampany()
{
}



//ゲームステージ初期化メソッド
void CSceneDrugCampany::InitScene()
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

	//外部グラフィックファイルを読み込み10番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"武器商売ロボット.png", 6, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み7番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"製薬会社１階マップ.png", 7, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み10番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"会話.png", 8, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み4番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"チャイナタウン.png", 9, TEX_SIZE_512);


	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero(400, 280); //主人公オブジェクト作成
	Objs::InsertObj(obj, OBJ_HERO, 4); //作った主人公オブジェクトをオブジェクトマネージャーに登録

	//製薬会社のモブオブジェクト追加
	CObjDrugMob* objdrugmob = new CObjDrugMob();//モブ
	Objs::InsertObj(objdrugmob, OBJ_DRUG_MOB, 6);

	//マップ図
	CObjMap* objm = new CObjMap();//マップ図
	Objs::InsertObj(objm, OBJ_MAP, 4);

	//銃オブジェクト作成
	CObjGun* objg = new CObjGun();
	Objs::InsertObj(objg, OBJ_GUN, 5);

	//製薬会社オブジェクト作成
	CObjDrugCampany* objd = new CObjDrugCampany(); //製薬会社オブジェクト作成
	Objs::InsertObj(objd, OBJ_DRUG_CAMPANY, 3); //作った製薬会社オブジェクトをオブジェクトマネージャーに登録

	//会話の背景オブジェクト作成
	CObjSpBack* objsp = new CObjSpBack(); //会話の背景作成
	Objs::InsertObj(objsp, OBJ_SP_BACK, 5); //作った会話の背景オブジェクトをオブジェクトマネージャーに登録
}


//ゲームステージ実行中メソッド
void CSceneDrugCampany::Scene()
{
}
