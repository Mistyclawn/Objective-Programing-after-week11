#include <iostream>
#include <string>

#include "Student.h"
#include "Subject.h"
#include "IOInterface.h"

using namespace std;

inline void InputValue(int&); // �Է� �Լ�
inline void InputValue(string&); // �Է� �Լ�
inline void PrintMenu(); // �޴� ��� �Լ�
void PrintAllData(const Student*, int); // ��� �л� ���� ���
void InputData(Student*, int); // ��� �л� ���� �Է�
Student* StdSearch(Student*, int); // �л� �̸� �˻�
void Modify(Student*, int); // �л� ���� ����

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
			printf("\n�л� �� �Է� : "); // studentnum�� �л����Է�
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

	cout << ("���α׷��� �����մϴ�.");
	return 0;
};

void PrintMenu() {
	cout << "\n===== �޴� =====\n";
	cout << "1. �л� ���� �Է�\n";
	cout << "2. ��ü �л� ���� ����\n";
	cout << "3. �л� ���� ����\n";
	cout << "4. ���α׷� ����\n\n";
	cout << "���ϴ� ����� �Է��ϼ���. :";
};

void PrintAllData(const Student* rSt, int studentnum) {
	cout << "\n\n               ��ü �л� ���� ����\n--------------------------------------------------\n";
	int i;
	for (i = 0; i < studentnum; i++) {
		rSt[i].PrintData();
	}
}; // ��� �л� ���� ���

void InputData(Student* stlist, int studentnum) {
	int i;
	for (i = 0; i < studentnum; i++) {
		cout << i + 1 << "��° �л� �̸��� �й��� ������� �Է��ϼ���.\n";
		stlist[i].InputData();
		cout << "\n";
		stlist[i].CalcAveGPA();
	}
}; // ��� �л� ���� �Է�

Student* StdSearch(Student* pSt, int a) {
	string targetStd;
	string tempname;
	cout << "\n�˻��� �л��� �̸� : ";
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
}; // �л� �̸� �˻�

void Modify(Student* pSt, int StdNum) {
	Student* SearchStd;
	SearchStd = StdSearch(pSt, StdNum);
	if (SearchStd != 0) //0�̾ƴϸ� �̸��й� ����
	{
		string Type;
		cout << "\n����(�л�����/��������) :";
		InputValue(Type);

		if (Type == "�л�����")
		{
			SearchStd->Modify();
		}
		else if (Type == "��������")
		{
			Subject* SearchSub = SearchStd->SubSearch();   // ������ Ž��
			if (SearchSub == NULL)
				cout << "\n������ �������� �ʽ��ϴ�.";
			else
			{
				SearchSub->InputData();
			}
		}
	}
	else
		cout << "\n������ �����ϴ�.\n";

	pSt->CalcAveGPA();
}; // �л� ���� ����
