#include"DxLib.h"
#include"Result.h"
#include"SceneMgr.h"


int resultImg; //画像ハンドル値
int coutinueBox_x1, coutinueBox_x2, coutinueBox_y1, coutinueBox_y2;	//coutinueボックス座標
int endBox_x1, endBox_x2, endBox_y1, endBox_y2;						//endボックス座標
int string_y1, string_y2;
int nextSelect = 0;		//次の画面をどうするかの数値を持つ

void Result_Initialize(int winlose) {	//winloseが1なら勝ち、2なら負け、3なら引き分け
	if (winlose == 1) {
		//勝ちの時の処理
		resultImg = LoadGraph("images/win.png");
		winlose = 0;
	}
	else if(winlose == 2){
		//負けの時の処理
		resultImg = LoadGraph("images/lose.png");
		winlose = 0;
	}
	else {
		//引き分けの処理
		resultImg = LoadGraph("images/draw.png");
		winlose = 0;
	}
	
	//coutinueボックス初期値
	coutinueBox_x1 = 100; coutinueBox_x2 = 210;
	coutinueBox_y1 = 350; coutinueBox_y2 = 390;

	//endボックス初期値
	endBox_x1 = 400; endBox_x2 = 510;
	endBox_y1 = 350; endBox_y2 = 390;

	//文字列座標初期値
	string_y1 = string_y2 = 360;
}

void Result_Finalize() {
	DeleteGraph(resultImg);
	nextSelect = 0;
}

void Result_Update() {
	Result_Select();
	if (CheckHitKey(KEY_INPUT_RETURN) == 1) {
		if (nextSelect == 1) {
			//ゲーム画面へ
			Result_Finalize();
			SceneMgr_ChangeScene(SCENE_GAME);
		}
		else if (nextSelect == 2) {
			//タイトル画面へ
			Result_Finalize();
			SceneMgr_ChangeScene(SCENE_TITLE);
		}
	}
}

void Result_Select()
{
	if (CheckHitKey(KEY_INPUT_RIGHT)) {
		coutinueBox_y1 = 350;
		coutinueBox_y2 = 390;
		endBox_y1 = 330;
		endBox_y2 = 370;
		string_y1 = 360;
		string_y2 = 340;
		nextSelect = 2;
	}
	if (CheckHitKey(KEY_INPUT_LEFT)) {
		coutinueBox_y1 = 330;
		coutinueBox_y2 = 370;
		endBox_y1 = 350;
		endBox_y2 = 390;
		string_y1 = 340;
		string_y2 = 360;
		nextSelect = 1;
	}
}

void Result_Draw() {
	DrawGraph(200, 50, resultImg, FALSE);
	DrawBox(coutinueBox_x1, coutinueBox_y1, coutinueBox_x2, coutinueBox_y2, GetColor(0, 0, 0), FALSE);
	DrawBox(endBox_x1, endBox_y1, endBox_x2, endBox_y2, GetColor(0, 0, 0), FALSE);
	DrawFormatString(130, string_y1, GetColor(0, 0, 0), "続ける");
	DrawFormatString(430, string_y2, GetColor(0, 0, 0), "やめる");
}