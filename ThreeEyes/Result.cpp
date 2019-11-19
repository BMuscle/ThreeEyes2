#include"DxLib.h"
#include"Result.h"
#include"SceneMgr.h"
#include "Sprite.h"
#include "MyWindow.h"
#include "MyMouse.h"
#include "MassageBox.h"
#include"LoadEffect.h"

static Sprite backSprite;
int nextSelect = 0;		//���̉�ʂ��ǂ����邩�̐��l������

static int resultImg;					//�摜�n���h���l
static int resultMousex, resultMousey;	//�}�E�X���W������ϐ�
static int SEnter, SSelect;				//SE�p�̃n���h��
static int startSelect, endSelect;		//SE�Ǘ��p�ϐ�
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
	startSelect = 0;
	endSelect = 0;


	nextSelect = SCENE_NONE;
	startGame.mystr.alpha = 255 * 0.5;
	endGame.mystr.alpha = 255 * 0.5;
}

void Result_Finalize() {
	DeleteGraph(resultImg);					//�摜�̊J������
	deleteMassageBox(&startGame);
	deleteMassageBox(&endGame);
	deleteSprite(&backSprite);
	nextSelect = 0;
}

void Result_Update() {
	if (getCurrentLoadState() > 0) {
		if (isLoadEnd()) {
			Result_Finalize();
			SceneMgr_ChangeScene(SCENE_TITLE);
		}
		return;
	}
	GetMousePoint(&resultMousex, &resultMousey);
	Result_EndMouseSelect();
	Result_StartMouseSelect();
	/*�����ɃV�[���`�F���W�ƃG�t�F�N�g������*/
}


void Result_Draw() {
	drawAtSprite(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, &backSprite, TRUE);
	DrawGraph(200, 50, resultImg, FALSE);
	drawAtMassageBox(&startGame, TRUE);
	drawAtMassageBox(&endGame, TRUE);
}

void Result_StartMouseSelect()			//�}�E�X�̃J�[�\���𑱂���ɍ��킹��ƕ����̐F���ς��
{
	//���̃{�b�N�X
	if (resultMousex >= startGame.mystr.x - startGame.sprite.width / 2 + 10 && resultMousex <= startGame.mystr.x + startGame.sprite.width / 2 - 30
		&& resultMousey >= startGame.mystr.y - startGame.sprite.height / 2 + 10 && resultMousey <= startGame.mystr.y + startGame.sprite.height / 2 - 10) {
		startGame.mystr.color = 0xff0000;
		if (startSelect == 0) {			//SE�Ǘ��p��IF��
			PlaySoundMem(SSelect, DX_PLAYTYPE_BACK);
			startSelect = 1;
		}
		if (getLeftDown() != 0) {
			startGame.mystr.color = 0x00ff00;
			PlaySoundMem(SEnter, DX_PLAYTYPE_BACK);
			onLoadFlag(LOAD_FLUSH);
		}
	}
	else {
		startGame.mystr.color = 0x000000;
		startSelect = 0;
	}
}

void Result_EndMouseSelect()		//�}�E�X�̃J�[�\�����I���ɍ��킹��ƕ����̐F���ς��
{
	//�E�̃{�b�N�X
	if (resultMousex >= endGame.mystr.x - endGame.sprite.width / 2 + 10 && resultMousex <= endGame.mystr.x + endGame.sprite.width / 2 - 30
		&& resultMousey >= endGame.mystr.y - endGame.sprite.height / 2 + 10 && resultMousey <= endGame.mystr.y + endGame.sprite.height / 2 - 10) {
		endGame.mystr.color = 0xff0000;
		if (endSelect == 0) {
			PlaySoundMem(SSelect, DX_PLAYTYPE_BACK);
			endSelect = 1;
		}
		if (getLeftDown() != 0) {
			endGame.mystr.color = 0x00ff00;
			PlaySoundMem(SEnter, DX_PLAYTYPE_BACK);
			/*�����ɏI��������`��*/

		}
	}
	else {
		endGame.mystr.color = 0x000000;
		endSelect = 0;
	}
	
}