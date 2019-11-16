#pragma once
#include "DxLib.h"

struct Sprite {
	int imgHandler;
	int width;
	int height;
};

Sprite initSprite(const char *FileName,int width,int height);
int drawSprite(int x, int y, Sprite* sprite, BOOL transFlag);
int drawAtSprite(int x, int y, Sprite* sprite, BOOL transFlag);
void deleteSprite(Sprite* sprite);