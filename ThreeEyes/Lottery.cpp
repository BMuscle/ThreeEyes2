#include "Lottery.h"


static Sprite lottery[2];
static MyString message;
static BOOL isEnd;
static BOOL isRun;//計算処理が動いてるかどうか
static int font;
static int frameCount;
static int countLimit;
static int currentTurn;//ゲームで決まったターン
static int nowTurn;//現在回しているターン
static int times;//現在の回数
static int limitTimes;//ぐるぐる回る回数
static int seStopWatch;//ストップウォッチが回る時の効果音ハンドル
static int seStopWatchEnd;//ストップウォッチが終わる時の効果音


void initLottery(int turn) {
	isEnd = FALSE;
	isRun = FALSE;
	currentTurn = turn - 1;//ゲームのターンは１始まりのため１引く	
	frameCount = 0;
	countLimit = 7;
	nowTurn = 0;
	times = 0;
	limitTimes = GetRand(2) + 5;
	seStopWatch = LoadSoundMem("musics/stopwatch.wav");
	seStopWatchEnd = LoadSoundMem("musics/stopwatchend.wav");
	ChangeVolumeSoundMem(140, seStopWatch);
	ChangeVolumeSoundMem(140, seStopWatchEnd);
	lottery[0] = initSprite("images/senkou1.png", 274, 318);
	lottery[1] = initSprite("images/koukou1.png", 274, 318);
	font = CreateFontToHandle("ゴシック", 30, 6, DX_FONTTYPE_ANTIALIASING);
	if (turn == 1) {
		message = initMyString("あなたは先攻です。",0xFFFFFF,font, WINDOW_WIDTH/2, WINDOW_HEIGHT * 0.5);
	}
	else {
		message = initMyString("あなたは後攻です。", 0xFFFFFF, font, WINDOW_WIDTH / 2, WINDOW_HEIGHT * 0.5);
	}
	message.alpha = 0;
}
void deleteLottery() {
	DeleteSoundMem(seStopWatch);
	DeleteSoundMem(seStopWatchEnd);
	deleteSprite(&lottery[0]);
	deleteSprite(&lottery[1]);
}

void updateLottery() {
	if (isEnd == FALSE) {
		isRun = TRUE;
		frameCount++;
		if (frameCount % countLimit == 0) {//一定時間経過後　表示されているものを交換する。
			frameCount = 0;
			nowTurn = (nowTurn + 1) % 2 ;
			countLimit *= 1.4;
			times++;
			if (limitTimes < times && nowTurn != currentTurn) {//最後確定させる時
				isEnd = TRUE;
				isRun = FALSE;
				message.alpha = 255;
				PlaySoundMem(seStopWatchEnd, DX_PLAYTYPE_BACK);//確定させる時の音
			}
			else {
				PlaySoundMem(seStopWatch, DX_PLAYTYPE_BACK);//回っているときの音
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