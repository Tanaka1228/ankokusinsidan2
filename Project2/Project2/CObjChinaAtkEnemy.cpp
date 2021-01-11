//�g�p����w�b�_�[�t�@�C��
#include"GameL/DrawTexture.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"CObjChinaAtkEnemy.h"
#include"UtilityModule.h"
#include"GameL/Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjChinaAtkEnemy::CObjChinaAtkEnemy(float x, float y,int id)
{
	m_id = id;
	m_x = x;
	m_y = y;
}

//�C�j�V�����C�Y
void CObjChinaAtkEnemy::Init()
{

	m_vx = 0.0f;
	m_vy = 0.0f;
	m_time = 0.0f;

	//�@�e�ۂ��G�ɓ��������@���y���̓ǂݍ���
	Audio::LoadAudio(6, L"����.wav", EFFECT);//�P��


	if (m_id == 1)
	{
		//�����蔻��pHitBox���쐬
		Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_ENEMY, OBJ_CHINA_ATK_ENEMY, 1);
	}
	if (m_id == 2)
	{
		//�����蔻��pHitBox���쐬
		Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_ENEMY, OBJ_CHINA_ATK_ENEMY, 1);
	}
	if (m_id == 3)
	{
		//�����蔻��pHitBox���쐬
		Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_ENEMY, OBJ_CHINA_ATK_ENEMY, 1);
	}
}

//�A�N�V����
void CObjChinaAtkEnemy::Action()
{
	//�`���C�i�^�E���{�X��t�B�[���h�̏��
	CObjChinaTownBoss* chinatownboss = (CObjChinaTownBoss*)Objs::GetObj(OBJ_CHINA_TOWN_BOSS);
	//�`���C�i�^�E���̏��
	CObjChinaTown* chinatown = (CObjChinaTown*)Objs::GetObj(OBJ_CHINA_TOWN);
	//�`���C�i�^�E��b�̏��
	CObjChinaTown_b* chinatownb = (CObjChinaTown_b*)Objs::GetObj(OBJ_CHINA_TOWN_B);


	//�`���C�i�^�E���G��
	if (m_id == 1) {
		m_time++;//1���Z

		if (m_time > 60)//�e�ۂ𔭎˂���Ԋu
		{
			m_time = 0;

			//�e�ۓG�@�I�u�W�F�N�g
			CObjBulletEnemy* obj_bullte_enemy = new CObjBulletEnemy(m_x, m_y, 3);
			Objs::InsertObj(obj_bullte_enemy, OBJ_BULLET_ENEMY, 4);
		}


		//�G�@�����S�ɗ̈�O�ɏo����G�@��j������
		bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 4000.0f, 3000.0f);
		if (check == false)
		{
			this->SetStatus(false);//���g�ɍ폜����
			Hits::DeleteHitBox(this);

			return;
		}

		//HitBox�̓��e���X�V
		CHitBox* hit = Hits::GetHitBox(this);
		hit->SetPos(m_x + chinatown->GetScroll(), m_y + chinatown->GetScroll2());

		//�e�ۂƐڐG���Ă邩�ǂ������ׂ�
		if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
			Audio::Start(5);
		}
	}
	//�`���C�i�^�E���{�X�̎G��
	if (m_id == 2) {
		m_time++;//1���Z

		if (m_time > 100)//�e�ۂ𔭎˂���Ԋu
		{
			m_time = 0;

			//�e�ۓG�@�I�u�W�F�N�g
			CObjBulletEnemy* obj_bullte_enemy = new CObjBulletEnemy(m_x, m_y, 1);
			Objs::InsertObj(obj_bullte_enemy, OBJ_BULLET_ENEMY, 4);
		}


		//�G�@�����S�ɗ̈�O�ɏo����G�@��j������
		bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 3072.0f, 2752.0f);
		if (check == false)
		{
			this->SetStatus(false);//���g�ɍ폜����
			Hits::DeleteHitBox(this);

			return;
		}

		//HitBox�̓��e���X�V
		CHitBox* hit = Hits::GetHitBox(this);
		hit->SetPos(m_x + chinatownboss->GetScroll(), m_y + chinatownboss->GetScroll2());

		//�e�ۂƐڐG���Ă邩�ǂ������ׂ�
		if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
			Audio::Start(5);
		}
	}
	if (chinatownb != nullptr)
	{
		//�`���C�i�^�E�� b �̎G��
		if (m_id == 3)
		{
			m_time++;//1���Z

			if (m_time > 100)//�e�ۂ𔭎˂���Ԋu
			{
				m_time = 0;

				//�e�ۓG�@�I�u�W�F�N�g
				CObjBulletEnemy* obj_bullet_enemy = new CObjBulletEnemy(m_x, m_y, 4);
				Objs::InsertObj(obj_bullet_enemy, OBJ_BULLET_ENEMY, 4);
			}


			//�G�@�����S�ɗ̈�O�ɏo����G�@��j������
			bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 3000.0f, 3000.0f);
			if (check == false)
			{
				this->SetStatus(false);//���g�ɍ폜����
				Hits::DeleteHitBox(this);

				return;
			}

			//HitBox�̓��e���X�V
			CHitBox* hit = Hits::GetHitBox(this);
			hit->SetPos(m_x + chinatownb->GetScroll(), m_y + chinatownb->GetScroll2());

			//�e�ۂƐڐG���Ă邩�ǂ������ׂ�
			if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
			{
				this->SetStatus(false);
				Hits::DeleteHitBox(this);
				Audio::Start(5);
			}
		}
	}
}

//�h���[
void CObjChinaAtkEnemy::Draw()
{
	//�`���C�i�^�E���{�X��t�B�[���h�̏��
	CObjChinaTownBoss* chinatownboss = (CObjChinaTownBoss*)Objs::GetObj(OBJ_CHINA_TOWN_BOSS);
	//�`���C�i�^�E���̏��
	CObjChinaTown* chinatown = (CObjChinaTown*)Objs::GetObj(OBJ_CHINA_TOWN);
	//�`���C�i�^�E��b�̏��
	CObjChinaTown_b* chinatownb = (CObjChinaTown_b*)Objs::GetObj(OBJ_CHINA_TOWN_B);

	//�`��J���[���@R=RED G=Green B=Blue A=alpha(���ߏ��)
	float c[4] = { 0.5f,2.5f,1.5f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu


	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f; //y
	src.m_left = 0.0f; //x
	src.m_right = 139.0f; //x
	src.m_bottom = 131.0f; //y

	if (chinatown != nullptr) {
		if (m_id == 1) {
			//�\���ʒu�̐ݒ�
			dst.m_top = 0.0f + m_y + chinatown->GetScroll2();
			dst.m_left = 32.0f + 32.0f + m_x + chinatown->GetScroll();
			dst.m_right = 0.0f + m_x + chinatown->GetScroll();
			dst.m_bottom = 32.0f + 32.0f + m_y + chinatown->GetScroll2();

			//1�Ԗڂɓo�^�����O���t�B�b�N��stc�Edst�Ec�̏������ɕ`��
			Draw::Draw(1, &src, &dst, c, 0.0f);
		}
	}
	if (chinatownboss != nullptr) {
		if (m_id == 2) {
			//�\���ʒu�̐ݒ�
			dst.m_top = 0.0f + m_y + chinatownboss->GetScroll2();
			dst.m_left = 32.0f + 32.0f + m_x + chinatownboss->GetScroll();
			dst.m_right = 0.0f + m_x + chinatownboss->GetScroll();
			dst.m_bottom = 32.0f + 32.0f + m_y + chinatownboss->GetScroll2();

			//1�Ԗڂɓo�^�����O���t�B�b�N��stc�Edst�Ec�̏������ɕ`��
			Draw::Draw(1, &src, &dst, c, 0.0f);
		}
	}
	if (chinatownb != nullptr)
	{
		if (m_id == 3)
		{
			//�\���ʒu�̐ݒ�
			dst.m_top = 0.0f + m_y + chinatownb->GetScroll2();
			dst.m_left = 32.0f + 32.0f + m_x + chinatownb->GetScroll();
			dst.m_right = 0.0f + m_x + chinatownb->GetScroll();
			dst.m_bottom = 32.0f + 32.0f + m_y + chinatownb->GetScroll2();

			//1�Ԗڂɓo�^�����O���t�B�b�N��stc�Edst�Ec�̏������ɕ`��
			Draw::Draw(1, &src, &dst, c, 0.0f);
		}
	}
}