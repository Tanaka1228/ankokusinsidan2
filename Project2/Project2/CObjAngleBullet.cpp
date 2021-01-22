//�g�p����w�b�_�[�t�@�C��
#include"GameL/DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameHead.h"
#include"CObjAngleBullet.h"
#include"UtilityModule.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjAngleBullet::CObjAngleBullet(float x, float y,float r,float speed)//�R���X�g���N�^�Ŏ󂯎��������ϐ��ɑ���
{
	m_x = x;
	m_y = y;
	m_r = r;
	m_speed = speed;
}

//�C�j�V�����C�Y
void CObjAngleBullet::Init()
{
	
	m_vx = cos(3.14f / 180.0f * m_r);
	m_vy = sin(3.14f / 180.0f * m_r);

	//�����蔻��pHitBox���쐬
	Hits::SetHitBox(this, m_x, m_y, 30, 22, ELEMENT_ENEMY, OBJ_ANGLE_BULLET, 1);//�ʒux �ʒu�� ����w �c��h
}

//�A�N�V����
void CObjAngleBullet::Action()
{
	//�a�@�̉���̏��
	CObjRooftop* rooftop = (CObjRooftop*)Objs::GetObj(OBJ_ROOF_TOP);
	//��l���@�ƗU���e�ۂŊp�x���Ƃ�
	CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	//�`���C�i�^�E��BOSS�̏��
	CObjChinaTownBoss* chinatownboss = (CObjChinaTownBoss*)Objs::GetObj(OBJ_CHINA_TOWN_BOSS);
	//������BOSS�̏��
	CObjInstituteBoss* instituteboss = (CObjInstituteBoss*)Objs::GetObj(OBJ_INSTITUTE_BOSS);

	if (rooftop != nullptr)
	{
		
			//�ړ�
			m_x += m_vx * m_speed;
			m_y -= m_vy * m_speed;

			//�e�ۂ�HitBox�X�V�p�|�C���^�[�擾
			CHitBox* hit = Hits::GetHitBox(this); //HitBox�̈ʒu��e�ۂ̈ʒu�ɍX�V
			hit->SetPos(m_x + rooftop->GetScroll(), m_y + rooftop->GetScroll2());


			//�G�@�����S�ɗ̈�O�ɏo����G�@��j������
			bool check = CheckWindow(m_x, m_y, 1700, 32, 2500.0f, 2500.0f);
			if (check == false)
			{
				this->SetStatus(false);//���g�ɍ폜����
				Hits::DeleteHitBox(this);
			}

			//��l���@�I�u�W�F�N�g�ƐڐG������e�ۍ폜
			if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
			{
				this->SetStatus(false);   //���g�ɍ폜���߂��o���B
				Hits::DeleteHitBox(this); //�e�ۂ����L����HitBox�ɍ폜����B

				return;
			}
		
	}
	if (chinatownboss != nullptr)
	{
		
			//�ړ�
			m_x += m_vx * m_speed;
			m_y -= m_vy * m_speed;

			//�e�ۂ�HitBox�X�V�p�|�C���^�[�擾
			CHitBox* hit = Hits::GetHitBox(this); //HitBox�̈ʒu��e�ۂ̈ʒu�ɍX�V
			hit->SetPos(m_x + chinatownboss->GetScroll(), m_y + chinatownboss->GetScroll2());


			//�G�@�����S�ɗ̈�O�ɏo����G�@��j������
			bool check = CheckWindow(m_x, m_y, 1000.0f, 1000.0f, 2000.0f, 1900.0f);
			if (check == false)
			{
				this->SetStatus(false);//���g�ɍ폜����
				Hits::DeleteHitBox(this);
			}

			//��l���@�I�u�W�F�N�g�ƐڐG������e�ۍ폜
			if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
			{
				this->SetStatus(false);   //���g�ɍ폜���߂��o���B
				Hits::DeleteHitBox(this); //�e�ۂ����L����HitBox�ɍ폜����B
				return;
			}
	}
	if (instituteboss != nullptr)
	{

		//�ړ�
		m_x += m_vx * m_speed;
		m_y -= m_vy * m_speed;

		//�e�ۂ�HitBox�X�V�p�|�C���^�[�擾
		CHitBox* hit = Hits::GetHitBox(this); //HitBox�̈ʒu��e�ۂ̈ʒu�ɍX�V
		hit->SetPos(m_x + instituteboss->GetScroll(), m_y + instituteboss->GetScroll2());


		//�G�@�����S�ɗ̈�O�ɏo����G�@��j������
		bool check = CheckWindow(m_x, m_y, 0.0f, 0.0f, 3000.0f, 2500.0f);
		if (check == false)
		{
			this->SetStatus(false);//���g�ɍ폜����
			Hits::DeleteHitBox(this);
		}

		//��l���@�I�u�W�F�N�g�ƐڐG������e�ۍ폜
		if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
		{
			this->SetStatus(false);   //���g�ɍ폜���߂��o���B
			Hits::DeleteHitBox(this); //�e�ۂ����L����HitBox�ɍ폜����B
			return;
		}



	}
}

//�h���[
void CObjAngleBullet::Draw()
{

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	//�؂���ʒu�̐ݒ�@�O���t�B�b�N������Ă��Ȃ�
	src.m_top = 12.0f;   //y
	src.m_left = 8.0f;  //x
	src.m_right = 26.0f; //x 
	src.m_bottom = 19.0f; //y

	////�\���ʒu�̐ݒ�
	//dst.m_top = 5.0f + m_y;//�c�̈ʒu�ύX
	//dst.m_left = 0.0f + m_x;
	//dst.m_right = 30.0f + m_x;
	//dst.m_bottom = 19.0f + m_y;
//�a�@�̉���̏��
	CObjRooftop* rooftop = (CObjRooftop*)Objs::GetObj(OBJ_ROOF_TOP);

	//�`���C�i�^�E��BOSS�̏��
	CObjChinaTownBoss* chinatownboss = (CObjChinaTownBoss*)Objs::GetObj(OBJ_CHINA_TOWN_BOSS);

	//������BOSS�̏��
	CObjInstituteBoss* instituteboss = (CObjInstituteBoss*)Objs::GetObj(OBJ_INSTITUTE_BOSS);

	if (rooftop != nullptr)
	{
		//�\���ʒu�̐ݒ�
		dst.m_top = 0.0f + m_y + rooftop->GetScroll2();
		dst.m_left = 0.0f + m_x + rooftop->GetScroll();
		dst.m_right = 45.0f + m_x + rooftop->GetScroll();
		dst.m_bottom = 32.0f + m_y + rooftop->GetScroll2();

		Draw::Draw(3, &src, &dst, c, m_r);
	}

	if (chinatownboss != nullptr)
	{
		//�\���ʒu�̐ݒ�
		dst.m_top = 0.0f + m_y + chinatownboss->GetScroll2();
		dst.m_left = 0.0f + m_x + chinatownboss->GetScroll();
		dst.m_right = 45.0f + m_x + chinatownboss->GetScroll();
		dst.m_bottom = 32.0f + m_y + chinatownboss->GetScroll2();

		Draw::Draw(3, &src, &dst, c, m_r);
	}
	if (instituteboss != nullptr)
	{
		//�\���ʒu�̐ݒ�
		dst.m_top = 0.0f + m_y + instituteboss->GetScroll2();
		dst.m_left = 0.0f + m_x + instituteboss->GetScroll();
		dst.m_right = 45.0f + m_x + instituteboss->GetScroll();
		dst.m_bottom = 32.0f + m_y + instituteboss->GetScroll2();

		Draw::Draw(3, &src, &dst, c, m_r);
	}
}