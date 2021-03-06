#include <iostream>
#include <string>

#include "Subject.h"

using namespace std;

Subject::Subject() {
	_Name = "국어";
	Hakjum = 3;
	Grade = "A";
}

void Subject::InputData() {
	cout << "\n교과목명 : ";
	InputValue(_Name);
	cout << "과목학점수 : ";
	InputValue(Hakjum);
	cout << "과목등급(A+ ~ F) : ";
	InputValue(Grade);
	cout << "\n";
	CalcGPA();
}
void Subject::PrintData() const {

	cout.width(18);
	cout << _Name;
	cout.width(10);
	cout << Hakjum;
	cout.width(10);
	cout << Grade;
	cout.width(10);
	cout << fixed;
	cout.precision(2);
	cout << GPA;
	cout << "\n";
}				// 멤버변수 값 출력

void Subject::PrintData1() const {
	cout << "\n*(" << _Name << ", 학점 :" << Hakjum << ", 등급 :" << Grade;
}

void Subject::CalcGPA() {
	float Gradescore = 0;
	if (Grade.compare("A+") == 0)
		Gradescore = 4.5;
	else if (Grade.compare("A0") == 0)
		Gradescore = 4.0;
	else if (Grade.compare("B+") == 0)
		Gradescore = 3.5;
	else if (Grade.compare("B0") == 0)
		Gradescore = 3.0;
	else if (Grade.compare("C+") == 0)
		Gradescore = 2.5;
	else if (Grade.compare("C0") == 0)
		Gradescore = 2.0;
	else if (Grade.compare("D+") == 0)
		Gradescore = 1.5;
	else if (Grade.compare("D0") == 0)
		Gradescore = 1.0;
	else
		Gradescore = 0;

	GPA = Gradescore * Hakjum;
}						// 평점 계산, 원본 실습에서는 CalcGPA 함수와 Grading 함수로 나

float Subject::GetGPA() {
	return GPA;
}						// 평점 반환

void Subject::Modify() {
	cout << "\n교과목명 : ";
	InputValue(_Name);
	cout << "과목학점수 : ";
	InputValue(Hakjum);
	cout << "과목등급(A+ ~ F) : ";
	InputValue(Grade);
	cout << "\n";
	CalcGPA();
}


string Subject::GetName() {
	return _Name;
}