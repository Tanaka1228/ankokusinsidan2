//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCR (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include"GameL\DrawTexture.h"
#include"GameL\SceneObjManager.h"
#include"GameL\UserData.h"
#include"GameL/WinInputs.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include"SceneMain.h"
#include"GameHead.h"



//�R���X�g���N�^
CSceneMain::CSceneMain()
{

}

//�f�X�g���N�^
CSceneMain::~CSceneMain()
{

}

//�Q�[�����C�����������\�b�h
void CSceneMain::InitScene()
{

	//�O���O���t�B�b�N�t�@�C����ǂݍ���0�Ԃɓo�^(512�~512�s�N�Z��)���܂�֌W�Ȃ��炵��
	//Draw::LoadImage(L"Hero.png", 0, TEX_SIZE_512);//��l���O���t�B�b�N

	//�O���O���t�B�b�N�t�@�C����ǂݍ���1�Ԃɓo�^(512�~512�s�N�Z��)���܂�֌W�Ȃ��炵��
	Draw::LoadImage(L"Enemy1.png", 1, TEX_SIZE_512);//�G�O���t�B�b�N

	//�O���O���t�B�b�N�t�@�C����ǂݍ���1�Ԃɓo�^(512�~512�s�N�Z��)���܂�֌W�Ȃ��炵��
	//Draw::LoadImage(L"�n���h�K��.png", 2, TEX_SIZE_512);//�n���h�K���O���t�B�b�N

	//�O���O���t�B�b�N�t�@�C����ǂݍ���3�Ԃɓo�^(512�~512�s�N�Z��)���܂�֌W�Ȃ��炵��
	//Draw::LoadImage(L"�e�ہQ�E.png", 3, TEX_SIZE_512);//�e�ۃO���t�B�b�N

	//�O���O���t�B�b�N�t�@�C����ǂݍ���8�Ԃɓo�^(512�~512�s�N�Z��)���܂�֌W�Ȃ��炵��
	//Draw::LoadImage(L"���_�̑f��.png", 8, TEX_SIZE_512);

	//�O���O���t�B�b�N�t�@�C����ǂݍ���11�Ԃɓo�^(512�~512�s�N�Z��)���܂�֌W�Ȃ��炵��
	//Draw::LoadImage(L"���j���[���.png", 11, TEX_SIZE_512);

		//�O���O���t�B�b�N�t�@�C����ǂݍ���12�Ԃɓo�^(512�~512�s�N�Z��)���܂�֌W�Ȃ��炵��
	//Draw::LoadImage(L"�������̃{�X��t�B�[���h.png", 12, TEX_SIZE_512);

	//��l���I�u�W�F�N�g�쐬
	//CObjHero* obj = new CObjHero(400,280); //��l���I�u�W�F�N�g�쐬
	///Objs::InsertObj(obj, OBJ_HERO, 2); //�������l���I�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^

	//�G�@�I�u�W�F�N�g�쐬
	//CObjEnemy* obj_enemy = new CObjEnemy(); //�G�@�I�u�W�F�N�g�쐬
	//Objs::InsertObj(obj_enemy, OBJ_ENEMY, 3); //������G�@�I�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^

	//block�I�u�W�F�N�g�쐬
	//CObjBlock* objb = new CObjBlock();
	//Objs::InsertObj(objb, OBJ_BLOCK, 1);

	

	//�^�C��������
	m_time = 0;
	
	CObjMain* p = new CObjMain();
	Objs::InsertObj(p, OBJ_MAIN,1);

}

//�Q�[�����C�����s�����\�b�h
void CSceneMain::Scene()
{
	//m_time++;

	//if (m_time == 100)
	//{
	//	//Sin�G�@�I�u�W�F�N�g�쐬
	//	CObjSinEnemy* obj_sin_enemy = new CObjSinEnemy(700, 300); //Sin�G�@�I�u�W�F�N�g�쐬
	//	Objs::InsertObj(obj_sin_enemy, OBJ_SIN_ENEMY, 3); //Sin�G�@�I�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^
	//}
	//else if (m_time == 150)
	//{
	//	//Sin�G�@�I�u�W�F�N�g�쐬
	//	CObjSinEnemy* obj_sin_enemy = new CObjSinEnemy(700, 300); //Sin�G�@�I�u�W�F�N�g�쐬
	//	Objs::InsertObj(obj_sin_enemy, OBJ_SIN_ENEMY, 3); //Sin�G�@�I�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^
	//}
	//else if (m_time == 200)
	//{
	//	//�U������G�@�I�u�W�F�N�g�쐬
	//	CObjAttackEnemy* obj_attack_enemy = new CObjAttackEnemy(700, 220); //�U������G�@�I�u�W�F�N�g�쐬
	//	Objs::InsertObj(obj_attack_enemy, OBJ_ATTACK_ENEMY, 3); //�U������G�@�I�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^
	//}
	//else if (m_time == 300)
	//{
	//	//�g�U�G�@�I�u�W�F�N�g�쐬
	//	CObjDiffusionEnemy* obj_diffusion_enemy = new CObjDiffusionEnemy(700, 300); //Sin�G�@�I�u�W�F�N�g�쐬
	//	Objs::InsertObj(obj_diffusion_enemy, OBJ_DIFFUSION_ENEMY, 3); //Sin�G�@�I�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^
	//}
	//else if (m_time == 400)
	//{
	//	//�U���G�@�I�u�W�F�N�g�쐬
	//	CObjHomingEnemy* obj_homing_enemy = new CObjHomingEnemy(100, 50); //�U���G�@�I�u�W�F�N�g�쐬
	//	Objs::InsertObj(obj_homing_enemy, OBJ_HOMING_ENEMY, 3); //�U���G�@�I�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^
	//}
	//
	//if (Input::GetVKey('X') == true)
	//{
	//	//���j���[�I�u�W�F�N�g�쐬
	//	CObjMenu* obj_menu = new CObjMenu(); //���j���[�I�u�W�F�N�g�쐬
	//	Objs::InsertObj(obj_menu, OBJ_HOMING_ENEMY, 14); //���j���[�I�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^
	//}
}