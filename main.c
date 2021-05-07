#include <stdio.h>
#include <string.h>
#include "manager.h"

int main(void){
    
    Person p[100];
    int count = 0, menu;
    
    // count = loadData(p);  -- load 함수 부재로 주석 처리 

    while (1){
        menu = selectMenu();
        getchar();
        if(menu == 0) break;
        
        // selectDatNo 구현
        //selectDataNo(p,count);
	}

	printf("\n종료됨!\n");
   	return 0;
}