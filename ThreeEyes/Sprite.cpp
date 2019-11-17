#include "Sprite.h"

//構造体初期化
Sprite initSprite(const char* FileName, int width, int height) {
	Sprite sprite = { LoadGraph(FileName), width, height };
	return sprite;
}
//左上起点描画
int drawSprite(int x, int y, Sprite* sprite, BOOL transFlag) {
	return DrawGraph(x, y, sprite->imgHandler, transFlag);
}
//中央起点描画
int drawAtSprite(int x, int y, Sprite* sprite, BOOL transFlag) {
	return DrawGraph(x - (sprite->width / 2), y - (sprite->height / 2), sprite->imgHandler, transFlag);
}
//画像消去
void deleteSprite(Sprite* sprite) {
	DeleteGraph(sprite->imgHandler);
}
