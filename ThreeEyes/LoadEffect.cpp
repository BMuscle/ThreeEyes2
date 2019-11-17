#include "LoadEffect.h"

#define ROD_HEIGHT 100
#define ROD_SIZE ((WINDOW_HEIGHT + (ROD_HEIGHT + 1)) / ROD_HEIGHT) 


enum LOAD_STATE {//現在のロード状態
	NONE = 0,//ロードしていない
	WRITE = 1,//表示フェーズ
	MOVE = 2,//移行フェーズ
	ERASE = 3,//消去フェーズ
};

int backImg;
LOAD_STATE loadflag;

Sprite greenRod;
Sprite greenRod2;
int currentRod; //現在動かしている棒
int currentX;
int rodSpeed;

void initLoadEffect(void) {
	currentRod = 0;
	currentX = -WINDOW_WIDTH*2;
	rodSpeed = 50;
	backImg = LoadGraph("images/loadeffect/back.png");
	greenRod = initSprite("images/loadeffect/green.png", WINDOW_WIDTH , ROD_HEIGHT);
	greenRod2 = initSprite("images/loadeffect/green1.png", WINDOW_WIDTH * 2, ROD_HEIGHT);
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
				return loadflag;
			}
		}
	}
	else if(loadflag == WRITE){
		currentX -= rodSpeed;
		if (currentX <= -WINDOW_WIDTH) {
			currentX = 0;
			currentRod--;
			if (currentRod < 0) {
				loadflag = NONE;
				return loadflag;
			}
		}
	}
	return loadflag;
}
void LoadEffect_Draw(void) {
	if (loadflag == NONE) { return;}
	for (int i = 0; i < currentRod; i++) {
		drawSprite(0, i * ROD_HEIGHT, &greenRod, TRUE);
	}
	if (loadflag == ERASE) {
		drawSprite(currentX, currentRod * ROD_HEIGHT, &greenRod2, TRUE);
		DrawGraph(0, 0, backImg, TRUE);
	}
	else {
		drawSprite(currentX, currentRod * ROD_HEIGHT, &greenRod2, TRUE);
		DrawGraph(0, 0, backImg, TRUE);
	}
}