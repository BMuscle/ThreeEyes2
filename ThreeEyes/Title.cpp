#include"DxLib.h"
#include"Title.h"
#include"SceneMgr.h"
#include"MyMouse.h"
#include"MassageBox.h"
#include "LoadEffect.h"

int Title;					//タイトル用のハンドル
int SEnter, SSelect;		//音用ハンドル
int Mousex, Mousey;			//マウスのx,y座標
int Font00;					//フォント指定用のハンドル
static Sprite backSprite;
MassageBox startGame;
MassageBox endGame;

void Title_Initialize() {
	Font00 = CreateFontToHandle("ゴシック", 15, 6, DX_FONTTYPE_ANTIALIASING);
	backSprite = initSprite("images/1blackboard.png", 640, 480);
	Title = LoadGraph("images/title.png");
	SEnter = LoadSoundMem("music/enter1.wav");
	SSelect = LoadSoundMem("music/select1.wav");
	startGame = initMassageBox("images/enpitu.png", "ゲーム開始", GetColor(0, 0, 0), Font00, 180, 370, 170, 60);
	endGame = initMassageBox("images/enpitu.png", "終了", GetColor(0, 0, 0), Font00, 480, 370, 170, 60);
	startGame.mystr.alpha = 255 * 0.5;
	endGame.mystr.alpha = 255 * 0.5;
}

void Title_Finalize() {
	DeleteGraph(Title);
}

void Title_Update() {
	if (getLoadFlag() > 0) {
		if (isLoadEnd()) {
			PlaySoundMem(SEnter, DX_PLAYTYPE_BACK);
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
	DrawGraph(50, 50, Title, FALSE);		//画像貼り付け
	drawAtMassageBox(&startGame,TRUE);
	drawAtMassageBox(&endGame, TRUE);
	
}


void Title_StartMouseSelect() {				//ゲーム開始の方の枠の色変える関数、黒→緑
	if (Mousex >= startGame.mystr.x-startGame.sprite.width / 2 + 10&& Mousex <= startGame.mystr.x + startGame.sprite.width / 2 - 30
		&& Mousey >= startGame.mystr.y - startGame.sprite.height / 2 + 10 && Mousey <= startGame.mystr.y + startGame.sprite.height / 2 - 10) {//ゲーム開始の枠の色変更
		startGame.mystr.color = 0xff0000;
		if ( getLeftDown() != 0) {
			onLoadFlag();
		}
	}
	else {
		startGame.mystr.color = 0x000000;
	}
	
}

void Title_EndMouseSelect() {
	if (Mousex >= endGame.mystr.x - endGame.sprite.width / 2 + 10 && Mousex <= endGame.mystr.x + endGame.sprite.width / 2 - 30
		&& Mousey >= endGame.mystr.y - endGame.sprite.height / 2 + 10 && Mousey <= endGame.mystr.y + endGame.sprite.height / 2 - 10) {//ゲーム開始の枠の色変更
		endGame.mystr.color = 0xff0000;
		if ( getLeftDown() != 0) {
			PlaySoundMem(SEnter, DX_PLAYTYPE_BACK);
			/*ここにゲーム終了処理を描く*/
			
		}
	}
	else {
		endGame.mystr.color = 0x000000;
	}

}

