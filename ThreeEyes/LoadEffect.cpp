#include "LoadEffect.h"

#define ROD_HEIGHT 100//緑の画像高さ
#define ROD_SIZE 4	//消す本数


enum LOAD_STATE {//現在のロード状態
	NONE = 0,//ロードしていない
	WRITE = 1,//表示フェーズ
	MOVE = 2,//移行フェーズ
	ERASE = 3,//消去フェーズ
};

void eraseUpdate();
void eraseDraw();
void flushUpdate();
void flushDraw();
void empty() {};

static void(*funcUpdate)();		//Updateの関数ポインタ
static void(*funcDraw)();		//Drawの関数ポインタ

static LOAD_STATE currentLoadState;
//LOAD_ERASE用
static int eraseBackImg;
static Sprite greenRod;
static Sprite greenRodErase;
static Sprite greenRodWrite;
static int currentRod; //現在動かしている棒
static int currentX;
static int rodSpeed;
//LOAD_FLUSH用
static int alpha;

void initLoadEffect(void) {
	funcUpdate = empty;
	funcDraw = empty;

	currentRod = 0;
	currentX = -WINDOW_WIDTH*2;
	rodSpeed = 30;
	eraseBackImg = LoadGraph("images/loadeffect/back.png");
	greenRod = initSprite("images/loadeffect/green.png", WINDOW_WIDTH , ROD_HEIGHT);
	greenRodErase = initSprite("images/loadeffect/green1.png", WINDOW_WIDTH * 2, ROD_HEIGHT);
	greenRodWrite = initSprite("images/loadeffect/green3.png", WINDOW_WIDTH * 2, ROD_HEIGHT);
	currentLoadState = NONE;

	alpha = 0;	
}
void deleteLoadEffect(void) {
	DeleteGraph(eraseBackImg);
	//deleteSprite(greenRod);
}

void onLoadFlag(LOAD_TYPE type) {
	currentLoadState = ERASE;
	switch (type) {
	case LOAD_ERASE:
		funcUpdate = eraseUpdate;
		funcDraw = eraseDraw;
		currentX = -WINDOW_WIDTH * 2;
		currentRod = 0;
		break;
	case LOAD_FLUSH:
		funcUpdate = flushUpdate;
		funcDraw = flushDraw;
		alpha = 0;
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
void LoadEffect_Draw(void) {
	(*funcDraw)();
}


void eraseUpdate() {
	if (currentLoadState == NONE) { return; }
	if (currentLoadState == ERASE) {
		currentX += rodSpeed;
		if (currentX >= 0) {
			currentX = -WINDOW_WIDTH * 2;
			currentRod++;
			if (currentRod > ROD_SIZE - 1) {
				currentLoadState = MOVE;
				currentX = -WINDOW_WIDTH;
				currentRod = 0;
				return;
			}
		}
	}
	else if (currentLoadState == WRITE) {
		currentX += rodSpeed;
		if (currentX >= WINDOW_WIDTH) {
			currentX = -WINDOW_WIDTH;
			currentRod++;
			if (currentRod > ROD_SIZE - 1) {
				currentLoadState = NONE;
				return;
			}
		}
	}
	return;
}
void eraseDraw() {
	if (currentLoadState == NONE) { return; }

	if (currentLoadState == ERASE) {
		for (int i = 0; i < currentRod; i++) {
			drawSprite(0, i * ROD_HEIGHT, &greenRod, TRUE);
		}
		drawSprite(currentX, currentRod * ROD_HEIGHT, &greenRodErase, TRUE);
		DrawGraph(0, 0, eraseBackImg, TRUE);
	}
	else {
		for (int i = currentRod + 1; i <= ROD_SIZE; i++) {
			drawSprite(0, i * ROD_HEIGHT, &greenRod, TRUE);
		}
		drawSprite(currentX, currentRod * ROD_HEIGHT, &greenRodWrite, TRUE);
		DrawGraph(0, 0, eraseBackImg, TRUE);
	}
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
