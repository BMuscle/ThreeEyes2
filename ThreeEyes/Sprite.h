#pragma once
#include "DxLib.h"
#include "MyWindow.h"

struct Sprite {//�摜���
	int imgHandler;
	int width;
	int height;
};

Sprite initSprite(const char *FileName,int width,int height);//�摜�������������\���̂�Ԃ�
int drawSprite(int x, int y, Sprite* sprite, BOOL transFlag);//����N�_�`��
int drawAtSprite(int x, int y, Sprite* sprite, BOOL transFlag);//�����N�_�`��
void deleteSprite(Sprite* sprite);//�摜����