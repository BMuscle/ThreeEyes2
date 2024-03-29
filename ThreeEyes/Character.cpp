#include "Character.h"

#define CHAR_WIDTH 200
#define CHAR_HEIGHT 550

#define MESSAGE_WIDTH 640
#define MESSAGE_HEIGHT 480

static Sprite character[CHAR_SIZE][CHAR_EX_SIZE];
static CHAR_TYPE currentChar;
static CHAR_EXPRESSION currentCharEx;
static Sprite message[CHAR_MG_SIZE];//ゲームメッセージ
static CHAR_MESSAGE currentMessage;
static BOOL messageFlag;
static BOOL drawFlag;

void initCharacter(void) {
	currentChar = NONE;
	currentCharEx = CHAR_EX_NORMAL;
	messageFlag = FALSE;
	drawFlag = FALSE;
	//画像サイズ要変更
		
	character[0][CHAR_EX_NORMAL] = initSprite("images/characters/長谷川美嘉/normal.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[0][CHAR_EX_THINK] = initSprite("images/characters/長谷川美嘉/think.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[0][CHAR_EX_LOSING] = initSprite("images/characters/長谷川美嘉/losing.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[0][CHAR_EX_WINNING] = initSprite("images/characters/長谷川美嘉/winning.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[0][CHAR_EX_WIN] = initSprite("images/characters/長谷川美嘉/win.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[0][CHAR_EX_LOSE] = initSprite("images/characters/長谷川美嘉/lose.png", CHAR_WIDTH, CHAR_HEIGHT);

	character[1][CHAR_EX_NORMAL] = initSprite("images/characters/神代凛/normal.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[1][CHAR_EX_THINK] = initSprite("images/characters/神代凛/think.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[1][CHAR_EX_LOSING] = initSprite("images/characters/神代凛/losing.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[1][CHAR_EX_WINNING] = initSprite("images/characters/神代凛/winning.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[1][CHAR_EX_WIN] = initSprite("images/characters/神代凛/win.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[1][CHAR_EX_LOSE] = initSprite("images/characters/神代凛/lose.png", CHAR_WIDTH, CHAR_HEIGHT);

	character[2][CHAR_EX_NORMAL] = initSprite("images/characters/望月くるみ/normal.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[2][CHAR_EX_THINK] = initSprite("images/characters/望月くるみ/think.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[2][CHAR_EX_LOSING] = initSprite("images/characters/望月くるみ/losing.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[2][CHAR_EX_WINNING] = initSprite("images/characters/望月くるみ/winning.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[2][CHAR_EX_WIN] = initSprite("images/characters/望月くるみ/win.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[2][CHAR_EX_LOSE] = initSprite("images/characters/望月くるみ/lose.png", CHAR_WIDTH, CHAR_HEIGHT);

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
		//座標をゲームによって変える?　シーン
		drawSprite(0, 10, &message[currentMessage], TRUE);
	}
}


void setCharacter(CHAR_TYPE type, CHAR_EXPRESSION charEx) {
	drawFlag = TRUE;
	currentChar = type;
	switch (type) {
	case CHAR_EASY:
		message[CHAR_MG_NORMAL] = initSprite("images/characters/長谷川美嘉/messages/normal.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_THINK] = initSprite("images/characters/長谷川美嘉/messages/think.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_LOSING] = initSprite("images/characters/長谷川美嘉/messages/losing.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_WINNING] = initSprite("images/characters/長谷川美嘉/messages/winning.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_WIN] = initSprite("images/characters/長谷川美嘉/messages/win.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_LOSE] = initSprite("images/characters/長谷川美嘉/messages/lose.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_START] = initSprite("images/characters/長谷川美嘉/messages/start.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_DRAW] = initSprite("images/characters/長谷川美嘉/messages/draw.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		break;
	case CHAR_NORMAL:
		message[CHAR_MG_NORMAL] = initSprite("images/characters/神代凛/messages/normal.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_THINK] = initSprite("images/characters/神代凛/messages/think.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_LOSING] = initSprite("images/characters/神代凛/messages/losing.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_WINNING] = initSprite("images/characters/神代凛/messages/winning.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_WIN] = initSprite("images/characters/神代凛/messages/win.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_LOSE] = initSprite("images/characters/神代凛/messages/lose.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_START] = initSprite("images/characters/神代凛/messages/start.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_DRAW] = initSprite("images/characters/神代凛/messages/draw.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		break;
	case CHAR_DIF:
		message[CHAR_MG_NORMAL] = initSprite("images/characters/望月くるみ/messages/normal.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_THINK] = initSprite("images/characters/望月くるみ/messages/think.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_LOSING] = initSprite("images/characters/望月くるみ/messages/losing.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_WINNING] = initSprite("images/characters/望月くるみ/messages/winning.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_WIN] = initSprite("images/characters/望月くるみ/messages/win.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_LOSE] = initSprite("images/characters/望月くるみ/messages/lose.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_START] = initSprite("images/characters/望月くるみ/messages/start.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_DRAW] = initSprite("images/characters/望月くるみ/messages/draw.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
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