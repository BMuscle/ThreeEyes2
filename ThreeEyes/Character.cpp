#include "Character.h"

#define CHAR_WIDTH 200
#define CHAR_HEIGHT 550

#define MESSAGE_WIDTH 640
#define MESSAGE_HEIGHT 480

static Sprite character[CHAR_SIZE][CHAR_EX_SIZE];
static CHAR_TYPE currentChar;
static CHAR_EXPRESSION currentCharEx;
static Sprite message[CHAR_MG_SIZE];//ƒQ[ƒ€ƒƒbƒZ[ƒW
static CHAR_MESSAGE currentMessage;
static BOOL messageFlag;
static BOOL drawFlag;

void initCharacter(void) {
	currentChar = NONE;
	currentCharEx = CHAR_EX_NORMAL;
	messageFlag = FALSE;
	drawFlag = FALSE;
	//‰æ‘œƒTƒCƒY—v•ÏX
		
	character[0][CHAR_EX_NORMAL] = initSprite("images/characters/_‘ã™z/normal.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[0][CHAR_EX_THINK] = initSprite("images/characters/_‘ã™z/think.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[0][CHAR_EX_LOSING] = initSprite("images/characters/_‘ã™z/losing.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[0][CHAR_EX_WINNING] = initSprite("images/characters/_‘ã™z/winning.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[0][CHAR_EX_WIN] = initSprite("images/characters/_‘ã™z/win.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[0][CHAR_EX_LOSE] = initSprite("images/characters/_‘ã™z/lose.png", CHAR_WIDTH, CHAR_HEIGHT);

	character[1][CHAR_EX_NORMAL] = initSprite("images/characters/–]Œ‚­‚é‚İ/normal.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[1][CHAR_EX_THINK] = initSprite("images/characters/–]Œ‚­‚é‚İ/think.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[1][CHAR_EX_LOSING] = initSprite("images/characters/–]Œ‚­‚é‚İ/losing.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[1][CHAR_EX_WINNING] = initSprite("images/characters/–]Œ‚­‚é‚İ/winning.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[1][CHAR_EX_WIN] = initSprite("images/characters/–]Œ‚­‚é‚İ/win.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[1][CHAR_EX_LOSE] = initSprite("images/characters/–]Œ‚­‚é‚İ/lose.png", CHAR_WIDTH, CHAR_HEIGHT);

	character[2][CHAR_EX_NORMAL] = initSprite("images/characters/’†“ˆ”ü‰Ã/normal.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[2][CHAR_EX_THINK] = initSprite("images/characters/’†“ˆ”ü‰Ã/think.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[2][CHAR_EX_LOSING] = initSprite("images/characters/’†“ˆ”ü‰Ã/losing.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[2][CHAR_EX_WINNING] = initSprite("images/characters/’†“ˆ”ü‰Ã/winning.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[2][CHAR_EX_WIN] = initSprite("images/characters/’†“ˆ”ü‰Ã/win.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[2][CHAR_EX_LOSE] = initSprite("images/characters/’†“ˆ”ü‰Ã/lose.png", CHAR_WIDTH, CHAR_HEIGHT);

}
void deleteCharacter(void) {
	for (int i = 0; i < CHAR_SIZE; i++) {
		for (int j = 0; j < CHAR_SIZE; j++) {
			deleteSprite(&character[i][j]);
		}
	}
}


void Character_Draw() {
	if (drawFlag) {
		drawAtSprite(100, WINDOW_HEIGHT * 0.7, &character[currentChar - 1][currentCharEx], TRUE);
	}
	if (messageFlag) {
		//À•W‚ğƒQ[ƒ€‚É‚æ‚Á‚Ä•Ï‚¦‚é?@ƒV[ƒ“
		drawSprite(0, 10, &message[currentMessage], TRUE);
	}
}


void setCharacter(CHAR_TYPE type, CHAR_EXPRESSION charEx) {
	drawFlag = TRUE;
	currentChar = type;
	switch (type) {
	case CHAR_EASY:
		message[CHAR_MG_NORMAL] = initSprite("images/characters/_‘ã™z/messages/normal.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_THINK] = initSprite("images/characters/_‘ã™z/messages/think.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_LOSING] = initSprite("images/characters/_‘ã™z/messages/losing.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_WINNING] = initSprite("images/characters/_‘ã™z/messages/winning.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_WIN] = initSprite("images/characters/_‘ã™z/messages/win.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_LOSE] = initSprite("images/characters/_‘ã™z/messages/lose.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_START] = initSprite("images/characters/_‘ã™z/messages/start.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_DRAW] = initSprite("images/characters/_‘ã™z/messages/draw.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		break;
	case CHAR_NORMAL:
		message[CHAR_MG_NORMAL] = initSprite("images/characters/–]Œ‚­‚é‚İ/messages/normal.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_THINK] = initSprite("images/characters/–]Œ‚­‚é‚İ/messages/think.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_LOSING] = initSprite("images/characters/–]Œ‚­‚é‚İ/messages/losing.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_WINNING] = initSprite("images/characters/–]Œ‚­‚é‚İ/messages/winning.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_WIN] = initSprite("images/characters/–]Œ‚­‚é‚İ/messages/win.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_LOSE] = initSprite("images/characters/–]Œ‚­‚é‚İ/messages/lose.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_START] = initSprite("images/characters/–]Œ‚­‚é‚İ/messages/start.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_DRAW] = initSprite("images/characters/–]Œ‚­‚é‚İ/messages/draw.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		break;
	case CHAR_DIF:
		message[CHAR_MG_NORMAL] = initSprite("images/characters/’†“ˆ”ü‰Ã/messages/normal.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_THINK] = initSprite("images/characters/’†“ˆ”ü‰Ã/messages/think.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_LOSING] = initSprite("images/characters/’†“ˆ”ü‰Ã/messages/losing.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_WINNING] = initSprite("images/characters/’†“ˆ”ü‰Ã/messages/winning.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_WIN] = initSprite("images/characters/’†“ˆ”ü‰Ã/messages/win.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_LOSE] = initSprite("images/characters/’†“ˆ”ü‰Ã/messages/lose.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_START] = initSprite("images/characters/’†“ˆ”ü‰Ã/messages/start.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_DRAW] = initSprite("images/characters/’†“ˆ”ü‰Ã/messages/draw.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		break;


	}
}

void setCharacterExpression(CHAR_EXPRESSION charEx) {
	currentCharEx = charEx;
}

void setCharacterMessage(CHAR_MESSAGE charMsg) {
	currentMessage = charMsg;
}

void setCharDrawFlag(BOOL flag) {
	drawFlag = flag;
}
void setMessageFlag(BOOL flag) {
	messageFlag = flag;
}

void clearCharacter() {
	//currentChar = NONE;
	drawFlag = FALSE;
	messageFlag = FALSE;
}


CHAR_TYPE getCharacterType() {
	return currentChar;
}