

//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameL/DrawFont.h"
#include"GameL/WinInputs.h"

#include"GameHead.h"
#include"ObjDrugMob.h"
#include"UtilityModule.h"
#include<fstream>


//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjDrugMob::CObjDrugMob()
{
	//Heroineのヘッダーを見たらわかる
	m_sp = false;
	key_flag = 1;
	sp_flag = false;
	m_key_control = true;
	mob_flag = 0;
}


//イニシャライズ
void CObjDrugMob::Init()
{

}

//アクション
void CObjDrugMob::Action()
{
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	CObjDrugCampany* drug = (CObjDrugCampany*)Objs::GetObj(OBJ_DRUG_CAMPANY);//製薬会社の一階
	

	if (drug != nullptr)
	{
		if (hero->GetBT() == 10)
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

//ドロー
void CObjDrugMob::Draw()
{
	////描画カラー情報　R=RED G=Green B=Blue A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	CObjDrugCampany* drug = (CObjDrugCampany*)Objs::GetObj(OBJ_DRUG_CAMPANY);//製薬会社の一階

	if (drug != nullptr && mob_flag == 1)
	{
		if (m_sp == 1)//エンターキーを一回押したとき
		{
			sp_flag == true;

			ifstream fin("製薬会社の会話.txt", ios::in);//テキストデータをを読み込み
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
	
		if (m_sp == 2)
		{
			sp_flag = false;
			Font::StrDraw(L"", 200.0f, 530, 25, c);// X  Y  大きさ    
			key_flag = 1;
		}
	}
	
}

