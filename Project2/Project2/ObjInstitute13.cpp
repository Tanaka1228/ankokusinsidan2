//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL/DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"

#include"GameHead.h"
#include "ObjInstitute13.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjInstitute13::Init()
{
	mx_scroll = -430.0f;
	my_scroll = -380.0f;

	//�}�b�v���
	int block_data[70][70] =
	{
		{1,1,1,1,1,1,1,1,1,50,1,1,1,1,1,1,1,1,1,25,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,25,1,1,1,1,1,1,1,1,1},
		{1,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,23,23,0,0,0,0,0,0,0,0,0,5,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,60,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,60,1,1,1,1,1,1,1,1,1},
		{1,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,61,0,0,0,0,0,25,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,23,23,0,0,0,0,62,0,0,0,0,5,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,20,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,19,19,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,70,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,25,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4,1,1,1,1,1,1,1,60,1,1,1,1,1,1,1,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,5,0,0,0,0,0,0,63,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,64,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,60,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,25,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1},
	    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1}, 
	    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,10,0,1},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,2,50,1,1,1,1,1,1},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,50,50,0,0,0,0,0,0},
	};
	//�}�b�v�f�[�^��R�s�[
	memcpy(m_map, block_data, sizeof(int) * (70 * 70));
	map_flag = true;
	map_flag2 = false;
	

}
//�A�N�V����
void CObjInstitute13::Action()
{
	//��l���̈ʒu��擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX2();//�X�N���[��
	float hy = hero->GetY2();

	//踏んでいるblockの種類を初期化
	hero->SetBT(0);

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
	for (int i = 0; i < 70; i++)
	{
		for (int j = 0; j < 70; j++)
		{
			if (m_map[i][j] > 0)
			{

				//�v�f�ԍ�����W�ɕύX
				float x = j * 32.0f;
				float y = i * 32.0f;

				//��l���ƃu���b�N�̓����蔻��
				if ((hx + (-mx_scroll) + 64.0f > x) && (hx + (-mx_scroll) < x + 64.0f) && (hy + (-my_scroll) + 64.0f > y) && (hy + (-my_scroll) < y + 64.0f))
				{

					//�㉺���E����

					//vector�̍쐬
					float vx = (hx + (-mx_scroll)) - x;
					float vy = (hy + (-my_scroll)) - y;

					//��������߂�
					float len = sqrt(vx * vx + vy * vy);//sqrt�֐��́A��������Ԃ�

					//�p�x����߂�
					float r = atan2(vy, vx);//atan2�֐��̓A�[�N�^���W�F���g��Ԃ�
					r = r * 180.0f / 3.14f;

					if (r <= 0.0f)//abs�֐��́A�l�̐�Βl����߂� �����𖳎������l
						r = abs(r);
					else
						r = 360.0f - abs(r);

					//len��������̒����̂��Z���ꍇ����ɓ���
					if (len < 44.0f)
					{

						//�p�x�ŏ㉺���E�𔻒�
						if ((r < 45 && r >= 0) || r > 315)
						{
							//�E
							hero->SetRight(true);//��l���̍��̕������Փ˂��Ă���
							hero->SetX2(x + 40.0f + (mx_scroll));//�u���b�N�̈ʒu+��l���̕�
							hero->SetBT(m_map[i][j]);
							hero->SetVX(0.0f);//-VX*�����W��
						}
						if (r > 45 && r < 135)
						{
							//��
							hero->SetDown(true);//��l���̉��̕������Փ˂��Ă���
							hero->SetY2(y - 40.0f + (my_scroll));//�u���b�N�̈ʒu-��l���̕�
							hero->SetBT(m_map[i][j]);
							hero->SetVY(0.0f);//-VX*�����W��

						}
						if (r > 135 && r < 225)
						{
							//��
							hero->SetLeft(true);//��l���̉E�̕������Փ˂��Ă���
							hero->SetX2(x - 40.0f + (mx_scroll));//�u���b�N�̈ʒu-��l���̕�
							hero->SetBT(m_map[i][j]);
							hero->SetVX(0.0f);//-VX*�����W��
						}
						if (r > 225 && r < 315)
						{
							//��
							hero->SetUp(true);//��l���̏�̕������Փ˂��Ă���
							hero->SetY2(y + 40.0f + (my_scroll));//�u���b�N�̈ʒu+��l���̕�
							hero->SetBT(m_map[i][j]);
							hero->SetVY(0.0f);//-VX*�����W��
						}
						

						if ( m_map[i][j] == 4)//������14
						{
							Scene::SetScene(new CSceneInstitute14());
						}
						if (m_map[i][j] == 2|| m_map[i][j] == 50)//������BOSS
						{
							Scene::SetScene(new CSceneInstituteBoss());
						}
						if (m_map[i][j] == 61)//������1
						{
							Scene::SetScene(new CSceneInstitute1());
						}
						if (m_map[i][j] == 62)//������2
						{
							Scene::SetScene(new CSceneInstitute2());
						}
						if (m_map[i][j] == 63)//������3
						{
							Scene::SetScene(new CSceneInstitute3());
						}
						if (m_map[i][j] == 64)//������4
						{
							Scene::SetScene(new CSceneInstitute4());
						}
					}
				}



			}
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
	//�G�o�����C��
	//float Xline = hx + (-mx_scroll) + 400;
	//float Yline = hy + (my_scroll)-100;

	//int ex = ((int)Xline) / 32;
	//int ey = ((int)Yline) / 32;

	//for (int i = 0; i < 25; i++)
	//{
	//	for (int j = 0; j < 25; j++)

	//		if (m_map[i][ex] == 15)
	//		{
	//			//�U���G�@�I�u�W�F�N�g�쐬
	//			CObjRooftopBoss* obj_rooftop_boss = new CObjRooftopBoss(ex * 32, i * 32); //�U���G�@�I�u�W�F�N�g�쐬
	//			Objs::InsertObj(obj_rooftop_boss, OBJ_ROOF_TOP_BOSS, 4); //�U���G�@�I�u�W�F�N�g��I�u�W�F�N�g�}�l�[�W���[�ɓo�^

	//			m_map[i][ex] = 0;
	//		}


	//}

}
//�h���[
void CObjInstitute13::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�w�i�\��
	src.m_top = 73.0f;   // Y
	src.m_left = 21.0f;  // X
	src.m_right = 106.0f; // X
	src.m_bottom = 196.0f;// Y 

	dst.m_top = 0.0f + my_scroll;
	dst.m_left = 0.0f + mx_scroll;
	dst.m_right = 1990.0f + mx_scroll;
	dst.m_bottom = 1000.0 + my_scroll;
	Draw::Draw(30, &src, &dst, c, 0.0f);

	//�}�b�v�`�b�v�ɂ��block�ݒu
	for (int i = 0; i < 70; i++)
	{
		for (int j = 0; j < 70; j++)
		{

			if (m_map[i][j] == 1)//��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 73.0f;   //y
				src.m_left = 3.0f; //x
				src.m_right = 61.0f; //x
				src.m_bottom = 130.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}


			if (m_map[i][j] == 4)//�G���x�[�^�[
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 2.0f;   //y
				src.m_left = 136.0f; //x
				src.m_right = 190.0f; //x
				src.m_bottom = 4.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 2)//�K�i
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 277.0f;   //y
				src.m_left = 220.0f; //x
				src.m_right = 289.0f; //x
				src.m_bottom = 346.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 64.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;
			}
				//�`��
				Draw::Draw(5, &src, &dst, c, 0.0f);
			
			if (m_map[i][j] == 5)//��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 2.0f;   //y
				src.m_left = 208.0f; //x
				src.m_right = 231.0f; //x
				src.m_bottom = 59.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 6)//�R�s�[�@
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 4.0f;   //y
				src.m_left = 237.0f; //x
				src.m_right = 265.0f; //x
				src.m_bottom = 48.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 7)//��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 6.0f;   //y
				src.m_left = 335.0f; //x
				src.m_right = 397.0f; //x
				src.m_bottom = 44.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 8)//�f�X�N
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 4.0f;   //y
				src.m_left = 397.0f; //x
				src.m_right = 456.0f; //x
				src.m_bottom = 44.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 9)//��������
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 77.0f;   //y
				src.m_left = 76.0f; //x
				src.m_right = 137.0f; //x
				src.m_bottom = 120.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 18)//�I
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 72.0f;   //y
				src.m_left = 143.0f; //x
				src.m_right = 178.0f; //x
				src.m_bottom = 123.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 10)//���K���X
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 69.0f;   //y
				src.m_left = 194.0f; //x
				src.m_right = 238.0f; //x
				src.m_bottom = 140.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 11)//�K�i
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 80.0f;   //y
				src.m_left = 255.0f; //x
				src.m_right = 306.0f; //x
				src.m_bottom = 135.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 12)//���̋@
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 74.0f;   //y
				src.m_left = 317.0f; //x
				src.m_right = 365.0f; //x
				src.m_bottom = 82.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 13)//���j�^�[1
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 81.0f;   //y
				src.m_left = 366.0f; //x
				src.m_right = 422.0f; //x
				src.m_bottom = 120.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 14)//�p�\�R��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 85.0f;   //y
				src.m_left = 436.0f; //x
				src.m_right = 471.0f; //x
				src.m_bottom = 121.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 15)//�֎q
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 150.0f;   //y
				src.m_left = 18.0f; //x
				src.m_right = 39.0f; //x
				src.m_bottom = 181.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 16)//��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 153.0f;   //y
				src.m_left = 78.0f; //x
				src.m_right = 110.0f; //x
				src.m_bottom = 186.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 17)//�}�b�g
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 156.0f;   //y
				src.m_left = 121.0f; //x
				src.m_right = 181.0f; //x
				src.m_bottom = 189.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 19)//�z���C�g�{�[�h
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 150.0f;   //y
				src.m_left = 199.0f; //x
				src.m_right = 266.0f; //x
				src.m_bottom = 194.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 21)//�c���搶�̑��_
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 153.0f;   //y
				src.m_left = 274.0f; //x
				src.m_right = 330.0f; //x
				src.m_bottom = 196.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 22)//�R�s�[�@
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 146.0f;   //y
				src.m_left = 351.0f; //x
				src.m_right = 398.0f; //x
				src.m_bottom = 199.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 23)//�ו�����
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 150.0f;   //y
				src.m_left = 402.0f; //x
				src.m_right = 459.0f; //x
				src.m_bottom = 199.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 24)//���j�^�[�Q
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 6.0f;   //y
				src.m_left = 196.0f; //x
				src.m_right = 73.0f; //x
				src.m_bottom = 252.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 25)//�p�l��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 194.0f;   //y
				src.m_left = 90.0f; //x
				src.m_right = 143.0f; //x
				src.m_bottom = 271.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 26)//���Ί�
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 271.0f;   //y
				src.m_left = 120.0f; //x
				src.m_right = 193.0f; //x
				src.m_bottom = 245.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 27)//�S�~��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 205.0f;   //y
				src.m_left = 215.0f; //x
				src.m_right = 248.0f; //x
				src.m_bottom = 251.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 28)//����
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 209.0f;   //y
				src.m_left = 325.0f; //x
				src.m_right = 351.0f; //x
				src.m_bottom = 264.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 29)//��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 223.0f;   //y
				src.m_left = 380.0f; //x
				src.m_right = 421.0f; //x
				src.m_bottom = 257.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 30)//��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 212.0f;   //y
				src.m_left = 435.0f; //x
				src.m_right = 473.0f; //x
				src.m_bottom = 257.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 31)//��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 275.0f;   //y
				src.m_left = 180.0f; //x
				src.m_right = 198.0f; //x
				src.m_bottom = 318.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 50)//�����蔻��
			{	
			}
			if (m_map[i][j] == 60)//�������h�A
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 371.0f;   //y
				src.m_left = 39.0f; //x
				src.m_right = 114.0f; //x
				src.m_bottom = 440.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			
			if (m_map[i][j] == 61)//�����蔻��
			{
			}
			if (m_map[i][j] == 62)//�����蔻��
			{
			}
			if (m_map[i][j] == 63)//�����蔻��
			{
			}
			if (m_map[i][j] == 64)//�����蔻��
			{
			}
			if (m_map[i][j] == 70)//　モブロボット表示
			{
				//切り取り位置の設定
				src.m_top = 0.0f;   //y
				src.m_left = 0.0f;  //x
				src.m_right = 32.0f; //x
				src.m_bottom = 32.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;//y
				dst.m_left = j * 32.0f + mx_scroll;//x
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;//x
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll; //y

				//1番目に登録したグラフィックをstc・dst・cの情報を元に描画

				Draw::Draw(6, &src, &dst, c, -1.0f);
			}
			
		}
	}
}