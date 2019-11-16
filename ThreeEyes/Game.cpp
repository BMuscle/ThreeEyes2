#include"DxLib.h"
#include"Game.h"
#include"SceneMgr.h"
#include"Result.h"
#include "Sprite.h"

enum TURN {
	PLAYER = 1,
	COM = 2,
};

struct Board
{
	int board[BOARD_SIZE][BOARD_SIZE];
};

struct Pos {
	int x, y;
};

Sprite back;
Sprite frame;
Sprite maru;
Sprite batu;

Board myBoard;
TURN nowTurn;
BOOL isGameClear;
int gameResult;


void Game_Initialize() {
	nowTurn = PLAYER;
	isGameClear = FALSE;
	
	back = initSprite("images/1blackboard.png", 640, 480);
	frame = initSprite("images/flame.png", 300, 300);
	maru = initSprite("images/maru.png", 100, 100);
	batu = initSprite("images/batsu.png", 100, 100);
}

void Game_Finalize() {

}

void Game_Update() {
	if (CheckHitKey(KEY_INPUT_R) == 1) {
		SceneMgr_ChangeScene(SCENE_RESULT);
		Result_Initialize(getGameResult());
	}

	gameResult = isGameEnd();//�Q�[�����I����Ă���Ȃ�
	if (gameResult > 0) {
		//�V�[���ύX
		SceneMgr_ChangeScene(SCENE_RESULT);
		Result_Initialize(getGameResult());
		return;
	}

	//�Q�[������
	BOOL isSet = FALSE;//�΂�u�������ǂ����t���O

	if (nowTurn == PLAYER) {//�v���C���[�̍s��
		Pos pos;
		if (getLeftDown() == FALSE) { return; }//���̓`�F�b�N
		if (getMousePos(&pos) == FALSE) { return; }//�}�E�X���� & �͈̓`�F�b�N

		if (isSetStone(myBoard, pos.x, pos.y)) {//�Βu���邩�`�F�b�N
			myBoard.board[pos.y][pos.x] = nowTurn;//�u��
			isSet = TRUE;
		}
	}
	else if (nowTurn == COM) {//�R���s���[�^�̍s��
		Pos pos = cpuThink(myBoard, nowTurn);
		myBoard.board[pos.y][pos.x] = nowTurn;
		isSet = TRUE;
	}

	if (isSet) {	//�Βu���ꂽ�Ȃ� �G���h�`�F�b�N&�^�[���`�F���W
		if (isWin(myBoard, nowTurn)) {
			isGameClear = TRUE;
		}
		else {
			nowTurn = changeTurn(nowTurn);
		}
	}
}

void Game_Draw() {
	drawAtSprite(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, &back, TRUE);
	boardDraw();
	DrawFormatString(50, 50, GetColor(0, 0, 0), "�Q�[����ʂł�");
}

int getGameResult() {
	return gameResult;
}


TURN changeTurn(TURN turn) {
	return (TURN)((turn % 2) + 1);
}

BOOL getKey(Pos *pos) {	//�L�[����if���Ŏ��
	int number = -1;
	switch (CheckHitKeyAll()) {
	case KEY_INPUT_1:
		number = 0;
		break;
	case KEY_INPUT_2:
		number = 1;
		break;
	case KEY_INPUT_3:
		number = 2;
		break;
	case KEY_INPUT_4:
		number = 3;
		break;
	case KEY_INPUT_5:
		number = 4;
		break;
	case KEY_INPUT_6:
		number = 5;
		break;
	case KEY_INPUT_7:
		number = 6;
		break;
	case KEY_INPUT_8:
		number = 7;
		break;
	case KEY_INPUT_9:
		number = 8;
		break;
	}

	if (number >= 0) {
		Pos result;
		pos->x = number % BOARD_SIZE;
		pos->y = number / BOARD_SIZE;
		return TRUE;
	}
	return FALSE;
}

void  boardDraw() {//�Ֆʕ`��
	drawSprite(BOARD_OFFSET_X, BOARD_OFFSET_Y, &frame, TRUE);
	int color;
	for (int y = 0; y < BOARD_SIZE; y++) {
		for (int x = 0; x < BOARD_SIZE; x++) {
			switch (myBoard.board[y][x]) {
			case 1:
				drawSprite(BOARD_OFFSET_X + x * RECT_WIDTH, BOARD_OFFSET_Y + y * RECT_HEIGHT, &maru, TRUE);
				break;
			case 2:
				drawSprite(BOARD_OFFSET_X + x * RECT_WIDTH, BOARD_OFFSET_Y + y * RECT_HEIGHT, &batu, TRUE);
				break;
			}
		}
	}
}

void boardDrawString() {//�Ֆʕ����`��
#define OFFSET_BOARD 20
	for (int y = 0; y < BOARD_SIZE; y++) {
		for (int x = 0; x < BOARD_SIZE; x++) {
			DrawFormatString(x * OFFSET_BOARD, y * OFFSET_BOARD, 0xFFFFFF, "%d ", myBoard.board[y][x]);
		}
	}
}

BOOL getMousePos(Pos* pos) {//�}�E�X�̓��͍��W�擾
	int x,y;
	GetMousePoint(&x, &y);
	x -= BOARD_OFFSET_X;
	y -= BOARD_OFFSET_Y;
	if (x >= 0 && x <= BOARD_WIDTH &&
		y >= 0 && y <= BOARD_HEIGHT) {
		//�g���ɓ����Ă���
		pos->x = x / RECT_WIDTH;
		pos->y = y / RECT_HEIGHT;
		return TRUE;
	}
	return FALSE;
}


BOOL isWin(Board board, TURN turn) {//�N���A���Ă��邩�ǂ���
	//�c���є���
	for (int y = 0; y < BOARD_SIZE; y++) {
		if (board.board[y][0] == turn && board.board[y][1] == turn && board.board[y][2] == turn) {
			return true;
		}
	}
	//�����є���
	for (int x = 0; x < BOARD_SIZE; x++) {
		if (board.board[0][x] == turn && board.board[1][x] == turn && board.board[2][x] == turn) {
			return true;
		}
	}
	//�΂ߔ���
	if (board.board[0][0] == turn && board.board[1][1] == turn && board.board[2][2] == turn) {
		return true;
	}

	if (board.board[0][2] == turn && board.board[1][1] == turn && board.board[2][0] == turn) {
		return true;
	}
	return false;
}

BOOL isSetStone(Board board, int x, int y) { //�u���邩�ǂ���
	if (board.board[y][x] == 0) {
		return TRUE;
	}
	return FALSE;
}

BOOL isDrow(Board board) {  //������������ �ύX�ς� �΂��u����ꏊ�𔭌�������return�ɕύX
	for (int y = 0; y < BOARD_SIZE; y++) {
		for (int x = 0; x < BOARD_SIZE; x++) {
			if (isSetStone(board, x, y) == TRUE) {
				return FALSE;
			}
		}
	}
	return TRUE;
}


Pos cpuThink(Board board, TURN turn) {
	Pos pos;
	for (int i = 0; i < 2; i++) {//���ƂP�ŏ��Ă�p�^�[���T�������ƂP�ŕ�����p�^�[���T��
		for (int y = 0; y < BOARD_SIZE; y++) {
			for (int x = 0; x < BOARD_SIZE; x++) {
				if (isSetStone(board, x, y)) {
					Board tmp = board;
					tmp.board[y][x] = turn;
					if (isWin(tmp, turn)) {
						pos.x = x;
						pos.y = y;
						return pos;
					}
				}
			}
		}
		turn = changeTurn(turn);
	}


	if (isSetStone(board, 1, 1)) {//�^��
		pos.x = 1;
		pos.y = 1;
		return pos;
	}
	if (isSetStone(board, 0, 0)) {//�p
		pos.x = 0;
		pos.y = 0;
		return pos;
	}
	if (isSetStone(board, 2, 2)) {
		pos.x = 2;
		pos.y = 2;
		return pos;
	}
	if (isSetStone(board, 2, 0)) {
		pos.x = 2;
		pos.y = 0;
		return pos;
	}
	if (isSetStone(board, 0, 2)) {
		pos.x = 0;
		pos.y = 2;
		return pos;
	}

	for (int i = 0; i < 2; i++) {//���ƂP�ŏ��Ă�p�^�[���T�������ƂP�ŕ�����p�^�[���T��
		for (int y = 0; y < BOARD_SIZE; y++) {
			for (int x = 0; x < BOARD_SIZE; x++) {
				if (isSetStone(board, x, y)) {
					pos.x = x;
					pos.y = y;
				}
			}
		}
	}
	return pos;
}

int isGameEnd() {
	//�Q�[�����I����Ă���Ȃ��
	if (isGameClear) {
		if (nowTurn == PLAYER) {
			return 1;//PLAYER�̏���
		}
		else if (nowTurn == COM) {
			return 2;//COM�̏���
		}		
	}

	if (isDrow(myBoard)) {//��������
		return 3;
	}
	return 0;
}