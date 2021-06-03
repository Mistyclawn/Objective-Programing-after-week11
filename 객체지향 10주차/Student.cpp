#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

Student::Student() {
	_Name = "ȫ�浿";
	_Hakbun = 2019000000;
	_SubNum = 1;
	_Sub = new Subject[_SubNum];
}

Student::~Student() {};

void Student::InputData() {
	cout << "�̸� : ";
	InputValue(_Name);
	cout << "�й� : ";
	InputValue(_Hakbun);
	cout << "����� : ";
	InputValue(_SubNum);
	_Sub = new Subject[_SubNum];
	cout << "������ ���� " << _SubNum << "���� �� �������, ������������ �������� �Է��ϼ���.\n";
	int i;
	for (i = 0; i < _SubNum; i++) {
		_Sub[i].InputData();
		_Sub[i].CalcGPA();
	}
}

void Student::PrintData() const {
	cout << "\n�̸� : " << _Name << "  �й� : " << _Hakbun << "\n";// << "  ����� :" << _SubNum << //������
	cout << "\n==================================================\n      �����        ��������   ������   ��������\n==================================================\n";
	int i;
	for (i = 0; i < _SubNum; i++)
	{
		_Sub[i].PrintData();
	}
	cout << "==================================================\n";
	cout.precision(2);
	cout.width(45);
	cout << "������� : " << _AveGPA << "\n\n";
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
	cout << "\n�˻��� ���� �̸�:";
	InputValue(tempSubName);
	int i = 0;
	int cnt = -1;
	for (i = 0; i < _SubNum; i++)
	{
		temp = _Sub->GetName();
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
		cout << ")�� ������ �����ϼ���.";
		return &_Sub[cnt];
	}
	return NULL;
}

void Student::Modify() {
	cout << "�̸� : ";
	InputValue(_Name);
	cout << "�й� : ";
	InputValue(_Hakbun);
}

string Student:: GetName() {
	return _Name;
}