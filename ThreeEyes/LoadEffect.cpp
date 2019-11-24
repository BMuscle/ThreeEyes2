#include "LoadEffect.h"

#define ROD_HEIGHT 100//緑の画像高さ
#define ROD_SIZE 4	//消す本数


enum LOAD_STATE {//現在のロード状態
	NONE = 0,//ロードしていない
	WRITE = 1,//表示フェーズ
	MOVE = 2,//移行フェーズ
	ERASE = 3,//消去フェーズ
	BLACKERASE = 4,//黒板消しで消すフェーズ
};

void eraseUpdate();
void eraseDraw();
void flushUpdate();
void flushDraw();
void empty() {};

static void(*funcUpdate)();		//Updateの関数ポインタ

static LOAD_STATE currentLoadState;
//LOAD_ERASE用
static int eraseBackImg;
static Sprite greenRod;
static Sprite greenRodErase;
static int currentRod; //現在動かしている棒
static int currentX;
static int rodSpeed;
//LOAD_FLUSH用
static int alpha;
static int seErase;//効果音　黒板消すとき

void initLoadEffect(void) {
	seErase = LoadSoundMem("musics/erase.wav");
	ChangeVolumeSoundMem(140, seErase);
	funcUpdate = empty;
	currentRod = 0;
	currentX = -WINDOW_WIDTH*2;
	rodSpeed = 30;
	eraseBackImg = LoadGraph("images/loadeffect/back3.png");
	greenRod = initSprite("images/loadeffect/green.png", WINDOW_WIDTH , ROD_HEIGHT);
	greenRodErase = initSprite("images/loadeffect/green1.png", WINDOW_WIDTH * 2, ROD_HEIGHT);
	currentLoadState = NONE;

	alpha = 0;	
}
void deleteLoadEffect(void) {
	DeleteGraph(eraseBackImg);
	deleteSprite(&greenRod);
	deleteSprite(&greenRodErase);
}

void onLoadFlag(LOAD_TYPE type) {
	currentRod = 0;
	alpha = 0;
	switch (type) {
	case LOAD_ERASE:
		PlaySoundMem(seErase, DX_PLAYTYPE_BACK);
		currentLoadState = BLACKERASE;
		funcUpdate = eraseUpdate;
		currentX = -WINDOW_WIDTH * 2;

		break;
	case LOAD_FLUSH:
		currentLoadState = ERASE;
		funcUpdate = flushUpdate;
		break;
	}

}
int getCurrentLoadState() {
	return currentLoadState;
}

BOOL isLoadEnd() {
	if (currentLoadState == MOVE) {
		currentLoadState = WRITE;
		return TRUE;
	}
	return FALSE;
}
BOOL isStart() {
	if (currentLoadState == NONE) {
		return TRUE;
	}
	return FALSE;
}

void LoadEffect_Update(void) {
	(*funcUpdate)();
}
void boardEraseDraw(void) {
	if (currentLoadState == NONE) { return; }

	if (currentLoadState == BLACKERASE) {
		for (int i = 0; i < currentRod; i++) {
			drawSprite(0, i * ROD_HEIGHT, &greenRod, TRUE);
		}
		drawSprite(currentX, currentRod * ROD_HEIGHT, &greenRodErase, TRUE);
		DrawGraph(0, 0, eraseBackImg, TRUE);
	}
	else {
		if (currentLoadState == ERASE) {
			for (int i = 0; i < currentRod; i++) {
				drawSprite(0, i * ROD_HEIGHT, &greenRod, TRUE);
			}
		}
	}
}


void eraseUpdate() {
	if (currentLoadState == NONE) { return; }
	if (currentLoadState == BLACKERASE) {
		currentX += rodSpeed;
		if (currentX >= 0) {
			currentX = -WINDOW_WIDTH * 2;
			currentRod++;
			if (currentRod > ROD_SIZE - 1) {
				currentLoadState = ERASE;
				currentX = -WINDOW_WIDTH;
				return;
			}
			else {
				PlaySoundMem(seErase, DX_PLAYTYPE_BACK);
			}

		}
	}
	else if (currentLoadState == ERASE) {
		alpha += 5;
		if (alpha >= 255) {
			alpha = 255;
			currentLoadState = MOVE;
		}
	}
	else {
		alpha -= 5;
		if (alpha <= 0) {
			alpha = 0;
			currentLoadState = NONE;
		}
	}
	return;
}
void eraseDraw() {

}
void flushUpdate() {
	if (currentLoadState == NONE) { return; }

	if (currentLoadState == ERASE) {
		alpha += 5;
		if (alpha >= 255) {
			alpha = 255;
			currentLoadState = MOVE;
		}
	}
	else {
		alpha -= 5;
		if (alpha <= 0) {
			alpha = 0;
			currentLoadState = NONE;
		}
	}
}
void flushDraw() {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	DrawBox(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, 0x000000, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
