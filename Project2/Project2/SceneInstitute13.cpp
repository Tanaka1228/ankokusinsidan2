//STL�̃f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0);
#define _HAS_ITERATOR_DEBUGGING (0);

//GameL�Ŏg�p����w�b�_�[
#include"GameL\SceneObjManager.h"
#include"GameL\DrawFont.h"
#include"GameL/DrawTexture.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p����w�b�_�[
#include"GameHead.h"
#include"ObjInstitute13.h"



//�R���X�g���N�^
CSceneInstitute13::CSceneInstitute13()
{
}

//�f�X�g���N�^
CSceneInstitute13::~CSceneInstitute13()
{
}



//�Q�[���X�e�[�W���������\�b�h
void CSceneInstitute13::InitScene()
{
	//�O���O���t�B�b�N�t�@�C����ǂݍ���0�Ԃɓo�^(512�~512�s�N�Z��)���܂�֌W�Ȃ��炵��
	Draw::LoadImage(L"Hero.png", 0, TEX_SIZE_512);//��l���O���t�B�b�N

	//�O���O���t�B�b�N�t�@�C����ǂݍ���1�Ԃɓo�^(512�~512�s�N�Z��)���܂�֌W�Ȃ��炵��
	Draw::LoadImage(L"�n���h�K��.png", 2, TEX_SIZE_512);//�n���h�K���O���t�B�b�N

	//�O���O���t�B�b�N�t�@�C����ǂݍ���3�Ԃɓo�^(512�~512�s�N�Z��)���܂�֌W�Ȃ��炵��
	Draw::LoadImage(L"�e�ہQ�E.png", 3, TEX_SIZE_512);//�e�ۃO���t�B�b�N

	//�O���O���t�B�b�N�t�@�C����ǂݍ���5�Ԃɓo�^(512�~512�s�N�Z��)���܂�֌W�Ȃ��炵��
	Draw::LoadImage(L"�������n������.png", 5, TEX_SIZE_512);//�e�ۃO���t�B�b�N//�O���O���t�B�b�N�t�@�C����ǂݍ���5�Ԃɓo�^(512�~512�s�N�Z��)���܂�֌W�Ȃ��炵��

	//�O���O���t�B�b�N�t�@�C����ǂݍ���10�Ԃɓo�^(512�~512�s�N�Z��)���܂�֌W�Ȃ��炵��
	Draw::LoadImageW(L"���폤�����{�b�g.png", 6, TEX_SIZE_512);

	//�O���O���t�B�b�N�t�@�C����ǂݍ���6�Ԃɓo�^(512�~512�s�N�Z��)���܂�֌W�Ȃ��炵��
	Draw::LoadImage(L"��������.png", 30, TEX_SIZE_512);//�e�ۃO���t�B�b�N//�O���O���t�B�b�N�t�@�C����ǂݍ���5�Ԃɓo�^(512�~512�s�N�Z��)���܂�֌W�Ȃ��炵��

		//�O���O���t�B�b�N�t�@�C����ǂݍ���6�Ԃɓo�^(512�~512�s�N�Z��)���܂�֌W�Ȃ��炵��
	Draw::LoadImage(L"�������n���Q�K.png", 8, TEX_SIZE_512);//�e�ۃO���t�B�b�N//�O���O���t�B�b�N�t�@�C����ǂݍ���5�Ԃɓo�^(512�~512�s�N�Z��)���܂�֌W�Ȃ��炵��

	//���u�I�u�W�F�N�g�ǉ�
	CObjInstMob* objinstmob = new CObjInstMob();//���u
	Objs::InsertObj(objinstmob, OBJ_INST_MOB, 6);

	//��l���I�u�W�F�N�g�쐬
	CObjHero* obj = new CObjHero(400, 280); //��l���I�u�W�F�N�g�쐬
	Objs::InsertObj(obj, OBJ_HERO, 5); //�������l���I�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^

	//�e�I�u�W�F�N�g�쐬
	CObjGun* objg = new CObjGun();
	Objs::InsertObj(objg, OBJ_GUN, 6);

	//�������I�u�W�F�N�g�쐬
	CObjInstitute13* obji = new CObjInstitute13(); //�������I�u�W�F�N�g�쐬
	Objs::InsertObj(obji, OBJ_INSTITUTE13, 4); //������������I�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^

		//�}�b�v�}
	CObjMap* objm = new CObjMap();//�}�b�v�}
	Objs::InsertObj(objm, OBJ_MAP, 6);
}


//�Q�[���X�e�[�W���s�����\�b�h
void CSceneInstitute13::Scene()
{
}