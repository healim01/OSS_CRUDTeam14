#include <stdio.h>
#include <string.h>

typedef struct{
    int type; // 제품 종류 ( 1. 음료  2. 과자  3. 라면  4. 밥,죽 )
	char name[60]; // 제품 이름
	int price; // 제품 가격
	int wight; // 제품 무게 
    int count; // 제품 개수
} Product;

// SELECT
int selectMenu(); // 메뉴 선택 
int selectDataNo(Product *p[], int num); // 번호 선택

// CRUD
int createProduct(Product *p); // 제품 추가하기
void readProduct(Product *p); // 제품 읽어오기
int updateProduct(Product *p); // 제품 수정하기   
int deleteProduct(Product *p, int no); // 제품 삭제하기       
void listProduct(Product *p,int count); // 제품 리스트 가져오기

// FILE
void saveData(Product *p, int count); // 데이타 파일 저장하기 
int loadData(Product *p); // 데이타 읽어오기

// SEARCH
void searchName(Product *p[], int num); // 이름으로 검색
void searchType(Product *p[], int num); // 종류로 검색
void searchPrice(Product *p[], int num); // 가격으로 검색 

// MANAGER
void managerStore(Product *p[],int num); // 재고 관리 
