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
#include "SceneDrugCampany2.h"



//コンストラクタ
CSceneDrugCampany2::CSceneDrugCampany2()
{
}

//デストラクタ
CSceneDrugCampany2::~CSceneDrugCampany2()
{
}



//ゲームステージ初期化メソッド
void CSceneDrugCampany2::InitScene()
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

	//外部グラフィックファイルを読み込み7番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"製薬会社２階マップ.png", 6, TEX_SIZE_512);

	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero(400, 280); //主人公オブジェクト作成
	Objs::InsertObj(obj, OBJ_HERO, 4); //作った主人公オブジェクトをオブジェクトマネージャーに登録

	//マップ図
	CObjMap* objm = new CObjMap();//マップ図
	Objs::InsertObj(objm, OBJ_MAP, 5);

	//銃オブジェクト作成
	CObjGun* objg = new CObjGun();
	Objs::InsertObj(objg, OBJ_GUN, 5);

	//製薬会社オブジェクト作成
	CObjDrugCampany2* objd = new CObjDrugCampany2(); //製薬会社オブジェクト作成
	Objs::InsertObj(objd, OBJ_DRUG_CAMPANY2, 3); //作った製薬会社オブジェクトをオブジェクトマネージャーに登録
}


//ゲームステージ実行中メソッド
void CSceneDrugCampany2::Scene()
{
}
