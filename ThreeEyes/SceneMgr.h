#pragma once

//Update��Draw�̈ꊇ�Ǘ��̊֐�

typedef enum {				//�񋓌^�A�e�V�[���ɔԍ���t����
	SCENE_TITLE,		// 0
	SCENE_DIFFICULTY,	// 1
	SCENE_GAME,			// 2
	SCENE_RESULT,		// 3
	SCENE_NONE,
}scene;

void SceneMgr_Initialize();			//����������
void SceneMgr_Finalize();			//�I������
void SceneMgr_Update();				//�X�V����
void SceneMgr_Draw();				//�`�揈��
void SceneMgr_ChangeScene(scene nextscene);