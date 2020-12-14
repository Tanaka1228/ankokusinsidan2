//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameL/DrawFont.h"
#include"GameL/WinInputs.h"
#include"GameL/UserData.h"
#include"GameL/Audio.h"

#include"GameHead.h"
#include"ObjChinaMob.h"
#include"UtilityModule.h"
#include<fstream>


//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjChinaMob::CObjChinaMob()
{
	//Heroineのヘッダーを見たらわかる
	m_sp = 0;
	m_sp2 = 0;
	key_flag = 1;
	sp_flag = false;
	m_key_control = true;
	m_time = 0;
	mob_flag = 0;
	m_save_sp = 0;

	Save_sp=true;

	//　選択　音楽情報の読み込み
	Audio::LoadAudio(2, L"会話.wav", EFFECT);//単発
}


//イニシャライズ
void CObjChinaMob::Init()
{

}

//アクション
void CObjChinaMob::Action()
{
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	CObjChinaTown* chinatown = (CObjChinaTown*)Objs::GetObj(OBJ_CHINA_TOWN);//チャイナタウン
	CObjChinaTownBoss* chinatownboss = (CObjChinaTownBoss*)Objs::GetObj(OBJ_CHINA_TOWN_BOSS);//チャイナタウンボス
	CObjChinaTown_b* chinatown_b = (CObjChinaTown_b*)Objs::GetObj(OBJ_CHINA_TOWN_B);//チャイナタウンのB

	
	//チャイナタウンのモブ
	if (chinatown != nullptr)
	{
		if (hero->GetBT() == 34)//車
		{
			mob_flag = 1;
			if (Input::GetVKey(VK_RETURN) == true)
			{

				if (m_key_control == true)
				{
					Audio::Start(2);
					if ((key_flag == 1))
					{
						m_sp2 = 1;
						sp_flag = true;
					}

					if ((key_flag == 2))
					{
						m_sp2 = 2;
						sp_flag = true;
					}
					if ((key_flag == 3))
					{

						m_sp2 = 3;
						sp_flag = true;
					}
					if ((key_flag == 4))
					{
						m_sp2 = 4;
						sp_flag = true;
					}
					if ((key_flag == 5))
					{
						m_sp2 = 5;
						sp_flag = true;
					}
					if ((key_flag == 6))
					{
						m_sp2 = 6;
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


		if (hero->GetBT() == 99)
		{
			mob_flag = 4;
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
						sp_flag = true;
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

		if (hero->GetBT() == 100)
		{
			mob_flag = 2;
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
						sp_flag = true;
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

	if (chinatown != nullptr)
	{
	
		if (hero->GetBT() == 83)
		{
			mob_flag = 5;

			if (Input::GetVKey(VK_RETURN) == true)
			{
			
				if (Save_sp == true)
				{
					Audio::Start(2);
					((UserData*)Save::GetData())->mStage = 1;
					Save::Seve();
					Save_sp = false;
					m_save_sp = 1;
					sp_flag = true;
				}
			}
			else
			{
				Save_sp = true;
				m_save_sp = 2;

			}
		}
		
	}

	//ケビン
	if (chinatownboss != nullptr)
	{
		if (hero->GetBT() == 99)
		{
			mob_flag = 1;
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
						sp_flag = true;
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

		//マイケル
		if (hero->GetBT() == 100)
		{
			mob_flag = 2;
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
						sp_flag = true;
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

		//トーマス
		if (hero->GetBT() == 101)
		{
			mob_flag = 3;
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
						sp_flag = true;
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

	
		//チャイナタウンのB
		if (chinatown_b != nullptr)
		{
			if (hero->GetBT() == 97)
			{
				mob_flag == 1;
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
							sp_flag = true;
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
void CObjChinaMob::Draw()
{
	////描画カラー情報　R=RED G=Green B=Blue A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	CObjChinaTown* chinatown = (CObjChinaTown*)Objs::GetObj(OBJ_CHINA_TOWN);
	CObjChinaTownBoss* chinatownboss = (CObjChinaTownBoss*)Objs::GetObj(OBJ_CHINA_TOWN_BOSS);
	CObjChinaTown_b* chinatown_b = (CObjChinaTown_b*)Objs::GetObj(OBJ_CHINA_TOWN_B);//チャイナタウンのB

	if (chinatown != nullptr && mob_flag == 1)//車
	{
		if (m_sp2 == 1 && mob_flag == 1)//エンターキーを一回押したとき
		{
			sp_flag == true;

			ifstream fin("チャイナタウン会話.txt", ios::in);//テキストデータをを読み込み
			char str1[64];//ただの配列
			wchar_t wstr1[64];
			fin.seekg(100, ios::cur);//0バイト数進める
			fin >> str1;//str1にテキストを入れる

			sprintf_s(str1, "%s", str1);//出力
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//文字をユニコードに変換する
			Font::StrDraw(wstr1, 50.0f, 500, 30, c);// X  Y  大きさ     


			key_flag = 2;
			fin.close();//ファイルを閉じる
		}
		if (m_sp2 == 2 && mob_flag == 1)//エンターキーを2回押したとき
		{
			sp_flag == true;

			ifstream fin("チャイナタウン会話.txt", ios::in);//テキストデータをを読み込み
			char str1[64];//ただの配列
			wchar_t wstr1[64];
			fin.seekg(114, ios::cur);//0バイト数進める
			fin >> str1;//str1にテキストを入れる

			sprintf_s(str1, "%s", str1);//出力
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//文字をユニコードに変換する
			Font::StrDraw(wstr1, 50.0f, 500, 25, c);// X  Y  大きさ     


			key_flag = 3;
			fin.close();//ファイルを閉じる
		}
		if (m_sp2 == 3 && mob_flag == 1)//エンターキーを2回押したとき
		{
			sp_flag == true;

			ifstream fin("チャイナタウン会話.txt", ios::in);//テキストデータをを読み込み
			char str1[64];//ただの配列
			wchar_t wstr1[64];
			fin.seekg(146, ios::cur);//0バイト数進める
			fin >> str1;//str1にテキストを入れる

			sprintf_s(str1, "%s", str1);//出力
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//文字をユニコードに変換する
			Font::StrDraw(wstr1, 50.0f, 500, 25, c);// X  Y  大きさ     


			key_flag = 4;
			fin.close();//ファイルを閉じる
		}
		if (m_sp2 == 4 && mob_flag == 1)//エンターキーを2回押したとき
		{
			sp_flag == true;

			ifstream fin("チャイナタウン会話.txt", ios::in);//テキストデータをを読み込み
			char str1[64];//ただの配列
			wchar_t wstr1[64];
			fin.seekg(164, ios::cur);//0バイト数進める
			fin >> str1;//str1にテキストを入れる

			sprintf_s(str1, "%s", str1);//出力
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//文字をユニコードに変換する
			Font::StrDraw(wstr1, 50.0f, 480, 25, c);// X  Y  大きさ     


			key_flag = 5;
			fin.close();//ファイルを閉じる
		}
		if (m_sp2 == 4 && mob_flag == 1)//エンターキーを2回押したとき
		{
			sp_flag == true;

			ifstream fin("チャイナタウン会話.txt", ios::in);//テキストデータをを読み込み
			char str1[64];//ただの配列
			wchar_t wstr1[64];
			fin.seekg(200, ios::cur);//0バイト数進める
			fin >> str1;//str1にテキストを入れる

			sprintf_s(str1, "%s", str1);//出力
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//文字をユニコードに変換する
			Font::StrDraw(wstr1, 110.0f, 510, 25, c);// X  Y  大きさ     


			key_flag = 5;
			fin.close();//ファイルを閉じる
		}
		if (m_sp2 == 5 && mob_flag == 1)//エンターキーを3回押したとき
		{
			sp_flag = false;

			//Font::StrDraw(L"", 50.0f, 500, 25, c);// X  Y  大きさ     

			key_flag = 1;
		}
	}
	if (chinatown != nullptr && mob_flag == 4)
	{
		if (m_sp == 1&&mob_flag==4)//エンターキーを一回押したとき
		{
			sp_flag == true;

			ifstream fin("チャイナタウン会話.txt", ios::in);//テキストデータをを読み込み
			char str1[64];//ただの配列
			wchar_t wstr1[64];
			fin.seekg(0, ios::cur);//0バイト数進める
			fin >> str1;//str1にテキストを入れる

			sprintf_s(str1, "%s", str1);//出力
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//文字をユニコードに変換する
			Font::StrDraw(wstr1, 50.0f, 500, 30, c);// X  Y  大きさ     


			key_flag = 2;
			fin.close();//ファイルを閉じる
		}
		if (m_sp == 2 && mob_flag == 4)//エンターキーを2回押したとき
		{
			sp_flag == true;

			ifstream fin("チャイナタウン会話.txt", ios::in);//テキストデータをを読み込み
			char str1[64];//ただの配列
			wchar_t wstr1[64];
			fin.seekg(46, ios::cur);//0バイト数進める
			fin >> str1;//str1にテキストを入れる

			sprintf_s(str1, "%s", str1);//出力
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//文字をユニコードに変換する
			Font::StrDraw(wstr1, 50.0f, 500, 25, c);// X  Y  大きさ     


			key_flag = 3;
			fin.close();//ファイルを閉じる
		}
		if (m_sp == 3 && mob_flag == 4)//エンターキーを3回押したとき
		{
			sp_flag = false;

			//Font::StrDraw(L"", 50.0f, 500, 25, c);// X  Y  大きさ     

			key_flag = 1;
		}
	}

	//モブ2体目
	if (chinatown != nullptr && mob_flag == 2)
	{
		if (m_sp == 1 && mob_flag == 2)//エンターキーを一回押したとき
		{
			sp_flag == true;

			ifstream fin("チャイナタウン会話.txt", ios::in);//テキストデータをを読み込み
			char str1[64];//ただの配列
			wchar_t wstr1[64];
			fin.seekg(222, ios::cur);//0バイト数進める
			fin >> str1;//str1にテキストを入れる

			sprintf_s(str1, "%s", str1);//出力
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//文字をユニコードに変換する
			Font::StrDraw(wstr1, 50.0f, 500, 30, c);// X  Y  大きさ     


			key_flag = 2;
			fin.close();//ファイルを閉じる
		}
		if (m_sp == 2 && mob_flag == 2)//エンターキーを2回押したとき
		{
			sp_flag == true;

			ifstream fin("チャイナタウン会話.txt", ios::in);//テキストデータをを読み込み
			char str1[64];//ただの配列
			wchar_t wstr1[64];
			fin.seekg(246, ios::cur);//0バイト数進める
			fin >> str1;//str1にテキストを入れる

			sprintf_s(str1, "%s", str1);//出力
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//文字をユニコードに変換する
			Font::StrDraw(wstr1, 50.0f, 500, 25, c);// X  Y  大きさ     


			key_flag = 3;
			fin.close();//ファイルを閉じる
		}
		if (m_sp == 3 && mob_flag == 2)//エンターキーを3回押したとき
		{
			sp_flag = false;

			//Font::StrDraw(L"", 50.0f, 500, 25, c);// X  Y  大きさ     

			key_flag = 1;
		}
	}

	


	if (chinatown != nullptr) 
	{
		if (m_save_sp == 1 && mob_flag == 5)
		{
			sp_flag = true;
			Font::StrDraw(L"セーブしました", 100.0f, 490, 40, c);// X  Y  大きさ     
		}
		if (m_save_sp == 2 && mob_flag == 5)
		{
			sp_flag = false;
		}
	}


	//ケビン
	if (chinatownboss != nullptr && mob_flag == 1)
	{


		if (m_sp == 1)//エンターキーを一回押したとき
		{
			sp_flag == true;

				ifstream fin("チャイナタウンボス戦フィールドの会話.txt", ios::in);//テキストデータをを読み込み
				char str1[64];//ただの配列
				wchar_t wstr1[64];
				fin.seekg(0, ios::cur);//0バイト数進める
				fin >> str1;//str1にテキストを入れる

				sprintf_s(str1, "%s", str1);//出力
				MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//文字をユニコードに変換する
				Font::StrDraw(wstr1, 50.0f, 490, 30, c);// X  Y  大きさ     


			key_flag = 2;
			fin.close();//ファイルを閉じる
		}
		if (m_sp == 2)//エンターキーを一回押したとき
		{
			sp_flag == true;

				ifstream fin("チャイナタウンボス戦フィールドの会話.txt", ios::in);//テキストデータをを読み込み
				char str1[64];//ただの配列
				wchar_t wstr1[64];
				fin.seekg(20, ios::cur);//0バイト数進める
				fin >> str1;//str1にテキストを入れる

				sprintf_s(str1, "%s", str1);//出力
				MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//文字をユニコードに変換する
				Font::StrDraw(wstr1, 50.0f, 490, 30, c);// X  Y  大きさ     


			key_flag = 3;
			fin.close();//ファイルを閉じる
		}
		if (m_sp == 2)//エンターキーを一回押したとき
		{
			sp_flag == true;

				ifstream fin("チャイナタウンボス戦フィールドの会話.txt", ios::in);//テキストデータをを読み込み
				char str1[64];//ただの配列
				wchar_t wstr1[64];
				fin.seekg(66, ios::cur);//0バイト数進める
				fin >> str1;//str1にテキストを入れる

				sprintf_s(str1, "%s", str1);//出力
				MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//文字をユニコードに変換する
				Font::StrDraw(wstr1, 50.0f, 520, 30, c);// X  Y  大きさ     


			key_flag = 3;
			fin.close();//ファイルを閉じる
		}
		if (m_sp == 3)//エンターキーを一回押したとき
		{
			sp_flag == true;

				ifstream fin("チャイナタウンボス戦フィールドの会話.txt", ios::in);//テキストデータをを読み込み
				char str1[64];//ただの配列
				wchar_t wstr1[64];
				fin.seekg(100, ios::cur);//0バイト数進める
				fin >> str1;//str1にテキストを入れる

				sprintf_s(str1, "%s", str1);//出力
				MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//文字をユニコードに変換する
				Font::StrDraw(wstr1, 50.0f, 490, 30, c);// X  Y  大きさ     


			key_flag = 4;
			fin.close();//ファイルを閉じる
		}
		if (m_sp == 4)//エンターキーを一回押したとき
		{
			sp_flag = false;
			//Font::StrDraw(L"", 50.0f, 500, 30, c);// X  Y  大きさ     


			key_flag = 1;

		}
	}

	//マイケル
	if (chinatownboss != nullptr && mob_flag == 2)
	{
		if (m_sp == 1)//エンターキーを一回押したとき
		{
			sp_flag == true;

			ifstream fin("チャイナタウンボス戦フィールドの会話.txt", ios::in);//テキストデータをを読み込み
			char str1[64];//ただの配列
			wchar_t wstr1[64];
			fin.seekg(146, ios::cur);//0バイト数進める
			fin >> str1;//str1にテキストを入れる

			sprintf_s(str1, "%s", str1);//出力
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//文字をユニコードに変換する
			Font::StrDraw(wstr1, 50.0f, 500, 30, c);// X  Y  大きさ     


			key_flag = 2;
			fin.close();//ファイルを閉じる
		}
		if (m_sp == 2)//エンターキーを一回押したとき
		{
			sp_flag == true;

			ifstream fin("チャイナタウンボス戦フィールドの会話.txt", ios::in);//テキストデータをを読み込み
			char str1[64];//ただの配列
			wchar_t wstr1[64];
			fin.seekg(194, ios::cur);//0バイト数進める
			fin >> str1;//str1にテキストを入れる

			sprintf_s(str1, "%s", str1);//出力
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//文字をユニコードに変換する
			Font::StrDraw(wstr1, 50.0f, 500, 30, c);// X  Y  大きさ     


			key_flag = 3;
			fin.close();//ファイルを閉じる
		}
		if (m_sp == 3)//エンターキーを一回押したとき
		{
			sp_flag == true;

			ifstream fin("チャイナタウンボス戦フィールドの会話.txt", ios::in);//テキストデータをを読み込み
			char str1[64];//ただの配列
			wchar_t wstr1[64];
			fin.seekg(228, ios::cur);//0バイト数進める
			fin >> str1;//str1にテキストを入れる

			sprintf_s(str1, "%s", str1);//出力
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//文字をユニコードに変換する
			Font::StrDraw(wstr1, 50.0f, 500, 30, c);// X  Y  大きさ     


			key_flag = 4;
			fin.close();//ファイルを閉じる
		}
		if (m_sp == 4)//エンターキーを一回押したとき
		{
			sp_flag = false;
			//Font::StrDraw(L"", 50.0f, 500, 30, c);// X  Y  大きさ     
			key_flag = 1;

		}

	}

	//トーマス
	if (chinatownboss != nullptr && mob_flag == 3)
	{
		if (m_sp == 1)//エンターキーを一回押したとき
		{
			sp_flag == true;

			ifstream fin("チャイナタウンボス戦フィールドの会話.txt", ios::in);//テキストデータをを読み込み
			char str1[64];//ただの配列
			wchar_t wstr1[64];
			fin.seekg(270, ios::cur);//0バイト数進める
			fin >> str1;//str1にテキストを入れる

			sprintf_s(str1, "%s", str1);//出力
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//文字をユニコードに変換する
			Font::StrDraw(wstr1, 50.0f, 500, 30, c);// X  Y  大きさ     


			key_flag = 2;
			fin.close();//ファイルを閉じる
		}
		if (m_sp == 2)//エンターキーを一回押したとき
		{
			sp_flag == true;

			ifstream fin("チャイナタウンボス戦フィールドの会話.txt", ios::in);//テキストデータをを読み込み
			char str1[64];//ただの配列
			wchar_t wstr1[64];
			fin.seekg(310, ios::cur);//0バイト数進める
			fin >> str1;//str1にテキストを入れる

			sprintf_s(str1, "%s", str1);//出力
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//文字をユニコードに変換する
			Font::StrDraw(wstr1, 50.0f, 500, 30, c);// X  Y  大きさ     


			key_flag = 3;
			fin.close();//ファイルを閉じる
		}
		if (m_sp == 3)//エンターキーを一回押したとき
		{
			sp_flag == true;

			ifstream fin("チャイナタウンボス戦フィールドの会話.txt", ios::in);//テキストデータをを読み込み
			char str1[64];//ただの配列
			wchar_t wstr1[64];
			fin.seekg(354, ios::cur);//0バイト数進める
			fin >> str1;//str1にテキストを入れる

			sprintf_s(str1, "%s", str1);//出力
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//文字をユニコードに変換する
			Font::StrDraw(wstr1, 50.0f, 500, 30, c);// X  Y  大きさ     


			key_flag = 4;
			fin.close();//ファイルを閉じる
		}
		if (m_sp == 4)//エンターキーを一回押したとき
		{
			sp_flag = false;
			//Font::StrDraw(L"", 50.0f, 500, 30, c);// X  Y  大きさ     
			key_flag = 1;

		}

	}
	
	




if (chinatown_b != nullptr && mob_flag == 1)
{
	if (m_sp == 1)//エンターキーを一回押したとき
	{
		sp_flag == true;

		ifstream fin("チャイナタウン会話.txt", ios::in);//テキストデータをを読み込み
		char str1[64];//ただの配列
		wchar_t wstr1[64];
		fin.seekg(98, ios::cur);//0バイト数進める
		fin >> str1;//str1にテキストを入れる

		sprintf_s(str1, "%s", str1);//出力
		MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//文字をユニコードに変換する
		Font::StrDraw(wstr1, 50.0f, 500, 30, c);// X  Y  大きさ     


		key_flag = 2;
		fin.close();//ファイルを閉じる
	}
	if (m_sp == 1)//エンターキーを一回押したとき
	{
		sp_flag == true;

		ifstream fin("チャイナタウン会話.txt", ios::in);//テキストデータをを読み込み
		char str1[64];//ただの配列
		wchar_t wstr1[64];
		fin.seekg(114, ios::cur);//0バイト数進める
		fin >> str1;//str1にテキストを入れる

		sprintf_s(str1, "%s", str1);//出力
		MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//文字をユニコードに変換する
		Font::StrDraw(wstr1, 50.0f, 500, 25, c);// X  Y  大きさ     


		key_flag =2;
		fin.close();//ファイルを閉じる

	}
	if (m_sp == 1)//エンターキーを一回押したとき
	{
		sp_flag == true;

		ifstream fin("チャイナタウン会話.txt", ios::in);//テキストデータをを読み込み
		char str1[64];//ただの配列
		wchar_t wstr1[64];
		fin.seekg(124, ios::cur);//0バイト数進める
		fin >> str1;//str1にテキストを入れる

		sprintf_s(str1, "%s", str1);//出力
		MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//文字をユニコードに変換する
		Font::StrDraw(wstr1, 50.0f, 500, 25, c);// X  Y  大きさ     


		key_flag = 2;
		fin.close();//ファイルを閉じる

	}
}
}

