#pragma once
//�g�p����w�b�_�[
#include"GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g : �G�@
class CObjItem : public CObj
{
public:
	CObjItem(float x, float y,int id);//�R���X�g���N�^�ʒu���	�����炤
	~CObjItem() {};
	void Init(); //�C�j�V�����C�Y
	void Action(); //�A�N�V����
	void Draw(); //�h���[

	static int Get_M_Bullet_Item() { return m_bullet_item; }//�e�ۏ��������킽��
	void Set_M_Bullet_Item(int b) { m_bullet_item = b; };

	int Get_M_Bullet_Item_Flag() { return item_flag; }//�A�C�e�����Ƃ�ƃt���O
	void Set_M_Bullet_Item_Flag(bool b) { item_flag = b; };

private:
	float m_x; //Item��x�����̈ʒu
	float m_y; //Item��y�����̈ʒu

	static int m_bullet_item;//�e�ۂ̏������@���{���o�[

	int m_id;

	bool item_flag;
};