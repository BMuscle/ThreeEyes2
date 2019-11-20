#include "Lottery.h"


static Sprite lottery[2];
static MyString message;
static BOOL isEnd;
static BOOL isRun;//�v�Z�����������Ă邩�ǂ���
static int font;
static int frameCount;
static int countLimit;
static int currentTurn;//�Q�[���Ō��܂����^�[��
static int nowTurn;//���݉񂵂Ă���^�[��
static int times;//���݂̉�
static int limitTimes;//���邮�����


void initLottery(int turn) {
	isEnd = FALSE;
	isRun = FALSE;
	currentTurn = turn - 1;//�Q�[���̃^�[���͂P�n�܂�̂��߂P����	
	frameCount = 0;
	countLimit = 7;
	nowTurn = 0;
	times = 0;
	limitTimes = GetRand(2) + 5;

	lottery[0] = initSprite("images/senkou1.png", 274, 318);
	lottery[1] = initSprite("images/koukou1.png", 274, 318);
	font = CreateFontToHandle("�S�V�b�N", 30, 6, DX_FONTTYPE_ANTIALIASING);
	if (turn == 1) {
		message = initMyString("���Ȃ��͐�U�ł��B",0xFFFFFF,font, WINDOW_WIDTH/2, WINDOW_HEIGHT * 0.5);
	}
	else {
		message = initMyString("���Ȃ��͌�U�ł��B", 0xFFFFFF, font, WINDOW_WIDTH / 2, WINDOW_HEIGHT * 0.5);
	}
	message.alpha = 0;
}
void deleteLottery() {
	deleteSprite(&lottery[0]);
	deleteSprite(&lottery[1]);
}

void updateLottery() {
	if (isEnd == FALSE) {
		isRun = TRUE;
		frameCount++;
		if (frameCount % countLimit == 0) {
			frameCount = 0;
			nowTurn = (nowTurn + 1) % 2 ;
			countLimit *= 1.4;
			times++;
			if (limitTimes < times && nowTurn != currentTurn) {
				isEnd = TRUE;
				isRun = FALSE;
				message.alpha = 255;
			}
		}
	}
	else {
		message.alpha -= 3;
		if (message.alpha < 0) {
			message.alpha = 0;
		}
	}
}
void drawLottery() {
	if (isRun) {
		drawAtSprite(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, &lottery[nowTurn], TRUE);
	}
	else {
		mydrawAtString(&message);
	}
}

BOOL isLotteryEnd() {
	return isEnd;
}