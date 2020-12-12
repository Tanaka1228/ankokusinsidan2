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
CObjChinaAtkEnemy::CObjChinaAtkEnemy(float x, float y)
{
	m_x = x;
	m_y = y;
}

//�C�j�V�����C�Y
void CObjChinaAtkEnemy::Init()
{

	m_vx = 0.0f;
	m_vy = 0.0f;
	m_time = 0.0f;

	//�����蔻��pHitBox���쐬
	Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_ENEMY, OBJ_CHINA_ATK_ENEMY, 1);
}

//�A�N�V����
void CObjChinaAtkEnemy::Action()
{
	//�`���C�i�^�E���{�X��t�B�[���h�̏��
	CObjChinaTownBoss* chinatownboss = (CObjChinaTownBoss*)Objs::GetObj(OBJ_CHINA_TOWN_BOSS);

	m_time++;//1���Z

	if (m_time > 100)//�e�ۂ𔭎˂���Ԋu
	{
		m_time = 0;

		//�e�ۓG�@�I�u�W�F�N�g
		CObjBulletEnemy* obj_bullte_enemy = new CObjBulletEnemy(m_x, m_y);
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
		Audio::Start(2);
	}
}

//�h���[
void CObjChinaAtkEnemy::Draw()
{
	//�`���C�i�^�E���{�X��t�B�[���h�̏��
	CObjChinaTownBoss* chinatownboss = (CObjChinaTownBoss*)Objs::GetObj(OBJ_CHINA_TOWN_BOSS);

	//�`��J���[���@R=RED G=Green B=Blue A=alpha(���ߏ��)
	float c[4] = { 0.5f,2.5f,1.5f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f; //y
	src.m_left = 0.0f; //x
	src.m_right = 139.0f; //x
	src.m_bottom = 131.0f; //y

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_y + chinatownboss->GetScroll2();
	dst.m_left = 32.0f + 32.0f + m_x + chinatownboss->GetScroll();
	dst.m_right = 0.0f + m_x + chinatownboss->GetScroll();
	dst.m_bottom = 32.0f + 32.0f + m_y + chinatownboss->GetScroll2();

	//0�Ԗڂɓo�^�����O���t�B�b�N��stc�Edst�Ec�̏������ɕ`��
	Draw::Draw(1, &src, &dst, c, 0.0f);
}