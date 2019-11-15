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

void boardDraw(void);//�摜�ŔՖʕ`��
void boardDrawString(void);//�����ŔՖʕ`��
int getKey(void);//�{�[�h��̍��W�擾�@�v�C��
BOOL getMousePos(Pos *pos);//�{�[�h��}�E�X���W�擾

BOOL isSetStone(Board board, int x, int y);//�΂��u���邩�H
BOOL isClear(Board board, int turn);//�����Ă���H
BOOL isDrow(Board board);//���������H

Pos cpuThink(Board board, int turn);//CPU�̎�@�v�Z

int getGameResult(void);
int isGameEnd(void);