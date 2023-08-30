#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DAYS_IN_YEAR 365

int main(int argc, char *argv[]) {
	
	double summa, procent;
	int days;
	
	summa = 100;
	procent = 20;
	days = DAYS_IN_YEAR/2;
	
	double income;
	
	int years = days / DAYS_IN_YEAR;
	int reminder_days = days % DAYS_IN_YEAR;
	
	double total = summa * pow( 1 + procent / 100, years);
	income = total*procent*reminder_days / (100*DAYS_IN_YEAR);
	income += total - summa;
	
	printf("Income: %.2lf\n", income);
	
	
	
	return 0;
}
