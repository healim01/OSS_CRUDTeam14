#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "manager.h"

int selectMenu(){
    int menu;
    printf("\n*** Handong Global University ***\n");
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

int selectDatNo(Person *p, int num) {
    int no;
    listProduct(p, num);
    printf("번호는 (취소 :0)? ");
    scanf("%d", &no);
    return no;
}