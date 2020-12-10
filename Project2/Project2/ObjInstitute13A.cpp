//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL/DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"

#include"GameHead.h"
#include"ObjInstitute13A.h"  

//使用するネームスペース
using namespace GameL;

extern int Inst_Hero_x;
//イニシャライズ
void CObjInstitute13A::Init()
{
	if (Inst_Hero_x == 15)
	{
		mx_scroll = -1290.0f;
		my_scroll = -650.0f;
	}
	else if (Inst_Hero_x == 10)
	{
		mx_scroll = -205.0f;
		my_scroll = +100.0f;
	}
	else if (Inst_Hero_x == 11)
	{
		mx_scroll = -1205.0f;
		my_scroll = +115.0f;
	}
	else if (Inst_Hero_x == 12)
	{
		mx_scroll = +110.0f;
		my_scroll = -350.0f;
	}
	else if (Inst_Hero_x == 13)
	{
		mx_scroll = -690.0f;
		my_scroll = -390.0f;
	}
	else
	{
		mx_scroll = -430.0f;
		my_scroll = -350.0f;
	}
	

	Inst_Hero_x = 14;
	//マップ情報
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
		{1,0,5,0,0,0,0,0,0,63,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,1},
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

	//マップデータをコピー
	memcpy(m_map, block_data, sizeof(int) * (70 * 70));

}
//アクション
void CObjInstitute13A::Action()
{
	//主人公の位置を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX2();//スクロール
	float hy = hero->GetY2();


	if (hero->GetRight() == false)
	{
		//後方スクロールライン　←
		if (hx < 400)
		{
			hero->SetX2(400); //主人公はラインを超えないようにする
			mx_scroll -= -6.0f + hero->GetVX(); //主人公は本来動くべき分の値をm_scrollに加える
		}
	}

	if (hero->GetLeft() == false)
	{
		//前方スクロールライン →
		if (hx > 400)
		{
			hero->SetX2(400); //主人公はラインを超えないようにする
			mx_scroll -= 6.0f + hero->GetVX(); //主人公は本来動くべき分の値をm_scrollに加える

		}
	}

	if (hero->GetDown() == false)
	{
		//スクロールライン　↑
		if (hy > 300)
		{
			hero->SetY2(300); //主人公はラインを超えないようにする
			my_scroll -= 6.0f + hero->GetVY(); //主人公は本来動くべき分の値をm_scrollに加える

		}
	}

	if (hero->GetUp() == false)
	{
		//スクロールライン　↓
		if (hy < 300)
		{
			hero->SetY2(300); //主人公はラインを超えないようにする
			my_scroll -= -6.0f + hero->GetVY(); //主人公は本来動くべき分の値をm_scrollに加える
		}
	}





	//主人公の衝突状態確認用フラグの初期化
	hero->SetUp(false);
	hero->SetDown(false);
	hero->SetLeft(false);
	hero->SetRight(false);






	//m_mapの全要素にアクセス
	for (int i = 0; i < 70; i++)
	{
		for (int j = 0; j < 70; j++)
		{
			if (m_map[i][j] > 0)
			{

				//要素番号を座標に変更
				float x = j * 32.0f;
				float y = i * 32.0f;

				//主人公とブロックの当たり判定
				if ((hx + (-mx_scroll) + 64.0f > x) && (hx + (-mx_scroll) < x + 64.0f) && (hy + (-my_scroll) + 64.0f > y) && (hy + (-my_scroll) < y + 64.0f))
				{

					//上下左右判定

					//vectorの作成
					float vx = (hx + (-mx_scroll)) - x;
					float vy = (hy + (-my_scroll)) - y;

					//長さを求める
					float len = sqrt(vx * vx + vy * vy);//sqrt関数は、平方根を返す

					//角度を求める
					float r = atan2(vy, vx);//atan2関数はアークタンジェントを返す
					r = r * 180.0f / 3.14f;

					if (r <= 0.0f)//abs関数は、値の絶対値を求める 符号を無視した値
						r = abs(r);
					else
						r = 360.0f - abs(r);

					//lenがある一定の長さのより短い場合判定に入る
					if (len < 44.0f)
					{

						//角度で上下左右を判定
						if ((r < 45 && r >= 0) || r > 315)
						{
							//右
							hero->SetRight(true);//主人公の左の部分が衝突している
							hero->SetX2(x + 40.0f + (mx_scroll));//ブロックの位置+主人公の幅
							hero->SetBT(m_map[i][j]);
							hero->SetVX(0.0f);//-VX*反発係数
						}
						if (r > 45 && r < 135)
						{
							//上
							hero->SetDown(true);//主人公の下の部分が衝突している
							hero->SetY2(y - 40.0f + (my_scroll));//ブロックの位置-主人公の幅
							hero->SetBT(m_map[i][j]);
							hero->SetVY(0.0f);//-VX*反発係数

						}
						if (r > 135 && r < 225)
						{
							//左
							hero->SetLeft(true);//主人公の右の部分が衝突している
							hero->SetX2(x - 40.0f + (mx_scroll));//ブロックの位置-主人公の幅
							hero->SetBT(m_map[i][j]);
							hero->SetVX(0.0f);//-VX*反発係数
						}
						if (r > 225 && r < 315)
						{
							//下
							hero->SetUp(true);//主人公の上の部分が衝突している
							hero->SetY2(y + 40.0f + (my_scroll));//ブロックの位置+主人公の幅
							hero->SetBT(m_map[i][j]);
							hero->SetVY(0.0f);//-VX*反発係数
						}
						if (m_map[i][j] == 4)//������14
						{
							Scene::SetScene(new CSceneInstitute14());
						}
						if (m_map[i][j] == 2 || m_map[i][j] == 50)//������BOSS
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
	
}
//ドロー
void CObjInstitute13A::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//背景表示
	src.m_top = 73.0f;   // Y
	src.m_left = 21.0f;  // X
	src.m_right = 106.0f; // X
	src.m_bottom = 196.0f;// Y 

	dst.m_top = 0.0f + my_scroll;
	dst.m_left = 0.0f + mx_scroll;
	dst.m_right = 1900.0f + mx_scroll;
	dst.m_bottom = 1000.0 + my_scroll;
	Draw::Draw(30, &src, &dst, c, 0.0f);

	//マップチップによるblock設置
	for (int i = 0; i < 70; i++)
	{
		for (int j = 0; j < 70; j++)
		{

			if (m_map[i][j] == 1)//壁
			{
				//切り取り位置の設定
				src.m_top = 73.0f;   //y
				src.m_left = 3.0f; //x
				src.m_right = 61.0f; //x
				src.m_bottom = 130.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 4)//エレベーター
			{
				//切り取り位置の設定
				src.m_top = 2.0f;   //y
				src.m_left = 136.0f; //x
				src.m_right = 190.0f; //x
				src.m_bottom = 4.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 5)//草
			{
				//切り取り位置の設定
				src.m_top = 2.0f;   //y
				src.m_left = 208.0f; //x
				src.m_right = 231.0f; //x
				src.m_bottom = 59.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 6)//コピー機
			{
				//切り取り位置の設定
				src.m_top = 4.0f;   //y
				src.m_left = 237.0f; //x
				src.m_right = 265.0f; //x
				src.m_bottom = 48.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 7)//机
			{
				//切り取り位置の設定
				src.m_top = 6.0f;   //y
				src.m_left = 335.0f; //x
				src.m_right = 397.0f; //x
				src.m_bottom = 44.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 8)//デスク
			{
				//切り取り位置の設定
				src.m_top = 4.0f;   //y
				src.m_left = 397.0f; //x
				src.m_right = 456.0f; //x
				src.m_bottom = 44.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 9)//実験道具
			{
				//切り取り位置の設定
				src.m_top = 77.0f;   //y
				src.m_left = 76.0f; //x
				src.m_right = 137.0f; //x
				src.m_bottom = 120.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 18)//棚
			{
				//切り取り位置の設定
				src.m_top = 72.0f;   //y
				src.m_left = 143.0f; //x
				src.m_right = 178.0f; //x
				src.m_bottom = 123.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 10)//水ガラス
			{
				//切り取り位置の設定
				src.m_top = 69.0f;   //y
				src.m_left = 194.0f; //x
				src.m_right = 238.0f; //x
				src.m_bottom = 140.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 11)//階段
			{
				//切り取り位置の設定
				src.m_top = 80.0f;   //y
				src.m_left = 255.0f; //x
				src.m_right = 306.0f; //x
				src.m_bottom = 135.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 12)//自販機
			{
				//切り取り位置の設定
				src.m_top = 74.0f;   //y
				src.m_left = 317.0f; //x
				src.m_right = 365.0f; //x
				src.m_bottom = 82.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 13)//モニター1
			{
				//切り取り位置の設定
				src.m_top = 81.0f;   //y
				src.m_left = 366.0f; //x
				src.m_right = 422.0f; //x
				src.m_bottom = 120.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 14)//パソコン
			{
				//切り取り位置の設定
				src.m_top = 85.0f;   //y
				src.m_left = 436.0f; //x
				src.m_right = 471.0f; //x
				src.m_bottom = 121.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 15)//椅子
			{
				//切り取り位置の設定
				src.m_top = 150.0f;   //y
				src.m_left = 18.0f; //x
				src.m_right = 39.0f; //x
				src.m_bottom = 181.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 16)//壁
			{
				//切り取り位置の設定
				src.m_top = 153.0f;   //y
				src.m_left = 78.0f; //x
				src.m_right = 110.0f; //x
				src.m_bottom = 186.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 17)//マット
			{
				//切り取り位置の設定
				src.m_top = 156.0f;   //y
				src.m_left = 121.0f; //x
				src.m_right = 181.0f; //x
				src.m_bottom = 189.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 19)//ホワイトボード
			{
				//切り取り位置の設定
				src.m_top = 150.0f;   //y
				src.m_left = 199.0f; //x
				src.m_right = 266.0f; //x
				src.m_bottom = 194.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 21)//田中先生の相棒
			{
				//切り取り位置の設定
				src.m_top = 153.0f;   //y
				src.m_left = 274.0f; //x
				src.m_right = 330.0f; //x
				src.m_bottom = 196.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 22)//コピー機
			{
				//切り取り位置の設定
				src.m_top = 146.0f;   //y
				src.m_left = 351.0f; //x
				src.m_right = 398.0f; //x
				src.m_bottom = 199.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 23)//荷物入れ
			{
				//切り取り位置の設定
				src.m_top = 150.0f;   //y
				src.m_left = 402.0f; //x
				src.m_right = 459.0f; //x
				src.m_bottom = 199.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 24)//モニター２
			{
				//切り取り位置の設定
				src.m_top = 6.0f;   //y
				src.m_left = 196.0f; //x
				src.m_right = 73.0f; //x
				src.m_bottom = 252.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 25)//パネル
			{
				//切り取り位置の設定
				src.m_top = 194.0f;   //y
				src.m_left = 90.0f; //x
				src.m_right = 143.0f; //x
				src.m_bottom = 271.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 26)//消火器
			{
				//切り取り位置の設定
				src.m_top = 271.0f;   //y
				src.m_left = 120.0f; //x
				src.m_right = 193.0f; //x
				src.m_bottom = 245.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 27)//ゴミ箱
			{
				//切り取り位置の設定
				src.m_top = 205.0f;   //y
				src.m_left = 215.0f; //x
				src.m_right = 248.0f; //x
				src.m_bottom = 251.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 28)//水道
			{
				//切り取り位置の設定
				src.m_top = 209.0f;   //y
				src.m_left = 325.0f; //x
				src.m_right = 351.0f; //x
				src.m_bottom = 264.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 29)//薬
			{
				//切り取り位置の設定
				src.m_top = 223.0f;   //y
				src.m_left = 380.0f; //x
				src.m_right = 421.0f; //x
				src.m_bottom = 257.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 30)//箱
			{
				//切り取り位置の設定
				src.m_top = 212.0f;   //y
				src.m_left = 435.0f; //x
				src.m_right = 473.0f; //x
				src.m_bottom = 257.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 31)//薬
			{
				//切り取り位置の設定
				src.m_top = 275.0f;   //y
				src.m_left = 180.0f; //x
				src.m_right = 198.0f; //x
				src.m_bottom = 318.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(5, &src, &dst, c, 0.0f);
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

				Draw::Draw(7, &src, &dst, c, -1.0f);
			}
		}
	}
}
