#pragma once
#include "DxLib.h"
#include "MyDrawString.h"
#include "Sprite.h"

//�摜�̘g�̒��S�ɕ����񂪂���{�^���̂悤�Ȃ��̂��ȒP�Ɏ������邽�߂�Lib

struct MassageBox {
	struct MyString mystr;//��������
	struct Sprite sprite;//�摜���
};

//���������č\���̂�Ԃ�
MassageBox initMassageBox(const char* FileName, const char* str, int color, int FontHandle, int x, int y, int width, int height);

int drawMassageBox(MassageBox* msgbox, int x, int y, BOOL transFlag);//����N�_�Ń��b�Z�[�W�{�b�N�X��`��
int drawMassageBox(MassageBox* msgbox, BOOL transFlag);//�\���̂ɓ����Ă�����ō���N�_�Ń��b�Z�[�W�{�b�N�X��`��

int drawAtMassageBox(MassageBox* msgbox, int x, int y, BOOL transFlag);//�����N�_�Ń��b�Z�[�W�{�b�N�X��`��
int drawAtMassageBox(MassageBox* msgbox, BOOL transFlag);//�\���̂ɓ����Ă�����Œ����N�_�Ń��b�Z�[�W�{�b�N�X��`��

void deleteMassageBox(MassageBox* msgbox);//�\���̏�������