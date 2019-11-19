#include "Character.h"

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
#define CHAR_WIDTH 200
#define CHAR_HEIGHT 550
		
		
		
		
		
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
	if (currentChar != NONE) {
		drawSprite(-20, WINDOW_HEIGHT * 0.4, &character[currentChar - 1][currentCharEx], TRUE);
	}
	if (messageFlag) {
		//���W���Q�[���ɂ���ĕς���@�V�[��
		
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
		message[0] = initSprite("images/characters/�_��z/message/normal.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[1] = initSprite("images/characters/�_��z/message/think.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[2] = initSprite("images/characters/�_��z/message/losing.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[3] = initSprite("images/characters/�_��z/message/winning.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[4] = initSprite("images/characters/�_��z/message/win.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[5] = initSprite("images/characters/�_��z/message/lose.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		break;
	case CHAR_NORMAL:
		message[0] = initSprite("images/characters/�]�������/message/normal.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[1] = initSprite("images/characters/�]�������/message/think.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[2] = initSprite("images/characters/�]�������/message/losing.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[3] = initSprite("images/characters/�]�������/message/winning.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[4] = initSprite("images/characters/�]�������/message/win.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[5] = initSprite("images/characters/�]�������/message/lose.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		break;
	case CHAR_DIF:
		message[0] = initSprite("images/characters/��������/message/normal.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[1] = initSprite("images/characters/��������/message/think.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[2] = initSprite("images/characters/��������/message/losing.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[3] = initSprite("images/characters/��������/message/winning.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[4] = initSprite("images/characters/��������/message/win.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[5] = initSprite("images/characters/��������/message/lose.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
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
