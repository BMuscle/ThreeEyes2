#include "MassageBox.h"


//���������č\���̂�Ԃ�
MassageBox initMassageBox(const char* FileName, const char* str, int color, int FontHandle, int x, int y, int width, int height) {
	MassageBox msgbox;
	msgbox.mystr = initMyString(str, color, FontHandle, x, y);
	msgbox.sprite = initSprite(FileName, width, height);
	return msgbox;
}

//����N�_�`��@���W���ڎw��
int drawMassageBox(MassageBox* msgbox, int x, int y, BOOL transFlag) {
	drawSprite(x, y, &msgbox->sprite, transFlag);
	return mydrawAtString(x + msgbox->sprite.width / 2, y + msgbox->sprite.height / 2, &msgbox->mystr);
}
//����N�_�`��
int drawMassageBox(MassageBox* msgbox, BOOL transFlag) {
	return drawMassageBox(msgbox, msgbox->mystr.x, msgbox->mystr.y, transFlag);
}
//�����N�_�`��@���W���ڎw��
int drawAtMassageBox(MassageBox* msgbox, int x, int y, BOOL transFlag) {
	drawAtSprite(x, y, &msgbox->sprite, transFlag);
	return mydrawAtString(x, y, &msgbox->mystr);
}
//�����N�_�`��
int drawAtMassageBox(MassageBox* msgbox, BOOL transFlag) {
	return drawAtMassageBox(msgbox, msgbox->mystr.x, msgbox->mystr.y, transFlag);
}
//�摜����
void deleteMassageBox(MassageBox* msgbox) {
	deleteSprite(&msgbox->sprite);
}