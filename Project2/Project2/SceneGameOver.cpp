//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECHURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include"GameL\SceneObjManager.h"
#include"GameL\DrawFont.h"
#include"GameL/Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include"SceneGameOver.h"
#include"GameHead.h"

//�R���X�g���N�^
CSceneGameOver::CSceneGameOver()
{

}

//�f�X�g���N�^
CSceneGameOver::~CSceneGameOver()
{

}

//�Q�[�����C�����������\�b�h
void CSceneGameOver::InitScene()
{
	//�O���O���t�B�b�N�t�@�C����ǂݍ���0�Ԃɓo�^(512�~512�s�N�Z��)
	Draw::LoadImage(L"Sifi_town3_4n-480x270.png", 4, TEX_SIZE_512);//title�o�b�N�O���[��
	Draw::LoadImage(L"���j���[��� - �R�s�[ - �R�s�[.png", 6, TEX_SIZE_512);//�J�[�\��	
	Draw::LoadImage(L"Hero.png", 5, TEX_SIZE_512);//�J�[�\��	

	//���y���̓ǂݍ���
	Audio::LoadAudio(0, L".game_maoudamashii_7_event30.wav", SOUND_TYPE::BACK_MUSIC);//Loop

	//�@�I���@���y���̓ǂݍ���
	Audio::LoadAudio(1, L"����.wav", EFFECT);//�P��

	//�o�b�N�~���[�W�b�N�X�^�[�g
	float v = Audio::VolumeMaster(0);//�}�X�^�[�{�����[����������
	v = Audio::VolumeMaster(0.4 - v);

	//Audio::Start(0);//���y�X�^�[�g

	//�Q�[���I�[�o�[�I�u�W�F�N�g�쐬
	CObjGameOver* obj = new CObjGameOver();
	Objs::InsertObj(obj, OBJ_GAME_OVER, 1);
}

//���s�����\�b�h
void CSceneGameOver::Scene()
{
	
}
