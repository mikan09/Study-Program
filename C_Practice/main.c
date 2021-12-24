#include <stdio.h>
#include "static_practice.h"



char* str() {
	static char greeting[64]; // �ÓI�ȃ������̊m��
	sprintf_s( greeting,64, "%s %s!", "Hello", "World" );
	return greeting;
}

int counter1() {
	static int cnt = 0; // static���[�J���ϐ�
	cnt++;
	return cnt;
}

int counter2() {
	int cnt = 0; // ���[�J���ϐ�
	cnt++;
	return cnt;
}

int main( void ) {
	//�ÓI�ȃ������̒l���擾
	printf( "%s\n", str() );

	int cnt1 = 0, cnt2 = 0;
	for ( int i = 0; i < 3; i++ ) {
		cnt1 = counter1(); // static���[�J���ϐ����擾
		cnt2 = counter2(); // ���[�J���ϐ����擾
		printf( "%d���, �����l:%d\n", cnt1, cnt2 );
	}

	//�ʂ̃t�@�C���̃O���[�o���ϐ����o�͕\��
	printf( "%s\n", greeting );
	printf( "%f\n", pi );

	return 0;
}