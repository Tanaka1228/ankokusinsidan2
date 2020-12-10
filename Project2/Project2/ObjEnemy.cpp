//�g�p����w�b�_�[�t�@�C��
#include"GameL/DrawTexture.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"ObjEnemy.h"
#include"UtilityModule.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjEnemy::CObjEnemy(float x, float y)
{
	m_x = x;
	m_y = y;
}


//�C�j�V�����C�Y
void CObjEnemy::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;

	//�����蔻��pHitBox���쐬
	Hits::SetHitBox(this, m_x, m_y, 42, 42, ELEMENT_ENEMY, OBJ_ENEMY, 1);
}

//�A�N�V����
void CObjEnemy::Action()
{
	//�ړ�����
	m_vx = -1.0f;
	m_vy = 0.0f;

	//�ړ��x�N�g���̐��K��
	UnitVec(&m_vy, &m_vx);

	//���x��t����B
	m_vx*=1.5f;
	m_vy*=1.5f;

	//�ړ��x�N�g�������W�ɉ��Z����
	m_x += m_vx;
	m_y += m_vy;

	//HitBox�̓��e���X�V
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);


	//�G�@�����S�ɗ̈�O�ɏo����G�@��j������
	bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 800.0f, 600.0f);
	if (check==false)
	{
		this->SetStatus(false);//���g�ɍ폜����
		Hits::DeleteHitBox(this);

		return;
	}

	//�e�ۂƐڐG���Ă邩�ǂ������ׂ�
	if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
}

//�h���[
void CObjEnemy::Draw()
{

	//�`��J���[���@R=RED G=Green B=Blue A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f; //y
	src.m_left = 0.0f; //x
	src.m_right = 139.0f; //x
	src.m_bottom = 131.0f; //y

	//�������{�X��t�B�[���h�̏��
	CObjInstituteBoss* instituteboss = (CObjInstituteBoss*)Objs::GetObj(OBJ_INSTITUTE_BOSS);

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f+m_y+instituteboss->GetScroll2();
	dst.m_left = 32.0f + 10.0f +m_x+instituteboss->GetScroll();
	dst.m_right = 0.0f+m_x + instituteboss->GetScroll();
	dst.m_bottom = 32.0f+10.0f+m_y + instituteboss->GetScroll2();

	//0�Ԗڂɓo�^�����O���t�B�b�N��stc�Edst�Ec�̏������ɕ`��
	Draw::Draw(1, &src, &dst, c, 0.0f);
}