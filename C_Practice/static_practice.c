#include <stdio.h>
#include "static_practice.h"

static char pref[] = "Tokyo";	// static�O���[�o���ϐ�(�z��)
static float new_pi = 3.0f;		// static�O���[�o���ϐ�

char greeting[] = "Hello";		// �O���[�o���ϐ�
float pi = 3.14f;				// �O���[�o���ϐ�

int nNotUse = 100;

void exec() {
	printf( "static: %f, %s\n", new_pi, pref );
}