#include "MassageBox.h"

MassageBox initMassageBox(const char* FileName, const char* str, int color, int FontHandle, int x, int y, int width, int height) {
	MassageBox msgbox;
	msgbox.mystr = initMyString(str, color, FontHandle, x, y);
	msgbox.sprite = initSprite(FileName, width, height);
	return msgbox;
}

int drawMassageBox(MassageBox* msgbox, int x, int y, BOOL transFlag) {
	drawSprite(x, y, &msgbox->sprite, transFlag);
	return mydrawAtString(x + msgbox->sprite.width / 2, y + msgbox->sprite.height / 2, &msgbox->mystr);
}
int drawMassageBox(MassageBox* msgbox, BOOL transFlag) {
	return drawMassageBox(msgbox, msgbox->mystr.x, msgbox->mystr.y, transFlag);
}

int drawAtMassageBox(MassageBox* msgbox, int x, int y, BOOL transFlag) {
	drawAtSprite(x, y, &msgbox->sprite, transFlag);
	return mydrawAtString(x, y, &msgbox->mystr);
}
int drawAtMassageBox(MassageBox* msgbox, BOOL transFlag) {
	return drawAtMassageBox(msgbox, msgbox->mystr.x, msgbox->mystr.y, transFlag);
}

void deleteMassageBox(MassageBox* msgbox) {
	deleteSprite(&msgbox->sprite);
}