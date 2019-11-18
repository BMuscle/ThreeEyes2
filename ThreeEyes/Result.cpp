#include"DxLib.h"
#include"Result.h"
#include"SceneMgr.h"
#include "Sprite.h"
#include "MyWindow.h"
#include "MyMouse.h"
#include "MassageBox.h"

static Sprite backSprite;
int nextSelect = 0;		//���̉�ʂ��ǂ����邩�̐��l������

static int resultImg;					//�摜�n���h���l
static int resultMousex, resultMousey;	//�}�E�X���W������ϐ�

static int fontResult;		//�t�H���g�p�n���h��

static MassageBox startGame;
static MassageBox endGame;



void Result_Initialize(int winlose) {	//winlose��1�Ȃ珟���A2�Ȃ畉���A3�Ȃ��������
	backSprite = initSprite("images/1blackboard.png", 640, 480);
	if (winlose == 1) {
		//�����̎��̏���
		resultImg = LoadGraph("images/win.png");
		winlose = 0;
	}
	else if (winlose == 2) {
		//�����̎��̏���
		resultImg = LoadGraph("images/lose.png");
		winlose = 0;
	}
	else {
		//���������̏���
		resultImg = LoadGraph("images/draw.png");
		winlose = 0;
	}

	fontResult = CreateFontToHandle("�S�V�b�N", 15, 6, DX_FONTTYPE_ANTIALIASING);
	startGame = initMassageBox("images/enpitu.png", "������", GetColor(0, 0, 0), fontResult, 180, 370, 170, 60);
	endGame = initMassageBox("images/enpitu.png", "�I��", GetColor(0, 0, 0), fontResult, 480, 370, 170, 60);



	nextSelect = SCENE_NONE;
	startGame.mystr.alpha = 255 * 0.5;
	endGame.mystr.alpha = 255 * 0.5;
}

void Result_Finalize() {
	DeleteGraph(resultImg);
	nextSelect = 0;
}

void Result_Update() {
	GetMousePoint(&resultMousex, &resultMousey);
}


void Result_Draw() {
	drawAtSprite(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, &backSprite, TRUE);
	DrawGraph(200, 50, resultImg, FALSE);
	drawAtMassageBox(&startGame, TRUE);
	drawAtMassageBox(&endGame, TRUE);
	Result_EndMouseSelect();
}

void Result_StartMouseSelect()
{
	//���̃{�b�N�X
	if (resultMousex >= 90 && resultMousex <= 190 && resultMousey >= 370 && resultMousey <= 410) {
		
	}
	else {


	}
}

void Result_EndMouseSelect()
{
	//�E�̃{�b�N�X
	if (resultMousex >= 390 && resultMousex <= 490 && resultMousey >= 370 && resultMousey <= 410) {
		
	}
	else {

	}
}