#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g : ��l��
class CObjHero : public CObj
{
public:
	CObjHero(float x,float y);
	~CObjHero() {};
	void Init();        //�C�j�V�����C�Y
	void Action();      //�A�N�V����
	void Draw();        //�h���[

	float GetX();     //�ʒu���X�擾�p
	float GetY();     //�ʒu���Y�擾�p
	
	float GetX2() { return m_x; }   //�ʒu���X2�擾�p�@�����蔻��
	float GetY2() { return m_y; }   //�ʒu���Y2�擾�p
	  //�ʒu���Y2�擾�p
	float GetVX() { return m_vx; }   //�ʒu���VX�擾�p
	float GetVY() { return m_vy; }   //�ʒu���VY�擾�p

	//m_x,m_y�̓A�N�V�����Q�[���w�쏑�Ō����Am_px,m_py�ł��B

	void SetX(float x);//�ʒu���X�ύX�p
	void SetY(float y);//�ʒu���Y�ύX�p
	void SetX2(float x)  { m_x = x; }
	void SetY2(float y)  { m_y = y; }
	void SetVY(float vy) { m_vy = vy; }
	void SetVX(float vx) { m_vx = vx; }
	
	void SetUp(bool b) { m_hit_up = b; }
	void SetDown(bool b) { m_hit_down = b; }
	void SetLeft(bool b) { m_hit_left = b; }
	void SetRight(bool b) { m_hit_right = b; }

	bool GetUp() { return m_hit_up; }
	bool GetDown() { return m_hit_down; }
	bool GetLeft() { return m_hit_left; }
	bool GetRight(){ return m_hit_right; }

	float GetB();//�e�ۂ̌���
	int Get_Gun() { return m_gun; }//�e���\���Ă��邩�\���Ă��Ȃ�����Ԃ�
	int Get_Gun_Kama() { return gun_Kama; ; }//�\���Ă��邩�̃t���O
	int Get_GunType() { return gun_type; }//�e�̎�ނ�Ԃ�
	int Get_Gun_Type_Flag() { return gun_type_flag; }//�e�̎�ރt���O

	int Get_AniFlame() { return m_ani_frame; }

	int Get_M_Bullet() { return m_bullet; }//�e�ې��@���{���o�[
	int Get_M_Bullet_Held() { return m_bullet_held; }//�e�ۏ�����

	int Get_M_Ass_Bullet() { return ass_bullet; }//�e�ې��@�A�T���g
	int Get_M_Ass_Bullet_Held() { return ass_bullet_held; }//�e�ۏ�����

	int GetBT() { return m_block_type; }//��l��������ł���u���b�N�̎��
	void SetBT(int t) { m_block_type = t; }


private:
	float m_px; //�ʒu
	float m_py;
	float m_x;  //��l���@��x�����ړ��p�ϐ�
	float m_y;  //��l���@��y�����ړ��p�ϐ�
	float m_vx; //�ړ��x�N�g��
	float m_vy; //�ړ��x�N�g��
	float m_posture; //���p��
	bool m_f; //�e�۔��ː���p
	bool m_ass_f;

	//---------------------------------------------------

	int m_ani_time=0; //�����A�j���[�V�����t���[������Ԋu
	int m_ani_frame=0; //�����`��t���[��


	//---------------------------------------------------
	//���ʃA�j���[�V����
	int m_ani_time1 = 0; //�A�j���[�V�����t���[������Ԋu
	int m_ani_frame1=0; //�`��t���[��


	//�w�ʃA�j���[�V����
	int m_ani_time2 = 0; //�A�j���[�V�����t���[������Ԋu
	int m_ani_frame2 = 0; //�`��t���[��

	//�E�A�j���[�V����
	int m_ani_time3 = 0; //�A�j���[�V�����t���[������Ԋu
	int m_ani_frame3 = 0; //�`��t���[��

	//���A�j���[�V����
	int m_ani_time4 = 0; //�A�j���[�V�����t���[������Ԋu
	int m_ani_frame4 = 0; //�`��t���[��

	//----------------------------------------------------

	int m_hp;//��l����HP
	int m_gun;//�e�̌���
	int gun_type;//�e�̎��
	int gun_Kama;//�e���\����
	int gun_type_flag;

	//---------------------------------------------------

	int ass_bullet;//�A�T���g�e�ۂ̒e��
	int ass_bullet_held;//�A�T���g�e�ۂ̏�����
	int m_bullet;//�e�ۂ̒e�� ���{���o�[
	int m_bullet_held;//�e�ۂ̏������@���{���o�[

	//---------------------------------------------------
	//block�Ƃ̏Փˏ�Ԋm�F�p
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

	//����ł���block�̎�ނ��m�F�p
	int m_block_type;
};