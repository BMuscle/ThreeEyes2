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



void boardDraw(void);//�摜�ŔՖʕ`��
void boardDrawString(void);//�����ŔՖʕ`��

BOOL getKey(Pos *pos);//�{�[�h��̍��W�擾�@�v�C��
BOOL getMousePos(Pos *pos);//�{�[�h��}�E�X���W�擾

BOOL isSetStone(Board board, int x, int y);//�΂��u���邩�H
BOOL isWin(Board board, TURN turn);//�����Ă���H
BOOL isDrow(Board board);//���������H

Pos cpuThink(Board board, TURN turn);//CPU�̎�@�v�Z

int getGameResult(void);
int isGameEnd(void);
TURN changeTurn(TURN turn);