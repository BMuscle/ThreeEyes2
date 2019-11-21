#include"DxLib.h"
#include"Title.h"
#include"SceneMgr.h"
#include"MyMouse.h"
#include"MassageBox.h"
#include "LoadEffect.h"

static Sprite backSprite;
static int Title;					//�^�C�g���p�̃n���h��
static int title_enter_SE, title_select_SE;		//���p�n���h��
static int Mousex, Mousey;			//�}�E�X��x,y���W
static int Font00;					//�t�H���g�w��p�̃n���h��
static int startSelect, endSelect;		//SE�Ǘ��p�̕ϐ�
static int title_bgm;					//bgm�p�̃n���h��

static MassageBox startGame;
static MassageBox endGame;

void Title_Initialize() {
	Font00 = CreateFontToHandle("�S�V�b�N", 15, 6, DX_FONTTYPE_ANTIALIASING);
	backSprite = initSprite("images/titleback.png", 640, 480);
	Title = LoadGraph("images/title.png");
	title_enter_SE = LoadSoundMem("musics/enter_ou.wav");
	title_select_SE = LoadSoundMem("musics/select_or_enter.wav");
	title_bgm = LoadSoundMem("musics/bgm_title.wav");
	ChangeVolumeSoundMem( 255 * 40 / 100 ,title_bgm);
	PlaySoundMem(title_bgm,DX_PLAYTYPE_LOOP);

	startGame = initMassageBox("images/enpitu.png", "�Q�[���J�n", GetColor(0, 0, 0), Font00, 180, 370, 170, 60);
	endGame = initMassageBox("images/enpitu.png", "�I��", GetColor(0, 0, 0), Font00, 480, 370, 170, 60);
	startSelect = 0;
	endSelect = 0;
	startGame.mystr.alpha = 255 * 0.5;
	endGame.mystr.alpha = 255 * 0.5;
}

void Title_Finalize() {
	DeleteGraph(Title);						//�摜�̊J������
	deleteMassageBox(&startGame);
	deleteMassageBox(&endGame);
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
	drawAtMassageBox(&startGame,TRUE);
	drawAtMassageBox(&endGame, TRUE);
	
}


void Title_StartMouseSelect() {				
	if (Mousex >= startGame.mystr.x-startGame.sprite.width / 2 + 10&& Mousex <= startGame.mystr.x + startGame.sprite.width / 2 - 30
		&& Mousey >= startGame.mystr.y - startGame.sprite.height / 2 + 10 && Mousey <= startGame.mystr.y + startGame.sprite.height / 2 - 10) {
		startGame.mystr.color = 0xff0000;
		if (startSelect == 0) {			//SE�Ǘ��p��IF��
			PlaySoundMem(title_select_SE, DX_PLAYTYPE_BACK);
			startSelect = 1;
		}
		if ( getLeftDown() != 0) {
			startGame.mystr.color = 0x00ff00;
			PlaySoundMem(title_enter_SE, DX_PLAYTYPE_BACK);
			onLoadFlag(LOAD_FLUSH);
		}
	}
	else {
		startGame.mystr.color = 0x000000;
		startSelect = 0;
	}
	
}

void Title_EndMouseSelect() {
	if (Mousex >= endGame.mystr.x - endGame.sprite.width / 2 + 10 && Mousex <= endGame.mystr.x + endGame.sprite.width / 2 - 30
		&& Mousey >= endGame.mystr.y - endGame.sprite.height / 2 + 10 && Mousey <= endGame.mystr.y + endGame.sprite.height / 2 - 10) {
		endGame.mystr.color = 0xff0000;
		if (endSelect == 0) {
			PlaySoundMem(title_select_SE, DX_PLAYTYPE_BACK);
			endSelect = 1;
		}
		if (getLeftDown() != 0) {
			PlaySoundMem(title_enter_SE, DX_PLAYTYPE_BACK);
			endGame.mystr.color = 0x00ff00;
			/*�����ɏI��������`��*/

		}
	}
	else {
		endGame.mystr.color = 0x000000;
		endSelect = 0;
	}
}