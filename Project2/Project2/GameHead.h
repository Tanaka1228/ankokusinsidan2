#pragma once

//オブジェクトネーム------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//オブジェクト名無し(禁止)
					//ゲームで使うオブジェクトの名前
					//OBJ_○○と表記
					OBJ_MAIN,
					OBJ_HERO, //主人公
					OBJ_TITLE,//ゲームタイトル
					OBJ_ENEMY,//敵１
					OBJ_BULLET,//弾丸
					OBJ_GAME_OVER,//ゲームオーバー
					OBJ_TITLE_BACKGROUND,//ゲームタイトルの背景
					OBJ_ATTACK_ENEMY,//攻撃敵機
					OBJ_BULLET_ENEMY,//弾丸敵機
					OBJ_HOMING_ENEMY,//誘導敵機
					OBJ_SIN_ENEMY,//カーブ敵機
					OBJ_DIFFUSION_ENEMY,//
					OBJ_ANGLE_BULLET,//拡散敵
					OBJ_HOMING_BULLET,//誘導弾丸敵
					OBJ_END,//エンド
					OBJ_FIN,//クリア
					OBJ_MANU,//メニュー
					OBJ_HEROINE,//ヒロイン
					OBJ_GUN,//武器銃
					OBJ_ASS_BULLET,//アサルトライフルの弾丸
					OBJ_MAP,//各マップの全体図

					//-----------モブキャラクター-------------------
					OBJ_CHINA_MOB,//チャイナタウンのモブ
					OBJ_HOS_MOB,//病院のモブ
					OBJ_INST_MOB,//研究所のモブ
					OBJ_DRUG_MOB,//製薬会社のモブ
					OBJ_SP_BACK,//会話の背景
					//-------------------------------------------------

					//------マップ-------------------------------------------
					//------チャイナタウン----------------------------------
					OBJ_BLOCK,//拠点
					OBJ_CHINA_TOWN_BOSS,//チャイナタウンのボス戦フィールド
					OBJ_CHINA_TOWN,//チャイナタウン
					OBJ_CHINA_TOWN_B,//チャイナタウンb
					OBJ_CHINA_TOWN_C,//チャイナタウンc
					OBJ_CHINA_TOWN_D,//チャイナタウンd
					OBJ_CHINA_TOWN_BOSS_BOSS,//チャイナタウンのボス戦フィールドBOSS
					OBJ_CHINA_EVENT,//チャイナタウンのEvent
					OBJ_CHINA_ATK_ENEMY,//チャイナタウン雑魚
					//---------------------------------------------------------

					//-------------研究所----------------------
					OBJ_INSTITUTE_BOSS,//研究所ボス
					OBJ_INSTITUTE_BOSS_BOSS,//研究所ボスボス
					OBJ_INSTITUTE,//研究所
					OBJ_INSTITUTE1,//研究所部屋１
					OBJ_INSTITUTE2,//研究所部屋2
					OBJ_INSTITUTE3,//研究所部屋３
					OBJ_INSTITUTE4,//研究部屋４
					OBJ_INSTITUTE5,//研究部屋5
					OBJ_INSTITUTE6,//研究部屋6
					OBJ_INSTITUTE7,//研究部屋7
					OBJ_INSTITUTE8,//研究部屋8
					OBJ_INSTITUTE9,//研究部屋9
					OBJ_INSTITUTE10,//研究部屋10
					OBJ_INSTITUTE11,//研究部屋11
					OBJ_INSTITUTE12,//研究部屋12
					OBJ_INSTITUTE13A,//研究廊下13
					OBJ_INSTITUTE14,//研究廊下14
					//----------------------------------------------


					//--------------病院---------------------
					OBJ_ROOF_TOP,//病院屋上
					OBJ_ROOF_TOP_BOSS,//病院の屋上BOSS
					OBJ_HOSPITAL,//病院1階
					OBJ_HOSPITAL2,//病院2階
					OBJ_HOSPITAL3,//病院3階
					OBJ_TEMPLATE_ROOM,//病院の部屋
					OBJ_EVENT_ROOM,//病院のイベント部屋
					OBJ_OPE_ROOM,//病院の手術室
					OBJ_EX_ROOM,//病院の診察室
					OBJ_XRAY_ROOM,//病院のレントゲン室

					//----------------------------------------

					//------------製薬会社---------------------

					OBJ_DRUG_CAMPANY,//製薬会社
					OBJ_DRUG_CAMPANY2,//製薬会社2階
					OBJ_DRUG_CAMPANY3,//製薬会社3階
					OBJ_DRUG_CAMPANY_ROOM1,//製薬会社部屋1
					OBJ_DRUG_CAMPANY_ROOM2,//製薬会社部屋2
					OBJ_DRUG_CAMPANY_ROOM3,//製薬会社部屋3
					OBJ_DRUG_CAMPANY_ROOM4,//製薬会社部屋4
					OBJ_DRUG_CAMPANY_ROOM5,//製薬会社部屋5
					OBJ_DRUG_CAMPANY_ROOM6,//製薬会社部屋６
					OBJ_DRUG_CAMPANY_ROOM7,//製薬会社部屋7
					OBJ_DRUG_CAMPANY_ROOM8,//製薬会社部屋8
					OBJ_DRUG_CAMPANY_ROOM9,//製薬会社部屋9

					//-------------------------------------
};
//------------------------------------------------

//当たり判定属性----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//属性無し 全ての属性と当たり判定が実行される
	//以下　同じ属性同士では当たり判定は実行されない
	//属性は追加可能だが、デバック時の色は初期設定分しか無い
	ELEMENT_PLAYER,
	ELEMENT_ENEMY,
	ELEMENT_ITEM,
	ELEMENT_MAGIC,
	ELEMENT_FIELD,
	ELEMENT_RED,
	ELEMENT_GREEN,
	ELEMENT_BLUE,
	ELEMENT_BLACK,
	ELEMENT_WHITE,
};
//------------------------------------------------

//------------------------------------------------
//セーブ＆ロードとシーン間のやり取りするデータ
struct UserData
{
	int mSeveData;	//サンプルセーブデータ
	int mStage;   //進行度合い
	int mBullet;   //弾丸数
};
//------------------------------------------------


//ゲーム内で使用されるグローバル変数・定数・列挙--



//------------------------------------------------
//ゲーム内で使用するクラスヘッダ------------------


//------------------------------------------------

//ゲームシーンオブジェクトヘッダ------------------
#include"ObjMain.h"
#include"ObjHero.h"
#include"ObjTitle.h"
#include"ObjEnemy.h"
#include"CObjBullet.h"
#include"ObjGameOver.h"
#include"ObjTitleBackground.h"
#include"ObjAttackEnemy.h"
#include"CObjBulletEnemy.h"
#include"CObjHomingEnemy.h"
#include"CObjSinEnemy.h"
#include"ObjDiffusionEnemy.h"
#include"CObjAngleBullet.h"
#include"CObjHomingBullet.h"
#include"ObjBlock.h"
#include"ObjEnd.h"
#include"ObjFin.h"
#include"ObjMenu.h"
#include"ObjRooftop.h"
#include"ObjInstituteBoss.h"
#include"ObjHeroine.h"
#include"ObjChinaTown.h"
#include"CObjRooftopBoss.h"
#include"ObjGun.h"
#include"CObjAssBullet.h"
#include"ObjDrugCampany.h"
#include"ObjDrugCampany2.h"
#include"ObjDrugCampany3.h"
#include"ObjDrugCampanyRoom1.h"
#include"ObjDrugCampanyRoom2.h"
#include"ObjDrugCampanyRoom3.h"
#include"ObjDrugCampanyRoom4.h"
#include"ObjDrugCampanyRoom5.h"
#include"ObjDrugCampanyRoom6.h"
#include"ObjDrugCampanyRoom7.h"
#include"ObjDrugCampanyRoom8.h"
#include"ObjDrugCampanyRoom9.h"
#include"ObjHospital.h"
#include"ObjHospital2.h"
#include"ObjHospital3.h"
#include"ObjTemplateRoom.h"
#include"ObjChinaTownBoss.h"
#include"ObjInstitute.h"
#include"ObjEventRoom.h"
#include"ObjOpeRoom.h"
#include"ObjExRoom.h"
#include"ObjXRayRoom.h"
#include"ObjInstitute1.h"
#include"ObjInstitute2.h"
#include"ObjInstitute3.h"  
#include"CObjChinaTownBossBoss.h"
#include"CObjChinaAtkEnemy.h"

#include"ObjInstitute4.h"
#include"ObjInstitute5.h"
#include"ObjInstitute6.h"
#include"ObjInstitute7.h"
#include"ObjInstitute8.h"
#include"ObjInstitute9.h"
#include"ObjInstitute10.h"
#include"ObjInstitute11.h"
#include"ObjInstitute12.h"
#include"ObjInstitute13A.h"
#include"ObjInstitute14.h"


#include"CObjInstituteBossBoss.h"
#include"ObjMap.h"
#include"ObjChinaTown_b.h"
#include"ObjChinaTown_c.h"
#include"ObjChinaTown_d.h"
#include"ObjChinaEvent.h"

#include"ObjChinaMob.h"
#include"ObjHosMob.h"
#include"ObjInstMob.h"
#include"ObjDrugMob.h"
#include"ObjSpBack.h"

//------------------------------------------------

//ゲームシーンクラスヘッダ------------------------
#include"SceneTitle.h"
#include"SceneMain.h"
#include"SceneGameOver.h"
#include"SceneEnd.h"
#include"SceneFin.h"
#include"SceneBlock.h"
#include"SceneRooftop.h"
#include"SceneInstituteBoss.h"
#include"SceneChinaTown.h"
#include"SceneDrugCampany.h"
#include"SceneDrugCampany2.h"
#include"SceneDrugCampany3.h"
#include"SceneDrugCampanyRoom1.h"
#include"SceneDrugCampanyRoom2.h"
#include"SceneDrugCampanyRoom3.h"
#include"SceneDrugCampanyRoom4.h"
#include"SceneDrugCampanyRoom5.h"
#include"SceneDrugCampanyRoom6.h"
#include"SceneDrugCampanyRoom7.h"
#include"SceneDrugCampanyRoom8.h"
#include"SceneDrugCampanyRoom9.h"
#include"SceneHospital.h"
#include"SceneHospital2.h"
#include"SceneHospital3.h"
#include"SceneTemplateRoom.h"
#include"SceneInstitute.h"
#include"SceneChinaTownBoss.h"
#include"SceneEventRoom.h"
#include"SceneOpeRoom.h"
#include"SceneExRoom.h"
#include"SceneXRayRoom.h"
#include"SceneInstitute1.h"
#include"SceneInstitute2.h"
#include"SceneInstitute3.h"
#include"SceneInstitute4.h"
#include"SceneInstitute5.h"
#include"SceneInstitute6.h"
#include"SceneInstitute7.h"
#include"SceneInstitute8.h"
#include"SceneInstitute9.h"
#include"SceneInstitute10.h"
#include"SceneInstitute11.h"
#include"SceneInstitute12.h"
#include"SceneInstitute13A.h"
#include"SceneInstitute14.h"
#include"SceneChinaTown_b.h"
#include"SceneChinaTown_c.h"
#include"SceneChinaTown_d.h"
#include"SceneChinaEvent.h"

//-----------------------------------------------

//シーンスタートクラス---------------------------
////ゲーム開始時のシーンクラス登録
//#define SET_GAME_START CSceneGameOver
#define SET_GAME_START CSceneTitle
//#define SET_GAME_START CSceneRooftop
//#define SET_GAME_START CSceneEnd 
//#define SET_GAME_START CSceneFin
//#define SET_GAME_START CSceneMain
//#define SET_GAME_START CSceneStage
//#define SET_GAME_START CSceneHospital2
//#define SET_GAME_START CSceneInstitute13
//#define SET_GAME_START CSceneDrugCampany3


//-----------------------------------------------