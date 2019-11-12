#include"DxLib.h"
#include"Title.h"
#include"SceneMgr.h"

int Title;
int game_x, end_x;			//font描画用x座標
int upBox_x1, upBox_x2;		//Box描画用x座標(ゲーム開始の箱)
int downBox_x1, downBox_x2;	//Box描画用x座標(終了の箱)
int Mousex, Mousey;			//マウスのx,y座標
int MouseInput;				//マウスの判定用変数;
int upBoxColor1, upBoxColor2;	//Boxの色
int upBcolorG,downBcolorG;		//マウスのカーソルがゲーム開始と終了に合わせた時、緑色にするための変数

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
	DrawGraph(50, 50, Title, FALSE);				//画像貼り付け
	DrawBox(upBox_x1,240,upBox_x2,280,upBoxColor1,FALSE);		//ゲーム開始の枠
	DrawBox(downBox_x1, 340, downBox_x2, 380, upBoxColor2, FALSE);		//終了の枠
	DrawFormatString(game_x, 250, GetColor(0, 0, 0), "ゲーム開始");		
	DrawFormatString(end_x, 350, GetColor(0, 0, 0), "終了");
	Title_StartMouseSelect();
	Title_EndMouseSelect();
}

void Title_Select() {
	if (CheckHitKey(KEY_INPUT_UP)) {	//上ボタンを押したときにゲーム開始とその枠を左に少しずらす
		game_x = 75;
		end_x = 100;
		upBox_x1 = 65;
		upBox_x2 = 175;
		downBox_x1 = 90;
		downBox_x2 = 200;
	}
	if (CheckHitKey(KEY_INPUT_DOWN)) {	//下ボタンも↑同様
		game_x = 100;
		end_x = 75;
		upBox_x1 = 90;
		upBox_x2 = 200;
		downBox_x1 = 65;
		downBox_x2 = 175;
	}

}

void Title_StartMouseSelect() {				//ゲーム開始の方の枠の色変える関数、黒→緑
	if (Mousey >= 240 && Mousey <= 280 && Mousex >= upBox_x1 && Mousex <= upBox_x2) {//ゲーム開始の枠の色変更
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
	if (Mousey >= 340 && Mousey <= 380 && Mousex >= downBox_x1 && Mousex <= downBox_x2) {//ゲーム開始の枠の色変更
		downBcolorG = 255;
		if ((MouseInput & MOUSE_INPUT_LEFT) != 0) {
			/*ここにゲーム終了処理を描く*/
		}
	}
	else {
		downBcolorG = 0;
	}

	upBoxColor2 = GetColor(0, downBcolorG, 0);
}

