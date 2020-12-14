//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL/DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"

#include"GameHead.h"
#include "ObjDrugCampanyRoom12.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

extern int Drug_Hero_x;
//�C�j�V�����C�Y
void CObjDrugCampanyRoom12::Init()
{
	mx_scroll = 0.0f;
	my_scroll = +220.0f;

	Drug_Hero_x = 12;
	//�}�b�v���
	int block_data[200][200] =
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,0,0,28,28,28,0,0,0,0,0,0,0,0,14,14,14,14,0,0,0,0,0,0,0,0,28,28,28,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,0,0,28,28,28,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,28,28,28,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,0,0,28,28,28,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,28,28,28,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,0,0,28,28,28,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,28,28,28,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,0,0,28,28,28,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,28,28,28,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,0,0,28,28,28,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,28,28,28,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,0,0,28,28,28,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,28,28,28,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,0,0,28,28,28,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,28,28,28,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},


	};
	//�}�b�v�f�[�^���R�s�[
	memcpy(m_map, block_data, sizeof(int) * (200 * 200));

}
//�A�N�V����
void CObjDrugCampanyRoom12::Action()
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
	for (int i = 0; i < 200; i++)
	{
		for (int j = 0; j < 200; j++)
		{
			if (m_map[i][j] > 0 && m_map[i][j] != 15)
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
					if (len < 44.0f)
					{

						//�p�x�ŏ㉺���E�𔻒�
						if ((r < 45 && r >= 0) || r > 315)
						{
							//�E
							hero->SetRight(true);//��l���̍��̕������Փ˂��Ă���
							hero->SetX2(x + 40.0f + (mx_scroll));//�u���b�N�̈ʒu+��l���̕�
							hero->SetVX(0.0f);//-VX*�����W��
						}
						if (r > 45 && r < 135)
						{
							//��
							hero->SetDown(true);//��l���̉��̕������Փ˂��Ă���
							hero->SetY2(y - 40.0f + (my_scroll));//�u���b�N�̈ʒu-��l���̕�
							hero->SetVY(0.0f);//-VX*�����W��

						}
						if (r > 135 && r < 225)
						{
							//��
							hero->SetLeft(true);//��l���̉E�̕������Փ˂��Ă���
							hero->SetX2(x - 40.0f + (mx_scroll));//�u���b�N�̈ʒu-��l���̕�
							hero->SetVX(0.0f);//-VX*�����W��
						}
						if (r > 225 && r < 315)
						{
							//��
							hero->SetUp(true);//��l���̏�̕������Փ˂��Ă���
							hero->SetY2(y + 40.0f + (my_scroll));//�u���b�N�̈ʒu+��l���̕�
							hero->SetVY(0.0f);//-VX*�����W��
						}
						if (m_map[i][j] == 5)//�ړ�
						{
							Scene::SetScene(new CSceneDrugCampany());
						}
					}
				}



			}
		}
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
	//			Objs::InsertObj(obj_rooftop_boss, OBJ_ROOF_TOP_BOSS, 4); //�U���G�@�I�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^

	//			m_map[i][ex] = 0;
	//		}


	//}

}
//�h���[
void CObjDrugCampanyRoom12::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�w�i�\��
	src.m_top = 0.0f;   // Y
	src.m_left = 0.0f;  // X
	src.m_right = 500.0f; // X
	src.m_bottom = 500.0f;// Y 

	dst.m_top = 0.0f + my_scroll;
	dst.m_left = 0.0f + mx_scroll;
	dst.m_right = 4400.0f + mx_scroll;
	dst.m_bottom = 4400.0 + my_scroll;
	Draw::Draw(5, &src, &dst, c, 0.0f);

	//�}�b�v�`�b�v�ɂ��block�ݒu
	for (int i = 0; i < 200; i++)
	{
		for (int j = 0; j < 200; j++)
		{
			if (m_map[i][j] == 1)//��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 239.0f;   //y
				src.m_left = 211.0f; //x
				src.m_right = 310.0f; //x
				src.m_bottom = 309.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 2)//���U��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 288.0f;   //y
				src.m_left = 175.0f; //x
				src.m_right = 211.0f; //x
				src.m_bottom = 309.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 3)//�P����
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 347.0f;   //y
				src.m_left = 106.0f; //x
				src.m_right = 179.0f; //x
				src.m_bottom = 389.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 33.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 4)//	���̋@
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 318.0f;   //y
				src.m_left = 0.0f; //x
				src.m_right = 70.0f; //x
				src.m_bottom = 388.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 33.5f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.5f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 5)//���P
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 236.0f;   //y
				src.m_left = 535.0f; //x
				src.m_right = 581.0f; //x
				src.m_bottom = 307.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 6)//���Q
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 237.0f;   //y
				src.m_left = 591.0f; //x
				src.m_right = 620.0f; //x
				src.m_bottom = 311.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 7)//�G���x�[�^�[
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 325.0f;   //y
				src.m_left = 191.0f; //x
				src.m_right = 236.0f; //x
				src.m_bottom = 387.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}
			if (m_map[i][j] == 8)//CT�X�L����
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 4.0f;   //y
				src.m_left = 0.0f; //x
				src.m_right = 83.0f; //x
				src.m_bottom = 127.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 9)//PC
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 74.0f;   //y
				src.m_left = 89.0f; //x
				src.m_right = 183.0f; //x
				src.m_bottom = 127.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 10)//�f�X�N�g�b�vPC
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 68.0f;   //y
				src.m_left = 188.0f; //x
				src.m_right = 223.0f; //x
				src.m_bottom = 127.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 33.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 11)//�䐅��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;   //y
				src.m_left = 227.0f; //x
				src.m_right = 293.0f; //x
				src.m_bottom = 127.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 33.5f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.5f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 12)//�J�[�e��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 76.0f;   //y
				src.m_left = 297.0f; //x
				src.m_right = 404.0f; //x
				src.m_bottom = 127.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 13)//��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 50.0f;   //y
				src.m_left = 407.0f; //x
				src.m_right = 549.0f; //x
				src.m_bottom = 128.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 14)//�z���C�g�{�[�h
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 179.0f;   //y
				src.m_left = 124.0f; //x
				src.m_right = 229.0f; //x
				src.m_bottom = 223.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 15)//�����g�Q���i�����g�j
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 198.0f;   //y
				src.m_left = 232.0f; //x
				src.m_right = 225.0f; //x
				src.m_bottom = 223.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 16)//�����g�Q���i��j
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 207.0f;   //y
				src.m_left = 257.0f; //x
				src.m_right = 281.0f; //x
				src.m_bottom = 223.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 17)//�����g�Q���i�㔼�g�j
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 198.0f;   //y
				src.m_left = 283.0f; //x
				src.m_right = 206.0f; //x
				src.m_bottom = 223.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 18)//�����g�Q���i���j
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 201.0f;   //y
				src.m_left = 308.0f; //x
				src.m_right = 326.0f; //x
				src.m_bottom = 223.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 19)//�e�[�u��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 152.0f;   //y
				src.m_left = 328.0f; //x
				src.m_right = 434.0f; //x
				src.m_bottom = 223.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 20)//�e�[�u��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 152.0f;   //y
				src.m_left = 434.0f; //x
				src.m_right = 469.0f; //x
				src.m_bottom = 223.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 21)//�@�B�P
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 158.0f;   //y
				src.m_left = 473.0f; //x
				src.m_right = 542.0f; //x
				src.m_bottom = 223.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 22)//�����ǂP
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 202.0f;   //y
				src.m_left = 544.0f; //x
				src.m_right = 572.0f; //x
				src.m_bottom = 223.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 23)//�����ǂQ
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 202.0f;   //y
				src.m_left = 580.0f; //x
				src.m_right = 607.0f; //x
				src.m_bottom = 223.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 24)//�{�I�P
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 240.0f;   //y
				src.m_left = 0.0f; //x
				src.m_right = 36.0f; //x
				src.m_bottom = 308.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 25)//�{�I�Q
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 240.0f;   //y
				src.m_left = 35.0f; //x
				src.m_right = 106.0f; //x
				src.m_bottom = 308.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 26)//�I
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 240.0f;   //y
				src.m_left = 105.0f; //x
				src.m_right = 175.0f; //x
				src.m_bottom = 308.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 27)//�{�I�R
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 238.0f;   //y
				src.m_left = 317.0f; //x
				src.m_right = 423.0f; //x
				src.m_bottom = 308.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 28)//��i�I
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 274.0f;   //y
				src.m_left = 423.0f; //x
				src.m_right = 493.0f; //x
				src.m_bottom = 310.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 29)//�b�c
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 270.0f;   //y
				src.m_left = 493.0f; //x
				src.m_right = 530.0f; //x
				src.m_bottom = 309.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 30)//�S�~��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 335.0f;   //y
				src.m_left = 69.0f; //x
				src.m_right = 107.0f; //x
				src.m_bottom = 387.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}
		}
	}
}