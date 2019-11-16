#include "MyDrawString.h"

MyString initMyString(const char* str, int color, int FontHandle, int x, int y) {
	MyString mystr;
	strcpy(mystr.str, str);
	mystr.color = color;
	mystr.FontHandle = FontHandle;
	mystr.x = x;
	mystr.y = y;
	return mystr;
}

int mydrawString(int x, int y, MyString* string) {
	return DrawStringToHandle(x, y, string->str, string->color, string->FontHandle);
}

int mydrawString(MyString* string) {
	return mydrawString(string->x, string->y, string);
}

int mydrawAtString(int x, int y, MyString* string) {
	x = x - GetDrawStringWidthToHandle(string->str, strlen(string->str), string->FontHandle) / 2;
	y = y - GetFontSizeToHandle(string->FontHandle) / 2;
	return DrawStringToHandle(x, y, string->str, string->color, string->FontHandle);
}

int mydrawAtString(MyString* string) {
	return mydrawAtString(string->x, string->y, string);
}
