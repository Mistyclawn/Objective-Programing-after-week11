#include <iostream>
#include <string>

#include "Subject.h"

using namespace std;

Subject::Subject() {
	SubName = "����";
	Hakjum = 3;
	Grade = "A";
}

void Subject::InputData() {
	cout << "\n������� : ";
	InputValue(SubName);
	cout << "���������� : ";
	InputValue(Hakjum);
	cout << "������(A+ ~ F) : ";
	InputValue(Grade);
	cout << "\n";
	CalcGPA();
}
void Subject::PrintData() const {

	cout.width(18);
	cout << SubName;
	cout.width(10);
	cout << Hakjum;
	cout.width(10);
	cout << Grade;
	cout.width(10);
	cout << fixed;
	cout.precision(2);
	cout << GPA;
	cout << "\n";
}				// ������� �� ���

void Subject::PrintData1() const {
	cout << "\n*(" << SubName << ", ���� :" << Hakjum << ", ��� :" << Grade;
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
}						// ���� ���, ���� �ǽ������� CalcGPA �Լ��� Grading �Լ��� ��

float Subject::GetGPA() {
	return GPA;
}						// ���� ��ȯ

void Subject::Modify() {
	cout << "\n������� : ";
	InputValue(SubName);
	cout << "���������� : ";
	InputValue(Hakjum);
	cout << "������(A+ ~ F) : ";
	InputValue(Grade);
	cout << "\n";
	CalcGPA();
}

string Subject::GetSubName() {
	return SubName;
}