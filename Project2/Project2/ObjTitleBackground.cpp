//�g�p����w�b�_�\�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameHead.h"

#include"ObjTitleBackground.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjTitleBackground::Init()
{
	
}

//�A�N�V����
void CObjTitleBackground::Action()
{
		
}

//�h���[
void CObjTitleBackground::Draw()
{

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	



	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;   //y
	src.m_left = 0.0f;  //x
	src.m_right = 512.0f; //x
	src.m_bottom = 448.0f; //y

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 850.0f;
	dst.m_bottom = 1000.0f;

	Draw::Draw(4, &src, &dst, c, 0.0f);

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;   //y
	src.m_left = 0.0f;  //x
	src.m_right = 213.0f; //x
	src.m_bottom = 90.0f; //y

	//�\���ʒu�̐ݒ�
	dst.m_top = 330.0f;//y
	dst.m_left = 230.0f;//x;
	dst.m_right = 550.0f;//x
	dst.m_bottom = 510.f; //y

	Draw::Draw(6, &src, &dst, c, 0.0f);
	 
}