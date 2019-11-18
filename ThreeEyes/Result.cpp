#include"DxLib.h"
#include"Result.h"
#include"SceneMgr.h"
#include "Sprite.h"
#include "MyWindow.h"
#include "MyMouse.h"
#include "MassageBox.h"

static Sprite backSprite;
int nextSelect = 0;		//次の画面をどうするかの数値を持つ

static int resultImg;					//画像ハンドル値
static int resultMousex, resultMousey;	//マウス座標を入れる変数

static int fontResult;		//フォント用ハンドル

static MassageBox startGame;
static MassageBox endGame;



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

	fontResult = CreateFontToHandle("ゴシック", 15, 6, DX_FONTTYPE_ANTIALIASING);
	startGame = initMassageBox("images/enpitu.png", "続ける", GetColor(0, 0, 0), fontResult, 180, 370, 170, 60);
	endGame = initMassageBox("images/enpitu.png", "終了", GetColor(0, 0, 0), fontResult, 480, 370, 170, 60);



	nextSelect = SCENE_NONE;
	startGame.mystr.alpha = 255 * 0.5;
	endGame.mystr.alpha = 255 * 0.5;
}

void Result_Finalize() {
	DeleteGraph(resultImg);
	nextSelect = 0;
}

void Result_Update() {
	GetMousePoint(&resultMousex, &resultMousey);
}


void Result_Draw() {
	drawAtSprite(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, &backSprite, TRUE);
	DrawGraph(200, 50, resultImg, FALSE);
	drawAtMassageBox(&startGame, TRUE);
	drawAtMassageBox(&endGame, TRUE);
	Result_EndMouseSelect();
}

void Result_StartMouseSelect()
{
	//左のボックス
	if (resultMousex >= 90 && resultMousex <= 190 && resultMousey >= 370 && resultMousey <= 410) {
		
	}
	else {


	}
}

void Result_EndMouseSelect()
{
	//右のボックス
	if (resultMousex >= 390 && resultMousex <= 490 && resultMousey >= 370 && resultMousey <= 410) {
		
	}
	else {

	}
}