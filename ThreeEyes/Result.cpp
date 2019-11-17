#include"DxLib.h"
#include"Result.h"
#include"SceneMgr.h"
#include "Sprite.h"
#include "MyWindow.h"

static Sprite backSprite;
int coutinueBox_x1, coutinueBox_x2, coutinueBox_y1, coutinueBox_y2;	//coutinue�{�b�N�X���W
int endBox_x1, endBox_x2, endBox_y1, endBox_y2;						//end�{�b�N�X���W
int string_y1, string_y2;
int nextSelect = 0;		//���̉�ʂ��ǂ����邩�̐��l������

int resultImg;					//�摜�n���h���l
int colorBox1, colorBox2;		//�}�E�X�I�����Ƀ{�b�N�X�̐F��ύX����
int resultMousex, resultMousey;	//�}�E�X���W������ϐ�
int resultMouseInput;			//�}�E�X�̓��͏��
int coutinue_fclor, end_fcolor;	//�{�b�N�X���̕����F

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


	//���̐F�ݒ�
	colorBox1 = GetColor(0, 255, 0);
	colorBox2 = GetColor(0, 0, 0);

	//�����F�ݒ�
	coutinue_fclor = GetColor(0, 0, 0);
	end_fcolor = GetColor(0, 0, 0);

	nextSelect = SCENE_NONE;
}

void Result_Finalize() {
	DeleteGraph(resultImg);
	nextSelect = 0;
	resultMouseInput = 0;
}

void Result_Update() {
	GetMousePoint(&resultMousex, &resultMousey);
	Result_Select();
	resultMouseInput = GetMouseInput();
	if (CheckHitKey(KEY_INPUT_RETURN) == 1) {
		if (nextSelect == SCENE_GAME) {
			//�Q�[����ʂ�
			Result_Finalize();
			SceneMgr_ChangeScene(SCENE_GAME);
		}
		else if (nextSelect == SCENE_TITLE) {
			//�^�C�g����ʂ�
			Result_Finalize();
			SceneMgr_ChangeScene(SCENE_TITLE);
		}
	}
}

void Result_Select()
{
	if (CheckHitKey(KEY_INPUT_RIGHT)) {
		coutinue_fclor = GetColor(0, 0, 0);
		end_fcolor = GetColor(255, 0, 0);
		nextSelect = SCENE_TITLE;
	}
	if (CheckHitKey(KEY_INPUT_LEFT)) {
		coutinue_fclor = GetColor(255, 0, 0);
		end_fcolor = GetColor(0, 0, 0);
		nextSelect = SCENE_GAME;
	}
}

void Result_Draw() {
	drawAtSprite(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, &backSprite, TRUE);
	DrawGraph(200, 50, resultImg, FALSE);
	DrawBox(90, 370, 190, 410, colorBox1, FALSE);
	DrawBox(390, 370, 490, 410, colorBox2, FALSE);
	DrawFormatString(115, 380, coutinue_fclor, "������");
	DrawFormatString(415, 380, end_fcolor, "��߂�");
	Result_EndMouseSelect();
}

void Result_EndMouseSelect()
{
	//���̃{�b�N�X
	if (resultMousex >= 90 && resultMousex <= 190 && resultMousey >= 370 && resultMousey <= 410) {
		//�F��ς��鏈��
		colorBox1 = GetColor(0, 255, 0);
		if ((resultMouseInput & MOUSE_INPUT_LEFT) != 0) {
			Result_Finalize();
			SceneMgr_ChangeScene(SCENE_GAME);
		}
	}
	else {
		colorBox1 = GetColor(0, 0, 0);

	}

	//�E�̃{�b�N�X
	if (resultMousex >= 390 && resultMousex <= 490 && resultMousey >= 370 && resultMousey <= 410) {
		//�F��ς��鏈��
		colorBox2 = GetColor(0, 255, 0);
		if ((resultMouseInput & MOUSE_INPUT_LEFT) != 0) {
			Result_Finalize();
			SceneMgr_ChangeScene(SCENE_TITLE);
		}
	}
	else {
		colorBox2 = GetColor(0, 0, 0);
	}
}