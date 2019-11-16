#pragma once
#include "DxLib.h"
#include "MyDrawString.h"
#include "Sprite.h"

struct MassageBox {
	struct MyString mystr;
	struct Sprite sprite;
};

MassageBox initMassageBox(const char* FileName, const char* str, int color, int FontHandle, int x, int y, int width, int height);
int DrawMassageBox(MassageBox* msgbox, int x, int y, BOOL transFlag);
int DrawMassageBox(MassageBox* msgbox, BOOL transFlag);

int DrawAtMassageBox(MassageBox* msgbox, int x, int y, BOOL transFlag);
int DrawAtMassageBox(MassageBox* msgbox, BOOL transFlag);