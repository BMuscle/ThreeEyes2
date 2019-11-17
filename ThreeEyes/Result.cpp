#include"DxLib.h"
#include"Result.h"
#include"SceneMgr.h"
#include "Sprite.h"
#include "MyWindow.h"

static Sprite backSprite;
int coutinueBox_x1, coutinueBox_x2, coutinueBox_y1, coutinueBox_y2;	//coutinueボックス座標
int endBox_x1, endBox_x2, endBox_y1, endBox_y2;						//endボックス座標
int string_y1, string_y2;
int nextSelect = 0;		//次の画面をどうするかの数値を持つ

int resultImg;					//画像ハンドル値
int colorBox1, colorBox2;		//マウスオン時にボックスの色を変更する
int resultMousex, resultMousey;	//マウス座標を入れる変数
int resultMouseInput;			//マウスの入力状態
int coutinue_fclor, end_fcolor;	//ボックス内の文字色

void Result_Initialize(int winlose) {	//winloseが1なら勝ち、2なら負け、3なら引き分け
	backSprite = initSprite("images/1blackboard.png", 640, 480);
	if (winlose == 1) {
		//勝ちの時の処理
		resultImg = LoadGraph("images/win.png");
		winlose = 0;
	}
	else if (winlose == 2) {
		//負けの時の処理
		resultImg = LoadGraph("images/lose.png");
		winlose = 0;
	}
	else {
		//引き分けの処理
		resultImg = LoadGraph("images/draw.png");
		winlose = 0;
	}


	//縁の色設定
	colorBox1 = GetColor(0, 255, 0);
	colorBox2 = GetColor(0, 0, 0);

	//文字色設定
	coutinue_fclor = GetColor(0, 0, 0);
	end_fcolor = GetColor(0, 0, 0);

	nextSelect = SCENE_NONE;
}

void Result_Finalize() {
	DeleteGraph(resultImg);
	nextSelect = 0;
	resultMouseInput = 0;
}

void Result_Update() {
	GetMousePoint(&resultMousex, &resultMousey);
	Result_Select();
	resultMouseInput = GetMouseInput();
	if (CheckHitKey(KEY_INPUT_RETURN) == 1) {
		if (nextSelect == SCENE_GAME) {
			//ゲーム画面へ
			Result_Finalize();
			SceneMgr_ChangeScene(SCENE_GAME);
		}
		else if (nextSelect == SCENE_TITLE) {
			//タイトル画面へ
			Result_Finalize();
			SceneMgr_ChangeScene(SCENE_TITLE);
		}
	}
}

void Result_Select()
{
	if (CheckHitKey(KEY_INPUT_RIGHT)) {
		coutinue_fclor = GetColor(0, 0, 0);
		end_fcolor = GetColor(255, 0, 0);
		nextSelect = SCENE_TITLE;
	}
	if (CheckHitKey(KEY_INPUT_LEFT)) {
		coutinue_fclor = GetColor(255, 0, 0);
		end_fcolor = GetColor(0, 0, 0);
		nextSelect = SCENE_GAME;
	}
}

void Result_Draw() {
	drawAtSprite(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, &backSprite, TRUE);
	DrawGraph(200, 50, resultImg, FALSE);
	DrawBox(90, 370, 190, 410, colorBox1, FALSE);
	DrawBox(390, 370, 490, 410, colorBox2, FALSE);
	DrawFormatString(115, 380, coutinue_fclor, "続ける");
	DrawFormatString(415, 380, end_fcolor, "やめる");
	Result_EndMouseSelect();
}

void Result_EndMouseSelect()
{
	//左のボックス
	if (resultMousex >= 90 && resultMousex <= 190 && resultMousey >= 370 && resultMousey <= 410) {
		//色を変える処理
		colorBox1 = GetColor(0, 255, 0);
		if ((resultMouseInput & MOUSE_INPUT_LEFT) != 0) {
			Result_Finalize();
			SceneMgr_ChangeScene(SCENE_GAME);
		}
	}
	else {
		colorBox1 = GetColor(0, 0, 0);

	}

	//右のボックス
	if (resultMousex >= 390 && resultMousex <= 490 && resultMousey >= 370 && resultMousey <= 410) {
		//色を変える処理
		colorBox2 = GetColor(0, 255, 0);
		if ((resultMouseInput & MOUSE_INPUT_LEFT) != 0) {
			Result_Finalize();
			SceneMgr_ChangeScene(SCENE_TITLE);
		}
	}
	else {
		colorBox2 = GetColor(0, 0, 0);
	}
}