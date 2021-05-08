#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "manager.h"

// Select
int selectMenu(){
    int menu;
    printf("\n*** Handong Global University ***\n\n");
    printf("1. 학생 정보 조회\n");
    printf("2. 학생 정보 추가\n");
    printf("3. 학생 정보 수정\n");
    printf("4. 학생 정보 삭제\n");
    printf("5. 파일저장\n");
    printf("6. 학생 이름으로 검색\n");
    printf("7. 학번으로 검색\n");
    printf("8. 전공 검색\n");
    printf("8. 학년 검색\n");
    printf("8. 기숙사별 팀 선정\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

int selectDatNo(Person *p[], int num) {
    int no;
    listPerson(p, num);
    printf("번호는 (취소 :0)? ");
    scanf("%d", &no);
    return no;
}

// CRUD
int createPerson(Person *p) {

    getchar();
    printf("이름: ");
    fgets(p->name,60,stdin);
    p->name[strlen(p->name)-1] = '\0';
    printf("학번: ");
    scanf("%d",&p->id);
    printf("학년: ");
    scanf("%d",&p->grade);
    printf("전공: ");
    fgets(p->major,60,stdin);
    p->major[strlen(p->major)-1] = '\0';
    printf("RC: ");
    // RC 이름 적기
    scanf("%d",&p->RC);
    printf("=> 추가 완료!\n");

    return 1;
}

void readPerson(Person *p){
    printf("\t%s\t%d\t%d\t%s\n",p->name,p->id,p->grade,p->major);
    // RC 이름 리스트로 가져와서 번호로 출력하기 
}


int updatePerson(Person *p) {

    getchar();
    printf("이름: ");
    fgets(p->name,60,stdin);
    p->name[strlen(p->name)-1] = '\0';
    printf("학번: ");
    scanf("%d",&p->id);
    printf("학년: ");
    scanf("%d",&p->grade);
    printf("전공: ");
    fgets(p->major,60,stdin);
    p->major[strlen(p->major)-1] = '\0';
    printf("RC: ");
    // RC 이름 적기
    scanf("%d",&p->RC);
    printf("=> 수정 완료!\n");

    return 1;
};

int deletePerson(Person *p[], int no){
   p[no-1] = NULL;
   return 0;
}

void listPerson(Person *p[],int num){
    printf("\nNo. Name id grade major Rc\n");
    printf("================================");
    for(int i = 0; i< num; i++){
        if(p[i] == NULL) continue;
        printf("%2d.",i+1);
        readPerson(p[i]);
    }
    printf("\n");
}
  

// Team
int makeTeam(Person *p[], int num) {
    // 어떤 RC 인지 묻기
    // 몇팀으로 나눌꺼인지 묻기

    // 해당 RC 몇명인지 카운트 
    // 카운트 하면서 해당 번호 배열에 집어넣기 

    // 카운트 갯수 / 팀 으로 랜덤값 생성 + 2차원 배열 저장
    // 배열 내용대로 팀 번호 입력해주기 

    int count=0;
    int RC[100];
    int team, tNum, rNum[10][100], k=0;

    srand(time(0));
    printf("어떤 RC의 팀을 선정할까요?\n");
    printf("1. 토레이   2. 벧엘   3. 로뎀   4. 장기려   5. 카이퍼\n");
    scanf("%d",&num);

    for (int i=0;i<num;i++) {
        if (p[i]->RC == num-1) {
            RC[count] = i;
            count++;
        }
    }
    printf("해당 RC에는 총 %d명이 있습니다. 몇 팀으로 나눌까요?\n",count);
    scanf("%d",&team);

    for (int i=0;i<team;i++) {
        tNum = count / team;

        while (1) {
            rNum[i][k] = rand()%count;
            for (int j=0;j<k;j++) {
                if (rNum[i][k]==rNum[i][j]) {
                    k--;
                    count++;
                    break;
                }
                else {
                    p[RC[rNum[i][k]]]->team = i+1; 
                }
            }
            if (k == tNum || count == 0) break;
            k++;
            count--;
        }
    }

    listPerson(p,num);
    printf("\n");
    return 0;
}

