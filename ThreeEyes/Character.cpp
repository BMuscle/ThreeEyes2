#include "Character.h"

static Sprite character[CHAR_SIZE][CHAR_EX_SIZE];
static CHAR_TYPE currentChar;
static CHAR_EXPRESSION currentCharEx;


void initCharacter(void) {
	currentChar = NONE;
	currentCharEx = CHAR_EX_NORMAL;
	//âÊëúÉTÉCÉYóvïœçX
	character[0][0] = initSprite("images/characters/ê_ë„ôz/normal.png", 250, 400);
	character[0][1] = initSprite("images/characters/ê_ë„ôz/think.png", 250, 400);
	character[0][2] = initSprite("images/characters/ê_ë„ôz/losing.png", 250, 400);
	character[0][3] = initSprite("images/characters/ê_ë„ôz/winning.png", 250, 400);
	character[0][4] = initSprite("images/characters/ê_ë„ôz/win.png", 250, 400);
	character[0][5] = initSprite("images/characters/ê_ë„ôz/lose.png", 250, 400);

	character[1][0] = initSprite("images/characters/2/normal.png", 250, 400);
	character[1][1] = initSprite("images/characters/2/think.png", 250, 400);
	character[1][2] = initSprite("images/characters/2/losing.png", 250, 400);
	character[1][3] = initSprite("images/characters/2/winning.png", 250, 400);
	character[1][4] = initSprite("images/characters/2/win.png", 250, 400);
	character[1][5] = initSprite("images/characters/2/lose.png", 250, 400);

	character[2][0] = initSprite("images/characters/3/normal.png", 250, 400);
	character[2][1] = initSprite("images/characters/3/think.png", 250, 400);
	character[2][2] = initSprite("images/characters/3/losing.png", 250, 400);
	character[2][3] = initSprite("images/characters/3/winning.png", 250, 400);
	character[2][4] = initSprite("images/characters/3/win.png", 250, 400);
	character[2][5] = initSprite("images/characters/3/lose.png", 250, 400);

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
		drawSprite(-50, WINDOW_HEIGHT * 0.6, &character[currentChar - 1][currentCharEx], TRUE);
	}
}


void setCharacter(CHAR_TYPE type, CHAR_EXPRESSION charEx) {
	currentChar = type;
}

void setCharacterExpression(CHAR_EXPRESSION charEx) {
	currentCharEx = charEx;
}

void clearCharacter() {
	currentChar = NONE;
}
