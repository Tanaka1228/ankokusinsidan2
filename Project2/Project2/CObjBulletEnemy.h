#pragma once
//�g�p����w�b�_�[
#include"GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�e��
class CObjBulletEnemy : public CObj
{
public:
	CObjBulletEnemy(float x,float y);
	~CObjBulletEnemy(){};
	void Init();     //�C�j�V�����C�Y
	void Action();  //�A�N�V����
	void Draw();   //�h���[
private:
	float m_x;  //�I�u�W�F�N�g�̈ʒuX
	float m_y;  //�I�u�W�F�N�g�̈ʒuY
	float m_vx; //�I�u�W�F�N�g�̈ړ��p�x�N�g��X
	float m_vy; //�I�u�W�F�N�g�̈ړ��p�x�N�g��Y
};

