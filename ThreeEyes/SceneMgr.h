#pragma once

//UpdateとDrawの一括管理の関数

typedef enum {				//列挙型、各シーンに番号を付ける
	SCENE_TITLE,		// 0
	SCENE_DIFFICULTY,	// 1
	SCENE_GAME,			// 2
	SCENE_RESULT,		// 3
	SCENE_NONE,
}scene;

void SceneMgr_Initialize();			//初期化処理
void SceneMgr_Finalize();			//終了処理
void SceneMgr_Update();				//更新処理
void SceneMgr_Draw();				//描画処理
void SceneMgr_ChangeScene(scene nextscene);