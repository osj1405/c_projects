#include <stdio.h>
#include <stdlib.h>

void write_test(const char* filename){
	int buffer[] = {10, 20, 30, 40, 50};
	FILE* fp = fopen("binary.bin","wb");
	if( fp == NULL )
		{ exit(1);}

	int count = sizeof(buffer) / sizeof(buffer[0]);
	int size = sizeof(buffer[0]);
	int written_cnt = fwrite(buffer, size, count, fp);

	fclose(fp);
}

int main(int argc, char* argv[]){
	write_test("binary.bim");
	return 0;
}
