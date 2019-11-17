#pragma once
#include "MyMouse.h"
#include "DxLib.h"



void Mouse_Update(void);//マウスの情報更新
BOOL getLeftDown(void);//左クリックされた瞬間か？
BOOL getRightDown(void);//右クリックされた瞬間か？

int getLeftPress(void);//左クリックが押し続けられている間
int getRightPress(void);//右クリックが押し続けられている間
