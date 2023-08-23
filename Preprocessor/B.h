#ifndef _B_H_

#define _B_H_

#include "A.h"

void super_test() {
	for(int i=0; i < 10; i++)
		test(); // from A.h
}

#endif