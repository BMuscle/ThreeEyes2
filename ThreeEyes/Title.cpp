#include"DxLib.h"
#include"Title.h"
#include"SceneMgr.h"

int Title;
int game_x, end_x;			//font�`��px���W
int upBox_x1, upBox_x2;		//Box�`��px���W(�Q�[���J�n�̔�)
int downBox_x1, downBox_x2;	//Box�`��px���W(�I���̔�)
int Mousex, Mousey;			//�}�E�X��x,y���W
int MouseInput;				//�}�E�X�̔���p�ϐ�;
int upBoxColor1, upBoxColor2;	//Box�̐F
int upBcolorG,downBcolorG;		//�}�E�X�̃J�[�\�����Q�[���J�n�ƏI���ɍ��킹�����A�ΐF�ɂ��邽�߂̕ϐ�

void Title_Initialize() {
	Title = LoadGraph("images/title.png");
	game_x = 100, end_x = 100;
	upBox_x1 = 90, upBox_x2 = 200;
	downBox_x1 = 90, downBox_x2 = 200;
}

void Title_Finalize() {
	DeleteGraph(Title);
	MouseInput = 0;
}

void Title_Update() {
	GetMousePoint(&Mousex, &Mousey);
	Title_Select();
	MouseInput = GetMouseInput();
	if (CheckHitKey(KEY_INPUT_RETURN ) && game_x == 75 ) {
		Title_Finalize();
		SceneMgr_ChangeScene(SCENE_GAME);
	}
}

void Title_Draw() {
	DrawGraph(50, 50, Title, FALSE);				//�摜�\��t��
	DrawBox(upBox_x1,240,upBox_x2,280,upBoxColor1,FALSE);		//�Q�[���J�n�̘g
	DrawBox(downBox_x1, 340, downBox_x2, 380, upBoxColor2, FALSE);		//�I���̘g
	DrawFormatString(game_x, 250, GetColor(0, 0, 0), "�Q�[���J�n");		
	DrawFormatString(end_x, 350, GetColor(0, 0, 0), "�I��");
	Title_StartMouseSelect();
	Title_EndMouseSelect();
}

void Title_Select() {
	if (CheckHitKey(KEY_INPUT_UP)) {	//��{�^�����������Ƃ��ɃQ�[���J�n�Ƃ��̘g�����ɏ������炷
		game_x = 75;
		end_x = 100;
		upBox_x1 = 65;
		upBox_x2 = 175;
		downBox_x1 = 90;
		downBox_x2 = 200;
	}
	if (CheckHitKey(KEY_INPUT_DOWN)) {	//���{�^���������l
		game_x = 100;
		end_x = 75;
		upBox_x1 = 90;
		upBox_x2 = 200;
		downBox_x1 = 65;
		downBox_x2 = 175;
	}

}

void Title_StartMouseSelect() {				//�Q�[���J�n�̕��̘g�̐F�ς���֐��A������
	if (Mousey >= 240 && Mousey <= 280 && Mousex >= upBox_x1 && Mousex <= upBox_x2) {//�Q�[���J�n�̘g�̐F�ύX
		upBcolorG = 255;
		if ((MouseInput & MOUSE_INPUT_LEFT) != 0) {
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
	if (Mousey >= 340 && Mousey <= 380 && Mousex >= downBox_x1 && Mousex <= downBox_x2) {//�Q�[���J�n�̘g�̐F�ύX
		downBcolorG = 255;
		if ((MouseInput & MOUSE_INPUT_LEFT) != 0) {
			/*�����ɃQ�[���I��������`��*/
		}
	}
	else {
		downBcolorG = 0;
	}

	upBoxColor2 = GetColor(0, downBcolorG, 0);
}

