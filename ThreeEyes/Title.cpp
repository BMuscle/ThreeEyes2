#include"DxLib.h"
#include"Title.h"
#include"SceneMgr.h"
#include"MyMouse.h"
#include"MassageBox.h"
#include "LoadEffect.h"

#define BUTTON_W 300				//�摜�̕��w��p�}�N��
#define BUTTON_H 60					//�摜�̍����w��̃}�N��

static Sprite backSprite;
static int Title;					//�^�C�g���p�̃n���h��
static int title_enter_SE, title_select_SE;		//���p�n���h��
static int Mousex, Mousey;			//�}�E�X��x,y���W
static int Font00;					//�t�H���g�w��p�̃n���h��
static int startSelect, endSelect;		//SE�Ǘ��p�̕ϐ�
static int title_bgm;					//bgm�p�̃n���h��

static Sprite startButton[1];			//�摜�̃n���h��
static Sprite endButton[1];



void Title_Initialize() {
	Font00 = CreateFontToHandle("�S�V�b�N", 15, 6, DX_FONTTYPE_ANTIALIASING);
	backSprite = initSprite("images/titleback3.png", 640, 480);
	Title = LoadGraph("images/title.png");
	title_enter_SE = LoadSoundMem("musics/enter_ou.wav");
	title_select_SE = LoadSoundMem("musics/select_or_enter.wav");
	title_bgm = LoadSoundMem("musics/bgm_title.wav");
	ChangeVolumeSoundMem(255 * 40 / 100, title_bgm);
	PlaySoundMem(title_bgm, DX_PLAYTYPE_LOOP);

	startButton[FALSE]= initSprite("images/button/Title_start1.png", BUTTON_W, BUTTON_H);
	startButton[TRUE] = initSprite("images/button/Title_start2.png", BUTTON_W, BUTTON_H);
	endButton[FALSE] = initSprite("images/button/Title_end1.png", BUTTON_W, BUTTON_H);
	endButton[TRUE] = initSprite("images/button/Title_end2.png", BUTTON_W, BUTTON_H);

	startSelect = 0;
	endSelect = 0;
}

void Title_Finalize() {
	DeleteGraph(Title);						//�摜�̊J������
	deleteSprite(&backSprite);
	DeleteSoundMem(title_bgm);
}

void Title_Update() {
	if (getCurrentLoadState() > 0) {
		if (isLoadEnd()) {
			Title_Finalize();
			SceneMgr_ChangeScene(SCENE_DIFFICULTY);
		}
		return;
	}
	GetMousePoint(&Mousex, &Mousey);
	Title_StartMouseSelect();
	Title_EndMouseSelect();
}

void Title_Draw() {
	drawAtSprite(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, &backSprite, TRUE);
	DrawGraph(50, 50, Title, FALSE);		
	for (int i = 0; i < 2; i++) {					//startSelect��endSelect���ς��Ɖ摜���ς��
		drawSprite(300, 240 , &startButton[startSelect], TRUE);
		drawSprite(300, 360, &endButton[endSelect], TRUE);
	}
	
}

										//�J�[�\�����J�n�ɍ��킹��ƌ��鏈��
void Title_StartMouseSelect() {			//x��y��ł��͋����Ă�������	
	if (Mousex >= 300 && Mousex <= 300 + startButton[0].width 
		&& Mousey >= 240 && Mousey <=240 + startButton[0].height) {
		if (startSelect == 0) {			//SE�Ǘ��p��IF��
			PlaySoundMem(title_select_SE, DX_PLAYTYPE_BACK);
			startSelect = 1;
		}
		if ( getLeftDown() != 0) {
			PlaySoundMem(title_enter_SE, DX_PLAYTYPE_BACK);
			onLoadFlag(LOAD_FLUSH);
		}
	}
	else {
		startSelect = 0;
	}
	
}
										//�J�[�\�����I���ɍ��킹��ƌ��鏈��
void Title_EndMouseSelect() {			//x��y��ł��͋����Ă�������
	if (Mousex >= 300 && Mousex <= 300 + startButton[0].width
		&& Mousey >= 360 && Mousey <= 360 + startButton[0].height) {
		if (endSelect == 0) {
			PlaySoundMem(title_select_SE, DX_PLAYTYPE_BACK);
			endSelect = 1;
		}
		if (getLeftDown() != 0) {
			PlaySoundMem(title_enter_SE, DX_PLAYTYPE_BACK);
			setMainEndFlag(TRUE);
			Title_Finalize();
		}
	}
	else {
		endSelect = 0;
	}
}