#include "Character.h"

static Sprite character[CHAR_SIZE];
static CHAR_TYPE currentChar;

void initCharacter(void) {
	currentChar = NONE;

	character[0] = initSprite("images/characters/char1.png", 250, 400);
	character[1] = initSprite("images/characters/char2.png", 250, WINDOW_HEIGHT * 0.7);
	character[2] = initSprite("images/characters/char3.png", WINDOW_WIDTH * 0.2, WINDOW_HEIGHT * 0.7);
}
void deleteCharacter(void) {
	for (int i = 0; i < CHAR_SIZE; i++) {
		deleteSprite(&character[i]);
	}
}


void Character_Draw() {
	if (currentChar != NONE) {
		drawSprite(-50, WINDOW_HEIGHT * 0.6, &character[currentChar - 1], TRUE);
	}
}


void setCharacter(CHAR_TYPE type) {
	currentChar = type;
}
void clearCharacter() {
	currentChar = NONE;
}
