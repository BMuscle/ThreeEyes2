#include"DxLib.h"
#include"Game.h"
#include"SceneMgr.h"
#include"Result.h"

void Game_Initialize() {

}

void Game_Finalize() {

}

void Game_Update() {
	update();
	if (CheckHitKey(KEY_INPUT_R) == 1) {
		SceneMgr_ChangeScene(SCENE_RESULT);
		Result_Initialize(getGameResult());
	}
}

void Game_Draw() {
	draw();
	DrawFormatString(50, 50, GetColor(0, 0, 0), "ゲーム画面です");
}

int getGameResult() {
	int gameresult = 3;
	return gameresult;
}

struct Board
{
	int board[BOARD_SIZE][BOARD_SIZE];
};

struct Pos {
	int x, y;
};

Board myBoard;

int turn = 1;
bool isGameClear = false;
int a = 1;

void update() {   //計算関係
		//ゲームが終わっているならば
	if (isGameClear) {
		DrawFormatString(100, 100, 0xFFFFFF, "くりあ ");
		return;
	}

	//
	if (isDrow(myBoard)) {
		DrawFormatString(100, 100, 0xFFFFFF, "引き分け");
		return;
	}
	int key = getKey();
	if (key >= 0) {
		bool isSet = false;

		if (turn == 1) {
			int x, y;
			x = key % 3;
			y = key / 3;
			if (isSetStone(myBoard, x, y)) {
				myBoard.board[y][x] = turn;
				isSet = true;
			}

		}
		else {
			Pos pos = cpuThink(myBoard, turn);
			myBoard.board[pos.y][pos.x] = turn;
			isSet = true;

		}
		if (isSet) {	//ターンチェンジ
			if (isClear(myBoard, turn)) {
				isGameClear = true;
			}
			else {
				turn = (turn % 2) + 1;
			}
		}

	}



}

void draw() {    //描画関係
	boardDraw();

}

int getKey() {	//キー入力if文で取る
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

void boardDraw() {//描画
#define OFFSET_BOARD 20
	for (int y = 0; y < BOARD_SIZE; y++) {
		for (int x = 0; x < BOARD_SIZE; x++) {
			DrawFormatString(x * OFFSET_BOARD, y * OFFSET_BOARD, 0xFFFFFF, "%d ", myBoard.board[y][x]);
		}
	}
}



bool isClear(Board board, int turn) {//クリアしているかどうか
	for (int y = 0; y < BOARD_SIZE; y++) {
		if (board.board[y][0] == turn && board.board[y][1] == turn && board.board[y][2] == turn) {

			return true;
		}
	}

	for (int x = 0; x < BOARD_SIZE; x++) {
		if (board.board[0][x] == turn && board.board[1][x] == turn && board.board[2][x] == turn) {

			return true;
		}
	}

	if (board.board[0][0] == turn && board.board[1][1] == turn && board.board[2][2] == turn) {

		return true;
	}

	if (board.board[0][2] == turn && board.board[1][1] == turn && board.board[2][0] == turn) {

		return true;
	}

	return false;

}

bool isSetStone(Board board, int x, int y) { //置けるかどうか
	if (board.board[y][x] == 0) {
		return true;
	}

	return false;
}

bool isDrow(Board board) {  //引き分け判定
	int cnt = 0;
	for (int y = 0; y < BOARD_SIZE; y++) {
		for (int x = 0; x < BOARD_SIZE; x++) {
			if (isSetStone(board, x, y) == false) {
				cnt++;
			}

		}
	}

	if (cnt == 9) {
		return true;
	}

	return false;
}


Pos cpuThink(Board board, int turn) {
	Pos pos;
	for (int i = 0; i < 2; i++) {//あと１つで勝てるパターン探索→あと１つで負けるパターン探索
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
		turn = (turn % 2) + 1;
	}


	if (isSetStone(board, 1, 1)) {//真ん中
		pos.x = 1;
		pos.y = 1;
		return pos;
	}
	if (isSetStone(board, 0, 0)) {
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
	//エラー
	pos.x = -1;
	pos.y = -1;
	return pos;
}