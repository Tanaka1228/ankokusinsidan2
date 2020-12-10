//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL/DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"
#include"GameL/HitBoxManager.h"

#include"GameHead.h"
#include"ObjBlock.h"
#include"UtilityModule.h"



//使用するネームスペース
using namespace GameL;

extern int ChinaTown_Hero_x;

//イニシャライズ
void CObjBlock::Init()
{
	ChinaTown_Hero_x = 0;
	//マップ情報
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
	//マップデータをコピー
	memcpy(m_map, block_data, sizeof(int) * (25 * 25));
	map_flag = true;
	map_flag2 = false;

}
//アクション
void CObjBlock::Action()
{
	//主人公の位置を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX2();
	float hy = hero->GetY2();

	//主人公の衝突状態確認用フラグの初期化
	hero->SetUp(false);
	hero->SetDown(false);
	hero->SetLeft(false);
	hero->SetRight(false);

	//踏んでいるblockの種類を初期化
	hero->SetBT(0);

	//m_mapの全要素にアクセス
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			

			if (m_map[i][j] > 0)
			{
				
				//要素番号を座標に変更
				float x = j * 32.0f;
				float y = i * 32.0f;

				//主人公とブロックの当たり判定
				if ((hx + 32.0f > x) && (hx < x + 32.0f) && (hy + 32.0f > y) && (hy < y + 32.0f))
				{
					//上下左右判定

					//vectorの作成
					float vx = hx - x;
					float vy = hy - y;

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
						if ((r < 45 && r >= 0)||r>315)
						{
							//右
							hero->SetRight(true);//主人公の左の部分が衝突している
							hero->SetX2(x + 32.0f);//ブロックの位置+主人公の幅
							if(m_map[i][j]==17)
							hero->SetBT(m_map[i][j]);//ブロックの要素(type)を主人公に渡す
							hero->SetVX(0.0f);//-VX*反発係数
						}
						if (r > 45 && r < 135)
						{
							//上
							hero->SetDown(true);//主人公の下の部分が衝突している
							hero->SetY2(y - 32.0f);//ブロックの位置-主人公の幅
							if (m_map[i][j] == 17)
							hero->SetBT(m_map[i][j]);//ブロックの要素(type)を主人公に渡す
							hero->SetVY(0.0f);//-VX*反発係数
	
						}
						if (r > 135 && r < 225)
						{
							//左
							hero->SetLeft(true);//主人公の右の部分が衝突している
							hero->SetX2(x - 32.0f);//ブロックの位置-主人公の幅
							if (m_map[i][j] == 17)
							hero->SetBT(m_map[i][j]);//ブロックの要素(type)を主人公に渡す
							hero->SetVX(0.0f);//-VX*反発係数
						}
						if (r > 225 && r < 315)
						{
							//下
							hero->SetUp(true);//主人公の上の部分が衝突している
							hero->SetY2(y + 32.0f);//ブロックの位置+主人公の幅
							if (m_map[i][j] == 17)
							hero->SetBT(m_map[i][j]);//ブロックの要素(type)を主人公に渡す
							hero->SetVY(0.0f);//-VX*反発係数

						}

					}

					
					
					
					
					if (m_map[i][j] == 24)//外に移動するとチャイナタウン
					{
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
//ドロー
void CObjBlock::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置
	

	//背景表示
	src.m_top = 0.0f;
	src.m_left = 10.0f;
	src.m_right = 500.0f;
	src.m_bottom = 500.0f;

	dst.m_top = 85.0f;
	dst.m_left = 96.0f;
	dst.m_right = 704.0f;
	dst.m_bottom = 514.0f;
	Draw::Draw(9, &src, &dst, c, 0.0f);

	//マップチップによるblock設置
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			

			if (m_map[i][j] == 1)
			{
				//切り取り位置の設定
				src.m_top = 135.0f;   //y
				src.m_left = 315.0f; //x
				src.m_right = 450.0f; //x
				src.m_bottom = 215.0f; //y

				//表示位置の設定
				dst.m_top = i*32.0f;
				dst.m_left = j*32.0f;
				dst.m_right = dst.m_left+32.0;
				dst.m_bottom = dst.m_top+32.0;

				//描画
				Draw::Draw(8, &src, &dst, c, 0.0f);			
			}
			if (m_map[i][j] == 2)
			{
				//切り取り位置の設定
				src.m_top = 0.0f;   //y
				src.m_left = 220.0f; //x
				src.m_right =  280.0f; //x
				src.m_bottom = 60.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f;
				dst.m_left = j * 32.0;
				dst.m_right = dst.m_left + 32.0;
				dst.m_bottom = dst.m_top + 32.0;

				//描画
				Draw::Draw(8, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 3)
			{
				//切り取り位置の設定
				src.m_top = 60.0f;   //y
				src.m_left = 220.0f; //x
				src.m_right = 280.0f; //x
				src.m_bottom = 115.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f;
				dst.m_left = j * 32.0;
				dst.m_right = dst.m_left + 32.0;
				dst.m_bottom = dst.m_top + 32.0;

				//描画
				Draw::Draw(8, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 4)
			{
				//切り取り位置の設定
				src.m_top = 0.0f;   //y
				src.m_left = 350.0f; //x
				src.m_right = 380.0f; //x
				src.m_bottom = 45.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f;
				dst.m_left = j * 32.0;
				dst.m_right = dst.m_left + 32.0;
				dst.m_bottom = dst.m_top + 32.0;

				//描画
				Draw::Draw(8, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 5)
			{
				//切り取り位置の設定
				src.m_top = 0.0f;   //y
				src.m_left = 380.0f; //x
				src.m_right = 420.0f; //x
				src.m_bottom = 45.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f;
				dst.m_left = j * 32.0;
				dst.m_right = dst.m_left + 32.0;
				dst.m_bottom = dst.m_top + 32.0;

				//描画
				Draw::Draw(8, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 6)
			{
				//切り取り位置の設定
				src.m_top = 45.0f;   //y
				src.m_left = 350.0f; //x
				src.m_right = 380.0f; //x
				src.m_bottom = 80.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f;
				dst.m_left = j * 32.0;
				dst.m_right = dst.m_left + 32.0;
				dst.m_bottom = dst.m_top + 32.0;

				//描画
				Draw::Draw(8, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 7)
			{
				//切り取り位置の設定
				src.m_top = 45.0f;   //y
				src.m_left = 380.0f; //x
				src.m_right = 420.0f; //x
				src.m_bottom = 80.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f;
				dst.m_left = j * 32.0;
				dst.m_right = dst.m_left + 32.0;
				dst.m_bottom = dst.m_top + 32.0;

				//描画
				Draw::Draw(8, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 8)
			{
				//切り取り位置の設定
				src.m_top = 135.0f;   //y
				src.m_left = 320.0f; //x
				src.m_right = 435.0f; //x
				src.m_bottom = 315.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f;
				dst.m_left = j * 32.0;
				dst.m_right = dst.m_left + 32.0;
				dst.m_bottom = dst.m_top + 32.0;

				//描画
				Draw::Draw(8, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 9)
			{
				//切り取り位置の設定
				src.m_top = 150.0f;   //y
				src.m_left = 10.0f; //x
				src.m_right = 140.0f; //x
				src.m_bottom = 205.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f;
				dst.m_left = j * 32.0;
				dst.m_right = dst.m_left + 32.0;
				dst.m_bottom = dst.m_top + 32.0;

				//描画
				Draw::Draw(8, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 10)
			{
				//切り取り位置の設定
				src.m_top = 150.0f;   //y
				src.m_left = 140.0f; //x
				src.m_right = 255.0f; //x
				src.m_bottom = 205.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f;
				dst.m_left = j * 32.0;
				dst.m_right = dst.m_left + 32.0;
				dst.m_bottom = dst.m_top + 32.0;

				//描画
				Draw::Draw(8, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 11)
			{
				//切り取り位置の設定
				src.m_top = 205.0f;   //y
				src.m_left = 10.0f; //x
				src.m_right = 140.0f; //x
				src.m_bottom = 295.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f;
				dst.m_left = j * 32.0;
				dst.m_right = dst.m_left + 32.0;
				dst.m_bottom = dst.m_top + 32.0;

				//描画
				Draw::Draw(8, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 12)
			{
				//切り取り位置の設定
				src.m_top = 205.0f;   //y
				src.m_left = 140.0f; //x
				src.m_right = 255.0f; //x
				src.m_bottom = 295.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f;
				dst.m_left = j * 32.0;
				dst.m_right = dst.m_left + 32.0;
				dst.m_bottom = dst.m_top + 32.0;

				//描画
				Draw::Draw(8, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 13)
			{
				//切り取り位置の設定
				src.m_top = 295.0f;   //y
				src.m_left = 200.0f; //x
				src.m_right = 265.0f; //x
				src.m_bottom = 360.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f;
				dst.m_left = j * 32.0;
				dst.m_right = dst.m_left + 32.0;
				dst.m_bottom = dst.m_top + 32.0;

				//描画
				Draw::Draw(8, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 14)
			{
				//切り取り位置の設定
				src.m_top = 300.0f;   //y
				src.m_left = 110.0f; //x
				src.m_right = 170.0f; //x
				src.m_bottom = 365.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f;
				dst.m_left = j * 32.0;
				dst.m_right = dst.m_left + 32.0;
				dst.m_bottom = dst.m_top + 32.0;

				//描画
				Draw::Draw(8, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 15)
			{
				//切り取り位置の設定
				src.m_top = 345.0f;   //y
				src.m_left = 325.0f; //x
				src.m_right = 380.0f; //x
				src.m_bottom = 405.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f;
				dst.m_left = j * 32.0;
				dst.m_right = dst.m_left + 32.0;
				dst.m_bottom = dst.m_top + 32.0;

				//描画
				Draw::Draw(8, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 17)//女の子表示
			{
				//切り取り位置の設定
				src.m_top = 0.0f;   //y
				src.m_left = 0.0f;  //x
				src.m_right = 255.0f; //x
				src.m_bottom = 255.0f; //y

				//表示位置の設定
				dst.m_top = i*32.0f;//y
				dst.m_left = j*32.0f;//x
				dst.m_right = dst.m_left+32.0f;//x
				dst.m_bottom = dst.m_top+32.0f; //y

				//5番目に登録したグラフィックをstc・dst・cの情報を元に描画
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 20)//武器商売ロボット表示
			{
				//切り取り位置の設定
				src.m_top = 0.0f;   //y
				src.m_left = 0.0f;  //x
				src.m_right = 32.0f; //x
				src.m_bottom = 32.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f;//y
				dst.m_left = j * 32.0f;//x
				dst.m_right = dst.m_left + 32.0f;//x
				dst.m_bottom = dst.m_top + 32.0f; //y

				//5番目に登録したグラフィックをstc・dst・cの情報を元に描画
				Draw::Draw(11, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 23)//ドア
			{
				//切り取り位置の設定
				src.m_top = 400.0f;   //y
				src.m_left = 44.0f;  //x
				src.m_right = 90.0f; //x
				src.m_bottom = 466.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f;//y
				dst.m_left = j * 32.0f;//x
				dst.m_right = dst.m_left + 32.0f;//x
				dst.m_bottom = dst.m_top + 64.0f; //y

				//5番目に登録したグラフィックをstc・dst・cの情報を元に描画
				Draw::Draw(8, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 24)//当たり判定
			{
				//切り取り位置の設定
				src.m_top = 295.0f;   //y
				src.m_left = 200.0f; //x
				src.m_right = 265.0f; //x
				src.m_bottom = 360.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f;
				dst.m_left = j * 32.0;
				dst.m_right = dst.m_left + 32.0;
				dst.m_bottom = dst.m_top + 32.0;

				//描画
				Draw::Draw(8, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 25)//当たり判定
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