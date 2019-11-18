#include "DxLib.h"
#include <stdio.h>
#include"SceneMgr.h"
#include "MyMouse.h"
#include "MyWindow.h"
#include "LoadEffect.h"
#include "Character.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
		SetBackgroundColor(100, 100, 100);//�w�i�𔒐F�ɕύX
		ChangeWindowMode(TRUE);//��S��ʂɃZ�b�g
		SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32);//��ʃT�C�Y�w��
		SetOutApplicationLogValidFlag(FALSE);//log.text�𐶐����Ȃ��悤��


		if (DxLib_Init() == -1) {		// �c�w���C�u��������������
			/* �����ŉ摜�E����ǂݍ���  */
			return -1;			// �G���[���N�����璼���ɏI��
			}
		SetMouseDispFlag(TRUE);
		initLoadEffect();
		initCharacter();
		SceneMgr_Initialize();			//����������
		
		

		while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {//��ʍX�V & ���b�Z�[�W���� & ��ʏ���
				LoadEffect_Update();
				//SetDrawScreen(DX_SCREEN_BACK);//�`���𗠉�ʂ�
				Mouse_Update();
				/* Main�ɏ����̂͂��̓�̂�*/
				SceneMgr_Update();
				SceneMgr_Draw();
				LoadEffect_Draw();
				Character_Draw();
				
		}
		deleteCharacter();
		deleteLoadEffect();
		WaitKey();				// �L�[���͑҂�

		DxLib_End();				// �c�w���C�u�����g�p�̏I������

		return 0;				// �\�t�g�̏I�� 
	
}