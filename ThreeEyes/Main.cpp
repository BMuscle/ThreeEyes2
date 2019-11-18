#include "DxLib.h"
#include <stdio.h>
#include"SceneMgr.h"
#include "MyMouse.h"
#include "MyWindow.h"
#include "LoadEffect.h"
#include "Character.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
		SetBackgroundColor(100, 100, 100);//背景を白色に変更
		ChangeWindowMode(TRUE);//非全画面にセット
		SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32);//画面サイズ指定
		SetOutApplicationLogValidFlag(FALSE);//log.textを生成しないように


		if (DxLib_Init() == -1) {		// ＤＸライブラリ初期化処理
			/* ここで画像・音を読み込み  */
			return -1;			// エラーが起きたら直ちに終了
			}
		SetMouseDispFlag(TRUE);
		initLoadEffect();
		initCharacter();
		SceneMgr_Initialize();			//初期化処理
		
		

		while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {//画面更新 & メッセージ処理 & 画面消去
				LoadEffect_Update();
				//SetDrawScreen(DX_SCREEN_BACK);//描画先を裏画面に
				Mouse_Update();
				/* Mainに書くのはこの二つのみ*/
				SceneMgr_Update();
				SceneMgr_Draw();
				LoadEffect_Draw();
				Character_Draw();
				
		}
		deleteCharacter();
		deleteLoadEffect();
		WaitKey();				// キー入力待ち

		DxLib_End();				// ＤＸライブラリ使用の終了処理

		return 0;				// ソフトの終了 
	
}