//�g�p����w�b�_�[�t�@�C��
#include"GameL/DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameL/DrawFont.h"
#include"GameL/WinInputs.h"
#include"GameL/UserData.h"
#include"GameL/Audio.h"

#include"GameHead.h"
#include"ObjChinaMob.h"
#include"UtilityModule.h"
#include<fstream>


//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjChinaMob::CObjChinaMob()
{
	//Heroine�̃w�b�_�[��������킩��
	m_sp = 0;
	key_flag = 1;
	sp_flag = false;
	m_key_control = true;
	m_time = 0;
	mob_flag = 0;
	m_save_sp = 0;

	Save_sp=true;

	//�@�I���@���y���̓ǂݍ���
	Audio::LoadAudio(2, L"��b.wav", EFFECT);//�P��
}


//�C�j�V�����C�Y
void CObjChinaMob::Init()
{

}

//�A�N�V����
void CObjChinaMob::Action()
{
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	CObjChinaTown* chinatown = (CObjChinaTown*)Objs::GetObj(OBJ_CHINA_TOWN);//�`���C�i�^�E��
	CObjChinaTownBoss* chinatownboss = (CObjChinaTownBoss*)Objs::GetObj(OBJ_CHINA_TOWN_BOSS);//�`���C�i�^�E���{�X

	//�`���C�i�^�E���̃��u
	if (chinatown != nullptr)
	{
		if (hero->GetBT() == 34)//��
		{
			mob_flag = 1;
			if (Input::GetVKey(VK_RETURN) == true)
			{

				if (m_key_control == true)
				{
					Audio::Start(2);
					if ((key_flag == 1))
					{
						m_sp = 1;
						sp_flag = true;
					}

					if ((key_flag == 2))
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
						sp_flag = true;
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


		if (hero->GetBT() == 99)
		{
			mob_flag = 4;
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
						sp_flag = true;
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

		if (hero->GetBT() == 100)
		{
			mob_flag = 2;
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
						sp_flag = true;
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
		//�s���N���{
		if (hero->GetBT() == 101)
		{
			mob_flag = 6;
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
						sp_flag = true;
					}
					if ((key_flag == 6))
					{
						m_sp = 6;
						sp_flag = true;
					}
					if ((key_flag == 7))
					{
						m_sp = 7;
						sp_flag = true;
					}
					if ((key_flag == 8))
					{
						m_sp = 8;
						sp_flag = true;
					}
					if ((key_flag ==9))
					{
						m_sp = 9;
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

		//����������u
		if (hero->GetBT() == 104)
		{
			mob_flag = 3;
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
						sp_flag = true;
					}
					if ((key_flag == 6))
					{
						m_sp = 6;
						sp_flag = true;
					}
					if ((key_flag ==7))
					{
						m_sp = 7;
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

	if (chinatown != nullptr)
	{
	
		if (hero->GetBT() == 83)
		{
			mob_flag = 5;

			if (Input::GetVKey(VK_RETURN) == true)
			{
			
				if (Save_sp == true)
				{
					Audio::Start(2);
					((UserData*)Save::GetData())->mStage = 1;
					Save::Seve();
					Save_sp = false;
					m_save_sp = 1;
					sp_flag = true;
				}
			}
			else
			{
				Save_sp = true;
				m_save_sp = 2;

			}
		}
		
	}

	//�P�r��
	if (chinatownboss != nullptr)
	{
		if (hero->GetBT() == 99)
		{
			mob_flag = 1;
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
						sp_flag = true;
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

		//�}�C�P��
		if (hero->GetBT() == 100)
		{
			mob_flag = 2;
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
						sp_flag = true;
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

		//�g�[�}�X
		if (hero->GetBT() == 101)
		{
			mob_flag = 3;
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
						sp_flag = true;
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
void CObjChinaMob::Draw()
{
	////�`��J���[���@R=RED G=Green B=Blue A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	CObjChinaTown* chinatown = (CObjChinaTown*)Objs::GetObj(OBJ_CHINA_TOWN);
	CObjChinaTownBoss* chinatownboss = (CObjChinaTownBoss*)Objs::GetObj(OBJ_CHINA_TOWN_BOSS);

	if (chinatown != nullptr)
	{
		switch (mob_flag)
		{
		case 1://��
			if (m_sp == 0)//�G���^�[�L�[��3�񉟂����Ƃ�
			{
				sp_flag = false;//�w�i
				key_flag = 1;//��b�̏���
			}
			if (m_sp == 1)//�G���^�[�L�[����񉟂����Ƃ�
			{
				sp_flag == true;

				ifstream fin("�`���C�i�^�E����b.txt", ios::in);//�e�L�X�g�f�[�^����ǂݍ���
				char str1[64];//�����̔z��
				wchar_t wstr1[64];
				fin.seekg(100, ios::cur);//0�o�C�g���i�߂�
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

				ifstream fin("�`���C�i�^�E����b.txt", ios::in);//�e�L�X�g�f�[�^����ǂݍ���
				char str1[64];//�����̔z��
				wchar_t wstr1[64];
				fin.seekg(114, ios::cur);//0�o�C�g���i�߂�
				fin >> str1;//str1�Ƀe�L�X�g������

				sprintf_s(str1, "%s", str1);//�o��
				MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//���������j�R�[�h�ɕϊ�����
				Font::StrDraw(wstr1, 50.0f, 500, 25, c);// X  Y  �傫��     


				key_flag = 3;
				fin.close();//�t�@�C�������
			}
			if (m_sp == 3)//�G���^�[�L�[��2�񉟂����Ƃ�
			{
				sp_flag == true;

				ifstream fin("�`���C�i�^�E����b.txt", ios::in);//�e�L�X�g�f�[�^����ǂݍ���
				char str1[64];//�����̔z��
				wchar_t wstr1[64];
				fin.seekg(146, ios::cur);//0�o�C�g���i�߂�
				fin >> str1;//str1�Ƀe�L�X�g������

				sprintf_s(str1, "%s", str1);//�o��
				MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//���������j�R�[�h�ɕϊ�����
				Font::StrDraw(wstr1, 50.0f, 500, 25, c);// X  Y  �傫��     


				key_flag = 4;
				fin.close();//�t�@�C�������
			}
			if (m_sp == 4)//�G���^�[�L�[��2�񉟂����Ƃ�
			{
				sp_flag == true;

				ifstream fin("�`���C�i�^�E����b.txt", ios::in);//�e�L�X�g�f�[�^����ǂݍ���
				char str1[64];//�����̔z��
				wchar_t wstr1[64];
				fin.seekg(164, ios::cur);//0�o�C�g���i�߂�
				fin >> str1;//str1�Ƀe�L�X�g������

				sprintf_s(str1, "%s", str1);//�o��
				MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//���������j�R�[�h�ɕϊ�����
				Font::StrDraw(wstr1, 50.0f, 490, 25, c);// X  Y  �傫��     


				key_flag = 5;
				fin.close();//�t�@�C�������
			}
			if (m_sp == 4)//�G���^�[�L�[��2�񉟂����Ƃ�
			{
				sp_flag == true;

				ifstream fin("�`���C�i�^�E����b.txt", ios::in);//�e�L�X�g�f�[�^����ǂݍ���
				char str1[64];//�����̔z��
				wchar_t wstr1[64];
				fin.seekg(200, ios::cur);//0�o�C�g���i�߂�
				fin >> str1;//str1�Ƀe�L�X�g������

				sprintf_s(str1, "%s", str1);//�o��
				MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//���������j�R�[�h�ɕϊ�����
				Font::StrDraw(wstr1, 110.0f, 520, 25, c);// X  Y  �傫��     


				key_flag = 5;
				fin.close();//�t�@�C�������
			}
			if (m_sp == 5)//�G���^�[�L�[��3�񉟂����Ƃ�
			{
				sp_flag = false;//�w�i
				key_flag = 1;//��b�̏���
			}
			break;
			case 2:
				if (m_sp == 0)//�G���^�[�L�[��3�񉟂����Ƃ�
				{
					sp_flag = false;//�w�i
					key_flag = 1;//��b�̏���
				}
				if (m_sp == 1)//�G���^�[�L�[����񉟂����Ƃ�
				{
					sp_flag == true;

					ifstream fin("�`���C�i�^�E����b.txt", ios::in);//�e�L�X�g�f�[�^����ǂݍ���
					char str1[64];//�����̔z��
					wchar_t wstr1[64];
					fin.seekg(222, ios::cur);//0�o�C�g���i�߂�
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

					ifstream fin("�`���C�i�^�E����b.txt", ios::in);//�e�L�X�g�f�[�^����ǂݍ���
					char str1[64];//�����̔z��
					wchar_t wstr1[64];
					fin.seekg(246, ios::cur);//0�o�C�g���i�߂�
					fin >> str1;//str1�Ƀe�L�X�g������

					sprintf_s(str1, "%s", str1);//�o��
					MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//���������j�R�[�h�ɕϊ�����
					Font::StrDraw(wstr1, 50.0f, 500, 25, c);// X  Y  �傫��     


					key_flag = 3;
					fin.close();//�t�@�C�������
				}
				if (m_sp == 3)//�G���^�[�L�[��3�񉟂����Ƃ�
				{
					sp_flag = false;
					key_flag = 1;
				}
				break;

			case 3://����������u
				if (m_sp == 0)//�G���^�[�L�[��3�񉟂����Ƃ�
				{
					sp_flag = false;//�w�i
					key_flag = 1;//��b�̏���
				}
				if (m_sp == 1)//�G���^�[�L�[����񉟂����Ƃ�
				{
					sp_flag == true;

					ifstream fin("����������u.txt", ios::in);//�e�L�X�g�f�[�^����ǂݍ���
					char str1[128];//�����̔z��
					wchar_t wstr1[128];
					fin.seekg(0, ios::cur);//0�o�C�g���i�߂�
					fin >> str1;//str1�Ƀe�L�X�g������

					sprintf_s(str1, "%s", str1);//�o��
					MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 128, wstr1, 128);//���������j�R�[�h�ɕϊ�����
					Font::StrDraw(wstr1, 30.0f, 500, 30, c);// X  Y  �傫��     

					key_flag = 2;
					fin.close();//�t�@�C�������
				}
				if (m_sp == 1)//�G���^�[�L�[��2�񉟂����Ƃ�
				{
					sp_flag == true;

					ifstream fin("����������u.txt", ios::in);//�e�L�X�g�f�[�^����ǂݍ���
					char str1[64];//�����̔z��
					wchar_t wstr1[64];
					fin.seekg(36, ios::cur);//0�o�C�g���i�߂�
					fin >> str1;//str1�Ƀe�L�X�g������

					sprintf_s(str1, "%s", str1);//�o��
					MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//���������j�R�[�h�ɕϊ�����
					Font::StrDraw(wstr1, 240.0f, 530, 30, c);// X  Y  �傫��     

					key_flag = 2;
					fin.close();//�t�@�C�������
				}
				if (m_sp == 2)//�G���^�[�L�[��2�񉟂����Ƃ�
				{
					sp_flag == true;

					ifstream fin("����������u.txt", ios::in);//�e�L�X�g�f�[�^����ǂݍ���
					char str1[64];//�����̔z��
					wchar_t wstr1[64];
					fin.seekg(70, ios::cur);//0�o�C�g���i�߂�
					fin >> str1;//str1�Ƀe�L�X�g������

					sprintf_s(str1, "%s", str1);//�o��
					MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//���������j�R�[�h�ɕϊ�����
					Font::StrDraw(wstr1, 50.0f, 500, 25, c);// X  Y  �傫��     

					key_flag = 3;
					fin.close();//�t�@�C�������
				}
				if (m_sp == 2)//�G���^�[�L�[��2�񉟂����Ƃ�
				{
					sp_flag == true;

					ifstream fin("����������u.txt", ios::in);//�e�L�X�g�f�[�^����ǂݍ���
					char str1[64];//�����̔z��
					wchar_t wstr1[64];
					fin.seekg(132, ios::cur);//0�o�C�g���i�߂�
					fin >> str1;//str1�Ƀe�L�X�g������

					sprintf_s(str1, "%s", str1);//�o��
					MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//���������j�R�[�h�ɕϊ�����
					Font::StrDraw(wstr1, 230.0f, 530, 25, c);// X  Y  �傫��     

					key_flag = 3;
					fin.close();//�t�@�C�������
				}
				if (m_sp == 3)//�G���^�[�L�[��2�񉟂����Ƃ�
				{
					sp_flag == true;

					ifstream fin("����������u.txt", ios::in);//�e�L�X�g�f�[�^����ǂݍ���
					char str1[64];//�����̔z��
					wchar_t wstr1[64];
					fin.seekg(170, ios::cur);//0�o�C�g���i�߂�
					fin >> str1;//str1�Ƀe�L�X�g������

					sprintf_s(str1, "%s", str1);//�o��
					MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//���������j�R�[�h�ɕϊ�����
					Font::StrDraw(wstr1, 50.0f, 480, 27, c);// X  Y  �傫��     

					key_flag = 4;
					fin.close();//�t�@�C�������
				}
				if (m_sp == 3)//�G���^�[�L�[��2�񉟂����Ƃ�
				{
					sp_flag == true;

					ifstream fin("����������u.txt", ios::in);//�e�L�X�g�f�[�^����ǂݍ���
					char str1[128];//�����̔z��
					wchar_t wstr1[128];
					fin.seekg(212, ios::cur);//0�o�C�g���i�߂�
					fin >> str1;//str1�Ƀe�L�X�g������

					sprintf_s(str1, "%s", str1);//�o��
					MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 128, wstr1, 128);//���������j�R�[�h�ɕϊ�����
					Font::StrDraw(wstr1, 235.0f, 510, 27, c);// X  Y  �傫��     

					key_flag = 4;
					fin.close();//�t�@�C�������
				}
				if (m_sp == 3 )//�G���^�[�L�[��2�񉟂����Ƃ�
				{
					sp_flag == true;

					ifstream fin("����������u.txt", ios::in);//�e�L�X�g�f�[�^����ǂݍ���
					char str1[128];//�����̔z��
					wchar_t wstr1[128];
					fin.seekg(248, ios::cur);//0�o�C�g���i�߂�
					fin >> str1;//str1�Ƀe�L�X�g������

					sprintf_s(str1, "%s", str1);//�o��
					MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 128, wstr1, 128);//���������j�R�[�h�ɕϊ�����
					Font::StrDraw(wstr1, 235.0f, 540, 27, c);// X  Y  �傫��     

					key_flag = 4;
					fin.close();//�t�@�C�������
				}
				if (m_sp == 4)//�G���^�[�L�[��3�񉟂����Ƃ�
				{
					sp_flag = false;

					key_flag = 1;
				}
				break;

				case 4: 
					if (m_sp == 0)//�G���^�[�L�[��3�񉟂����Ƃ�
					{
						sp_flag = false;//�w�i
						key_flag = 1;//��b�̏���
					}
					if (m_sp == 1)//�G���^�[�L�[����񉟂����Ƃ�
					{
						sp_flag == true;

						ifstream fin("�`���C�i�^�E����b.txt", ios::in);//�e�L�X�g�f�[�^����ǂݍ���
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

						ifstream fin("�`���C�i�^�E����b.txt", ios::in);//�e�L�X�g�f�[�^����ǂݍ���
						char str1[64];//�����̔z��
						wchar_t wstr1[64];
						fin.seekg(46, ios::cur);//0�o�C�g���i�߂�
						fin >> str1;//str1�Ƀe�L�X�g������

						sprintf_s(str1, "%s", str1);//�o��
						MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//���������j�R�[�h�ɕϊ�����
						Font::StrDraw(wstr1, 50.0f, 500, 25, c);// X  Y  �傫��     

						key_flag = 3;
						fin.close();//�t�@�C�������
					}
					if (m_sp == 3)//�G���^�[�L�[��3�񉟂����Ƃ�
					{
						sp_flag = false;  
						key_flag = 1;
					}
					break;
				case 5://�Z�[�u
					if (m_save_sp == 1)
					{
						sp_flag = true;
						Font::StrDraw(L"�Z�[�u���܂���", 100.0f, 490, 40, c);// X  Y  �傫��     
					}
					if (m_save_sp == 2)
					{
						sp_flag = false;
					}
					break;

			case 6://�s���N���{��b
				if (m_sp == 0)//�G���^�[�L�[��3�񉟂����Ƃ�
				{
					sp_flag = false;//�w�i
					key_flag = 1;//��b�̏���
				}
				if (m_sp == 1)//�G���^�[�L�[����񉟂����Ƃ�
				{
					sp_flag == true;

					ifstream fin("�s���N���{��b.txt", ios::in);//�e�L�X�g�f�[�^����ǂݍ���
					char str1[64];//�����̔z��
					wchar_t wstr1[64];
					fin.seekg(0, ios::cur);//0�o�C�g���i�߂�
					fin >> str1;//str1�Ƀe�L�X�g������

					sprintf_s(str1, "%s", str1);//�o��
					MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//���������j�R�[�h�ɕϊ�����
					Font::StrDraw(wstr1, 50.0f, 510, 30, c);// X  Y  �傫��     


					key_flag = 2;
					fin.close();//�t�@�C�������
				}
				if (m_sp == 2)//�G���^�[�L�[��2�񉟂����Ƃ�
				{
					sp_flag == true;

					ifstream fin("�s���N���{��b.txt", ios::in);//�e�L�X�g�f�[�^����ǂݍ���
					char str1[64];//�����̔z��
					wchar_t wstr1[64];
					fin.seekg(36, ios::cur);//0�o�C�g���i�߂�
					fin >> str1;//str1�Ƀe�L�X�g������

					sprintf_s(str1, "%s", str1);//�o��
					MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//���������j�R�[�h�ɕϊ�����
					Font::StrDraw(wstr1, 50.0f, 510, 30, c);// X  Y  �傫��     


					key_flag = 3;
					fin.close();//�t�@�C�������
				}
				if (m_sp == 3)//�G���^�[�L�[��2�񉟂����Ƃ�
				{
					sp_flag == true;

					ifstream fin("�s���N���{��b.txt", ios::in);//�e�L�X�g�f�[�^����ǂݍ���
					char str1[64];//�����̔z��
					wchar_t wstr1[64];
					fin.seekg(58, ios::cur);//0�o�C�g���i�߂�
					fin >> str1;//str1�Ƀe�L�X�g������

					sprintf_s(str1, "%s", str1);//�o��
					MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//���������j�R�[�h�ɕϊ�����
					Font::StrDraw(wstr1, 50.0f, 510, 30, c);// X  Y  �傫��     


					key_flag = 4;
					fin.close();//�t�@�C�������
				}
				if (m_sp == 4)//�G���^�[�L�[��2�񉟂����Ƃ�
				{
					sp_flag == true;

					ifstream fin("�s���N���{��b.txt", ios::in);//�e�L�X�g�f�[�^����ǂݍ���
					char str1[64];//�����̔z��
					wchar_t wstr1[64];
					fin.seekg(102, ios::cur);//0�o�C�g���i�߂�
					fin >> str1;//str1�Ƀe�L�X�g������

					sprintf_s(str1, "%s", str1);//�o��
					MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//���������j�R�[�h�ɕϊ�����
					Font::StrDraw(wstr1, 50.0f, 510, 30, c);// X  Y  �傫��     


					key_flag = 5;
					fin.close();//�t�@�C�������
				}
				if (m_sp == 5)//�G���^�[�L�[��2�񉟂����Ƃ�
				{
					sp_flag == true;

					ifstream fin("�s���N���{��b.txt", ios::in);//�e�L�X�g�f�[�^����ǂݍ���
					char str1[64];//�����̔z��
					wchar_t wstr1[64];
					fin.seekg(140, ios::cur);//0�o�C�g���i�߂�
					fin >> str1;//str1�Ƀe�L�X�g������

					sprintf_s(str1, "%s", str1);//�o��
					MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//���������j�R�[�h�ɕϊ�����
					Font::StrDraw(wstr1, 50.0f, 490, 26, c);// X  Y  �傫��     


					key_flag = 6;
					fin.close();//�t�@�C�������
				}
				if (m_sp == 5)//�G���^�[�L�[��2�񉟂����Ƃ�
				{
					sp_flag == true;

					ifstream fin("�s���N���{��b.txt", ios::in);//�e�L�X�g�f�[�^����ǂݍ���
					char str1[64];//�����̔z��
					wchar_t wstr1[64];
					fin.seekg(198, ios::cur);//0�o�C�g���i�߂�
					fin >> str1;//str1�Ƀe�L�X�g������

					sprintf_s(str1, "%s", str1);//�o��
					MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//���������j�R�[�h�ɕϊ�����
					Font::StrDraw(wstr1, 205.0f, 530, 26, c);// X  Y  �傫��     


					key_flag = 6;
					fin.close();//�t�@�C�������
				}
				if (m_sp == 6)//�G���^�[�L�[��2�񉟂����Ƃ�
				{
					sp_flag == true;

					ifstream fin("�s���N���{��b.txt", ios::in);//�e�L�X�g�f�[�^����ǂݍ���
					char str1[64];//�����̔z��
					wchar_t wstr1[64];
					fin.seekg(242, ios::cur);//0�o�C�g���i�߂�
					fin >> str1;//str1�Ƀe�L�X�g������

					sprintf_s(str1, "%s", str1);//�o��
					MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//���������j�R�[�h�ɕϊ�����
					Font::StrDraw(wstr1, 50.0f, 510, 30, c);// X  Y  �傫��     


					key_flag = 7;
					fin.close();//�t�@�C�������
				}
				if (m_sp == 7)//�G���^�[�L�[��2�񉟂����Ƃ�
				{
					sp_flag == true;

					ifstream fin("�s���N���{��b.txt", ios::in);//�e�L�X�g�f�[�^����ǂݍ���
					char str1[64];//�����̔z��
					wchar_t wstr1[64];
					fin.seekg(262, ios::cur);//0�o�C�g���i�߂�
					fin >> str1;//str1�Ƀe�L�X�g������

					sprintf_s(str1, "%s", str1);//�o��
					MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//���������j�R�[�h�ɕϊ�����
					Font::StrDraw(wstr1, 48.0f, 490, 26, c);// X  Y  �傫��     


					key_flag = 8;
					fin.close();//�t�@�C�������
				}
				if (m_sp == 7)//�G���^�[�L�[��2�񉟂����Ƃ�
				{
					sp_flag == true;

					ifstream fin("�s���N���{��b.txt", ios::in);//�e�L�X�g�f�[�^����ǂݍ���
					char str1[64];//�����̔z��
					wchar_t wstr1[64];
					fin.seekg(322, ios::cur);//0�o�C�g���i�߂�
					fin >> str1;//str1�Ƀe�L�X�g������

					sprintf_s(str1, "%s", str1);//�o��
					MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//���������j�R�[�h�ɕϊ�����
					Font::StrDraw(wstr1, 205.0f, 530, 26, c);// X  Y  �傫��     


					key_flag = 8;
					fin.close();//�t�@�C�������
				}
				if (m_sp == 8)//�G���^�[�L�[��2�񉟂����Ƃ�
				{
					sp_flag == true;

					ifstream fin("�s���N���{��b.txt", ios::in);//�e�L�X�g�f�[�^����ǂݍ���
					char str1[64];//�����̔z��
					wchar_t wstr1[64];
					fin.seekg(358, ios::cur);//0�o�C�g���i�߂�
					fin >> str1;//str1�Ƀe�L�X�g������

					sprintf_s(str1, "%s", str1);//�o��
					MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//���������j�R�[�h�ɕϊ�����
					Font::StrDraw(wstr1, 50.0f, 510, 30, c);// X  Y  �傫��     


					key_flag = 9;
					fin.close();//�t�@�C�������
				}
				if (m_sp == 9)//�G���^�[�L�[��3�񉟂����Ƃ�
				{
					sp_flag = false;//�w�i
					key_flag = 1;//��b�̏���
				} 
				break;

		}
	}

	if (chinatownboss != nullptr)
	{
		switch (mob_flag)
		{
		case 1://�P�r��
			if (m_sp == 0)//�G���^�[�L�[��0�񉟂����Ƃ�
			{
				sp_flag = false;//�w�i
				key_flag = 1;//��b�̏���
			}
			if (m_sp == 1)//�G���^�[�L�[����񉟂����Ƃ�
			{
				sp_flag == true;

				ifstream fin("�`���C�i�^�E���{�X��t�B�[���h�̉�b.txt", ios::in);//�e�L�X�g�f�[�^����ǂݍ���
				char str1[64];//�����̔z��
				wchar_t wstr1[64];
				fin.seekg(0, ios::cur);//0�o�C�g���i�߂�
				fin >> str1;//str1�Ƀe�L�X�g������

				sprintf_s(str1, "%s", str1);//�o��
				MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//���������j�R�[�h�ɕϊ�����
				Font::StrDraw(wstr1, 50.0f, 490, 30, c);// X  Y  �傫��     

				key_flag = 2;
				fin.close();//�t�@�C�������
			}
			if (m_sp == 2)//�G���^�[�L�[����񉟂����Ƃ�
			{
				sp_flag == true;

				ifstream fin("�`���C�i�^�E���{�X��t�B�[���h�̉�b.txt", ios::in);//�e�L�X�g�f�[�^����ǂݍ���
				char str1[64];//�����̔z��
				wchar_t wstr1[64];
				fin.seekg(20, ios::cur);//0�o�C�g���i�߂�
				fin >> str1;//str1�Ƀe�L�X�g������

				sprintf_s(str1, "%s", str1);//�o��
				MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//���������j�R�[�h�ɕϊ�����
				Font::StrDraw(wstr1, 50.0f, 490, 30, c);// X  Y  �傫��     

				key_flag = 3;
				fin.close();//�t�@�C�������
			}
			if (m_sp == 2)//�G���^�[�L�[����񉟂����Ƃ�
			{
				sp_flag == true;

				ifstream fin("�`���C�i�^�E���{�X��t�B�[���h�̉�b.txt", ios::in);//�e�L�X�g�f�[�^����ǂݍ���
				char str1[64];//�����̔z��
				wchar_t wstr1[64];
				fin.seekg(66, ios::cur);//0�o�C�g���i�߂�
				fin >> str1;//str1�Ƀe�L�X�g������

				sprintf_s(str1, "%s", str1);//�o��
				MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//���������j�R�[�h�ɕϊ�����
				Font::StrDraw(wstr1, 50.0f, 520, 30, c);// X  Y  �傫��     

				key_flag = 3;
				fin.close();//�t�@�C�������
			}
			if (m_sp == 3)//�G���^�[�L�[����񉟂����Ƃ�
			{
				sp_flag == true;

				ifstream fin("�`���C�i�^�E���{�X��t�B�[���h�̉�b.txt", ios::in);//�e�L�X�g�f�[�^����ǂݍ���
				char str1[64];//�����̔z��
				wchar_t wstr1[64];
				fin.seekg(100, ios::cur);//0�o�C�g���i�߂�
				fin >> str1;//str1�Ƀe�L�X�g������

				sprintf_s(str1, "%s", str1);//�o��
				MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//���������j�R�[�h�ɕϊ�����
				Font::StrDraw(wstr1, 50.0f, 490, 30, c);// X  Y  �傫��     

				key_flag = 4;
				fin.close();//�t�@�C�������
			}
			if (m_sp == 4)//�G���^�[�L�[����񉟂����Ƃ�
			{
				sp_flag = false;


				key_flag = 1;

			}
			break;
		case 2://�}�C�P��
			if (m_sp == 0)//�G���^�[�L�[��3�񉟂����Ƃ�
			{
				sp_flag = false;//�w�i
				key_flag = 1;//��b�̏���
			}
			if (m_sp == 1)//�G���^�[�L�[����񉟂����Ƃ�
			{
				sp_flag == true;

				ifstream fin("�`���C�i�^�E���{�X��t�B�[���h�̉�b.txt", ios::in);//�e�L�X�g�f�[�^����ǂݍ���
				char str1[64];//�����̔z��
				wchar_t wstr1[64];
				fin.seekg(146, ios::cur);//0�o�C�g���i�߂�
				fin >> str1;//str1�Ƀe�L�X�g������

				sprintf_s(str1, "%s", str1);//�o��
				MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//���������j�R�[�h�ɕϊ�����
				Font::StrDraw(wstr1, 50.0f, 500, 30, c);// X  Y  �傫��     

				key_flag = 2;
				fin.close();//�t�@�C�������
			}
			if (m_sp == 2)//�G���^�[�L�[����񉟂����Ƃ�
			{
				sp_flag == true;

				ifstream fin("�`���C�i�^�E���{�X��t�B�[���h�̉�b.txt", ios::in);//�e�L�X�g�f�[�^����ǂݍ���
				char str1[64];//�����̔z��
				wchar_t wstr1[64];
				fin.seekg(194, ios::cur);//0�o�C�g���i�߂�
				fin >> str1;//str1�Ƀe�L�X�g������

				sprintf_s(str1, "%s", str1);//�o��
				MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//���������j�R�[�h�ɕϊ�����
				Font::StrDraw(wstr1, 50.0f, 500, 30, c);// X  Y  �傫��     

				key_flag = 3;
				fin.close();//�t�@�C�������
			}
			if (m_sp == 3)//�G���^�[�L�[����񉟂����Ƃ�
			{
				sp_flag == true;

				ifstream fin("�`���C�i�^�E���{�X��t�B�[���h�̉�b.txt", ios::in);//�e�L�X�g�f�[�^����ǂݍ���
				char str1[64];//�����̔z��
				wchar_t wstr1[64];
				fin.seekg(228, ios::cur);//0�o�C�g���i�߂�
				fin >> str1;//str1�Ƀe�L�X�g������

				sprintf_s(str1, "%s", str1);//�o��
				MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//���������j�R�[�h�ɕϊ�����
				Font::StrDraw(wstr1, 50.0f, 500, 30, c);// X  Y  �傫��     

				key_flag = 4;
				fin.close();//�t�@�C�������
			}
			if (m_sp == 4)//�G���^�[�L�[����񉟂����Ƃ�
			{
				sp_flag = false;
				key_flag = 1;

			}
			break;

		case 3://�g�[�}�X
			if (m_sp == 0)//�G���^�[�L�[��3�񉟂����Ƃ�
			{
				sp_flag = false;//�w�i
				key_flag = 1;//��b�̏���
			}
			if (m_sp == 1)//�G���^�[�L�[����񉟂����Ƃ�
			{
				sp_flag == true;

				ifstream fin("�`���C�i�^�E���{�X��t�B�[���h�̉�b.txt", ios::in);//�e�L�X�g�f�[�^����ǂݍ���
				char str1[64];//�����̔z��
				wchar_t wstr1[64];
				fin.seekg(270, ios::cur);//0�o�C�g���i�߂�
				fin >> str1;//str1�Ƀe�L�X�g������

				sprintf_s(str1, "%s", str1);//�o��
				MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//���������j�R�[�h�ɕϊ�����
				Font::StrDraw(wstr1, 50.0f, 500, 30, c);// X  Y  �傫��     

				key_flag = 2;
				fin.close();//�t�@�C�������
			}
			if (m_sp == 2)//�G���^�[�L�[����񉟂����Ƃ�
			{
				sp_flag == true;

				ifstream fin("�`���C�i�^�E���{�X��t�B�[���h�̉�b.txt", ios::in);//�e�L�X�g�f�[�^����ǂݍ���
				char str1[64];//�����̔z��
				wchar_t wstr1[64];
				fin.seekg(310, ios::cur);//0�o�C�g���i�߂�
				fin >> str1;//str1�Ƀe�L�X�g������

				sprintf_s(str1, "%s", str1);//�o��
				MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//���������j�R�[�h�ɕϊ�����
				Font::StrDraw(wstr1, 50.0f, 500, 30, c);// X  Y  �傫��     

				key_flag = 3;
				fin.close();//�t�@�C�������
			}
			if (m_sp == 3)//�G���^�[�L�[����񉟂����Ƃ�
			{
				sp_flag == true;

				ifstream fin("�`���C�i�^�E���{�X��t�B�[���h�̉�b.txt", ios::in);//�e�L�X�g�f�[�^����ǂݍ���
				char str1[64];//�����̔z��
				wchar_t wstr1[64];
				fin.seekg(350, ios::cur);//0�o�C�g���i�߂�
				fin >> str1;//str1�Ƀe�L�X�g������

				sprintf_s(str1, "%s", str1);//�o��
				MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str1, 64, wstr1, 64);//���������j�R�[�h�ɕϊ�����
				Font::StrDraw(wstr1, 50.0f, 500, 30, c);// X  Y  �傫��     

				key_flag = 4;
				fin.close();//�t�@�C�������
			}
			if (m_sp == 4)//�G���^�[�L�[����񉟂����Ƃ�
			{
				sp_flag = false;
				key_flag = 1;

			}
			break;

		}
	}
}

