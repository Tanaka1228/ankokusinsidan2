//�g�p����w�b�_�\�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"
#include"GameL\DrawFont.h"

#include"GameHead.h"
#include"ObjEnd.h"
#include"SceneTitle.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjEnd::Init()
{
	m_key_flag = false;//�L�[�t���O
}

//�A�N�V����
void CObjEnd::Action()
{
	//�G���^�[�L�[�������ăV�[���F�Q�[��Title�Ɉڍs����
	if (Input::GetVKey(VK_RETURN) == true)
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
	}
}


//�h���[
void CObjEnd::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };
	

	//�^�C�g�����̕\��
	Font::StrDraw(L"�d�m�c", 350, 250, 32, c);
	Font::StrDraw(L"by �Í��a�m�c", 590, 550, 32, c);


	
}