#include "Sprite.h"


Sprite initSprite(const char* FileName, int width, int height) {
	Sprite sprite = { LoadGraph(FileName), width, height };
	return sprite;
}
int drawSprite(int x, int y, Sprite* sprite, BOOL transFlag) {
	return DrawGraph(x, y, sprite->imgHandler, transFlag);
}
int drawAtSprite(int x, int y, Sprite* sprite, BOOL transFlag) {
	return DrawGraph(x - (sprite->width / 2), y - (sprite->height / 2), sprite->imgHandler, transFlag);
}
