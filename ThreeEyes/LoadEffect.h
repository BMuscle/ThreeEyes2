#pragma once
#include "DxLib.h"
#include "MyWindow.h"
#include "Sprite.h"



void initLoadEffect(void);//���[�h�G�t�F�N�g��������
void deleteLoadEffect(void);//���[�h�G�t�F�N�g�̏���

void onLoadFlag(void);//���[�h�G�t�F�N�g���J�n����
int getCurrentLoadState(void);//���[�h��Ԃ��擾����
BOOL isLoadEnd(void);//���̃V�[���Ɉڍs�ł��邩�H
BOOL isStart(void);//scene���J�n���Ă������H
void LoadEffect_Update(void);//�v�Z����
void LoadEffect_Draw(void);//�`�揈��
