#include"DxLib.h"
#include"Title.h"
#include"Game.h"
#include"Result.h"
#include"SceneMgr.h"
#include"stdio.h"

static void(*funcUpdate)();		//Updateの関数ポインタ
static void(*funcDraw)();		//Drawの関数ポインタ
static scene nowscene;			//今のシーン変数
static scene nextscene;			//次のシーン変数

void SceneMgr_Initialize() {
	Title_Initialize();
	nowscene = SCENE_NONE;
	nextscene = SCENE_TITLE;
	funcUpdate = Title_Update;
	funcDraw = Title_Draw;
}

void SceneMgr_Finalize() {

}

void SceneMgr_Update() {			//Updateの箱
	(*funcUpdate)();

}

void SceneMgr_Draw() {				//Drawの箱
	(*funcDraw)();
}

void SceneMgr_ChangeScene(scene nextscene) {
	if (nowscene != nextscene) {
		nowscene = nextscene;
	}
	switch(nowscene) {
		case SCENE_TITLE:
			Title_Initialize();
			funcUpdate = Title_Update;
			funcDraw = Title_Draw;
			break;
		case SCENE_GAME:

			funcUpdate = Game_Update;
			funcDraw = Game_Draw;
			break;
		case SCENE_RESULT:
			funcUpdate = Result_Update;
			funcDraw = Result_Draw;
			break;
	}
}