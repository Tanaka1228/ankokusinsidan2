

//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameL/DrawFont.h"
#include"GameL/WinInputs.h"

#include"GameHead.h"
#include"ObjChinaEvent.h"
#include"UtilityModule.h"
#include<fstream>


//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjChinaEvent::CObjChinaEvent()
{
	//Heroineのヘッダーを見たらわかる
	m_sp = false;
	key_flag = 1;
	sp_flag = false;
	m_key_control = true;
	mob_flag = 0;
	m_time = 0;
}


//イニシャライズ
void CObjChinaEvent::Init()
{

}

//アクション
void CObjChinaEvent::Action()
{
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	//チャイナタウンのイベント情報
	CObjChinaEvent* chinaevent = (CObjChinaEvent*)Objs::GetObj(OBJ_CHINA_EVENT);

	int minute;//分
	int second;//秒

	m_time++;

	second = (m_time / 60) % 60;//秒
	minute = (m_time / 60) / 60;//分

	//-------------チャイナタウンのイベント------------------
	if (chinaevent!= nullptr)
	{
		if (second == 1)//秒たつと
		{

			if (key_flag == 1)
			{
				m_sp = 1;
				sp_flag = true;

			}
		}
		if (second == 3)//秒たつと
		{

			if (key_flag == 2)
			{
				m_sp = 2;
				sp_flag = true;

			}
		}
		if (second == 5)//秒たつと
		{
			if ((key_flag == 3))
			{

				m_sp = 3;
				sp_flag = true;

			}
		}
		if (second == 7)//秒たつと
		{
			if ((key_flag == 4))
			{
				m_sp = 4;
				sp_flag = true;

			}
		}
		if (second == 9)//秒たつと
		{
			if ((key_flag == 5))
			{
				m_sp = 5;
				sp_flag = true;

			}
		}
		if (second == 11)//秒たつと
		{
			if ((key_flag == 6))
			{
				m_sp = 6;
				sp_flag = true;

			}
		}
		if (second == 14)//秒たつと
		{
			if ((key_flag == 7))
			{
				m_sp = 7;
				sp_flag = true;

			}
		}
	}
	//------------------------------------------------------




}

//ドロー
void CObjChinaEvent::Draw()
{
	////描画カラー情報　R=RED G=Green B=Blue A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	CObjChinaEvent* chinaevent = (CObjChinaEvent*)Objs::GetObj(OBJ_CHINA_EVENT);

	if (chinaevent != nullptr)
	{
		if (m_sp == 1)//エンターキーを一回押したとき
		{
			sp_flag == true;

			ifstream fin("チャイナタウンイベント.txt", ios::in);//テキストデータをを読み込み
			char str1[64];//ただの配列
			wchar_t wstr1[64];
			fin.seekg(0, ios::cur);//0バイト数進める
			fin >> str1;//str1にテキストを入れる

			sprintf_s(str1, "%s", str1);//出力
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//文字をユニコードに変換する
			Font::StrDraw(wstr1, 20.0f, 510, 30, c);// X  Y  大きさ     


			key_flag = 2;
			fin.close();//ファイルを閉じる
		}
		if (m_sp == 2)//エンターキーを2回押したとき
		{
			sp_flag == true;

			ifstream fin("チャイナタウンイベント.txt", ios::in);//テキストデータをを読み込み
			char str1[64];//ただの配列
			wchar_t wstr1[64];
			fin.seekg(24, ios::cur);//0バイト数進める
			fin >> str1;//str1にテキストを入れる

			sprintf_s(str1, "%s", str1);//出力
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//文字をユニコードに変換する
			Font::StrDraw(wstr1, 20.0f, 510, 30, c);// X  Y  大きさ     


			key_flag = 3;
			fin.close();//ファイルを閉じる
		}
		if (m_sp == 3)//エンターキーを3回押したとき
		{
			sp_flag == true;

			ifstream fin("チャイナタウンイベント.txt", ios::in);//テキストデータをを読み込み
			char str1[64];//ただの配列
			wchar_t wstr1[64];
			fin.seekg(46, ios::cur);//0バイト数進める
			fin >> str1;//str1にテキストを入れる

			sprintf_s(str1, "%s", str1);//出力
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//文字をユニコードに変換する
			Font::StrDraw(wstr1, 20.0f, 510, 30, c);// X  Y  大きさ     


			key_flag = 4;
			fin.close();//ファイルを閉じる
		}
		if (m_sp ==4)//エンターキーを3回押したとき
		{
			sp_flag == true;

			ifstream fin("チャイナタウンイベント.txt", ios::in);//テキストデータをを読み込み
			char str1[64];//ただの配列
			wchar_t wstr1[64];
			fin.seekg(80, ios::cur);//0バイト数進める
			fin >> str1;//str1にテキストを入れる

			sprintf_s(str1, "%s", str1);//出力
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//文字をユニコードに変換する
			Font::StrDraw(wstr1, 20.0f, 510, 30, c);// X  Y  大きさ     


			key_flag = 5;
			fin.close();//ファイルを閉じる
		}
		if (m_sp == 5)//エンターキーを3回押したとき
		{
			sp_flag == true;

			ifstream fin("チャイナタウンイベント.txt", ios::in);//テキストデータをを読み込み
			char str1[64];//ただの配列
			wchar_t wstr1[64];
			fin.seekg(130, ios::cur);//0バイト数進める
			fin >> str1;//str1にテキストを入れる

			sprintf_s(str1, "%s", str1);//出力
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//文字をユニコードに変換する
			Font::StrDraw(wstr1, 20.0f, 510, 28, c);// X  Y  大きさ     


			key_flag = 6;
			fin.close();//ファイルを閉じる
		}
	    if (m_sp == 6)//エンターキーを3回押したとき
	    {
	    	sp_flag == true;
	    
	    	ifstream fin("チャイナタウンイベント.txt", ios::in);//テキストデータをを読み込み
	    	char str1[64];//ただの配列
	    	wchar_t wstr1[64];
	    	fin.seekg(188, ios::cur);//0バイト数進める
	    	fin >> str1;//str1にテキストを入れる
	    
	    	sprintf_s(str1, "%s", str1);//出力
	    	MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//文字をユニコードに変換する
	    	Font::StrDraw(wstr1, 20.0f, 510, 30, c);// X  Y  大きさ     
	    
	    
	    	key_flag = 7;
	    	fin.close();//ファイルを閉じる
	    }
	    if (m_sp == 7)
	    {
	    	sp_flag = false;
	    	Scene::SetScene(new CSceneChinaTown());//チャイナタウンにシーン切り替え
	    }
	}
	
}

