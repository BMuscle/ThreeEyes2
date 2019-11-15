#include"DxLib.h"
#include"Title.h"
#include"SceneMgr.h"

int Title;
int SEnter, SSelect;		//音用ハンドル
int game_y, end_y;			//font描画用y座標
int upBox_y1, upBox_y2;		//Box描画用y座標(ゲーム開始の箱)
int downBox_y1, downBox_y2;	//Box描画用y座標(終了の箱)
int Mousex, Mousey;			//マウスのx,y座標
int MouseInput;				//マウスの判定用変数;
int upBoxColor1, upBoxColor2;	//Boxの色
int upBcolorG, downBcolorG;		//マウスのカーソルがゲーム開始と終了に合わせた時、緑色にするための変数
int gameFontR, endFontR;		//ゲーム開始と終了の文字のフォントのRedの色

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
	DrawGraph(50, 50, Title, FALSE);				//画像貼り付け
	DrawBox(90, upBox_y1, 190, upBox_y2, upBoxColor1, FALSE);		//ゲーム開始の枠
	DrawBox(390, downBox_y1, 490, downBox_y2, upBoxColor2, FALSE);		//終了の枠
	DrawFormatString(100, game_y, GetColor(gameFontR, 0, 0), "ゲーム開始");
	DrawFormatString(400, end_y, GetColor(endFontR, 0, 0), "終了");
	Title_StartMouseSelect();
	Title_EndMouseSelect();
}

void Title_Select() {
	if (CheckHitKey(KEY_INPUT_LEFT) && gameFontR == 0) {	//左ボタンを押したときにゲーム開始のフォントの色を赤色にする
		PlaySoundMem(SSelect, DX_PLAYTYPE_BACK);
		gameFontR = 255;
		endFontR = 0;
	}
	if (CheckHitKey(KEY_INPUT_RIGHT) && endFontR == 0) {	//右ボタンも↑同様
		PlaySoundMem(SSelect, DX_PLAYTYPE_BACK);
		gameFontR = 0;
		endFontR = 255;
	}

}

void Title_StartMouseSelect() {				//ゲーム開始の方の枠の色変える関数、黒→緑
	if (Mousex >= 90 && Mousex <= 190 && Mousey >= upBox_y1 && Mousey <= upBox_y2) {//ゲーム開始の枠の色変更
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
	if (Mousex >= 390 && Mousex <= 490 && Mousey >= downBox_y1 && Mousey <= downBox_y2) {//ゲーム開始の枠の色変更
		downBcolorG = 255;
		if ((MouseInput & MOUSE_INPUT_LEFT) != 0) {
			PlaySoundMem(SEnter, DX_PLAYTYPE_BACK);
			/*ここにゲーム終了処理を描く*/
		}
	}
	else {
		downBcolorG = 0;
	}

	upBoxColor2 = GetColor(0, downBcolorG, 0);
}

