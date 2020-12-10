//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameL/DrawFont.h"
#include"GameL/WinInputs.h"

#include"GameHead.h"
#include"ObjInstMob.h"
#include"UtilityModule.h"
#include<fstream>


//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjInstMob::CObjInstMob()
{
	//Heroineのヘッダーを見たらわかる
	m_sp = false;
	key_flag = 1;
	sp_flag = false;
	m_key_control = true;
	mob_flag = 0;
	m_save_sp = 0;
}


//イニシャライズ
void CObjInstMob::Init()
{

}

//アクション
void CObjInstMob::Action()
{
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	CObjInstitute* inst = (CObjInstitute*)Objs::GetObj(OBJ_INSTITUTE);//研究所1階
	CObjInstitute13A* inst13a = (CObjInstitute13A*)Objs::GetObj(OBJ_INSTITUTE13A);//研究所地下2階
	CObjInstituteBoss* instituteboss = (CObjInstituteBoss*)Objs::GetObj(OBJ_INSTITUTE_BOSS);//研究所BOSS


	//------------------研究所1階の会話フラグ-----------------------
	if (inst != nullptr)
	{
		if (hero->GetBT() == 73)//この数字には研究所で設定したモブの番号を
		{
			mob_flag = 1;//モブ一体目のフラグ
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

		if (inst != nullptr)
		{
			//セーブしました
			if (inst->GetSaveSp() == false)
			{
				mob_flag = 5;
				m_save_sp = 1;
				sp_flag = true;

			}
			if (inst->GetSaveSp() == true)
			{
				m_save_sp = 2;
				sp_flag = false;
			}


		}
	



	//----------地下2階の会話フラグ----------------------------------
	if (inst13a != nullptr)
	{
		if (hero->GetBT() == 70)//主人公が数字(ブロック)に触れていれば
		{
			mob_flag = 1;

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
	//---------------------------------------------------------------
	if (instituteboss != nullptr)
	{
		if (hero->GetBT() == 99)//主人公が数字(ブロック)に触れていれば
		{
			mob_flag = 1;

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
}

//ドロー
void CObjInstMob::Draw()
{
	////描画カラー情報　R=RED G=Green B=Blue A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	CObjInstitute* inst = (CObjInstitute*)Objs::GetObj(OBJ_INSTITUTE);//研究所1階
	CObjInstitute13A* inst13a = (CObjInstitute13A*)Objs::GetObj(OBJ_INSTITUTE13A);//研究所地下2階
	CObjInstituteBoss* instituteboss = (CObjInstituteBoss*)Objs::GetObj(OBJ_INSTITUTE_BOSS);//研究所BOSS

	//------触っるやつは「〇」を付けています----------------------------------------------------


	//------------地上1階の一体目----------------------------------------------------------------------------
	if (inst != nullptr && mob_flag == 1)
	{
		if (m_sp == 1)//エンターキーを一回押したとき
		{
			sp_flag == true;

			ifstream fin("研究所の会話.txt", ios::in);//テキストデータをを読み込み------------------〇
			char str1[100];//ただの配列----------文字数が多くなったら要素数を変えてよい
			wchar_t wstr1[100];
			fin.seekg(0, ios::cur);//0バイト数進める-----------〇------------------
			fin >> str1;//str1にテキストを入れる

			sprintf_s(str1, "%s", str1);//出力
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 100, wstr1, 100);//文字をユニコードに変換する
			Font::StrDraw(wstr1, 50.0f, 470, 30, c);// X  Y  大きさ     ---------------〇-------------------


			key_flag = 2;
			fin.close();//ファイルを閉じる
		}
		if (m_sp == 1)//エンターキーを一回押したとき
		{
			sp_flag == true;

			ifstream fin("研究所の会話.txt", ios::in);//テキストデータをを読み込み
			char str1[64];//ただの配列
			wchar_t wstr1[64];
			fin.seekg(50, ios::cur);//0バイト数進める
			fin >> str1;//str1にテキストを入れる

			sprintf_s(str1, "%s", str1);//出力
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//文字をユニコードに変換する
			Font::StrDraw(wstr1, 250.0f, 500, 30, c);// X  Y  大きさ     


			key_flag = 2;
			fin.close();//ファイルを閉じる
		}
		if (m_sp == 2)//エンターキーを一回押したとき
		{
			sp_flag == true;

			ifstream fin("研究所の会話.txt", ios::in);//テキストデータをを読み込み
			char str1[64];//ただの配列
			wchar_t wstr1[64];
			fin.seekg(70, ios::cur);//0バイト数進める
			fin >> str1;//str1にテキストを入れる

			sprintf_s(str1, "%s", str1);//出力
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//文字をユニコードに変換する
			Font::StrDraw(wstr1, 50.0f, 470, 30, c);// X  Y  大きさ     


			key_flag = 3;
			fin.close();//ファイルを閉じる
		}
		if (m_sp == 3)
		{
			sp_flag = false;
			Font::StrDraw(L"", 200.0f, 530, 25, c);// X  Y  大きさ    
			key_flag = 1;
		}
	}

	if (inst != nullptr) {
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

	//----------------2体目の会話-----------------------------------------------------------------------
	//if (inst != nullptr && mob_flag == 2)
	//{
	//	if (m_sp == 1)//エンターキーを一回押したとき
	//	{
	//		sp_flag == true;

	//		ifstream fin("研究所の会話.txt", ios::in);//テキストデータをを読み込み
	//		char str1[64];//ただの配列
	//		wchar_t wstr1[64];
	//		fin.seekg(162, ios::cur);//0バイト数進める
	//		fin >> str1;//str1にテキストを入れる

	//		sprintf_s(str1, "%s", str1);//出力
	//		MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//文字をユニコードに変換する
	//		Font::StrDraw(wstr1, 50.0f, 500, 25, c);// X  Y  大きさ     


	//		key_flag = 2;
	//		fin.close();//ファイルを閉じる
	//	}
	//	if (m_sp == 2)//エンターキーを一回押したとき
	//	{
	//		sp_flag == true;

	//		ifstream fin("研究所の会話.txt", ios::in);//テキストデータをを読み込み
	//		char str1[64];//ただの配列
	//		wchar_t wstr1[64];
	//		fin.seekg(222, ios::cur);//0バイト数進める
	//		fin >> str1;//str1にテキストを入れる

	//		sprintf_s(str1, "%s", str1);//出力
	//		MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//文字をユニコードに変換する
	//		Font::StrDraw(wstr1, 50.0f, 500, 25, c);// X  Y  大きさ     


	//		key_flag = 3;
	//		fin.close();//ファイルを閉じる
	//	}
	//	if (m_sp == 3)//エンターキーを一回押したとき
	//	{
	//		sp_flag == true;

	//		ifstream fin("研究所の会話.txt", ios::in);//テキストデータをを読み込み
	//		char str1[100];//ただの配列
	//		wchar_t wstr1[100];
	//		fin.seekg(260, ios::cur);//0バイト数進める
	//		fin >> str1;//str1にテキストを入れる

	//		sprintf_s(str1, "%s", str1);//出力
	//		MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 100, wstr1, 100);//文字をユニコードに変換する
	//		Font::StrDraw(wstr1, 40.0f, 500, 22, c);// X  Y  大きさ     


	//		key_flag = 4;
	//		fin.close();//ファイルを閉じる
	//	}
	//	if (m_sp == 4)
	//	{
	//		Font::StrDraw(L"", 200.0f, 530, 25, c);// X  Y  大きさ    
	//		key_flag = 1;
	//	}
	//}

	//------地下2階--------------------------------------------------------------------------------------------------
	if (inst13a != nullptr && mob_flag == 1)
	{
		if (m_sp == 1)//エンターキーを一回押したとき
		{
			sp_flag == true;

			ifstream fin("研究所の会話.txt", ios::in);//テキストデータをを読み込み
			char str1[64];//ただの配列
			wchar_t wstr1[64];
			fin.seekg(118, ios::cur);//0バイト数進める
			fin >> str1;//str1にテキストを入れる

			sprintf_s(str1, "%s", str1);//出力
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//文字をユニコードに変換する
			Font::StrDraw(wstr1, 40.0f, 500, 30, c);// X  Y  大きさ     


			key_flag = 2;
			fin.close();//ファイルを閉じる
		}
		if (m_sp == 2)//エンターキーを一回押したとき
		{
			sp_flag == true;

			ifstream fin("研究所の会話.txt", ios::in);//テキストデータをを読み込み
			char str1[64];//ただの配列
			wchar_t wstr1[64];
			fin.seekg(170, ios::cur);//0バイト数進める
			fin >> str1;//str1にテキストを入れる

			sprintf_s(str1, "%s", str1);//出力
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//文字をユニコードに変換する
			Font::StrDraw(wstr1, 50.0f, 500, 30, c);// X  Y  大きさ     


			key_flag = 3;
			fin.close();//ファイルを閉じる
		}
	
		if (m_sp == 3)//エンターキーを一回押したとき
		{
			sp_flag = false;
			Font::StrDraw(L"", 50.0f, 500, 25, c);// X  Y  大きさ     

			key_flag = 1;
		}
	}
	//----------------------------------------------------------------------------------------
	if (instituteboss != nullptr && mob_flag == 1)
	{
		if (m_sp == 1)//エンターキーを一回押したとき
		{
			sp_flag == true;

			ifstream fin("研究所ボス戦フィールドの会話.txt", ios::in);//テキストデータをを読み込み
			char str1[64];//ただの配列
			wchar_t wstr1[64];
			fin.seekg(0, ios::cur);//0バイト数進める
			fin >> str1;//str1にテキストを入れる

			sprintf_s(str1, "%s", str1);//出力
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//文字をユニコードに変換する
			Font::StrDraw(wstr1, 40.0f, 500, 30, c);// X  Y  大きさ     


			key_flag = 2;
			fin.close();//ファイルを閉じる
		}

		if (m_sp == 2)//エンターキーを一回押したとき
		{
			sp_flag = false;
			Font::StrDraw(L"", 50.0f, 500, 25, c);// X  Y  大きさ     

			key_flag = 1;
		}
	}
}