Mini project 주제
=================

편의저 재고 관리 프로그램

한동대학교의 학교 생활 주 필수적 편의시설인 편의점의 재고관리 프로그램으 제작함으로써 재고관리에 좀 더 용이하게 한다. 

Mini project 기능

편의점 재고 관리를 위해 종류, 이름,가격,무게,CRUD 한다.
이러한 정보를 토대로 하여 삭제 및 관리르 할 수 있도록 한다. 

Owner : 최혜림
Collaborator : 김민기
Developer : 최혜림



함수 설명

typedef struct{
    int type; // 제품 종류 ( 1. 음료  2. 과자  3. 라면  4. 밥,죽 )
	char name[60]; // 제품 이름
	int price; // 제품 가격
	int wight; // 제품 무게 
    int count; // 제품 개수
} Product;


int selectMenu(){
<img width="257" alt="스크린샷 2021-05-09 오후 4 40 03" src="https://user-images.githubusercontent.com/79801529/117564190-d7d51f00-b0e5-11eb-80e2-03feae0e2299.png">


int createProduct(Product *p) {

int updateProduct(Product *p) {
<img width="426" alt="스크린샷 2021-05-09 오후 4 49 01" src="https://user-images.githubusercontent.com/79801529/117564345-8d07d700-b0e6-11eb-8170-eabb0807cb45.png">


void listProduct(Product *p[],int num) {

void managerStore(Product *p[], int num) {
