#pragma once
#include "DxLib.h"
#include "MyDrawString.h"
#include "Sprite.h"

//画像の枠の中心に文字列があるボタンのようなものを簡単に実装するためのLib

struct MassageBox {
	struct MyString mystr;//文字列情報
	struct Sprite sprite;//画像情報
};

//初期化して構造体を返す
MassageBox initMassageBox(const char* FileName, const char* str, int color, int FontHandle, int x, int y, int width, int height);

int drawMassageBox(MassageBox* msgbox, int x, int y, BOOL transFlag);//左上起点でメッセージボックスを描画
int drawMassageBox(MassageBox* msgbox, BOOL transFlag);//構造体に入っている情報で左上起点でメッセージボックスを描画

int drawAtMassageBox(MassageBox* msgbox, int x, int y, BOOL transFlag);//中央起点でメッセージボックスを描画
int drawAtMassageBox(MassageBox* msgbox, BOOL transFlag);//構造体に入っている情報で中央起点でメッセージボックスを描画

void deleteMassageBox(MassageBox* msgbox);//構造体情報を消去