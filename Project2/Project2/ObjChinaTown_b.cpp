//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL/DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"

#include"GameHead.h"
#include "ObjChinaTown_b.h"

//使用するネームスペース
using namespace GameL;

extern int ChinaTown_Hero_x;

//イニシャライズ
void CObjChinaTown_b::Init()
{
	if (ChinaTown_Hero_x == 2)
	{
		mx_scroll = +300.0f;
		my_scroll = -600.0f;
	}
	if (ChinaTown_Hero_x == 4)
	{
		mx_scroll = -125.0f;
		my_scroll = 0.0f;
	}
	if (ChinaTown_Hero_x == 5)
	{
		mx_scroll = -600.0f;
		my_scroll = -550.0f;
	}

	ChinaTown_Hero_x = 3;

	//マップ情報
	int block_data[65][54] =
	{


				   {1,9,9,9,9,9,9,9,9,1,1001,1002,1002,1002,1002,1002,1002,1002,1002,1002,1002,1002,1002,1001,1,9,9,9,9,9,9,9,9,1},
		           {1,0,0,0,0,0,0,0,0,1,1001,1002,1002,1002,1002,1002,1002,1002,1002,1002,1002,1002,1002,1001,1,0,0,0,0,0,0,0,0,1},
				   {1,0,0,0,0,0,0,0,0,1,1001,1002,1002,1002,1002,1002,1002,1002,1002,1002,1002,1002,1002,1001,1,0,0,0,0,0,0,0,0,1},
				   {1,0,0,0,0,0,0,0,0,1,1001,1002,1002,1002,1002,1002,1002,1002,1002,1002,1002,1002,1002,1001,1,0,0,0,0,0,0,0,0,1},
				   {1,0,0,0,0,0,0,0,0,1,1001,1001,1001,1001,1002,1002,1002,1002,1002,1002,1001,1001,1001,1001,1,0,0,0,0,0,0,0,0,1},
				   {1,0,0,0,0,0,0,0,0,1,0,0,0,1001,1001,1002,999,999,1002,1001,1001,0,0,0,1,0,0,0,0,0,0,0,0,1},
				   {1,0,0,0,0,0,0,0,0,1,0,0,0,0,1001,1001,0,0,1001,1001,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
				   {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
				   {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
				   {1,0,0,0,0,0,0,0,0,1,89,0,0,0,0,0,0,0,0,0,0,0,0,89,1,0,0,0,0,0,0,0,0,1},
				   {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
				   {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
				   {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
				   {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
				   {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
				   {1,0,0,0,0,0,0,0,0,1,89,0,0,0,0,0,0,0,0,0,0,0,0,89,1,0,0,0,0,0,0,0,0,1},
				   {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
				   {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
				   {1,1,1,1,1,1,1,1,1,1,101,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1},
				   {15,15,15,15,15,15,15,15,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,102,0,0,0,0,0,0,0,1000},
				   {16,16,16,16,16,16,16,16,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1000},
				   {0,100,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1000},
				   {0,98,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1000},
				   {0,98,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,81,0,0,0,0,0,0,1000},
				   {0,98,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1000},
				   {0,98,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1000},
				   {0,98,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1000},
				   {0,98,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1000},
				   {0,98,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1000},
				   {0,98,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,81,0,0,0,0,0,0,1000},
				   {0,98,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1000},
				   {0,98,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1000},
				   {0,98,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1000},
				   {0,98,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1000},
				   {0,98,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1000},
				   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},

	};

	//マップデータをコピー
	memcpy(m_map, block_data, sizeof(int) * (65 * 54));
	map_flag = true;
	map_flag2 = false;
}

//アクション
void CObjChinaTown_b::Action()
{
	//主人公の位置を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX2();//スクロール
	float hy = hero->GetY2();


	//踏んでいるblockの種類を初期化
	hero->SetBT(0);

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
	for (int i = 0; i < 65; i++)
	{
		for (int j = 0; j < 54; j++)
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
							hero->SetX2(x + 39.0f + (mx_scroll));//ブロックの位置+主人公の幅
							if (m_map[i][j] == 97)
								hero->SetBT(m_map[i][j]);//ブロックの要素(type)を主人公に渡す
							hero->SetVX(0.0f);//-VX*反発係数
						}
						if (r > 45 && r < 135)
						{
							//上
							hero->SetDown(true);//主人公の下の部分が衝突している
							hero->SetY2(y - 39.0f + (my_scroll));//ブロックの位置-主人公の幅
							if (m_map[i][j] == 97)
								hero->SetBT(m_map[i][j]);//ブロックの要素(type)を主人公に渡す
							hero->SetVY(0.0f);//-VX*反発係数

						}
						if (r > 135 && r < 225)
						{
							//左
							hero->SetLeft(true);//主人公の右の部分が衝突している
							hero->SetX2(x - 39.0f + (mx_scroll));//ブロックの位置-主人公の幅
							if (m_map[i][j] == 97)
								hero->SetBT(m_map[i][j]);//ブロックの要素(type)を主人公に渡す
							hero->SetVX(0.0f);//-VX*反発係数
						}
						if (r > 225 && r < 315)
						{
							//下
							hero->SetUp(true);//主人公の上の部分が衝突している
							hero->SetY2(y + 39.0f + (my_scroll));//ブロックの位置+主人公の幅
							if (m_map[i][j] == 97)
								hero->SetBT(m_map[i][j]);//ブロックの要素(type)を主人公に渡す
							hero->SetVY(0.0f);//-VX*反発係数
						}
						if (m_map[i][j] == 98)//左に行くとチャイナタウンボス
						{
							Scene::SetScene(new CSceneChinaTownBoss());
						}
						if (m_map[i][j] == 1000)//下に行くとチャイナタウンボス
						{
							Scene::SetScene(new CSceneChinaTown_c());
						}
						if (m_map[i][j] == 999)//上に行くと病院1階
						{
							Scene::SetScene(new CSceneHospital());
						}
						
					}
				}



			}
		}
	}
	//敵出現ライン
	//float Xline = hx + (-mx_scroll) - 1100;
	//float Yline = hy + (my_scroll)-400;

	//int ex = ((int)Xline) / 32;
	//int ey = ((int)Yline) / 32;

	//for (int i = 0; i < 65; i++)
	//{
	//	for (int j = 0; j < 54; j++)

	//		//if (m_map[i][ex] == 81)
	//		//	////誘導敵機オブジェクト作成
	//		//	//CObjChinaTownBossBoss* obj_chinatown_boss_boss = new CObjChinaTownBossBoss(ex * 32, i * 32); //誘導敵機オブジェクト作成
	//		//	//Objs::InsertObj(obj_chinatown_boss_boss, OBJ_CHINA_TOWN_BOSS_BOSS, 4); //誘導敵機オブジェクトをオブジェクトマネージャーに登録

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
//ドロー
void CObjChinaTown_b::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置


	//背景表示
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 60.0f;
	src.m_bottom = 95.0f;

	dst.m_top = 0.0f + my_scroll;
	dst.m_left = 0.0f + mx_scroll;
	dst.m_right = 1090.0f + mx_scroll;
	dst.m_bottom = 2100.0f + my_scroll;
	Draw::Draw(16, &src, &dst, c, 0.0f);

	

	//マップチップによるblock設置
	for (int i = 0; i < 65; i++)
	{
		for (int j = 0; j < 54; j++)
		{
			if (m_map[i][j] == 1)//壁
			{
				//切り取り位置の設定
				src.m_top = 18.0f;   //y
				src.m_left = 11.0f; //x
				src.m_right = 82.0f; //x
				src.m_bottom = 91.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);

			}
			if (m_map[i][j] == 2)//壁
			{
				//切り取り位置の設定
				src.m_top = 18.0f;   //y
				src.m_left = 104.0f; //x
				src.m_right = 177.0f; //x
				src.m_bottom = 91.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 3)//看板
			{
				//切り取り位置の設定
				src.m_top = 10.0f;   //y
				src.m_left = 191.0f; //x
				src.m_right = 223.0f; //x
				src.m_bottom = 52.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 4)//ゴミ箱
			{
				//切り取り位置の設定
				src.m_top = 8.0f;   //y
				src.m_left = 232.0f; //x
				src.m_right = 313.0f; //x
				src.m_bottom = 43.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 100.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 40.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 5)//エレベーター
			{
				//切り取り位置の設定
				src.m_top = 62.0f;   //y
				src.m_left = 191.0f; //x
				src.m_right = 265.0f; //x
				src.m_bottom = 95.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 130.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 6)//自販機
			{
				//切り取り位置の設定
				src.m_top = 10.0f;   //y
				src.m_left = 327.0f; //x
				src.m_right = 366.0f; //x
				src.m_bottom = 53.0f; //y

				//表示位置の設定
				dst.m_top = i * 31.9f + my_scroll;
				dst.m_left = j * 31.9f + mx_scroll;
				dst.m_right = j * 32.0f + 64.0f + mx_scroll;
				dst.m_bottom = i * 32.1f + 64.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 7)//シャッター
			{
				//切り取り位置の設定
				src.m_top = 9.0f;   //y
				src.m_left = 373.0f; //x
				src.m_right = 426.0f; //x
				src.m_bottom = 49.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 8)//公衆電話
			{
				//切り取り位置の設定
				src.m_top = 44.0f;   //y
				src.m_left = 270.0f; //x
				src.m_right = 298.0f; //x
				src.m_bottom = 93.0f; //y

				//表示位置の設定
				dst.m_top = i * 31.9f + my_scroll;
				dst.m_left = j * 31.9f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 9)//当たり判定
			{
				//切り取り位置の設定
				src.m_top = 32.0f;   //y
				src.m_left = 32.0f; //x
				src.m_right = 32.0f; //x
				src.m_bottom = 32.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;
			}
			if (m_map[i][j] == 10)//黒
			{
				//切り取り位置の設定
				src.m_top = 429.0f;   //y
				src.m_left = 19.0f; //x
				src.m_right = 33.0f; //x
				src.m_bottom = 447.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 11)//バイク
			{
				//切り取り位置の設定
				src.m_top = 55.0f;   //y
				src.m_left = 349.0f; //x
				src.m_right = 392.0f; //x
				src.m_bottom = 88.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 64.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 12)//自転車　縦
			{
				//切り取り位置の設定
				src.m_top = 56.0f;   //y
				src.m_left = 401.0f; //x
				src.m_right = 430.0f; //x
				src.m_bottom = 121.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 13)//自転車　横
			{
				//切り取り位置の設定
				src.m_top = 71.0f;   //y
				src.m_left = 430.0f; //x
				src.m_right = 495.0f; //x
				src.m_bottom = 114.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 64.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 14)//自転車　縦
			{
				//切り取り位置の設定
				src.m_top = 7.0f;   //y
				src.m_left = 439.0f; //x
				src.m_right = 470.0f; //x
				src.m_bottom = 72.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 15)//自転車　横
			{
				//切り取り位置の設定
				src.m_top = 95.0f;   //y
				src.m_left = 4.0f; //x
				src.m_right = 50.0f; //x
				src.m_bottom = 127.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 64.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 16)//自転車　横
			{
				//切り取り位置の設定
				src.m_top = 96.0f;   //y
				src.m_left = 51.0f; //x
				src.m_right = 99.0f; //x
				src.m_bottom = 128.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 64.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 17)//自転車　横
			{
				//切り取り位置の設定
				src.m_top = 100.0f;   //y
				src.m_left = 100.0f; //x
				src.m_right = 147.0f; //x
				src.m_bottom = 130.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 64.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 18)//車　黒　縦
			{
				//切り取り位置の設定
				src.m_top = 98.0f;   //y
				src.m_left = 149.0f; //x
				src.m_right = 183.0f; //x
				src.m_bottom = 141.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 30.0f + mx_scroll;
				dst.m_right = j * 30.0f + 62.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 96.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 19)//車　横
			{
				//切り取り位置の設定
				src.m_top = 99.0f;   //y
				src.m_left = 185.0f; //x
				src.m_right = 232.0f; //x
				src.m_bottom = 126.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 29.0f + mx_scroll;
				dst.m_right = j * 29.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 20)//車　横　青
			{
				//切り取り位置の設定
				src.m_top = 98.0f;   //y
				src.m_left = 272.0f; //x
				src.m_right = 323.0f; //x
				src.m_bottom = 127.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 30.0f + mx_scroll;
				dst.m_right = j * 30.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 21)//車　白　縦
			{
				//切り取り位置の設定
				src.m_top = 98.0f;   //y
				src.m_left = 238.0f; //x
				src.m_right = 269.0f; //x
				src.m_bottom = 138.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 28.0f + mx_scroll;
				dst.m_right = j * 28.0f + 64.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 96.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 22)//車　青　横
			{
				//切り取り位置の設定
				src.m_top = 89.0f;   //y
				src.m_left = 332.0f; //x
				src.m_right = 395.0f; //x
				src.m_bottom = 122.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 28.0f + mx_scroll;
				dst.m_right = j * 28.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 23)//車　赤　横
			{
				//切り取り位置の設定
				src.m_top = 133.0f;   //y
				src.m_left = 7.0f; //x
				src.m_right = 63.0f; //x
				src.m_bottom = 165.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 28.0f + mx_scroll;
				dst.m_right = j * 28.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 24)//車　白　横
			{
				//切り取り位置の設定
				src.m_top = 132.0f;   //y
				src.m_left = 66.0f; //x
				src.m_right = 116.0f; //x
				src.m_bottom = 163.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 28.0f + mx_scroll;
				dst.m_right = j * 28.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 25)//車　赤　縦
			{
				//切り取り位置の設定
				src.m_top = 132.0f;   //y
				src.m_left = 118.0f; //x
				src.m_right = 152.0f; //x
				src.m_bottom = 184.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 28.0f + mx_scroll;
				dst.m_right = j * 28.0f + 64.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 96.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 26)//車　青　横
			{
				//切り取り位置の設定
				src.m_top = 129.0f;   //y
				src.m_left = 189.0f; //x
				src.m_right = 233.0f; //x
				src.m_bottom = 156.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 28.0f + mx_scroll;
				dst.m_right = j * 28.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 27)//車　ベージュ　横
			{
				//切り取り位置の設定
				src.m_top = 131.0f;   //y
				src.m_left = 305.0f; //x
				src.m_right = 360.0f; //x
				src.m_bottom = 158.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 28.0f + mx_scroll;
				dst.m_right = j * 28.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 28)//車　横
			{
				//切り取り位置の設定
				src.m_top = 125.0f;   //y
				src.m_left = 364.0f; //x
				src.m_right = 416.0f; //x
				src.m_bottom = 153.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 28.0f + mx_scroll;
				dst.m_right = j * 28.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 29)//車　白　横
			{
				//切り取り位置の設定
				src.m_top = 122.0f;   //y
				src.m_left = 421.0f; //x
				src.m_right = 473.0f; //x
				src.m_bottom = 148.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 28.0f + mx_scroll;
				dst.m_right = j * 28.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 30)//バイク　縦
			{
				//切り取り位置の設定
				src.m_top = 123.0f;   //y
				src.m_left = 477.0f; //x
				src.m_right = 492.0f; //x
				src.m_bottom = 164.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 28.0f + mx_scroll;
				dst.m_right = j * 28.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 31)//車　横
			{
				//切り取り位置の設定
				src.m_top = 169.0f;   //y
				src.m_left = 13.0f; //x
				src.m_right = 65.0f; //x
				src.m_bottom = 204.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 28.0f + mx_scroll;
				dst.m_right = j * 28.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 32)//バス　白　横
			{
				//切り取り位置の設定
				src.m_top = 157.0f;   //y
				src.m_left = 159.0f; //x
				src.m_right = 234.0f; //x
				src.m_bottom = 199.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 28.0f + mx_scroll;
				dst.m_right = j * 28.0f + 128.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 33)//車　灰色　横
			{
				//切り取り位置の設定
				src.m_top = 143.0f;   //y
				src.m_left = 235.0f; //x
				src.m_right = 294.0f; //x
				src.m_bottom = 175.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 34)//車　青
			{
				//切り取り位置の設定
				src.m_top = 161.0f;   //y
				src.m_left = 307.0f; //x
				src.m_right = 349.0f; //x
				src.m_bottom = 191.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 64.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 35)//車　白
			{
				//切り取り位置の設定
				src.m_top = 158.0f;   //y
				src.m_left = 353.0f; //x
				src.m_right = 398.0f; //x
				src.m_bottom = 190.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 64.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 36)//車　横
			{
				//切り取り位置の設定
				src.m_top = 157.0f;   //y
				src.m_left = 408.0f; //x
				src.m_right = 477.0f; //x
				src.m_bottom = 197.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 37)//車　横
			{
				//切り取り位置の設定
				src.m_top = 210.0f;   //y
				src.m_left = 9.0f; //x
				src.m_right = 65.0f; //x
				src.m_bottom = 245.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 18.0f + mx_scroll;
				dst.m_right = j * 18.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 38)//車　横
			{
				//切り取り位置の設定
				src.m_top = 205.0f;   //y
				src.m_left = 72.0f; //x
				src.m_right = 131.0f; //x
				src.m_bottom = 240.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 18.0f + mx_scroll;
				dst.m_right = j * 18.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 39)//車　横
			{
				//切り取り位置の設定
				src.m_top = 205.0f;   //y
				src.m_left = 195.0f; //x
				src.m_right = 254.0f; //x
				src.m_bottom = 243.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 25.0f + mx_scroll;
				dst.m_right = j * 25.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 40)//車　横
			{
				//切り取り位置の設定
				src.m_top = 221.0f;   //y
				src.m_left = 261.0f; //x
				src.m_right = 311.0f; //x
				src.m_bottom = 246.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 41)//バス　横
			{
				//切り取り位置の設定
				src.m_top = 194.0f;   //y
				src.m_left = 319.0f; //x
				src.m_right = 383.0f; //x
				src.m_bottom = 227.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 128.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 42)//バス　横
			{
				//切り取り位置の設定
				src.m_top = 205.0f;   //y
				src.m_left = 393.0f; //x
				src.m_right = 472.0f; //x
				src.m_bottom = 246.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 128.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 43)//車　横
			{
				//切り取り位置の設定
				src.m_top = 229.0f;   //y
				src.m_left = 314.0f; //x
				src.m_right = 371.0f; //x
				src.m_bottom = 255.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 44)//バイク　横
			{
				//切り取り位置の設定
				src.m_top = 247.0f;   //y
				src.m_left = 10.0f; //x
				src.m_right = 48.0f; //x
				src.m_bottom = 269.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 64.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 45)//バイク　横
			{
				//切り取り位置の設定
				src.m_top = 246.0f;   //y
				src.m_left = 67.0f; //x
				src.m_right = 104.0f; //x
				src.m_bottom = 270.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 30.0f + mx_scroll;
				dst.m_right = j * 30.0f + 64.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 46)//バイク　横
			{
				//切り取り位置の設定
				src.m_top = 242.0f;   //y
				src.m_left = 111.0f; //x
				src.m_right = 148.0f; //x
				src.m_bottom = 274.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 64.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 47)//車　水色　横
			{
				//切り取り位置の設定
				src.m_top = 245.0f;   //y
				src.m_left = 208.0f; //x
				src.m_right = 266.0f; //x
				src.m_bottom = 268.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 28.0f + mx_scroll;
				dst.m_right = j * 28.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 48)//リムジン　横
			{
				//切り取り位置の設定
				src.m_top = 256.0f;   //y
				src.m_left = 272.0f; //x
				src.m_right = 347.0f; //x
				src.m_bottom = 286.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 128.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 49)//大型車　横
			{
				//切り取り位置の設定
				src.m_top = 261.0f;   //y
				src.m_left = 355.0f; //x
				src.m_right = 436.0f; //x
				src.m_bottom = 303.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 24.0f + mx_scroll;
				dst.m_right = j * 24.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 50)//車　水色　横
			{
				//切り取り位置の設定
				src.m_top = 249.0f;   //y
				src.m_left = 439.0f; //x
				src.m_right = 493.0f; //x
				src.m_bottom = 280.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 64.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 51)//車　ベージュ　横
			{
				//切り取り位置の設定
				src.m_top = 281.0f;   //y
				src.m_left = 440.0f; //x
				src.m_right = 497.0f; //x
				src.m_bottom = 315.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 64.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 52)//車　オレンジ　横
			{
				//切り取り位置の設定
				src.m_top = 266.0f;   //y
				src.m_left = 159.0f; //x
				src.m_right = 214.0f; //x
				src.m_bottom = 288.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 18.0f + mx_scroll;
				dst.m_right = j * 18.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 53)//車　白　横
			{
				//切り取り位置の設定
				src.m_top = 275.0f;   //y
				src.m_left = 6.0f; //x
				src.m_right = 72.0f; //x
				src.m_bottom = 306.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 24.0f + mx_scroll;
				dst.m_right = j * 24.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 54)//トラック　横
			{
				//切り取り位置の設定
				src.m_top = 275.0f;   //y
				src.m_left = 82.0f; //x
				src.m_right = 150.0f; //x
				src.m_bottom = 316.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 55)//大型自動車　横
			{
				//切り取り位置の設定
				src.m_top = 288.0f;   //y
				src.m_left = 153.0f; //x
				src.m_right = 222.0f; //x
				src.m_bottom = 325.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 56)//バイク　縦
			{
				//切り取り位置の設定
				src.m_top = 273.0f;   //y
				src.m_left = 224.0f; //x
				src.m_right = 238.0f; //x
				src.m_bottom = 309.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 30.0f + mx_scroll;
				dst.m_right = j * 30.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 57)//バイク　縦
			{
				//切り取り位置の設定
				src.m_top = 272.0f;   //y
				src.m_left = 244.0f; //x
				src.m_right = 260.0f; //x
				src.m_bottom = 315.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 58)//車　灰色　横
			{
				//切り取り位置の設定
				src.m_top = 287.0f;   //y
				src.m_left = 260.0f; //x
				src.m_right = 321.0f; //x
				src.m_bottom = 325.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 59)//車　緑色　横
			{
				//切り取り位置の設定
				src.m_top = 302.0f;   //y
				src.m_left = 323.0f; //x
				src.m_right = 375.0f; //x
				src.m_bottom = 334.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 24.0f + mx_scroll;
				dst.m_right = j * 24.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 60)//車　緑色　横
			{
				//切り取り位置の設定
				src.m_top = 332.0f;   //y
				src.m_left = 422.0f; //x
				src.m_right = 487.0f; //x
				src.m_bottom = 371.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 30.0f + mx_scroll;
				dst.m_right = j * 30.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 61)//車　水色　横
			{
				//切り取り位置の設定
				src.m_top = 308.0f;   //y
				src.m_left = 6.0f; //x
				src.m_right = 79.0f; //x
				src.m_bottom = 348.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 62)//自転車　3つ　横
			{
				//切り取り位置の設定
				src.m_top = 317.0f;   //y
				src.m_left = 83.0f; //x
				src.m_right = 154.0f; //x
				src.m_bottom = 336.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 224.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 63)//自動車　白　横
			{
				//切り取り位置の設定
				src.m_top = 349.0f;   //y
				src.m_left = 3.0f; //x
				src.m_right = 51.0f; //x
				src.m_bottom = 373.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 64)//自動車　黄土色　横
			{
				//切り取り位置の設定
				src.m_top = 344.0f;   //y
				src.m_left = 85.0f; //x
				src.m_right = 140.0f; //x
				src.m_bottom = 374.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 26.0f + mx_scroll;
				dst.m_right = j * 26.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 65)//自動車　青　左向き
			{
				//切り取り位置の設定
				src.m_top = 382.0f;   //y
				src.m_left = 5.0f; //x
				src.m_right = 70.0f; //x
				src.m_bottom = 419.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 66)//自動車　青　右向き
			{
				//切り取り位置の設定
				src.m_top = 383.0f;   //y
				src.m_left = 72.0f; //x
				src.m_right = 135.0f; //x
				src.m_bottom = 419.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 67)//自動車　左向き　白
			{
				//切り取り位置の設定
				src.m_top = 348.0f;   //y
				src.m_left = 218.0f; //x
				src.m_right = 282.0f; //x
				src.m_bottom = 382.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 68)//自動車　右向き　白
			{
				//切り取り位置の設定
				src.m_top = 347.0f;   //y
				src.m_left = 283.0f; //x
				src.m_right = 348.0f; //x
				src.m_bottom = 381.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 69)//自動車　左向き　赤
			{
				//切り取り位置の設定
				src.m_top = 393.0f;   //y
				src.m_left = 218.0f; //x
				src.m_right = 282.0f; //x
				src.m_bottom = 427.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 70)//自動車　右向き　赤
			{
				//切り取り位置の設定
				src.m_top = 393.0f;   //y
				src.m_left = 285.0f; //x
				src.m_right = 347.0f; //x
				src.m_bottom = 427.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 71)//自動車　左向き　灰色
			{
				//切り取り位置の設定
				src.m_top = 444.0f;   //y
				src.m_left = 219.0f; //x
				src.m_right = 284.0f; //x
				src.m_bottom = 477.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 72)//自動車　右向き　灰色
			{
				//切り取り位置の設定
				src.m_top = 444.0f;   //y
				src.m_left = 284.0f; //x
				src.m_right = 349.0f; //x
				src.m_bottom = 477.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 96.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 73)//自動車　下向き　青
			{
				//切り取り位置の設定
				src.m_top = 373.0f;   //y
				src.m_left = 137.0f; //x
				src.m_right = 168.0f; //x
				src.m_bottom = 425.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 64.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 96.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 74)//自動車　上向き　青
			{
				//切り取り位置の設定
				src.m_top = 373.0f;   //y
				src.m_left = 169.0f; //x
				src.m_right = 202.0f; //x
				src.m_bottom = 425.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 64.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 96.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 75)//自動車　下向き　白
			{
				//切り取り位置の設定
				src.m_top = 339.0f;   //y
				src.m_left = 350.0f; //x
				src.m_right = 380.0f; //x
				src.m_bottom = 385.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 64.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 96.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 76)//自動車　上向き　白
			{
				//切り取り位置の設定
				src.m_top = 343.0f;   //y
				src.m_left = 381.0f; //x
				src.m_right = 412.0f; //x
				src.m_bottom = 387.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 64.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 96.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 77)//自動車　下向き　赤
			{
				//切り取り位置の設定
				src.m_top = 386.0f;   //y
				src.m_left = 349.0f; //x
				src.m_right = 380.0f; //x
				src.m_bottom = 433.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 64.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 96.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 78)//自動車　上向き　赤
			{
				//切り取り位置の設定
				src.m_top = 388.0f;   //y
				src.m_left = 380.0f; //x
				src.m_right = 410.0f; //x
				src.m_bottom = 433.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 64.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 96.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 79)//自動車　下向き　灰色
			{
				//切り取り位置の設定
				src.m_top = 434.0f;   //y
				src.m_left = 350.0f; //x
				src.m_right = 382.0f; //x
				src.m_bottom = 481.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 64.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 96.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 80)//自動車　上向き　灰色
			{
				//切り取り位置の設定
				src.m_top = 434.0f;   //y
				src.m_left = 382.0f; //x
				src.m_right = 413.0f; //x
				src.m_bottom = 481.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 64.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 96.0f + my_scroll;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 81)//屋台的な
			{
				//切り取り位置の設定
				src.m_top = 8.0f;   //y
				src.m_left = 0.0f; //x
				src.m_right = 93.0f; //x
				src.m_bottom = 134.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 120.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 120.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 82)//建物
			{
				//切り取り位置の設定
				src.m_top = 2.0f;   //y
				src.m_left = 111.0f; //x
				src.m_right = 212.0f; //x
				src.m_bottom = 122.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 100.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 100.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 83)//公衆電話
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
			if (m_map[i][j] == 84)//噴水
			{
				//切り取り位置の設定
				src.m_top = 24.0f;   //y
				src.m_left = 355.0f; //x
				src.m_right = 438.0f; //x
				src.m_bottom = 89.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 85)//パイロン
			{
				//切り取り位置の設定
				src.m_top = 45.0f;   //y
				src.m_left = 460.0f; //x
				src.m_right = 588.0f; //x
				src.m_bottom = 95.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 86)//木
			{
				//切り取り位置の設定
				src.m_top = 22.0f;   //y
				src.m_left = 607.0f; //x
				src.m_right = 708.0f; //x
				src.m_bottom = 153.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 128.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 128.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 87)//黄色の看板
			{
				//切り取り位置の設定
				src.m_top = 159.0f;   //y
				src.m_left = 9.0f; //x
				src.m_right = 79.0f; //x
				src.m_bottom = 208.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 88)//ガードレール
			{
				//切り取り位置の設定
				src.m_top = 157.0f;   //y
				src.m_left = 103.0f; //x
				src.m_right = 257.0f; //x
				src.m_bottom = 194.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 89)//街灯
			{
				//切り取り位置の設定
				src.m_top = 145.0f;   //y
				src.m_left = 353.0f; //x
				src.m_right = 388.0f; //x
				src.m_bottom = 257.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 132.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 90)//電柱
			{
				//切り取り位置の設定
				src.m_top = 113.0f;   //y
				src.m_left = 434.0f; //x
				src.m_right = 476.0f; //x
				src.m_bottom = 273.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 128.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 91)//自販機
			{
				//切り取り位置の設定
				src.m_top = 119.0f;   //y
				src.m_left = 514.0f; //x
				src.m_right = 587.0f; //x
				src.m_bottom = 224.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 92)//木箱
			{
				//切り取り位置の設定
				src.m_top = 171.0f;   //y
				src.m_left = 612.0f; //x
				src.m_right = 656.0f; //x
				src.m_bottom = 250.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 93)//ゴミ箱
			{
				//切り取り位置の設定
				src.m_top = 179.0f;   //y
				src.m_left = 671.0f; //x
				src.m_right = 717.0f; //x
				src.m_bottom = 241.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 94)//木箱と布
			{
				//切り取り位置の設定
				src.m_top = 215.0f;   //y
				src.m_left = 12.0f; //x
				src.m_right = 97.0f; //x
				src.m_bottom = 284.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 95)//ツボ
			{
				//切り取り位置の設定
				src.m_top = 217.0f;   //y
				src.m_left = 228.0f; //x
				src.m_right = 260.0f; //x
				src.m_bottom = 290.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 96)//ツボ
			{
				//切り取り位置の設定
				src.m_top = 298.0f;   //y
				src.m_left = 117.0f; //x
				src.m_right = 171.0f; //x
				src.m_bottom = 364.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 99)//モブロボット表示
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

			if (m_map[i][j] == 100)//看板チャイナタウン
			{
				//切り取り位置の設定
				src.m_top = 48.0f;   //y
				src.m_left = 114.0f;  //x
				src.m_right = 205.0f; //x
				src.m_bottom = 189.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;//y
				dst.m_left = j * 32.0f + mx_scroll;//x
				dst.m_right = j * 32.0f + 64.0f + mx_scroll;//x
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll; //y

				//5番目に登録したグラフィックをstc・dst・cの情報を元に描画
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 101)//看板病院
			{
				//切り取り位置の設定
				src.m_top = 45.0f;   //y
				src.m_left =213.0f;  //x
				src.m_right = 292.0f; //x
				src.m_bottom = 203.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;//y
				dst.m_left = j * 32.0f + mx_scroll;//x
				dst.m_right = j * 32.0f + 56.0f + mx_scroll;//x
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll; //y

				//5番目に登録したグラフィックをstc・dst・cの情報を元に描画
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 102)//看板
			{
				//切り取り位置の設定
				src.m_top = 42.0f;   //y
				src.m_left = 313.0f;  //x
				src.m_right = 393.0f; //x
				src.m_bottom = 203.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;//y
				dst.m_left = j * 32.0f + mx_scroll;//x
				dst.m_right = j * 32.0f + 56.0f + mx_scroll;//x
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll; //y

				//5番目に登録したグラフィックをstc・dst・cの情報を元に描画
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 999)//当たり判定
			{
				//切り取り位置の設定
				src.m_top = 18.0f;   //y
				src.m_left = 390.0f; //x
				src.m_right = 415.0f; //x
				src.m_bottom = 40.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(7, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 1000)//当たり判定
			{
				
			}
			if (m_map[i][j] == 1001)//壁
			{
				//切り取り位置の設定
				src.m_top = 0.0f;   //y
				src.m_left = 0.0f; //x
				src.m_right = 75.0f; //x
				src.m_bottom = 75.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(7, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 1002)//壁
			{
				//切り取り位置の設定
				src.m_top = 18.0f;   //y
				src.m_left = 390.0f; //x
				src.m_right = 415.0f; //x
				src.m_bottom = 40.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(7, &src, &dst, c, 0.0f);
			}
			
		}
	}
}