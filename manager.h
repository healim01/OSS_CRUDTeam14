#include <stdio.h>
#include <string.h>

typedef struct{
	char name[60]; // 학생 이름
	int id; // 학번
	int grade; // 학년
    char major[60]; // 전공
    int RC; // RC
    int team; // 팀 번호
} Person;

// SELECT
int selectMenu(); // 메뉴 선택 
int selectDataNo(Person *p[], int num); // 번호 선택

// CRUD
int createPerson(Person *p); // 명단 추가하기
void readPerson(Person *p); // 명단 출력하기 
int updatePerson(Person *p); // 명단 업데이트하기   
int deletePerson(Person *p[], int no); // 명단 삭제하기
void listPerson(Person *p[],int num); // 명단 리스트 불러오기

// FILE
void saveData(Person *p[], int num); // 데이타 파일 저장하기 
int loadData(Person *p[]); // 데이타 읽어오기


// SEARCH
void searchName(Person *p[], int num); // 이름으로 검색
void searchid(Person *p[], int num); // 학번으로 검색
void searchmajor(Person *p[], int num); // 전공으로 검색 
void searchgrade(Person *p[], int num); // 학년으로 검색 

// TEAM
int makeTeam(Person *p[], int num); // 긱사별 팀 선정
