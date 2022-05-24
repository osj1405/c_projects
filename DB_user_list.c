#include <stdio.h>
#define MAX_SIZE 1000

void DB_user_list(FILE* fp){
	fp=fopen("DB_mini.txt","r");
	if(fp==NULL)
		printf("파일 열기 실패\n");
	else
		printf("파일 열기 성공\n");
	
	char line[MAX_SIZE];	
	while(fgets(line,sizeof(line),fp)!=NULL){
		printf("%s",line);	
	}
	
	fclose(fp);
	return;
}
