#pragma once
#include "DxLib.h"
#include "Sprite.h"
#include "MyWindow.h"


enum CHAR_TYPE {
	NONE,
	CHAR_EASY,
	CHAR_NORMAL,
	CHAR_DIF,
	CHAR_SIZE = 3,
};

enum CHAR_EXPRESSION {
	CHAR_EX_NORMAL,
	CHAR_EX_THINK,
	CHAR_EX_LOSING,
	CHAR_EX_WINNING,
	CHAR_EX_WIN,
	CHAR_EX_LOSE,
	CHAR_EX_SIZE,
};

void initCharacter(void);
void deleteCharacter(void);

void Character_Draw();

void setCharacter(CHAR_TYPE type, CHAR_EXPRESSION charEx);
void setCharacterExpression(CHAR_EXPRESSION charEx);
void clearCharacter();
