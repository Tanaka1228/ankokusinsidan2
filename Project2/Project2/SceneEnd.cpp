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
CSceneEnd::CSceneEnd()
{

}


//�f�X�g���N�^
CSceneEnd::~CSceneEnd()
{

}

//�Q�[�����C�����������\�b�h
void CSceneEnd::InitScene()
{
	//���y���̓ǂݍ���
	//Audio::LoadAudio(0, L".wav", SOUND_TYPE::BACK_MUSIC);//Loop

	//�o�b�N�~���[�W�b�N�X�^�[�g
	//float v = Audio::VolumeMaster(0);//�}�X�^�[�{�����[����������
	//v = Audio::VolumeMaster(1.0 - v);

	//Audio::Start(0);//���y�X�^�[�g

	//�^�C�g���I�u�W�F�N�g�쐬
	//CObjEnd* obj = new CObjEnd();
	//Objs::InsertObj(obj, OBJ_END, 10);

}

//�Q�[�����C�����s�����\�b�h
void CSceneEnd::Scene()
{

}