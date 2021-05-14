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
    scanf("%d",&p->weight);
    printf("제품 재고 개수: ");
    scanf("%d",&p->count);
    printf("=> 추가 완료!\n");

    return 1;
}


void readProduct(Product p){
    if (p.type == 1) printf("  음료  |");
    else if (p.type == 2) printf("  과자  |");
    else if (p.type == 3) printf("  라면  |");
    else if (p.type == 4) printf("    밥  |");
    printf("  %s  |  %d 원  |",p.name,p.price);
    if (p.type == 1) printf("  %d ml  |  %d 개\n",p.weight,p.count);
    else printf("  %d g  |  %d 개\n",p.weight,p.count);
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
    scanf("%d",&p->weight);
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
    printf(" 번호 | 종류 |   제품명   |  가격  |  무게  |  재고 개수\n");
    printf("---------------------------------------------------------\n");
    for (int i=0; i<num; i++) {
        if(p[i] == NULL) continue;
        printf("%2d  |",i+1);
        readProduct(*p[i]);
    }
    printf("\n");
}

// File
void saveData(Product *p[], int count) {
    int num[4] = {0};
    FILE * file;
    file = fopen("store.txt","w");

    fprintf(file,"*** 전체 편의점 정보 ***\n");

    fprintf(file,"\n1. 전체 편의점 제품 갯수\n");
    fprintf(file,"\t총 %d가지\n",count);

    fprintf(file,"\n2. 전체 편의점 물품 정보\n");
    fprintf(file," 번호 |  종류  |   제품명   |  가격  |  무게  |  재고 개수\n");
    fprintf(file,"-------------------------------------------------------\n");
    for (int i=0; i<count; i++) {
        fprintf(file,"%2d  |",i+1);
        if (p[i]->type == 1) {
            num[0]++;
            fprintf(file,"  음료  |");
        }
        else if (p[i]->type == 2) {
            num[1]++;
            fprintf(file,"  과자  |");
        }
        else if (p[i]->type == 3) {
            num[2]++;
            fprintf(file,"  라면  |");
        }
        else {
            num[3]++;
            fprintf(file,"    밥  |");
        }
        fprintf(file,"  %s  |  %d 원  |",p[i]->name,p[i]->price);
        if (p[i]->type == 1) fprintf(file,"  %d ml |  %d 개\n",p[i]->weight,p[i]->count);
        else fprintf(file,"  %d g  |  %d 개\n",p[i]->weight,p[i]->count);
    }

    fprintf(file,"\n3. 종류별 제품 갯수\n");
    fprintf(file,"\t음료 : %d 종류  과자 : %d 종류  라면 : %d 종류  밥 : %d 종류\n",num[0],num[1],num[2],num[3]);

    printf("=> 저장 완료!\n");
    fclose(file);
}


int loadData(Product *p[]) {
    int i=0;
    FILE * file;
    if ((file = fopen("product.txt","r"))) {
        while (!feof(file)) {
            p[i] = (Product *)malloc(sizeof(Product));
            fscanf(file,"%d %s %d %d %d \n",&p[i]->type,p[i]->name,&p[i]->price,&p[i]->weight,&p[i]->count);
            i++;
        }
        fclose(file);
    }
    return i;
}

// Search
void searchName(Product *p[], int num) {
    char pro[20];
    int yn = 0;
    printf("검색할 제품은? ");
    scanf("%s",pro);
    for (int i=0;i<num;i++) {
        if (strstr(p[i]->name,pro)!=0) {
            readProduct(*p[i]);
            yn = 1;
        }
        else if (i == num-1 && yn == 0) printf("검색 결과가 없습니다.\n");
    }
}

void searchType(Product *p[], int num) {
    int ty, yn = 0;
    printf("검색할 제품의 종류는? (1. 음료  2. 과자  3. 라면  4. 밥)");
    scanf("%d",&ty);
    for (int i=0;i<num;i++) {
        if (p[i]->type == ty) { 
            readProduct(*p[i]);
            yn = 1;
        }
        else if (i == num-1 && yn == 0) printf("검색 결과가 없습니다.\n");
    }
}

void searchPrice(Product *p[], int num) {
    int money, yn = 0;
    printf("검색할 제품의 가격대는? (천원 단위) ");
    scanf("%d",&money);
    for (int i=0;i<num;i++) {
        if ((p[i]->price >= money) && (p[i]->price < money+1000)) {
            readProduct(*p[i]);
            yn = 1;
        }
        else if (i == num-1 && yn == 0) printf("검색 결과가 없습니다.\n");
    }
}


// Manager
void managerStore(Product *p[], int num) {
    printf("===============\n");
    printf("남은 재고\n");
    for (int i=0;i<num;i++) {
        printf("%d. %s %d개\n",i+1,p[i]->name,p[i]->count);
    }
}

