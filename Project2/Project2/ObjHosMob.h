#pragma once
//�g�p����w�b�_�[
#include"GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g : �G�@
class CObjHosMob : public CObj
{
public:
	CObjHosMob();//�R���X�g���N�^�ʒu���	�����炤
	~CObjHosMob() {};
	void Init(); //�C�j�V�����C�Y
	void Action(); //�A�N�V����
	void Draw(); //�h���[

	bool Sp_Flag() { return sp_flag; }//��b�̔w�i
	void SetSp_flag(int s) { sp_flag = s; }

	bool GetM_sp() { return  m_sp; }//��b�̏���
	void SetM_sp(int m) { m_sp = m; }

private:
	int m_sp;//��b
	int m_save_sp;//�Z�[�u����
	int key_flag;//��b�̃t���O
	bool sp_flag;//��b�̃O���t�B�b�N�̃t���O

	bool m_key_control;//��b�L�[����

	int mob_flag;

	bool Save_sp;
};