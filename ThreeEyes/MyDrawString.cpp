#include "MyDrawString.h"

MyString initMyString(const char* str, int color, int FontHandle, int x, int y) {
	MyString mystr;
	strcpy(mystr.str, str);
	mystr.color = color;
	mystr.FontHandle = FontHandle;
	mystr.x = x;
	mystr.y = y;
	mystr.alpha = 255;
	return mystr;
}

int mydrawString(int x, int y, MyString* string) {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, string->alpha);
	int result = DrawStringToHandle(x, y, string->str, string->color, string->FontHandle);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	return result;
}

int mydrawString(MyString* string) {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, string->alpha);
	int result = mydrawString(string->x, string->y, string);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	return result;
}

int mydrawAtString(int x, int y, MyString* string) {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, string->alpha);
	x = x - GetDrawStringWidthToHandle(string->str, strlen(string->str), string->FontHandle) / 2;
	y = y - GetFontSizeToHandle(string->FontHandle) / 2;
	int result = DrawStringToHandle(x, y, string->str, string->color, string->FontHandle);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	return result;
}

int mydrawAtString(MyString* string) {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, string->alpha);
	int result = mydrawAtString(string->x, string->y, string);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	return result;
}
