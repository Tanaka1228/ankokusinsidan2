//使用するヘッダ―ファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"
#include"GameL\DrawFont.h"
#include"GameL/Audio.h"

#include"GameHead.h"
#include"ObjTitle.h"
#include"GameL/UserData.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjTitle::Init()
{
	 m_key_flag = false;
	 m_y = 345;
	 m_x = 240;
	 m_key_uy = 0.0f;
	 m_key_dy = 0.0f;
	 m_key_enter = false;
	 m_color = 1.0f;
	 color_flag = true;
}

//アクション
void CObjTitle::Action()
{
	CObjChinaTown* chinatown = (CObjChinaTown*)Objs::GetObj(OBJ_CHINA_TOWN);


	 //矢印キーの位置取得
	 m_key_uy = (float)Input::GetVKey(VK_UP);
	 m_key_dy = (float)Input::GetVKey(VK_DOWN);
	 //矢印キーのボタンの状態
	 m_key_enter = Input::GetVKey(VK_RETURN);
	
	 if (Input::GetVKey(VK_UP) == true)//カーソルの移動
	 {
		 m_y -= 6.0f;
	 }
	 else if (Input::GetVKey(VK_DOWN) == true)
	 {
		 m_y += 6.0f;
	 }

	 if (m_y < 349)//カーソル制限
	 {
		 m_y = 349;
	 }
	 if (m_y > 450)
	 {
		 m_y = 450;
	 }
	 

	 //カーソルの位置とプッシュする場所で当たり判定
	 if (m_x > 200 && m_x < 550 && m_y>330 && m_y < 360)
	 {
		
		 //エンターキーが押されたらメインに還移
		 if (m_key_enter == true)
		 {
			 Audio::Start(1);
			 Sleep(300);
		    ((UserData*)Save::GetData())->mStage=0;
			Save::Seve();
			 Scene::SetScene(new CSceneChinaEvent());
		 }
	 }

	 //ロード
	 if (m_x > 200 && m_x < 550 && m_y>370 && m_y < 430)
	 {
		 //エンターキーが押されたらロードに還移
		 if (m_key_enter == true)
		 {
			 Save::Open();
			 if (((UserData*)Save::GetData())->mStage == 0)//拠点ニューゲーム
			 {
				 Audio::Start(1);
				 Sleep(300);
				 Scene::SetScene(new CSceneChinaEvent());
			 }
			 if (((UserData*)Save::GetData())->mStage == 1)//チャイナタウン
			 {
				 Audio::Start(1);
				 Sleep(300);
				 Scene::SetScene(new CSceneChinaTown());
			 }
			 if (((UserData*)Save::GetData())->mStage == 2)//病院1階
			 {
				 Audio::Start(1);
				 Sleep(300);
				 Scene::SetScene(new CSceneHospital());
			 }
			 if (((UserData*)Save::GetData())->mStage == 3)//製薬会社一階
			 {
				 Audio::Start(1);
				 Sleep(300);
				 Scene::SetScene(new CSceneDrugCampany());
			 }
			 if (((UserData*)Save::GetData())->mStage == 8)//研究所
			 {
				 Audio::Start(1);
				 Sleep(300);
				 Scene::SetScene(new CSceneInstitute());
			 }
		 }
	 }

	 if (m_x > 200 && m_x < 550 && m_y>440 && m_y < 470)
	 {
		 //エンターキーが押されたらシャットダウンに還移
		 if (m_key_enter == true)
		 {
			 Audio::Start(1);
			 Sleep(300);
			 Scene::SetScene(nullptr);
		 }
	 }

	 if (color_flag == true)
	 {
		 m_color -= 0.02f;

		 if (m_color < 0.4f)
		 {
			 color_flag = false;
		 }
	 }
	 if (color_flag == false)
	 {
		 m_color += 0.02f;

		 if (m_color > 1.0f)
		 {
			 color_flag = true;
		 }
	 }
}

//ドロー
void CObjTitle::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };
	float ca[4] = { 1.0f,1.0f,1.0f,m_color, };
	RECT_F src;
	RECT_F dst;

	//タイトル名の表示
	Font::StrDraw(L"ARTIFICIAL HUMAN ", 270, 100, 32, c);
	Font::StrDraw(L" 〜無人世界の旅〜", 250, 150, 32, c);

	//カーソル選択位置
	//mainに移行
	Font::StrDraw(L"◆  ニューゲーム", 250, 350, 32, c);

	////ロード画面に移行
	Font::StrDraw(L"◆     ロード    ", 250, 400, 32, c);
	
	//設定画面に移行
	Font::StrDraw(L"◆ シャットダウン", 250, 450, 32, c);
	//

	Font::StrDraw(L"★↑or↓キーでカーソル移動 ", 550, 570, 18, c);

	//切り取り位置の設定
	src.m_top = 0.0f;   //y
	src.m_left = 0.0f;  //x
	src.m_right = 255.0f; //x
	src.m_bottom = 255.0f; //y

	//表示位置の設定
	dst.m_top = 0.0f+m_y;//y
	dst.m_left = 0.0f+m_x;//x
	dst.m_right = 45.0f+m_x;//x
	dst.m_bottom =45.0f+m_y; //y

	//5番目に登録したグラフィックをstc・dst・cの情報を元に描画
	Draw::Draw(5, &src, &dst, c, 0.0f);

	//切り取り位置の設定
	src.m_top = 0.0f;   //y
	src.m_left = 0.0f;  //x
	src.m_right = 128.0f; //x
	src.m_bottom = 64.0f; //y

	//表示位置の設定
	dst.m_top = 0.0f+270.0f;//y
	dst.m_left =0.0f+300.0f;//x
	dst.m_right = 128.0f +300+32.0f;//x
	dst.m_bottom = 64.0f +270.0f; //y

	//5番目に登録したグラフィックをstc・dst・cの情報を元に描画
	Draw::Draw(7, &src, &dst, ca, 0.0f);
}