//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL	(0)  
#define _HAS_ITERATOR_DEBUGGING	(0)  

//GameL�Ŏg�p����w�b�_�[
#include"GameL\SceneObjManager.h"
#include"GameL\DrawFont.h"
#include"GameL/DrawTexture.h"
#include"GameL/Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include"SceneMain.h"
#include"GameHead.h"

//�R���X�g���N�^
CSceneTitle::CSceneTitle()
{

}


//�f�X�g���N�^
CSceneTitle::~CSceneTitle()
{

}

//�Q�[�����C�����������\�b�h
void CSceneTitle::InitScene()
{
	//�^�C�g���I�u�W�F�N�g�쐬
	CObjTitle* obj = new CObjTitle();
	Objs::InsertObj(obj, OBJ_TITLE, 10);

	//�O���O���t�B�b�N�t�@�C����ǂݍ���0�Ԃɓo�^(512�~512�s�N�Z��)
	Draw::LoadImage(L"Sifi_town3_4n-480x270.png", 4, TEX_SIZE_512);//title�o�b�N�O���[��
	Draw::LoadImage(L"���j���[��� - �R�s�[ - �R�s�[.png", 6, TEX_SIZE_512);//�J�[�\��	
	Draw::LoadImage(L"���̎q����.png", 5, TEX_SIZE_512);//�J�[�\��	
	
	//���y���̓ǂݍ���
	Audio::LoadAudio(0, L"bgm_maoudamashii_cyber35.wav", SOUND_TYPE::BACK_MUSIC);//Loop

	//�o�b�N�~���[�W�b�N�X�^�[�g
	float Volume = Audio::VolumeMaster(-0.8f);//�}�X�^�[�{�����[����������
	Audio::Start(0);//���y�X�^�[�g

	//�I�u�W�F�N�g�쐬
	CObjTitleBackground* back = new CObjTitleBackground();
	Objs::InsertObj(back, OBJ_TITLE_BACKGROUND, 4), (back, OBJ_TITLE_BACKGROUND, 6),(back, OBJ_TITLE_BACKGROUND, 5);

}

//�Q�[�����C�����s�����\�b�h
void CSceneTitle::Scene()
{

}