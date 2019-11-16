#pragma once
#include "DxLib.h"

struct MyString {//strÇÕ64éöêßå¿
	char str[64] = {0};
	int color;
	int FontHandle;
	int x, y;
};

MyString initMyString(const char* str, int color, int FontHandle, int x, int y);


int MyDrawString(int x, int y, MyString* string);
int MyDrawString(MyString* string);
int MyDrawAtString(int x, int y, MyString* string);
int MyDrawAtString(MyString* string);
