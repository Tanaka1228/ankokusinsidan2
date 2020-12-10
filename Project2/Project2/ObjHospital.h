#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"
#include"GameL\SceneManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;


//�萔��
#define MAP_X_MAX_1F (50)//�a�@�̔z��v�f��
#define MAP_Y_MAX_1F (26)


//�I�u�W�F�N�g�F�u���b�N&�w�i
class CObjHospital :public CObj
{
public:
	CObjHospital() {};
	~CObjHospital() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[

	void SetScroll(float s) { mx_scroll = s; }
	float GetScroll() { return mx_scroll; }

	void SetScroll2(float s) { my_scroll = s; }
	float GetScroll2() { return my_scroll; }

	bool GetMap() { return map_flag2; }

private:
	int m_map[MAP_Y_MAX_1F][MAP_X_MAX_1F];//�}�b�v���

	float mx_scroll; //���E�X�N���[���p
	float my_scroll; //���E�X�N���[���p

	int m_key_control;//��b����
	int	key_flag;//��b�t���O
	int m_sp;//��b�̎�ރt���O

	bool map_flag;
	bool map_flag2;

};