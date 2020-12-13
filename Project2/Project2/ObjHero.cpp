//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL\HitBoxManager.h"
#include"GameHead.h"
#include"ObjHero.h"
#include"CObjBullet.h"
#include"UtilityModule.h"
#include"GameL/DrawFont.h"
#include"GameL/Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�ʒu���X�ύX�p
void CObjHero::SetX(float x) 
{
	m_x = x;
}

//�ʒu���Y�ύX�p
void CObjHero::SetY(float y)
{
	m_y = y;
}
float CObjHero::GetB()//�e�ی����擾�p
{
	return m_ani_frame;
}
//�ʒu���X�擾�p
float CObjHero::GetX()
{
	return m_x;
	
}
//�ʒu���Y�擾�p
float CObjHero::GetY()
{
	return m_y;
}



//�R���X�g���N�^
CObjHero::CObjHero(float x, float y)
{
	m_x = x;
	m_y = y;


	//�@�I���@���y���̓ǂݍ���
	Audio::LoadAudio(3, L"����.wav", EFFECT);//�P��
}

//�C�j�V�����C�Y
void CObjHero::Init()
{
	m_px = 0.0f; //�ʒu
	m_py = 0.0f;
	m_vx = 0.0f; //�ړ��x�N�g��
	m_vy = 0.0f; //�ړ��x�N�g��
	m_posture = 0.0f; //�E����0.0f ������1.0f


	m_ani_time=0; //�����t���[��
    m_ani_frame=0; //�����`��t���[��

	//-----------------------------------------------------------------
	//���ʃA�j���[�V����
	m_ani_time1 = 0; //�A�j���[�V�����t���[������Ԋu
    m_ani_frame1=0; //�Î~�t���[���������ɂ���

	//�w�ʃA�j���[�V����
	m_ani_time2 = 0; //�A�j���[�V�����t���[������Ԋu
	m_ani_frame2 = 0; //�Î~�t���[���������ɂ���

	//�E�A�j���[�V����
	m_ani_time3= 0; //�A�j���[�V�����t���[������Ԋu
	m_ani_frame3 = 0; //�Î~�t���[���������ɂ���

	//���A�j���[�V����
	m_ani_time4= 0; //�A�j���[�V�����t���[������Ԋu
	m_ani_frame4= 0; //�Î~�t���[���������ɂ���

	//------------------------------------------------------------------
	m_hp = 10;//��l����HP
	//--------------------------------------------------------------------
	m_f = true; //�e�۔��ː���
	m_ass_f = true;
	m_gun = 0;//�e�̍\���Ă��邩�@0���\���Ă��Ȃ� �@1���\���Ă���
	gun_type = 0;//�@0�����{���o�[ 1���A�T���g
	m_bullet = 6;//�e�ۂ̒e���@���{���o�[
	m_bullet_held = 30;//�e�ۂ̏�����
	gun_Kama = 1;//�e���\����t���O
	gun_type_flag = 1;//�e�̎�ރt���O
	ass_bullet = 30;//�A�T���g�e�ې�
	ass_bullet_held = 150;//�A�T���g�e�ۏ�����

	//---------------------------------------------------------------

	//�����蔻��pHitBox���쐬
	Hits::SetHitBox(this, m_x, m_y, 34, 34, ELEMENT_PLAYER, OBJ_HERO, 1);

	//block�Ƃ̏Փˏ�Ԋm�F�p
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	m_block_type = 0; //����ł���block�̎�ނ��m�F�p
}

//�A�N�V����
void CObjHero::Action()
{
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);//���_


	//�ړ��x�N�g���̔j��
	m_vx = 0.0f;
	m_vy = 0.0f;
	if (!block) {
		if (Input::GetVKey('A') == true)
		{
			if (gun_Kama == 1)
			{

				if (m_gun == 1)
				{
					m_gun = 0;//�\���Ă��Ȃ�
				}
				else if (m_gun == 0)
				{
					m_gun = 1;//�\���Ă���
				}

				gun_Kama = 0;
			}


		}
		else
		{
			gun_Kama = 1;
		}

		if (Input::GetVKey('Q') == true && m_gun == 1)//����̎�ނ�ς���
		{
			if (gun_type_flag == 1)
			{
				//���{���o�[
				if (gun_type == 0)
				{
					gun_type = 1;
				}
				//�A�T���g
				else if (gun_type == 1)
				{
					gun_type = 0;
				}
				gun_type_flag = 0;
			}
		}
		else
		{
			gun_type_flag = 1;
		}
	}

	if (m_bullet > 0)//�e����0�ȏ�Ȃ� --------------���{���o�[--------------------------------------------
	{
		//��l���̒e�۔���
		if (Input::GetVKey('Z') == true && m_gun == 1&&gun_type==0)
		{
			

			if (m_f == true)
			{
			

				m_bullet -= 1;

				if (m_ani_frame == 2)//�E
				{
					//�e�ۃI�u�W�F�N�g�쐬
					CObjBullet* obj_b = new CObjBullet(m_x + 0.0f, m_y + 0.0f); //�e�ۃI�u�W�F�N�g�쐬
					Objs::InsertObj(obj_b, OBJ_BULLET, 4); //������e�ۃI�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^

					Audio::Start(1);
				}
				if (m_ani_frame == 3)//��
				{
					//�e�ۃI�u�W�F�N�g�쐬
					CObjBullet* obj_b = new CObjBullet(m_x + 0.0f, m_y + 0.0f); //�e�ۃI�u�W�F�N�g�쐬
					Objs::InsertObj(obj_b, OBJ_BULLET, 4);

					Audio::Start(1);
				}
				if (m_ani_frame == 1)//���
				{
					//�e�ۃI�u�W�F�N�g�쐬
					CObjBullet* obj_b = new CObjBullet(m_x + 0.0f, m_y + 0.0f); //�e�ۃI�u�W�F�N�g�쐬
					Objs::InsertObj(obj_b, OBJ_BULLET, 4);

					Audio::Start(1);
				}
				if (m_ani_frame == 0)//�O
				{
					//�e�ۃI�u�W�F�N�g�쐬
					CObjBullet* obj_b = new CObjBullet(m_x + 0.0f, m_y + 0.0f); //�e�ۃI�u�W�F�N�g�쐬
					Objs::InsertObj(obj_b, OBJ_BULLET, 4);

					Audio::Start(1);
				}



				m_f = false;
	       	}
		}
		else
		{
			m_f = true;
		}
	}//------------------------------------------------------------------------------------------------------



	if (ass_bullet > 0)//�e����0�ȏ�Ȃ�   ------------�A�T���g-------------------------------------------------------
	{
		//��l���̒e�۔���
		if (Input::GetVKey('Z') == true && m_gun == 1 && gun_type == 1)
		{
			

				ass_bullet -= 1;

				if (m_ani_frame == 2)//�E
				{
					//�e�ۃI�u�W�F�N�g�쐬
					CObjBullet* obj_b = new CObjBullet(m_x + 0.0f, m_y + 0.0f); //�e�ۃI�u�W�F�N�g�쐬
					Objs::InsertObj(obj_b, OBJ_BULLET, 4); //������e�ۃI�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^
					Audio::Start(1);
				}
				if (m_ani_frame == 3)//��
				{
					//�e�ۃI�u�W�F�N�g�쐬
					CObjBullet* obj_b = new CObjBullet(m_x + 0.0f, m_y + 0.0f); //�e�ۃI�u�W�F�N�g�쐬
					Objs::InsertObj(obj_b, OBJ_BULLET, 4);
					Audio::Start(1);
				}
				if (m_ani_frame == 1)//���
				{
					//�e�ۃI�u�W�F�N�g�쐬
					CObjBullet* obj_b = new CObjBullet(m_x + 0.0f, m_y + 0.0f); //�e�ۃI�u�W�F�N�g�쐬
					Objs::InsertObj(obj_b, OBJ_BULLET, 4);
					Audio::Start(1);
				}
				if (m_ani_frame == 0)//�O
				{
					//�e�ۃI�u�W�F�N�g�쐬
					CObjBullet* obj_b = new CObjBullet(m_x + 0.0f, m_y + 0.0f); //�e�ۃI�u�W�F�N�g�쐬
					Objs::InsertObj(obj_b, OBJ_BULLET, 4);
					Audio::Start(1);
				}
			
			
		}
		

	}//------------------------------------------------------------------------------------------------------

	//���{���o�[�̃����[�h
	if (Input::GetVKey(VK_SPACE) == true && m_bullet_held > 0)//�����[�h
	{

		if ( m_bullet== 6)
		{
			m_bullet_held -= 0;
			if (m_bullet_held >= 0) {
				m_bullet += 0;
			}

		}
		if (m_bullet == 5)
		{
			m_bullet_held -= 1;
			if (m_bullet_held >= 0) {
				m_bullet += 1;
			}
		}
		if (m_bullet == 4)
		{
			m_bullet_held -= 2;
			if (m_bullet_held >= 0) {
				m_bullet += 2;
			}
		}
		if (m_bullet == 3)
		{
			m_bullet_held -= 3;
			if (m_bullet_held >= 0) {
				m_bullet += 3;
			}
		}
		if (m_bullet == 2)
		{
			m_bullet_held -= 4;
			if (m_bullet_held >= 0) {
				m_bullet += 4;
			}
		}
		if (m_bullet == 1)
		{
			m_bullet_held -= 5;
			if (m_bullet_held >= 0) {
				m_bullet += 5;
			}
		}
		if (m_bullet == 0)
		{
			m_bullet_held -= 6;
			if (m_bullet_held >= 0) {
				m_bullet += 6;
			}
		}

	}
	//�A�T���g�̃����[�h
	if (Input::GetVKey(VK_SPACE) == true && ass_bullet_held > 0)//�����[�h�A�T���g
	{
		if (ass_bullet == 30)
		{
			ass_bullet_held -= 0;
			if (ass_bullet_held > 0) {
				ass_bullet += 0;
			}
		}
		if (ass_bullet == 29)
		{
			ass_bullet_held -= 1;
			if (ass_bullet_held > 0) {
				ass_bullet += 1;
			}
		}
		if (ass_bullet == 28)
		{
			ass_bullet_held -= 2;
			if (ass_bullet_held > 0) {
				ass_bullet += 2;
			}
		}
		if (ass_bullet == 27)
		{
			ass_bullet_held -= 3;
			if (ass_bullet_held > 0) {
				ass_bullet += 3;
			}
		}
		if (ass_bullet == 26)
		{
			ass_bullet_held -= 4;
			if (ass_bullet_held > 0) {
				ass_bullet += 4;
			}
		}
		if (ass_bullet == 25)
		{
			ass_bullet_held -= 5;
			if (ass_bullet_held > 0) {
				ass_bullet += 5;
			}
		}
		if (ass_bullet == 24)
		{
			ass_bullet_held -= 6;
			if (ass_bullet_held > 0) {
				ass_bullet += 6;
			}
		}
		if (ass_bullet == 23)
		{
			ass_bullet_held -= 7;
			if (ass_bullet_held > 0) {
				ass_bullet += 7;
			}
		}
		if (ass_bullet == 22)
		{
			ass_bullet_held -= 8;
			if (ass_bullet_held > 0) {
				ass_bullet += 8;
			}
		}
		if (ass_bullet == 21)
		{
			ass_bullet_held -= 9;
			if (ass_bullet_held > 0) {
				ass_bullet += 9;
			}
		}
		if (ass_bullet == 20)
		{
			ass_bullet_held -= 10;
			if (ass_bullet_held > 0) {
				ass_bullet += 10;
			}
		}
		if (ass_bullet == 19)
		{
			ass_bullet_held -= 11;
			if (ass_bullet_held > 0) {
				ass_bullet += 11;
			}
		}
		if (ass_bullet == 18)
		{
			ass_bullet_held -= 12;
			if (ass_bullet_held > 0) {
				ass_bullet += 12;
			}
		}
		if (ass_bullet == 17)
		{
			ass_bullet_held -= 13;
			if (ass_bullet_held > 0) {
				ass_bullet += 13;
			}
		}
		if (ass_bullet == 16)
		{
			ass_bullet_held -= 14;
			if (ass_bullet_held > 0) {
				ass_bullet += 14;
			}
		}
		if (ass_bullet == 15)
		{
			ass_bullet_held -= 15;
			if (ass_bullet_held > 0) {
				ass_bullet += 15;
			}
		}
		if (ass_bullet == 14)
		{
			ass_bullet_held -= 16;
			if (ass_bullet_held > 0) {
				ass_bullet += 16;
			}
		}
		if (ass_bullet == 13)
		{
			ass_bullet_held -= 17;
			if (ass_bullet_held > 0) {
				ass_bullet += 17;
			}
		}
		if (ass_bullet == 12)
		{
			ass_bullet_held -= 18;
			if (ass_bullet_held > 0) {
				ass_bullet += 18;
			}
		}
		if (ass_bullet == 11)
		{
			ass_bullet_held -= 19;
			if (ass_bullet_held > 0) {
				ass_bullet += 19;
			}
		}
		if (ass_bullet == 10)
		{
			ass_bullet_held -= 20;
			if (ass_bullet_held > 0) {
				ass_bullet += 20;
			}
		}
		if (ass_bullet == 9)
		{
			ass_bullet_held -= 21;
			if (ass_bullet_held > 0) {
				ass_bullet += 21;
			}
		}
		if (ass_bullet == 8)
		{
			ass_bullet_held -= 22;
			if (ass_bullet_held > 0) {
				ass_bullet +=22;
			}
		}
		if (ass_bullet == 7)
		{
			ass_bullet_held -= 23;
			if (ass_bullet_held > 0) {
				ass_bullet += 23;
			}
		}
		if (ass_bullet == 6)
		{
			ass_bullet_held -= 24;
			if (ass_bullet_held > 0) {
				ass_bullet += 24;
			}
		}
		if (ass_bullet == 5)
		{
			ass_bullet_held -= 25;
			if (ass_bullet_held > 0) {
				ass_bullet += 25;
			}
		}
		if (ass_bullet == 4)
		{
			ass_bullet_held -= 26;
			if (ass_bullet_held > 0) {
				ass_bullet += 26;
			}
		}
		if (ass_bullet == 3)
		{
			ass_bullet_held -= 27;
			if (ass_bullet_held > 0) {
				ass_bullet += 27;
			}
		}
		if (ass_bullet == 2)
		{
			ass_bullet_held -= 28;
			if (ass_bullet_held > 0) {
				ass_bullet += 28;
			}
		}
		if (ass_bullet == 1)
		{
			ass_bullet_held -= 29;
			if (ass_bullet_held > 0) {
				ass_bullet += 29;
			}
		}
		if (ass_bullet == 0)
		{
			ass_bullet_held -= 30;
			if (ass_bullet_held >= 0) {
				ass_bullet += 30;
			}
		}

	}


	//----------��l���E�ړ�(�A�j���[�V����)-----------------------
	if (Input::GetVKey(VK_RIGHT) == true) //��l���ړ��L�[ �E
	{
		m_x += 5.0f;
		m_vx += m_x;
		m_posture = 0.0f;
		m_ani_frame = 2;
		m_ani_time3 += 1;
		if (m_gun == 1)//������\������ړ����x�ቺ
		{
			m_x -= 2;
			m_vx -= m_x;
		}
		
		
	}
	else
	{
		m_ani_time3= 0;
		m_ani_frame3 = 0;
	}
	if (m_ani_time3 > 2)
	{
		m_ani_frame3+= 1;
		m_ani_time3 = 0;
	}
	if (m_ani_frame3 == 2)
	{
		Audio::Start(3);
		m_ani_frame3 = 0;
	}
	//--------------------------------------------------------------------

	//----------��l�����ړ�(�A�j���[�V����)-----------------------
	if (Input::GetVKey(VK_LEFT) == true) //��l���ړ��L�[ ��
	{
		m_x -= 5.0f;
		m_vx -= m_x;
		m_posture = 1.0f;
		m_ani_frame = 3;
		m_ani_time4 += 1;
		if (m_gun == 1)//������\������ړ����x�ቺ
		{
			m_x += 2;
			m_vx -= m_x;
		}
		
		
	}
	else
	{
		m_ani_time4 = 0;
		m_ani_frame4 = 0;
	}
	if (m_ani_time4 > 2)
	{
		m_ani_frame4 += 1;
		m_ani_time4 = 0;
	}
	if (m_ani_frame4 == 2)
	{
		Audio::Start(3);
		m_ani_frame4= 0;
	}
	//-------------------------------------------------------------------

	//----------��l����ړ�(�A�j���[�V����)-----------------------
	if (Input::GetVKey(VK_UP) == true) //��l���ړ��L�[ ��
	{
		m_y -= 5.0f;
		m_vy -= m_y;
		m_ani_frame = 1;
		m_ani_time2 += 1;
		if (m_gun == 1)//������\������ړ����x�ቺ
		{
			m_y += 2;
			m_vy -= m_y;
		}
	
	}
	else
	{
		m_ani_time2 = 0;
		m_ani_frame2 = 0;
	}
	if (m_ani_time2 > 3)
	{
		m_ani_frame2 += 1;
		m_ani_time2 = 0;
	}
	if (m_ani_frame2 == 3)
	{
		Audio::Start(3);
		m_ani_frame2 = 0;
	}
	//---------------------------------------------------------------

	//----------��l�����ړ�(�A�j���[�V����)-----------------------
	if (Input::GetVKey(VK_DOWN) == true) //��l���ړ��L�[ ��
	{
		m_y+= 5.0f;
		m_vy += m_y;
		m_ani_frame = 0;
		m_ani_time1 += 1;
		if (m_gun == 1)//������\������ړ����x�ቺ
		{
			m_y -= 2;
			m_vy -= m_y;
		}
		
	}
	else
	{
		m_ani_time1 = 0;
		m_ani_frame1 = 0;
	}
	if (m_ani_time1 > 3)
	{
		m_ani_frame1 += 1;
		m_ani_time1 = 0;
	}
	if (m_ani_frame1 == 3)
	{
		Audio::Start(3);
		m_ani_frame1 = 0;
	}
	//--------------------------------------------------------------------



	//�ړ��x�N�g���̐��K��
	UnitVec(&m_vy, &m_vx);

	//HitBox�̓��e���X�V
	CHitBox* hit = Hits::GetHitBox(this); //�쐬����HitBox�X�V�p�̓���������o��
	hit->SetPos(m_x, m_y);                //���������V�����ʒu(��l���@�̈ʒu)���ɒu��������


	//�G�@�I�u�W�F�N�g�ƐڐG�������l���@�폜
	if (hit->CheckElementHit(ELEMENT_ENEMY) ==true)
	{
		m_hp -= 1;
	
	}
	
	if (m_hp <= 0)//HP���O�ɂȂ�����j��
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		//��l�����łŃQ�[���I�[�o�[�Ɉڍs����
		Scene::SetScene(new CSceneGameOver());
	}

}

//�h���[
void CObjHero::Draw()
{
	int AniData1[3] = //���ʌ�������o�^
	{
		0,1,2,
	};
	int AniData2[3] = //�w�ʌ�������o�^
	{
		0,1,2,
	};
	int AniData3[2] = //�E��������o�^
	{
		0,1,
	};
	int AniData4[2] = //����������o�^
	{
		0,1,
	};

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	//��l��
	if (m_ani_frame == 2) //�E
	{

		//�؂���ʒu�̐ݒ�
		src.m_top = 64.0f;   //y
		src.m_left = 0.0f + AniData3[m_ani_frame3] * 32.0f; //x
		src.m_right = 32.0f + AniData3[m_ani_frame3] * 32.0f; //x
		src.m_bottom = 96.0f; //y


	}
	if (m_ani_frame == 1) //��
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 32.0f;   //y
		src.m_left = 0.0f + AniData2[m_ani_frame2] * 32.0f; //x
		src.m_right = 32.0f + AniData2[m_ani_frame2] * 32.0f; //x
		src.m_bottom = 64.0f; //y
	}

	if (m_ani_frame == 0) //�O
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;   //y
		src.m_left = 0.0f+AniData1[m_ani_frame1]*32.0f; //x
		src.m_right = 32.0f+AniData1[m_ani_frame1]*32.0f; //x
		src.m_bottom =32.0f; //y
	}

	if (m_ani_frame == 3)//��
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 96.0f;   //y
		src.m_left = 0.0f + AniData4[m_ani_frame4] * 32.0f; //x
		src.m_right = 32.0f + AniData4[m_ani_frame4] * 32.0f; //x
		src.m_bottom =128.0f; //y
	}

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 36.0f + m_x;
	dst.m_bottom = 34.0f + m_y;

	Draw::Draw(0, &src, &dst, c, 0.0f);


	//wchar_t str[32];
	//swprintf_s(str, L"�e�� : %d / 6", m_bullet);
	//Font::StrDraw(str, 10, 560, 22, c);// X  Y �傫�� 
	
	//��l����HP�\��
	wchar_t strHP[32];
	swprintf_s(strHP, L"HP : %d", m_hp);
	Font::StrDraw(strHP, 10, 5, 28, c);// X  Y �傫�� 

	
}

////�\���ʒu�̐ݒ�
//dst.m_top = 0.0f + m_y;
//dst.m_left = (64.0f * m_posture) + m_x;
//dst.m_right = (64.0f - 64.0f * m_posture) + m_x;
//dst.m_bottom = 32.0f + 50.0f + m_y;