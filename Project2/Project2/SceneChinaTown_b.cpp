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
#include"GameHead.h"
#include "SceneChinaTown_b.h"



//�R���X�g���N�^
CSceneChinaTown_b::CSceneChinaTown_b()
{
}

//�f�X�g���N�^
CSceneChinaTown_b::~CSceneChinaTown_b()
{
}



//�Q�[���X�e�[�W���������\�b�h
void CSceneChinaTown_b::InitScene()
{
	//�O���O���t�B�b�N�t�@�C����ǂݍ���0�Ԃɓo�^(512�~512�s�N�Z��)���܂�֌W�Ȃ��炵��
	Draw::LoadImage(L"Hero.png", 0, TEX_SIZE_512);//��l���O���t�B�b�N

	//�O���O���t�B�b�N�t�@�C����ǂݍ���1�Ԃɓo�^(512�~512�s�N�Z��)���܂�֌W�Ȃ��炵��
	Draw::LoadImage(L"Enemy1.png", 1, TEX_SIZE_512);//�G�O���t�B�b�N

	//�O���O���t�B�b�N�t�@�C����ǂݍ���1�Ԃɓo�^(512�~512�s�N�Z��)���܂�֌W�Ȃ��炵��
	Draw::LoadImage(L"�n���h�K��.png", 2, TEX_SIZE_512);//�n���h�K���O���t�B�b�N

	//�O���O���t�B�b�N�t�@�C����ǂݍ���3�Ԃɓo�^(512�~512�s�N�Z��)���܂�֌W�Ȃ��炵��
	Draw::LoadImage(L"�e�ہQ�E.png", 3, TEX_SIZE_512);//�e�ۃO���t�B�b�N

	//�O���O���t�B�b�N�t�@�C����ǂݍ���4�Ԃɓo�^(512�~512�s�N�Z��)���܂�֌W�Ȃ��炵��
	Draw::LoadImage(L"�`���C�i�^�E��.png", 4, TEX_SIZE_512);

	//�O���O���t�B�b�N�t�@�C����ǂݍ���16�Ԃɓo�^(512�~512�s�N�Z��)���܂�֌W�Ȃ��炵��
	Draw::LoadImage(L"�`���C�i�^�E���̃{�X��t�B�[���h.png", 16, TEX_SIZE_512);

	//�O���O���t�B�b�N�t�@�C����ǂݍ���17�Ԃɓo�^(512�~512�s�N�Z��)���܂�֌W�Ȃ��炵��
	Draw::LoadImage(L"�`���C�i�^�E���{�X��t�B�[���h�̑f��.png", 17, TEX_SIZE_512);

	//�O���O���t�B�b�N�t�@�C����ǂݍ���3�Ԃɓo�^(512�~512�s�N�Z��)���܂�֌W�Ȃ��炵��
	Draw::LoadImage(L"�Ŕ�.png", 5, TEX_SIZE_512);//�O���t�B�b�N

	//�O���O���t�B�b�N�t�@�C����ǂݍ���10�Ԃɓo�^(512�~512�s�N�Z��)���܂�֌W�Ȃ��炵��
	Draw::LoadImage(L"���폤�����{�b�g.png", 6, TEX_SIZE_512);


	//�O���O���t�B�b�N�t�@�C����ǂݍ���10�Ԃɓo�^(512�~512�s�N�Z��)���܂�֌W�Ȃ��炵��
	Draw::LoadImage(L"��b.png", 8, TEX_SIZE_512);

	//�O���O���t�B�b�N�t�@�C����ǂݍ���13�Ԃɓo�^(512�~512�s�N�Z��)���܂�֌W�Ȃ��炵��
	Draw::LoadImage(L"�a�@�̉���̑f��.png", 7, TEX_SIZE_512);

	//�O���O���t�B�b�N�t�@�C����ǂݍ���5�Ԃɓo�^(512�~512�s�N�Z��)���܂�֌W�Ȃ��炵��
	Draw::LoadImage(L"�}�b�vb.png", 18, TEX_SIZE_512);

	//�@�e�@���y���̓ǂݍ���
	Audio::LoadAudio(1, L"se_maoudamashii_battle_gun01.wav", EFFECT);//�P��

	//���y���̓ǂݍ���
	Audio::LoadAudio(0, L"game_maoudamashii_7_event23.wav", SOUND_TYPE::BACK_MUSIC);//Loop

	//�@�G�����@���y���̓ǂݍ���
	Audio::LoadAudio(5, L"se_maoudamashii_explosion05.wav", EFFECT);//�P��

	//�o�b�N�~���[�W�b�N�X�^�[�g
	float v = Audio::VolumeMaster(0);//�}�X�^�[�{�����[����������
	v = Audio::VolumeMaster(0.9f - v);

	Audio::Start(0);//���y�X�^�[�g

	//��l���I�u�W�F�N�g�쐬
	CObjHero* obj = new CObjHero(400, 280); //��l���I�u�W�F�N�g�쐬
	Objs::InsertObj(obj, OBJ_HERO, 3); //�������l���I�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^

	//���u�I�u�W�F�N�g�ǉ�
	CObjChinaMob* objchinamob = new CObjChinaMob();//���u
	Objs::InsertObj(objchinamob, OBJ_CHINA_MOB, 6);

	//�`���C�i�^�E���I�u�W�F�N�g�쐬
	CObjChinaTown_b* objc = new CObjChinaTown_b(); //�`���C�i�^�E���I�u�W�F�N�g�쐬
	Objs::InsertObj(objc, OBJ_CHINA_TOWN_B, 1); //������`���C�i�^�E���I�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^

	//�e�I�u�W�F�N�g�쐬
	CObjGun* objg = new CObjGun();
	Objs::InsertObj(objg, OBJ_GUN, 4);

	//��b�̔w�i�I�u�W�F�N�g�쐬
	CObjSpBack* objsp = new CObjSpBack(); //��b�̔w�i�쐬
	Objs::InsertObj(objsp, OBJ_SP_BACK, 5); //�������b�̔w�i�I�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^

	CObjMap* objm = new CObjMap();//�}�b�v�}
	Objs::InsertObj(objm, OBJ_MAP, 7);
}


//�Q�[���X�e�[�W���s�����\�b�h
void CSceneChinaTown_b::Scene()
{
}