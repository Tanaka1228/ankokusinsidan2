#pragma once
//�g�p����w�b�_�\
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�^�C�g��
class CObjTitle : public CObj
{
	public :
		 CObjTitle() {};
		~CObjTitle() {};
		void Init();
		void Action();
		void Draw();
	private:
		bool m_key_flag;//�L�[�t���O
		
		float m_key_uy;//���L�[�̈ʒu��
		float m_key_dy;//���L�[�̈ʒu y
		float m_key_enter;//����
		
		int m_x;
		int m_y;//�J�[�\���ړ�

		float m_color;
		bool color_flag;//���u�����h���Ǘ�
		
};