//STL�̃f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0);
#define _HAS_ITERATOR_DEBUGGING (0);

//GameL�Ŏg�p����w�b�_�[
#include"GameL\SceneObjManager.h"
#include"GameL\DrawFont.h"
#include"GameL/DrawTexture.h"
#include"GameL/Audio.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p����w�b�_�[
#include "GameHead.h"
#include "SceneChinaTownBoss.h"



//�R���X�g���N�^
CSceneChinaTownBoss::CSceneChinaTownBoss()
{

}

//�f�X�g���N�^
CSceneChinaTownBoss::~CSceneChinaTownBoss()
{
}



//�Q�[���X�e�[�W���������\�b�h
void CSceneChinaTownBoss::InitScene()
{
	//�O���O���t�B�b�N�t�@�C����ǂݍ���0�Ԃɓo�^(512�~512�s�N�Z��)���܂�֌W�Ȃ��炵��
	Draw::LoadImage(L"Hero.png", 0, TEX_SIZE_512);//��l���O���t�B�b�N

	//�O���O���t�B�b�N�t�@�C����ǂݍ���1�Ԃɓo�^(512�~512�s�N�Z��)���܂�֌W�Ȃ��炵��
	Draw::LoadImage(L"Enemy1.png", 1, TEX_SIZE_512);//�G�O���t�B�b�N

	//�O���O���t�B�b�N�t�@�C����ǂݍ���1�Ԃɓo�^(512�~512�s�N�Z��)���܂�֌W�Ȃ��炵��
	Draw::LoadImage(L"�n���h�K��.png", 2, TEX_SIZE_512);//�n���h�K���O���t�B�b�N

	//�O���O���t�B�b�N�t�@�C����ǂݍ���3�Ԃɓo�^(512�~512�s�N�Z��)���܂�֌W�Ȃ��炵��
	Draw::LoadImage(L"�e�ہQ�E.png", 3, TEX_SIZE_512);//�e�ۃO���t�B�b�N


	//�O���O���t�B�b�N�t�@�C����ǂݍ���10�Ԃɓo�^(512�~512�s�N�Z��)���܂�֌W�Ȃ��炵��
	Draw::LoadImage(L"���폤�����{�b�g.png", 6, TEX_SIZE_512);

	//�O���O���t�B�b�N�t�@�C����ǂݍ���7�Ԃɓo�^(512�~512�s�N�Z��)���܂�֌W�Ȃ��炵��
	Draw::LoadImage(L"�`���C�i�^�E���{�X��t�B�[���h�̃}�b�v.png", 7, TEX_SIZE_512);//�e�ۃO���t�B�b�N

	//�O���O���t�B�b�N�t�@�C����ǂݍ���10�Ԃɓo�^(512�~512�s�N�Z��)���܂�֌W�Ȃ��炵��
	Draw::LoadImage(L"��b.png", 8, TEX_SIZE_512);


	//�O���O���t�B�b�N�t�@�C����ǂݍ���5�Ԃɓo�^(512�~512�s�N�Z��)���܂�֌W�Ȃ��炵��
	Draw::LoadImage(L"�e�ۃA�C�e��.png", 12, TEX_SIZE_512);

	//�O���O���t�B�b�N�t�@�C����ǂݍ���16�Ԃɓo�^(512�~512�s�N�Z��)���܂�֌W�Ȃ��炵��
	Draw::LoadImage(L"�`���C�i�^�E���̃{�X��t�B�[���h.png",16 , TEX_SIZE_512);

	//�O���O���t�B�b�N�t�@�C����ǂݍ���17�Ԃɓo�^(512�~512�s�N�Z��)���܂�֌W�Ȃ��炵��
	Draw::LoadImage(L"�`���C�i�^�E���{�X��t�B�[���h�̑f��.png", 17, TEX_SIZE_512);

	//�O���O���t�B�b�N�t�@�C����ǂݍ���5�Ԃɓo�^(512�~512�s�N�Z��)���܂�֌W�Ȃ��炵��
	Draw::LoadImage(L"�������̃}�b�v.png", 15, TEX_SIZE_512);

	//�@�e�@���y���̓ǂݍ���
	Audio::LoadAudio(1, L"se_maoudamashii_battle_gun01.wav", EFFECT);//�P��

	//�@�G�����@���y���̓ǂݍ���
	Audio::LoadAudio(5, L"se_maoudamashii_explosion05.wav", EFFECT);//�P��

	//���y���̓ǂݍ���
	Audio::LoadAudio(0, L"game_maoudamashii_1_battle23.wav", SOUND_TYPE::BACK_MUSIC);//Loop

	//�o�b�N�~���[�W�b�N�X�^�[�g
	float v = Audio::VolumeMaster(0);//�}�X�^�[�{�����[����������
	v = Audio::VolumeMaster(1.7 - v);

	Audio::Start(0);//���y�X�^�[�g

	//��l���I�u�W�F�N�g�쐬
	CObjHero* obj = new CObjHero(400, 280); //��l���I�u�W�F�N�g�쐬
	Objs::InsertObj(obj, OBJ_HERO, 7); //�������l���I�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^

	//�}�b�v�}
	CObjMap* objma = new CObjMap();//�}�b�v�}
	Objs::InsertObj(objma, OBJ_MAP, 5);

	//�`���C�i�^�E���̃{�X��t�B�[���h�I�u�W�F�N�g�쐬
	CObjChinaTownBoss* objb = new CObjChinaTownBoss();
	Objs::InsertObj(objb, OBJ_CHINA_TOWN_BOSS, 3);

	//�e�I�u�W�F�N�g�쐬
	CObjGun* objg = new CObjGun();
	Objs::InsertObj(objg, OBJ_GUN, 8);

	//�`���C�i�^�E���I�u�W�F�N�g�쐬
	CObjChinaMob* objm = new CObjChinaMob(); //�`���C�i�^�E�����u�I�u�W�F�N�g�쐬
	Objs::InsertObj(objm, OBJ_CHINA_MOB, 6); //������`���C�i�^�E���I�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^

	//��b�̔w�i�I�u�W�F�N�g�쐬
	CObjSpBack* objsp = new CObjSpBack(); //��b�̔w�i�쐬
	Objs::InsertObj(objsp, OBJ_SP_BACK, 5); //�������b�̔w�i�I�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^

	//�^�C��������
	m_time = 0;
}


//�Q�[���X�e�[�W���s�����\�b�h
void CSceneChinaTownBoss::Scene()
{
	CObjChinaTownBoss* chinaboss = (CObjChinaTownBoss*)Objs::GetObj(OBJ_CHINA_TOWN_BOSS);

	m_time++;
	//if (m_time == 5)
	//{
	//	//Item�I�u�W�F�N�g�쐬
	//	CObjItem* objitem = new CObjItem(3000.0f + chinaboss->GetScroll(), 100.0f + chinaboss->GetScroll2());//�A�C�e��
	//	Objs::InsertObj(objitem, OBJ_ITEM, 5);
	//}

	if (m_time == 50)
	{
		//�U���G�@�I�u�W�F�N�g�쐬
		CObjChinaTownBossBoss* objc = new CObjChinaTownBossBoss(2300.0f + chinaboss->GetScroll(), 1300.0f + chinaboss->GetScroll2()); //�U���G�@�I�u�W�F�N�g�쐬
		Objs::InsertObj(objc, OBJ_CHINA_TOWN_BOSS_BOSS, 5); //�U���G�@�I�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^

	}
	if (m_time == 51)
	{
		//�U���G�@�I�u�W�F�N�g�쐬
		CObjChinaAtkEnemy* obja = new CObjChinaAtkEnemy(2900.0f + chinaboss->GetScroll(), 2100.0f + chinaboss->GetScroll2()); //�G�@�I�u�W�F�N�g�쐬
		Objs::InsertObj(obja, OBJ_CHINA_ATK_ENEMY, 6); //�G�@�I�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^
	}
	if (m_time == 52)
	{
		//�U���G�@�I�u�W�F�N�g�쐬
		CObjChinaAtkEnemy2* obja2 = new CObjChinaAtkEnemy2(2200.0f + chinaboss->GetScroll(), 2100.0f + chinaboss->GetScroll2()); //�G�@�I�u�W�F�N�g�쐬
		Objs::InsertObj(obja2, OBJ_CHINA_ATK_ENEMY2, 7); //�G�@�I�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^

	}
}
