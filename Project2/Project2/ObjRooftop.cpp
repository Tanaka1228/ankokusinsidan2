//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL/SceneObjManager.h"

#include"GameHead.h"
#include"ObjRooftop.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjRooftop::Init()
{
	mx_scroll = -850.0f;//主人公の初期位置
	my_scroll = -400.0f;

	
	//マップ情報
	int block_data[38][83] =
	{
		{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,1,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,25,34,1},
	    {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,18,18,18,18,6,4,5,18,4,5,18,18,6,18,18,9,9,9,9,20,9,9,9,20,9,9,10,10,10,10,19,10,10,10,19,10,10,11,12,4,5,29,4,5,10,26,35,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,45,45,45,45,45,0,0,0,0,0,0,8,45,45,45,45,45,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,45,45,45,45,45,45,0,0,0,0,0,0,45,45,45,45,45,45,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,45,45,45,45,45,45,0,0,0,0,0,0,45,45,45,45,45,45,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,45,45,45,45,45,45,0,0,0,0,0,0,45,45,45,45,45,45,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,45,45,45,45,45,45,0,0,0,0,0,0,45,45,45,45,45,45,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,45,45,45,45,45,45,0,0,0,0,0,0,45,45,45,45,45,45,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,7,7,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,7,7,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,37,38,7,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,34,7,7,39,40,7,7,43,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,35,7,7,41,42,7,7,44,0,0,0,0,8,45,45,45,45,45,0,0,0,0,0,0,8,45,45,45,45,45,0,0,0,0,0,0,0,0,0,0,0,0,0,0,99,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,45,45,45,45,45,45,0,0,0,0,0,0,45,45,45,45,45,45,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,45,45,45,45,45,45,0,0,0,0,0,0,45,45,45,45,45,45,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,45,45,45,45,45,45,0,0,0,0,0,0,45,45,45,45,45,45,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,45,45,45,45,45,45,0,0,0,0,0,0,45,45,45,45,45,45,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,45,45,45,45,45,45,0,0,0,0,0,0,45,45,45,45,45,45,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,25,0,0,0,0,0,0,0,0,0,0,21,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,13,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,26,23,23,23,23,23,2,3,23,2,3,22,24,24,24,24,24,36,36,36,36,36,36,16,16,16,16,16,16,16,16,16,14,27,27,28,28,32,2,3,31,2,3,33,29,12,1},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	    {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7},


	};
	//マップデータをコピー
	memcpy(m_map, block_data, sizeof(int) * (38 * 83));
	map_flag = true;
	map_flag2 = false;
}
//アクション
void CObjRooftop::Action()
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
	for (int i = 0; i < 38; i++)
	{
		for (int j = 0; j < 83; j++)
		{
			if (m_map[i][j] > 0&&m_map[i][j]!=15)
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
							if (m_map[i][j] == 99 )
								hero->SetBT(m_map[i][j]);//ブロックの要素(type)を主人公に渡す
							hero->SetVX(0.0f);//-VX*反発係数
						}
						if (r > 45 && r < 135)
						{
							//上
							hero->SetDown(true);//主人公の下の部分が衝突している
							hero->SetY2(y - 40.0f + (my_scroll));//ブロックの位置-主人公の幅
							if (m_map[i][j] == 99)
								hero->SetBT(m_map[i][j]);//ブロックの要素(type)を主人公に渡す
							hero->SetVY(0.0f);//-VX*反発係数

						}
						if (r > 135 && r < 225)
						{
							//左
							hero->SetLeft(true);//主人公の右の部分が衝突している
							hero->SetX2(x - 40.0f + (mx_scroll));//ブロックの位置-主人公の幅
							if (m_map[i][j] == 99)
								hero->SetBT(m_map[i][j]);//ブロックの要素(type)を主人公に渡す
							hero->SetVX(0.0f);//-VX*反発係数
						}
						if (r > 225 && r < 315)
						{
							//下
							hero->SetUp(true);//主人公の上の部分が衝突している
							hero->SetY2(y + 40.0f + (my_scroll));//ブロックの位置+主人公の幅
							if (m_map[i][j] == 99)
								hero->SetBT(m_map[i][j]);//ブロックの要素(type)を主人公に渡す
							hero->SetVY(0.0f);//-VX*反発係数
						}
						if (m_map[i][j] == 41||m_map[i][j]==42)//ドアに入ると病院に移動
						{
							Scene::SetScene(new CSceneHospital3());
						}
						
					}
				}
				

				
			}
		}
	}

	//敵出現ライン
	float Xline = hx + (-mx_scroll)+ 400;
	float Yline = hy + (my_scroll)-100;

	int ex = ((int)Xline) / 32;
	int ey = ((int)Yline) / 32;

	for (int i = 0; i < 38; i++)
	{
		//for (int j = 0; j < 83; j++)
		
			if (m_map[i][ex] == 15)
			{
				//誘導敵機オブジェクト作成
				CObjRooftopBoss* obj_rooftop_boss = new CObjRooftopBoss(ex * 32, i * 32); //誘導敵機オブジェクト作成
				Objs::InsertObj(obj_rooftop_boss, OBJ_ROOF_TOP_BOSS, 4); //誘導敵機オブジェクトをオブジェクトマネージャーに登録

				m_map[i][ex] = 0;
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
void CObjRooftop::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り背景表示
	src.m_top = 0.0f ;
	src.m_left = 3.0f ;
	src.m_right = 500.0f ;
	src.m_bottom = 170.0f ;
	
	//表示位置の設定
	dst.m_top = 64.0f + my_scroll;    //y
	dst.m_left = 64.0f + mx_scroll;   //x
	dst.m_right = 2655.0f + mx_scroll;  //x
	dst.m_bottom = 1057.0f + my_scroll; //y

	Draw::Draw(10, &src, &dst, c, 0.0f);
	/*dst.m_top = -100.0f + my_scroll;
	dst.m_left = -100.0f + mx_scroll;
	dst.m_right = 1500.0f + mx_scroll;
	dst.m_bottom = 1468.0f + my_scroll;*/

	

	//マップチップによるblock設置
	for (int i = 0; i < 38; i++)
	{
		for (int j = 0; j < 83; j++)
		{
			
			if (m_map[i][j] == 1)//壁
			{
				//切り取り位置の設定
				src.m_top = 0.0f;   //y
				src.m_left = 0.0f; //x
				src.m_right = 75.0f; //x
				src.m_bottom = 75.0f; //y

				//表示位置の設定
				dst.m_top    =  i*32.0f + my_scroll;
				dst.m_left   =  j*32.0f + mx_scroll;
				dst.m_right  =  j*32.0f+32.0f + mx_scroll;
				dst.m_bottom =  i*32.0f+32.0f + my_scroll;

				//描画
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 2)//ベンチ
			{
				//切り取り位置の設定
				src.m_top = 15.0f;   //y
				src.m_left = 100.0f; //x
				src.m_right = 130.0f; //x
				src.m_bottom = 70.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 3)//ベンチ
			{
				//切り取り位置の設定
				src.m_top = 15.0f;   //y
				src.m_left = 130.0f; //x
				src.m_right = 170.0f; //x
				src.m_bottom = 70.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 4)//ベンチ
			{
				//切り取り位置の設定
				src.m_top = 20.0f;   //y
				src.m_left = 180.0f; //x
				src.m_right = 210.0f; //x
				src.m_bottom = 65.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 5)//ベンチ
			{
				//切り取り位置の設定
				src.m_top = 20.0f;   //y
				src.m_left = 210.0f; //x
				src.m_right = 245.0f; //x
				src.m_bottom = 65.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 6)//草
			{
				//切り取り位置の設定
				src.m_top = 20.0f;   //y
				src.m_left = 260.0f; //x
				src.m_right = 293.0f; //x
				src.m_bottom = 55.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 7)//壁
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
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 8)//花壇
			{
				//切り取り位置の設定
				src.m_top = 15.0f;   //y
				src.m_left = 305.0f; //x
				src.m_right = 370.0f; //x
				src.m_bottom = 77.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 200.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 200.0f + my_scroll;

				//描画
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}
			
			if (m_map[i][j] == 9)//草
			{
				//切り取り位置の設定
				src.m_top = 7.0f;   //y
				src.m_left = 430.0f; //x
				src.m_right = 495.0f; //x
				src.m_bottom = 55.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 10)//草
			{
				//切り取り位置の設定
				src.m_top = 85.0f;   //y
				src.m_left = 5.0f; //x
				src.m_right = 43.0f; //x
				src.m_bottom = 115.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 11)//草
			{
				//切り取り位置の設定
				src.m_top = 87.0f;   //y
				src.m_left = 47.0f; //x
				src.m_right = 83.0f; //x
				src.m_bottom = 118.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 12)//草
			{
				//切り取り位置の設定
				src.m_top = 77.0f;   //y
				src.m_left = 92.0f; //x
				src.m_right = 129.0f; //x
				src.m_bottom = 108.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 13)//草
			{
				//切り取り位置の設定
				src.m_top = 70.0f;   //y
				src.m_left = 130.0f; //x
				src.m_right = 165.0f; //x
				src.m_bottom = 105.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 14)//草
			{
				//切り取り位置の設定
				src.m_top = 105.0f;   //y
				src.m_left = 130.0f; //x
				src.m_right = 165.0f; //x
				src.m_bottom = 130.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 16)//草
			{
				//切り取り位置の設定
				src.m_top = 75.0f;   //y
				src.m_left = 177.0f; //x
				src.m_right = 208.0f; //x
				src.m_bottom = 97.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 17)//草
			{
				//切り取り位置の設定
				src.m_top = 73.0f;   //y
				src.m_left = 215.0f; //x
				src.m_right = 270.0f; //x
				src.m_bottom = 115.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 18)//草
			{
				//切り取り位置の設定
				src.m_top = 82.0f;   //y
				src.m_left = 276.0f; //x
				src.m_right = 312.0f; //x
				src.m_bottom = 113.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 19)//草
			{
				//切り取り位置の設定
				src.m_top = 86.0f;   //y
				src.m_left = 321.0f; //x
				src.m_right = 352.0f; //x
				src.m_bottom = 108.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 20)//草
			{
				//切り取り位置の設定
				src.m_top = 88.0f;   //y
				src.m_left = 364.0f; //x
				src.m_right = 397.0f; //x
				src.m_bottom = 115.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}


			if (m_map[i][j] == 21)//草
			{
				//切り取り位置の設定
				src.m_top = 71.0f;   //y
				src.m_left = 408.0f; //x
				src.m_right = 450.0f; //x
				src.m_bottom = 105.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 22)//草
			{
				//切り取り位置の設定
				src.m_top = 105.0f;   //y
				src.m_left = 408.0f; //x
				src.m_right = 450.0f; //x
				src.m_bottom = 132.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 23)//草
			{
				//切り取り位置の設定
				src.m_top = 127.0f;   //y
				src.m_left = 11.0f; //x
				src.m_right = 49.0f; //x
				src.m_bottom = 159.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 24)//草
			{
				//切り取り位置の設定
				src.m_top = 135.0f;   //y
				src.m_left = 55.0f; //x
				src.m_right = 85.0f; //x
				src.m_bottom = 166.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 25)//草
			{
				//切り取り位置の設定
				src.m_top = 133.0f;   //y
				src.m_left = 92.0f; //x
				src.m_right = 123.0f; //x
				src.m_bottom = 164.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 26)//草
			{
				//切り取り位置の設定
				src.m_top = 164.0f;   //y
				src.m_left = 92.0f; //x
				src.m_right = 123.0f; //x
				src.m_bottom = 194.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 27)//花
			{
				//切り取り位置の設定
				src.m_top = 134.0f;   //y
				src.m_left = 133.0f; //x
				src.m_right = 199.0f; //x
				src.m_bottom = 198.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 28)//花
			{
				//切り取り位置の設定
				src.m_top = 123.0f;   //y
				src.m_left = 206.0f; //x
				src.m_right = 274.0f; //x
				src.m_bottom = 190.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 29)//草
			{
				//切り取り位置の設定
				src.m_top = 122.0f;   //y
				src.m_left = 284.0f; //x
				src.m_right = 326.0f; //x
				src.m_bottom = 177.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 30)//花
			{
				//切り取り位置の設定
				src.m_top = 122.0f;   //y
				src.m_left = 342.0f; //x
				src.m_right = 373.0f; //x
				src.m_bottom = 152.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 31)//花
			{
				//切り取り位置の設定
				src.m_top = 133.0f;   //y
				src.m_left = 382.0f; //x
				src.m_right = 419.0f; //x
				src.m_bottom = 166.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 32)//花
			{
				//切り取り位置の設定
				src.m_top = 140.0f;   //y
				src.m_left = 425.0f; //x
				src.m_right = 460.0f; //x
				src.m_bottom = 171.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 33)//花
			{
				//切り取り位置の設定
				src.m_top = 176.0f;   //y
				src.m_left = 8.0f; //x
				src.m_right = 42.0f; //x
				src.m_bottom = 205.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 34)//木
			{
				//切り取り位置の設定
				src.m_top = 176.0f;   //y
				src.m_left = 54.0f; //x
				src.m_right = 88.0f; //x
				src.m_bottom = 205.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 35)//木
			{
				//切り取り位置の設定
				src.m_top = 205.0f;   //y
				src.m_left = 54.0f; //x
				src.m_right = 88.0f; //x
				src.m_bottom = 240.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 36)//草
			{
				//切り取り位置の設定
				src.m_top = 199.0f;   //y
				src.m_left = 87.0f; //x
				src.m_right = 151.0f; //x
				src.m_bottom = 288.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 37)//出入口
			{
				//切り取り位置の設定
				src.m_top = 215.0f;   //y
				src.m_left = 165.0f; //x
				src.m_right = 180.0f; //x
				src.m_bottom = 235.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 38)//出入口
			{
				//切り取り位置の設定
				src.m_top = 215.0f;   //y
				src.m_left = 180.0f; //x
				src.m_right = 193.0f; //x
				src.m_bottom = 235.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 39)//出入口
			{
				//切り取り位置の設定
				src.m_top = 235.0f;   //y
				src.m_left = 165.0f; //x
				src.m_right = 180.0f; //x
				src.m_bottom = 250.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 40)//出入口
			{
				//切り取り位置の設定
				src.m_top = 235.0f;   //y
				src.m_left = 180.0f; //x
				src.m_right = 193.0f; //x
				src.m_bottom = 250.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 41)//出入口
			{
				//切り取り位置の設定
				src.m_top = 250.0f;   //y
				src.m_left = 165.0f; //x
				src.m_right = 180.0f; //x
				src.m_bottom = 268.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 42)//出入口
			{
				//切り取り位置の設定
				src.m_top = 250.0f;   //y
				src.m_left = 180.0f; //x
				src.m_right = 193.0f; //x
				src.m_bottom = 268.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 43)//自販機
			{
				//切り取り位置の設定
				src.m_top = 215.0f;   //y
				src.m_left = 219.0f; //x
				src.m_right = 280.0f; //x
				src.m_bottom = 260.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 44)//自販機
			{
				//切り取り位置の設定
				src.m_top = 260.0f;   //y
				src.m_left = 219.0f; //x
				src.m_right = 280.0f; //x
				src.m_bottom = 288.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

				//描画
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}
			if (m_map[i][j] == 45)//当たり判定
			{
				//切り取り位置の設定
				src.m_top = 0.0f;   //y
				src.m_left = 0.0f; //x
				src.m_right = 0.0f; //x
				src.m_bottom = 0.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 32.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 32.0f + my_scroll;

			}
		
			if (m_map[i][j] == 46)//出入口
			{
				//切り取り位置の設定
				src.m_top = 250.0f;   //y
				src.m_left = 180.0f; //x
				src.m_right = 193.0f; //x
				src.m_bottom = 268.0f; //y

				//表示位置の設定
				dst.m_top = i * 32.0f + my_scroll;
				dst.m_left = j * 32.0f + mx_scroll;
				dst.m_right = j * 32.0f + 64.0f + mx_scroll;
				dst.m_bottom = i * 32.0f + 64.0f + my_scroll;

				//描画
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}
			else if (m_map[i][j] == 15)//敵
			{
				;
			}
			if (m_map[i][j] == 99)//武器商売ロボット表示
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
		}
	}
}
