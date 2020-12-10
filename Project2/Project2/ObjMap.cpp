//�g�p����w�b�_�[�t�@�C��
#include"GameL/DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameL/DrawFont.h"
#include"GameL/WinInputs.h"

#include"GameHead.h"
#include"ObjMap.h"
#include"UtilityModule.h"
#include<fstream>


//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjMap::CObjMap()
{
	//Heroine�̃w�b�_�[��������킩��
	m_sp = false;
	key_flag = 1;
	sp_flag = false;
	m_key_control = true;
}


//�C�j�V�����C�Y
void CObjMap::Init()
{

}

//�A�N�V����
void CObjMap::Action()
{
	

}

//�h���[
void CObjMap::Draw()
{
	////�`��J���[���@R=RED G=Green B=Blue A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

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

	
	//�a�@��K�̃}�b�v�}
	if (hospital != nullptr)
	{
		if (hospital->GetMap() == true)
		{

			//�w�i�\��
			src.m_top = 10.0f;   // Y
			src.m_left = 11.0f;  // X
			src.m_right = 220.0f; // X
			src.m_bottom =165.0f;// Y 

			dst.m_top = 100.0f;
			dst.m_left = 0.0f;
			dst.m_right = 300.0f+0.0f;
			dst.m_bottom = 400.0f+0.0f;

			Draw::Draw(1, &src, &dst, c, 0.0f);//�a�@�̏�
		}

	}
	//�a�@��K�̃}�b�v�}
	if (hospital2 != nullptr)
	{
		if (hospital2->GetMap() == true)
		{

			//�w�i�\��
			src.m_top = 15.0f;   // Y
			src.m_left = 254.0f;  // X
			src.m_right = 461.0f; // X
			src.m_bottom = 170.0f;// Y 

			dst.m_top = 100.0f;
			dst.m_left = 0.0f;
			dst.m_right = 300.0f + 0.0f;
			dst.m_bottom = 400.0f + 0.0f;

			Draw::Draw(1, &src, &dst, c, 0.0f);//�a�@�̏�
		}

	}
	//�a�@�O�K�̃}�b�v
	if (hospital3 != nullptr)
	{
		if (hospital3->GetMap() == true)
		{

			//�w�i�\��
			src.m_top = 18.0f;   // Y
			src.m_left =502.0f;  // X
			src.m_right = 739.0f; // X
			src.m_bottom =164.0f;// Y 

			dst.m_top = 100.0f;
			dst.m_left = 0.0f;
			dst.m_right = 300.0f + 0.0f;
			dst.m_bottom = 400.0f + 0.0f;

			Draw::Draw(1, &src, &dst, c, 0.0f);//�a�@�̏�
		}

	}

	//�����ЂP�K
	if (drug != nullptr)
	{
		if (drug->GetMap() == true)
		{

			//�w�i�\��
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

			//�w�i�\��
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

			//�w�i�\��
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

	//�������n���K
	if (inst != nullptr)
	{
		if (inst->GetMap() == true)
		{

			//�w�i�\��
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
	//�������n��1�K
	if (inst14 != nullptr)
	{
		if (inst14->GetMap() == true)
		{

			//�w�i�\��
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
	//�������n��2�K
	if (inst13a != nullptr)
	{
		if (inst13a->GetMap() == true)
		{

			//�w�i�\��
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
	//�`���C�i�^�E���{�X��t�B�[���h
	if (chinatownboss != nullptr)
	{
		if (chinatownboss->GetMap() == true)
		{

			//�w�i�\��
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
	//�a�@�̉���
	if (rooftop != nullptr)
	{
		if (rooftop->GetMap() == true)
		{

			//�w�i�\��
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
	//�������{�X��t�B�[���h
	if (instboss != nullptr)
	{
		if (instboss->GetMap() == true)
		{

			//�w�i�\��
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
	//�`���C�i�^�E��
	if (chinatown != nullptr)
	{
		if (chinatown->GetMap() == true)
		{

			//�w�i�\��
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

	//�`���C�i�^�E��b
	if (chinatown_b != nullptr)
	{
		if (chinatown_b->GetMap() == true)
		{

			//�w�i�\��
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

	//�`���C�i�^�E��c
	if (chinatown_c != nullptr)
	{
		if (chinatown_c->GetMap() == true)
		{

			//�w�i�\��
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

	//�`���C�i�^�E��d
	if (chinatown_d != nullptr)
	{
		if (chinatown_d->GetMap() == true)
		{

			//�w�i�\��
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
	//���_
	if (block != nullptr)
	{
		if (block->GetMap() == true)
		{

			//�w�i�\��
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
