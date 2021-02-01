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
	if (m_y >400)
	{
		m_y = 400;
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

	//エンターキーが押されたらシャットダウンに還移
	if (m_x > 200 && m_x < 550 && m_y>370 && m_y < 430)
	{
		if (m_key_enter == true)
		{
			Audio::Start(1);
			Sleep(300);
			Scene::SetScene(nullptr);
		}
	}

	

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
	//Font::StrDraw(L"◆     ロード    ", 250, 400, 32, c);

	//設定画面に移行
	Font::StrDraw(L"◆ シャットダウン", 250, 400, 32, c);



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