//�g�p����w�b�_�[�t�@�C��
#include"GameL/DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameHead.h"
#include"CObjBullet.h"
#include"ObjHero.h"
#include"UtilityModule.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjBullet::CObjBullet(float x, float y)//�R���X�g���N�^�Ŏ󂯎��������ϐ��ɑ���
{
	m_x = x;//���{���o�[
	m_y = y;
	m_vx = 0.0f;//���x�p�ϐ�
	m_vy = 0.0f;

	ass_m_x = x;//�A�T���g
	ass_m_y = y;
	ass_m_vx = 0.0f;//���x�p�ϐ�
	ass_m_vy = 0.0f;

	m_Xpos = 0;//0�͍�
	m_Ypos = 0;//0�͏�
}


//�C�j�V�����C�Y
void CObjBullet::Init()
{
	m_eff.m_top = 32;
	m_eff.m_left = 0;
	m_eff.m_right = 32;
	m_eff.m_bottom = 64;
	m_ani = 0;
	m_ani_time = 0;
	m_del = false;
	

	//�����蔻��pHitBox���쐬
	Hits::SetHitBox(this, m_x, m_y, 25, 22, ELEMENT_PLAYER, OBJ_BULLET, 1);
}

//�A�N�V����
void CObjBullet::Action()
{
	CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float bx = obj->GetB();

	if (m_del == true)
	{
		//�A�j���`�����RECT���
		RECT_F ani_src[4] =
		{
			{32,0,32,64},
			{32,32,64,64},
			{32,64,96,64},
			{32,96,128,64},
		};

		//�A�j���[�V�����̃R�}�Ԋu����
		if (m_ani_time > 2)
		{
			m_ani++;//�A�j���[�V�����̃R�}��1�i�߂�
			m_ani_time = 0;

			m_eff = ani_src[m_ani];//�A�j���[�V������RECT�z�񂩂�m_ani�Ԗڂ�RECT�����擾
		}
		else
		{
			m_ani_time++;
		}

		//���e�A�j���[�V�����I���Ŗ{���ɃI�u�W�F�N�g�̔j��
		if (m_ani == 4)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}

		return;//���ŏ����́A�����ŃA�N�V�������\�b�h���I��������
	}



	if (bx == 2)
	{
		m_vx += 6.0f;
		m_x += m_vx;
		m_Xpos = 0.0f;
	}
	else if (bx == 3)
	{
		m_vx -= 6.0f;
		m_x   += m_vx;
		m_Xpos = 1.0f;
	}
	else if (bx == 1)
	{
		m_vy -= 6.0f;
		m_y += m_vy;
		m_Ypos = 0.0f;
	}
	else if (bx == 0)
	{
		m_vy += 6.0f;
		m_y += m_vy;
		m_Ypos = 1.0f;
	}

	//�e�ۂ�HitBox�X�V�p�|�C���^�[�擾
	CHitBox* hit = Hits::GetHitBox(this); //HitBox�̈ʒu��e�ۂ̈ʒu�ɍX�V
	hit->SetPos(m_x, m_y);

	

	//�G�@�����S�ɗ̈�O�ɏo����G�@��j������
	bool check = CheckWindow(m_x, m_y, 100.0f, 50.0f, 700.0f, 550.0f);
	if (check == false)
	{
		this->SetStatus(false);//���g�ɍ폜����
		Hits::DeleteHitBox(this);
	}

	//�G�@�I�u�W�F�N�g�ƐڐG������e�ۍ폜
	if (hit->CheckObjNameHit(OBJ_ENEMY) != nullptr)
	{
		this->SetStatus(false);   //���g�ɍ폜���߂��o���B
		Hits::DeleteHitBox(this); //�e�ۂ����L����HitBox�ɍ폜����B
	}
	//�I�u�W�F�N�g���Q�Ɠ����蔻��s���A�������Ă���΍폜
   /*  for (int i = 0; i < 6; i++)
     {
		 if (hit->CheckObjNameHit(data_base[i]) != nullptr)
		 {
			 m_del = true;
			 hit->SetInvincibility(true);
		}
    }*/

}

//�h���[
void CObjBullet::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);

	//�\���ʒu�̐ݒ�
	dst.m_top = (32.0f - 32.0f * m_Ypos) + m_y;//�c�̈ʒu�ύX
	dst.m_left = (32.0f * m_Xpos) + m_x;
	dst.m_right = (32.0f - 32.0f * m_Xpos) + m_x;
	dst.m_bottom = (32.0f * m_Ypos) + m_y;
		

		if (m_del == true)
		{
			//���e�A�j���[�V�����`��
			Draw::Draw(14, &m_eff, &dst, c, 0.0f);
		}
		else
		{
		 

			//�؂���ʒu�̐ݒ�@
			src.m_top = 0.0f;   //y
			src.m_left = 0.0f;  //x
			src.m_right = 32.0f; //x 
			src.m_bottom = 32.0f; //y

			Draw::Draw(3, &src, &dst, c, 0.0f);
		}

		
	
}