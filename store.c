#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "manager.h"

// Select
int selectMenu(){
    int menu;
    printf("\n*** Convenience Store ***\n\n");
    printf("1. 제품 조회\n");
    printf("2. 제품 추가\n");
    printf("3. 제품 수정\n");
    printf("4. 제품 삭제\n");
    printf("5. 파일저장\n");
    printf("6. 제품 이름 검색\n");
    printf("7. 제품 종류 검색\n");
    printf("8. 제품 가격 검색\n");
    printf("9. 재고 관리\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

int selectDatNo(Product *p[], int num) {
    int no;
    // listPerson(p, num); -- list 함수 부재
    printf("번호는 (취소 :0)? ");
    scanf("%d", &no);
    return no;
}
