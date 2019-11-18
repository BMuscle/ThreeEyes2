#include "Difficulty.h"


static Sprite backSprite;	//”wŒi‰æ‘œ
static Sprite charname[CHAR_SIZE];
static BOOL mouseOnFlag[CHAR_SIZE];


void Difficulty_Initialize() {
	backSprite = initSprite("images/1blackboard.png", WINDOW_WIDTH, WINDOW_HEIGHT);
	charname[0] = initSprite("images/charname/rk.png", 65, 270);
	charname[1] = initSprite("images/charname/rk.png", 65, 270);
	charname[2] = initSprite("images/charname/rk.png", 65, 270);
	for (int i = 0; i < CHAR_SIZE; i++) {
		mouseOnFlag[i] = 0;
	}

}
void Difficulty_Finalize() {
	deleteSprite(&backSprite);
	for (int i = 0; i < CHAR_SIZE; i++) {
		deleteSprite(&charname[i]);
	}
}
void Difficulty_Update() {
	if (getCurrentLoadState() > 0) {
		if (isLoadEnd()) {
			Difficulty_Finalize();
			SceneMgr_ChangeScene(SCENE_GAME);
		}
		return;
	}

	int mouseX, mouseY;
	GetMousePoint(&mouseX, &mouseY); 
	for (int i = 0; i < CHAR_SIZE; i++) {
		if (mouseX >= WINDOW_WIDTH / 2 + (i - 1) * 150 - charname[i].width / 2 && mouseX <= WINDOW_WIDTH / 2 + (i - 1) * 150 + charname[i].width / 2
			&& mouseY >= WINDOW_HEIGHT * 0.4 - charname[i].height / 2 && mouseY <= WINDOW_HEIGHT * 0.4 + charname[i].height / 2) {
			mouseOnFlag[i] = TRUE;
			setCharacter((CHAR_TYPE)(i + 1));
			if (getLeftDown()) {
				onLoadFlag(LOAD_ERASE);
				return;
			}
		}
		else {
			mouseOnFlag[i] = FALSE;
		}
	}

}
void Difficulty_Draw() {
	drawAtSprite(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, &backSprite, TRUE);//”wŒi•`‰æ
	for (int i = 0; i < CHAR_SIZE; i++) {
		int alpha = 170;
		if (mouseOnFlag[i] == TRUE) {
			alpha = 255;
		}
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
		drawAtSprite(WINDOW_WIDTH / 2 + (i - 1) * 150, WINDOW_HEIGHT * 0.4, &charname[i], TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		
	} 
}