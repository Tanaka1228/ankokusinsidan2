#pragma once

//�g�p����w�b�_�[
#include"GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g : �G�@
class CObjInstituteBossBoss : public CObj
{
public:
	CObjInstituteBossBoss(float x, float y);//�R���X�g���N�^�ʒu���	�����炤
	~CObjInstituteBossBoss() {};
	void Init(); //�C�j�V�����C�Y
	void Action(); //�A�N�V����
	void Draw(); //�h���[
private:
	float m_x; //�G�@��x�����̈ʒu
	float m_y; //�G�@��y�����̈ʒu
	float m_vx;//�G�@�ړ��x�N�g��X
	float m_vy;//�G�@�ړ��x�N�g��Y
	int m_time;//�z�[�~���O�e�۔��˃^�C�~���O�p
	int m_timeboss;//�g�U�e�۔��˃^�C�~���O
	int m_hp;//�q�b�g�|�C���g
};
