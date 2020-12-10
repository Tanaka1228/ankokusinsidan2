//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL/DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"

#include"GameHead.h"
#include "ObjChinaTown_d.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

extern int ChinaTown_Hero_x;

//�C�j�V�����C�Y
void CObjChinaTown_d::Init()
{
	if (ChinaTown_Hero_x == 5)
	{
		mx_scroll = +300.0f;
		my_scroll = 0.0f;
	}
	if (ChinaTown_Hero_x == 8)
	{
		mx_scroll = -600.0f;
		my_scroll = +50.0f;
	}

	

	ChinaTown_Hero_x = 7;

	//�}�b�v���
	int block_data[65][54] =
	{


				   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
				   {101,0,0,82,0,0,91,91,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,97,97,97,97,97,2},
				   {101,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,97,97,97,97,97,2},
				   {101,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,97,97,97,97,97,2},
				   {101,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,97,97,97,97,97,2},
				   {101,0,0,0,0,20,0,0,0,29,0,0,0,0,0,0,0,0,0,0,0,42,0,0,0,0,0,0,97,97,97,97,97,2},
				   {101,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,97,97,97,97,97,2},
				   {101,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,97,97,97,2,2,2},
				   {101,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,97,97,97,97,97,102},
				   {101,0,0,0,0,0,0,0,0,0,0,0,48,0,0,0,0,0,0,40,0,0,0,0,0,0,0,0,97,97,97,97,97,102},
				   {101,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,97,97,97,2,2,2},
				   {101,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,97,97,97,97,97,2},
				   {101,0,0,0,0,0,0,0,0,0,90,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,97,97,97,97,97,2},
				   {101,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,97,97,97,97,97,2},
				   {101,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,97,97,97,97,97,2},
				   {101,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,97,97,97,97,97,2},
				   {101,0,0,82,0,0,91,91,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,91,91,82,0,0,0,0},
				   {101,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				   {101,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				   {101,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				   {101,0,0,0,0,20,0,0,0,29,0,0,0,0,0,0,0,0,0,0,0,42,0,0,0,0,0,0,0,0,0,0,0,0},
				   {101,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				   {101,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				   {101,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				   {101,0,0,0,0,0,0,0,0,0,0,0,48,0,0,0,0,0,0,40,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				   {101,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				   {101,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				   {101,0,0,0,0,0,0,0,0,0,90,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				   {101,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				   {101,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				   {101,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},

	};

	//�}�b�v�f�[�^��R�s�[
	memcpy(m_map, block_data, sizeof(int) * (65 * 54));
	map_flag = true;
	map_flag2 = false;
}

//�A�N�V����
void CObjChinaTown_d::Action()
{
	//��l���̈ʒu��擾
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
	for (int i = 0; i < 65; i++)
	{
		for (int j = 0; j < 54; j++)
		{
			if (m_map[i][j] > 0 && m_map[i][j] != 97)
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
							hero->SetX2(x + 39.0f + (mx_scroll));//�u���b�N�̈ʒu+��l���̕�
							hero->SetVX(0.0f);//-VX*�����W��
						}
						if (r > 45 && r < 135)
						{
							//��
							hero->SetDown(true);//��l���̉��̕������Փ˂��Ă���
							hero->SetY2(y - 39.0f + (my_scroll));//�u���b�N�̈ʒu-��l���̕�
							hero->SetVY(0.0f);//-VX*�����W��

						}
						if (r > 135 && r < 225)
						{
							//��
							hero->SetLeft(true);//��l���̉E�̕������Փ˂��Ă���
							hero->SetX2(x - 39.0f + (mx_scroll));//�u���b�N�̈ʒu-��l���̕�
							hero->SetVX(0.0f);//-VX*�����W��
						}
						if (r > 225 && r < 315)
						{
							//��
							hero->SetUp(true);//��l���̏�̕������Փ˂��Ă���
							hero->SetY2(y + 39.0f + (my_scroll));//�u���b�N�̈ʒu+��l���̕�
							hero->SetVY(0.0f);//-VX*�����W��
						}
						if (m_map[i][j] == 101)//���ɍs���ƃ`���C�i�^�E���{�X
						{
							Scene::SetScene(new CSceneChinaTown_c());
						}
						if (m_map[i][j] == 102)//上に行くと病院一階
						{
							Scene::SetScene(new CSceneInstitute());
						}

					}
				}



			}
		}
	}
	//�G�o�����C��
	//float Xline = hx + (-mx_scroll) - 1100;
	//float Yline = hy + (my_scroll)-400;

	//int ex = ((int)Xline) / 32;
	//int ey = ((int)Yline) / 32;

	//for (int i = 0; i < 65; i++)
	//{
	//	for (int j = 0; j < 54; j++)

	//		//if (m_map[i][ex] == 81)
	//		//	////�U���G�@�I�u�W�F�N�g�쐬
	//		//	//CObjChinaTownBossBoss* obj_chinatown_boss_boss = new CObjChinaTownBossBoss(ex * 32, i * 32); //�U���G�@�I�u�W�F�N�g�쐬
	//		//	//Objs::InsertObj(obj_chinatown_boss_boss, OBJ_CHINA_TOWN_BOSS_BOSS, 4); //�U���G�@�I�u�W�F�N�g��I�u�W�F�N�g�}�l�[�W���[�ɓo�^

	//			m_map[i][ex] = 0;		
	//}

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
void CObjChinaTown_d::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu


	//�w�i�\��
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 60.0f;
	src.m_bottom = 95.0f;

	dst.m_top = 0.0f + my_scroll;
	dst.m_left = 0.0f + mx_scroll;
	dst.m_right = 1090.0f + mx_scroll;
	dst.m_bottom = 2100.0f + my_scroll;
	Draw::Draw(16, &src, &dst, c, 0.0f);



	//�}�b�v�`�b�v�ɂ��block�ݒu
	for (int i = 0; i < 65; i++)
	{
		for (int j = 0; j < 54; j++)
		{
			if (m_map[i][j] == 1)//��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 18.0f;   //y
				src.m_left = 11.0f; //x
				src.m_right = 82.0f; //x
				src.m_bottom = 91.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);

			}
			if (m_map[i][j] == 2)//��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 18.0f;   //y
				src.m_left = 104.0f; //x
				src.m_right = 177.0f; //x
				src.m_bottom = 91.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 3)//�Ŕ�
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 10.0f;   //y
				src.m_left = 191.0f; //x
				src.m_right = 223.0f; //x
				src.m_bottom = 52.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 4)//�S�~��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 8.0f;   //y
				src.m_left = 232.0f; //x
				src.m_right = 313.0f; //x
				src.m_bottom = 43.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 100.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 40.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 5)//�G���x�[�^�[
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 62.0f;   //y
				src.m_left = 191.0f; //x
				src.m_right = 265.0f; //x
				src.m_bottom = 95.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 130.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 6)//���̋@
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 10.0f;   //y
				src.m_left = 327.0f; //x
				src.m_right = 366.0f; //x
				src.m_bottom = 53.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 31.9f + my_scroll;
				dst.m_left = j * 31.9f + mx_scroll;
				dst.m_right = j * 32.0f + 64.0f + mx_scroll;
				dst.m_bottom = i * 32.1f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 7)//�V���b�^�[
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 9.0f;   //y
				src.m_left = 373.0f; //x
				src.m_right = 426.0f; //x
				src.m_bottom = 49.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 8)//���O�d�b
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 44.0f;   //y
				src.m_left = 270.0f; //x
				src.m_right = 298.0f; //x
				src.m_bottom = 93.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 31.9f + my_scroll;
				dst.m_left = j * 31.9f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 9)//�����蔻��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 32.0f;   //y
				src.m_left = 32.0f; //x
				src.m_right = 32.0f; //x
				src.m_bottom = 32.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;
			}
			if (m_map[i][j] == 10)//��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 429.0f;   //y
				src.m_left = 19.0f; //x
				src.m_right = 33.0f; //x
				src.m_bottom = 447.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 11)//�o�C�N
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 55.0f;   //y
				src.m_left = 349.0f; //x
				src.m_right = 392.0f; //x
				src.m_bottom = 88.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 64.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 12)//���]�ԁ@�c
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 56.0f;   //y
				src.m_left = 401.0f; //x
				src.m_right = 430.0f; //x
				src.m_bottom = 121.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 13)//���]�ԁ@��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 71.0f;   //y
				src.m_left = 430.0f; //x
				src.m_right = 495.0f; //x
				src.m_bottom = 114.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 64.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 14)//���]�ԁ@�c
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 7.0f;   //y
				src.m_left = 439.0f; //x
				src.m_right = 470.0f; //x
				src.m_bottom = 72.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 15)//���]�ԁ@��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 95.0f;   //y
				src.m_left = 4.0f; //x
				src.m_right = 50.0f; //x
				src.m_bottom = 127.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 64.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 16)//���]�ԁ@��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 96.0f;   //y
				src.m_left = 51.0f; //x
				src.m_right = 99.0f; //x
				src.m_bottom = 128.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 64.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 17)//���]�ԁ@��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 100.0f;   //y
				src.m_left = 100.0f; //x
				src.m_right = 147.0f; //x
				src.m_bottom = 130.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 64.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 18)//�ԁ@���@�c
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 98.0f;   //y
				src.m_left = 149.0f; //x
				src.m_right = 183.0f; //x
				src.m_bottom = 141.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 30.0f + mx_scroll;
				dst.m_right = j * 30.0f + 62.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 96.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 19)//�ԁ@��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 99.0f;   //y
				src.m_left = 185.0f; //x
				src.m_right = 232.0f; //x
				src.m_bottom = 126.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 29.0f + mx_scroll;
				dst.m_right = j * 29.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 20)//�ԁ@���@��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 98.0f;   //y
				src.m_left = 272.0f; //x
				src.m_right = 323.0f; //x
				src.m_bottom = 127.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 30.0f + mx_scroll;
				dst.m_right = j * 30.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 21)//�ԁ@���@�c
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 98.0f;   //y
				src.m_left = 238.0f; //x
				src.m_right = 269.0f; //x
				src.m_bottom = 138.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 28.0f + mx_scroll;
				dst.m_right = j * 28.0f + 64.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 96.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 22)//�ԁ@�@��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 89.0f;   //y
				src.m_left = 332.0f; //x
				src.m_right = 395.0f; //x
				src.m_bottom = 122.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 28.0f + mx_scroll;
				dst.m_right = j * 28.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 23)//�ԁ@�ԁ@��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 133.0f;   //y
				src.m_left = 7.0f; //x
				src.m_right = 63.0f; //x
				src.m_bottom = 165.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 28.0f + mx_scroll;
				dst.m_right = j * 28.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 24)//�ԁ@���@��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 132.0f;   //y
				src.m_left = 66.0f; //x
				src.m_right = 116.0f; //x
				src.m_bottom = 163.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 28.0f + mx_scroll;
				dst.m_right = j * 28.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 25)//�ԁ@�ԁ@�c
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 132.0f;   //y
				src.m_left = 118.0f; //x
				src.m_right = 152.0f; //x
				src.m_bottom = 184.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 28.0f + mx_scroll;
				dst.m_right = j * 28.0f + 64.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 96.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 26)//�ԁ@�@��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 129.0f;   //y
				src.m_left = 189.0f; //x
				src.m_right = 233.0f; //x
				src.m_bottom = 156.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 28.0f + mx_scroll;
				dst.m_right = j * 28.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 27)//�ԁ@�x�[�W���@��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 131.0f;   //y
				src.m_left = 305.0f; //x
				src.m_right = 360.0f; //x
				src.m_bottom = 158.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 28.0f + mx_scroll;
				dst.m_right = j * 28.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 28)//�ԁ@��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 125.0f;   //y
				src.m_left = 364.0f; //x
				src.m_right = 416.0f; //x
				src.m_bottom = 153.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 28.0f + mx_scroll;
				dst.m_right = j * 28.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 29)//�ԁ@���@��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 122.0f;   //y
				src.m_left = 421.0f; //x
				src.m_right = 473.0f; //x
				src.m_bottom = 148.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 28.0f + mx_scroll;
				dst.m_right = j * 28.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 30)//�o�C�N�@�c
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 123.0f;   //y
				src.m_left = 477.0f; //x
				src.m_right = 492.0f; //x
				src.m_bottom = 164.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 28.0f + mx_scroll;
				dst.m_right = j * 28.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 31)//�ԁ@��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 169.0f;   //y
				src.m_left = 13.0f; //x
				src.m_right = 65.0f; //x
				src.m_bottom = 204.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 28.0f + mx_scroll;
				dst.m_right = j * 28.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 32)//�o�X�@���@��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 157.0f;   //y
				src.m_left = 159.0f; //x
				src.m_right = 234.0f; //x
				src.m_bottom = 199.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 28.0f + mx_scroll;
				dst.m_right = j * 28.0f + 128.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 33)//�ԁ@�D�F�@��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 143.0f;   //y
				src.m_left = 235.0f; //x
				src.m_right = 294.0f; //x
				src.m_bottom = 175.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 34)//�ԁ@��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 161.0f;   //y
				src.m_left = 307.0f; //x
				src.m_right = 349.0f; //x
				src.m_bottom = 191.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 64.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 35)//�ԁ@��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 158.0f;   //y
				src.m_left = 353.0f; //x
				src.m_right = 398.0f; //x
				src.m_bottom = 190.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 64.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 36)//�ԁ@��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 157.0f;   //y
				src.m_left = 408.0f; //x
				src.m_right = 477.0f; //x
				src.m_bottom = 197.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 37)//�ԁ@��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 210.0f;   //y
				src.m_left = 9.0f; //x
				src.m_right = 65.0f; //x
				src.m_bottom = 245.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 18.0f + mx_scroll;
				dst.m_right = j * 18.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 38)//�ԁ@��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 205.0f;   //y
				src.m_left = 72.0f; //x
				src.m_right = 131.0f; //x
				src.m_bottom = 240.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 18.0f + mx_scroll;
				dst.m_right = j * 18.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 39)//�ԁ@��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 205.0f;   //y
				src.m_left = 195.0f; //x
				src.m_right = 254.0f; //x
				src.m_bottom = 243.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 25.0f + mx_scroll;
				dst.m_right = j * 25.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 40)//�ԁ@��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 221.0f;   //y
				src.m_left = 261.0f; //x
				src.m_right = 311.0f; //x
				src.m_bottom = 246.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 41)//�o�X�@��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 194.0f;   //y
				src.m_left = 319.0f; //x
				src.m_right = 383.0f; //x
				src.m_bottom = 227.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 128.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 42)//�o�X�@��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 205.0f;   //y
				src.m_left = 393.0f; //x
				src.m_right = 472.0f; //x
				src.m_bottom = 246.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 128.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 43)//�ԁ@��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 229.0f;   //y
				src.m_left = 314.0f; //x
				src.m_right = 371.0f; //x
				src.m_bottom = 255.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 44)//�o�C�N�@��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 247.0f;   //y
				src.m_left = 10.0f; //x
				src.m_right = 48.0f; //x
				src.m_bottom = 269.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 64.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 45)//�o�C�N�@��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 246.0f;   //y
				src.m_left = 67.0f; //x
				src.m_right = 104.0f; //x
				src.m_bottom = 270.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 30.0f + mx_scroll;
				dst.m_right = j * 30.0f + 64.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 46)//�o�C�N�@��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 242.0f;   //y
				src.m_left = 111.0f; //x
				src.m_right = 148.0f; //x
				src.m_bottom = 274.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 64.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 47)//�ԁ@���F�@��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 245.0f;   //y
				src.m_left = 208.0f; //x
				src.m_right = 266.0f; //x
				src.m_bottom = 268.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 28.0f + mx_scroll;
				dst.m_right = j * 28.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 48)//�����W���@��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 256.0f;   //y
				src.m_left = 272.0f; //x
				src.m_right = 347.0f; //x
				src.m_bottom = 286.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 128.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 49)//��^�ԁ@��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 261.0f;   //y
				src.m_left = 355.0f; //x
				src.m_right = 436.0f; //x
				src.m_bottom = 303.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 24.0f + mx_scroll;
				dst.m_right = j * 24.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 50)//�ԁ@���F�@��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 249.0f;   //y
				src.m_left = 439.0f; //x
				src.m_right = 493.0f; //x
				src.m_bottom = 280.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 64.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 51)//�ԁ@�x�[�W���@��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 281.0f;   //y
				src.m_left = 440.0f; //x
				src.m_right = 497.0f; //x
				src.m_bottom = 315.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 64.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 52)//�ԁ@�I�����W�@��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 266.0f;   //y
				src.m_left = 159.0f; //x
				src.m_right = 214.0f; //x
				src.m_bottom = 288.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 18.0f + mx_scroll;
				dst.m_right = j * 18.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 53)//�ԁ@���@��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 275.0f;   //y
				src.m_left = 6.0f; //x
				src.m_right = 72.0f; //x
				src.m_bottom = 306.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 24.0f + mx_scroll;
				dst.m_right = j * 24.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 54)//�g���b�N�@��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 275.0f;   //y
				src.m_left = 82.0f; //x
				src.m_right = 150.0f; //x
				src.m_bottom = 316.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 55)//��^�����ԁ@��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 288.0f;   //y
				src.m_left = 153.0f; //x
				src.m_right = 222.0f; //x
				src.m_bottom = 325.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 56)//�o�C�N�@�c
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 273.0f;   //y
				src.m_left = 224.0f; //x
				src.m_right = 238.0f; //x
				src.m_bottom = 309.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 30.0f + mx_scroll;
				dst.m_right = j * 30.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 57)//�o�C�N�@�c
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 272.0f;   //y
				src.m_left = 244.0f; //x
				src.m_right = 260.0f; //x
				src.m_bottom = 315.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 58)//�ԁ@�D�F�@��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 287.0f;   //y
				src.m_left = 260.0f; //x
				src.m_right = 321.0f; //x
				src.m_bottom = 325.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 59)//�ԁ@�ΐF�@��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 302.0f;   //y
				src.m_left = 323.0f; //x
				src.m_right = 375.0f; //x
				src.m_bottom = 334.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 24.0f + mx_scroll;
				dst.m_right = j * 24.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 60)//�ԁ@�ΐF�@��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 332.0f;   //y
				src.m_left = 422.0f; //x
				src.m_right = 487.0f; //x
				src.m_bottom = 371.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 30.0f + mx_scroll;
				dst.m_right = j * 30.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 61)//�ԁ@���F�@��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 308.0f;   //y
				src.m_left = 6.0f; //x
				src.m_right = 79.0f; //x
				src.m_bottom = 348.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 62)//���]�ԁ@3�@��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 317.0f;   //y
				src.m_left = 83.0f; //x
				src.m_right = 154.0f; //x
				src.m_bottom = 336.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 224.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 63)//�����ԁ@���@��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 349.0f;   //y
				src.m_left = 3.0f; //x
				src.m_right = 51.0f; //x
				src.m_bottom = 373.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 64)//�����ԁ@���y�F�@��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 344.0f;   //y
				src.m_left = 85.0f; //x
				src.m_right = 140.0f; //x
				src.m_bottom = 374.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 26.0f + mx_scroll;
				dst.m_right = j * 26.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 65)//�����ԁ@�@������
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 382.0f;   //y
				src.m_left = 5.0f; //x
				src.m_right = 70.0f; //x
				src.m_bottom = 419.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 66)//�����ԁ@�@�E����
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 383.0f;   //y
				src.m_left = 72.0f; //x
				src.m_right = 135.0f; //x
				src.m_bottom = 419.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 67)//�����ԁ@�������@��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 348.0f;   //y
				src.m_left = 218.0f; //x
				src.m_right = 282.0f; //x
				src.m_bottom = 382.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 68)//�����ԁ@�E�����@��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 347.0f;   //y
				src.m_left = 283.0f; //x
				src.m_right = 348.0f; //x
				src.m_bottom = 381.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 69)//�����ԁ@�������@��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 393.0f;   //y
				src.m_left = 218.0f; //x
				src.m_right = 282.0f; //x
				src.m_bottom = 427.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 70)//�����ԁ@�E�����@��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 393.0f;   //y
				src.m_left = 285.0f; //x
				src.m_right = 347.0f; //x
				src.m_bottom = 427.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 71)//�����ԁ@�������@�D�F
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 444.0f;   //y
				src.m_left = 219.0f; //x
				src.m_right = 284.0f; //x
				src.m_bottom = 477.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 72)//�����ԁ@�E�����@�D�F
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 444.0f;   //y
				src.m_left = 284.0f; //x
				src.m_right = 349.0f; //x
				src.m_bottom = 477.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 73)//�����ԁ@�������@��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 373.0f;   //y
				src.m_left = 137.0f; //x
				src.m_right = 168.0f; //x
				src.m_bottom = 425.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 64.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 96.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 74)//�����ԁ@������@��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 373.0f;   //y
				src.m_left = 169.0f; //x
				src.m_right = 202.0f; //x
				src.m_bottom = 425.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 64.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 96.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 75)//�����ԁ@�������@��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 339.0f;   //y
				src.m_left = 350.0f; //x
				src.m_right = 380.0f; //x
				src.m_bottom = 385.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 64.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 96.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 76)//�����ԁ@������@��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 343.0f;   //y
				src.m_left = 381.0f; //x
				src.m_right = 412.0f; //x
				src.m_bottom = 387.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 64.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 96.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 77)//�����ԁ@�������@��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 386.0f;   //y
				src.m_left = 349.0f; //x
				src.m_right = 380.0f; //x
				src.m_bottom = 433.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 64.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 96.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 78)//�����ԁ@������@��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 388.0f;   //y
				src.m_left = 380.0f; //x
				src.m_right = 410.0f; //x
				src.m_bottom = 433.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 64.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 96.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 79)//�����ԁ@�������@�D�F
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 434.0f;   //y
				src.m_left = 350.0f; //x
				src.m_right = 382.0f; //x
				src.m_bottom = 481.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 64.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 96.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 80)//�����ԁ@������@�D�F
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 434.0f;   //y
				src.m_left = 382.0f; //x
				src.m_right = 413.0f; //x
				src.m_bottom = 481.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 64.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 96.0f + my_scroll;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 81)//����I��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 8.0f;   //y
				src.m_left = 0.0f; //x
				src.m_right = 93.0f; //x
				src.m_bottom = 134.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 120.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 120.0f + my_scroll;

				//�`��
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 82)//����
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 2.0f;   //y
				src.m_left = 111.0f; //x
				src.m_right = 212.0f; //x
				src.m_bottom = 122.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 100.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 100.0f + my_scroll;

				//�`��
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 83)//���O�d�b
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 32.0f;   //y
				src.m_left = 251.0f; //x
				src.m_right = 304.0f; //x
				src.m_bottom = 138.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 40.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 72.0f + my_scroll;

				//�`��
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 84)//����
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 24.0f;   //y
				src.m_left = 355.0f; //x
				src.m_right = 438.0f; //x
				src.m_bottom = 89.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 85)//�p�C����
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 45.0f;   //y
				src.m_left = 460.0f; //x
				src.m_right = 588.0f; //x
				src.m_bottom = 95.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 86)//��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 22.0f;   //y
				src.m_left = 607.0f; //x
				src.m_right = 708.0f; //x
				src.m_bottom = 153.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 128.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 128.0f + my_scroll;

				//�`��
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 87)//���F�̊Ŕ�
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 159.0f;   //y
				src.m_left = 9.0f; //x
				src.m_right = 79.0f; //x
				src.m_bottom = 208.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 88)//�K�[�h���[��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 157.0f;   //y
				src.m_left = 103.0f; //x
				src.m_right = 257.0f; //x
				src.m_bottom = 194.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 89)//�X��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 145.0f;   //y
				src.m_left = 353.0f; //x
				src.m_right = 388.0f; //x
				src.m_bottom = 257.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 132.0f + my_scroll;

				//�`��
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 90)//�d��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 113.0f;   //y
				src.m_left = 434.0f; //x
				src.m_right = 476.0f; //x
				src.m_bottom = 273.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 128.0f + my_scroll;

				//�`��
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 91)//���̋@
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 119.0f;   //y
				src.m_left = 514.0f; //x
				src.m_right = 587.0f; //x
				src.m_bottom = 224.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 92)//�ؔ�
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 171.0f;   //y
				src.m_left = 612.0f; //x
				src.m_right = 656.0f; //x
				src.m_bottom = 250.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 93)//�S�~��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 179.0f;   //y
				src.m_left = 671.0f; //x
				src.m_right = 717.0f; //x
				src.m_bottom = 241.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 94)//�ؔ��ƕz
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 215.0f;   //y
				src.m_left = 12.0f; //x
				src.m_right = 97.0f; //x
				src.m_bottom = 284.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 95)//�c�{
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 217.0f;   //y
				src.m_left = 228.0f; //x
				src.m_right = 260.0f; //x
				src.m_bottom = 290.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 96)//�c�{
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 298.0f;   //y
				src.m_left = 117.0f; //x
				src.m_right = 171.0f; //x
				src.m_bottom = 364.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 97)//��
			{

				//�w�i�\��
				src.m_top = 0.0f;   // Y
				src.m_left = 0.0f;  // X
				src.m_right = 30.0f; // X
				src.m_bottom = 30.0f;// Y 

				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;
				Draw::Draw(5, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 98)//�����P
			{

				//�w�i�\��
				src.m_top = 134.0f;   // Y
				src.m_left = 21.0f;  // X
				src.m_right = 182.0f; // X
				src.m_bottom = 265.0f;// Y 

				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;
				Draw::Draw(5, &src, &dst, c, 0.0f);
		}

			if (m_map[i][j] == 99)//�����Q
			{

				//�w�i�\��
				src.m_top = 232.0f;   // Y
				src.m_left = 225.0f;  // X
				src.m_right = 375.0f; // X
				src.m_bottom = 355.0f;// Y 

				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 100)//��
			{

				
				src.m_top = 73.0f;   //y
				src.m_left = 3.0f; //x
				src.m_right = 61.0f; //x
				src.m_bottom = 130.0f; //y

				
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				
				Draw::Draw(6, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 101)//�����蔻��
			{

			}
			if (m_map[i][j] == 102)//
			{

				//
				src.m_top = 0.0f;   // Y
				src.m_left = 0.0f;  // X
				src.m_right = 30.0f; // X
				src.m_bottom = 30.0f;// Y 

				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
		}
	}
}
