#include "DxLib.h"
#include <stdio.h>
#include "Game.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);//非全画面にセット
	SetGraphMode(640, 480, 32);//画面サイズ指定
	SetOutApplicationLogValidFlag(FALSE);//log.textを生成しないように

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		/* ここで画像・音を読み込み  */

		return -1;			// エラーが起きたら直ちに終了
	}
	while (ProcessMessage() == 0) 
	{
		ClearDrawScreen();//裏画面消す
		SetDrawScreen(DX_SCREEN_BACK);//描画先を裏画面に

		update();
		draw();
		/* ここに毎フレーム呼ぶ処理を描く */

		ScreenFlip();//裏画面を表画面にコピー

	}


	WaitKey();				// キー入力待ち

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}