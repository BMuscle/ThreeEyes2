#include"DxLib.h"
#include"Result.h"
#include"SceneMgr.h"
#include "Sprite.h"
#include "MyWindow.h"
#include "MyMouse.h"
#include "MassageBox.h"
#include"LoadEffect.h"

static Sprite backSprite;
int nextSelect = 0;		//次の画面をどうするかの数値を持つ

static int resultImg;					//画像ハンドル値
static int resultMousex, resultMousey;	//マウス座標を入れる変数
static int SEnter, SSelect;				//SE用のハンドル
static int startSelect, endSelect;		//SE管理用変数
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
	startSelect = 0;
	endSelect = 0;


	nextSelect = SCENE_NONE;
	startGame.mystr.alpha = 255 * 0.5;
	endGame.mystr.alpha = 255 * 0.5;
}

void Result_Finalize() {
	DeleteGraph(resultImg);					//画像の開放処理
	deleteMassageBox(&startGame);
	deleteMassageBox(&endGame);
	deleteSprite(&backSprite);
	nextSelect = 0;
}

void Result_Update() {
	if (getCurrentLoadState() > 0) {
		if (isLoadEnd()) {
			Result_Finalize();
			SceneMgr_ChangeScene(SCENE_TITLE);
		}
		return;
	}
	GetMousePoint(&resultMousex, &resultMousey);
	Result_EndMouseSelect();
	Result_StartMouseSelect();
	/*ここにシーンチェンジとエフェクトを入れる*/
}


void Result_Draw() {
	drawAtSprite(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, &backSprite, TRUE);
	DrawGraph(200, 50, resultImg, FALSE);
	drawAtMassageBox(&startGame, TRUE);
	drawAtMassageBox(&endGame, TRUE);
}

void Result_StartMouseSelect()			//マウスのカーソルを続けるに合わせると文字の色が変わる
{
	//左のボックス
	if (resultMousex >= startGame.mystr.x - startGame.sprite.width / 2 + 10 && resultMousex <= startGame.mystr.x + startGame.sprite.width / 2 - 30
		&& resultMousey >= startGame.mystr.y - startGame.sprite.height / 2 + 10 && resultMousey <= startGame.mystr.y + startGame.sprite.height / 2 - 10) {
		startGame.mystr.color = 0xff0000;
		if (startSelect == 0) {			//SE管理用のIF文
			PlaySoundMem(SSelect, DX_PLAYTYPE_BACK);
			startSelect = 1;
		}
		if (getLeftDown() != 0) {
			startGame.mystr.color = 0x00ff00;
			PlaySoundMem(SEnter, DX_PLAYTYPE_BACK);
			onLoadFlag(LOAD_FLUSH);
		}
	}
	else {
		startGame.mystr.color = 0x000000;
		startSelect = 0;
	}
}

void Result_EndMouseSelect()		//マウスのカーソルを終了に合わせると文字の色が変わる
{
	//右のボックス
	if (resultMousex >= endGame.mystr.x - endGame.sprite.width / 2 + 10 && resultMousex <= endGame.mystr.x + endGame.sprite.width / 2 - 30
		&& resultMousey >= endGame.mystr.y - endGame.sprite.height / 2 + 10 && resultMousey <= endGame.mystr.y + endGame.sprite.height / 2 - 10) {
		endGame.mystr.color = 0xff0000;
		if (endSelect == 0) {
			PlaySoundMem(SSelect, DX_PLAYTYPE_BACK);
			endSelect = 1;
		}
		if (getLeftDown() != 0) {
			endGame.mystr.color = 0x00ff00;
			PlaySoundMem(SEnter, DX_PLAYTYPE_BACK);
			/*ここに終了処理を描く*/

		}
	}
	else {
		endGame.mystr.color = 0x000000;
		endSelect = 0;
	}
	
}