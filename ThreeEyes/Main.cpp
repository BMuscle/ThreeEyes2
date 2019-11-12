#include "DxLib.h"
#include <stdio.h>
#include "Game.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);//��S��ʂɃZ�b�g
	SetGraphMode(640, 480, 32);//��ʃT�C�Y�w��
	SetOutApplicationLogValidFlag(FALSE);//log.text�𐶐����Ȃ��悤��

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		/* �����ŉ摜�E����ǂݍ���  */

		return -1;			// �G���[���N�����璼���ɏI��
	}
	while (ProcessMessage() == 0) 
	{
		ClearDrawScreen();//����ʏ���
		SetDrawScreen(DX_SCREEN_BACK);//�`���𗠉�ʂ�

		update();
		draw();
		/* �����ɖ��t���[���Ăԏ�����`�� */

		ScreenFlip();//����ʂ�\��ʂɃR�s�[

	}


	WaitKey();				// �L�[���͑҂�

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}