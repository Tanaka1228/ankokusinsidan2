#pragma once
//�g�p����w�b�_�[
#include"GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g : �G�@
class CObjItem : public CObj
{
public:
	CObjItem(float x, float y);//�R���X�g���N�^�ʒu���	�����炤
	~CObjItem() {};
	void Init(); //�C�j�V�����C�Y
	void Action(); //�A�N�V����
	void Draw(); //�h���[

private:
	float m_x; //Item��x�����̈ʒu
	float m_y; //Item��y�����̈ʒu
};