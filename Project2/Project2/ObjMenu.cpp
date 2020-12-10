//使用するヘッダ―ファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"
#include"GameL\DrawFont.h"

#include"GameHead.h"
#include"ObjTitle.h"
#include"SceneMain.h"
#include"ObjMenu.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjMenu::Init()
{
	
}

//アクション
void CObjMenu::Action()
{
	


}

//ドロー
void CObjMenu::Draw()
{

	//描画カラー情報　R=RED G=Green B=Blue A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 12.0f; //y
	src.m_left = 572.0f; //x
	src.m_right = 785.0f; //x
	src.m_bottom = 531.0f; //y

	//表示位置の設定
	dst.m_top  = 0.0f;
	dst.m_left =600.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 500.0f;

	//11番目に登録したグラフィックをstc・dst・cの情報を元に描画
	Draw::Draw(11, &src, &dst, c, 0.0f);

}