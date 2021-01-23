//�g�p����w�b�_�[�t�@�C��
#include"GameL/DrawTexture.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"CObjChinaTownBossBoss.h"
#include"UtilityModule.h"
#include"GameL/Audio.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjChinaTownBossBoss::CObjChinaTownBossBoss(float x, float y)
{
	m_x = x;
	m_y = y;
}


//�C�j�V�����C�Y
void CObjChinaTownBossBoss::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;
	m_time = 0;
	m_timeboss = 0;
	m_hp =7;

	//�@�e�ۂ��G�ɓ��������@���y���̓ǂݍ���
	Audio::LoadAudio(6, L"����.wav", EFFECT);//�P��

	//�����蔻��pHitBox���쐬
	Hits::SetHitBox(this, m_x, m_y, 500, 490, ELEMENT_ENEMY, OBJ_CHINA_TOWN_BOSS_BOSS, 1);
}

//�A�N�V����
void CObjChinaTownBossBoss::Action()
{
	//�`���C�i�^�E���{�X��t�B�[���h�̏��
	CObjChinaTownBoss* chinatownboss = (CObjChinaTownBoss*)Objs::GetObj(OBJ_CHINA_TOWN_BOSS);


	m_timeboss++;
	if (m_timeboss > 50)
	{
		m_timeboss = 0;

		//19����������
		CObjAngleBullet* obj_b;
		for (int i = 0; i < 360; i += 20)
		{
			//�p�xi�Ŋp�x�e�۔���
			obj_b = new CObjAngleBullet(m_x, m_y, i, 5.0f);
			Objs::InsertObj(obj_b, OBJ_ANGLE_BULLET, 4);
		}

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

	hit->SetPos(m_x + chinatownboss->GetScroll(), m_y + chinatownboss->GetScroll2());


	//�z�[�~���O�G�@�����S�ɗ̈�O�ɏo����G�@��j������
	bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 3072.0f, 2752.0f);
	if (check == false)
	{
		this->SetStatus(false);//���g�ɍ폜����
		Hits::DeleteHitBox(this);

		return;
	}

	//�e�ۂƐڐG���Ă邩�ǂ������ׂ�
	if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	{
		Audio::Start(6);
		m_hp -= 1;
	}
	if (m_hp < 0)//HP���O�ɂȂ�����j��
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		Audio::Start(5);
		Sleep(400);
	}
}

//�h���[
void CObjChinaTownBossBoss::Draw()
{
	//�`���C�i�^�E���{�X��t�B�[���h�̏��
	CObjChinaTownBoss* chinatownboss = (CObjChinaTownBoss*)Objs::GetObj(OBJ_CHINA_TOWN_BOSS);

	//�`��J���[���@R=RED G=Green B=Blue A=alpha(���ߏ��)
	float c[4] = { 4.0f,3.0f,3.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f; //y
	src.m_left = 9.0f; //x
	src.m_right = 141.0f; //x
	src.m_bottom = 139.0f; //y

	dst.m_top = 0.0f + m_y + chinatownboss->GetScroll2();
	dst.m_left = 32.0f + 500.0f + m_x + chinatownboss->GetScroll();
	dst.m_right = 0.0f + m_x + chinatownboss->GetScroll();
	dst.m_bottom = 32.0f + 500.0f + m_y + chinatownboss->GetScroll2();

	//0�Ԗڂɓo�^�����O���t�B�b�N��stc�Edst�Ec�̏������ɕ`��
	Draw::Draw(1, &src, &dst, c, 0.0f);
}