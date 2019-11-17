#include"DxLib.h"
#include"Title.h"
#include"SceneMgr.h"
#include"MyMouse.h"
#include"MassageBox.h"
#include "LoadEffect.h"

int Title;					//繧ｿ繧､繝医Ν逕ｨ縺ｮ繝上Φ繝峨Ν
int SEnter, SSelect;		//髻ｳ逕ｨ繝上Φ繝峨Ν
int Mousex, Mousey;			//繝槭え繧ｹ縺ｮx,y蠎ｧ讓
int Font00;					//繝輔か繝ｳ繝域欠螳夂畑縺ｮ繝上Φ繝峨Ν
static Sprite backSprite;
int Title;					//タイトル用のハンドル
int SEnter, SSelect;		//音用ハンドル
int Mousex, Mousey;			//マウスのx,y座標
int Font00;					//フォント指定用のハンドル
static int startSelect, endSelect;		//SE管理用の変数

MassageBox startGame;
MassageBox endGame;

void Title_Initialize() {
	Font00 = CreateFontToHandle("繧ｴ繧ｷ繝�け", 15, 6, DX_FONTTYPE_ANTIALIASING);
	backSprite = initSprite("images/1blackboard.png", 640, 480);
	Title = LoadGraph("images/title.png");
	SEnter = LoadSoundMem("music/enter1.wav");
	SSelect = LoadSoundMem("music/select1.wav");

	startGame = initMassageBox("images/enpitu.png", "ゲーム開始", GetColor(0, 0, 0), Font00, 180, 370, 170, 60);
	endGame = initMassageBox("images/enpitu.png", "終了", GetColor(0, 0, 0), Font00, 480, 370, 170, 60);
	startSelect = 0;
	endSelect = 0;
	startGame.mystr.alpha = 255 * 0.5;
	endGame.mystr.alpha = 255 * 0.5;
}

void Title_Finalize() {
	DeleteGraph(Title);
}

void Title_Update() {
	if (getLoadFlag() > 0) {
		if (isLoadEnd()) {
			PlaySoundMem(SEnter, DX_PLAYTYPE_BACK);
			Title_Finalize();
			SceneMgr_ChangeScene(SCENE_GAME);
		}
		return;
	}
	GetMousePoint(&Mousex, &Mousey);
	Title_StartMouseSelect();
	Title_EndMouseSelect();
}

void Title_Draw() {
	drawAtSprite(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, &backSprite, TRUE);
	DrawGraph(50, 50, Title, FALSE);		//逕ｻ蜒剰ｲｼ繧贋ｻ倥￠
	drawAtMassageBox(&startGame,TRUE);
	drawAtMassageBox(&endGame, TRUE);
	
}


void Title_StartMouseSelect() {				//繧ｲ繝ｼ繝髢句ｧ九�譁ｹ縺ｮ譫縺ｮ濶ｲ螟峨∴繧矩未謨ｰ縲�ｻ停�邱
	if (Mousex >= startGame.mystr.x-startGame.sprite.width / 2 + 10&& Mousex <= startGame.mystr.x + startGame.sprite.width / 2 - 30
		&& Mousey >= startGame.mystr.y - startGame.sprite.height / 2 + 10 && Mousey <= startGame.mystr.y + startGame.sprite.height / 2 - 10) {//繧ｲ繝ｼ繝髢句ｧ九�譫縺ｮ濶ｲ螟画峩
		startGame.mystr.color = 0xff0000;
		if (startSelect == 0) {			//SE管理用のIF文
			PlaySoundMem(SSelect, DX_PLAYTYPE_BACK);
			startSelect = 1;
		}
		if ( getLeftDown() != 0) {
			onLoadFlag();
		}
	}
	else {
		startGame.mystr.color = 0x000000;
		startSelect = 0;
	}
	
}

void Title_EndMouseSelect() {
	if (Mousex >= endGame.mystr.x - endGame.sprite.width / 2 + 10 && Mousex <= endGame.mystr.x + endGame.sprite.width / 2 - 30
		&& Mousey >= endGame.mystr.y - endGame.sprite.height / 2 + 10 && Mousey <= endGame.mystr.y + endGame.sprite.height / 2 - 10) {//繧ｲ繝ｼ繝髢句ｧ九�譫縺ｮ濶ｲ螟画峩
		endGame.mystr.color = 0xff0000;
		if (endSelect == 0) {
			PlaySoundMem(SSelect, DX_PLAYTYPE_BACK);
			endSelect = 1;
		}
		if ( getLeftDown() != 0) {
			PlaySoundMem(SEnter, DX_PLAYTYPE_BACK);
			/*ここに終了処理を描く*/
			
		}
	}
	else {
		endGame.mystr.color = 0x000000;
		endSelect = 0;
	}

}

