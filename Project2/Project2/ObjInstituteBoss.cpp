//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameL\SceneObjManager.h"
#include"GameHead.h"
#include"ObjInstituteBoss.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjInstituteBoss::Init()
{
	mx_scroll = -990.0f;
	my_scroll = 200.0f;

	//�}�b�v���
	int block_data[50][51] =
	{
		{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,19,20,1,1,1,1,1,1},
		{0,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,2,2,2,2,2,1},
		{0,1,0,0,5,6,0,0,5,6,0,0,5,6,0,0,5,6,0,0,5,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,10,8,10,8,10,8,10,8,10,8,10,8,10,8,10,8,10,8,10,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,12,0,0,12,0,12,0,12,12,12,0,12,0,12,12,12,0,12,0,12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,5,6,0,0,5,6,0,0,5,6,0,0,5,6,0,0,5,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,10,8,10,8,10,8,10,8,10,8,10,8,10,8,10,8,10,8,10,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,8,3,8,3,8,1},
		{0,1,0,12,12,0,12,12,12,12,12,0,12,0,0,0,12,0,12,0,12,12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,0,12,12,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,1},
		{0,1,0,0,21,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,99,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,11,11,11,11,11,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,8,7,8,0,0,7,8,0,0,0,0,14,0,14,14,14,14,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,18,18,18,18,0,18,18,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,0,8,8,8,8,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,18,18,0,18,0,18,18,0,18,0,0,0,0,7,8,7,8,7,8,0,0,0,0,0,0,0,15,15,15,15,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,18,18,0,18,18,0,18,0,18,18,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,8,8,8,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,18,0,0,0,18,0,18,0,18,18,0,0,0,0,7,8,0,0,7,8,7,8,0,0,0,16,16,16,0,0,16,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,8,8,0,0,8,0,0,0,1},
		{0,1,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,1},
		{0,1,0,35,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},

		

	};
	//�}�b�v�f�[�^��R�s�[
	memcpy(m_map, block_data, sizeof(int) * (50 * 51));
	map_flag = true;
	map_flag2 = false;
}
//�A�N�V����
void CObjInstituteBoss::Action()
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

	//�G�o�����C��
	float Xline = hx + (-mx_scroll) - 1000;
	float Yline = hy + (my_scroll)-50;

	int ex = ((int)Xline) / 32;
	int ey = ((int)Yline) / 32;

	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 51; j++)
		
			if (m_map[i][ex] == 21)
			{
				//�g�U�G�@�I�u�W�F�N�g�쐬
				CObjInstituteBossBoss* objs = new CObjInstituteBossBoss(ex*32.0f, i*32.0f); //Sin�G�@�I�u�W�F�N�g�쐬
				Objs::InsertObj(objs, OBJ_INSTITUTE_BOSS_BOSS, 5); //Sin�G�@�I�u�W�F�N�g��I�u�W�F�N�g�}�l�[�W���[�ɓo�^
				

				m_map[i][ex] = 0;
			}

	}

    //��l���̏Փˏ�Ԋm�F�p�t���O�̏�����
	hero->SetUp(false);
	hero->SetDown(false);
	hero->SetLeft(false);
	hero->SetRight(false);






	//m_map�̑S�v�f�ɃA�N�Z�X
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 51; j++)
		{
			if (m_map[i][j] > 0 )
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
							if (m_map[i][j] == 99)
								hero->SetBT(m_map[i][j]);//�u���b�N�̗v�f(type)���l���ɓn��
							hero->SetVX(0.0f);//-VX*�����W��
						}
						if (r > 45 && r < 135)
						{
							//��
							hero->SetDown(true);//��l���̉��̕������Փ˂��Ă���
							hero->SetY2(y - 40.0f + (my_scroll));//�u���b�N�̈ʒu-��l���̕�
							if (m_map[i][j] == 99)
								hero->SetBT(m_map[i][j]);//�u���b�N�̗v�f(type)���l���ɓn��
							hero->SetVY(0.0f);//-VX*�����W��

						}
						if (r > 135 && r < 225)
						{
							//��
							hero->SetLeft(true);//��l���̉E�̕������Փ˂��Ă���
							hero->SetX2(x - 40.0f + (mx_scroll));//�u���b�N�̈ʒu-��l���̕�
							if (m_map[i][j] == 99)
								hero->SetBT(m_map[i][j]);//�u���b�N�̗v�f(type)���l���ɓn��
							hero->SetVX(0.0f);//-VX*�����W��
						}
						if (r > 225 && r < 315)
						{
							//��
							hero->SetUp(true);//��l���̏�̕������Փ˂��Ă���
							hero->SetY2(y + 40.0f + (my_scroll));//�u���b�N�̈ʒu+��l���̕�
							if (m_map[i][j] == 99)
								hero->SetBT(m_map[i][j]);//�u���b�N�̗v�f(type)���l���ɓn��
							hero->SetVY(0.0f);//-VX*�����W��
						}
						
					}
					if (m_map[i][j] == 19|| m_map[i][j] == 20)//研究所13A
					{
						Scene::SetScene(new CSceneInstitute13A());
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
}
//�h���[
void CObjInstituteBoss::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�w�i�\��
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 800.0f;
	src.m_bottom = 600.0f;

	dst.m_top = 64.0f + my_scroll;
	dst.m_left = 64.0f + mx_scroll;
	dst.m_right = 1600.0f + mx_scroll;
	dst.m_bottom = 900.0f + my_scroll;
	Draw::Draw(12, &src, &dst, c, 0.0f);

	//�}�b�v�`�b�v�ɂ��block�ݒu
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 51; j++)
		{
			if (m_map[i][j] == 1)//��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;   //y
				src.m_left = 0.0f; //x
				src.m_right = 88.0f; //x
				src.m_bottom = 55.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(15, &src, &dst, c, 0.0f);

			}
			if (m_map[i][j] == 2)//��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 20.0f;   //y
				src.m_left = 118.0f; //x
				src.m_right = 145.0f; //x
				src.m_bottom = 50.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(15, &src, &dst, c, 0.0f);

			}
			if (m_map[i][j] == 3)//�p�\�R��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 15.0f;   //y
				src.m_left = 158.0f; //x
				src.m_right = 275.0f; //x
				src.m_bottom = 90.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 64.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(15, &src, &dst, c, 0.0f);

			}
			if (m_map[i][j] == 4)//�①��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 98.0f;   //y
				src.m_left = 210.0f; //x
				src.m_right = 245.0f; //x
				src.m_bottom = 165.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(15, &src, &dst, c, 0.0f);
			}
			
			if (m_map[i][j] == 5)//�e���r
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 20.0f;   //y
				src.m_left = 270.0f; //x
				src.m_right = 330.0f; //x
				src.m_bottom = 85.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(15, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 6)//�e���r
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 20.0f;   //y
				src.m_left = 330.0f; //x
				src.m_right = 385.0f; //x
				src.m_bottom = 85.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(15, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 7)//�J�v�Z��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 10.0f;   //y
				src.m_left = 380.0f; //x
				src.m_right = 460.0f; //x
				src.m_bottom = 95.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 64.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(15, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 8)//�����蔻��
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
			if (m_map[i][j] == 9)//�f�X�N
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 78.0f;   //y
				src.m_left = 20.0f; //x
				src.m_right = 90.0f; //x
				src.m_bottom = 120.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 64.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(15, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 10)//��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 88.0f;   //y
				src.m_left = 100.0f; //x
				src.m_right = 200.0f; //x
				src.m_bottom = 148.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 64.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(15, &src, &dst, c, 0.0f);
			}
			
			if (m_map[i][j] == 11)//�I
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 97.0f;   //y
				src.m_left = 252.0f; //x
				src.m_right = 294.0f; //x
				src.m_bottom = 143.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(15, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 12)//�֎q
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 96.0f;   //y
				src.m_left = 302.0f; //x
				src.m_right = 333.0f; //x
				src.m_bottom = 145.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(15, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 13)//�֎q
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 95.0f;   //y
				src.m_left = 345.0f; //x
				src.m_right = 376.0f; //x
				src.m_bottom = 140.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(15, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 14)//�J�v�Z��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 95.0f;   //y
				src.m_left = 387.0f; //x
				src.m_right = 417.0f; //x
				src.m_bottom = 165.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(15, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 15)//�J�v�Z��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 94.0f;   //y
				src.m_left = 422.0f; //x
				src.m_right = 454.0f; //x
				src.m_bottom = 164.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(15, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 16)//�J�v�Z��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 133.0f;   //y
				src.m_left = 15.0f; //x
				src.m_right = 48.0f; //x
				src.m_bottom = 200.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(15, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 17)//��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 148.0f;   //y
				src.m_left = 61.0f; //x
				src.m_right = 90.0f; //x
				src.m_bottom = 201.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(15, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 18)//�J�v�Z��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 149.0f;   //y
				src.m_left = 103.0f; //x
				src.m_right = 131.0f; //x
				src.m_bottom = 202.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(15, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 19)//�K�i
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 180.0f;   //y
				src.m_left = 156.0f; //x
				src.m_right = 282.0f; //x
				src.m_bottom = 300.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 63.8f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//�`��
				Draw::Draw(15, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 20)//�����蔻��
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
			if (m_map[i][j] == 99)//�@���u���{�b�g�\��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;   //y
				src.m_left = 0.0f;  //x
				src.m_right = 32.0f; //x
				src.m_bottom = 32.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;//y
				dst.m_left = j * 32.0f + mx_scroll;//x
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;//x
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll; //y

				//1�Ԗڂɓo�^�����O���t�B�b�N��stc�Edst�Ec�̏�����ɕ`��

				Draw::Draw(31, &src, &dst, c, 0.0f);
			}
		}
		
	}
}