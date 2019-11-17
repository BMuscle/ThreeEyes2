#include "LoadEffect.h"

#define ROD_HEIGHT 100//緑の画像高さ
#define ROD_SIZE 4	//消す本数


enum LOAD_STATE {//現在のロード状態
	NONE = 0,//ロードしていない
	WRITE = 1,//表示フェーズ
	MOVE = 2,//移行フェーズ
	ERASE = 3,//消去フェーズ
};

int backImg;
LOAD_STATE loadflag;

Sprite greenRod;
Sprite greenRod1;
Sprite greenRod2;
int currentRod; //現在動かしている棒
int currentX;
int rodSpeed;

void initLoadEffect(void) {
	currentRod = 0;
	currentX = -WINDOW_WIDTH*2;
	rodSpeed = 30;
	backImg = LoadGraph("images/loadeffect/back.png");
	greenRod = initSprite("images/loadeffect/green.png", WINDOW_WIDTH , ROD_HEIGHT);
	greenRod1 = initSprite("images/loadeffect/green1.png", WINDOW_WIDTH * 2, ROD_HEIGHT);
	greenRod2 = initSprite("images/loadeffect/green3.png", WINDOW_WIDTH * 2, ROD_HEIGHT);
	loadflag = NONE;
	
}
void deleteLoadEffect(void) {
	DeleteGraph(backImg);
	//deleteSprite(greenRod);
}

void onLoadFlag() {
	loadflag = ERASE;
	currentX = -WINDOW_WIDTH*2;
	currentRod = 0;
}
BOOL getLoadFlag() {
	return loadflag;
}

BOOL isLoadEnd() {
	if (loadflag == MOVE) {
		loadflag = WRITE;
		return TRUE;
	}
	return FALSE;
}
BOOL isStart() {
	if (loadflag == NONE) {
		return TRUE;
	}
	return FALSE;
}

BOOL LoadEffect_Update(void) {
	if (loadflag == NONE) { return loadflag; }
	if (loadflag == ERASE) {
		currentX += rodSpeed;
		if (currentX >= 0) {
			currentX = -WINDOW_WIDTH * 2;
			currentRod++;
			if (currentRod > ROD_SIZE - 1) {
				loadflag = MOVE;
				currentX = -WINDOW_WIDTH;
				currentRod = 0;
				return loadflag;
			}
		}
	}
	else if(loadflag == WRITE){
		currentX += rodSpeed;
		if (currentX >= WINDOW_WIDTH) {
			currentX = -WINDOW_WIDTH;
			currentRod++;
			if (currentRod > ROD_SIZE - 1) {
				loadflag = NONE;
				return loadflag;
			}
		}
	}
	return loadflag;
}
void LoadEffect_Draw(void) {
	if (loadflag == NONE) { return;}

	if (loadflag == ERASE) {
		for (int i = 0; i < currentRod; i++) {
			drawSprite(0, i * ROD_HEIGHT, &greenRod, TRUE);
		}
		drawSprite(currentX, currentRod * ROD_HEIGHT, &greenRod1, TRUE);
		DrawGraph(0, 0, backImg, TRUE);
	}
	else {
		for (int i = currentRod + 1; i <= ROD_SIZE; i++) {
			drawSprite(0, i * ROD_HEIGHT, &greenRod, TRUE);
		}
		drawSprite(currentX, currentRod * ROD_HEIGHT, &greenRod2, TRUE);
		DrawGraph(0, 0, backImg, TRUE);
	}
}