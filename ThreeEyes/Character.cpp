#include "Character.h"

#define CHAR_WIDTH 200
#define CHAR_HEIGHT 550

#define MESSAGE_WIDTH 640
#define MESSAGE_HEIGHT 480

static Sprite character[CHAR_SIZE][CHAR_EX_SIZE];
static CHAR_TYPE currentChar;
static CHAR_EXPRESSION currentCharEx;
static Sprite message[CHAR_MG_SIZE];//�Q�[�����b�Z�[�W
static CHAR_MESSAGE currentMessage;
static BOOL messageFlag;
static BOOL drawFlag;

void initCharacter(void) {
	currentChar = NONE;
	currentCharEx = CHAR_EX_NORMAL;
	messageFlag = FALSE;
	drawFlag = FALSE;
	//�摜�T�C�Y�v�ύX
		
	character[0][CHAR_EX_NORMAL] = initSprite("images/characters/�_��z/normal.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[0][CHAR_EX_THINK] = initSprite("images/characters/�_��z/think.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[0][CHAR_EX_LOSING] = initSprite("images/characters/�_��z/losing.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[0][CHAR_EX_WINNING] = initSprite("images/characters/�_��z/winning.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[0][CHAR_EX_WIN] = initSprite("images/characters/�_��z/win.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[0][CHAR_EX_LOSE] = initSprite("images/characters/�_��z/lose.png", CHAR_WIDTH, CHAR_HEIGHT);

	character[1][CHAR_EX_NORMAL] = initSprite("images/characters/�]�������/normal.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[1][CHAR_EX_THINK] = initSprite("images/characters/�]�������/think.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[1][CHAR_EX_LOSING] = initSprite("images/characters/�]�������/losing.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[1][CHAR_EX_WINNING] = initSprite("images/characters/�]�������/winning.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[1][CHAR_EX_WIN] = initSprite("images/characters/�]�������/win.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[1][CHAR_EX_LOSE] = initSprite("images/characters/�]�������/lose.png", CHAR_WIDTH, CHAR_HEIGHT);

	character[2][CHAR_EX_NORMAL] = initSprite("images/characters/��������/normal.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[2][CHAR_EX_THINK] = initSprite("images/characters/��������/think.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[2][CHAR_EX_LOSING] = initSprite("images/characters/��������/losing.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[2][CHAR_EX_WINNING] = initSprite("images/characters/��������/winning.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[2][CHAR_EX_WIN] = initSprite("images/characters/��������/win.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[2][CHAR_EX_LOSE] = initSprite("images/characters/��������/lose.png", CHAR_WIDTH, CHAR_HEIGHT);

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
		//���W���Q�[���ɂ���ĕς���?�@�V�[��
		drawSprite(0, 10, &message[currentMessage], TRUE);
	}
}


void setCharacter(CHAR_TYPE type, CHAR_EXPRESSION charEx) {
	drawFlag = TRUE;
	currentChar = type;
	switch (type) {
	case CHAR_EASY:
		message[CHAR_MG_NORMAL] = initSprite("images/characters/�_��z/messages/normal.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_THINK] = initSprite("images/characters/�_��z/messages/think.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_LOSING] = initSprite("images/characters/�_��z/messages/losing.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_WINNING] = initSprite("images/characters/�_��z/messages/winning.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_WIN] = initSprite("images/characters/�_��z/messages/win.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_LOSE] = initSprite("images/characters/�_��z/messages/lose.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_START] = initSprite("images/characters/�_��z/messages/start.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_DRAW] = initSprite("images/characters/�_��z/messages/draw.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		break;
	case CHAR_NORMAL:
		message[CHAR_MG_NORMAL] = initSprite("images/characters/�]�������/messages/normal.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_THINK] = initSprite("images/characters/�]�������/messages/think.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_LOSING] = initSprite("images/characters/�]�������/messages/losing.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_WINNING] = initSprite("images/characters/�]�������/messages/winning.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_WIN] = initSprite("images/characters/�]�������/messages/win.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_LOSE] = initSprite("images/characters/�]�������/messages/lose.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_START] = initSprite("images/characters/�]�������/messages/start.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_DRAW] = initSprite("images/characters/�]�������/messages/draw.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		break;
	case CHAR_DIF:
		message[CHAR_MG_NORMAL] = initSprite("images/characters/��������/messages/normal.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_THINK] = initSprite("images/characters/��������/messages/think.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_LOSING] = initSprite("images/characters/��������/messages/losing.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_WINNING] = initSprite("images/characters/��������/messages/winning.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_WIN] = initSprite("images/characters/��������/messages/win.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_LOSE] = initSprite("images/characters/��������/messages/lose.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_START] = initSprite("images/characters/��������/messages/start.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[CHAR_MG_DRAW] = initSprite("images/characters/��������/messages/draw.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
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