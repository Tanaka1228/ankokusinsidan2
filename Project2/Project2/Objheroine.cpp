//�g�p����w�b�_�[�t�@�C��
#include"GameL/DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameL/DrawFont.h"
#include"GameL/WinInputs.h"
#include"GameL/Audio.h"

#include"GameHead.h"
#include"ObjHeroine.h"
#include"UtilityModule.h"
#include<fstream>

 
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjHeroine::CObjHeroine()
{
	//Heroine�̃w�b�_�[��������킩��
	m_sp = false;
	key_flag = 1;
	sp_flag = false;
	m_key_control = true;

	//�@�I���@���y���̓ǂݍ���
	Audio::LoadAudio(2, L"��b.wav", EFFECT);//�P��
}


//�C�j�V�����C�Y
void CObjHeroine::Init()
{
	
}

//�A�N�V����
void CObjHeroine::Action()
{
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	if (block != nullptr)
	{
		if (hero->GetBT() == 17)
		{
			if (Input::GetVKey(VK_RETURN) == true) {

				if (m_key_control == true)
				{
					Audio::Start(2);
					if (key_flag == 1)
					{
						m_sp = 1;
						sp_flag = true;
					}

					if (key_flag == 2)
					{
						m_sp = 2;
						sp_flag = true;
					}
					if ((key_flag == 3))
					{

						m_sp = 3;
						sp_flag = true;
					}
					if ((key_flag == 4))
					{
						m_sp = 4;
						sp_flag = true;
					}




					if ((key_flag == 5))
					{
						m_sp = 5;
						sp_flag = false;
					}
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
			}
		}
	}
	
}

//�h���[
void CObjHeroine::Draw()
{
	////�`��J���[���@R=RED G=Green B=Blue A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);//���_

	//setlocale(LC_ALL, "Japanese");
	
	//--------------------------�e�X�g  
	//ifstream ifs(L"��b.txt", ios::in);
	//wchar_t str1[32];
	//ifs >> str2;
	//sprintf_s(str2,"%s\n", str2);
	//MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str2, 32, str1, 32);
	//Font::StrDraw(str1, 50.0f, 500, 25, c);// X  Y  �傫�� 
	//ifs.close();
	//-----------------------------

	//��s�e�L�X�g���o���Ƃ��́A2�s�ڂ�Y����30�グ��Ƃ��������ɂȂ�
	
	if (block != nullptr) {
		if (m_sp == 1)//�G���^�[�L�[����񉟂����Ƃ�
		{
			sp_flag == true;

			ifstream fin("��b.txt", ios::in);//�e�L�X�g�f�[�^����ǂݍ���
			char str1[64];//�����̔z��
			wchar_t wstr1[64];
			fin.seekg(0, ios::cur);//0�o�C�g���i�߂�
			fin >> str1;//str1�Ƀe�L�X�g������

			sprintf_s(str1, "%s", str1);//�o��
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//���������j�R�[�h�ɕϊ�����
			Font::StrDraw(wstr1, 50.0f, 480, 25, c);// X  Y  �傫��     


			key_flag = 2;
			fin.close();//�t�@�C�������
		}
		if (m_sp == 1)
		{
			sp_flag == true;

			ifstream fin("��b.txt", ios::in);
			char str1[64];//�{��
			wchar_t wstr1[64];
			fin.seekg(48, ios::cur);
			fin >> str1;

			sprintf_s(str1, "%s", str1);
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);
			Font::StrDraw(wstr1, 50.0f, 510, 25, c);// X  Y  �傫�� 


			key_flag = 2;
			fin.close();
		}

		if (m_sp == 2)
		{
			sp_flag == true;

			ifstream fin("��b.txt", ios::in);
			char str3[64];//�{��
			wchar_t wstr3[64];
			fin.seekg(94, ios::cur);
			fin >> str3;
			sprintf_s(str3, "%s", str3);
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str3, 64, wstr3, 64);
			Font::StrDraw(wstr3, 40.0f, 480, 25, c);// X  Y  �傫��

			key_flag = 3;
			fin.close();
		}
		if (m_sp == 2)
		{
			sp_flag == true;

			ifstream fin("��b.txt", ios::in);
			char str3[64];//�{��
			wchar_t wstr3[64];
			fin.seekg(158, ios::cur);
			fin >> str3;
			sprintf_s(str3, "%s", str3);
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str3, 64, wstr3, 64);
			Font::StrDraw(wstr3, 40.0f, 510, 25, c);// X  Y  �傫��

			key_flag = 3;
			fin.close();
		}

		if (m_sp == 3)
		{
			sp_flag == true;
			ifstream fin("��b.txt", ios::in);
			char str3[64];//�{��
			wchar_t wstr3[64];
			fin.seekg(194, ios::cur);
			fin >> str3;
			sprintf_s(str3, "%s", str3);
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str3, 64, wstr3, 64);
			Font::StrDraw(wstr3, 50.0f, 480, 25, c);// X  Y  �傫��

			key_flag = 4;
			fin.close();
		}
		if (m_sp == 4)
		{
			sp_flag == true;
			ifstream fin("��b.txt", ios::in);
			char str3[64];//�{��
			wchar_t wstr3[64];
			fin.seekg(239, ios::cur);
			fin >> str3;
			sprintf_s(str3, "%s", str3);
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str3, 64, wstr3, 64);
			Font::StrDraw(wstr3, 50.0f, 480, 25, c);// X  Y  �傫��

			key_flag = 5;
			fin.close();
		}
		if (m_sp == 5)
		{
			sp_flag == false;
			Font::StrDraw(L"", 100, 500, 30, c);
			key_flag = 1;

		}
	}


}

//this->SetStatus(false);//���g�ɍ폜����
		//Font::Delete();

//
////��b�O���t�B�b�N
////�؂���ʒu�̐ݒ�
//src.m_top = 373.0f; //y
//src.m_left = 20.0f; //x
//src.m_right = 780.0f; //x
//src.m_bottom = 581.0f; //y
//
////�\���ʒu�̐ݒ�
//dst.m_top = 400.0f;
//dst.m_left = 40.0f;
//dst.m_right = 750.0f;
//dst.m_bottom = 550.0f;
//
////0�Ԗڂɓo�^�����O���t�B�b�N��stc�Edst�Ec�̏������ɕ`��
//Draw::Draw(10, &src, &dst, c, 0.0f);//0.0f�͊p�x��ς�����