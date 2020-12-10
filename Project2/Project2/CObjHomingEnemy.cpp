//�g�p����w�b�_�[�t�@�C��
#include"GameL/DrawTexture.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"CObjHomingEnemy.h"
#include"UtilityModule.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjHomingEnemy::CObjHomingEnemy(float x, float y)
{
	m_x = x;
	m_y = y;
}


//�C�j�V�����C�Y
void CObjHomingEnemy::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;
	m_time = 0;
	m_hp = 5;


	//�����蔻��pHitBox���쐬
	Hits::SetHitBox(this, m_x, m_y,132 , 132, ELEMENT_ENEMY, OBJ_HOMING_ENEMY, 1);
}

//�A�N�V����
void CObjHomingEnemy::Action()
{
	//�a�@�̉���̏��
	CObjRooftop* rooftop = (CObjRooftop*)Objs::GetObj(OBJ_ROOF_TOP);

	m_time++;
	if (m_time > 100)
	{
	
		m_time = 0;
		//�U���e�ۍ쐬
		CObjHomingBullet* obj_homing_bullet = new CObjHomingBullet(m_x, m_y); //�U���e�I�u�W�F�N�g�쐬
		Objs::InsertObj(obj_homing_bullet, OBJ_HOMING_BULLET, 4); //�U���e�ۓo�^
	
		
	}


	//�ړ�����
	m_vx = 0.0f;
	m_vy = 0.0f;

	//�ړ��x�N�g���̐��K��
	UnitVec(&m_vy, &m_vx);

	//���x��t����B
	m_vx *= 1.5f;
	m_vy *= 1.5f;

	//�ړ��x�N�g�������W�ɉ��Z����
	m_x += m_vx;
	m_y += m_vy;

	//HitBox�̓��e���X�V
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x+rooftop->GetScroll(), m_y+rooftop->GetScroll2());


	//�z�[�~���O�G�@�����S�ɗ̈�O�ɏo����G�@��j������
	bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 1700.0f, 705.0f);
	if (check == false)
	{
		this->SetStatus(false);//���g�ɍ폜����
		Hits::DeleteHitBox(this);

		return;
	}

	//�e�ۂƐڐG���Ă邩�ǂ������ׂ�
	if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	{
		m_hp -= 1;	
	}
	if (m_hp <= 0)//HP���O�ɂȂ�����j��
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
}

//�h���[
void CObjHomingEnemy::Draw()
{
	//�`��J���[���@R=RED G=Green B=Blue A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,6.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f; //y
	src.m_left = 0.0f; //x
	src.m_right = 139.0f; //x
	src.m_bottom = 131.0f; //y

	//�a�@�̉���̏��
	CObjRooftop* rooftop = (CObjRooftop*)Objs::GetObj(OBJ_ROOF_TOP);

	dst.m_top = 0.0f + m_y + rooftop->GetScroll2();
	dst.m_left = 32.0f + 100.0f + m_x + rooftop->GetScroll();
	dst.m_right = 0.0f + m_x + rooftop->GetScroll();
	dst.m_bottom = 32.0f + 100.0f + m_y + rooftop->GetScroll2();

	//0�Ԗڂɓo�^�����O���t�B�b�N��stc�Edst�Ec�̏������ɕ`��
	Draw::Draw(1, &src, &dst, c, 0.0f);
}