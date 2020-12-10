//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameL/DrawFont.h"
#include"GameL/WinInputs.h"

#include"GameHead.h"
#include"ObjMap.h"
#include"UtilityModule.h"
#include<fstream>


//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjMap::CObjMap()
{
	//Heroineのヘッダーを見たらわかる
	m_sp = false;
	key_flag = 1;
	sp_flag = false;
	m_key_control = true;
}


//イニシャライズ
void CObjMap::Init()
{

}

//アクション
void CObjMap::Action()
{
	

}

//ドロー
void CObjMap::Draw()
{
	////描画カラー情報　R=RED G=Green B=Blue A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	CObjHospital* hospital = (CObjHospital*)Objs::GetObj(OBJ_HOSPITAL);
	CObjHospital2* hospital2 = (CObjHospital2*)Objs::GetObj(OBJ_HOSPITAL2);
	CObjHospital3* hospital3 = (CObjHospital3*)Objs::GetObj(OBJ_HOSPITAL3);
	CObjDrugCampany* drug = (CObjDrugCampany*)Objs::GetObj(OBJ_DRUG_CAMPANY);
	CObjDrugCampany2* drug2 = (CObjDrugCampany2*)Objs::GetObj(OBJ_DRUG_CAMPANY2);
	CObjDrugCampany3* drug3 = (CObjDrugCampany3*)Objs::GetObj(OBJ_DRUG_CAMPANY3);
	CObjInstitute*inst = (CObjInstitute*)Objs::GetObj(OBJ_INSTITUTE);
	CObjInstitute14* inst14 = (CObjInstitute14*)Objs::GetObj(OBJ_INSTITUTE14);
	CObjInstitute13A* inst13a = (CObjInstitute13A*)Objs::GetObj(OBJ_INSTITUTE13A);
	CObjChinaTownBoss* chinatownboss = (CObjChinaTownBoss*)Objs::GetObj(OBJ_CHINA_TOWN_BOSS);
	CObjRooftop* rooftop = (CObjRooftop*)Objs::GetObj(OBJ_ROOF_TOP);
	CObjInstituteBoss* instboss = (CObjInstituteBoss*)Objs::GetObj(OBJ_INSTITUTE_BOSS);
	CObjChinaTown* chinatown = (CObjChinaTown*)Objs::GetObj(OBJ_CHINA_TOWN);
	CObjChinaTown_b* chinatown_b = (CObjChinaTown_b*)Objs::GetObj(OBJ_CHINA_TOWN_B);
	CObjChinaTown_c* chinatown_c = (CObjChinaTown_c*)Objs::GetObj(OBJ_CHINA_TOWN_C);
	CObjChinaTown_d* chinatown_d = (CObjChinaTown_d*)Objs::GetObj(OBJ_CHINA_TOWN_D);
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	
	//病院一階のマップ図
	if (hospital != nullptr)
	{
		if (hospital->GetMap() == true)
		{

			//背景表示
			src.m_top = 10.0f;   // Y
			src.m_left = 11.0f;  // X
			src.m_right = 220.0f; // X
			src.m_bottom =165.0f;// Y 

			dst.m_top = 100.0f;
			dst.m_left = 0.0f;
			dst.m_right = 300.0f+0.0f;
			dst.m_bottom = 400.0f+0.0f;

			Draw::Draw(1, &src, &dst, c, 0.0f);//病院の床
		}

	}
	//病院二階のマップ図
	if (hospital2 != nullptr)
	{
		if (hospital2->GetMap() == true)
		{

			//背景表示
			src.m_top = 15.0f;   // Y
			src.m_left = 254.0f;  // X
			src.m_right = 461.0f; // X
			src.m_bottom = 170.0f;// Y 

			dst.m_top = 100.0f;
			dst.m_left = 0.0f;
			dst.m_right = 300.0f + 0.0f;
			dst.m_bottom = 400.0f + 0.0f;

			Draw::Draw(1, &src, &dst, c, 0.0f);//病院の床
		}

	}
	//病院三階のマップ
	if (hospital3 != nullptr)
	{
		if (hospital3->GetMap() == true)
		{

			//背景表示
			src.m_top = 18.0f;   // Y
			src.m_left =502.0f;  // X
			src.m_right = 739.0f; // X
			src.m_bottom =164.0f;// Y 

			dst.m_top = 100.0f;
			dst.m_left = 0.0f;
			dst.m_right = 300.0f + 0.0f;
			dst.m_bottom = 400.0f + 0.0f;

			Draw::Draw(1, &src, &dst, c, 0.0f);//病院の床
		}

	}

	//製薬会社１階
	if (drug != nullptr)
	{
		if (drug->GetMap() == true)
		{

			//背景表示
			src.m_top = 27.0f;   // Y
			src.m_left = 69.0f;  // X
			src.m_right = 400.0f; // X
			src.m_bottom = 500.0f;// Y 

			dst.m_top = 100.0f;
			dst.m_left = 0.0f;
			dst.m_right = 300.0f + 0.0f;
			dst.m_bottom = 400.0f + 0.0f;

			Draw::Draw(7, &src, &dst, c, 0.0f);
		}

	}
	if (drug2 != nullptr)
	{
		if (drug2->GetMap() == true)
		{

			//背景表示
			src.m_top =14.0f;   // Y
			src.m_left = 29.0f;  // X
			src.m_right = 493.0f; // X
			src.m_bottom = 500.0f;// Y 

			dst.m_top = 100.0f;
			dst.m_left = 0.0f;
			dst.m_right = 300.0f + 0.0f;
			dst.m_bottom = 400.0f + 0.0f;

			Draw::Draw(6, &src, &dst, c, 0.0f);
		}

	}
	if (drug3 != nullptr)
	{
		if (drug3->GetMap() == true)
		{

			//背景表示
			src.m_top = 26.0f;   // Y
			src.m_left = 97.0f;  // X
			src.m_right =481.0f; // X
			src.m_bottom = 513.0f;// Y 

			dst.m_top = 100.0f;
			dst.m_left = 0.0f;
			dst.m_right = 300.0f + 0.0f;
			dst.m_bottom = 400.0f + 0.0f;

			Draw::Draw(6, &src, &dst, c, 0.0f);
		}

	}

	//研究所地上一階
	if (inst != nullptr)
	{
		if (inst->GetMap() == true)
		{

			//背景表示
			src.m_top = 0.0f;   // Y
			src.m_left = 360.0f;  // X
			src.m_right =1211.0f; // X
			src.m_bottom =656.0f;// Y 

			dst.m_top = 100.0f;
			dst.m_left = 0.0f;
			dst.m_right = 400.0f + 0.0f;
			dst.m_bottom = 400.0f + 0.0f;

			Draw::Draw(7, &src, &dst, c, 0.0f);
		}

	}
	//研究所地下1階
	if (inst14 != nullptr)
	{
		if (inst14->GetMap() == true)
		{

			//背景表示
			src.m_top = 39.0f;   // Y
			src.m_left = 104.0f;  // X
			src.m_right = 971.0f; // X
			src.m_bottom =535.0f;// Y 

			dst.m_top = 100.0f;
			dst.m_left = 0.0f;
			dst.m_right = 400.0f + 0.0f;
			dst.m_bottom = 400.0f + 0.0f;

			Draw::Draw(6, &src, &dst, c, 0.0f);
		}

	}
	//研究所地下2階
	if (inst13a != nullptr)
	{
		if (inst13a->GetMap() == true)
		{

			//背景表示
			src.m_top = 53.0f;   // Y
			src.m_left = 121.0f;  // X
			src.m_right = 817.0f; // X
			src.m_bottom = 464.0f;// Y 

			dst.m_top = 100.0f;
			dst.m_left = 0.0f;
			dst.m_right = 400.0f + 0.0f;
			dst.m_bottom = 400.0f + 0.0f;

			Draw::Draw(6, &src, &dst, c, 0.0f);
		}

	}
	//チャイナタウンボス戦フィールド
	if (chinatownboss != nullptr)
	{
		if (chinatownboss->GetMap() == true)
		{

			//背景表示
			src.m_top = 0.0f;   // Y
			src.m_left = 0.0f;  // X
			src.m_right = 500.0f; // X
			src.m_bottom = 500.0f;// Y 

			dst.m_top = 100.0f;
			dst.m_left = 0.0f;
			dst.m_right = 400.0f + 0.0f;
			dst.m_bottom = 400.0f + 0.0f;

			Draw::Draw(7, &src, &dst, c, 0.0f);
		}

	}
	//病院の屋上
	if (rooftop != nullptr)
	{
		if (rooftop->GetMap() == true)
		{

			//背景表示
			src.m_top = 0.0f;   // Y
			src.m_left = 0.0f;  // X
			src.m_right = 500.0f; // X
			src.m_bottom = 500.0f;// Y 

			dst.m_top = 100.0f;
			dst.m_left = 0.0f;
			dst.m_right = 400.0f + 0.0f;
			dst.m_bottom = 400.0f + 0.0f;

			Draw::Draw(15, &src, &dst, c, 0.0f);
		}

	}
	//研究所ボス戦フィールド
	if (instboss != nullptr)
	{
		if (instboss->GetMap() == true)
		{

			//背景表示
			src.m_top = 0.0f;   // Y
			src.m_left = 0.0f;  // X
			src.m_right = 500.0f; // X
			src.m_bottom = 500.0f;// Y 

			dst.m_top = 100.0f;
			dst.m_left = 0.0f;
			dst.m_right = 400.0f + 0.0f;
			dst.m_bottom = 400.0f + 0.0f;

			Draw::Draw(16, &src, &dst, c, 0.0f);
		}

	}
	//チャイナタウン
	if (chinatown != nullptr)
	{
		if (chinatown->GetMap() == true)
		{

			//背景表示
			src.m_top = 0.0f;   // Y
			src.m_left = 0.0f;  // X
			src.m_right = 500.0f; // X
			src.m_bottom = 500.0f;// Y 

			dst.m_top = 100.0f;
			dst.m_left = 0.0f;
			dst.m_right = 400.0f + 0.0f;
			dst.m_bottom = 400.0f + 0.0f;

			Draw::Draw(15, &src, &dst, c, 0.0f);
		}

	}

	//チャイナタウンb
	if (chinatown_b != nullptr)
	{
		if (chinatown_b->GetMap() == true)
		{

			//背景表示
			src.m_top = 0.0f;   // Y
			src.m_left = 0.0f;  // X
			src.m_right = 500.0f; // X
			src.m_bottom = 500.0f;// Y 

			dst.m_top = 100.0f;
			dst.m_left = 0.0f;
			dst.m_right = 400.0f + 0.0f;
			dst.m_bottom = 400.0f + 0.0f;

			Draw::Draw(18, &src, &dst, c, 0.0f);
		}

	}

	//チャイナタウンc
	if (chinatown_c != nullptr)
	{
		if (chinatown_c->GetMap() == true)
		{

			//背景表示
			src.m_top = 0.0f;   // Y
			src.m_left = 0.0f;  // X
			src.m_right = 500.0f; // X
			src.m_bottom = 500.0f;// Y 

			dst.m_top = 100.0f;
			dst.m_left = 0.0f;
			dst.m_right = 400.0f + 0.0f;
			dst.m_bottom = 400.0f + 0.0f;

			Draw::Draw(15, &src, &dst, c, 0.0f);
		}

	}

	//チャイナタウンd
	if (chinatown_d != nullptr)
	{
		if (chinatown_d->GetMap() == true)
		{

			//背景表示
			src.m_top = 0.0f;   // Y
			src.m_left = 0.0f;  // X
			src.m_right = 500.0f; // X
			src.m_bottom = 500.0f;// Y 

			dst.m_top = 100.0f;
			dst.m_left = 0.0f;
			dst.m_right = 400.0f + 0.0f;
			dst.m_bottom = 400.0f + 0.0f;

			Draw::Draw(15, &src, &dst, c, 0.0f);
		}

	}
	//拠点
	if (block != nullptr)
	{
		if (block->GetMap() == true)
		{

			//背景表示
		src.m_top = 0.0f;   // Y
			src.m_left = 0.0f;  // X
			src.m_right = 500.0f; // X
			src.m_bottom = 500.0f;// Y 

			dst.m_top = 100.0f;
			dst.m_left = 0.0f;
			dst.m_right = 400.0f + 0.0f;
			dst.m_bottom = 400.0f + 0.0f;

			Draw::Draw(15, &src, &dst, c, 0.0f);
		}

	}
	
}
