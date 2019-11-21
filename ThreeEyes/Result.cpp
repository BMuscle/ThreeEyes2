#include"DxLib.h"
#include"Result.h"
#include"SceneMgr.h"
#include "Sprite.h"
#include "MyWindow.h"
#include "MyMouse.h"
#include "MassageBox.h"
#include"LoadEffect.h"
#include "Character.h"


#define BUTTON_OFFSET_X 200
#define BUTTON_OFFSET_Y 230
#define BUTTON_INTERVAL_Y 10
#define BUTTON_WIDTH 300
#define BUTTON_HEIGHT 60

#define METER_X (WINDOW_WIDTH * 0.85)
#define METER_Y	(WINDOW_HEIGHT * 0.6)

enum BUTTON_TYPE {
	BUTTON_GAME,
	BUTTON_DIF,
	BUTTON_EXIT,
	BUTTON_SIZE,
};

static Sprite backSprite;
static int SEnter, SSelect;				//SE用のハンドル
static int result_bgm;					//bgm用ハンドル
static int startSelect, endSelect;		//SE管理用変数
static int fontResult;//フォント用ハンドル
static Sprite button[BUTTON_SIZE][2];
static BOOL mouseOnFlag[BUTTON_SIZE];
static Sprite meter;
static Sprite judge;
static BUTTON_TYPE holdType;

void Result_Initialize(int winlose) {	//winloseが1なら勝ち、2なら負け、3なら引き分け
	backSprite = initSprite("images/resultback.png", 640, 480);
	button[0][0] = initSprite("images/button/Result_To_Game.png", BUTTON_WIDTH, BUTTON_HEIGHT);
	button[0][1] = initSprite("images/button/Result_To_Gameon.png", BUTTON_WIDTH, BUTTON_HEIGHT);
	button[1][0] = initSprite("images/button/Result_To_Select.png", BUTTON_WIDTH, BUTTON_HEIGHT);
	button[1][1] = initSprite("images/button/Result_To_Selecton.png", BUTTON_WIDTH, BUTTON_HEIGHT);
	button[2][0] = initSprite("images/button/Result_To_Finish.png", BUTTON_WIDTH, BUTTON_HEIGHT);
	button[2][1] = initSprite("images/button/Result_To_Finishon.png", BUTTON_WIDTH, BUTTON_HEIGHT);

	fontResult = CreateFontToHandle("ゴシック", 15, 6, DX_FONTTYPE_ANTIALIASING);
	startSelect = 0;
	endSelect = 0;
	SEnter = LoadSoundMem("musics/enter_ou.wav");
	SSelect = LoadSoundMem("musics/select_or_enter.wav");
	result_bgm = LoadSoundMem("musics/bgm2.wav");
	ChangeVolumeSoundMem(255 * 40 / 100, result_bgm);
	PlaySoundMem(result_bgm, DX_PLAYTYPE_LOOP);

	switch(winlose) {
	case 1:
		judge = initSprite("images/win.png", 300, 100);
		meter = initSprite("images/meter1.png", 70, 300);
		break;
	case 2:
		judge = initSprite("images/lose.png", 300, 100);
		meter = initSprite("images/meter2.png", 70, 300);
		break;
	case 3:
		judge = initSprite("images/draw.png", 300, 100);
		meter = initSprite("images/meter3.png", 70, 300);
		break;
	}
}

void Result_Finalize() {
	deleteSprite(&backSprite);
	DeleteSoundMem(result_bgm);

}

void Result_Update() {
	if (getCurrentLoadState() > 0) {
		if (isLoadEnd()) {
			Result_Finalize();
			switch (holdType) {
			case BUTTON_GAME:
				SceneMgr_ChangeScene(SCENE_GAME);
				break;
			case BUTTON_DIF:
				SceneMgr_ChangeScene(SCENE_DIFFICULTY);
				clearCharacter();
				break;
			case BUTTON_EXIT:
				//ゲーム終了処理かく
				setMainEndFlag(TRUE);
				Result_Finalize();
				break;
				
			}
		}
		return;
	}
	setMessageFlag(TRUE);
	//選択肢３つ分
	int mouseX, mouseY;
	GetMousePoint(&mouseX, &mouseY);

	
	
	for (int i = 0; i < BUTTON_SIZE; i++) {
		if (mouseX >= BUTTON_OFFSET_X  + 10 && mouseX <= BUTTON_OFFSET_X + button[i][0].width
			&& mouseY >= BUTTON_OFFSET_Y + BUTTON_INTERVAL_Y * i + button[i][0].height * i && mouseY <= BUTTON_OFFSET_Y + BUTTON_INTERVAL_Y * i + button[i][0].height * (i + 1)) {
			if (mouseOnFlag[i] == FALSE) {
				PlaySoundMem(SSelect, DX_PLAYTYPE_BACK);
			}
			mouseOnFlag[i] = TRUE;
			if (getLeftDown()) {
				PlaySoundMem(SEnter, DX_PLAYTYPE_BACK);
				switch (i) {
				case 0:
					holdType = BUTTON_GAME;
					break;
				case 1:
					holdType = BUTTON_DIF;
					break;
				case 2:
					holdType = BUTTON_EXIT;
				}
				onLoadFlag(LOAD_FLUSH);
				return;
			}
		}
		else {
			mouseOnFlag[i] = FALSE;
		}
	}
	
}


void Result_Draw() {
	drawAtSprite(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, &backSprite, TRUE);
	for (int i = 0; i < BUTTON_SIZE; i++) {
		drawSprite(BUTTON_OFFSET_X, BUTTON_OFFSET_Y + BUTTON_INTERVAL_Y * i + button[i][0].height * i, &button[i][mouseOnFlag[i]], TRUE);
	}
	drawAtSprite(METER_X, METER_Y, &meter, TRUE);
	drawAtSprite(WINDOW_WIDTH * 0.55, WINDOW_HEIGHT * 0.3, &judge, TRUE);
}
