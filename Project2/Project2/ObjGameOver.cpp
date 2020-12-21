// �g�p����w�b�_�\�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"
#include"GameL/Audio.h"
#include"GameL/UserData.h"

#include"GameHead.h"
#include"ObjGameOver.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjGameOver::Init()
{
	 m_key_flag=false;//�L�[�t���O

	 m_y = 345;
	 m_x = 240;
	 m_key_uy = 0.0f;
	 m_key_dy = 0.0f;
	 m_key_enter = false;
}

//�A�N�V����
void CObjGameOver::Action()
{ 
	
	//���L�[�̃{�^���̏��
	m_key_enter = Input::GetVKey(VK_RETURN);

	if (Input::GetVKey(VK_UP) == true)//�J�[�\���̈ړ�
	{
		m_y -= 6.0f;
	}
	else if (Input::GetVKey(VK_DOWN) == true)
	{
		m_y += 6.0f;
	}

	if (m_y < 349)//�J�[�\������
	{
		m_y = 349;
	}
	if (m_y > 450)
	{
		m_y = 450;
	}

	//�J�[�\���̈ʒu�ƃv�b�V������ꏊ�œ����蔻��
	if (m_x > 200 && m_x < 550 && m_y>330 && m_y < 360)
	{

		//�G���^�[�L�[�������ꂽ��^�C�g���Ɋ҈�
		if (m_key_enter == true)
		{
			Audio::Start(1);
			Sleep(300);
			Scene::SetScene(new CSceneTitle());
		}
	}

	//���[�h
	if (m_x > 200 && m_x < 550 && m_y>370 && m_y < 430)
	{
		//�G���^�[�L�[�������ꂽ�烍�[�h�Ɋ҈�
		if (m_key_enter == true)
		{
			Save::Open();
			if (((UserData*)Save::GetData())->mStage == 0)//���_�j���[�Q�[��
			{
				Audio::Start(1);
				Sleep(300);
				Scene::SetScene(new CSceneChinaEvent());
			}
			if (((UserData*)Save::GetData())->mStage == 1)//�`���C�i�^�E��
			{
				Audio::Start(1);
				Sleep(300);
				Scene::SetScene(new CSceneChinaTown());
			}
			if (((UserData*)Save::GetData())->mStage == 2)//�a�@1�K
			{
				Audio::Start(1);
				Sleep(300);
				Scene::SetScene(new CSceneHospital());
			}
			if (((UserData*)Save::GetData())->mStage == 3)//�����Ј�K
			{
				Audio::Start(1);
				Sleep(300);
				Scene::SetScene(new CSceneDrugCampany());
			}
			if (((UserData*)Save::GetData())->mStage == 8)//������
			{
				Audio::Start(1);
				Sleep(300);
				Scene::SetScene(new CSceneInstitute());
			}
		}
	}

	if (m_x > 200 && m_x < 550 && m_y>440 && m_y < 470)
	{
		//�G���^�[�L�[�������ꂽ��V���b�g�_�E���Ɋ҈�
		if (m_key_enter == true)
		{
			Audio::Start(1);
			Sleep(300);
			Scene::SetScene(nullptr);
		}
	}


	//�G���^�[�L�[�������ăV�[���F�Q�[��Title�Ɉڍs����
	/*if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneTitle());
			m_key_flag = false;
		}
		
	}
	else
	{
		m_key_flag = true;
	}*/
}

//�h���[
void CObjGameOver::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };
	RECT_F src;
	RECT_F dst;

	Font::StrDraw(L"GAME OVER",340,250,32,c);

	//main�Ɉڍs
	Font::StrDraw(L"��    �^�C�g�� ", 250, 350, 32, c);

	////���[�h��ʂɈڍs
	Font::StrDraw(L"��     ���[�h    ", 250, 400, 32, c);

	//�ݒ��ʂɈڍs
	Font::StrDraw(L"�� �V���b�g�_�E��", 250, 450, 32, c);



	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;   //y
	src.m_left = 0.0f;  //x
	src.m_right = 32.0f; //x
	src.m_bottom = 32.0f; //y

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_y;//y
	dst.m_left = 7.0f + m_x;//x
	dst.m_right = 52.0f + m_x;//x
	dst.m_bottom = 45.0f + m_y; //y

	//5�Ԗڂɓo�^�����O���t�B�b�N��stc�Edst�Ec�̏������ɕ`��
	Draw::Draw(5, &src, &dst, c, 0.0f);
}