#pragma once
//�g�p����w�b�_�[
#include"GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�e��
class CObjGun : public CObj
{
public:
	CObjGun();
	~CObjGun() {};
	void Init();     //�C�j�V�����C�Y
	void Action();  //�A�N�V����
	void Draw();   //�h���[

private:
	int m_f;//�e�ې���
	int m_gun;//�e�̌���
	int m_bullet;//�e�ۂ̐�
	int m_bullet_held;//�e�ۂ̏�����
	int m_ani_frame;//�e����

};
