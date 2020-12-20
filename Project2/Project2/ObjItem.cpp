//�g�p����w�b�_�[�t�@�C��
#include"GameL/DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameL/DrawFont.h"
#include"GameL/WinInputs.h"
#include"GameL/UserData.h"
#include"GameL/Audio.h"

#include"GameHead.h"
#include"ObjItem.h"
#include"UtilityModule.h"
#include<fstream>


//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjItem::CObjItem(float x, float y)
{
	m_x = x;
	m_y = y;

	//�@��l�����A�C�e���ڐGSE�@���y���̓ǂݍ���
	Audio::LoadAudio(9, L"�e�ۃA�C�e��.wav", EFFECT);//�P��
}


//�C�j�V�����C�Y
void CObjItem::Init()
{
	CObjChinaTown* chinatown = (CObjChinaTown*)Objs::GetObj(OBJ_CHINA_TOWN);//�`���C�i�^�E��
	CObjChinaTownBoss* chinatownboss = (CObjChinaTownBoss*)Objs::GetObj(OBJ_CHINA_TOWN_BOSS);//�`���C�i�^�E���{�X
	if (chinatown != nullptr)
	{
		//�����蔻��pHitBox���쐬
		Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ITEM, OBJ_ITEM, 1);
	}
	if (chinatownboss != nullptr)
	{
		//�����蔻��pHitBox���쐬
		Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ITEM, OBJ_ITEM, 1);
	}
}

int CObjItem::m_bullet_item = 0;//�e�ۂ̏�����

//�A�N�V����
void CObjItem::Action()
{
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);//���_
	CObjChinaTown* chinatown = (CObjChinaTown*)Objs::GetObj(OBJ_CHINA_TOWN);//�`���C�i�^�E��
	CObjChinaTownBoss* chinatownboss = (CObjChinaTownBoss*)Objs::GetObj(OBJ_CHINA_TOWN_BOSS);//�`���C�i�^�E���{�X
	CObjChinaTown_b* chinatown_b = (CObjChinaTown_b*)Objs::GetObj(OBJ_CHINA_TOWN_B);//�`���C�i�^�E����B



	if (chinatown != nullptr)
	{
		//HitBox�̓��e���X�V
		CHitBox* hit = Hits::GetHitBox(this);
		hit->SetPos(m_x + chinatown->GetScroll(), m_y + chinatown->GetScroll2());

		//�e�ۂƐڐG���Ă邩�ǂ������ׂ�
		if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
		{
			Set_M_Bullet_Item(12);
			Audio::Start(9);

			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}
	}
	if (chinatownboss != nullptr) 
	{
		//HitBox�̓��e���X�V
		CHitBox* hit = Hits::GetHitBox(this);
		hit->SetPos(m_x + chinatownboss->GetScroll(), m_y + chinatownboss->GetScroll2());

		//�e�ۂƐڐG���Ă邩�ǂ������ׂ�
		if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
		{
			Set_M_Bullet_Item(12);
			Audio::Start(9);

			this->SetStatus(false);
			Hits::DeleteHitBox(this);
			
		}
	}
}

//�h���[
void CObjItem::Draw()
{
	////�`��J���[���@R=RED G=Green B=Blue A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);//���_
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	CObjChinaTown* chinatown = (CObjChinaTown*)Objs::GetObj(OBJ_CHINA_TOWN);
	CObjChinaTownBoss* chinatownboss = (CObjChinaTownBoss*)Objs::GetObj(OBJ_CHINA_TOWN_BOSS);
	CObjChinaTown_b* chinatown_b = (CObjChinaTown_b*)Objs::GetObj(OBJ_CHINA_TOWN_B);//�`���C�i�^�E����B

	if (chinatownboss!=nullptr)//�e�ۃA�C�e��
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 24.0f;   //y
		src.m_left = 30.0f; //x
		src.m_right = 226.0f; //x
		src.m_bottom = 222.0f; //y

		//�\���ʒu�̐ݒ�
		dst.m_top =0.0f + m_y + chinatownboss->GetScroll2();
		dst.m_left =0.0f + m_x + chinatownboss->GetScroll();
		dst.m_right =32.0f + m_x + chinatownboss->GetScroll();
		dst.m_bottom =32.0f + m_y + chinatownboss->GetScroll2();

		//�`��
		Draw::Draw(12, &src, &dst, c, 0.0f);
	}

	if (chinatown!= nullptr)//�e�ۃA�C�e��
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 24.0f;   //y
		src.m_left = 30.0f; //x
		src.m_right = 226.0f; //x
		src.m_bottom = 222.0f; //y

		//�\���ʒu�̐ݒ�
		dst.m_top = 0.0f + m_y + chinatown->GetScroll2();
		dst.m_left = 0.0f + m_x + chinatown->GetScroll();
		dst.m_right = 32.0f + m_x + chinatown->GetScroll();
		dst.m_bottom = 32.0f+m_y + chinatown->GetScroll2();

		//�`��
		Draw::Draw(12, &src, &dst, c, 0.0f);
	}
}

