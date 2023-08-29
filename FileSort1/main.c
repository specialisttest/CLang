#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* fin_name = "..\\names.txt";
const char* fout_name = "..\\namesSorted.txt";
#define MAX_STR_SIZE 200
#define MAX_LINES 1000 
int main(int argc, char *argv[]) {
	FILE* fin = fopen(fin_name, "rt");
	if (fin == NULL) {
		perror("Couldn't open file for read");
		exit(1);
	}
	
	unsigned char names[MAX_LINES][MAX_STR_SIZE];
	int lines = 0;
	while (fgets(names[lines], MAX_STR_SIZE, fin) != NULL) 
		lines++;
		
	fclose(fin);
	
	qsort(names, lines, MAX_STR_SIZE, (int (*)(const void*,const void*))strcmp);
		
	FILE* fout = fopen(fout_name, "wt");
	if (fout == NULL) {
		perror("Couldn't open file for write");
		exit(1);
	}
	
	for(int i=0; i < lines; i++)
		fputs (names[i], fout);
	
	fclose(fout);
	
	printf("Write %d line(s)\n", lines);
		
	return 0;
}