#include <stdio.h>
#include <stdlib.h>

/*typedef struct  {
	char* name;
	int   age;
} Person;
struct PersonStruct {
	char* name;
	int   age;
	struct PersonStruct* father;
}*/

typedef struct PersonStruct {
	char* name;
	int   age;
	struct PersonStruct* father;
} Person;

//typedef struct PersonStruct Person;

Person p = {"Sergey", 45, NULL};
struct PersonStruct alex = {"Alex", 20, &p};

struct Money {
	int summa;
	/*_Alignas(16)*/ char* currency;
};

struct Byte {
	unsigned int b0 : 1; // size in bits
	unsigned int b1 : 1;
	unsigned int b2 : 1;
	unsigned int b3 : 1;
	unsigned int b4 : 1;
	unsigned int b5 : 1;
	unsigned int b6 : 1;
	unsigned int b7 : 1;
};
struct HalfByte {
	unsigned int lo : 4;
	unsigned int hi : 4;
};

union Int2Byte {
	unsigned int i;
	unsigned char b;
	struct Byte bits;
	struct HalfByte halfByte;
};

void printM(struct Money m) {
	printf("%d%s\n", m.summa, m.currency);
}

void printMP(const struct Money* m) {
	// m->summa++; // visible outside
	printf("%d%s\n", m->summa, m->currency);
}

int main(int argc, char *argv[]) {
	struct {
		int summa;
		char* currency;
	} m1;
	
	m1.summa = 100;
	m1.currency = "RUB";
	printf("%d%s\n", m1.summa, m1.currency);
	
	struct Money m2;
	m2.summa = 200;
	m2.currency = "USD";
	printf("%d%s\n", m2.summa, m2.currency);
	
	struct Money m3 = {0};
	printf("%d\n", m3.summa);
	
	struct Money m4 = { 300, "EUR" };
	printM(m4);
	struct Money m5 = m4;
	
	struct Money* pm = &m4;
	//(*pm).summa = 400;
	pm->summa = 400;
	
	printM(m4);
	printM(m5);
	
	printMP(&m5);
	
	
	printf("sizeof(struct Money) %d\n", sizeof(m4));
	
	printf("Alex father name: %s\n", alex.father->name);
	
	Person* px1 = malloc(sizeof(Person));
	px1->name = "Konstantin";
	px1->age = 35;
	px1->father = NULL;
	
	Person* px2 = malloc(sizeof(Person));
	px2->name = "Elena";
	px2->age = 12;
	px2->father = px1;
	
	printf("%s %d\n", px1->name, px1->age);
	printf("%s %d\n", px2->name, px2->age);
	
	printf("%s\n", px2->father->name);
	
	//px2.father = NULL;
	//free(px1);
	//free(px2);
	
	free(px2);
	free(px1);
	
	union  Int2Byte i2b;
	i2b.i = 1;
	printf("i2b.i = %d\n", i2b.i);
	i2b.b = 128; // 1000 0000  == hi = 8 lo = 0 
	printf("i2b.i = %d\n", i2b.i);
	
	printf("sizeof(Int2Byte) : %d\n", sizeof(i2b));
	
	printf("sizeof(Byte) : %d\n", sizeof(struct Byte));
	printf("bit0 : %d\n", i2b.bits.b0);
	printf("bit1 : %d\n", i2b.bits.b1);
	printf("bit2 : %d\n", i2b.bits.b2);
	printf("bit3 : %d\n", i2b.bits.b3);
	
	printf("lo : %d\n", i2b.halfByte.lo );
	printf("hi : %d\n", i2b.halfByte.hi );
	
	return 0;
}