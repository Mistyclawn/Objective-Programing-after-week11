#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

Student::Student() {
	_StdName = "홍길동";
	_Hakbun = 2019000000;
	_SubNum = 1;
	_Sub = new Subject[_SubNum];
}

Student::~Student() {};

void Student::InputData() {
	cout << "이름 : ";
	InputValue(_StdName);
	cout << "학번 : ";
	InputValue(_Hakbun);
	cout << "과목수 : ";
	InputValue(_SubNum);
	_Sub = new Subject[_SubNum];
	cout << "수강한 과목 " << _SubNum << "개의 각 교과목명, 과목학점수와 과목등급을 입력하세요.\n";
	int i;
	for (i = 0; i < _SubNum; i++) {
		_Sub[i].InputData();
		_Sub[i].CalcGPA();
	}
}

void Student::PrintData() const {
	cout << "\n이름 : " << _StdName << "  학번 : " << _Hakbun << "\n";// << "  과목수 :" << _SubNum << //빼놓자
	cout << "\n==================================================\n      과목명        과목학점   과목등급   과목평점\n==================================================\n";
	int i;
	for (i = 0; i < _SubNum; i++)
	{
		_Sub[i].PrintData();
	}
	cout << "==================================================\n";
	cout.precision(2);
	cout.width(45);
	cout << "평균평점 : " << _AveGPA << "\n\n";
}

void Student::CalcAveGPA() {
	int i;
	float temp;
	float score = 0;
	for (i = 0; i < _SubNum; i++) {
		temp = _Sub[i].GetGPA();
		score = score + temp;
	}
	_AveGPA = score / _SubNum;
}

Subject* Student::SubSearch() {
	string tempSubName;
	string temp;
	cout << "\n검색할 과목 이름:";
	InputValue(tempSubName);
	int i = 0;
	int cnt = -1;
	for (i = 0; i < _SubNum; i++)
	{
		temp = _Sub->GetSubName();
		if (temp.compare(tempSubName) == 0) {
			cnt = i;
			break;
		}
	}
	if (cnt == -1)
	{
		return NULL;
	}
	else
	{
		_Sub[cnt].PrintData1();
		cout << ")의 정보를 수정하세요.";
		return &_Sub[cnt];
	}
	return NULL;
}

void Student::Modify() {
	cout << "이름 : ";
	InputValue(_StdName);
	cout << "학번 : ";
	InputValue(_Hakbun);
}

string Student::GetStdName() {
	return _StdName;
}