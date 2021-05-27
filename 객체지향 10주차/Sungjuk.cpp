#include <iostream>
#include <string>

#include "Student.h"
#include "Subject.h"
#include "IOInterface.h"

using namespace std;

inline void InputValue(int&); // 입력 함수
inline void InputValue(string&); // 입력 함수
inline void PrintMenu(); // 메뉴 출력 함수
void PrintAllData(const Student*, int); // 모든 학생 정보 출력
void InputData(Student*, int); // 모든 학생 정보 입력
Student* StdSearch(Student*, int); // 학생 이름 검색
void Modify(Student*, int); // 학생 정보 수정

inline void InputValue(int& i) {
	cin >> i;
	cin.ignore();
};
inline void InputValue(string& A) {
	getline(cin, A);
};

int main() {

	int menn = 0;
	int studentnum = 1;
	Student* stlist = new Student[studentnum];
	while (menn != 4)
	{
		PrintMenu();
		InputValue(menn);
		if (menn == 1)
		{
			printf("\n학생 수 입력 : "); // studentnum에 학생수입력
			InputValue(studentnum); 
			stlist = new Student[studentnum];
			InputData(stlist, studentnum);
		}
		if (menn == 2)
		{
			PrintAllData(stlist, studentnum);
		}
		if (menn == 3) {
			Modify(stlist, studentnum);
		}
	};

	cout << ("프로그램을 종료합니다.");
	return 0;
};

void PrintMenu() {
	cout << "\n===== 메뉴 =====\n";
	cout << "1. 학생 성적 입력\n";
	cout << "2. 전체 학생 성적 보기\n";
	cout << "3. 학생 성적 수정\n";
	cout << "4. 프로그램 종료\n\n";
	cout << "원하는 기능을 입력하세요. :";
};

void PrintAllData(const Student* rSt, int studentnum) {
	cout << "\n\n               전체 학생 성적 보기\n--------------------------------------------------\n";
	int i;
	for (i = 0; i < studentnum; i++) {
		rSt[i].PrintData();
	}
}; // 모든 학생 정보 출력

void InputData(Student* stlist, int studentnum) {
	int i;
	for (i = 0; i < studentnum; i++) {
		cout << i + 1 << "번째 학생 이름과 학번과 과목수를 입력하세요.\n";
		stlist[i].InputData();
		cout << "\n";
		stlist[i].CalcAveGPA();
	}
}; // 모든 학생 정보 입력

Student* StdSearch(Student* pSt, int a) {
	string targetStd;
	string tempname;
	cout << "\n검색할 학생의 이름 : ";
	InputValue(targetStd);
	
	int i;
	int cnt = 0;
	for (i = 0; i < a; i++)
	{
		tempname = pSt[i].GetStdName();
		if (tempname == targetStd){
			cnt++;
			return &pSt[i];
		}
	}
	if (cnt == 0) {
		return 0;
	}
}; // 학생 이름 검색

void Modify(Student* pSt, int StdNum) {
	Student* SearchStd;
	SearchStd = StdSearch(pSt, StdNum);
	if (SearchStd != 0) //0이아니면 이름학번 수정
	{
		string Type;
		cout << "\n수정(학생정보/과목정보) :";
		InputValue(Type);

		if (Type == "학생정보")
		{
			SearchStd->Modify();
		}
		else if (Type == "과목정보")
		{
			Subject* SearchSub = SearchStd->SubSearch();   // 교과목 탐색
			if (SearchSub == NULL)
				cout << "\n과목이 존재하지 않습니다.";
			else
			{
				SearchSub->InputData();
			}
		}
	}
	else
		cout << "\n정보가 없습니다.\n";

	pSt->CalcAveGPA();
}; // 학생 정보 수정
