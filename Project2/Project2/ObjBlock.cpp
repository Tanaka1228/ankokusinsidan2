//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL/DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"
#include"GameL/HitBoxManager.h"
#include"GameL/Audio.h"

#include"GameHead.h"
#include"ObjBlock.h"
#include"UtilityModule.h"



//�g�p����l�[���X�y�[�X
using namespace GameL;

extern int ChinaTown_Hero_x;

//�C�j�V�����C�Y
void CObjBlock::Init()
{
	mx_scroll = 0.0f;
	my_scroll = 20.0f;

	ChinaTown_Hero_x = 0;
	//�}�b�v���
	int block_data[25][25] =
	{

		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,0,0},
		{0,0,15,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,15,0,0},
		{0,0,15,3,4,5,4,5,4,5,0,1,0,0,0,0,0,0,0,0,0,0,15,0,0},
		{0,0,15,3,6,7,6,7,6,7,0,1,2,0,0,0,0,0,0,0,0,0,15,0,0},
		{0,0,15,0,0,0,20,0,0,0,0,1,2,0,0,0,17,0,0,0,0,0,15,0,0},
		{0,0,15,8,8,8,8,8,8,8,8,8,2,0,0,0,0,0,0,0,0,0,15,0,0},
		{0,0,15,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,15,0,0},
		{0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0},
		{0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0},
		{0,0,15,0,0,0,0,0,0,0,0,2,9,10,2,0,2,9,10,2,0,0,15,0,0},
		{0,0,15,0,0,0,0,0,0,0,0,2,11,12,2,0,2,11,12,2,0,0,15,0,0},
		{0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0},
		{0,0,15,0,0,0,0,0,0,0,0,2,9,10,2,0,2,9,10,2,0,0,15,0,0},
		{0,0,15,0,0,0,0,0,0,0,0,2,11,12,2,0,2,11,12,2,0,0,15,0,0},
		{0,0,13,13,24,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,0,0},
		{0,0,14,14,23,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,0,0},
		{0,0,14,14,16,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,0,0},

		



	};
	//�}�b�v�f�[�^���R�s�[
	memcpy(m_map, block_data, sizeof(int) * (25 * 25));
	map_flag = true;
	map_flag2 = false;

}
//�A�N�V����
void CObjBlock::Action()
{
	//��l���̈ʒu���擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX2();
	float hy = hero->GetY2();

	

	//����ł���block�̎�ނ�������
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
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			

			if (m_map[i][j] > 0)
			{
				
				//�v�f�ԍ������W�ɕύX
				float x = j * 32.0f;
				float y = i * 32.0f;

				//��l���ƃu���b�N�̓����蔻��
				if ((hx + (-mx_scroll) + 64.0f > x) && (hx + (-mx_scroll) < x + 64.0f) && (hy + (-my_scroll) + 64.0f > y) && (hy + (-my_scroll) < y +64.0f))
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
					if (len < 45.4f)
					{

						//�p�x�ŏ㉺���E�𔻒�
						if ((r < 45 && r >= 0)||r>315)
						{
							//�E
							hero->SetRight(true);//��l���̍��̕������Փ˂��Ă���
							hero->SetX2(x + 40.0f + (mx_scroll));//�u���b�N�̈ʒu+��l���̕�
							if(m_map[i][j]==0)
							hero->SetBT(m_map[i][j]);//�u���b�N�̗v�f(type)����l���ɓn��
							hero->SetVX(0.0f);//-VX*�����W��
						}
						if (r > 45 && r < 135)
						{
							//��
							hero->SetDown(true);//��l���̉��̕������Փ˂��Ă���
							hero->SetY2(y - 40.0f + (my_scroll));//�u���b�N�̈ʒu-��l���̕�
							if (m_map[i][j] == 17)
							hero->SetBT(m_map[i][j]);//�u���b�N�̗v�f(type)����l���ɓn��
							hero->SetVY(0.0f);//-VX*�����W��
	
						}
						if (r > 135 && r < 225)
						{
							//��
							hero->SetLeft(true);//��l���̉E�̕������Փ˂��Ă���
							hero->SetX2(x - 40.0f + (mx_scroll));//�u���b�N�̈ʒu-��l���̕�
							if (m_map[i][j] == 0)
							hero->SetBT(m_map[i][j]);//�u���b�N�̗v�f(type)����l���ɓn��
							hero->SetVX(0.0f);//-VX*�����W��
						}
						if (r > 225 && r < 315)
						{
							//��
							hero->SetUp(true);//��l���̏�̕������Փ˂��Ă���
							hero->SetY2(y + 40.0f + (my_scroll));//�u���b�N�̈ʒu+��l���̕�
							if (m_map[i][j] == 17)
							hero->SetBT(m_map[i][j]);//�u���b�N�̗v�f(type)����l���ɓn��
							hero->SetVY(0.0f);//-VX*�����W��

						}

					}

					if (m_map[i][j] == 24)//�O�Ɉړ�����ƃ`���C�i�^�E��
					{
						Audio::Start(4);
						Sleep(300);//0.3�����~�߂�
						Scene::SetScene(new CSceneChinaTown());
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
void CObjBlock::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu
	

	//�w�i�\��
	src.m_top = 0.0f;
	src.m_left = 10.0f;
	src.m_right = 500.0f;
	src.m_bottom = 500.0f;

	dst.m_top = 85.0f + my_scroll;
	dst.m_left = 96.0f + mx_scroll;
	dst.m_right = 704.0f + mx_scroll;
	dst.m_bottom = 514.0f + my_scroll;
	Draw::Draw(9, &src, &dst, c, 0.0f);

	//�}�b�v�`�b�v�ɂ��block�ݒu
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			

			if (m_map[i][j] == 1)
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 135.0f;   //y
				src.m_left = 315.0f; //x
				src.m_right = 450.0f; //x
				src.m_bottom = 215.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i*32.0f + my_scroll;
				dst.m_left = j*32.0f + mx_scroll;
				dst.m_right = j*32.0f+32.0f + mx_scroll;
				dst.m_bottom =i* 32.0f+32.0f + my_scroll;

				//�`��
				Draw::Draw(8, &src, &dst, c, 0.0f);			
			}
			if (m_map[i][j] == 2)
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;   //y
				src.m_left = 220.0f; //x
				src.m_right =  280.0f; //x
				src.m_bottom = 60.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0 + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f+ mx_scroll;
				dst.m_bottom = i * 32.0f+ 32.0f + my_scroll;

				//�`��
				Draw::Draw(8, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 3)
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 60.0f;   //y
				src.m_left = 220.0f; //x
				src.m_right = 280.0f; //x
				src.m_bottom = 115.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0 + mx_scroll;
				dst.m_right = j * 32.0f + 32.0 + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0 + my_scroll;

				//�`��
				Draw::Draw(8, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 4)
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;   //y
				src.m_left = 350.0f; //x
				src.m_right = 380.0f; //x
				src.m_bottom = 45.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0 + mx_scroll;
				dst.m_right = j * 32.0f + 32.0 + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0 + my_scroll;

				//�`��
				Draw::Draw(8, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 5)
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;   //y
				src.m_left = 380.0f; //x
				src.m_right = 420.0f; //x
				src.m_bottom = 45.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0 + mx_scroll;
				dst.m_right = j * 32.0f + 32.0 + mx_scroll;
				dst.m_bottom = i* 32.0f + 32.0 + my_scroll;

				//�`��
				Draw::Draw(8, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 6)
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 45.0f;   //y
				src.m_left = 350.0f; //x
				src.m_right = 380.0f; //x
				src.m_bottom = 80.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0 + mx_scroll;
				dst.m_right = j * 32.0f + 32.0 + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0 + my_scroll;

				//�`��
				Draw::Draw(8, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 7)
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 45.0f;   //y
				src.m_left = 380.0f; //x
				src.m_right = 420.0f; //x
				src.m_bottom = 80.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0 + mx_scroll;
				dst.m_right = j * 32.0f + 32.0 + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0 + my_scroll;

				//�`��
				Draw::Draw(8, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 8)
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 135.0f;   //y
				src.m_left = 320.0f; //x
				src.m_right = 435.0f; //x
				src.m_bottom = 315.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0 + mx_scroll;
				dst.m_right = j * 32.0f + 32.0 + mx_scroll;
				dst.m_bottom=  i * 32.0f + 32.0 + my_scroll;

				//�`��
				Draw::Draw(8, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 9)
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 150.0f;   //y
				src.m_left = 10.0f; //x
				src.m_right = 140.0f; //x
				src.m_bottom = 205.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0 + mx_scroll;
				dst.m_right = j * 32.0f + 32.0 + mx_scroll;
				dst.m_bottom = i* 32.0f + 32.0 + my_scroll;

				//�`��
				Draw::Draw(8, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 10)
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 150.0f;   //y
				src.m_left = 140.0f; //x
				src.m_right = 255.0f; //x
				src.m_bottom = 205.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0 + mx_scroll;
				dst.m_right = j * 32.0f + 32.0 + mx_scroll;
				dst.m_bottom = i* 32.0f + 32.0 + my_scroll;

				//�`��
				Draw::Draw(8, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 11)
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 205.0f;   //y
				src.m_left = 10.0f; //x
				src.m_right = 140.0f; //x
				src.m_bottom = 295.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0 + mx_scroll;
				dst.m_right = j * 32.0f + 32.0 + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0 + my_scroll;

				//�`��
				Draw::Draw(8, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 12)
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 205.0f;   //y
				src.m_left = 140.0f; //x
				src.m_right = 255.0f; //x
				src.m_bottom = 295.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0 + mx_scroll;
				dst.m_right = j * 32.0f + 32.0 + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0 + my_scroll;

				//�`��
				Draw::Draw(8, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 13)
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 295.0f;   //y
				src.m_left = 200.0f; //x
				src.m_right = 265.0f; //x
				src.m_bottom = 360.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(8, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 14)
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 300.0f;   //y
				src.m_left = 110.0f; //x
				src.m_right = 170.0f; //x
				src.m_bottom = 365.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f+ my_scroll;

				//�`��
				Draw::Draw(8, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 15)
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 345.0f;   //y
				src.m_left = 325.0f; //x
				src.m_right = 380.0f; //x
				src.m_bottom = 405.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f+ my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//�`��
				Draw::Draw(8, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 17)//���̎q�\��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;   //y
				src.m_left = 0.0f;  //x
				src.m_right = 255.0f; //x
				src.m_bottom = 255.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i*32.0f + my_scroll;//y
				dst.m_left = j*32.0f + mx_scroll;//x
				dst.m_right = j * 32.0f +32.0f + mx_scroll;//x
				dst.m_bottom = i * 32.0f +32.0f + my_scroll; //y

				//5�Ԗڂɓo�^�����O���t�B�b�N��stc�Edst�Ec�̏������ɕ`��
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 20)//���폤�����{�b�g�\��
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
				dst.m_bottom = i* 32.0f + 32.0f + my_scroll; //y

				//5�Ԗڂɓo�^�����O���t�B�b�N��stc�Edst�Ec�̏������ɕ`��
				Draw::Draw(11, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 23)//�h�A
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 400.0f;   //y
				src.m_left = 44.0f;  //x
				src.m_right = 90.0f; //x
				src.m_bottom = 466.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;//y
				dst.m_left = j * 32.0f + mx_scroll;//x
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;//x
				dst.m_bottom =i * 32.0f + 64.0f + my_scroll; //y

				//5�Ԗڂɓo�^�����O���t�B�b�N��stc�Edst�Ec�̏������ɕ`��
				Draw::Draw(8, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 24)//�����蔻��
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 295.0f;   //y
				src.m_left = 200.0f; //x
				src.m_right = 265.0f; //x
				src.m_bottom = 360.0f; //y

				//�\���ʒu�̐ݒ�
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0 + mx_scroll;
				dst.m_right = j * 32.0f + 32.0 + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0 + my_scroll;

				//�`��
				Draw::Draw(8, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 25)//�����蔻��
			{
				
			}

			if (m_map[i][j] == 26)
			{
				
			}

			if (m_map[i][j] == 27)
			{

			}
		}
	}
}