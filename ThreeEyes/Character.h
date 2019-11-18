#pragma once
#include "DxLib.h"
#include "Sprite.h"
#include "MyWindow.h"


enum CHAR_TYPE {
	NONE,
	CHAR_EASY,
	CHAR_NORMAL,
	CHAR_DIF,
	CHAR_SIZE,
};

void initCharacter(void);
void deleteCharacter(void);

void Character_Draw();

void setCharacter(CHAR_TYPE type);
void clearCharacter();
