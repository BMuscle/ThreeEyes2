#include"DxLib.h"
#include"Title.h"
#include"SceneMgr.h"
#include"MyMouse.h"
#include"MassageBox.h"

int Title;					//�^�C�g���p�̃n���h��
int SEnter, SSelect;		//���p�n���h��
int Mousex, Mousey;			//�}�E�X��x,y���W
int Font00;					//�t�H���g�w��p�̃n���h��
static int startSelect, endSelect;		//�}�E�X�̑I�𔻒�p

MassageBox startGame;
MassageBox endGame;

void Title_Initialize() {
	Font00 = CreateFontToHandle("�S�V�b�N", 15, 6, DX_FONTTYPE_ANTIALIASING);
	Title = LoadGraph("images/title.png");
	SEnter = LoadSoundMem("music/enter1.wav");
	SSelect = LoadSoundMem("music/select1.wav");
	startGame = initMassageBox("images/enpitu.png", "�Q�[���J�n", GetColor(0, 0, 0), Font00, 180, 370, 170, 60);
	endGame = initMassageBox("images/enpitu.png", "�I��", GetColor(0, 0, 0), Font00, 480, 370, 170, 60);
	startSelect = 0;
	endSelect = 0;
	startGame.mystr.alpha = 255 * 0.5;
	endGame.mystr.alpha = 255 * 0.5;
}

void Title_Finalize() {
	DeleteGraph(Title);
}

void Title_Update() {
	GetMousePoint(&Mousex, &Mousey);
	Title_StartMouseSelect();
	Title_EndMouseSelect();
}

void Title_Draw() {
	DrawGraph(50, 50, Title, FALSE);		//�摜�\��t��
	drawAtMassageBox(&startGame,TRUE);
	drawAtMassageBox(&endGame, TRUE);
	
}


void Title_StartMouseSelect() {				//�Q�[���J�n�̕��̘g�̐F�ς���֐��A������
	if (Mousex >= startGame.mystr.x-startGame.sprite.width / 2 + 10&& Mousex <= startGame.mystr.x + startGame.sprite.width / 2 - 30
		&& Mousey >= startGame.mystr.y - startGame.sprite.height / 2 + 10 && Mousey <= startGame.mystr.y + startGame.sprite.height / 2 - 10) {//�Q�[���J�n�̘g�̐F�ύX
		startGame.mystr.color = 0xff0000;
		if (startSelect == 0) {
			PlaySoundMem(SSelect, DX_PLAYTYPE_BACK);
			startSelect = 1;
		}
		if ( getLeftDown() != 0) {
			PlaySoundMem(SEnter, DX_PLAYTYPE_BACK);
			Title_Finalize();
			SceneMgr_ChangeScene(SCENE_GAME);
		}
	}
	else {
		startGame.mystr.color = 0x000000;
		startSelect = 0;
	}
	
}

void Title_EndMouseSelect() {
	if (Mousex >= endGame.mystr.x - endGame.sprite.width / 2 + 10 && Mousex <= endGame.mystr.x + endGame.sprite.width / 2 - 30
		&& Mousey >= endGame.mystr.y - endGame.sprite.height / 2 + 10 && Mousey <= endGame.mystr.y + endGame.sprite.height / 2 - 10) {//�Q�[���J�n�̘g�̐F�ύX
		endGame.mystr.color = 0xff0000;
		if (endSelect == 0) {
			PlaySoundMem(SSelect, DX_PLAYTYPE_BACK);
			endSelect = 1;
		}
		if ( getLeftDown() != 0) {
			PlaySoundMem(SEnter, DX_PLAYTYPE_BACK);
			/*�����ɃQ�[���I��������`��*/
			DxLib_End();
			
		}
	}
	else {
		endGame.mystr.color = 0x000000;
		endSelect = 0;
	}

}

