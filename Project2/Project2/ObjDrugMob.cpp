

//�g�p����w�b�_�[�t�@�C��
#include"GameL/DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameL/DrawFont.h"
#include"GameL/WinInputs.h"
#include"GameL/UserData.h"
#include"GameL/Audio.h"

#include"GameHead.h"
#include"ObjDrugMob.h"
#include"UtilityModule.h"
#include<fstream>


//�g�p����l�[���X�y�[�X
using namespace GameL;


//�R���X�g���N�^
CObjDrugMob::CObjDrugMob()
{
	//Heroine�̃w�b�_�[��������킩��
	m_sp = false;
	key_flag = 1;
	sp_flag = false;
	m_key_control = true;
	mob_flag = 0;

	Save_sp = true;
	m_save_sp = 0;

	//�@�I���@���y���̓ǂݍ���
	Audio::LoadAudio(2, L"��b.wav", EFFECT);//�P��
}


//�C�j�V�����C�Y
void CObjDrugMob::Init()
{

}

//�A�N�V����
void CObjDrugMob::Action()
{
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	CObjDrugCampany* drug = (CObjDrugCampany*)Objs::GetObj(OBJ_DRUG_CAMPANY);//�����Ђ̈�K
	

	if (drug != nullptr)
	{
		if (hero->GetBT() == 10)
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
		
	}




	if (drug != nullptr)
	{

		if (hero->GetBT() == 83)
		{
			mob_flag = 5;

			if (Input::GetVKey(VK_RETURN) == true)
			{
				
				if (Save_sp == true)
				{
					Audio::Start(2);
					((UserData*)Save::GetData())->mStage = 3;
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




}

//�h���[
void CObjDrugMob::Draw()
{
	////�`��J���[���@R=RED G=Green B=Blue A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	CObjDrugCampany* drug = (CObjDrugCampany*)Objs::GetObj(OBJ_DRUG_CAMPANY);//�����Ђ̈�K

	if (drug != nullptr && mob_flag == 1)
	{
		if (m_sp == 1)//�G���^�[�L�[����񉟂����Ƃ�
		{
			sp_flag == true;

			ifstream fin("�����Ђ̉�b.txt", ios::in);//�e�L�X�g�f�[�^����ǂݍ���
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
	
		if (m_sp == 2)
		{
			sp_flag = false;
			key_flag = 1;
		}
	}

	if(drug != nullptr)
	{
		if (m_save_sp == 1 && mob_flag == 5)
		{
			sp_flag = true;
			Font::StrDraw(L"�Z�[�u���܂���", 100.0f, 490, 40, c);// X  Y  �傫��     
		}
		if (m_save_sp == 2 && mob_flag == 5)
		{
			sp_flag = false;
		}
	}

}

