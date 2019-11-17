#include "MyDrawString.h"

//初期化して構造体を返す
MyString initMyString(const char* str, int color, int FontHandle, int x, int y) {
	MyString mystr;
	strcpy(mystr.str, str);
	mystr.color = color;
	mystr.FontHandle = FontHandle;
	mystr.x = x;
	mystr.y = y;
	mystr.alpha = 255;//初期α値
	return mystr;
}

//左上起点描画　座標直接指定
int mydrawString(int x, int y, MyString* string) {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, string->alpha);
	int result = DrawStringToHandle(x, y, string->str, string->color, string->FontHandle);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	return result;
}
//左上起点描画
int mydrawString(MyString* string) {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, string->alpha);
	int result = mydrawString(string->x, string->y, string);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	return result;
}
//中央起点描画　座標直接指定
int mydrawAtString(int x, int y, MyString* string) {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, string->alpha);
	x = x - GetDrawStringWidthToHandle(string->str, strlen(string->str), string->FontHandle) / 2;
	y = y - GetFontSizeToHandle(string->FontHandle) / 2;
	int result = DrawStringToHandle(x, y, string->str, string->color, string->FontHandle);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	return result;
}
//中央起点描画
int mydrawAtString(MyString* string) {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, string->alpha);
	int result = mydrawAtString(string->x, string->y, string);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	return result;
}
