//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL/SceneObjManager.h"

#include"GameHead.h"
#include"ObjRooftop.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

extern int Hos_Hero_x;

//�C�j�V�����C�Y
void CObjRooftop::Init()
{
	mx_scroll = -850.0f;//��l���̏����ʒu
	my_scroll = -400.0f;

	Hos_Hero_x = 14;
	
	//�}�b�v���
	int block_data[38][83] =
	{
		{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,1,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,25,34,1},
	    {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,18,18,18,18,6,4,5,18,4,5,18,18,6,18,18,9,9,9,9,20,9,9,9,20,9,9,10,10,10,10,19,10,10,10,19,10,10,11,12,4,5,29,4,5,10,26,35,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,45,45,45,45,45,0,0,0,0,0,0,8,45,45,45,45,45,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,45,45,45,45,45,45,0,0,0,0,0,0,45,45,45,45,45,45,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,45,45,45,45,45,45,0,0,0,0,0,0,45,45,45,45,45,45,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,45,45,45,45,45,45,0,0,0,0,0,0,45,45,45,45,45,45,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,45,45,45,45,45,45,0,0,0,0,0,0,45,45,45,45,45,45,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,45,45,45,45,45,45,0,0,0,0,0,0,45,45,45,45,45,45,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,7,7,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,7,7,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,37,38,7,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,34,7,7,39,40,7,7,43,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,35,7,7,41,42,7,7,44,0,0,0,0,8,45,45,45,45,45,0,0,0,0,0,0,8,45,45,45,45,45,0,0,0,0,0,0,0,0,0,0,0,0,0,0,99,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,45,45,45,45,45,45,0,0,0,0,0,0,45,45,45,45,45,45,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,45,45,45,45,45,45,0,0,0,0,0,0,45,45,45,45,45,45,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,45,45,45,45,45,45,0,0,0,0,0,0,45,45,45,45,45,45,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,45,45,45,45,45,45,0,0,0,0,0,0,45,45,45,45,45,45,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,45,45,45,45,45,45,0,0,0,0,0,0,45,45,45,45,45,45,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,25,0,0,0,0,0,0,0,0,0,0,21,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,13,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,26,23,23,23,23,23,2,3,23,2,3,22,24,24,24,24,24,36,36,36,36,36,36,16,16,16,16,16,16,16,16,16,14,27,27,28,28,32,2,3,31,2,3,33,29,12,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	    {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7},


	};
	//�}�b�v�f�[�^���R�s�[
	memcpy(m_map, block_data, sizeof(int) * (38 * 83));
	map_flag = true;
	map_flag2 = false;
}
//�A�N�V����
void CObjRooftop::Action()
{
	//��l���̈ʒu���擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX2();//�X�N���[��
	float hy = hero->GetY2();

	
	if (hero->GetRight() == false)
	{
		//����X�N���[�����C���@��
		if (hx < 400)
		{
			hero->SetX2(400); //��l���̓��C���𒴂��Ȃ��悤�ɂ���
			mx_scroll -= -6.0f + hero->GetVX(); //��l���͖{�������ׂ����̒l��m_scroll�ɉ�����
		}
	}

	if (hero->GetLeft() == false)
	{
		//�O���X�N���[�����C�� ��
		if (hx > 400)
		{
			hero->SetX2(400); //��l���̓��C���𒴂��Ȃ��悤�ɂ���
			mx_scroll -= 6.0f + hero->GetVX(); //��l���͖{�������ׂ����̒l��m_scroll�ɉ�����

		}
	}
	
	if (hero->GetDown() == false)
	{
		//�X�N���[�����C���@��
		if (hy > 300)
		{
			hero->SetY2(300); //��l���̓��C���𒴂��Ȃ��悤�ɂ���
			my_scroll -= 6.0f + hero->GetVY(); //��l���͖{�������ׂ����̒l��m_scroll�ɉ�����

		}
	}
	
	if (hero->GetUp() == false)
	{
		//�X�N���[�����C���@��
		if (hy < 300)
		{
			hero->SetY2(300); //��l���̓��C���𒴂��Ȃ��悤�ɂ���
			my_scroll -= -6.0f + hero->GetVY(); //��l���͖{�������ׂ����̒l��m_scroll�ɉ�����
		}
	}
	
	
	
	

	//��l���̏Փˏ�Ԋm�F�p�t���O�̏�����
	hero->SetUp(false);
	hero->SetDown(false);
	hero->SetLeft(false);
	hero->SetRight(false);

	
	
	
	

	//m_map�̑S�v�f�ɃA�N�Z�X
	for (int i = 0; i < 38; i++)
	{
		for (int j = 0; j < 83; j++)
		{
			if (m_map[i][j] > 0&&m_map[i][j]!=15)
			{

				//�v�f�ԍ������W�ɕύX
				float x = j * 32.0f;
				float y = i * 32.0f;

				//��l���ƃu���b�N�̓����蔻��
				if ((hx + (-mx_scroll) + 64.0f > x) && (hx + (-mx_scroll) < x + 64.0f) && (hy + (-my_scroll) + 64.0f > y) && (hy + (-my_scroll) < y + 64.0f))
				{

					//�㉺���E����

					//vector�̍쐬
					float vx = (hx + (-mx_scroll)) - x;
					float vy = (hy + (-my_scroll)) - y;

					//���������߂�
					float len = sqrt(vx * vx + vy * vy);//sqrt�֐��́A��������Ԃ�

					//�p�x�����߂�
					float r = atan2(vy, vx);//atan2�֐��̓A�[�N�^���W�F���g��Ԃ�
					r = r * 180.0f / 3.14f;

					if (r <= 0.0f)//abs�֐��́A�l�̐�Βl�����߂� �����𖳎������l
						r = abs(r);
					else
						r = 360.0f - abs(r);

					//len��������̒����̂��Z���ꍇ����ɓ���
					if (len < 44.4f)
					{

						//�p�x�ŏ㉺���E�𔻒�
						if ((r < 45 && r >= 0) || r > 315)
						{
							//�E
							hero->SetRight(true);//��l���̍��̕������Փ˂��Ă���
							hero->SetX2(x + 40.0f + (mx_scroll));//�u���b�N�̈ʒu+��l���̕�
							if (m_map[i][j] == 99 )
								hero->SetBT(m_map[i][j]);//�u���b�N�̗v�f(type)����l���ɓn��
							hero->SetVX(0.0f);//-VX*�����W��
						}
						if (r > 45 && r < 135)
						{
							//��
							hero->SetDown(true);//��l���̉��̕������Փ˂��Ă���
							hero->SetY2(y - 40.0f + (my_scroll));//�u���b�N�̈ʒu-��l���̕�
							if (m_map[i][j] == 99)
								hero->SetBT(m_map[i][j]);//�u���b�N�̗v�f(type)����l���ɓn��
							hero->SetVY(0.0f);//-VX*�����W��

						}
						if (r > 135 && r < 225)
						{
							//��
							hero->SetLeft(true);//��l���̉E�̕������Փ˂��Ă���
							hero->SetX2(x - 40.0f + (mx_scroll));//�u���b�N�̈ʒu-��l���̕�
							if (m_map[i][j] == 99)
								hero->SetBT(m_map[i][j]);//�u���b�N�̗v�f(type)����l���ɓn��
							hero->SetVX(0.0f);//-VX*�����W��
						}
						if (r > 225 && r < 315)
						{
							//��
							hero->SetUp(true);//��l���̏�̕������Փ˂��Ă���
							hero->SetY2(y + 40.0f + (my_scroll));//�u���b�N�̈ʒu+��l���̕�
							if (m_map[i][j] == 99)
								hero->SetBT(m_map[i][j]);//�u���b�N�̗v�f(type)����l���ɓn��
							hero->SetVY(0.0f);//-VX*�����W��
						}
						if (m_map[i][j] == 41||m_map[i][j]==42)//�h�A�ɓ���ƕa�@�Ɉړ�
						{
							Scene::SetScene(new CSceneHospital3());
						}
						
					}
				}
				

				
			}
		}
	}

	//�G�o�����C��
	float Xline = hx + (-mx_scroll)+ 400;
	float Yline = hy + (my_scroll)-100;

	int ex = ((int)Xline) / 32;
	int ey = ((int)Yline) / 32;

	for (int i = 0; i < 38; i++)
	{
		//for (int j = 0; j < 83; j++)
		
			if (m_map[i][ex] == 15)
			{
				//�U���G�@�I�u�W�F�N�g�쐬
				CObjRooftopBoss* obj_rooftop_boss = new CObjRooftopBoss(ex * 32, i * 32); //�U���G�@�I�u�W�F�N�g�쐬
				Objs::InsertObj(obj_rooftop_boss, OBJ_ROOF_TOP_BOSS, 4); //�U���G�@�I�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^

				m_map[i][ex] = 0;
			}
		  
		
	}

	if (Input::GetVKey('X') == true)
	{
		if (map_flag == true)
		{


			map_flag2 = true;
			map_flag = false;

		}
	}
	else
	{
		map_flag = true;
		map_flag2 = false;
	}

}
//�h���[
void CObjRooftop::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���w�i�\��
	src.m_top = 0.0f ;
	src.m_left = 3.0f ;
	src.m_right = 500.0f ;
	src.m_bottom = 170.0f ;
	
	//�\���ʒu�̐ݒ�
	dst.m_top = 64.0f + my_scroll;    //y
	dst.m_left = 64.0f + mx_scroll;   //x
	dst.m_right = 2655.0f + mx_scroll;  //x
	dst.m_bottom = 1057.0f + my_scroll; //y

	Draw::Draw(10, &src, &dst, c, 0.0f);
	/*dst.m_top = -100.0f + my_scroll;
	dst.m_left = -100.0f + mx_scroll;
	dst.m_right = 1500.0f + mx_scroll;
	dst.m_bottom = 1468.0f + my_scroll;*/

	

	//�}�b�v�`�b�v�ɂ��block�ݒu
	for (int i = 0; i < 38; i++)
	{
		for (int j = 0; j < 83; j++)
		{
			
			if (m_map[i][j] == 1)//��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;   //y
				src.m_left = 0.0f; //x
				src.m_right = 75.0f; //x
				src.m_bottom = 75.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top    =  i*32.0f + my_scroll;
				dst.m_left   =  j*32.0f + mx_scroll;
				dst.m_right  =  j*32.0f+32.0f + mx_scroll;
				dst.m_bottom =  i*32.0f+32.0f + my_scroll;

				//�`��
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 2)//�x���`
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 15.0f;   //y
				src.m_left = 100.0f; //x
				src.m_right = 130.0f; //x
				src.m_bottom = 70.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 3)//�x���`
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 15.0f;   //y
				src.m_left = 130.0f; //x
				src.m_right = 170.0f; //x
				src.m_bottom = 70.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 4)//�x���`
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 20.0f;   //y
				src.m_left = 180.0f; //x
				src.m_right = 210.0f; //x
				src.m_bottom = 65.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 5)//�x���`
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 20.0f;   //y
				src.m_left = 210.0f; //x
				src.m_right = 245.0f; //x
				src.m_bottom = 65.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 6)//��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 20.0f;   //y
				src.m_left = 260.0f; //x
				src.m_right = 293.0f; //x
				src.m_bottom = 55.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 7)//��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 18.0f;   //y
				src.m_left = 390.0f; //x
				src.m_right = 415.0f; //x
				src.m_bottom = 40.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 8)//�Ԓd
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 15.0f;   //y
				src.m_left = 305.0f; //x
				src.m_right = 370.0f; //x
				src.m_bottom = 77.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 200.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 200.0f + my_scroll;

				//�`��
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}
			
			if (m_map[i][j] == 9)//��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 7.0f;   //y
				src.m_left = 430.0f; //x
				src.m_right = 495.0f; //x
				src.m_bottom = 55.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 10)//��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 85.0f;   //y
				src.m_left = 5.0f; //x
				src.m_right = 43.0f; //x
				src.m_bottom = 115.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 11)//��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 87.0f;   //y
				src.m_left = 47.0f; //x
				src.m_right = 83.0f; //x
				src.m_bottom = 118.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 12)//��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 77.0f;   //y
				src.m_left = 92.0f; //x
				src.m_right = 129.0f; //x
				src.m_bottom = 108.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 13)//��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 70.0f;   //y
				src.m_left = 130.0f; //x
				src.m_right = 165.0f; //x
				src.m_bottom = 105.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 14)//��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 105.0f;   //y
				src.m_left = 130.0f; //x
				src.m_right = 165.0f; //x
				src.m_bottom = 130.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 16)//��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 75.0f;   //y
				src.m_left = 177.0f; //x
				src.m_right = 208.0f; //x
				src.m_bottom = 97.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 17)//��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 73.0f;   //y
				src.m_left = 215.0f; //x
				src.m_right = 270.0f; //x
				src.m_bottom = 115.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 18)//��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 82.0f;   //y
				src.m_left = 276.0f; //x
				src.m_right = 312.0f; //x
				src.m_bottom = 113.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 19)//��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 86.0f;   //y
				src.m_left = 321.0f; //x
				src.m_right = 352.0f; //x
				src.m_bottom = 108.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 20)//��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 88.0f;   //y
				src.m_left = 364.0f; //x
				src.m_right = 397.0f; //x
				src.m_bottom = 115.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}


			if (m_map[i][j] == 21)//��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 71.0f;   //y
				src.m_left = 408.0f; //x
				src.m_right = 450.0f; //x
				src.m_bottom = 105.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 22)//��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 105.0f;   //y
				src.m_left = 408.0f; //x
				src.m_right = 450.0f; //x
				src.m_bottom = 132.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 23)//��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 127.0f;   //y
				src.m_left = 11.0f; //x
				src.m_right = 49.0f; //x
				src.m_bottom = 159.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 24)//��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 135.0f;   //y
				src.m_left = 55.0f; //x
				src.m_right = 85.0f; //x
				src.m_bottom = 166.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 25)//��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 133.0f;   //y
				src.m_left = 92.0f; //x
				src.m_right = 123.0f; //x
				src.m_bottom = 164.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 26)//��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 164.0f;   //y
				src.m_left = 92.0f; //x
				src.m_right = 123.0f; //x
				src.m_bottom = 194.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 27)//��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 134.0f;   //y
				src.m_left = 133.0f; //x
				src.m_right = 199.0f; //x
				src.m_bottom = 198.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 28)//��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 123.0f;   //y
				src.m_left = 206.0f; //x
				src.m_right = 274.0f; //x
				src.m_bottom = 190.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 29)//��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 122.0f;   //y
				src.m_left = 284.0f; //x
				src.m_right = 326.0f; //x
				src.m_bottom = 177.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 30)//��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 122.0f;   //y
				src.m_left = 342.0f; //x
				src.m_right = 373.0f; //x
				src.m_bottom = 152.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 31)//��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 133.0f;   //y
				src.m_left = 382.0f; //x
				src.m_right = 419.0f; //x
				src.m_bottom = 166.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 32)//��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 140.0f;   //y
				src.m_left = 425.0f; //x
				src.m_right = 460.0f; //x
				src.m_bottom = 171.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 33)//��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 176.0f;   //y
				src.m_left = 8.0f; //x
				src.m_right = 42.0f; //x
				src.m_bottom = 205.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 34)//��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 176.0f;   //y
				src.m_left = 54.0f; //x
				src.m_right = 88.0f; //x
				src.m_bottom = 205.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 35)//��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 205.0f;   //y
				src.m_left = 54.0f; //x
				src.m_right = 88.0f; //x
				src.m_bottom = 240.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 36)//��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 199.0f;   //y
				src.m_left = 87.0f; //x
				src.m_right = 151.0f; //x
				src.m_bottom = 288.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 37)//�o����
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 215.0f;   //y
				src.m_left = 165.0f; //x
				src.m_right = 180.0f; //x
				src.m_bottom = 235.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 38)//�o����
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 215.0f;   //y
				src.m_left = 180.0f; //x
				src.m_right = 193.0f; //x
				src.m_bottom = 235.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 39)//�o����
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 235.0f;   //y
				src.m_left = 165.0f; //x
				src.m_right = 180.0f; //x
				src.m_bottom = 250.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 40)//�o����
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 235.0f;   //y
				src.m_left = 180.0f; //x
				src.m_right = 193.0f; //x
				src.m_bottom = 250.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 41)//�o����
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 250.0f;   //y
				src.m_left = 165.0f; //x
				src.m_right = 180.0f; //x
				src.m_bottom = 268.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 42)//�o����
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 250.0f;   //y
				src.m_left = 180.0f; //x
				src.m_right = 193.0f; //x
				src.m_bottom = 268.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 43)//���̋@
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 215.0f;   //y
				src.m_left = 219.0f; //x
				src.m_right = 280.0f; //x
				src.m_bottom = 260.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 44)//���̋@
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 260.0f;   //y
				src.m_left = 219.0f; //x
				src.m_right = 280.0f; //x
				src.m_bottom = 288.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 45)//�����蔻��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;   //y
				src.m_left = 0.0f; //x
				src.m_right = 0.0f; //x
				src.m_bottom = 0.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

			}
		
			if (m_map[i][j] == 46)//�o����
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 250.0f;   //y
				src.m_left = 180.0f; //x
				src.m_right = 193.0f; //x
				src.m_bottom = 268.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 64.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}
			else if (m_map[i][j] == 15)//�G
			{
				;
			}
			if (m_map[i][j] == 99)//���폤�����{�b�g�\��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;   //y
				src.m_left = 0.0f;  //x
				src.m_right = 32.0f; //x
				src.m_bottom = 32.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;//y
				dst.m_left = j * 32.0f + mx_scroll;//x
				dst.m_right = j * 32.0f + 45.0f + mx_scroll;//x
				dst.m_bottom = i * 32.0f + 45.0f + my_scroll; //y

				//5�Ԗڂɓo�^�����O���t�B�b�N��stc�Edst�Ec�̏������ɕ`��
				Draw::Draw(6, &src, &dst, c, 0.0f);
			}
		}
	}
}
