#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 1000 

void DB_add_user(FILE* fp){//신규 사용자 생성 함수
	fp=fopen("DB_mini.txt","a");//덧붙일 수 있도록 a모드로 파일을 연다.
	char name[255];
	int age;
	char email[255];
	char answer;

	do{//무조건 한 번은 실행
		printf("이름: ");
		scanf(" %[^\n]",name);//공백 처리를 해 주기 위해 한 칸 띄우고 받는다.
		printf("나이: ");
		scanf(" %d",&age); 
		printf("이메일: ");
		scanf(" %[^\n]",email);
		fprintf(fp,"%s/%d/%s\n",name,age,email);//받아온 정보들을 파일에 작성한다.
		getchar();//공백 한 칸 처리
		printf("계속 입력 할까요? (Y/N)");
		scanf("%c",&answer);
		getchar();//공백 한 칸 처리
		if(answer=='N'){
			printf("입력이 완료되었습니다.\n");
			break;//N 입력 시 반복 종료
		}
	}while(answer=='Y');//Y 입력 시 반복 진행

	fclose(fp);//파일 닫기
	return;//함수 종료
}

void DB_user_delete(FILE* fp){//사용자 삭제 함수
	fp=fopen("DB_mini.txt","r");//읽기 모드로 파일 열기
	FILE* fpnew=fopen("DB_nodelete.txt","w");//삭제하지 않는 내용들을 저장할 새 파일
	char line[MAX_LEN];
	char element[MAX_LEN];
	char delete[MAX_LEN];
	printf("삭제할 사람의 이름을 입력하세요: ");
	scanf(" %[^\n]",delete);//엔터나올 때까지 입력 받음
	getchar();//공백 한 칸 처리
	while(fgets(line,sizeof(line),fp)!=NULL){//파일의 내용 끝이 나올 때까지 반복
		strcpy(element,line);//line으로 파일의 내용을 한 줄씩 읽어와 element에 복사
		char* ptr=strtok(line,"/");//이름만 비교하여 삭제할 대상 찾기 위해 문자열 자르기
		if(strcmp(delete,ptr)!=0){//삭제할 내용이 아닐 때만
			fputs(element,fpnew);	//새 파일에 작성한다
		}	
	}
	remove("DB_mini.txt");//삭제되지 않은 내용이 포함된 기존 파일 삭제
	rename("DB_nodelete.txt","DB_mini.txt");//삭제할 내용 삭제하고 옮겨 적은 새 파일 이름 변경
	fclose(fpnew);//파일 닫기
}

void DB_member_list(FILE *fp){//사용자 목록 확인 함수
	fp=fopen("DB_mini.txt","r");//읽기 모드로 파일 열기
	
	if(fp == NULL)
		printf("파일 열기 실패\n");
	else
		printf("파일 열기 성공\n");

	char line[MAX_LEN];
	while(1){//break를 만날 때까지 반복
		char line[MAX_LEN];
		char *str= fgets(line,sizeof(char)*MAX_LEN,fp);//line에 파일 내용 한 줄씩 받아온다
		if(str==NULL) break;//파일 끝이면 종료
		printf("%s",line);	//가져온 line 출력 (한 줄 씩 출력된다)
	}
	printf("\n");	
	fclose(fp);
	return;
}

int main(void){
	FILE* fp=NULL;//file pointer 초기화
	char c;
	char inputName[20];
	char ch;
	while(c!='5'){//종료를 선택할 때까지
		printf("1. 신규회원 저장\n2. 회원정보 수정\n3. 회원 삭제\n4. 모든 회원 리스트\n5. 종료\n입력하세요>");
		scanf("%c",&c);

		ch=getchar();	//공백 한 칸 처리
		switch(c){//선택 번호마다 다른 함수 호출
			case '1':
				DB_add_user(fp);
				break;
			case '2':
				break;
			case '3':
				DB_user_delete(fp);
				break;
			case '4':
				DB_member_list(fp);
				break;
			case '5':
				printf("종료합니다.\n");
				exit(1);
	}	
		printf("\n");
}

return 0;
}
