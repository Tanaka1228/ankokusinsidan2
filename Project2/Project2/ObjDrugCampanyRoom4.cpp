//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL/DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"

#include"GameHead.h"
#include "ObjDrugCampanyRoom4.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjDrugCampanyRoom4::Init()
{
	mx_scroll = 0.0f;
	my_scroll = 0.0f;

	//マップ情報
	int block_data[200][200] =
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,21,21,18,18,16,16,18,16,21,21,0,0,0,0,0,0,0,30,30,0,11,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,0,0,0,19,19,19,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,26,26,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,26,26,26,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},

	};
	//マップデータをコピー
	memcpy(m_map, block_data, sizeof(int) * (200 * 200));

}
//アクション
void CObjDrugCampanyRoom4::Action()
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
	for (int i = 0; i < 200; i++)
	{
		for (int j = 0; j < 200; j++)
		{
			if (m_map[i][j] > 0 && m_map[i][j] != 15)
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
							hero->SetVX(0.0f);//-VX*反発係数
						}
						if (r > 45 && r < 135)
						{
							//上
							hero->SetDown(true);//主人公の下の部分が衝突している
							hero->SetY2(y - 40.0f + (my_scroll));//ブロックの位置-主人公の幅
							hero->SetVY(0.0f);//-VX*反発係数

						}
						if (r > 135 && r < 225)
						{
							//左
							hero->SetLeft(true);//主人公の右の部分が衝突している
							hero->SetX2(x - 40.0f + (mx_scroll));//ブロックの位置-主人公の幅
							hero->SetVX(0.0f);//-VX*反発係数
						}
						if (r > 225 && r < 315)
						{
							//下
							hero->SetUp(true);//主人公の上の部分が衝突している
							hero->SetY2(y + 40.0f + (my_scroll));//ブロックの位置+主人公の幅
							hero->SetVY(0.0f);//-VX*反発係数
						}
						if (m_map[i][j] == 5)//ドアに入ると拠点に移動
						{
							Scene::SetScene(new CSceneDrugCampany());
						}
					}
				}



			}
		}
	}

	//敵出現ライン
	//float Xline = hx + (-mx_scroll) + 400;
	//float Yline = hy + (my_scroll)-100;

	//int ex = ((int)Xline) / 32;
	//int ey = ((int)Yline) / 32;

	//for (int i = 0; i < 25; i++)
	//{
	//	for (int j = 0; j < 25; j++)

	//		if (m_map[i][ex] == 15)
	//		{
	//			//誘導敵機オブジェクト作成
	//			CObjRooftopBoss* obj_rooftop_boss = new CObjRooftopBoss(ex * 32, i * 32); //誘導敵機オブジェクト作成
	//			Objs::InsertObj(obj_rooftop_boss, OBJ_ROOF_TOP_BOSS, 4); //誘導敵機オブジェクトをオブジェクトマネージャーに登録

	//			m_map[i][ex] = 0;
	//		}


	//}

}
//ドロー
void CObjDrugCampanyRoom4::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//背景表示
	src.m_top = 0.0f;   // Y
	src.m_left = 0.0f;  // X
	src.m_right = 500.0f; // X
	src.m_bottom = 500.0f;// Y 

	dst.m_top = 0.0f + my_scroll;
	dst.m_left = 0.0f + mx_scroll;
	dst.m_right = 4400.0f + mx_scroll;
	dst.m_bottom = 4400.0 + my_scroll;
	Draw::Draw(5, &src, &dst, c, 0.0f);

	//マップチップによるblock設置
	for (int i = 0; i < 200; i++)
	{
		for (int j = 0; j < 200; j++)
		{
			if (m_map[i][j] == 1)//壁
			{
				//切り取り位置の設定
				src.m_top = 239.0f;   //y
				src.m_left = 211.0f; //x
				src.m_right = 310.0f; //x
				src.m_bottom = 309.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 2)//避難誘導
			{
				//切り取り位置の設定
				src.m_top = 288.0f;   //y
				src.m_left = 175.0f; //x
				src.m_right = 211.0f; //x
				src.m_bottom = 309.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 3)//傘立て
			{
				//切り取り位置の設定
				src.m_top = 347.0f;   //y
				src.m_left = 106.0f; //x
				src.m_right = 179.0f; //x
				src.m_bottom = 389.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 33.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 4)//	自販機
			{
				//切り取り位置の設定
				src.m_top = 318.0f;   //y
				src.m_left = 0.0f; //x
				src.m_right = 70.0f; //x
				src.m_bottom = 388.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 33.5f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.5f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 5)//扉１
			{
				//切り取り位置の設定
				src.m_top = 236.0f;   //y
				src.m_left = 535.0f; //x
				src.m_right = 581.0f; //x
				src.m_bottom = 307.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 6)//扉２
			{
				//切り取り位置の設定
				src.m_top = 237.0f;   //y
				src.m_left = 591.0f; //x
				src.m_right = 620.0f; //x
				src.m_bottom = 311.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 7)//エレベーター
			{
				//切り取り位置の設定
				src.m_top = 325.0f;   //y
				src.m_left = 191.0f; //x
				src.m_right = 236.0f; //x
				src.m_bottom = 387.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}
			if (m_map[i][j] == 8)//CTスキャン
			{
				//切り取り位置の設定
				src.m_top = 4.0f;   //y
				src.m_left = 0.0f; //x
				src.m_right = 83.0f; //x
				src.m_bottom = 127.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 9)//PC
			{
				//切り取り位置の設定
				src.m_top = 74.0f;   //y
				src.m_left = 89.0f; //x
				src.m_right = 183.0f; //x
				src.m_bottom = 127.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 10)//デスクトップPC
			{
				//切り取り位置の設定
				src.m_top = 68.0f;   //y
				src.m_left = 188.0f; //x
				src.m_right = 223.0f; //x
				src.m_bottom = 127.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 33.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 11)//謎水槽
			{
				//切り取り位置の設定
				src.m_top = 0.0f;   //y
				src.m_left = 227.0f; //x
				src.m_right = 293.0f; //x
				src.m_bottom = 127.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 33.5f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.5f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 12)//カーテン
			{
				//切り取り位置の設定
				src.m_top = 76.0f;   //y
				src.m_left = 297.0f; //x
				src.m_right = 404.0f; //x
				src.m_bottom = 127.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 13)//机
			{
				//切り取り位置の設定
				src.m_top = 50.0f;   //y
				src.m_left = 407.0f; //x
				src.m_right = 549.0f; //x
				src.m_bottom = 128.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 14)//ホワイトボード
			{
				//切り取り位置の設定
				src.m_top = 179.0f;   //y
				src.m_left = 124.0f; //x
				src.m_right = 229.0f; //x
				src.m_bottom = 223.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 15)//レントゲン（下半身）
			{
				//切り取り位置の設定
				src.m_top = 198.0f;   //y
				src.m_left = 232.0f; //x
				src.m_right = 225.0f; //x
				src.m_bottom = 223.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 16)//レントゲン（手）
			{
				//切り取り位置の設定
				src.m_top = 207.0f;   //y
				src.m_left = 257.0f; //x
				src.m_right = 281.0f; //x
				src.m_bottom = 223.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 17)//レントゲン（上半身）
			{
				//切り取り位置の設定
				src.m_top = 198.0f;   //y
				src.m_left = 283.0f; //x
				src.m_right = 206.0f; //x
				src.m_bottom = 223.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 18)//レントゲン（頭）
			{
				//切り取り位置の設定
				src.m_top = 201.0f;   //y
				src.m_left = 308.0f; //x
				src.m_right = 326.0f; //x
				src.m_bottom = 223.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 19)//テーブル
			{
				//切り取り位置の設定
				src.m_top = 152.0f;   //y
				src.m_left = 328.0f; //x
				src.m_right = 434.0f; //x
				src.m_bottom = 223.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 20)//テーブル
			{
				//切り取り位置の設定
				src.m_top = 152.0f;   //y
				src.m_left = 434.0f; //x
				src.m_right = 469.0f; //x
				src.m_bottom = 223.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 21)//機械１
			{
				//切り取り位置の設定
				src.m_top = 158.0f;   //y
				src.m_left = 473.0f; //x
				src.m_right = 542.0f; //x
				src.m_bottom = 223.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 22)//試験管１
			{
				//切り取り位置の設定
				src.m_top = 202.0f;   //y
				src.m_left = 544.0f; //x
				src.m_right = 572.0f; //x
				src.m_bottom = 223.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 23)//試験管２
			{
				//切り取り位置の設定
				src.m_top = 202.0f;   //y
				src.m_left = 580.0f; //x
				src.m_right = 607.0f; //x
				src.m_bottom = 223.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 24)//本棚１
			{
				//切り取り位置の設定
				src.m_top = 240.0f;   //y
				src.m_left = 0.0f; //x
				src.m_right = 36.0f; //x
				src.m_bottom = 308.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 25)//本棚２
			{
				//切り取り位置の設定
				src.m_top = 240.0f;   //y
				src.m_left = 35.0f; //x
				src.m_right = 106.0f; //x
				src.m_bottom = 308.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 26)//棚
			{
				//切り取り位置の設定
				src.m_top = 240.0f;   //y
				src.m_left = 105.0f; //x
				src.m_right = 175.0f; //x
				src.m_bottom = 308.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 27)//本棚３
			{
				//切り取り位置の設定
				src.m_top = 238.0f;   //y
				src.m_left = 317.0f; //x
				src.m_right = 423.0f; //x
				src.m_bottom = 308.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 28)//薬品棚
			{
				//切り取り位置の設定
				src.m_top = 274.0f;   //y
				src.m_left = 423.0f; //x
				src.m_right = 493.0f; //x
				src.m_bottom = 310.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 29)//ＣＤ
			{
				//切り取り位置の設定
				src.m_top = 270.0f;   //y
				src.m_left = 493.0f; //x
				src.m_right = 530.0f; //x
				src.m_bottom = 309.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}

			if (m_map[i][j] == 30)//ゴミ箱
			{
				//切り取り位置の設定
				src.m_top = 335.0f;   //y
				src.m_left = 69.0f; //x
				src.m_right = 107.0f; //x
				src.m_bottom = 387.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);

			}
		}
	}
}