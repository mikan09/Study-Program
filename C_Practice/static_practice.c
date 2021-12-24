#include <stdio.h>
#include "static_practice.h"

static char pref[] = "Tokyo";	// staticグローバル変数(配列)
static float new_pi = 3.0f;		// staticグローバル変数

char greeting[] = "Hello";		// グローバル変数
float pi = 3.14f;				// グローバル変数

int nNotUse = 100;

void exec() {
	printf( "static: %f, %s\n", new_pi, pref );
}