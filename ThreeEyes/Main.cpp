#include "DxLib.h"
#include <stdio.h>
#include"SceneMgr.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
		SetBackgroundColor(255, 255, 255);//�w�i�𔒐F�ɕύX
		ChangeWindowMode(TRUE);//��S��ʂɃZ�b�g
		SetGraphMode(640, 480, 32);//��ʃT�C�Y�w��
		SetOutApplicationLogValidFlag(FALSE);//log.text�𐶐����Ȃ��悤��


		if (DxLib_Init() == -1) {		// �c�w���C�u��������������
			/* �����ŉ摜�E����ǂݍ���  */
			return -1;			// �G���[���N�����璼���ɏI��
			}
		SetMouseDispFlag(TRUE);
		SceneMgr_Initialize();			//����������

		while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {//��ʍX�V & ���b�Z�[�W���� & ��ʏ���
			
				//SetDrawScreen(DX_SCREEN_BACK);//�`���𗠉�ʂ�

				/* Main�ɏ����̂͂��̓�̂�*/
				SceneMgr_Update();
				SceneMgr_Draw();

		}


		WaitKey();				// �L�[���͑҂�

		DxLib_End();				// �c�w���C�u�����g�p�̏I������

		return 0;				// �\�t�g�̏I�� 
	
}