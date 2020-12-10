

//�g�p����w�b�_�[�t�@�C��
#include"GameL/DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameL/DrawFont.h"
#include"GameL/WinInputs.h"

#include"GameHead.h"
#include"ObjSpBack.h"
#include"UtilityModule.h"
#include<fstream>


//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjSpBack::CObjSpBack()
{
	//Heroine�̃w�b�_�[��������킩��
	m_sp = false;
	key_flag = 1;
	sp_flag = false;
	m_key_control = true;
	mob_flag = 0;
}


//�C�j�V�����C�Y
void CObjSpBack::Init()
{

}

//�A�N�V����
void CObjSpBack::Action()
{


}

//�h���[
void CObjSpBack::Draw()
{
	////�`��J���[���@R=RED G=Green B=Blue A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);//��l��
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);//���_
	CObjDrugCampany* drug = (CObjDrugCampany*)Objs::GetObj(OBJ_DRUG_CAMPANY);//�����Ђ̈�K

	CObjChinaMob* chinamob = (CObjChinaMob*)Objs::GetObj(OBJ_CHINA_MOB);//�`���C�i�^�E���̃��u
	CObjInstMob* instmob = (CObjInstMob*)Objs::GetObj(OBJ_INST_MOB);//�������̃��u
	CObjHosMob* hosmob = (CObjHosMob*)Objs::GetObj(OBJ_HOS_MOB);//�a�@�̃��u
	CObjDrugMob* drugmob = (CObjDrugMob*)Objs::GetObj(OBJ_DRUG_MOB);//�`���C�i�^�E���̃��u
	CObjHeroine* heroine = (CObjHeroine*)Objs::GetObj(OBJ_HEROINE);//�q���C��

	CObjChinaTown* chinatown = (CObjChinaTown*)Objs::GetObj(OBJ_CHINA_TOWN);//�`���C�i�^�E��A
	CObjChinaTownBoss* chinatownboss = (CObjChinaTownBoss*)Objs::GetObj(OBJ_CHINA_TOWN_BOSS);//�`���C�i�^�E���{�X
	CObjChinaTown_b* chinatown_b = (CObjChinaTown_b*)Objs::GetObj(OBJ_CHINA_TOWN_B);//�`���C�i�^�E����B
	CObjChinaEvent* chinaevent = (CObjChinaEvent*)Objs::GetObj(OBJ_CHINA_EVENT);//�`���C�i�^�E���̃C�x���g

	CObjInstitute* inst = (CObjInstitute*)Objs::GetObj(OBJ_INSTITUTE);//������1�K
	CObjInstitute13A* inst13a = (CObjInstitute13A*)Objs::GetObj(OBJ_INSTITUTE13A);//�������n��2�K
	CObjInstituteBoss* instituteboss = (CObjInstituteBoss*)Objs::GetObj(OBJ_INSTITUTE_BOSS);//������BOSS

	CObjHospital* hospital = (CObjHospital*)Objs::GetObj(OBJ_HOSPITAL);//�a�@�̈�K
	CObjHospital2* hospital2 = (CObjHospital2*)Objs::GetObj(OBJ_HOSPITAL2);//�a�@�̓�K
	CObjRooftop* rooftop = (CObjRooftop*)Objs::GetObj(OBJ_ROOF_TOP);//�a�@�̉���


	//�`���C�i�^�E���̉�b�̔w�i
	if (chinatown != nullptr)
	{
		if (chinamob->Sp_Flag() == true)
		{
			//�؂���ʒu�̐ݒ�
			src.m_top = 372.0f;   //y
			src.m_left = 18.0f; //x
			src.m_right = 781.0f; //x
			src.m_bottom = 581.0f; //y

			//�\���ʒu�̐ݒ�
			dst.m_top = 450.0f;
			dst.m_left = 2.0f;
			dst.m_right = 798.0f;
			dst.m_bottom = 600.0f;

			Draw::Draw(7, &src, &dst, c, 0.0f);
		}
	}
	//�`���C�i�^�E���{�X�̉�b�̔w�i
	if (chinatownboss != nullptr)
	{
		if (chinamob->Sp_Flag() == true)
		{
			//�؂���ʒu�̐ݒ�
			src.m_top = 372.0f;   //y
			src.m_left = 18.0f; //x
			src.m_right = 781.0f; //x
			src.m_bottom = 581.0f; //y

			//�\���ʒu�̐ݒ�
			dst.m_top = 450.0f;
			dst.m_left = 2.0f;
			dst.m_right = 798.0f;
			dst.m_bottom = 600.0f;

			Draw::Draw(8, &src, &dst, c, 0.0f);
		}
	}
	//�������̉�b�̔w�i
	if (inst != nullptr)
	{
		if (instmob->Sp_Flag() == true)
		{
			//�؂���ʒu�̐ݒ�
			src.m_top = 372.0f;   //y
			src.m_left = 18.0f; //x
			src.m_right = 781.0f; //x
			src.m_bottom = 581.0f; //y

			//�\���ʒu�̐ݒ�
			dst.m_top = 450.0f;
			dst.m_left = 2.0f;
			dst.m_right = 798.0f;
			dst.m_bottom = 600.0f;

			Draw::Draw(8, &src, &dst, c, 0.0f);
		}
	}
	//�������̉�b�̔w�i
	if (inst13a!= nullptr)
	{
		if (instmob->Sp_Flag() == true)
		{
			//�؂���ʒu�̐ݒ�
			src.m_top = 372.0f;   //y
			src.m_left = 18.0f; //x
			src.m_right = 781.0f; //x
			src.m_bottom = 581.0f; //y

			//�\���ʒu�̐ݒ�
			dst.m_top = 450.0f;
			dst.m_left = 2.0f;
			dst.m_right = 798.0f;
			dst.m_bottom = 600.0f;

			Draw::Draw(8, &src, &dst, c, 0.0f);
		}
	}
	//�����Ђ̉�b�̔w�i
	if (drug != nullptr)
	{
		if (drugmob->Sp_Flag() == true)
		{
			//�؂���ʒu�̐ݒ�
			src.m_top = 372.0f;   //y
			src.m_left = 18.0f; //x
			src.m_right = 781.0f; //x
			src.m_bottom = 581.0f; //y

			//�\���ʒu�̐ݒ�
			dst.m_top = 450.0f;
			dst.m_left = 2.0f;
			dst.m_right = 798.0f;
			dst.m_bottom = 600.0f;

			Draw::Draw(8, &src, &dst, c, 0.0f);
		}
	}
	//�a�@��K�̉�b�̔w�i
	if (hospital != nullptr)
	{
		if (hosmob->Sp_Flag() == true)
		{
			//�؂���ʒu�̐ݒ�
			src.m_top = 372.0f;   //y
			src.m_left = 18.0f; //x
			src.m_right = 781.0f; //x
			src.m_bottom = 581.0f; //y

			//�\���ʒu�̐ݒ�
			dst.m_top = 450.0f;
			dst.m_left = 2.0f;
			dst.m_right = 798.0f;
			dst.m_bottom = 600.0f;

			Draw::Draw(9, &src, &dst, c, 0.0f);
		}
	}
	//�a�@2�K�̉�b�̔w�i
	if (hospital2 != nullptr)
	{
		if (hosmob->Sp_Flag() == true)
		{
			//�؂���ʒu�̐ݒ�
			src.m_top = 372.0f;   //y
			src.m_left = 18.0f; //x
			src.m_right = 781.0f; //x
			src.m_bottom = 581.0f; //y

			//�\���ʒu�̐ݒ�
			dst.m_top = 450.0f;
			dst.m_left = 2.0f;
			dst.m_right = 798.0f;
			dst.m_bottom = 600.0f;

			Draw::Draw(8, &src, &dst, c, 0.0f);
		}
	}
	//�a�@����̉�b�̔w�i
	if (rooftop != nullptr)
	{
		if (hosmob->Sp_Flag() == true)
		{
			//�؂���ʒu�̐ݒ�
			src.m_top = 372.0f;   //y
			src.m_left = 18.0f; //x
			src.m_right = 781.0f; //x
			src.m_bottom = 581.0f; //y

			//�\���ʒu�̐ݒ�
			dst.m_top = 450.0f;
			dst.m_left = 2.0f;
			dst.m_right = 798.0f;
			dst.m_bottom = 600.0f;

			Draw::Draw(7, &src, &dst, c, 0.0f);
		}
	}
	//���_�̉�b�̔w�i
	if (block != nullptr)
	{
		if (heroine->Sp_Flag() == true)
		{
			//�؂���ʒu�̐ݒ�
			src.m_top = 372.0f;   //y
			src.m_left = 18.0f; //x
			src.m_right = 781.0f; //x
			src.m_bottom = 581.0f; //y

			//�\���ʒu�̐ݒ�
			dst.m_top = 450.0f;
			dst.m_left = 2.0f;
			dst.m_right = 798.0f;
			dst.m_bottom = 600.0f;

			Draw::Draw(10, &src, &dst, c, 0.0f);
		}
	}
	//�`���C�i�^�E���̃C�x���g��b�̔w�i
	if (chinaevent != nullptr)
	{
		if (chinaevent->Sp_Flag() == true)
		{
			//�؂���ʒu�̐ݒ�
			src.m_top = 372.0f;   //y
			src.m_left = 18.0f; //x
			src.m_right = 781.0f; //x
			src.m_bottom = 581.0f; //y

			//�\���ʒu�̐ݒ�
			dst.m_top = 450.0f;
			dst.m_left = 2.0f;
			dst.m_right = 798.0f;
			dst.m_bottom = 600.0f;

			Draw::Draw(8, &src, &dst, c, 0.0f);
		}
	}
}

