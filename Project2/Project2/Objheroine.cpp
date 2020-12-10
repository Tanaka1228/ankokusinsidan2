//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameL/DrawFont.h"
#include"GameL/WinInputs.h"

#include"GameHead.h"
#include"ObjHeroine.h"
#include"UtilityModule.h"
#include<fstream>

 
//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjHeroine::CObjHeroine()
{
	//Heroineのヘッダーを見たらわかる
	m_sp = false;
	key_flag = 1;
	sp_flag = false;
	m_key_control = true;
}


//イニシャライズ
void CObjHeroine::Init()
{
	
}

//アクション
void CObjHeroine::Action()
{
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	if (block != nullptr)
	{
		if (hero->GetBT() == 17)
		{
			if (Input::GetVKey(VK_RETURN) == true) {

				if (m_key_control == true)
				{
					if (key_flag == 1)
					{
						m_sp = 1;
						sp_flag = true;
					}

					if (key_flag == 2)
					{
						m_sp = 2;
						sp_flag = true;
					}
					if ((key_flag == 3))
					{

						m_sp = 3;
						sp_flag = true;
					}
					if ((key_flag == 4))
					{
						m_sp = 4;
						sp_flag = true;
					}




					if ((key_flag == 5))
					{
						m_sp = 5;
						sp_flag = false;
					}
					if ((key_flag == 6))
					{
						m_sp = 6;
						sp_flag = true;
					}
					m_key_control = false;
				}

			}
			else
			{
				m_key_control = true;
			}
		}
	}
	
}

//ドロー
void CObjHeroine::Draw()
{
	////描画カラー情報　R=RED G=Green B=Blue A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);//拠点

	//setlocale(LC_ALL, "Japanese");
	
	//--------------------------テスト  
	//ifstream ifs(L"会話.txt", ios::in);
	//wchar_t str1[32];
	//ifs >> str2;
	//sprintf_s(str2,"%s\n", str2);
	//MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str2, 32, str1, 32);
	//Font::StrDraw(str1, 50.0f, 500, 25, c);// X  Y  大きさ 
	//ifs.close();
	//-----------------------------

	//二行テキストを出すときは、2行目のY軸を30上げるといい感じになる
	
	if (block != nullptr) {
		if (m_sp == 1)//エンターキーを一回押したとき
		{
			sp_flag == true;

			ifstream fin("会話.txt", ios::in);//テキストデータをを読み込み
			char str1[64];//ただの配列
			wchar_t wstr1[64];
			fin.seekg(0, ios::cur);//0バイト数進める
			fin >> str1;//str1にテキストを入れる

			sprintf_s(str1, "%s", str1);//出力
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//文字をユニコードに変換する
			Font::StrDraw(wstr1, 50.0f, 480, 25, c);// X  Y  大きさ     


			key_flag = 2;
			fin.close();//ファイルを閉じる
		}
		if (m_sp == 1)
		{
			sp_flag == true;

			ifstream fin("会話.txt", ios::in);
			char str1[64];//本体
			wchar_t wstr1[64];
			fin.seekg(48, ios::cur);
			fin >> str1;

			sprintf_s(str1, "%s", str1);
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);
			Font::StrDraw(wstr1, 50.0f, 510, 25, c);// X  Y  大きさ 


			key_flag = 2;
			fin.close();
		}

		if (m_sp == 2)
		{
			sp_flag == true;

			ifstream fin("会話.txt", ios::in);
			char str3[64];//本体
			wchar_t wstr3[64];
			fin.seekg(94, ios::cur);
			fin >> str3;
			sprintf_s(str3, "%s", str3);
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str3, 64, wstr3, 64);
			Font::StrDraw(wstr3, 40.0f, 480, 25, c);// X  Y  大きさ

			key_flag = 3;
			fin.close();
		}
		if (m_sp == 2)
		{
			sp_flag == true;

			ifstream fin("会話.txt", ios::in);
			char str3[64];//本体
			wchar_t wstr3[64];
			fin.seekg(158, ios::cur);
			fin >> str3;
			sprintf_s(str3, "%s", str3);
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str3, 64, wstr3, 64);
			Font::StrDraw(wstr3, 40.0f, 510, 25, c);// X  Y  大きさ

			key_flag = 3;
			fin.close();
		}

		if (m_sp == 3)
		{
			sp_flag == true;
			ifstream fin("会話.txt", ios::in);
			char str3[64];//本体
			wchar_t wstr3[64];
			fin.seekg(194, ios::cur);
			fin >> str3;
			sprintf_s(str3, "%s", str3);
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str3, 64, wstr3, 64);
			Font::StrDraw(wstr3, 50.0f, 480, 25, c);// X  Y  大きさ

			key_flag = 4;
			fin.close();
		}
		if (m_sp == 4)
		{
			sp_flag == true;
			ifstream fin("会話.txt", ios::in);
			char str3[64];//本体
			wchar_t wstr3[64];
			fin.seekg(239, ios::cur);
			fin >> str3;
			sprintf_s(str3, "%s", str3);
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str3, 64, wstr3, 64);
			Font::StrDraw(wstr3, 50.0f, 480, 25, c);// X  Y  大きさ

			key_flag = 5;
			fin.close();
		}
		if (m_sp == 5)
		{
			sp_flag == false;
			Font::StrDraw(L"", 100, 500, 30, c);
			key_flag = 1;

		}
	}


}

//this->SetStatus(false);//自身に削除命令
		//Font::Delete();

//
////会話グラフィック
////切り取り位置の設定
//src.m_top = 373.0f; //y
//src.m_left = 20.0f; //x
//src.m_right = 780.0f; //x
//src.m_bottom = 581.0f; //y
//
////表示位置の設定
//dst.m_top = 400.0f;
//dst.m_left = 40.0f;
//dst.m_right = 750.0f;
//dst.m_bottom = 550.0f;
//
////0番目に登録したグラフィックをstc・dst・cの情報を元に描画
//Draw::Draw(10, &src, &dst, c, 0.0f);//0.0fは角度を変えるやつ