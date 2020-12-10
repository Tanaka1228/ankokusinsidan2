
#include"GameL\DrawTexture.h"
#include"GameL/DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"
#include"GameL/UserData.h"

#include"GameHead.h"
#include "ObjInstitute.h"


using namespace GameL;

extern int ChinaTown_Hero_x;

extern int Inst_Hero_x;


void CObjInstitute::Init()
{
	
	if (Inst_Hero_x == 5)
	{
		mx_scroll = -495.0f;
		my_scroll = +130.0f;
	}
	else if (Inst_Hero_x == 1)
	{
		mx_scroll = +110.0f;
		my_scroll = +130.0f;
	}
	else if (Inst_Hero_x == 2)
	{
		mx_scroll = -150.0f;
		my_scroll = +130.0f;
	}
	else if (Inst_Hero_x == 3)
	{
		mx_scroll = -1000.0f;
		my_scroll = +130.0f;
	}
	else if (Inst_Hero_x == 4)
	{
		mx_scroll = -1160.0f;
		my_scroll = +130.0f;
	}
	else
	{
		mx_scroll = +300.0f;
		my_scroll = -100.0f;
	}

	

	ChinaTown_Hero_x = 8;

	int block_data[60][60] =
	{

		{1,1,1,1,1,1,1,1,1,25,1,1,1,1,1,1,1,25,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,25,1,1,1,1,25,1,1,1,1,1,1,1,1,1,1},
		{1,13,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,60,1,1,1,1,1,1,1,60,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,25,1,1,1,1,25,1,1,1,1,1,1,1,1,1,1},
		{1,13,5,83,0,0,0,0,0,69,0,0,0,0,0,0,0,70,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,71,0,0,0,0,72,0,0,0,0,0,5,0,0,0,1},
		{1,13,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,13,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,13,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,13,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,13,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,13,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,13,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,13,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{74,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{74,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,73,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,13,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,13,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,30,30,0,0,0,0,0,0,0,0,1},
		{1,13,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,30,30,0,0,0,0,0,0,0,0,1},
		{1,13,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,13,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,13,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,13,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,29,29,29,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,29,29,29,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	};
	
	memcpy(m_map, block_data, sizeof(int) * (60* 60));
	map_flag = true;
	map_flag2 = false;
	Save_sp = true;
}

void CObjInstitute::Action()
{
	
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX2();//
	float hy = hero->GetY2();

	//踏んでいるblockの種類を初期化
	hero->SetBT(0);

	if (hero->GetRight() == false)
	{
		
		if (hx < 400)
		{
			hero->SetX2(400); //
			mx_scroll -= -6.0f + hero->GetVX(); //
		}
	}

	if (hero->GetLeft() == false)
	{
		
		if (hx > 400)
		{
			hero->SetX2(400); 
			mx_scroll -= 6.0f + hero->GetVX(); 
		}
	}

	if (hero->GetDown() == false)
	{
		
		if (hy > 300)
		{
			hero->SetY2(300); 
			my_scroll -= 6.0f + hero->GetVY();

		}
	}

	if (hero->GetUp() == false)
	{
		
		if (hy < 300)
		{
			hero->SetY2(300); 
			my_scroll -= -6.0f + hero->GetVY(); 
		}
	}





	
	hero->SetUp(false);
	hero->SetDown(false);
	hero->SetLeft(false);
	hero->SetRight(false);






	
	for (int i = 0; i <60; i++)
	{
		for (int j = 0; j < 60; j++)
		{
			if (m_map[i][j] > 0)
			{

				
				float x = j * 32.0f;
				float y = i * 32.0f;

				
				if ((hx + (-mx_scroll) + 64.0f > x) && (hx + (-mx_scroll) < x + 64.0f) && (hy + (-my_scroll) + 64.0f > y) && (hy + (-my_scroll) < y + 64.0f))
				{

					

					
					float vx = (hx + (-mx_scroll)) - x;
					float vy = (hy + (-my_scroll)) - y;

					
					float len = sqrt(vx * vx + vy * vy);

					
					float r = atan2(vy, vx);
					r = r * 180.0f / 3.14f;

					if (r <= 0.0f)
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
						if (m_map[i][j] == 69)//������9
						{
							Scene::SetScene(new CSceneInstitute9());
						}
						if (m_map[i][j] == 70)//������10
						{
							Scene::SetScene(new CSceneInstitute10());
						}
						if (m_map[i][j] == 71)//������11
						{
							Scene::SetScene(new CSceneInstitute11());
						}
						if (m_map[i][j] == 72)//������12
						{
							Scene::SetScene(new CSceneInstitute12());
						}
						if (m_map[i][j] == 4)
						{
							Scene::SetScene(new CSceneInstitute14());
						}
						if (m_map[i][j] == 74)
						{
							Scene::SetScene(new CSceneChinaTown_d());
						}

						if (m_map[i][j] == 83)//公衆電話でエンターをおすとセーブ
						{
							if (Input::GetVKey(VK_RETURN) == true)
							{
								if (Save_sp == true) {
									((UserData*)Save::GetData())->mStage = 8;
									Save::Seve();
									SetSaveSp(false);
								}
							}
							else
							{
								SetSaveSp(true);
							}
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

}
//�h���[
void CObjInstitute::Draw()
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
	dst.m_bottom = 900.0 + my_scroll;
	Draw::Draw(30, &src, &dst, c, 0.0f);

	//�}�b�v�`�b�v�ɂ��block�ݒu
	for (int i = 0; i < 60; i++)
	{
		for (int j = 0; j < 60; j++)
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
			if (m_map[i][j] == 69)//�����蔻��
			{
				
			}
			if (m_map[i][j] == 70)//�����蔻��
			{

			}
			if (m_map[i][j] == 71)//�����蔻��
			{

			}
			if (m_map[i][j] == 72)//�����蔻��
			{

			}
			if (m_map[i][j] == 73)//　モブロボット表示
			{
				//切り取り位置の設定
				src.m_top = 0.0f;   //y
				src.m_left = 0.0f;  //x
				src.m_right = 32.0f; //x
				src.m_bottom = 32.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;//y
				dst.m_left = j * 32.0f + mx_scroll;//x
				dst.m_right = j * 32.0f + 45.0f + mx_scroll;//x
				dst.m_bottom = i * 32.0f + 45.0f + my_scroll; //y

				//5番目に登録したグラフィックをstc・dst・cの情報を元に描画
				Draw::Draw(6, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 74)
			{

			}
			if (m_map[i][j] == 83)//公衆電話 セーブ
			{
				//切り取り位置の設定
				src.m_top = 32.0f;   //y
				src.m_left = 251.0f; //x
				src.m_right = 304.0f; //x
				src.m_bottom = 138.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 40.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 72.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
		}
	}
}