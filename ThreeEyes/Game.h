#pragma once
#include"DxLib.h"

void Game_Initialize();
void Game_Finalize();
void Game_Update();	
void Game_Draw();


#define BOARD_SIZE 3

struct Board;
struct Pos;

void update(void);
void draw(void);

void boardDraw(void);
int getKey(void);
bool isClear(Board board, int turn);
bool isSetStone(Board board, int x, int y);
bool isDrow(Board board);

Pos cpuThink(Board board, int turn);

int getGameResult();