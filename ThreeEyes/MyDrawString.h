#pragma once
#include "DxLib.h"

//������`��
struct MyString {//str��64������
	char str[64] = {0};
	int color;
	int FontHandle;
	int x, y;
	int alpha;
};

MyString initMyString(const char* str, int color, int FontHandle, int x, int y);//������̏�����


int mydrawString(int x, int y, MyString* string);//����N�_�ŕ�����`��
int mydrawString(MyString* string);//������\���̂ɓ����Ă�����ō���N�_�ŕ`��
int mydrawAtString(int x, int y, MyString* string);//�����N�_�ŕ�����`��
int mydrawAtString(MyString* string);//������\���̂ɓ����Ă�����Œ����N�_�ŕ`��

