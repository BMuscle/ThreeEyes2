#pragma once
#include"DxLib.h"
#include "MyWindow.h"
#include "MyMouse.h"
#define RECT_WIDTH 100
#define RECT_HEIGHT 100
#define BOARD_SIZE 3

#define BOARD_WIDTH (RECT_WIDTH * BOARD_SIZE)
#define BOARD_HEIGHT (RECT_HEIGHT * BOARD_SIZE)

#define BOARD_OFFSET_X ((WINDOW_WIDTH / 2) - (RECT_WIDTH * BOARD_SIZE / 2))
#define BOARD_OFFSET_Y ((WINDOW_HEIGHT / 2) - (RECT_HEIGHT * BOARD_SIZE /2))

struct Board;
struct Pos;
enum TURN;

void Game_Initialize(void);
void Game_Finalize(void);
void Game_Update(void);
void Game_Draw(void);



void boardDraw(void);//画像で盤面描画
void boardDrawString(void);//文字で盤面描画

BOOL getKey(Pos *pos);//ボード上の座標取得　要修正
BOOL getMousePos(Pos *pos);//ボード上マウス座標取得

BOOL isSetStone(Board board, int x, int y);//石が置けるか？
BOOL isWin(Board board, TURN turn);//勝っている？
BOOL isDrow(Board board);//引き分け？

Pos cpuThink(Board board, TURN turn);//CPUの手　計算

int getGameResult(void);
int isGameEnd(void);
TURN changeTurn(TURN turn);