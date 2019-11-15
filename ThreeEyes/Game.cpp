#include"DxLib.h"
#include"Game.h"
#include"SceneMgr.h"
#include"Result.h"

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

Board myBoard;

int turn = PLAYER;
BOOL isGameClear = FALSE;
int gameResult;

void Game_Initialize() {//�Ă΂�Ă��Ȃ�
	turn = PLAYER;
	isGameClear = FALSE;
	
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
		return;
	}

	//�Q�[������

	BOOL isSet = FALSE;//�΂�u�������ǂ����t���O

	if (turn == PLAYER) {//�v���C���[�̍s��
		Pos pos;
		if (getLeftDown() == FALSE) { return; }//���̓`�F�b�N
		if (getMousePos(&pos) == FALSE) { return; }//�}�E�X���� & �͈̓`�F�b�N

		if (isSetStone(myBoard, pos.x, pos.y)) {//�Βu���邩�`�F�b�N
			myBoard.board[pos.y][pos.x] = turn;//�u��
			isSet = TRUE;
		}
	}
	else if (turn == COM) {//�R���s���[�^�̍s��
		Pos pos = cpuThink(myBoard, turn);
		myBoard.board[pos.y][pos.x] = turn;
		isSet = TRUE;
	}

	if (isSet) {	//�Βu���ꂽ�Ȃ� �G���h�`�F�b�N&�^�[���`�F���W
		if (isClear(myBoard, turn)) {
			isGameClear = TRUE;
		}
		else {
			turn = changeTurn(turn);
		}
	}
}

void Game_Draw() {
	boardDraw();
	DrawFormatString(50, 50, GetColor(0, 0, 0), "�Q�[����ʂł�");
}

int getGameResult() {
	return gameResult;
}


int changeTurn(int turn) {
	return (turn % 2) + 1;
}

int getKey() {	//�L�[����if���Ŏ��
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
	return number;
}

void  boardDraw() {//�Ֆʕ`��
	int color;
	for (int y = 0; y < BOARD_SIZE; y++) {
		for (int x = 0; x < BOARD_SIZE; x++) {
			switch (myBoard.board[y][x]) {
			case 0:
				color = 0x000000;
				break;
			case 1:
				color = 0xFF0000;
				break;
			case 2:
				color = 0x00FF00;
				break;
			}
			int dx = BOARD_OFFSET_X + x * RECT_SIZE;
			int dy = BOARD_OFFSET_Y + y * RECT_SIZE;
			DrawBox(dx, dy, dx + RECT_SIZE, dy + RECT_SIZE, color, TRUE);
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
	if (x >= 0 && x <= BOARD_DRAW_SIZE &&
		y >= 0 && y <= BOARD_DRAW_SIZE) {
		//�g���ɓ����Ă���
		pos->x = x / RECT_SIZE;
		pos->y = y / RECT_SIZE;
		return TRUE;
	}
	return FALSE;
}


BOOL isClear(Board board, int turn) {//�N���A���Ă��邩�ǂ���
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


Pos cpuThink(Board board, int turn) {
	Pos pos;
	for (int i = 0; i < 2; i++) {//���ƂP�ŏ��Ă�p�^�[���T�������ƂP�ŕ�����p�^�[���T��
		for (int y = 0; y < BOARD_SIZE; y++) {
			for (int x = 0; x < BOARD_SIZE; x++) {
				if (isSetStone(board, x, y)) {
					Board tmp = board;
					tmp.board[y][x] = turn;
					if (isClear(tmp, turn)) {
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
	//�G���[�@�ǂ���u���Ȃ�
	pos.x = -1;
	pos.y = -1;
	return pos;
}

int isGameEnd() {
	//�Q�[�����I����Ă���Ȃ��
	if (isGameClear) {
		if (turn == PLAYER) {
			return 1;//PLAYER�̏���
		}
		else if (turn == COM) {
			return 2;//COM�̏���
		}		
	}

	if (isDrow(myBoard)) {//��������
		return 3;
	}
	return 0;
}