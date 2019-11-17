#pragma once
#include "DxLib.h"

//文字列描画
struct MyString {//strは64字制限
	char str[64] = {0};
	int color;
	int FontHandle;
	int x, y;
	int alpha;
};

MyString initMyString(const char* str, int color, int FontHandle, int x, int y);//文字列の初期化


int mydrawString(int x, int y, MyString* string);//左上起点で文字列描画
int mydrawString(MyString* string);//文字列構造体に入っている情報で左上起点で描画
int mydrawAtString(int x, int y, MyString* string);//中央起点で文字列描画
int mydrawAtString(MyString* string);//文字列構造体に入っている情報で中央起点で描画

