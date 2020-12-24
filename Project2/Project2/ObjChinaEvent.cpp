

//�g�p����w�b�_�[�t�@�C��
#include"GameL/DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameL/DrawFont.h"
#include"GameL/WinInputs.h"

#include"GameHead.h"
#include"ObjChinaEvent.h"
#include"UtilityModule.h"
#include<fstream>


//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjChinaEvent::CObjChinaEvent()
{
	//Heroine�̃w�b�_�[��������킩��
	m_sp = false;
	key_flag = 1;
	sp_flag = false;
	m_key_control = true;
	mob_flag = 0;
	m_time = 0;
}


//�C�j�V�����C�Y
void CObjChinaEvent::Init()
{

}

//�A�N�V����
void CObjChinaEvent::Action()
{
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	//�`���C�i�^�E���̃C�x���g���
	CObjChinaEvent* chinaevent = (CObjChinaEvent*)Objs::GetObj(OBJ_CHINA_EVENT);

	int minute;//��
	int second;//�b

	m_time++;

	second = (m_time / 60) % 60;//�b
	minute = (m_time / 60) / 60;//��

	//-------------�`���C�i�^�E���̃C�x���g------------------
	if (chinaevent!= nullptr)
	{
		if (second == 1)//�b����
		{

			if (key_flag == 1)
			{
				m_sp = 1;
				sp_flag = true;

			}
		}
		if (second == 3)//�b����
		{

			if (key_flag == 2)
			{
				m_sp = 2;
				sp_flag = true;

			}
		}
		if (second == 5)//�b����
		{
			if ((key_flag == 3))
			{

				m_sp = 3;
				sp_flag = true;

			}
		}
		if (second == 7)//�b����
		{
			if ((key_flag == 4))
			{
				m_sp = 4;
				sp_flag = true;

			}
		}
		if (second == 9)//�b����
		{
			if ((key_flag == 5))
			{
				m_sp = 5;
				sp_flag = true;

			}
		}
		if (second == 11)//�b����
		{
			if ((key_flag == 6))
			{
				m_sp = 6;
				sp_flag = true;

			}
		}
		if (second == 13)//�b����
		{
			if ((key_flag ==7))
			{
				m_sp = 7;
				sp_flag = false;

			}
		}


	/*	if (Input::GetVKey(VK_RETURN) == true) {

			if (m_key_control == true)
			{

				
				if ((key_flag == 6))
				{
					m_sp = 6;
					sp_flag = true;

				}
				m_key_control = false;
			}
		}
		else
		{
			m_key_control = true;

		}*/
	}
	//------------------------------------------------------




}

//�h���[
void CObjChinaEvent::Draw()
{
	////�`��J���[���@R=RED G=Green B=Blue A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	CObjChinaEvent* chinaevent = (CObjChinaEvent*)Objs::GetObj(OBJ_CHINA_EVENT);

	if (chinaevent != nullptr)
	{
		if (m_sp == 1)//�G���^�[�L�[����񉟂����Ƃ�
		{
			sp_flag == true;

			ifstream fin("�`���C�i�^�E���C�x���g.txt", ios::in);//�e�L�X�g�f�[�^����ǂݍ���
			char str1[64];//�����̔z��
			wchar_t wstr1[64];
			fin.seekg(0, ios::cur);//0�o�C�g���i�߂�
			fin >> str1;//str1�Ƀe�L�X�g������

			sprintf_s(str1, "%s", str1);//�o��
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//���������j�R�[�h�ɕϊ�����
			Font::StrDraw(wstr1, 50.0f, 500, 30, c);// X  Y  �傫��     


			key_flag = 2;
			fin.close();//�t�@�C�������
		}
		if (m_sp == 2)//�G���^�[�L�[��2�񉟂����Ƃ�
		{
			sp_flag == true;

			ifstream fin("�`���C�i�^�E���C�x���g.txt", ios::in);//�e�L�X�g�f�[�^����ǂݍ���
			char str1[64];//�����̔z��
			wchar_t wstr1[64];
			fin.seekg(24, ios::cur);//0�o�C�g���i�߂�
			fin >> str1;//str1�Ƀe�L�X�g������

			sprintf_s(str1, "%s", str1);//�o��
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//���������j�R�[�h�ɕϊ�����
			Font::StrDraw(wstr1, 50.0f, 500, 30, c);// X  Y  �傫��     


			key_flag = 3;
			fin.close();//�t�@�C�������
		}
		if (m_sp == 3)//�G���^�[�L�[��3�񉟂����Ƃ�
		{
			sp_flag == true;

			ifstream fin("�`���C�i�^�E���C�x���g.txt", ios::in);//�e�L�X�g�f�[�^����ǂݍ���
			char str1[64];//�����̔z��
			wchar_t wstr1[64];
			fin.seekg(46, ios::cur);//0�o�C�g���i�߂�
			fin >> str1;//str1�Ƀe�L�X�g������

			sprintf_s(str1, "%s", str1);//�o��
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//���������j�R�[�h�ɕϊ�����
			Font::StrDraw(wstr1, 50.0f, 500, 30, c);// X  Y  �傫��     


			key_flag = 4;
			fin.close();//�t�@�C�������
		}
		if (m_sp ==4)//�G���^�[�L�[��3�񉟂����Ƃ�
		{
			sp_flag == true;

			ifstream fin("�`���C�i�^�E���C�x���g.txt", ios::in);//�e�L�X�g�f�[�^����ǂݍ���
			char str1[64];//�����̔z��
			wchar_t wstr1[64];
			fin.seekg(80, ios::cur);//0�o�C�g���i�߂�
			fin >> str1;//str1�Ƀe�L�X�g������

			sprintf_s(str1, "%s", str1);//�o��
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//���������j�R�[�h�ɕϊ�����
			Font::StrDraw(wstr1, 50.0f, 500, 30, c);// X  Y  �傫��     


			key_flag = 5;
			fin.close();//�t�@�C�������
		}
	    if (m_sp == 5)//�G���^�[�L�[��3�񉟂����Ƃ�
	    {
	    	sp_flag == true;
	    
	    	ifstream fin("�`���C�i�^�E���C�x���g.txt", ios::in);//�e�L�X�g�f�[�^����ǂݍ���
	    	char str1[64];//�����̔z��
	    	wchar_t wstr1[64];
	    	fin.seekg(130, ios::cur);//0�o�C�g���i�߂�
	    	fin >> str1;//str1�Ƀe�L�X�g������
	    
	    	sprintf_s(str1, "%s", str1);//�o��
	    	MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//���������j�R�[�h�ɕϊ�����
	    	Font::StrDraw(wstr1, 50.0f, 500, 30, c);// X  Y  �傫��     
	    
	    
	    	key_flag = 6;
	    	fin.close();//�t�@�C�������
	    }
	    if (m_sp == 6)
	    {
			sp_flag = false;
	    	key_flag =7;
	    }
	    if (m_sp == 7)
	    {
	    	sp_flag = false;
	    	Scene::SetScene(new CSceneChinaTown());//�`���C�i�^�E���ɃV�[���؂�ւ�
	    }
	}
	
}

