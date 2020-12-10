//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL/DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"

#include"GameHead.h"
#include "ObjHospital3.h"

//使用するネームスペース
using namespace GameL;

extern int Hos_Hero_x;

//イニシャライズ
void CObjHospital3::Init()
{
	mx_scroll = -420.0f;
	my_scroll = 0.0f;

	Hos_Hero_x =3;

	//マップ情報
	int block_data[MAP_Y_MAX][MAP_X_MAX] =
	{
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,1,35,35,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,32,32,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,34,0,1},
		{0,1,31,31,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,31,31,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,0,0,1},
		{0,1,31,31,0,1,1,1,1,1.1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,31,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,31,31,0,1},
		{0,1,31,31,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,31,31,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,31,31,0,1},
		{0,1,31,31,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,31,31,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,31,31,0,1},
		{0,1,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,1},
		{0,1,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,1},
		{0,1,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,1},
		{0,1,1,1,1,31,31,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,31,31,31,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,31,31,0,1,1,1,1},
		{0,2,2,2,1,31,31,0,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,33,33,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,31,31,0,1,2,2,2},
		{0,2,2,2,1,31,31,0,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,31,0,1,2,2,2},
		{0,0,0,2,1,1,36,0,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,36,0,1,0,0,0},
		{0,0,0,0,0,2,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,2,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},

	};
	//マップデータをコピー
	memcpy(m_map3, block_data, sizeof(int) * (MAP_Y_MAX * MAP_X_MAX));
	map_flag = true;
	map_flag2 = false;
}
//アクション
void CObjHospital3::Action()
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
	for (int i = 0; i < MAP_Y_MAX; i++)
	{
		for (int j = 0; j < MAP_X_MAX; j++)
		{
			if (m_map3[i][j] > 0&&m_map3[i][j]!=31)
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
						if (m_map3[i][j] == 32)//ドアに入ると病院屋上に移動
						{
							Scene::SetScene(new CSceneRooftop());
						}
						if (m_map3[i][j] == 33)//下ドアに入ると病院2階に移動
						{
							Scene::SetScene(new CSceneHospital2());
						}
						if (m_map3[i][j] == 34)//下ドアに入ると手術室に移動
						{
							Scene::SetScene(new CSceneOpeRoom());
						}
						if (m_map3[i][j] == 35)//下ドアに入るとレントゲン室に移動
						{
							Scene::SetScene(new CSceneXRayRoom());
						}
						if (m_map3[i][j] == 36)//下ドアに入ると診察室に移動
						{
							Scene::SetScene(new CSceneExRoom());
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
void CObjHospital3::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	Font::StrDraw(L"病院：3階", 600, 10, 32, c);

	//マップチップによるblock設置
	for (int i = 0; i < MAP_Y_MAX; i++)
	{
		for (int j = 0; j < MAP_X_MAX; j++)
		{

			if (m_map3[i][j] == 1)//壁　ボス
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
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map3[i][j] == 2)//壁　ボス
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
				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
			if (m_map3[i][j] == 3)//カーテン
			{
				//切り取り位置の設定
				src.m_top = 0.0f;   //y
				src.m_left = 90.0f; //x
				src.m_right = 280.0f; //x
				src.m_bottom = 85.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map3[i][j] == 4)//カウンター横
			{
				//切り取り位置の設定
				src.m_top = 0.0f;   //y
				src.m_left = 90.0f; //x
				src.m_right = 280.0f; //x
				src.m_bottom = 85.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map3[i][j] == 5)//カウンター縦
			{
				//切り取り位置の設定
				src.m_top = 0.0f;   //y
				src.m_left = 318.0f; //x
				src.m_right = 368.0f; //x
				src.m_bottom = 173.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map3[i][j] == 6)//テレビ
			{
				//切り取り位置の設定
				src.m_top = 0.0f;   //y
				src.m_left = 381.0f; //x
				src.m_right = 482.0f; //x
				src.m_bottom = 146.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map3[i][j] == 7)//縦長イス
			{
				//切り取り位置の設定
				src.m_top = 0.0f;   //y
				src.m_left = 632.0f; //x
				src.m_right = 712.0f; //x
				src.m_bottom = 158.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map3[i][j] == 8)//イス
			{
				//切り取り位置の設定
				src.m_top = 91.0f;   //y
				src.m_left = 0.0f; //x
				src.m_right = 143.0f; //x
				src.m_bottom = 176.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map3[i][j] == 9)//窓口
			{
				//切り取り位置の設定
				src.m_top = 94.0f;   //y
				src.m_left = 148.0f; //x
				src.m_right = 320.0f; //x
				src.m_bottom = 178.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map3[i][j] == 10)//ついたて
			{
				//切り取り位置の設定
				src.m_top = 83.0f;   //y
				src.m_left = 336.0f; //x
				src.m_right = 454.0f; //x
				src.m_bottom = 183.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map3[i][j] == 11)//椅子小 後ろ
			{
				//切り取り位置の設定
				src.m_top = 83.0f;   //y
				src.m_left = 336.0f; //x
				src.m_right = 454.0f; //x
				src.m_bottom = 183.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map3[i][j] == 12)//ゴミ箱
			{
				//切り取り位置の設定
				src.m_top = 147.0f;   //y
				src.m_left = 521.0f; //x
				src.m_right = 548.0f; //x
				src.m_bottom = 185.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map3[i][j] == 13)//横ベッド
			{
				//切り取り位置の設定
				src.m_top = 182.0f;   //y
				src.m_left = 1.0f; //x
				src.m_right = 120.0f; //x
				src.m_bottom = 269.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map3[i][j] == 14)//縦ベッド
			{
				//切り取り位置の設定
				src.m_top = 184.0f;   //y
				src.m_left = 137.0f; //x
				src.m_right = 214.0f; //x
				src.m_bottom = 323.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map3[i][j] == 15)//ちっさいテレビ
			{
				//切り取り位置の設定
				src.m_top = 186.0f;   //y
				src.m_left = 228.0f; //x
				src.m_right = 273.0f; //x
				src.m_bottom = 271.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map3[i][j] == 16)//ちっさい机
			{
				//切り取り位置の設定
				src.m_top = 207.0f;   //y
				src.m_left = 284.0f; //x
				src.m_right = 327.0f; //x
				src.m_bottom = 273.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map3[i][j] == 17)//椅子正面
			{
				//切り取り位置の設定
				src.m_top = 190.0f;   //y
				src.m_left = 334.0f; //x
				src.m_right = 363.0f; //x
				src.m_bottom = 232.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map3[i][j] == 18)//丸椅子
			{
				//切り取り位置の設定
				src.m_top = 237.0f;   //y
				src.m_left = 336.0f; //x
				src.m_right = 361.0f; //x
				src.m_bottom = 272.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map3[i][j] == 19)//栄養入れるやつ
			{
				//切り取り位置の設定
				src.m_top = 192.0f;   //y
				src.m_left = 367.0f; //x
				src.m_right = 400.0f; //x
				src.m_bottom = 276.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map3[i][j] == 20)//栄養入れるやつ 2
			{
				//切り取り位置の設定
				src.m_top = 192.0f;   //y
				src.m_left = 416.0f; //x
				src.m_right = 506.0f; //x
				src.m_bottom = 262.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map3[i][j] == 21)//機械1
			{
				//切り取り位置の設定
				src.m_top = 198.0f;   //y
				src.m_left = 521.0f; //x
				src.m_right = 543.0f; //x
				src.m_bottom = 258.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map3[i][j] == 22)//機械2
			{
				//切り取り位置の設定
				src.m_top = 195.0f;   //y
				src.m_left = 573.0f; //x
				src.m_right = 617.0f; //x
				src.m_bottom = 267.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map3[i][j] == 23)//機械3
			{
				//切り取り位置の設定
				src.m_top = 189.0f;   //y
				src.m_left = 627.0f; //x
				src.m_right = 685.0f; //x
				src.m_bottom = 267.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map3[i][j] == 24)//機械4
			{
				//切り取り位置の設定
				src.m_top = 278.0f;   //y
				src.m_left = 6.0f; //x
				src.m_right = 86.0f; //x
				src.m_bottom = 350.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map3[i][j] == 25)//洗面
			{
				//切り取り位置の設定
				src.m_top = 283.0f;   //y
				src.m_left = 232.0f; //x
				src.m_right = 323.0f; //x
				src.m_bottom = 334.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map3[i][j] == 26)//車椅子
			{
				//切り取り位置の設定
				src.m_top = 280.0f;   //y
				src.m_left = 336.0f; //x
				src.m_right = 418.0f; //x
				src.m_bottom = 347.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map3[i][j] == 27)//緑ソファ縦
			{
				//切り取り位置の設定
				src.m_top = 360.0f;   //y
				src.m_left = 5.0f; //x
				src.m_right = 53.0f; //x
				src.m_bottom = 473.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map3[i][j] == 28)//緑ソファ横
			{
				//切り取り位置の設定
				src.m_top = 408.0f;   //y
				src.m_left = 54.0f; //x
				src.m_right = 161.0f; //x
				src.m_bottom = 473.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map3[i][j] == 29)//ベッド
			{
				//切り取り位置の設定
				src.m_top = 350.0f;   //y
				src.m_left = 173.0f; //x
				src.m_right = 237.0f; //x
				src.m_bottom = 473.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map3[i][j] == 30)// M R I
			{
				//切り取り位置の設定
				src.m_top = 350.0f;   //y
				src.m_left = 244.0f; //x
				src.m_right = 371.0f; //x
				src.m_bottom = 517.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map3[i][j] == 30)// 棚
			{
				//切り取り位置の設定
				src.m_top = 485.0f;   //y
				src.m_left = 10.0f; //x
				src.m_right = 129.0f; //x
				src.m_bottom = 554.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map3[i][j] == 30)// 棚 2
			{
				//切り取り位置の設定
				src.m_top = 485.0f;   //y
				src.m_left = 147.0f; //x
				src.m_right = 234.0f; //x
				src.m_bottom = 554.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(4, &src, &dst, c, 0.0f);
			}
			if (m_map3[i][j] == 31) 
			{
				//背景表示
				src.m_top = 0.0f;   // Y
				src.m_left = 0.0f;  // X
				src.m_right = 87.0f; // X
				src.m_bottom = 87.0f;// Y 

				dst.m_top    = i*   32.0f        + my_scroll;
				dst.m_left   = j*   32.0f        + mx_scroll;
				dst.m_right  = j*   32.0f +64.0f + mx_scroll;
				dst.m_bottom = i*   32.0f +64.0f + my_scroll;

				Draw::Draw(6, &src, &dst, c, 0.0f);//病院の床
			}
			if (m_map3[i][j] == 33)//エレベーター
			{
				//背景表示
				src.m_top = 6.0f;   // Y
				src.m_left = 8.0f;  // X
				src.m_right = 71.0f; // X
				src.m_bottom = 59.0f;// Y 

				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 64.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				Draw::Draw(7, &src, &dst, c, 0.0f);
			}



			if (m_map3[i][j] == 34)//ドア
			{
				//切り取り位置の設定
				src.m_top = 400.0f;   //y
				src.m_left = 44.0f;  //x
				src.m_right = 90.0f; //x
				src.m_bottom = 466.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;//y
				dst.m_left = j * 32.0f + mx_scroll;//x
				dst.m_right = j * 32.0f + 64.0f + mx_scroll;//x
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll; //y

				//5番目に登録したグラフィックをstc・dst・cの情報を元に描画
				Draw::Draw(8, &src, &dst, c, 0.0f);
			}
			if (m_map3[i][j] == 35) //レントゲン室前ドア
			{
				//切り取り位置の設定
				src.m_top = 400.0f;   //y
				src.m_left = 44.0f;  //x
				src.m_right = 90.0f; //x
				src.m_bottom = 466.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;//y
				dst.m_left = j * 32.0f + mx_scroll;//x
				dst.m_right =j*32.0f + 32.0f + mx_scroll;//x
				dst.m_bottom = i*32.0f + 64.0f + my_scroll; //y

				//5番目に登録したグラフィックをstc・dst・cの情報を元に描画
				Draw::Draw(8, &src, &dst, c, 0.0f);
			}
			if (m_map3[i][j] == 36) //診察室前ドア
			{
				//切り取り位置の設定
				src.m_top = 400.0f;   //y
				src.m_left = 44.0f;  //x
				src.m_right = 90.0f; //x
				src.m_bottom = 466.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;//y
				dst.m_left = j * 32.0f + mx_scroll;//x
				dst.m_right = j * 32.0f + 64.0f + mx_scroll;//x
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll; //y

				//5番目に登録したグラフィックをstc・dst・cの情報を元に描画
				Draw::Draw(8, &src, &dst, c, 0.0f);
			}
		}
	}
}