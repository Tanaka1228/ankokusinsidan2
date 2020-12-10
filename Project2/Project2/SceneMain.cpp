//STLデバッグ機能をOFFにする
#define _SECURE_SCR (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include"GameL\DrawTexture.h"
#include"GameL\SceneObjManager.h"
#include"GameL\UserData.h"
#include"GameL/WinInputs.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include"SceneMain.h"
#include"GameHead.h"



//コンストラクタ
CSceneMain::CSceneMain()
{

}

//デストラクタ
CSceneMain::~CSceneMain()
{

}

//ゲームメイン初期化メソッド
void CSceneMain::InitScene()
{

	//外部グラフィックファイルを読み込み0番に登録(512×512ピクセル)あまり関係ないらしい
	//Draw::LoadImage(L"Hero.png", 0, TEX_SIZE_512);//主人公グラフィック

	//外部グラフィックファイルを読み込み1番に登録(512×512ピクセル)あまり関係ないらしい
	Draw::LoadImage(L"Enemy1.png", 1, TEX_SIZE_512);//敵グラフィック

	//外部グラフィックファイルを読み込み1番に登録(512×512ピクセル)あまり関係ないらしい
	//Draw::LoadImage(L"ハンドガン.png", 2, TEX_SIZE_512);//ハンドガングラフィック

	//外部グラフィックファイルを読み込み3番に登録(512×512ピクセル)あまり関係ないらしい
	//Draw::LoadImage(L"弾丸＿右.png", 3, TEX_SIZE_512);//弾丸グラフィック

	//外部グラフィックファイルを読み込み8番に登録(512×512ピクセル)あまり関係ないらしい
	//Draw::LoadImage(L"拠点の素材.png", 8, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み11番に登録(512×512ピクセル)あまり関係ないらしい
	//Draw::LoadImage(L"メニュー画面.png", 11, TEX_SIZE_512);

		//外部グラフィックファイルを読み込み12番に登録(512×512ピクセル)あまり関係ないらしい
	//Draw::LoadImage(L"研究所のボス戦フィールド.png", 12, TEX_SIZE_512);

	//主人公オブジェクト作成
	//CObjHero* obj = new CObjHero(400,280); //主人公オブジェクト作成
	///Objs::InsertObj(obj, OBJ_HERO, 2); //作った主人公オブジェクトをオブジェクトマネージャーに登録

	//敵機オブジェクト作成
	//CObjEnemy* obj_enemy = new CObjEnemy(); //敵機オブジェクト作成
	//Objs::InsertObj(obj_enemy, OBJ_ENEMY, 3); //作った敵機オブジェクトをオブジェクトマネージャーに登録

	//blockオブジェクト作成
	//CObjBlock* objb = new CObjBlock();
	//Objs::InsertObj(objb, OBJ_BLOCK, 1);

	

	//タイム初期化
	m_time = 0;
	
	CObjMain* p = new CObjMain();
	Objs::InsertObj(p, OBJ_MAIN,1);

}

//ゲームメイン実行中メソッド
void CSceneMain::Scene()
{
	//m_time++;

	//if (m_time == 100)
	//{
	//	//Sin敵機オブジェクト作成
	//	CObjSinEnemy* obj_sin_enemy = new CObjSinEnemy(700, 300); //Sin敵機オブジェクト作成
	//	Objs::InsertObj(obj_sin_enemy, OBJ_SIN_ENEMY, 3); //Sin敵機オブジェクトをオブジェクトマネージャーに登録
	//}
	//else if (m_time == 150)
	//{
	//	//Sin敵機オブジェクト作成
	//	CObjSinEnemy* obj_sin_enemy = new CObjSinEnemy(700, 300); //Sin敵機オブジェクト作成
	//	Objs::InsertObj(obj_sin_enemy, OBJ_SIN_ENEMY, 3); //Sin敵機オブジェクトをオブジェクトマネージャーに登録
	//}
	//else if (m_time == 200)
	//{
	//	//攻撃する敵機オブジェクト作成
	//	CObjAttackEnemy* obj_attack_enemy = new CObjAttackEnemy(700, 220); //攻撃する敵機オブジェクト作成
	//	Objs::InsertObj(obj_attack_enemy, OBJ_ATTACK_ENEMY, 3); //攻撃する敵機オブジェクトをオブジェクトマネージャーに登録
	//}
	//else if (m_time == 300)
	//{
	//	//拡散敵機オブジェクト作成
	//	CObjDiffusionEnemy* obj_diffusion_enemy = new CObjDiffusionEnemy(700, 300); //Sin敵機オブジェクト作成
	//	Objs::InsertObj(obj_diffusion_enemy, OBJ_DIFFUSION_ENEMY, 3); //Sin敵機オブジェクトをオブジェクトマネージャーに登録
	//}
	//else if (m_time == 400)
	//{
	//	//誘導敵機オブジェクト作成
	//	CObjHomingEnemy* obj_homing_enemy = new CObjHomingEnemy(100, 50); //誘導敵機オブジェクト作成
	//	Objs::InsertObj(obj_homing_enemy, OBJ_HOMING_ENEMY, 3); //誘導敵機オブジェクトをオブジェクトマネージャーに登録
	//}
	//
	//if (Input::GetVKey('X') == true)
	//{
	//	//メニューオブジェクト作成
	//	CObjMenu* obj_menu = new CObjMenu(); //メニューオブジェクト作成
	//	Objs::InsertObj(obj_menu, OBJ_HOMING_ENEMY, 14); //メニューオブジェクトをオブジェクトマネージャーに登録
	//}
}