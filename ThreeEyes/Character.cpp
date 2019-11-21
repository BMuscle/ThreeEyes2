#include "Character.h"

#define CHAR_WIDTH 200
#define CHAR_HEIGHT 550

#define MESSAGE_WIDTH 640
#define MESSAGE_HEIGHT 480

static Sprite character[CHAR_SIZE][CHAR_EX_SIZE];
static CHAR_TYPE currentChar;
static CHAR_EXPRESSION currentCharEx;
static Sprite message[CHAR_MG_SIZE];//ÉQÅ[ÉÄÉÅÉbÉZÅ[ÉW
static CHAR_MESSAGE currentMessage;
static BOOL messageFlag;
static BOOL drawFlag;

void initCharacter(void) {
	currentChar = NONE;
	currentCharEx = CHAR_EX_NORMAL;
	messageFlag = FALSE;
	drawFlag = FALSE;
	//âÊëúÉTÉCÉYóvïœçX
		
	character[0][CHAR_EX_NORMAL] = initSprite("images/characters/í∑íJêÏî¸â√/normal.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[0][CHAR_EX_THINK] = initSprite("images/characters/í∑íJêÏî¸â√/think.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[0][CHAR_EX_LOSING] = initSprite("images/characters/í∑íJêÏî¸â√/losing.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[0][CHAR_EX_WINNING] = initSprite("images/characters/í∑íJêÏî¸â√/winning.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[0][CHAR_EX_WIN] = initSprite("images/characters/í∑íJêÏî¸â√/win.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[0][CHAR_EX_LOSE] = initSprite("images/characters/í∑íJêÏî¸â√/lose.png", CHAR_WIDTH, CHAR_HEIGHT);

	character[1][CHAR_EX_NORMAL] = initSprite("images/characters/ê_ë„ôz/normal.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[1][CHAR_EX_THINK] = initSprite("images/characters/ê_ë„ôz/think.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[1][CHAR_EX_LOSING] = initSprite("images/characters/ê_ë„ôz/losing.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[1][CHAR_EX_WINNING] = initSprite("images/characters/ê_ë„ôz/winning.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[1][CHAR_EX_WIN] = initSprite("images/characters/ê_ë„ôz/win.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[1][CHAR_EX_LOSE] = initSprite("images/characters/ê_ë„ôz/lose.png", CHAR_WIDTH, CHAR_HEIGHT);

	character[2][CHAR_EX_NORMAL] = initSprite("images/characters/ñ]åéÇ≠ÇÈÇ›/normal.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[2][CHAR_EX_THINK] = initSprite("images/characters/ñ]åéÇ≠ÇÈÇ›/think.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[2][CHAR_EX_LOSING] = initSprite("images/characters/ñ]åéÇ≠ÇÈÇ›/losing.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[2][CHAR_EX_WINNING] = initSprite("images/characters/ñ]åéÇ≠ÇÈÇ›/winning.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[2][CHAR_EX_WIN] = initSprite("images/characters/ñ]åéÇ≠ÇÈÇ›/win.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[2][CHAR_EX_LOSE] = initSprite("images/characters/ñ]åéÇ≠ÇÈÇ›/lose.png", CHAR_WIDTH, CHAR_HEIGHT);

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
		//ç¿ïWÇÉQÅ[ÉÄÇ…ÇÊÇ¡ÇƒïœÇ¶ÇÈ?Å@ÉVÅ[Éì
		drawSprite(0, 10, &message[currentMessage], TRUE);
	}
}


void setCharacter(CHAR_TYPE type, CHAR_EXPRESSION charEx) {
	drawFlag = TRUE;
	currentChar = type;
	switch (type) {
	case CHAR_EASY:
		message[CHAR_MG_NORMAL] = initSprite("images/characters/í∑íJêÏî¸â√/messages/normal.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_THINK] = initSprite("images/characters/í∑íJêÏî¸â√/messages/think.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_LOSING] = initSprite("images/characters/í∑íJêÏî¸â√/messages/losing.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_WINNING] = initSprite("images/characters/í∑íJêÏî¸â√/messages/winning.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_WIN] = initSprite("images/characters/í∑íJêÏî¸â√/messages/win.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_LOSE] = initSprite("images/characters/í∑íJêÏî¸â√/messages/lose.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_START] = initSprite("images/characters/í∑íJêÏî¸â√/messages/start.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_DRAW] = initSprite("images/characters/í∑íJêÏî¸â√/messages/draw.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		break;
	case CHAR_NORMAL:
		message[CHAR_MG_NORMAL] = initSprite("images/characters/ê_ë„ôz/messages/normal.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_THINK] = initSprite("images/characters/ê_ë„ôz/messages/think.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_LOSING] = initSprite("images/characters/ê_ë„ôz/messages/losing.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_WINNING] = initSprite("images/characters/ê_ë„ôz/messages/winning.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_WIN] = initSprite("images/characters/ê_ë„ôz/messages/win.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_LOSE] = initSprite("images/characters/ê_ë„ôz/messages/lose.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_START] = initSprite("images/characters/ê_ë„ôz/messages/start.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_DRAW] = initSprite("images/characters/ê_ë„ôz/messages/draw.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		break;
	case CHAR_DIF:
		message[CHAR_MG_NORMAL] = initSprite("images/characters/ñ]åéÇ≠ÇÈÇ›/messages/normal.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_THINK] = initSprite("images/characters/ñ]åéÇ≠ÇÈÇ›/messages/think.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_LOSING] = initSprite("images/characters/ñ]åéÇ≠ÇÈÇ›/messages/losing.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_WINNING] = initSprite("images/characters/ñ]åéÇ≠ÇÈÇ›/messages/winning.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_WIN] = initSprite("images/characters/ñ]åéÇ≠ÇÈÇ›/messages/win.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_LOSE] = initSprite("images/characters/ñ]åéÇ≠ÇÈÇ›/messages/lose.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_START] = initSprite("images/characters/ñ]åéÇ≠ÇÈÇ›/messages/start.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_DRAW] = initSprite("images/characters/ñ]åéÇ≠ÇÈÇ›/messages/draw.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
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