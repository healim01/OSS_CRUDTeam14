#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "store.h"

int main(){

    Product *p[50];
    int menu;
    int num = 0;
    int no ,del;

    // num = loadData(p);  -- load 함수 부재로 주석 처리 
    if (num == 0) printf("=> 파일 없음\n");
    else printf("=> 로딩 성공!\n");
    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1) {
            if (num == 0 ) printf("데이터가 없습니다.\n"); 
            else listProduct(p,num);
        }
        else if (menu == 2)  {
            p[num] = (Product *)malloc(sizeof(Product));
            num += createProduct(p[num]);
        }
        else if (menu == 3) {
            if (num == 0 ) printf("데이터가 없습니다.\n");
            no = selectNum(p,num);
            if(no == 0){
                printf("=> 취소됨!\n");
                continue;
            }
            updateProduct(p[no-1]);
        }
        else if (menu == 4) {
            if (num == 0 ) printf("데이터가 없습니다.\n");
            no = selectNum(p, num);
            if (no == 0){
                printf("=> 취소됨!\n");
                continue;
            }
            printf("정말로 삭제하시겠습니까?(삭제:1) ");
            scanf("%d",&del);
            if (del==1) {
                deleteProduct(p,no);
                printf("=> 삭제됨!\n");
            } 
        } /*
        else if (menu == 5) {
            if (num == 0 ) printf("데이터가 없습니다.\n");
            else saveData(p,num);
        } 
        else if (menu == 6) {
            if (num == 0 ) printf("데이터가 없습니다.\n");
            else searchName(p,num);
        }
        else if (menu == 7) {
            if (num == 0 ) printf("데이터가 없습니다.\n");
            else searchType(p,num);
        }
        else if (menu == 8) {
            if (num == 0 ) printf("데이터가 없습니다.\n");
            else searchPrice(p,num);
        } */
        else if (menu ==9) {
            if (num == 0 ) printf("데이터가 없습니다.\n");
            else managerStore(p,num);
        }
        else break;
    }
    printf("종료됨!\n");

    return 0;
}