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
#include "SceneBlock.h"



//�R���X�g���N�^
CSceneBlock::CSceneBlock()
{
}

//�f�X�g���N�^
CSceneBlock::~CSceneBlock()
{
}



//�Q�[���X�e�[�W���������\�b�h
void CSceneBlock::InitScene()
{
	//���y���̓ǂݍ���
	Audio::LoadAudio(0, L"bgm_maoudamashii_ethnic23 (online-audio-converter.com).wav",BACK_MUSIC);//Loop

	//�o�b�N�~���[�W�b�N�X�^�[�g
	float v = Audio::VolumeMaster(1.5f);//�}�X�^�[�{�����[����������

	Audio::Start(0);//���y�X�^�[�g

	//�O���O���t�B�b�N�t�@�C����ǂݍ���0�Ԃɓo�^(512�~512�s�N�Z��)���܂�֌W�Ȃ��炵��
	Draw::LoadImage(L"Hero.png", 0, TEX_SIZE_512);//��l���O���t�B�b�N

	//�O���O���t�B�b�N�t�@�C����ǂݍ���1�Ԃɓo�^(512�~512�s�N�Z��)���܂�֌W�Ȃ��炵��
	Draw::LoadImage(L"�n���h�K��.png", 2, TEX_SIZE_512);//�n���h�K���O���t�B�b�N

	//�O���O���t�B�b�N�t�@�C����ǂݍ���3�Ԃɓo�^(512�~512�s�N�Z��)���܂�֌W�Ȃ��炵��
	Draw::LoadImage(L"�e�ہQ�E.png", 3, TEX_SIZE_512);//�e�ۃO���t�B�b�N

	//�O���O���t�B�b�N�t�@�C����ǂݍ���3�Ԃɓo�^(512�~512�s�N�Z��)���܂�֌W�Ȃ��炵��
	Draw::LoadImage(L"���̎q����.png", 5, TEX_SIZE_512);//���̎q

	//�O���O���t�B�b�N�t�@�C����ǂݍ���8�Ԃɓo�^(512�~512�s�N�Z��)���܂�֌W�Ȃ��炵��
	Draw::LoadImage(L"���_�̑f��.png", 8, TEX_SIZE_512);

	//�O���O���t�B�b�N�t�@�C����ǂݍ���9�Ԃɓo�^(512�~512�s�N�Z��)���܂�֌W�Ȃ��炵��
	Draw::LoadImage(L"��.png", 9, TEX_SIZE_512);

	//�O���O���t�B�b�N�t�@�C����ǂݍ���10�Ԃɓo�^(512�~512�s�N�Z��)���܂�֌W�Ȃ��炵��
	Draw::LoadImage(L"��b.png", 10, TEX_SIZE_512);

	//�O���O���t�B�b�N�t�@�C����ǂݍ���10�Ԃɓo�^(512�~512�s�N�Z��)���܂�֌W�Ȃ��炵��
	Draw::LoadImage(L"���폤�����{�b�g.png", 11, TEX_SIZE_512);

	//�O���O���t�B�b�N�t�@�C����ǂݍ���5�Ԃɓo�^(512�~512�s�N�Z��)���܂�֌W�Ȃ��炵��
	Draw::LoadImage(L"���_�̃}�b�v.png", 15, TEX_SIZE_512);

	//��l���I�u�W�F�N�g�쐬
	CObjHero* obj = new CObjHero(400, 280); //��l���I�u�W�F�N�g�쐬
	Objs::InsertObj(obj, OBJ_HERO, 4); //�������l���I�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^

	//block�I�u�W�F�N�g�쐬
	CObjBlock* objb = new CObjBlock();
	Objs::InsertObj(objb, OBJ_BLOCK, 3);

	//�q���C���I�u�W�F�N�g�쐬
	CObjHeroine* objh=new CObjHeroine();
	Objs::InsertObj(objh, OBJ_HEROINE, 6);

	//�e�I�u�W�F�N�g�쐬
	CObjGun* objg = new CObjGun();
	Objs::InsertObj(objg, OBJ_GUN, 5);

	//��b�̔w�i�I�u�W�F�N�g�쐬
	CObjSpBack* objsp = new CObjSpBack(); //��b�̔w�i�쐬
	Objs::InsertObj(objsp, OBJ_SP_BACK, 5); //�������b�̔w�i�I�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^

	CObjMap* objm = new CObjMap();//�}�b�v�}
	Objs::InsertObj(objm, OBJ_MAP, 7);

}


//�Q�[���X�e�[�W���s�����\�b�h
void CSceneBlock::Scene()
{
}
