#pragma once
#include "DxLib.h"
#include "MyWindow.h"

struct Sprite {//画像情報
	int imgHandler;
	int width;
	int height;
};

Sprite initSprite(const char *FileName,int width,int height);//画像情報を初期化し構造体を返す
int drawSprite(int x, int y, Sprite* sprite, BOOL transFlag);//左上起点描画
int drawAtSprite(int x, int y, Sprite* sprite, BOOL transFlag);//中央起点描画
void deleteSprite(Sprite* sprite);//画像消去