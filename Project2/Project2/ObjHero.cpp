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

	//�@�e���\����@���y���̓ǂݍ���
	Audio::LoadAudio(7, L"�\��.wav", EFFECT);//�P��

	//�@�G�̒e�ۂ���l���ɐڐGSE�@���y���̓ǂݍ���
	Audio::LoadAudio(8, L"��l���_���[�W.wav", EFFECT);//�P��

	//�O���O���t�B�b�N�t�@�C����ǂݍ���0�Ԃɓo�^(512�~512�s�N�Z��)���܂�֌W�Ȃ��炵��
	Draw::LoadImage(L"HP.png", 50, TEX_SIZE_512);//��l���O���t�B�b�N
	//�O���O���t�B�b�N�t�@�C����ǂݍ���0�Ԃɓo�^(512�~512�s�N�Z��)���܂�֌W�Ȃ��炵��
	Draw::LoadImage(L"HP��.png", 51, TEX_SIZE_512);//��l���O���t�B�b�N

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
	m_hp =256.0f;//��l����HP
	//--------------------------------------------------------------------
	m_f = true; //�e�۔��ː���
	m_ass_f = true;
	m_gun = 0;//�e�̍\���Ă��邩�@0���\���Ă��Ȃ� �@1���\���Ă���
	gun_type = 0;//�@0�����{���o�[ 1���A�T���g
	
	m_bullet_held = 30;//�e�ۂ̏�����
	gun_Kama = 1;//�e���\����t���O
	gun_type_flag = 1;//�e�̎�ރt���O
	//ass_bullet = 30;//�A�T���g�e�ې�
	//ass_bullet_held = 150;//�A�T���g�e�ۏ�����

	//---------------------------------------------------------------

	//block�Ƃ̏Փˏ�Ԋm�F�p
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	m_block_type = 0; //����ł���block�̎�ނ��m�F�p


	//�����蔻��pHitBox���쐬
	Hits::SetHitBox(this, m_x, m_y, 34, 34, ELEMENT_PLAYER, OBJ_HERO, 1);
}

int CObjHero::m_bullet = 6;//�e�ۂ̒e���@���{���o�[

//�A�N�V����
void CObjHero::Action()
{
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);//���_
	CObjChinaMob* chinamob = (CObjChinaMob*)Objs::GetObj(OBJ_CHINA_MOB);//�`���C�i�^�E���̃��u
	CObjInstMob* instmob = (CObjInstMob*)Objs::GetObj(OBJ_INST_MOB);//�������̃��u
	CObjHosMob* hosmob = (CObjHosMob*)Objs::GetObj(OBJ_HOS_MOB);//�a�@�̃��u
	CObjDrugMob* drugmob = (CObjDrugMob*)Objs::GetObj(OBJ_DRUG_MOB);//�`���C�i�^�E���̃��u
	CObjHeroine* heroine = (CObjHeroine*)Objs::GetObj(OBJ_HEROINE);//�q���C��


	CObjChinaTown* chinatown = (CObjChinaTown*)Objs::GetObj(OBJ_CHINA_TOWN);//�`���C�i�^�E��A
	CObjChinaTownBoss* chinatownboss = (CObjChinaTownBoss*)Objs::GetObj(OBJ_CHINA_TOWN_BOSS);//�`���C�i�^�E���{�X
	CObjChinaTown_b* chinatown_b = (CObjChinaTown_b*)Objs::GetObj(OBJ_CHINA_TOWN_B);//�`���C�i�^�E����B
	CObjChinaEvent* chinaevent = (CObjChinaEvent*)Objs::GetObj(OBJ_CHINA_EVENT);//�`���C�i�^�E���̃C�x���g

	CObjInstitute* inst = (CObjInstitute*)Objs::GetObj(OBJ_INSTITUTE);//������1�K
	CObjInstitute13A* inst13a = (CObjInstitute13A*)Objs::GetObj(OBJ_INSTITUTE13A);//�������n��2�K
	CObjInstituteBoss* instituteboss = (CObjInstituteBoss*)Objs::GetObj(OBJ_INSTITUTE_BOSS);//������BOSS

	CObjHospital* hospital = (CObjHospital*)Objs::GetObj(OBJ_HOSPITAL);//�a�@�̈�K
	CObjHospital2* hospital2 = (CObjHospital2*)Objs::GetObj(OBJ_HOSPITAL2);//�a�@�̓�K
	CObjRooftop* rooftop = (CObjRooftop*)Objs::GetObj(OBJ_ROOF_TOP);//�a�@�̉���

	CObjDrugCampany* drug = (CObjDrugCampany*)Objs::GetObj(OBJ_DRUG_CAMPANY);//�����Ђ̈�K

	//�ړ��x�N�g���̔j��
	m_vx = 0.0f;
	m_vy = 0.0f;
	if (!block) {
		if (Input::GetVKey('A') == true)
		{
			if (gun_Kama == 1)
			{
				Audio::Start(7);

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
	}

	if (m_bullet > 0)//�e����0�ȏ�Ȃ� --------------���{���o�[--------------------------------------------
	{
		//��l���̒e�۔���
		if (Input::GetVKey('Z') == true && m_gun == 1 && gun_type == 0)
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


	//���{���o�[�̃����[�h
	if (Input::GetVKey(VK_SPACE) == true && m_bullet_held > 0)//�����[�h
	{

		if (m_bullet == 6)
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
	

		//----------��l���E�ړ�(�A�j���[�V����)-----------------------
		if (Input::GetVKey(VK_RIGHT) == true) //��l���ړ��L�[ �E
		{

			m_x += 5.0f;
			m_vx += m_x;
			m_posture = 0.0f;
			m_ani_frame = 2;
			m_ani_time3 += 1;

			//�����Ɖ�b�I��--------
			if (chinatown != nullptr||chinatownboss!=nullptr)
			{
				chinamob->SetSp_flag(false);
				chinamob->SetM_sp(0);
			}
			if (hospital != nullptr || hospital2 != nullptr || rooftop != nullptr) {
				hosmob->SetSp_flag(false);
				hosmob->SetM_sp(0);
			}
			if (drug != nullptr) {
				drugmob->SetSp_flag(false);
				drugmob->SetM_sp(0);
			}
			if (inst != nullptr || inst13a != nullptr || instituteboss != nullptr)
			{
				instmob->SetSp_flag(false);
				instmob->SetM_sp(0);
			}
			if (block != nullptr) {
				heroine->SetSp_flag(false);
				heroine->SetM_sp(0);
			}
			//----------------------------
		}
		else
		{
			m_ani_time3 = 0;
			m_ani_frame3 = 0;
		}
		if (m_ani_time3 > 2)
		{
			m_ani_frame3 += 1;
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


			//�����Ɖ�b�I��--------
			if (chinatown != nullptr || chinatownboss != nullptr)
			{
				chinamob->SetSp_flag(false);
				chinamob->SetM_sp(0);
			}
			if (hospital != nullptr || hospital2 != nullptr || rooftop != nullptr) {
				hosmob->SetSp_flag(false);
				hosmob->SetM_sp(0);
			}
			if (drug != nullptr) {
				drugmob->SetSp_flag(false);
				drugmob->SetM_sp(0);
			}
			if (inst != nullptr || inst13a != nullptr || instituteboss != nullptr)
			{
				instmob->SetSp_flag(false);
				instmob->SetM_sp(0);
			}
			if (block != nullptr) {
				heroine->SetSp_flag(false);
				heroine->SetM_sp(0);
			}
			//-----------------------------

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
			m_ani_frame4 = 0;
		}
		//-------------------------------------------------------------------

		//----------��l����ړ�(�A�j���[�V����)-----------------------
		if (Input::GetVKey(VK_UP) == true) //��l���ړ��L�[ ��
		{
			m_y -= 5.0f;
			m_vy -= m_y;
			m_ani_frame = 1;
			m_ani_time2 += 1;

			//�����Ɖ�b�I��--------
			if (chinatown != nullptr || chinatownboss != nullptr)
			{
				chinamob->SetSp_flag(false);
				chinamob->SetM_sp(0);
			}
			if (hospital != nullptr || hospital2 != nullptr || rooftop != nullptr) {
				hosmob->SetSp_flag(false);
				hosmob->SetM_sp(0);
			}
			if (drug != nullptr) {
				drugmob->SetSp_flag(false);
				drugmob->SetM_sp(0);
			}
			if (inst != nullptr || inst13a != nullptr || instituteboss != nullptr)
			{
				instmob->SetSp_flag(false);
				instmob->SetM_sp(0);
			}
			if (block != nullptr) {
				heroine->SetSp_flag(false);
				heroine->SetM_sp(0);
			}
			//-----------------------------
		
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
			m_y += 5.0f;
			m_vy += m_y;
			m_ani_frame = 0;
			m_ani_time1 += 1;

			//�����Ɖ�b�I��--------
			if (chinatown != nullptr || chinatownboss != nullptr)
			{
				chinamob->SetSp_flag(false);
				chinamob->SetM_sp(0);
			}
			if (hospital != nullptr || hospital2 != nullptr || rooftop != nullptr) {
				hosmob->SetSp_flag(false);
				hosmob->SetM_sp(0);
			}
			if (drug != nullptr) {
				drugmob->SetSp_flag(false);
				drugmob->SetM_sp(0);
			}
			if (inst != nullptr || inst13a != nullptr || instituteboss != nullptr)
			{
				instmob->SetSp_flag(false);
				instmob->SetM_sp(0);
			}
			if (block != nullptr) {
				heroine->SetSp_flag(false);
				heroine->SetM_sp(0);
			}
			//-----------------------------
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

		//�ړ��x�N�g���̐��K��
		UnitVec(&m_vy, &m_vx);

		//HitBox�̓��e���X�V
		CHitBox* hit = Hits::GetHitBox(this); //�쐬����HitBox�X�V�p�̓���������o��
		hit->SetPos(m_x, m_y);                //���������V�����ʒu(��l���@�̈ʒu)���ɒu��������


		//�G�@�I�u�W�F�N�g�ƐڐG�������l���@�폜
		if (hit->CheckElementHit(ELEMENT_ENEMY) == true)
		{
			Audio::Start(8);
			m_hp -= 25.6;
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
	dst.m_right = 40.0f + m_x;
	dst.m_bottom = 38.0f + m_y;

	Draw::Draw(0, &src, &dst, c, 0.0f);


	//---HP------------------
	//�؂���ʒu�̐ݒ�
	src.m_top = 107.0f;   //y
	src.m_left = 0.0f; //x
	src.m_right = 256.0f; //x
	src.m_bottom = 151.0f; //y

	//�\���ʒu�̐ݒ�
	dst.m_top = 24.0f;
	dst.m_left = 0.0f;
	dst.m_right = 0.0f+m_hp;
	dst.m_bottom = 64.0f;

	Draw::Draw(50, &src, &dst, c, 0.0f);
	//------------------------------------
	//---HP�g------------------
	//�؂���ʒu�̐ݒ�
	src.m_top = 107.0f;   //y
	src.m_left = 256.0f; //x
	src.m_right = 512.0f; //x
	src.m_bottom = 151.0f; //y

	//�\���ʒu�̐ݒ�
	dst.m_top = 24.0f;
	dst.m_left = 0.0f;
	dst.m_right = 0.0f+256.0f;
	dst.m_bottom = 64.0f;

	Draw::Draw(50, &src, &dst, c, 0.0f);
	//------------------------------------
	//---HP��------------------
	//�؂���ʒu�̐ݒ�
	src.m_top = 21.0f;   //y
	src.m_left =9.0f; //x
	src.m_right = 52.0f; //x
	src.m_bottom = 39.0f; //y

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 32.0f;
	dst.m_bottom = 25.0f;

	Draw::Draw(51, &src, &dst, c, 0.0f);
	//------------------------------------

}
