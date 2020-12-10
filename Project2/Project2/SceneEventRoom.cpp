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
#include "SceneEventRoom.h"



//コンストラクタ
CSceneEventRoom::CSceneEventRoom()
{
}

//デストラクタ
CSceneEventRoom::~CSceneEventRoom()
{
}



//ゲームステージ初期化メソッド
void CSceneEventRoom::InitScene()
{
	//外部グラフィックファイルを読み込み0番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"Hero.png", 0, TEX_SIZE_512);//主人公グラフィック

	//外部グラフィックファイルを読み込み1番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"ハンドガン.png", 2, TEX_SIZE_512);//ハンドガングラフィック

	//外部グラフィックファイルを読み込み3番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"弾丸＿右.png", 3, TEX_SIZE_512);//弾丸グラフィック

	//外部グラフィックファイルを読み込み4番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"病院.png", 4, TEX_SIZE_512);//病院グラフィック

	//外部グラフィックファイルを読み込み5番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"病院の屋上の素材.png", 5, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み6番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"病院床.png", 6, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み10番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"武器商売ロボット.png", 7, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み10番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"会話.png", 8, TEX_SIZE_512);

	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero(400, 280); //主人公オブジェクト作成
	Objs::InsertObj(obj, OBJ_HERO, 2); //作った主人公オブジェクトをオブジェクトマネージャーに登録

	//銃オブジェクト作成
	CObjGun* objg = new CObjGun();
	Objs::InsertObj(objg, OBJ_GUN, 3);

	//病院の部屋オブジェクト作成
	CObjEventRoom* obje = new CObjEventRoom(); //病院部屋オブジェクト作成
	Objs::InsertObj(obje, OBJ_EVENT_ROOM, 1); //作った病院オブジェクトをオブジェクトマネージャーに登録

	//会話の背景オブジェクト作成
	CObjSpBack* objsp = new CObjSpBack(); //会話の背景作成
	Objs::InsertObj(objsp, OBJ_SP_BACK, 5); //作った会話の背景オブジェクトをオブジェクトマネージャーに登録
}


//ゲームステージ実行中メソッド
void CSceneEventRoom::Scene()
{
}
