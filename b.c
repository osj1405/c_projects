#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	FILE* src_fp=fopen(argv[1],"r");//원본 파일
	FILE* dst_fp=fopen(argv[2],"w");//복사본 파일

	char buf[1000]; //내용 저장
	//buf=(char*)malloc(sizeof(char)*10000);

	int r = fread(buf, 1, 10000, src_fp);
	printf("%d %ld\n", r, sizeof(buf));
	fprintf(dst_fp, "%s", buf);

	
	
	fclose(src_fp);
	fclose(dst_fp);
	return 0;
}
