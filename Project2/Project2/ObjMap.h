#pragma once
//�g�p����w�b�_�[
#include"GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g : �G�@
class CObjMap : public CObj
{
public:
	CObjMap();//�R���X�g���N�^�ʒu���	�����炤
	~CObjMap() {};
	void Init(); //�C�j�V�����C�Y
	void Action(); //�A�N�V����
	void Draw(); //�h���[
private:
	int m_sp;//��b
	int key_flag;//��b�̃t���O
	bool sp_flag;//��b�̃O���t�B�b�N�̃t���O

	bool m_key_control;//��b�L�[����
};