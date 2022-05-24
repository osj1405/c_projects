#include <stdio.h>
#include <stdlib.h>

void Add_player(FILE* fp){


}

int main(int argc, char* argv[]){

	FILE* fp=NULL;//file pointer 초기화
	char c;
	char inputName[20];
	char ch;
	while(c!='3'){//종료를 선택할 때까지
		printf("1. 플레이어 정보 기록\n2. 플레이어 정보 확인\n3. 종료\n");
		printf("입력하세요> ");
		scanf("%c",&c);

		ch=getchar();	//공백 한 칸 처리
		switch(c){//선택 번호마다 다른 함수 호출
			case '1':
				Add_player(fp);
				break;
			case '2':
				List_player(fp);
				break;
			case '3':
				printf("종료합니다.\n");
				exit(1);
		}
		printf("\n");
}

	return 0;
}
