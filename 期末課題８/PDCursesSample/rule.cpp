#include <stdio.h>
#include <curses.h>

void draw_rule(int* titleFlag) { //���[����ʂ̕`��
	int key;
	clear();

	while (*titleFlag == 0) {
		mvaddstr(1, 0, "�^�C�g����ʂ�play��I������ƃt�B�[���h�Ɉړ�����B�t�B�[���h��ʂɂ͗l�X�ȐF�̃h�b�g������A�e�h�b�g�͓G�Ǝ�����\����");
		mvaddstr(3, 0, "����B�����̃h�b�g�ƓG�̃h�b�g���d�˂�Ɛ퓬���n�܂�B�R�}���h��I�����邱�ƂŐ킢��i�ߓG��HP��0�ɂ���Ə����ɂȂ�B��");
		mvaddstr(5, 0, "�x���������A�ŏI�I�ɖ�����|���Ώ������I��{�I�Ɉړ���R�}���h�̑I���͖��L�[�A�I����a�L�[�A�߂��z�L�[�ł���B");
		mvaddstr(7, 0, "z�{�^���Ń^�C�g���ɖ߂�");
		refresh();
		key = getch();
		if (key == 'z') {
			*titleFlag = 1;
		}
	}
}