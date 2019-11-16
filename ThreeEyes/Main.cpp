#include "DxLib.h"
#include <stdio.h>
#include"SceneMgr.h"
#include "MyMouse.h"
#include "MyWindow.h"
#include "MassageBox.h"

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
		SceneMgr_Initialize();			//����������

		int Font00 = CreateFontToHandle("���C���I", 70, 3, DX_FONTTYPE_ANTIALIASING_EDGE);
		MassageBox msg = initMassageBox("images/title.png", "���b�Z�[�W", 0xFF00FF, Font00, WINDOW_WIDTH/2, WINDOW_HEIGHT/2, 502, 143);

		while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {//��ʍX�V & ���b�Z�[�W���� & ��ʏ���
			
				//SetDrawScreen(DX_SCREEN_BACK);//�`���𗠉�ʂ�
				Mouse_Update();
				/* Main�ɏ����̂͂��̓�̂�*/
				SceneMgr_Update();
				SceneMgr_Draw();
				DrawAtMassageBox(&msg, TRUE);

		}


		WaitKey();				// �L�[���͑҂�

		DxLib_End();				// �c�w���C�u�����g�p�̏I������

		return 0;				// �\�t�g�̏I�� 
	
}