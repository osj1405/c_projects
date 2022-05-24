#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 10000

void DB_help(FILE* fp){
	fp=fopen("DB_help.txt","r");//사용 방법 file read 모드로 열기
	if(fp == NULL)
		printf("파일 열기 실패\n");
	else
		printf("파일 열기 성공\n");

	char line[MAX_LEN];
	while(1){//break를 만날 때까지 반복
		char *str= fgets(line,sizeof(char)*MAX_LEN,fp);//line에 파일 내용 한 줄씩 받아온다
		if(str==NULL)
		 	break;//파일 끝이면 종료
		printf("%s",line);	//가져온 line 출력 (한 줄 씩 출력된다)
	}
	printf("\n");	
	fclose(fp);
	return;
}

void DB_list(FILE* fp, char* filename){//입력된 파일 출력하기
	fp=fopen(filename,"r");
	
	if(fp == NULL)
		printf("파일 열기 실패\n");
	else
		printf("파일 열기 성공\n");

	char line[MAX_LEN];
	while(1){
		char* str = fgets(line,sizeof(char)*MAX_LEN,fp);
		if(str==NULL)
			break;
		printf("%s",line);	
	}

	printf("\n");
	fclose(fp);
	return;
}

void DB_listcount(FILE* fp, char* filename){//입력 파일 line 수 출력하기
	fp=fopen(filename,"r");
	
	int count = 0;

	if(fp == NULL)
		printf("파일 열기 실패\n");
	else
		printf("파일 열기 성공\n");

	char line[MAX_LEN];
	while(1){
		char* str = fgets(line,sizeof(char)*MAX_LEN,fp);
		count++;//한 줄 씩 읽을 때마다 count ++ 함
		if(str == NULL){
			count--;//break 전에 count++ 되어 line수 보다 1 크기에 빼준다.
	    printf("Line count = %d \n",count);
			break;}
}
	fclose(fp);
}

void DB_replace(FILE* fp, char* filename, char* src, char* dst){
	fp=fopen(filename,"r+t");

	if(fp==NULL)
		printf("파일 열기 실패\n");
	else
		printf("파일 열기 성공\n");



	fclose(fp);
}



int main(int argc, char* argv[]){
	if(argc==1){
		printf("옵션을 입력하세요\n"); // 1점
		return 0;
	}
	
	FILE* fp=NULL;
	if(strcmp(argv[1],"-help")==0){ //./a.out -help가 들어왔을 때
		DB_help(fp);
	}	
	else if(strcmp(argv[1],"-list")==0){//./a.out -list일 때
		DB_list(fp,argv[2]);
	}
	else if(strcmp(argv[1],"-linecount")==0){//./a.out -listcount일 때
		DB_listcount(fp,argv[2]);
	}
	else if(strcmp(argv[1],"-replace")==0){// ./a.out -replace 원본문자열 바꿀문자열일 때
		DB_replace(fp,argv[2],argv[3],argv[4]);
	}
	return 0;
}
