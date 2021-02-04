//�g�p����w�b�_�\�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"
#include"GameL\DrawFont.h"
#include"GameL/Audio.h"

#include"GameHead.h"
#include"ObjTitle.h"
#include"GameL/UserData.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjTitle::Init()
{
	 m_key_flag = false;
	 m_y = 345;
	 m_x = 240;
	 m_key_uy = 0.0f;
	 m_key_dy = 0.0f;
	 m_key_enter = false;
	 m_color = 1.0f;
	 color_flag = true;
}

//�A�N�V����
void CObjTitle::Action()
{
	CObjChinaTown* chinatown = (CObjChinaTown*)Objs::GetObj(OBJ_CHINA_TOWN);


	 //���L�[�̈ʒu�擾
	 m_key_uy = (float)Input::GetVKey(VK_UP);
	 m_key_dy = (float)Input::GetVKey(VK_DOWN);
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
		
		 //�G���^�[�L�[�������ꂽ�烁�C���Ɋ҈�
		 if (m_key_enter == true)
		 {
			 Audio::Start(1);
			 Sleep(300);
		    ((UserData*)Save::GetData())->mStage=0;
			Save::Seve();
			 Scene::SetScene(new CSceneChinaEvent());
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

	 if (color_flag == true)
	 {
		 m_color -= 0.02f;

		 if (m_color < 0.4f)
		 {
			 color_flag = false;
		 }
	 }
	 if (color_flag == false)
	 {
		 m_color += 0.02f;

		 if (m_color > 1.0f)
		 {
			 color_flag = true;
		 }
	 }
}

//�h���[
void CObjTitle::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };
	float ca[4] = { 1.0f,1.0f,1.0f,m_color, };
	RECT_F src;
	RECT_F dst;

	//�^�C�g�����̕\��
	Font::StrDraw(L"ARTIFICIAL HUMAN ", 270, 100, 32, c);
	Font::StrDraw(L" �`���l���E�̗��`", 250, 150, 32, c);

	//�J�[�\���I���ʒu
	//main�Ɉڍs
	Font::StrDraw(L"��  �j���[�Q�[��", 250, 350, 32, c);

	////���[�h��ʂɈڍs
	Font::StrDraw(L"��     ���[�h    ", 250, 400, 32, c);
	
	//�ݒ��ʂɈڍs
	Font::StrDraw(L"�� �V���b�g�_�E��", 250, 450, 32, c);
	//

	Font::StrDraw(L"����or���L�[�ŃJ�[�\���ړ� ", 550, 570, 18, c);

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;   //y
	src.m_left = 0.0f;  //x
	src.m_right = 255.0f; //x
	src.m_bottom = 255.0f; //y

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f+m_y;//y
	dst.m_left = 0.0f+m_x;//x
	dst.m_right = 45.0f+m_x;//x
	dst.m_bottom =45.0f+m_y; //y

	//5�Ԗڂɓo�^�����O���t�B�b�N��stc�Edst�Ec�̏������ɕ`��
	Draw::Draw(5, &src, &dst, c, 0.0f);

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;   //y
	src.m_left = 0.0f;  //x
	src.m_right = 128.0f; //x
	src.m_bottom = 64.0f; //y

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f+270.0f;//y
	dst.m_left =0.0f+300.0f;//x
	dst.m_right = 128.0f +300+32.0f;//x
	dst.m_bottom = 64.0f +270.0f; //y

	//5�Ԗڂɓo�^�����O���t�B�b�N��stc�Edst�Ec�̏������ɕ`��
	Draw::Draw(7, &src, &dst, ca, 0.0f);
}