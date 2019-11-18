#include "Lottery.h"


static Sprite lottery[2];
static BOOL isEnd;
static int frameCount;
static int countLimit;
static int currentTurn;//�Q�[���Ō��܂����^�[��
static int nowTurn;//���݉񂵂Ă���^�[��
static int times;//���݂̉�
static int limitTimes;//���邮�����


void initLottery(int turn) {
	isEnd = FALSE;
	currentTurn = turn - 1;//�Q�[���̃^�[���͂P�n�܂�̂��߂P����	
	frameCount = 0;
	countLimit = 10;
	nowTurn = 0;
	times = 0;
	limitTimes = GetRand(5) + 5;

	lottery[0] = initSprite("images/senkou.png", 264, 299);
	lottery[1] = initSprite("images/koukou.png", 264, 299);
}
void deleteLottery() {
	deleteSprite(&lottery[0]);
	deleteSprite(&lottery[1]);
}

void updateLottery() {
	if (isEndLottery() == FALSE) {
		frameCount++;
		if (frameCount % countLimit == 0) {
			frameCount = 0;
			nowTurn = (nowTurn + 1) % 2 ;
			countLimit *= 1.3;
			times++;
			if (limitTimes < times && nowTurn != currentTurn) {
				isEnd = TRUE;
			}
		}
	}
}
void drawLottery() {
	if (isEndLottery() == FALSE) {
		drawAtSprite(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, &lottery[nowTurn], TRUE);
	}
}

BOOL isEndLottery() {
	return isEnd;
}