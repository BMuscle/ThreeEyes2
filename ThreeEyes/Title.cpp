#include"DxLib.h"
#include"Title.h"
#include"SceneMgr.h"
#include"MyMouse.h"
#include"MassageBox.h"
#include "LoadEffect.h"

static Sprite backSprite;
static int Title;					//タイトル用のハンドル
static int SEnter, SSelect;		//音用ハンドル
static int Mousex, Mousey;			//マウスのx,y座標
static int Font00;					//フォント指定用のハンドル
static int startSelect, endSelect;		//SE管理用の変数

static MassageBox startGame;
static MassageBox endGame;

void Title_Initialize() {
	Font00 = CreateFontToHandle("ゴシック", 15, 6, DX_FONTTYPE_ANTIALIASING);
	backSprite = initSprite("images/1blackboard.png", 640, 480);
	Title = LoadGraph("images/title.png");
	SEnter = LoadSoundMem("musics/enter1.wav");
	SSelect = LoadSoundMem("musics/select1.wav");

	startGame = initMassageBox("images/enpitu.png", "ゲーム開始", GetColor(0, 0, 0), Font00, 180, 370, 170, 60);
	endGame = initMassageBox("images/enpitu.png", "終了", GetColor(0, 0, 0), Font00, 480, 370, 170, 60);
	startSelect = 0;
	endSelect = 0;
	startGame.mystr.alpha = 255 * 0.5;
	endGame.mystr.alpha = 255 * 0.5;
}

void Title_Finalize() {
	DeleteGraph(Title);
}

void Title_Update() {
	if (getCurrentLoadState() > 0) {
		if (isLoadEnd()) {
			Title_Finalize();
			SceneMgr_ChangeScene(SCENE_GAME);
		}
		return;
	}
	GetMousePoint(&Mousex, &Mousey);
	Title_StartMouseSelect();
	Title_EndMouseSelect();
}

void Title_Draw() {
	drawAtSprite(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, &backSprite, TRUE);
	DrawGraph(50, 50, Title, FALSE);		
	drawAtMassageBox(&startGame,TRUE);
	drawAtMassageBox(&endGame, TRUE);
	
}


void Title_StartMouseSelect() {				
	if (Mousex >= startGame.mystr.x-startGame.sprite.width / 2 + 10&& Mousex <= startGame.mystr.x + startGame.sprite.width / 2 - 30
		&& Mousey >= startGame.mystr.y - startGame.sprite.height / 2 + 10 && Mousey <= startGame.mystr.y + startGame.sprite.height / 2 - 10) {
		startGame.mystr.color = 0xff0000;
		if (startSelect == 0) {			//SE管理用のIF文
			PlaySoundMem(SSelect, DX_PLAYTYPE_BACK);
			startSelect = 1;
		}
		if ( getLeftDown() != 0) {
			PlaySoundMem(SEnter, DX_PLAYTYPE_BACK);
			onLoadFlag();
		}
	}
	else {
		startGame.mystr.color = 0x000000;
		startSelect = 0;
	}
	
}

void Title_EndMouseSelect() {
	if (Mousex >= endGame.mystr.x - endGame.sprite.width / 2 + 10 && Mousex <= endGame.mystr.x + endGame.sprite.width / 2 - 30
		&& Mousey >= endGame.mystr.y - endGame.sprite.height / 2 + 10 && Mousey <= endGame.mystr.y + endGame.sprite.height / 2 - 10) {
		endGame.mystr.color = 0xff0000;
		if (endSelect == 0) {
			PlaySoundMem(SSelect, DX_PLAYTYPE_BACK);
			endSelect = 1;
		}
		if (getLeftDown() != 0) {
			PlaySoundMem(SEnter, DX_PLAYTYPE_BACK);
			/*ここに終了処理を描く*/

		}
	}
	else {
		endGame.mystr.color = 0x000000;
		endSelect = 0;
	}
}