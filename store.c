#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "store.h"

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

int selectNum(Product *p[], int num) {
    int no;
    listProduct(p, num);
    printf("번호는 (취소 :0)? ");
    scanf("%d", &no);
    return no;
}

// CRUD
int createProduct(Product *p) {
    getchar();
    printf("제품 종류 ");
    printf("(1. 음료  2. 과자  3. 라면  4. 밥): ");
    scanf("%d",&p->type);
    getchar();
    printf("제품 이름: ");
    fgets(p->name,60,stdin);
    p->name[strlen(p->name)-1] = '\0';
    printf("제품 가격: ");
    scanf("%d",&p->price);
    printf("제품 무게: ");
    scanf("%d",&p->wight);
    printf("제품 재고 개수: ");
    scanf("%d",&p->count);
    printf("=> 추가 완료!\n");

    return 1;
}


void readProduct(Product p){
    if (p.type == 1) printf("\t음료\t");
    else if (p.type == 2) printf("\t과자\t");
    else if (p.type == 3) printf("\t라면\t");
    else if (p.type == 4) printf("\t밥,죽\t");
    printf("%s\t%d\t%d\t%d\n",p.name,p.price,p.wight,p.count);
}


int updateProduct(Product *p) {
    getchar();
    printf("제품 종류  ");
    printf(" ( 1. 음료  2. 과자  3. 라면  4. 밥 ): \n");
    scanf("%d",&p->type);
    getchar();
    printf("제품 이름: ");
    fgets(p->name,60,stdin);
    p->name[strlen(p->name)-1] = '\0';
    printf("제품 가격: ");
    scanf("%d",&p->price);
    printf("제품 무게: ");
    scanf("%d",&p->wight);
    printf("제품 재고 개수: ");
    scanf("%d",&p->count);
    printf("=> 수정 완료!\n");

    return 1;
}

int deleteProduct(Product *p[], int no){
    p[no-1] = NULL;
    return 1;
}


void listProduct(Product *p[],int num) {
    printf("*******************************************\n");
    for (int i=0; i<num; i++) {
        if(p[i] == NULL) continue;
        printf("%d. ",i+1);
        readProduct(*p[i]);
    }
    printf("\n");
}

// File
void saveData(Product *p[], int count) {
    
}



void managerStore(Product *p[], int num) {
    printf("===============\n");
    printf("남은 재고\n");
    for (int i=0;i<num;i++) {
        printf("%d. %s %d개\n",i+1,p[i]->name,p[i]->count);
    }
}

