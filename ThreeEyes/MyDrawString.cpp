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

int MyDrawString(int x, int y, MyString* string) {
	return DrawStringToHandle(x, y, string->str, string->color, string->FontHandle);
}

int MyDrawString(MyString* string) {
	return MyDrawString(string->x, string->y, string);
}

int MyDrawAtString(int x, int y, MyString* string) {
	x = x - GetDrawStringWidthToHandle(string->str, strlen(string->str), string->FontHandle) / 2;
	y = y - GetFontSizeToHandle(string->FontHandle) / 2;
	return DrawStringToHandle(x, y, string->str, string->color, string->FontHandle);
}

int MyDrawAtString(MyString* string) {
	return MyDrawAtString(string->x, string->y, string);
}
