#pragma once
#include "DxLib.h"
#include "MyWindow.h"
#include "Sprite.h"



void initLoadEffect(void);
void deleteLoadEffect(void);

void onLoadFlag(void);
int getLoadFlag(void);
BOOL isLoadEnd(void);
BOOL isStart(void);
void LoadEffect_Update(void);
void LoadEffect_Draw(void);
