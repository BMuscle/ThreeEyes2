#include "LoadEffect.h"

#define ROD_HEIGHT 100//�΂̉摜����
#define ROD_SIZE 4	//�����{��


enum LOAD_STATE {//���݂̃��[�h���
	NONE = 0,//���[�h���Ă��Ȃ�
	WRITE = 1,//�\���t�F�[�Y
	MOVE = 2,//�ڍs�t�F�[�Y
	ERASE = 3,//�����t�F�[�Y
};

static int backImg;
static LOAD_STATE currentLoadState;

static Sprite greenRod;
static Sprite greenRodErase;
static Sprite greenRodWrite;
static int currentRod; //���ݓ������Ă���_
static int currentX;
static int rodSpeed;

void initLoadEffect(void) {
	currentRod = 0;
	currentX = -WINDOW_WIDTH*2;
	rodSpeed = 30;
	backImg = LoadGraph("images/loadeffect/back.png");
	greenRod = initSprite("images/loadeffect/green.png", WINDOW_WIDTH , ROD_HEIGHT);
	greenRodErase = initSprite("images/loadeffect/green1.png", WINDOW_WIDTH * 2, ROD_HEIGHT);
	greenRodWrite = initSprite("images/loadeffect/green3.png", WINDOW_WIDTH * 2, ROD_HEIGHT);
	currentLoadState = NONE;
	
}
void deleteLoadEffect(void) {
	DeleteGraph(backImg);
	//deleteSprite(greenRod);
}

void onLoadFlag() {
	currentLoadState = ERASE;
	currentX = -WINDOW_WIDTH*2;
	currentRod = 0;
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
	else if(currentLoadState == WRITE){
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
void LoadEffect_Draw(void) {
	if (currentLoadState == NONE) { return;}

	if (currentLoadState == ERASE) {
		for (int i = 0; i < currentRod; i++) {
			drawSprite(0, i * ROD_HEIGHT, &greenRod, TRUE);
		}
		drawSprite(currentX, currentRod * ROD_HEIGHT, &greenRodErase, TRUE);
		DrawGraph(0, 0, backImg, TRUE);
	}
	else {
		for (int i = currentRod + 1; i <= ROD_SIZE; i++) {
			drawSprite(0, i * ROD_HEIGHT, &greenRod, TRUE);
		}
		drawSprite(currentX, currentRod * ROD_HEIGHT, &greenRodWrite, TRUE);
		DrawGraph(0, 0, backImg, TRUE);
	}
}