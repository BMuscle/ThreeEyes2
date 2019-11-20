#pragma once
#include "DxLib.h"
#include "MyWindow.h"
#include "Sprite.h"

enum LOAD_TYPE {
	LOAD_ERASE,
	LOAD_FLUSH,
};

void initLoadEffect(void);//���[�h�G�t�F�N�g��������
void deleteLoadEffect(void);//���[�h�G�t�F�N�g�̏���

void onLoadFlag(LOAD_TYPE type);//���[�h�G�t�F�N�g���J�n����
int getCurrentLoadState(void);//���[�h��Ԃ��擾����
BOOL isLoadEnd(void);//���̃V�[���Ɉڍs�ł��邩�H
BOOL isStart(void);//scene���J�n���Ă������H
void LoadEffect_Update(void);//�v�Z����
void LoadEffect_Draw(void);//�`�揈��
