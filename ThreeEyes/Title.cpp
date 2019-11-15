#include"DxLib.h"
#include"Title.h"
#include"SceneMgr.h"

int Title;
int SEnter, SSelect;		//���p�n���h��
int game_y, end_y;			//font�`��py���W
int upBox_y1, upBox_y2;		//Box�`��py���W(�Q�[���J�n�̔�)
int downBox_y1, downBox_y2;	//Box�`��py���W(�I���̔�)
int Mousex, Mousey;			//�}�E�X��x,y���W
int MouseInput;				//�}�E�X�̔���p�ϐ�;
int upBoxColor1, upBoxColor2;	//Box�̐F
int upBcolorG, downBcolorG;		//�}�E�X�̃J�[�\�����Q�[���J�n�ƏI���ɍ��킹�����A�ΐF�ɂ��邽�߂̕ϐ�
int gameFontR, endFontR;		//�Q�[���J�n�ƏI���̕����̃t�H���g��Red�̐F

void Title_Initialize() {
	Title = LoadGraph("images/title.png");
	SEnter = LoadSoundMem("music/enter1.wav");
	SSelect = LoadSoundMem("music/select1.wav");
	game_y = 380, end_y = 380;
	upBox_y1 = 370, upBox_y2 = 410;
	downBox_y1 = 370, downBox_y2 = 410;
	gameFontR = 0; endFontR = 0;
}

void Title_Finalize() {
	DeleteGraph(Title);
	MouseInput = 0;
}

void Title_Update() {
	GetMousePoint(&Mousex, &Mousey);
	Title_Select();
	MouseInput = GetMouseInput();
	if (CheckHitKey(KEY_INPUT_RETURN) && gameFontR == 255) {
		PlaySoundMem(SEnter, DX_PLAYTYPE_NORMAL);
		Title_Finalize();
		SceneMgr_ChangeScene(SCENE_GAME);
	}
}

void Title_Draw() {
	DrawGraph(50, 50, Title, FALSE);				//�摜�\��t��
	DrawBox(90, upBox_y1, 190, upBox_y2, upBoxColor1, FALSE);		//�Q�[���J�n�̘g
	DrawBox(390, downBox_y1, 490, downBox_y2, upBoxColor2, FALSE);		//�I���̘g
	DrawFormatString(100, game_y, GetColor(gameFontR, 0, 0), "�Q�[���J�n");
	DrawFormatString(400, end_y, GetColor(endFontR, 0, 0), "�I��");
	Title_StartMouseSelect();
	Title_EndMouseSelect();
}

void Title_Select() {
	if (CheckHitKey(KEY_INPUT_LEFT) && gameFontR == 0) {	//���{�^�����������Ƃ��ɃQ�[���J�n�̃t�H���g�̐F��ԐF�ɂ���
		PlaySoundMem(SSelect, DX_PLAYTYPE_BACK);
		gameFontR = 255;
		endFontR = 0;
	}
	if (CheckHitKey(KEY_INPUT_RIGHT) && endFontR == 0) {	//�E�{�^���������l
		PlaySoundMem(SSelect, DX_PLAYTYPE_BACK);
		gameFontR = 0;
		endFontR = 255;
	}

}

void Title_StartMouseSelect() {				//�Q�[���J�n�̕��̘g�̐F�ς���֐��A������
	if (Mousex >= 90 && Mousex <= 190 && Mousey >= upBox_y1 && Mousey <= upBox_y2) {//�Q�[���J�n�̘g�̐F�ύX
		upBcolorG = 255;
		if ((MouseInput & MOUSE_INPUT_LEFT) != 0) {
			PlaySoundMem(SEnter, DX_PLAYTYPE_BACK);
			Title_Finalize();
			SceneMgr_ChangeScene(SCENE_GAME);
		}
	}
	else {
		upBcolorG = 0;
	}
	upBoxColor1 = GetColor(0, upBcolorG, 0);
}

void Title_EndMouseSelect() {
	if (Mousex >= 390 && Mousex <= 490 && Mousey >= downBox_y1 && Mousey <= downBox_y2) {//�Q�[���J�n�̘g�̐F�ύX
		downBcolorG = 255;
		if ((MouseInput & MOUSE_INPUT_LEFT) != 0) {
			PlaySoundMem(SEnter, DX_PLAYTYPE_BACK);
			/*�����ɃQ�[���I��������`��*/
		}
	}
	else {
		downBcolorG = 0;
	}

	upBoxColor2 = GetColor(0, downBcolorG, 0);
}

