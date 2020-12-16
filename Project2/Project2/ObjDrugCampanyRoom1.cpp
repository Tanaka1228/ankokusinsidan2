//?g?p????w?b?_?[?t?@?C??
#include"GameL\DrawTexture.h"
#include"GameL/DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"

#include"GameHead.h"
#include "ObjDrugCampanyRoom1.h"

//?g?p????l?[???X?y?[?X
using namespace GameL;

int Drug_Hero_x;
//?C?j?V?????C?Y
void CObjDrugCampanyRoom1::Init()
{
	mx_scroll = -20.0f;
	my_scroll = 0.0f;

	Drug_Hero_x = 1;

	//?}?b?v???
	int block_data[200][200] =
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,24,25,0,0,0,14,15,16,17,18,0,0,0,0,18,18,18,0,0,0,0,0,0,0,0,0,0,0,30,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,21,21,21,0,0,0,0,0,0,0,10,10,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,0,28,28,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},

		

	};
	//?}?b?v?f?[?^??R?s?[
	memcpy(m_map, block_data, sizeof(int) * (200 * 200));

}
//?A?N?V????
void CObjDrugCampanyRoom1::Action()
{
	//??l?????u??ï
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX2();//?X?N???[??
	float hy = hero->GetY2();


	if (hero->GetRight() == false)
	{
		//????X?N???[?????C???@??
		if (hx < 400)
		{
			hero->SetX2(400); //??l??????C????????????????
			mx_scroll -= -6.0f + hero->GetVX(); //??l????{?????????????l??m_scroll???????
		}
	}

	if (hero->GetLeft() == false)
	{
		//?O???X?N???[?????C?? ??
		if (hx > 400)
		{
			hero->SetX2(400); //??l??????C????????????????
			mx_scroll -= 6.0f + hero->GetVX(); //??l????{?????????????l??m_scroll???????

		}
	}

	if (hero->GetDown() == false)
	{
		//?X?N???[?????C???@??
		if (hy > 300)
		{
			hero->SetY2(300); //??l??????C????????????????
			my_scroll -= 6.0f + hero->GetVY(); //??l????{?????????????l??m_scroll???????

		}
	}

	if (hero->GetUp() == false)
	{
		//?X?N???[?????C???@??
		if (hy < 300)
		{
			hero->SetY2(300); //??l??????C????????????????
			my_scroll -= -6.0f + hero->GetVY(); //??l????{?????????????l??m_scroll???????
		}
	}





	//??l????????m?F?p?t???O???????
	hero->SetUp(false);
	hero->SetDown(false);
	hero->SetLeft(false);
	hero->SetRight(false);






	//m_map??S?v?f??A?N?Z?X
	for (int i = 0; i < 200; i++)
	{
		for (int j = 0; j < 200; j++)
		{
			if (m_map[i][j] > 0 && m_map[i][j] != 15)
			{

				//?v?f???????W???X
				float x = j * 32.0f;
				float y = i * 32.0f;

				//??l????u???b?N?????????
				if ((hx + (-mx_scroll) + 64.0f > x) && (hx + (-mx_scroll) < x + 64.0f) && (hy + (-my_scroll) + 64.0f > y) && (hy + (-my_scroll) < y + 64.0f))
				{

					//?????E????

					//vector???
					float vx = (hx + (-mx_scroll)) - x;
					float vy = (hy + (-my_scroll)) - y;

					//??????????
					float len = sqrt(vx * vx + vy * vy);//sqrt?????A??????????

					//?p?x??????
					float r = atan2(vy, vx);//atan2?????A?[?N?^???W?F???g????
					r = r * 180.0f / 3.14f;

					if (r <= 0.0f)//abs?????A?l???ƒ l?????? ?????????????l
						r = abs(r);
					else
						r = 360.0f - abs(r);

					//len????????????????Z????????????
					if (len < 44.0f)
					{

						//?p?x??????E????
						if ((r < 45 && r >= 0) || r > 315)
						{
							//?E
							hero->SetRight(true);//??l?????????????????????
							hero->SetX2(x + 40.0f + (mx_scroll));//?u???b?N???u+??l?????
							hero->SetVX(0.0f);//-VX*?????W??
						}
						if (r > 45 && r < 135)
						{
							//??
							hero->SetDown(true);//??l?????????????????????
							hero->SetY2(y - 40.0f + (my_scroll));//?u???b?N???u-??l?????
							hero->SetVY(0.0f);//-VX*?????W??

						}
						if (r > 135 && r < 225)
						{
							//??
							hero->SetLeft(true);//??l????E????????????????
							hero->SetX2(x - 40.0f + (mx_scroll));//?u???b?N???u-??l?????
							hero->SetVX(0.0f);//-VX*?????W??
						}
						if (r > 225 && r < 315)
						{
							//??
							hero->SetUp(true);//??l????????????????????
							hero->SetY2(y + 40.0f + (my_scroll));//?u???b?N???u+??l?????
							hero->SetVY(0.0f);//-VX*?????W??
						}
						if (m_map[i][j] == 5 )//?h?A????????_????
						{
							Scene::SetScene(new CSceneDrugCampany());
						}
					}
				}



			}
		}
	}

	//?G?o?????C??
	//float Xline = hx + (-mx_scroll) + 400;
	//float Yline = hy + (my_scroll)-100;

	//int ex = ((int)Xline) / 32;
	//int ey = ((int)Yline) / 32;

	//for (int i = 0; i < 25; i++)
	//{
	//	for (int j = 0; j < 25; j++)

	//		if (m_map[i][ex] == 15)
	//		{
	//			//?U???G?@?I?u?W?F?N?g??
	//			CObjRooftopBoss* obj_rooftop_boss = new CObjRooftopBoss(ex * 32, i * 32); //?U???G?@?I?u?W?F?N?g??
	//			Objs::InsertObj(obj_rooftop_boss, OBJ_ROOF_TOP_BOSS, 4); //?U???G?@?I?u?W?F?N?g??I?u?W?F?N?g?}?l?[?W???[??o?^

	//			m_map[i][ex] = 0;
	//		}


	//}

}
//?h???[
void CObjDrugCampanyRoom1::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//?`????????u
	RECT_F dst;//?`???\????u

	//?w?i?\??
	src.m_top = 0.0f;   // Y
	src.m_left = 0.0f;  // X
	src.m_right = 500.0f; // X
	src.m_bottom = 500.0f;// Y 

	dst.m_top = 0.0f + my_scroll;
	dst.m_left = 0.0f + mx_scroll;
	dst.m_right = 4400.0f + mx_scroll;
	dst.m_bottom = 4400.0 + my_scroll;
	Draw::Draw(5, &src, &dst, c, 0.0f);

	//?}?b?v?`?b?v????block??u
	for (int i = 0; i < 200; i++)
	{
		for (int j = 0; j < 200; j++)
		{
			if (m_map[i][j] == 1)//??
			{
				//??????u????
				src.m_top = 239.0f;   //y
				src.m_left = 211.0f; //x
				src.m_right = 310.0f; //x
				src.m_bottom = 309.0f; //y

				//?\????u????
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//?`??
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 2)//???U??
			{
				//??????u????
				src.m_top = 288.0f;   //y
				src.m_left = 175.0f; //x
				src.m_right = 211.0f; //x
				src.m_bottom = 309.0f; //y

				//?\????u????
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//?`??
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 3)//?P????
			{
				//??????u????
				src.m_top = 347.0f;   //y
				src.m_left = 106.0f; //x
				src.m_right = 179.0f; //x
				src.m_bottom = 389.0f; //y

				//?\????u????
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 33.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//?`??
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 4)//	????@
			{
				//??????u????
				src.m_top = 318.0f;   //y
				src.m_left = 0.0f; //x
				src.m_right = 70.0f; //x
				src.m_bottom = 388.0f; //y

				//?\????u????
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 33.5f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.5f + 32.0f + my_scroll;

				//?`??
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 5)//??P
			{
				//??????u????
				src.m_top = 236.0f;   //y
				src.m_left = 535.0f; //x
				src.m_right = 581.0f; //x
				src.m_bottom = 307.0f; //y

				//?\????u????
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//?`??
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 6)//??Q
			{
				//??????u????
				src.m_top = 237.0f;   //y
				src.m_left = 591.0f; //x
				src.m_right = 620.0f; //x
				src.m_bottom = 311.0f; //y

				//?\????u????
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//?`??
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 7)//?G???x?[?^?[
			{
				//??????u????
				src.m_top = 325.0f;   //y
				src.m_left = 191.0f; //x
				src.m_right = 236.0f; //x
				src.m_bottom = 387.0f; //y

				//?\????u????
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//?`??
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}
			if (m_map[i][j] == 8)//CT?X?L????
			{
				//??????u????
				src.m_top = 4.0f;   //y
				src.m_left = 0.0f; //x
				src.m_right = 83.0f; //x
				src.m_bottom = 127.0f; //y

				//?\????u????
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//?`??
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 9)//PC
			{
				//??????u????
				src.m_top = 74.0f;   //y
				src.m_left = 89.0f; //x
				src.m_right = 183.0f; //x
				src.m_bottom = 127.0f; //y

				//?\????u????
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//?`??
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 10)//?f?X?N?g?b?vPC
			{
				//??????u????
				src.m_top = 68.0f;   //y
				src.m_left = 188.0f; //x
				src.m_right = 223.0f; //x
				src.m_bottom = 127.0f; //y

				//?\????u????
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 33.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//?`??
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 11)//????
			{
				//??????u????
				src.m_top = 0.0f;   //y
				src.m_left = 227.0f; //x
				src.m_right = 293.0f; //x
				src.m_bottom = 127.0f; //y

				//?\????u????
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 33.5f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.5f + 32.0f + my_scroll;

				//?`??
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 12)//?J?[?e??
			{
				//??????u????
				src.m_top = 76.0f;   //y
				src.m_left = 297.0f; //x
				src.m_right = 404.0f; //x
				src.m_bottom = 127.0f; //y

				//?\????u????
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//?`??
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 13)//??
			{
				//??????u????
				src.m_top = 50.0f;   //y
				src.m_left = 407.0f; //x
				src.m_right = 549.0f; //x
				src.m_bottom = 128.0f; //y

				//?\????u????
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//?`??
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 14)//?z???C?g?{?[?h
			{
				//??????u????
				src.m_top = 179.0f;   //y
				src.m_left = 124.0f; //x
				src.m_right = 229.0f; //x
				src.m_bottom = 223.0f; //y

				//?\????u????
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//?`??
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 15)//?????g?Q???i?????g?j
			{
				//??????u????
				src.m_top = 198.0f;   //y
				src.m_left = 232.0f; //x
				src.m_right = 225.0f; //x
				src.m_bottom = 223.0f; //y

				//?\????u????
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//?`??
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}
			
			if (m_map[i][j] == 16)//?????g?Q???i??j
			{
				//??????u????
				src.m_top = 207.0f;   //y
				src.m_left = 257.0f; //x
				src.m_right = 281.0f; //x
				src.m_bottom = 223.0f; //y

				//?\????u????
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//?`??
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}
			
			if (m_map[i][j] == 17)//?????g?Q???i???g?j
			{
				//??????u????
				src.m_top = 198.0f;   //y
				src.m_left = 283.0f; //x
				src.m_right = 206.0f; //x
				src.m_bottom = 223.0f; //y

				//?\????u????
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//?`??
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}
			
			if (m_map[i][j] == 18)//?????g?Q???i???j
			{
				//??????u????
				src.m_top = 201.0f;   //y
				src.m_left = 308.0f; //x
				src.m_right = 326.0f; //x
				src.m_bottom = 223.0f; //y

				//?\????u????
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//?`??
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}
			
			if (m_map[i][j] == 19)//?e?[?u??
			{
				//??????u????
				src.m_top = 152.0f;   //y
				src.m_left = 328.0f; //x
				src.m_right = 434.0f; //x
				src.m_bottom = 223.0f; //y

				//?\????u????
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//?`??
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}
			
			if (m_map[i][j] == 20)//?e?[?u??
			{
				//??????u????
				src.m_top = 152.0f;   //y
				src.m_left = 434.0f; //x
				src.m_right = 469.0f; //x
				src.m_bottom = 223.0f; //y

				//?\????u????
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//?`??
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}
			
			if (m_map[i][j] == 21)//?@?B?P
			{
				//??????u????
				src.m_top = 158.0f;   //y
				src.m_left = 473.0f; //x
				src.m_right = 542.0f; //x
				src.m_bottom = 223.0f; //y

				//?\????u????
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//?`??
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}
			
			if (m_map[i][j] == 22)//??????P
			{
				//??????u????
				src.m_top = 202.0f;   //y
				src.m_left = 544.0f; //x
				src.m_right = 572.0f; //x
				src.m_bottom = 223.0f; //y

				//?\????u????
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//?`??
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}
			
			if (m_map[i][j] == 23)//??????Q
			{
				//??????u????
				src.m_top = 202.0f;   //y
				src.m_left = 580.0f; //x
				src.m_right = 607.0f; //x
				src.m_bottom = 223.0f; //y

				//?\????u????
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//?`??
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}
			
			if (m_map[i][j] == 24)//?{?I?P
			{
				//??????u????
				src.m_top = 240.0f;   //y
				src.m_left = 0.0f; //x
				src.m_right = 36.0f; //x
				src.m_bottom = 308.0f; //y

				//?\????u????
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//?`??
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 25)//?{?I?Q
			{
				//??????u????
				src.m_top = 240.0f;   //y
				src.m_left = 35.0f; //x
				src.m_right = 106.0f; //x
				src.m_bottom = 308.0f; //y

				//?\????u????
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//?`??
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}
			
			if (m_map[i][j] == 26)//?I
			{
				//??????u????
				src.m_top = 240.0f;   //y
				src.m_left = 105.0f; //x
				src.m_right = 175.0f; //x
				src.m_bottom = 308.0f; //y

				//?\????u????
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//?`??
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}
			
			if (m_map[i][j] == 27)//?{?I?R
			{
				//??????u????
				src.m_top = 238.0f;   //y
				src.m_left = 317.0f; //x
				src.m_right = 423.0f; //x
				src.m_bottom = 308.0f; //y

				//?\????u????
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//?`??
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}
			
			if (m_map[i][j] == 28)//??i?I
			{
				//??????u????
				src.m_top = 274.0f;   //y
				src.m_left = 423.0f; //x
				src.m_right = 493.0f; //x
				src.m_bottom = 310.0f; //y

				//?\????u????
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//?`??
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}
			
			if (m_map[i][j] == 29)//?b?c
			{
				//??????u????
				src.m_top = 270.0f;   //y
				src.m_left = 493.0f; //x
				src.m_right = 530.0f; //x
				src.m_bottom = 309.0f; //y

				//?\????u????
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//?`??
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}
			
			if (m_map[i][j] == 30)//?S?~??
			{
				//??????u????
				src.m_top = 335.0f;   //y
				src.m_left = 69.0f; //x
				src.m_right = 107.0f; //x
				src.m_bottom = 387.0f; //y

				//?\????u????
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//?`??
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}
		}
	}
}