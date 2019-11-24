#include"Game.h"


enum TURN {//ターン情報
	PLAYER = 1,
	COM = 2,
};

struct Board//盤面情報
{
	int board[BOARD_SIZE][BOARD_SIZE];
};

struct Pos {//盤面の座標情報
	int x, y;
};

static Sprite backSprite;	//背景画像
static Sprite frame;		//枠の画像
static Sprite maru;			//丸の画像
static Sprite batu;			//罰の画像

static Board myBoard;		//盤面情報
static TURN nowTurn;		//現在のターン情報
static BOOL isGameClear;	//ゲームがクリアされているかどうか
static int gameResult;		//ゲームの結果情報

static int startTime;

static int seChoke;//効果音　チョーク書く時
static int game_bgm;								//bgm用ハンドル


void Game_Initialize() {//初期化処理
	seChoke = LoadSoundMem("musics/choke6.wav");
	game_bgm = LoadSoundMem("musics/bgm_game.wav");
	ChangeVolumeSoundMem(70, game_bgm);
	PlaySoundMem(game_bgm, DX_PLAYTYPE_LOOP);
	nowTurn = (TURN)(GetRand(1) + 1);
	initLottery(nowTurn);
	isGameClear = FALSE;		//ゲームクリアフラグをOFF
	gameResult = 0;				//ゲームの結果初期化
	setCharacterMessage(CHAR_MG_START);
	setMessageFlag(TRUE);//メッセージ表示フラグON

	for (int y = 0; y < BOARD_SIZE; y++) {//board初期化
		for (int x = 0; x < BOARD_SIZE; x++) {
			myBoard.board[y][x] = 0;
		}
	}
	//画像の初期化
	backSprite = initSprite("images/gameback.png", 640, 480);
	frame = initSprite("images/flame.png", 300, 300);
	maru = initSprite("images/maru.png", 100, 100);
	batu = initSprite("images/batsu.png", 100, 100);
}

void Game_Finalize() {//終了処理
	//画像の消去
	deleteLottery();
	deleteSprite(&backSprite);
	deleteSprite(&frame);
	deleteSprite(&maru);
	deleteSprite(&batu);
	DeleteSoundMem(game_bgm);
	DeleteSoundMem(seChoke);
}

void Game_Update() {//計算処理
	if (getCurrentLoadState() > 0) {//ロード状態ならば
		if (isLoadEnd()) {//ロードが終わり次のシーンへの移行準備が整ったならば
			//シーン変更
			Game_Finalize();
			SceneMgr_ChangeScene(SCENE_RESULT);
			Result_Initialize(getGameResult());
		}
		return;	//ロード状態なので以降処理しない
	}
	updateLottery();
	if (isLotteryEnd() == FALSE) {
		startTime = GetNowCount();//ディレイのカウンタリセット		
		return;
	}
	gameResult = isGameEnd();
	if (gameResult > 0) {//ゲームが終わっているなら
		onLoadFlag(LOAD_ERASE);
		setMessageFlag(FALSE);//メッセージ表示フラグON
		return;
	}

	//ゲーム処理
	BOOL isSet = FALSE;//石を置いたかどうかフラグ

	if (nowTurn == PLAYER) {//プレイヤーの行動
		Pos pos;
		if (getLeftDown() == FALSE) { return; }		//入力チェック
		if (getMousePos(&pos) == FALSE) { return; }	//マウス入力 & 範囲チェック

		if (isSetStone(myBoard, pos.x, pos.y)) {	//石置けるかチェック
			myBoard.board[pos.y][pos.x] = nowTurn;	//置く
			isSet = TRUE;
			startTime = GetNowCount();//ディレイのカウンタリセット
		}
	}
	else if (nowTurn == COM && timeCnt()) {//コンピュータの行動
		Pos pos;
		switch (getCharacterType()) {
		case CHAR_EASY:
			pos = cpuThink3(myBoard, nowTurn);//コンピュータの手を計算し格納
			break;
		case CHAR_NORMAL:
			pos = cpuThink2(myBoard, nowTurn);//コンピュータの手を計算し格納
			break;
		case CHAR_DIF:
			pos = cpuThink1(myBoard, nowTurn);//コンピュータの手を計算し格納
			break;
		}
		
		myBoard.board[pos.y][pos.x] = nowTurn;//手通りに盤面に格納
		cpuUpdate();
		isSet = TRUE;
	}

	if (isSet) {//石置かれたなら エンドチェック&ターンチェンジ
		PlaySoundMem(seChoke, DX_PLAYTYPE_BACK);
		if (isWin(myBoard, nowTurn)) {//勝っている
			isGameClear = TRUE;//勝利フラグON
			if (nowTurn == PLAYER) {
				setCharacterExpression(CHAR_EX_LOSE);
			}
			else {
				setCharacterExpression(CHAR_EX_WIN);
			}
		}
		else {
			nowTurn = changeTurn(nowTurn);//ターンチェンジ
		}
	}
}

void Game_Draw() {//描画処理
	drawAtSprite(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, &backSprite, TRUE);//背景描画
	boardDraw();//盤面情報描画
	drawLottery();
}

int getGameResult() {//ゲームの結果を返す
	return gameResult;
}


TURN changeTurn(TURN turn) {//ターンチェンジ
	return (TURN)((turn % 2) + 1);
}

BOOL getKey(Pos *pos) {	//キー入力if文で取る　現在使用していない
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
		pos->x = number % BOARD_SIZE;
		pos->y = number / BOARD_SIZE;
		return TRUE;
	}
	return FALSE;
}

void  boardDraw() {//盤面描画
	drawSprite(BOARD_OFFSET_X, BOARD_OFFSET_Y, &frame, TRUE);//枠描画
	for (int y = 0; y < BOARD_SIZE; y++) {
		for (int x = 0; x < BOARD_SIZE; x++) {
			switch (myBoard.board[y][x]) {
			case 1://〇描画
				drawSprite(BOARD_OFFSET_X + x * RECT_WIDTH, BOARD_OFFSET_Y + y * RECT_HEIGHT, &maru, TRUE);
				break;
			case 2://×描画
				drawSprite(BOARD_OFFSET_X + x * RECT_WIDTH, BOARD_OFFSET_Y + y * RECT_HEIGHT, &batu, TRUE);
				break;
			}
		}
	}
}

void boardDrawString() {//盤面文字描画　デバッグ用
#define OFFSET_BOARD 20
	for (int y = 0; y < BOARD_SIZE; y++) {
		for (int x = 0; x < BOARD_SIZE; x++) {
			DrawFormatString(x * OFFSET_BOARD, y * OFFSET_BOARD, 0xFFFFFF, "%d ", myBoard.board[y][x]);
		}
	}
}

BOOL getMousePos(Pos* pos) {//マウスの入力座標取得
	int x,y;
	GetMousePoint(&x, &y);//マウスの座標取得
	x -= BOARD_OFFSET_X;//計算しやすいようマウスの基準を左上0に
	y -= BOARD_OFFSET_Y;//同上
	if (x >= 0 && x <= BOARD_WIDTH &&
		y >= 0 && y <= BOARD_HEIGHT) {
		//枠内に入っている
		pos->x = x / RECT_WIDTH;
		pos->y = y / RECT_HEIGHT;
		return TRUE;//正しく入力された
	}
	return FALSE;//入力失敗
}


BOOL isWin(Board board, TURN turn) {//クリアしているかどうか
	//縦並び判定
	for (int y = 0; y < BOARD_SIZE; y++) {
		if (board.board[y][0] == turn && board.board[y][1] == turn && board.board[y][2] == turn) {
			return TRUE;
		}
	}
	//横並び判定
	for (int x = 0; x < BOARD_SIZE; x++) {
		if (board.board[0][x] == turn && board.board[1][x] == turn && board.board[2][x] == turn) {
			return TRUE;
		}
	}
	//斜め判定
	if (board.board[0][0] == turn && board.board[1][1] == turn && board.board[2][2] == turn) {
		return TRUE;
	}

	if (board.board[0][2] == turn && board.board[1][1] == turn && board.board[2][0] == turn) {
		return TRUE;
	}
	return FALSE;
}

BOOL isSetStone(Board board, int x, int y) { //置けるかどうか
	if (board.board[y][x] == 0) {//石が無いなら
		return TRUE;
	}
	return FALSE;
}

BOOL isDrow(Board board) {  //引き分け判定 変更済み 石が置ける場所を発見したらreturnに変更
	for (int y = 0; y < BOARD_SIZE; y++) {
		for (int x = 0; x < BOARD_SIZE; x++) {
			if (isSetStone(board, x, y) == TRUE) {//石が置ける場所があった
				return FALSE;
			}
		}
	}
	return TRUE;
}


Pos cpuThink1(Board board, TURN turn) {//CPU手思考
	Pos pos{ -1, -1 };//範囲外エラー出るよう初期化
	for (int i = 0; i < 2; i++) {//あと１つで勝てるパターン探索→あと１つで負けるパターン探索
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

	//上の条件に当てはまらない場合　中央→角→辺の優先順位で手を打つ。

	if (isSetStone(board, 1, 1)) {//真ん中
		pos.x = 1;
		pos.y = 1;
		return pos;
	}
	if (isSetStone(board, 0, 0)) {//角
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

	for (int i = 0; i < 2; i++) {//あと１つで勝てるパターン探索→あと１つで負けるパターン探索
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


Pos cpuThink2(Board board, TURN turn) {//CPU手思考
	Pos pos{ -1, -1 };//範囲外エラー出るよう初期化
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

	if (isSetStone(board, 1, 1)) {//真ん中
		pos.x = 1;
		pos.y = 1;
		return pos;
	}
	if (isSetStone(board, 0, 0)) {//角
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



	for (int i = 0; i < 2; i++) {
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

Pos cpuThink3(Board board, TURN turn) {//CPU手思考
	Pos pos{ -1, -1 };//範囲外エラー出るよう初期化
	int rx = GetRand(2), ry = GetRand(2);
	if (isSetStone(board, rx, ry)) {
		pos.x = rx;
		pos.y = ry;
		return pos;
	}
	rx = GetRand(2), ry = GetRand(2);
	if (isSetStone(board, rx, ry)) {
		pos.x = rx;
		pos.y = ry;
		return pos;
	}


	for (int i = 0; i < 2; i++) {//あと１つで勝てるパターン探索→あと１つで負けるパターン探索
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
	//ゲームが終わっているならば
	if (isGameClear) {
		if (nowTurn == PLAYER) {
			setCharacterExpression(CHAR_EX_LOSE);
			setCharacterMessage(CHAR_MG_LOSE);//メッセージ変更
			return 1;//PLAYERの勝ち
		}
		else if (nowTurn == COM) {
			setCharacterExpression(CHAR_EX_WIN);
			setCharacterMessage(CHAR_MG_WIN);//メッセージ変更
			return 2;//COMの勝ち
		}		
	}

	if (isDrow(myBoard)) {//引き分け
		setCharacterExpression(CHAR_EX_NORMAL);
		setCharacterMessage(CHAR_MG_DRAW);//メッセージ変更
		return 3;
	}
	return 0;
}

BOOL timeCnt() {
	static int randTime = 1500;
	
	if (GetNowCount() - startTime > (randTime)) {
		startTime = GetNowCount();
		randTime = (rand() % 4) * 200 + 300;
		return TRUE;
	}
	return FALSE;
}
void cpuUpdate() {
	int ex = 0;//表情　勝ち1　負け2　優先は負け
	TURN turn = nowTurn;
	for (int i = 0; i < 2; i++) {//あと１つで勝てるパターン探索→あと１つで負けるパターン探索
		for (int y = 0; y < BOARD_SIZE; y++) {
			for (int x = 0; x < BOARD_SIZE; x++) {
				if (isSetStone(myBoard, x, y)) {
					Board tmp =myBoard;
					tmp.board[y][x] = turn;
					if (isWin(tmp, turn)) {
						ex = i + 1;//更新
					}
				}
			}
		}
		turn = changeTurn(turn);
	}

	switch (ex) {
	case 0:
		setCharacterExpression(CHAR_EX_NORMAL);
		setCharacterMessage(CHAR_MG_NORMAL);//メッセージ変更
		break;
	case 1:
		setCharacterExpression(CHAR_EX_WINNING);
		setCharacterMessage(CHAR_MG_WINNING);//メッセージ変更
		break;
	case 2:
		setCharacterExpression(CHAR_EX_LOSING);
		setCharacterMessage(CHAR_MG_LOSING);//メッセージ変更
		break;
	}
}