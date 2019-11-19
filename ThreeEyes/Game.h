#pragma once
#include"DxLib.h"
#include "MyWindow.h"
#include "MyMouse.h"
#define RECT_WIDTH 100	//�P�}�X�̕�
#define RECT_HEIGHT 100	//�P�}�X�̍���
#define BOARD_SIZE 3 //�Ֆʂ̂P�����̃}�X�̐�

#define BOARD_WIDTH (RECT_WIDTH * BOARD_SIZE)	//�Ֆʂ̕�
#define BOARD_HEIGHT (RECT_HEIGHT * BOARD_SIZE) //�Ֆʂ̍���

#define BOARD_OFFSET_X ((WINDOW_WIDTH / 2) - (RECT_WIDTH * BOARD_SIZE / 2)) //�Ֆʂ̍���N�_X
#define BOARD_OFFSET_Y ((WINDOW_HEIGHT / 2) - (RECT_HEIGHT * BOARD_SIZE /2))//�Ֆʂ̍���N�_Y

struct Board;	//�Ֆʏ��̍\����	
struct Pos;		//�Ֆʂ̍��W���̍\����
enum TURN;		//�^�[�����̗񋓌^

void Game_Initialize(void);	//�Q�[���̏���������
void Game_Finalize(void);	//�Q�[���̏I������
void Game_Update(void);		//�Q�[���̌v�Z����
void Game_Draw(void);		//�Q�[���̕`�揈��



void boardDraw(void);//�摜�ŔՖʕ`��
void boardDrawString(void);//�����ŔՖʕ`��

BOOL getKey(Pos *pos);//�{�[�h��̍��W�擾�@�v�C��
BOOL getMousePos(Pos *pos);//�{�[�h��}�E�X���W�擾

BOOL isSetStone(Board board, int x, int y);//�΂��u���邩�H
BOOL isWin(Board board, TURN turn);//�����Ă���H
BOOL isDrow(Board board);//���������H

Pos cpuThink(Board board, TURN turn);//CPU�̎�@�v�Z

int getGameResult(void);//�Q�[���̏����������������̌��ʂ��󂯎��
int isGameEnd(void);	//�Q�[�����I����Ă��邩����
TURN changeTurn(TURN turn);//�^�[������シ��

void timeCnt(void);  //cpu�̎v�l����