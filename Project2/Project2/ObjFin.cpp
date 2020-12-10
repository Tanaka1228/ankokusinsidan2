//使用するヘッダ―ファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"
#include"GameL\DrawFont.h"

#include"GameHead.h"
#include"ObjFin.h"
#include"SceneTitle.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjFin::Init()
{
	 m_key_flag = false;//キーフラグ
}

//アクション
void CObjFin::Action()
{
	//エンターキーを押してシーン：ゲームTitleに移行する
	if (Input::GetVKey(VK_RETURN) == true)
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
	}
}


//ドロー
void CObjFin::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };
	RECT_F src;
	RECT_F dst;

	//タイトル名の表示
	Font::StrDraw(L"ｆｉｎ", 350, 250, 32, c);
	Font::StrDraw(L"by 暗黒紳士団", 590, 550, 32, c);


	
}