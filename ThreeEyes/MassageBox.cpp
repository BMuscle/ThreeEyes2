#include "MassageBox.h"

MassageBox initMassageBox(const char* FileName, const char* str, int color, int FontHandle, int x, int y, int width, int height) {
	MassageBox msgbox;
	msgbox.mystr = initMyString(str, color, FontHandle, x, y);
	msgbox.sprite = initSprite(FileName, width, height);
	return msgbox;
}

int DrawMassageBox(MassageBox* msgbox, int x, int y, BOOL transFlag) {
	drawSprite(x, y, &msgbox->sprite, transFlag);
	return MyDrawAtString(x + msgbox->sprite.width / 2, y + msgbox->sprite.height / 2, &msgbox->mystr);
}
int DrawMassageBox(MassageBox* msgbox, BOOL transFlag) {
	return DrawMassageBox(msgbox, msgbox->mystr.x, msgbox->mystr.y, transFlag);
}

int DrawAtMassageBox(MassageBox* msgbox, int x, int y, BOOL transFlag) {
	drawAtSprite(x, y, &msgbox->sprite, transFlag);
	return MyDrawAtString(x, y, &msgbox->mystr);
}
int DrawAtMassageBox(MassageBox* msgbox, BOOL transFlag) {
	return DrawAtMassageBox(msgbox, msgbox->mystr.x, msgbox->mystr.y, transFlag);
}