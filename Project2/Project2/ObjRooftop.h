#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"
#include"GameL\SceneManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�u���b�N���w�i
class CObjRooftop :public CObj
{
public:
	CObjRooftop() {};
	~CObjRooftop() {};
	void Init(); //�C�j�V�����C�Y
	void Action(); //�A�N�V����
	void Draw(); //�h���[

	void SetScroll(float s) { mx_scroll = s; }
	float GetScroll() { return mx_scroll; }//X
	
	void SetScroll2(float s) { my_scroll = s; }
	float GetScroll2() { return my_scroll; }//Y

	bool GetMap() { return map_flag2; }

private:
	
	int m_map[38][83]; //�}�b�v���

	float mx_scroll; //���E�X�N���[���p
	float my_scroll; //���E�X�N���[���p

	bool map_flag;
	bool map_flag2;

};