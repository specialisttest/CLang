#include <stdio.h>
#include <stdlib.h>

const char* fname_1 = "test.txt";

int main(int argc, char *argv[]) {
	FILE* f = fopen(fname_1, "r");
	if (f == NULL) {
		perror("Couldn't open file");
		//return 1;
		exit(1);
	}
	
	puts("Read bytes");
	int byte;
	while( (byte = fgetc(f)) != EOF )
		putchar(byte);
		
	fseek(f, 0, SEEK_SET);
		
	puts("\nRead lines");
#define MAX_STR_SIZE 200
	unsigned char str[MAX_STR_SIZE];
	while ( fgets(str, MAX_STR_SIZE, f) != NULL )
		printf(str);
		
	fseek(f, 0, SEEK_END);
	long f_size = ftell(f);
	printf("\nFile size %ld\n", f_size);
	
	rewind(f); // fseek(f, 0, SEEK_SET);
	
	puts("Read formatted data (%s %d)");
	unsigned char word[MAX_STR_SIZE];
	int x;
	
	while( !feof(f) ) {
		fscanf_s(f, "%200s %d", word, MAX_STR_SIZE, &x);
		//fscanf(f, "%s %d", word, &x);
		printf("word: %s number: %d\n", word, x);
	}
	
	rewind(f);
	puts("Unbuffered read");
	unsigned char* buffer = calloc(f_size+1, sizeof(unsigned char));
	fread(buffer, 1, f_size, f);
	puts(buffer);
	free(buffer);
		
	fclose(f);
	
	puts("Write to file");
	f = fopen(fname_1, "a");
	if (f == NULL) {
		perror("Couldn't open file");
		exit(1);
	}
	
	fseek(f, 0, SEEK_END);
	fputs("Line 4\n", f);
	fflush(f);
	
	// fprintf
	// fputc
	// rename(old_name, new_name)
	// remove(name)
	// FILE* tmp = tmpfile(); // w+b
	
	
	fclose(f);
}