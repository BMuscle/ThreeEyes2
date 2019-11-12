#include"DxLib.h"
#include"Result.h"
#include"SceneMgr.h"


int resultImg; //�摜�n���h���l
int coutinueBox_x1, coutinueBox_x2, coutinueBox_y1, coutinueBox_y2;	//coutinue�{�b�N�X���W
int endBox_x1, endBox_x2, endBox_y1, endBox_y2;						//end�{�b�N�X���W
int string_y1, string_y2;
int nextSelect = 0;		//���̉�ʂ��ǂ����邩�̐��l������

void Result_Initialize(int winlose) {	//winlose��1�Ȃ珟���A2�Ȃ畉���A3�Ȃ��������
	if (winlose == 1) {
		//�����̎��̏���
		resultImg = LoadGraph("images/win.png");
		winlose = 0;
	}
	else if(winlose == 2){
		//�����̎��̏���
		resultImg = LoadGraph("images/lose.png");
		winlose = 0;
	}
	else {
		//���������̏���
		resultImg = LoadGraph("images/draw.png");
		winlose = 0;
	}
	
	//coutinue�{�b�N�X�����l
	coutinueBox_x1 = 100; coutinueBox_x2 = 210;
	coutinueBox_y1 = 350; coutinueBox_y2 = 390;

	//end�{�b�N�X�����l
	endBox_x1 = 400; endBox_x2 = 510;
	endBox_y1 = 350; endBox_y2 = 390;

	//��������W�����l
	string_y1 = string_y2 = 360;
}

void Result_Finalize() {
	DeleteGraph(resultImg);
	nextSelect = 0;
}

void Result_Update() {
	Result_Select();
	if (CheckHitKey(KEY_INPUT_RETURN) == 1) {
		if (nextSelect == 1) {
			//�Q�[����ʂ�
			Result_Finalize();
			SceneMgr_ChangeScene(SCENE_GAME);
		}
		else if (nextSelect == 2) {
			//�^�C�g����ʂ�
			Result_Finalize();
			SceneMgr_ChangeScene(SCENE_TITLE);
		}
	}
}

void Result_Select()
{
	if (CheckHitKey(KEY_INPUT_RIGHT)) {
		coutinueBox_y1 = 350;
		coutinueBox_y2 = 390;
		endBox_y1 = 330;
		endBox_y2 = 370;
		string_y1 = 360;
		string_y2 = 340;
		nextSelect = 2;
	}
	if (CheckHitKey(KEY_INPUT_LEFT)) {
		coutinueBox_y1 = 330;
		coutinueBox_y2 = 370;
		endBox_y1 = 350;
		endBox_y2 = 390;
		string_y1 = 340;
		string_y2 = 360;
		nextSelect = 1;
	}
}

void Result_Draw() {
	DrawGraph(200, 50, resultImg, FALSE);
	DrawBox(coutinueBox_x1, coutinueBox_y1, coutinueBox_x2, coutinueBox_y2, GetColor(0, 0, 0), FALSE);
	DrawBox(endBox_x1, endBox_y1, endBox_x2, endBox_y2, GetColor(0, 0, 0), FALSE);
	DrawFormatString(130, string_y1, GetColor(0, 0, 0), "������");
	DrawFormatString(430, string_y2, GetColor(0, 0, 0), "��߂�");
}