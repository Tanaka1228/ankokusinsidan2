#pragma once
//�g�p����w�b�_�[
#include"GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g : �U������G�@
class CObjChinaAtkEnemy : public CObj
{
public:
	CObjChinaAtkEnemy(float x, float y,int id);
	~CObjChinaAtkEnemy() {};
	void Init(); //�C�j�V�����C�Y
	void Action(); //�A�N�V����
	void Draw(); //�h���[


private:
	float m_x; //�U������G�@��x�����̈ʒu
	float m_y; //�U������G�@��y�����̈ʒu
	float m_vx; //�U������G�@�̃x�N�g��x
	float m_vy; //�U������G�@�̃x�N�g��y

	int m_time;//�U���G�@�p�e�۔��˃^�C�~���O�p
	int m_id;
	
};