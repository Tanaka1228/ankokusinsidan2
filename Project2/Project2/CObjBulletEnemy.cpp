//�g�p����w�b�_�[�t�@�C��
#include"GameL/DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameHead.h"
#include"CObjBulletEnemy.h"
#include"UtilityModule.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjBulletEnemy::CObjBulletEnemy(float x, float y)//�R���X�g���N�^�Ŏ󂯎��������ϐ��ɑ���
{
	m_x = x;
	m_y = y;
	
}

//�C�j�V�����C�Y
void CObjBulletEnemy::Init()
{
	CObjChinaTownBoss* chinatownboss = (CObjChinaTownBoss*)Objs::GetObj(OBJ_CHINA_TOWN_BOSS);//�`���C�i�^�E���{�X
	CObjChinaAtkEnemy* chinaAtkEnemy = (CObjChinaAtkEnemy*)Objs::GetObj(OBJ_CHINA_ATK_ENEMY);
	CObjChinaAtkEnemy2* chinaAtkEnemy2 = (CObjChinaAtkEnemy2*)Objs::GetObj(OBJ_CHINA_ATK_ENEMY2);
	if (chinatownboss != nullptr)
	{
		
	if (chinaAtkEnemy !=nullptr)
	{
		m_vx = -1.0f;
		m_vy = -1.0f;
		//�����蔻��pHitBox���쐬
		Hits::SetHitBox(this, m_x, m_y, 30, 20, ELEMENT_ENEMY, OBJ_BULLET_ENEMY, 1);
	}
	if (chinaAtkEnemy2 != nullptr)
	{
		m_vx = +1.0f;
		m_vy = -1.0f;
		//�����蔻��pHitBox���쐬
		Hits::SetHitBox(this, m_x, m_y, 30, 20, ELEMENT_ENEMY, OBJ_BULLET_ENEMY, 1);
	}
	}

}

//�A�N�V����
void CObjBulletEnemy::Action()
{
	//�`���C�i�^�E��BOSS�̏��
	CObjChinaTownBoss* chinatownboss = (CObjChinaTownBoss*)Objs::GetObj(OBJ_CHINA_TOWN_BOSS);//�`���C�i�^�E��BOSS�̏��
	CObjChinaAtkEnemy* chinaAtkEnemy = (CObjChinaAtkEnemy*)Objs::GetObj(OBJ_CHINA_ATK_ENEMY);
	CObjChinaAtkEnemy2* chinaAtkEnemy2 = (CObjChinaAtkEnemy2*)Objs::GetObj(OBJ_CHINA_ATK_ENEMY2);

	if (chinatownboss != nullptr)
	{
		if (chinaAtkEnemy != nullptr)
		{
			//�ړ�
			m_x += m_vx * 5.0f;
			m_y += m_vy * 5.0f;

			//�e�ۂ�HitBox�X�V�p�|�C���^�[�擾
			CHitBox* hit = Hits::GetHitBox(this); //HitBox�̈ʒu��e�ۂ̈ʒu�ɍX�V
			hit->SetPos(m_x + chinatownboss->GetScroll(), m_y + chinatownboss->GetScroll2());


			//�G�@�����S�ɗ̈�O�ɏo����G�@��j������
			bool check = CheckWindow(m_x, m_y, 1700.0f, -32.0f, 3000.0f, 2500.0f);
			if (check == false)
			{
				this->SetStatus(false);//���g�ɍ폜����
				Hits::DeleteHitBox(this);
			}

			//�G�@�I�u�W�F�N�g�ƐڐG������e�ۍ폜
			if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
			{
				this->SetStatus(false);   //���g�ɍ폜���߂��o���B
				Hits::DeleteHitBox(this); //�e�ۂ����L����HitBox�ɍ폜����B
			}
		}
		if (chinaAtkEnemy2 != nullptr)
		{
			//�ړ�
			m_x += m_vx * 5.0f;
			m_y += m_vy * 5.0f;

			//�e�ۂ�HitBox�X�V�p�|�C���^�[�擾
			CHitBox* hit = Hits::GetHitBox(this); //HitBox�̈ʒu��e�ۂ̈ʒu�ɍX�V
			hit->SetPos(m_x + chinatownboss->GetScroll(), m_y + chinatownboss->GetScroll2());


			//�G�@�����S�ɗ̈�O�ɏo����G�@��j������
			bool check = CheckWindow(m_x, m_y, 1700.0f, -32.0f, 3000.0f, 2500.0f);
			if (check == false)
			{
				this->SetStatus(false);//���g�ɍ폜����
				Hits::DeleteHitBox(this);
			}

			//�G�@�I�u�W�F�N�g�ƐڐG������e�ۍ폜
			if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
			{
				this->SetStatus(false);   //���g�ɍ폜���߂��o���B
				Hits::DeleteHitBox(this); //�e�ۂ����L����HitBox�ɍ폜����B
			}
		}
	}
	
}

//�h���[
void CObjBulletEnemy::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	//�؂���ʒu�̐ݒ�@
	//�e�ۂ��������ɂ��Ă���
	src.m_top = 0.0f;   //y
	src.m_left = 126.0f;  //x
	src.m_right = 96.0f; //x 
	src.m_bottom = 32.0f; //y

	//�`���C�i�^�E��BOSS�̏��
	CObjChinaTownBoss* chinatownboss = (CObjChinaTownBoss*)Objs::GetObj(OBJ_CHINA_TOWN_BOSS);
	CObjChinaAtkEnemy* chinaatkenemy = (CObjChinaAtkEnemy*)Objs::GetObj(OBJ_CHINA_ATK_ENEMY);
	CObjChinaAtkEnemy2* chinaatkenemy2 = (CObjChinaAtkEnemy2*)Objs::GetObj(OBJ_CHINA_ATK_ENEMY2);
	
	if (chinatownboss != nullptr)
	{
		if (chinaatkenemy != nullptr)
		{
			//�\���ʒu�̐ݒ�
			dst.m_top = -10.0f + m_y + chinatownboss->GetScroll2();
			dst.m_left = -5.0f + m_x + chinatownboss->GetScroll();
			dst.m_right = 45.0f + m_x + chinatownboss->GetScroll();
			dst.m_bottom = 32.0f + m_y + chinatownboss->GetScroll2();

			Draw::Draw(3, &src, &dst, c, 0.0f);
		}
		if (chinaatkenemy2 != nullptr)
		{
			//�\���ʒu�̐ݒ�
			dst.m_top = -10.0f + m_y + chinatownboss->GetScroll2();
			dst.m_left = -5.0f + m_x + chinatownboss->GetScroll();
			dst.m_right = 45.0f + m_x + chinatownboss->GetScroll();
			dst.m_bottom = 32.0f + m_y + chinatownboss->GetScroll2();

			Draw::Draw(3, &src, &dst, c, 0.0f);
		}
	}
	


	
}