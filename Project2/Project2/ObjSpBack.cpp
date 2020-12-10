

//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameL/DrawFont.h"
#include"GameL/WinInputs.h"

#include"GameHead.h"
#include"ObjSpBack.h"
#include"UtilityModule.h"
#include<fstream>


//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjSpBack::CObjSpBack()
{
	//Heroineのヘッダーを見たらわかる
	m_sp = false;
	key_flag = 1;
	sp_flag = false;
	m_key_control = true;
	mob_flag = 0;
}


//イニシャライズ
void CObjSpBack::Init()
{

}

//アクション
void CObjSpBack::Action()
{


}

//ドロー
void CObjSpBack::Draw()
{
	////描画カラー情報　R=RED G=Green B=Blue A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);//主人公
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);//拠点
	CObjDrugCampany* drug = (CObjDrugCampany*)Objs::GetObj(OBJ_DRUG_CAMPANY);//製薬会社の一階

	CObjChinaMob* chinamob = (CObjChinaMob*)Objs::GetObj(OBJ_CHINA_MOB);//チャイナタウンのモブ
	CObjInstMob* instmob = (CObjInstMob*)Objs::GetObj(OBJ_INST_MOB);//研究所のモブ
	CObjHosMob* hosmob = (CObjHosMob*)Objs::GetObj(OBJ_HOS_MOB);//病院のモブ
	CObjDrugMob* drugmob = (CObjDrugMob*)Objs::GetObj(OBJ_DRUG_MOB);//チャイナタウンのモブ
	CObjHeroine* heroine = (CObjHeroine*)Objs::GetObj(OBJ_HEROINE);//ヒロイン

	CObjChinaTown* chinatown = (CObjChinaTown*)Objs::GetObj(OBJ_CHINA_TOWN);//チャイナタウンA
	CObjChinaTownBoss* chinatownboss = (CObjChinaTownBoss*)Objs::GetObj(OBJ_CHINA_TOWN_BOSS);//チャイナタウンボス
	CObjChinaTown_b* chinatown_b = (CObjChinaTown_b*)Objs::GetObj(OBJ_CHINA_TOWN_B);//チャイナタウンのB
	CObjChinaEvent* chinaevent = (CObjChinaEvent*)Objs::GetObj(OBJ_CHINA_EVENT);//チャイナタウンのイベント

	CObjInstitute* inst = (CObjInstitute*)Objs::GetObj(OBJ_INSTITUTE);//研究所1階
	CObjInstitute13A* inst13a = (CObjInstitute13A*)Objs::GetObj(OBJ_INSTITUTE13A);//研究所地下2階
	CObjInstituteBoss* instituteboss = (CObjInstituteBoss*)Objs::GetObj(OBJ_INSTITUTE_BOSS);//研究所BOSS

	CObjHospital* hospital = (CObjHospital*)Objs::GetObj(OBJ_HOSPITAL);//病院の一階
	CObjHospital2* hospital2 = (CObjHospital2*)Objs::GetObj(OBJ_HOSPITAL2);//病院の二階
	CObjRooftop* rooftop = (CObjRooftop*)Objs::GetObj(OBJ_ROOF_TOP);//病院の屋上


	//チャイナタウンの会話の背景
	if (chinatown != nullptr)
	{
		if (chinamob->Sp_Flag() == true)
		{
			//切り取り位置の設定
			src.m_top = 372.0f;   //y
			src.m_left = 18.0f; //x
			src.m_right = 781.0f; //x
			src.m_bottom = 581.0f; //y

			//表示位置の設定
			dst.m_top = 450.0f;
			dst.m_left = 2.0f;
			dst.m_right = 798.0f;
			dst.m_bottom = 600.0f;

			Draw::Draw(7, &src, &dst, c, 0.0f);
		}
	}
	//チャイナタウンボスの会話の背景
	if (chinatownboss != nullptr)
	{
		if (chinamob->Sp_Flag() == true)
		{
			//切り取り位置の設定
			src.m_top = 372.0f;   //y
			src.m_left = 18.0f; //x
			src.m_right = 781.0f; //x
			src.m_bottom = 581.0f; //y

			//表示位置の設定
			dst.m_top = 450.0f;
			dst.m_left = 2.0f;
			dst.m_right = 798.0f;
			dst.m_bottom = 600.0f;

			Draw::Draw(8, &src, &dst, c, 0.0f);
		}
	}
	//研究所の会話の背景
	if (inst != nullptr)
	{
		if (instmob->Sp_Flag() == true)
		{
			//切り取り位置の設定
			src.m_top = 372.0f;   //y
			src.m_left = 18.0f; //x
			src.m_right = 781.0f; //x
			src.m_bottom = 581.0f; //y

			//表示位置の設定
			dst.m_top = 450.0f;
			dst.m_left = 2.0f;
			dst.m_right = 798.0f;
			dst.m_bottom = 600.0f;

			Draw::Draw(8, &src, &dst, c, 0.0f);
		}
	}
	//研究所の会話の背景
	if (inst13a!= nullptr)
	{
		if (instmob->Sp_Flag() == true)
		{
			//切り取り位置の設定
			src.m_top = 372.0f;   //y
			src.m_left = 18.0f; //x
			src.m_right = 781.0f; //x
			src.m_bottom = 581.0f; //y

			//表示位置の設定
			dst.m_top = 450.0f;
			dst.m_left = 2.0f;
			dst.m_right = 798.0f;
			dst.m_bottom = 600.0f;

			Draw::Draw(8, &src, &dst, c, 0.0f);
		}
	}
	//製薬会社の会話の背景
	if (drug != nullptr)
	{
		if (drugmob->Sp_Flag() == true)
		{
			//切り取り位置の設定
			src.m_top = 372.0f;   //y
			src.m_left = 18.0f; //x
			src.m_right = 781.0f; //x
			src.m_bottom = 581.0f; //y

			//表示位置の設定
			dst.m_top = 450.0f;
			dst.m_left = 2.0f;
			dst.m_right = 798.0f;
			dst.m_bottom = 600.0f;

			Draw::Draw(8, &src, &dst, c, 0.0f);
		}
	}
	//病院一階の会話の背景
	if (hospital != nullptr)
	{
		if (hosmob->Sp_Flag() == true)
		{
			//切り取り位置の設定
			src.m_top = 372.0f;   //y
			src.m_left = 18.0f; //x
			src.m_right = 781.0f; //x
			src.m_bottom = 581.0f; //y

			//表示位置の設定
			dst.m_top = 450.0f;
			dst.m_left = 2.0f;
			dst.m_right = 798.0f;
			dst.m_bottom = 600.0f;

			Draw::Draw(9, &src, &dst, c, 0.0f);
		}
	}
	//病院2階の会話の背景
	if (hospital2 != nullptr)
	{
		if (hosmob->Sp_Flag() == true)
		{
			//切り取り位置の設定
			src.m_top = 372.0f;   //y
			src.m_left = 18.0f; //x
			src.m_right = 781.0f; //x
			src.m_bottom = 581.0f; //y

			//表示位置の設定
			dst.m_top = 450.0f;
			dst.m_left = 2.0f;
			dst.m_right = 798.0f;
			dst.m_bottom = 600.0f;

			Draw::Draw(8, &src, &dst, c, 0.0f);
		}
	}
	//病院屋上の会話の背景
	if (rooftop != nullptr)
	{
		if (hosmob->Sp_Flag() == true)
		{
			//切り取り位置の設定
			src.m_top = 372.0f;   //y
			src.m_left = 18.0f; //x
			src.m_right = 781.0f; //x
			src.m_bottom = 581.0f; //y

			//表示位置の設定
			dst.m_top = 450.0f;
			dst.m_left = 2.0f;
			dst.m_right = 798.0f;
			dst.m_bottom = 600.0f;

			Draw::Draw(7, &src, &dst, c, 0.0f);
		}
	}
	//拠点の会話の背景
	if (block != nullptr)
	{
		if (heroine->Sp_Flag() == true)
		{
			//切り取り位置の設定
			src.m_top = 372.0f;   //y
			src.m_left = 18.0f; //x
			src.m_right = 781.0f; //x
			src.m_bottom = 581.0f; //y

			//表示位置の設定
			dst.m_top = 450.0f;
			dst.m_left = 2.0f;
			dst.m_right = 798.0f;
			dst.m_bottom = 600.0f;

			Draw::Draw(10, &src, &dst, c, 0.0f);
		}
	}
	//チャイナタウンのイベント会話の背景
	if (chinaevent != nullptr)
	{
		if (chinaevent->Sp_Flag() == true)
		{
			//切り取り位置の設定
			src.m_top = 372.0f;   //y
			src.m_left = 18.0f; //x
			src.m_right = 781.0f; //x
			src.m_bottom = 581.0f; //y

			//表示位置の設定
			dst.m_top = 450.0f;
			dst.m_left = 2.0f;
			dst.m_right = 798.0f;
			dst.m_bottom = 600.0f;

			Draw::Draw(8, &src, &dst, c, 0.0f);
		}
	}
}

