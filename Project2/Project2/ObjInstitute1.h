#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"
#include"GameL\SceneManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;


//�I�u�W�F�N�g�F�u���b�N&�w�i
class CObjInstitute1:public CObj
{
public:
	CObjInstitute1() {};
	~CObjInstitute1() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[

	void SetScroll(float s) { mx_scroll = s; }
	float GetScroll() { return mx_scroll; }

	void SetScroll2(float s) { my_scroll = s; }
	float GetScroll2() { return my_scroll; }
private:
	int m_map[40][40];//�}�b�v���(��)

	float mx_scroll; //���E�X�N���[���p
	float my_scroll; //���E�X�N���[���p

};