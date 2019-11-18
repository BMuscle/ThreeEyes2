#pragma once
#include "DxLib.h"
#include "MyWindow.h"
#include "Sprite.h"

enum LOAD_TYPE {
	LOAD_ERASE,
	LOAD_FLUSH,
};

void initLoadEffect(void);//ロードエフェクトを初期化
void deleteLoadEffect(void);//ロードエフェクトの消去

void onLoadFlag(LOAD_TYPE type);//ロードエフェクトを開始する
int getCurrentLoadState(void);//ロード状態を取得する
BOOL isLoadEnd(void);//次のシーンに移行できるか？
BOOL isStart(void);//sceneを開始していいか？
void LoadEffect_Update(void);//計算処理
void LoadEffect_Draw(void);//描画処理
