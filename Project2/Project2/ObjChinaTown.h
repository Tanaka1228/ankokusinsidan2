#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"
#include"GameL\SceneManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;



//�I�u�W�F�N�g�F�u���b�N&�w�i
class CObjChinaTown :public CObj
{
public:
	CObjChinaTown() {};
	~CObjChinaTown() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[

	void SetScroll(float s) { mx_scroll = s; }
	float GetScroll() { return mx_scroll; }

	void SetScroll2(float s) { my_scroll = s; }
	float GetScroll2() { return my_scroll; }

	bool GetMap() { return map_flag2; }

	void SetSaveSp(float s) { Save_sp = s; }//�Z�[�u�����ۂɂł�(�Z�[�u���܂���)�t���O
	bool GetSaveSp() { return Save_sp; }

private:
	int m_map[65][54];//�}�b�v���(��)

	float mx_scroll; //���E�X�N���[���p
	float my_scroll; //���E�X�N���[���p

	bool map_flag;
	bool map_flag2;

	bool Save_sp;

};