// 使用するヘッダ―ファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"
#include"GameL/Audio.h"
#include"GameL/UserData.h"

#include"GameHead.h"
#include"ObjGameOver.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjGameOver::Init()
{
	 m_key_flag=false;//キーフラグ

	 m_y = 345;
	 m_x = 240;
	 m_key_uy = 0.0f;
	 m_key_dy = 0.0f;
	 m_key_enter = false;
}

//アクション
void CObjGameOver::Action()
{ 
	
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

		//エンターキーが押されたらタイトルに還移
		if (m_key_enter == true)
		{
			Audio::Start(1);
			Sleep(300);
			Scene::SetScene(new CSceneTitle());
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


	//エンターキーを押してシーン：ゲームTitleに移行する
	/*if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneTitle());
			m_key_flag = false;
		}
		
	}
	else
	{
		m_key_flag = true;
	}*/
}

//ドロー
void CObjGameOver::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };
	RECT_F src;
	RECT_F dst;

	Font::StrDraw(L"GAME OVER",340,250,32,c);

	//mainに移行
	Font::StrDraw(L"◆    タイトル ", 250, 350, 32, c);

	////ロード画面に移行
	Font::StrDraw(L"◆     ロード    ", 250, 400, 32, c);

	//設定画面に移行
	Font::StrDraw(L"◆ シャットダウン", 250, 450, 32, c);



	//切り取り位置の設定
	src.m_top = 0.0f;   //y
	src.m_left = 0.0f;  //x
	src.m_right = 32.0f; //x
	src.m_bottom = 32.0f; //y

	//表示位置の設定
	dst.m_top = 0.0f + m_y;//y
	dst.m_left = 7.0f + m_x;//x
	dst.m_right = 52.0f + m_x;//x
	dst.m_bottom = 45.0f + m_y; //y

	//5番目に登録したグラフィックをstc・dst・cの情報を元に描画
	Draw::Draw(5, &src, &dst, c, 0.0f);
}