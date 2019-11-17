#include "MyMouse.h"

enum MOUSE{//�}�E�X�̓��͏��^�C�v
	LEFT,
	RIGHT,
	TYPE_SIZE,
};

static int mouse[MOUSE::TYPE_SIZE];//�}�E�X�̓��̓t���[�������i�[

void Mouse_Update() {//�v�Z����
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {//���N���b�N
		mouse[MOUSE::LEFT]++;
	}
	else {
		mouse[MOUSE::LEFT] = 0;
	}

	if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0) {//�E�N���b�N
		mouse[MOUSE::RIGHT]++;
	}
	else {
		mouse[MOUSE::RIGHT] = 0;
	}
}

BOOL getLeftDown() {//���N���b�N
	if (mouse[MOUSE::LEFT] == 1) {
		return TRUE;
	}
	return FALSE;
}

BOOL getRightDown() {//�E�N���b�N
	if (mouse[MOUSE::RIGHT] == 1) {
		return TRUE;
	}
	return FALSE;
}

int getLeftPress() {//���v���X
	return mouse[MOUSE::LEFT];
}

int getRightPress(){//�E�v���X
	return mouse[MOUSE::LEFT];
}


