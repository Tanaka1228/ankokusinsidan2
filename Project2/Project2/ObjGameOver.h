#pragma once
//�g�p����w�b�_�[�t�@�C��
#include"GameL\SceneManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�V�[���F�Q�[���^�C�g��
class CObjGameOver : public CObj
{
public:
	CObjGameOver() {};
	~CObjGameOver() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[
private:
	bool m_key_flag;//�L�[�t���O

	float m_key_uy;//���L�[�̈ʒu��
	float m_key_dy;//���L�[�̈ʒu y
	float m_key_enter;//����

	int m_x;
	int m_y;//�J�[�\���ړ�

};