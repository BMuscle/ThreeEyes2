#include "Character.h"

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
#define CHAR_WIDTH 200
#define CHAR_HEIGHT 550
		
		
		
		
		
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
	if (currentChar != NONE) {
		drawSprite(-20, WINDOW_HEIGHT * 0.4, &character[currentChar - 1][currentCharEx], TRUE);
	}
	if (messageFlag) {
		//À•W‚ğƒQ[ƒ€‚É‚æ‚Á‚Ä•Ï‚¦‚é@ƒV[ƒ“
		
		drawSprite(0, 0, &message[currentMessage], TRUE);
	}
}


void setCharacter(CHAR_TYPE type, CHAR_EXPRESSION charEx) {
#define MESSAGE_WIDTH 200
#define MESSAGE_HEIGHT 200
	drawFlag = TRUE;
	currentChar = type;
	switch (type) {
	case CHAR_EASY:
		message[0] = initSprite("images/characters/_‘ã™z/message/normal.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[1] = initSprite("images/characters/_‘ã™z/message/think.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[2] = initSprite("images/characters/_‘ã™z/message/losing.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[3] = initSprite("images/characters/_‘ã™z/message/winning.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[4] = initSprite("images/characters/_‘ã™z/message/win.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[5] = initSprite("images/characters/_‘ã™z/message/lose.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		break;
	case CHAR_NORMAL:
		message[0] = initSprite("images/characters/–]Œ‚­‚é‚İ/message/normal.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[1] = initSprite("images/characters/–]Œ‚­‚é‚İ/message/think.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[2] = initSprite("images/characters/–]Œ‚­‚é‚İ/message/losing.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[3] = initSprite("images/characters/–]Œ‚­‚é‚İ/message/winning.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[4] = initSprite("images/characters/–]Œ‚­‚é‚İ/message/win.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[5] = initSprite("images/characters/–]Œ‚­‚é‚İ/message/lose.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		break;
	case CHAR_DIF:
		message[0] = initSprite("images/characters/’†“ˆ”ü‰Ã/message/normal.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[1] = initSprite("images/characters/’†“ˆ”ü‰Ã/message/think.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[2] = initSprite("images/characters/’†“ˆ”ü‰Ã/message/losing.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[3] = initSprite("images/characters/’†“ˆ”ü‰Ã/message/winning.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[4] = initSprite("images/characters/’†“ˆ”ü‰Ã/message/win.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[5] = initSprite("images/characters/’†“ˆ”ü‰Ã/message/lose.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		break;


	}
}

void setCharacterExpression(CHAR_EXPRESSION charEx) {
	currentCharEx = charEx;
}

void setCharacterMessage(CHAR_MESSAGE charMsg) {
	currentMessage = charMsg;
}

void setMessageFlag(BOOL flag) {
	messageFlag = flag;
}

void clearCharacter() {
	currentChar = NONE;
	drawFlag = FALSE;
	messageFlag = FALSE;
}
