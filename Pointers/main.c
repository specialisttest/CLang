#include <stdio.h>
#include <stdlib.h>

int y = 20; // global - data segment

typedef int* pInt;
typedef const int* cpInt;

void swap(int* a, int* b) {
	int c = *a;
	*a = *b;
	*b = c;
	printf("swap inside a = %d b = %d\n",*a,*b);
}

int main(int argc, char *argv[]) {
	int x = 10; // local (auto) - stack
	int* px = &x;
	int* py = &y;
	
	int* pz = malloc( sizeof(int) ); // dynamic - heap
	
	*px = 12; // x = 12
	*pz = 14;
	
	printf("x  = %d\n", x);
	printf("px (stack       ) = %p\n", px);
	printf("py (data segment) = %p\n", py);
	printf("pz (heap)         = %p\n", pz);
	
	py = px;
	
	(*py)++; // x++;
	printf("x  = %d\n", x); // 13
	
	const int* cp = px; // &x
	//(*cp)++; // compile error - const pointer
	printf("*cp= %d\n", *cp); // 13
	
	double d = 2.5;
	double* pd = &d;
	
	//pd = px; // warning
	//(*pd) = 1.0; // !!! dangerous - corrupt data
	x = 0x1232560D; // 4-byte
	unsigned char* pchar = (unsigned char*)px;
	printf("unsigned char: %d\n", *pchar); // safe - get first byte
	void* pv = px;
	pv = pd;
	pd = pv;
	printf("void*: %p\n", pv);
	printf("d = %f\n", d);
	printf("void* to double: %f\n", *(double*)pv);
	
	int nums[] = { 10, 20, 30};
	int* pnums = nums; // pnums = &nums[0]
	for(int i=0; i < 3; i++)
		//printf("nums[%d] = %d\n", i, nums[i]);
		printf("nums[%d] = %d\n", i, *(pnums+i));
	
	printf("*pnums = %d\n", *pnums); // nums[0];
	printf(" pnums = %p\n", pnums);  // &nums[0]
	pnums += 1; // pnums++
	printf("*pnums = %d\n", *pnums); // nums[1];
	printf(" pnums = %p\n", pnums);  // &nums[1]
	
	free(pz);
	//*pz // unsafe
	
	pz = NULL;
	
	pInt pl = &x; // int* px = &x;
	cpInt cpp = pl;// const int* cp = pl;
	//(*cpp) = 10; // compile error - const
	
	printf("sizof(void*) %d\n", sizeof(void*));
	
	int a = 5, b = 7;
	printf("a = %d\nb = %d\n",a,b);
	swap( &a, &b);
	printf("a = %d\nb = %d\n",a,b);
	
	return 0;
}