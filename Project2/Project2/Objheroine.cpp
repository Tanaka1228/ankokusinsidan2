//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameL/DrawFont.h"
#include"GameL/WinInputs.h"
#include"GameL/Audio.h"

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

	//　選択　音楽情報の読み込み
	Audio::LoadAudio(2, L"会話.wav", EFFECT);//単発
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
					Audio::Start(2);
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

		if (m_sp == 0)//キャラクターが移動したらここにクル
		{
			sp_flag = false;//背景
			key_flag = 1;//会話の順番
		}
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
			Font::StrDraw(wstr1, 30.0f, 500, 25, c);// X  Y  大きさ     


			key_flag = 2;
			fin.close();//ファイルを閉じる
		}
		if (m_sp == 2)
		{
			sp_flag == true;

			ifstream fin("会話.txt", ios::in);
			char str1[64];//本体
			wchar_t wstr1[64];
			fin.seekg(20, ios::cur);
			fin >> str1;

			sprintf_s(str1, "%s", str1);
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);
			Font::StrDraw(wstr1, 30.0f, 500, 25, c);// X  Y  大きさ 


			key_flag = 2;
			fin.close();
		}
		if (m_sp == 2)
		{
			sp_flag == true;

			ifstream fin("会話.txt", ios::in);
			char str3[64];//本体
			wchar_t wstr3[64];
			fin.seekg(76, ios::cur);
			fin >> str3;
			sprintf_s(str3, "%s", str3);
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str3, 64, wstr3, 64);
			Font::StrDraw(wstr3, 170.0f, 530, 25, c);// X  Y  大きさ

			key_flag = 3;
			fin.close();
		}
		if (m_sp == 3)
		{
			sp_flag == true;

			ifstream fin("会話.txt", ios::in);
			char str3[64];//本体
			wchar_t wstr3[64];
			fin.seekg(110, ios::cur);
			fin >> str3;
			sprintf_s(str3, "%s", str3);
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str3, 64, wstr3, 64);
			Font::StrDraw(wstr3, 30.0f,500, 25, c);// X  Y  大きさ

			key_flag = 3;
			fin.close();
		}

		if (m_sp == 3)
		{
			sp_flag == true;
			ifstream fin("会話.txt", ios::in);
			char str3[64];//本体
			wchar_t wstr3[64];
			fin.seekg(172, ios::cur);
			fin >> str3;
			sprintf_s(str3, "%s", str3);
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str3, 64, wstr3, 64);
			Font::StrDraw(wstr3, 170.0f, 530, 25, c);// X  Y  大きさ

			key_flag = 4;
			fin.close();
		}
		if (m_sp == 4)
		{
			sp_flag == true;
			ifstream fin("会話.txt", ios::in);
			char str3[64];//本体
			wchar_t wstr3[64];
			fin.seekg(218, ios::cur);
			fin >> str3;
			sprintf_s(str3, "%s", str3);
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str3, 64, wstr3, 64);
			Font::StrDraw(wstr3, 30.0f,500, 25, c);// X  Y  大きさ

			key_flag = 5;
			fin.close();
		}
		if (m_sp == 4)
		{
			sp_flag == true;
			ifstream fin("会話.txt", ios::in);
			char str3[64];//本体
			wchar_t wstr3[64];
			fin.seekg(266, ios::cur);
			fin >> str3;
			sprintf_s(str3, "%s", str3);
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str3, 64, wstr3, 64);
			Font::StrDraw(wstr3, 30.0f, 530, 25, c);// X  Y  大きさ

			key_flag = 5;
			fin.close();
		}
		if (m_sp == 5)
		{
			sp_flag == false;
			key_flag = 1;
		}
	}


}
