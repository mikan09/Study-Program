#include <stdio.h>
#include "static_practice.h"



char* str() {
	static char greeting[64]; // 静的なメモリの確保
	sprintf_s( greeting,64, "%s %s!", "Hello", "World" );
	return greeting;
}

int counter1() {
	static int cnt = 0; // staticローカル変数
	cnt++;
	return cnt;
}

int counter2() {
	int cnt = 0; // ローカル変数
	cnt++;
	return cnt;
}

int main( void ) {
	//静的なメモリの値を取得
	printf( "%s\n", str() );

	int cnt1 = 0, cnt2 = 0;
	for ( int i = 0; i < 3; i++ ) {
		cnt1 = counter1(); // staticローカル変数を取得
		cnt2 = counter2(); // ローカル変数を取得
		printf( "%d回目, 初期値:%d\n", cnt1, cnt2 );
	}

	//別のファイルのグローバル変数を出力表示
	printf( "%s\n", greeting );
	printf( "%f\n", pi );

	return 0;
}