#include "MyMouse.h"

enum MOUSE{
	LEFT,
	RIGHT,
	TYPE_SIZE,
};

int mouse[MOUSE::TYPE_SIZE];//

void Mouse_Update() {
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {
		mouse[MOUSE::LEFT]++;
	}
	else {
		mouse[MOUSE::LEFT] = 0;
	}

	if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0) {
		mouse[MOUSE::RIGHT]++;
	}
	else {
		mouse[MOUSE::RIGHT] = 0;
	}
}

BOOL getLeftDown() {
	if (mouse[MOUSE::LEFT] == 1) {
		return TRUE;
	}
	return FALSE;
}

BOOL getRightDown() {
	if (mouse[MOUSE::RIGHT] == 1) {
		return TRUE;
	}
	return FALSE;
}

int getLeftPress() {
	return mouse[MOUSE::LEFT];
}

int getRightPress(){
	return mouse[MOUSE::LEFT];
}


