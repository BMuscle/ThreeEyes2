#include"DxLib.h"
#include"Game.h"
#include"SceneMgr.h"
#include"Result.h"

void Game_Initialize() {

}

void Game_Finalize() {

}

void Game_Update() {
	if (CheckHitKey(KEY_INPUT_R) == 1) {
		SceneMgr_ChangeScene(SCENE_RESULT);
		Result_Initialize(getGameResult());
	}
}

void Game_Draw() {
	DrawFormatString(50, 50, GetColor(0, 0, 0), "ÉQÅ[ÉÄâÊñ Ç≈Ç∑");
}

int getGameResult() {
	int gameresult = 3;
	return gameresult;
}