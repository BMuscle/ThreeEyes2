#include "MyMouse.h"

enum MOUSE{//マウスの入力情報タイプ
	LEFT,
	RIGHT,
	TYPE_SIZE,
};

static int mouse[MOUSE::TYPE_SIZE];//マウスの入力フレーム数が格納

void Mouse_Update() {//計算処理
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {//左クリック
		mouse[MOUSE::LEFT]++;
	}
	else {
		mouse[MOUSE::LEFT] = 0;
	}

	if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0) {//右クリック
		mouse[MOUSE::RIGHT]++;
	}
	else {
		mouse[MOUSE::RIGHT] = 0;
	}
}

BOOL getLeftDown() {//左クリック
	if (mouse[MOUSE::LEFT] == 1) {
		return TRUE;
	}
	return FALSE;
}

BOOL getRightDown() {//右クリック
	if (mouse[MOUSE::RIGHT] == 1) {
		return TRUE;
	}
	return FALSE;
}

int getLeftPress() {//左プレス
	return mouse[MOUSE::LEFT];
}

int getRightPress(){//右プレス
	return mouse[MOUSE::LEFT];
}


