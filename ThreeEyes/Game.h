#pragma once
#include"DxLib.h"
#include "MyWindow.h"
#include "MyMouse.h"

void Game_Initialize();
void Game_Finalize();
void Game_Update();	
void Game_Draw();


#define RECT_SIZE 100
#define BOARD_SIZE 3

#define BOARD_DRAW_SIZE (RECT_SIZE * BOARD_SIZE)

#define BOARD_OFFSET_X ((WINDOW_WIDTH / 2) - (RECT_SIZE + RECT_SIZE / 2))
#define BOARD_OFFSET_Y ((WINDOW_HEIGHT / 2) - (RECT_SIZE + RECT_SIZE / 2))

struct Board;
struct Pos;

int changeTurn(int turn);

void boardDraw(void);//画像で盤面描画
void boardDrawString(void);//文字で盤面描画
int getKey(void);//ボード上の座標取得　要修正
BOOL getMousePos(Pos *pos);//ボード上マウス座標取得

BOOL isSetStone(Board board, int x, int y);//石が置けるか？
BOOL isClear(Board board, int turn);//勝っている？
BOOL isDrow(Board board);//引き分け？

Pos cpuThink(Board board, int turn);//CPUの手　計算

int getGameResult(void);
int isGameEnd(void);