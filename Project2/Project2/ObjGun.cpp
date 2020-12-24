//�g�p����w�b�_�[�t�@�C��
#include"GameL/DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameL/SceneObjManager.h"
#include"GameL/SceneManager.h"
#include"GameHead.h"
#include"ObjGun.h"
#include"UtilityModule.h"
#include"GameL/WinInputs.h"
#include"GameL/DrawFont.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjGun::CObjGun()//�R���X�g���N�^�Ŏ󂯎��������ϐ��ɑ���
{
	//�O���O���t�B�b�N�t�@�C����ǂݍ���0�Ԃɓo�^(512�~512�s�N�Z��)���܂�֌W�Ȃ��炵��
	Draw::LoadImage(L"�e�ې�.png", 52, TEX_SIZE_512);//��l���O���t�B�b�N
}


//�C�j�V�����C�Y
void CObjGun::Init()
{
	m_ani_frame = 2;
	m_gun = 0;
	m_f =true;
}

//�A�N�V����
void CObjGun::Action()
{
	CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	m_ani_frame = obj->Get_AniFlame();
}

//�h���[
void CObjGun::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	CObjItem* objitem = (CObjItem*)Objs::GetObj(OBJ_ITEM);

	m_ani_frame = obj->Get_AniFlame();//��l���̌����̏��

	if (obj->Get_Gun()== 1)//�n���h�K��
	{

		if (m_ani_frame == 2)
		{
			float c[4] = { 1.0f,1.0f,1.0f,1.0f };
			RECT_F src;
			RECT_F dst;

			//�؂���ʒu�̐ݒ�
			src.m_top = 0.0f;   //y
			src.m_left = 0.0f; //x
			src.m_right = 32.0f; //x
			src.m_bottom = 32.0f; //y

			//�\���ʒu�̐ݒ�
			dst.m_top = 10.0f + obj->GetY();
			dst.m_left = 20.0f + obj->GetX();
			dst.m_right = 60.0f + obj->GetX();
			dst.m_bottom = 50.0f + obj->GetY();

			Draw::Draw(2, &src, &dst, c, 0.0f);
		}
		else if (m_ani_frame == 3)//��
		{
			//�؂���ʒu�̐ݒ�
			src.m_top = 0.0f;   //y
			src.m_left = 33.0f; //x
			src.m_right = 61.0f; //x
			src.m_bottom = 18.0f; //y

			//�\���ʒu�̐ݒ�
			dst.m_top = 10.0f + obj->GetY();
			dst.m_left = -28.0f + obj->GetX();
			dst.m_right = 0.0f + 9.0f + obj->GetX();
			dst.m_bottom = 32.0f + obj->GetY();

			Draw::Draw(2, &src, &dst, c, 0.0f);
		}
		else if (m_ani_frame == 0)//����
		{
			//�؂���ʒu�̐ݒ�
			src.m_top = 3.0f;   //y
			src.m_left = 74.0f; //x
			src.m_right = 83.0f; //x
			src.m_bottom = 21.0f; //y

			//�\���ʒu�̐ݒ�
			dst.m_top = 10.0f + obj->GetY();
			dst.m_left = 5.0f + obj->GetX();
			dst.m_right = 20.0f + obj->GetX();
			dst.m_bottom = 32.0f + obj->GetY();

			Draw::Draw(2, &src, &dst, c, 0.0f);
		}
	}
	else if (obj->Get_Gun() == 0)
	{
	}

	if (obj->Get_M_Bullet() == 0)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;   //y
		src.m_left = 768.0f; //x
		src.m_right = 896.0f; //x
		src.m_bottom = 128.0f; //y

		//�\���ʒu�̐ݒ�
		dst.m_top = 480.0f;
		dst.m_left = 65.0f;
		dst.m_right = 195.0f;
		dst.m_bottom = 600.0f;

		Draw::Draw(52, &src, &dst, c, 0.0f);
	}
	if (obj->Get_M_Bullet() == 1)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;   //y
		src.m_left = 0.0f; //x
		src.m_right = 128.0f; //x
		src.m_bottom = 128.0f; //y

		//�\���ʒu�̐ݒ�
		dst.m_top = 480.0f;
		dst.m_left = 75.0f;
		dst.m_right = 205.0f;
		dst.m_bottom = 600.0f;

		Draw::Draw(52, &src, &dst, c, 0.0f);
	}
	if (obj->Get_M_Bullet() == 2)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;   //y
		src.m_left = 128.0f; //x
		src.m_right = 256.0f; //x
		src.m_bottom = 128.0f; //y

		//�\���ʒu�̐ݒ�
		dst.m_top = 479.0f;
		dst.m_left = 74.0f;
		dst.m_right = 204.0f;
		dst.m_bottom = 599.0f;

		Draw::Draw(52, &src, &dst, c, 0.0f);
	}
	if (obj->Get_M_Bullet() == 3)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;   //y
		src.m_left = 256.0f; //x
		src.m_right = 384.0f; //x
		src.m_bottom = 128.0f; //y

		//�\���ʒu�̐ݒ�
		dst.m_top = 480.0f;
		dst.m_left = 73.0f;
		dst.m_right = 203.0f;
		dst.m_bottom = 600.0f;

		Draw::Draw(52, &src, &dst, c, 0.0f);
	}
	if (obj->Get_M_Bullet() == 4)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;   //y
		src.m_left = 384.0f; //x
		src.m_right = 512.0f; //x
		src.m_bottom = 128.0f; //y

		//�\���ʒu�̐ݒ�
		dst.m_top = 480.0f;
		dst.m_left = 71.0f;
		dst.m_right = 201.0f;
		dst.m_bottom = 600.0f;

		Draw::Draw(52, &src, &dst, c, 0.0f);
	}
	if (obj->Get_M_Bullet() == 5)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;   //y
		src.m_left = 512.0f; //x
		src.m_right = 640.0f; //x
		src.m_bottom = 128.0f; //y

		//�\���ʒu�̐ݒ�
		dst.m_top = 480.0f;
		dst.m_left = 71.0f;
		dst.m_right = 201.0f;
		dst.m_bottom = 600.0f;

		Draw::Draw(52, &src, &dst, c, 0.0f);
	}
	if (obj->Get_M_Bullet() == 6)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;   //y
		src.m_left = 640.0f; //x
		src.m_right =768.0f; //x
		src.m_bottom = 128.0f; //y

		//�\���ʒu�̐ݒ�
		dst.m_top = 480.0f;
		dst.m_left = 70.0f;
		dst.m_right = 200.0f;
		dst.m_bottom = 600.0f;

		Draw::Draw(52, &src, &dst, c, 0.0f);
	}

	//���{���o�[
	if (obj->Get_GunType() == 0)
	{
		//static wchar_t guntype0[32];
		//swprintf_s(guntype0, L"���{���o�[ : %d / 6", obj->Get_M_Bullet());
		//Font::StrDraw(guntype0, 10, 560, 22, c);// X  Y �傫�� 

		static wchar_t strb0[64];
		swprintf_s(strb0, L"�e�ۏ����� : %d��", obj->Get_M_Bullet_Held());
		Font::StrDraw(strb0, 300.0f, 560, 22, c);// X  Y  �傫�� 

	}
	
}