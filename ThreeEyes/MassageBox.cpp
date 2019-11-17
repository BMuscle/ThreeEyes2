#include "MassageBox.h"


//初期化して構造体を返す
MassageBox initMassageBox(const char* FileName, const char* str, int color, int FontHandle, int x, int y, int width, int height) {
	MassageBox msgbox;
	msgbox.mystr = initMyString(str, color, FontHandle, x, y);
	msgbox.sprite = initSprite(FileName, width, height);
	return msgbox;
}

//左上起点描画　座標直接指定
int drawMassageBox(MassageBox* msgbox, int x, int y, BOOL transFlag) {
	drawSprite(x, y, &msgbox->sprite, transFlag);
	return mydrawAtString(x + msgbox->sprite.width / 2, y + msgbox->sprite.height / 2, &msgbox->mystr);
}
//左上起点描画
int drawMassageBox(MassageBox* msgbox, BOOL transFlag) {
	return drawMassageBox(msgbox, msgbox->mystr.x, msgbox->mystr.y, transFlag);
}
//中央起点描画　座標直接指定
int drawAtMassageBox(MassageBox* msgbox, int x, int y, BOOL transFlag) {
	drawAtSprite(x, y, &msgbox->sprite, transFlag);
	return mydrawAtString(x, y, &msgbox->mystr);
}
//中央起点描画
int drawAtMassageBox(MassageBox* msgbox, BOOL transFlag) {
	return drawAtMassageBox(msgbox, msgbox->mystr.x, msgbox->mystr.y, transFlag);
}
//画像消去
void deleteMassageBox(MassageBox* msgbox) {
	deleteSprite(&msgbox->sprite);
}