#include <iostream>
#include <string>
#include "IOInterface.h"

#ifndef SUBJECT_H
#define SUBJECT_H

class Subject : public IOInterface {
protected:
	int Hakjum;						// �������� 
	string Grade;				// ������
	float GPA;						// ���� ����

public:
	Subject();
	void InputData();									// ������� �� �Է�
	void PrintData() const;								// ������� �� ���
	void CalcGPA();										// ���� ���
	void Modify();										// 10���� ���� �߰�����
	float GetGPA();										// ���� ��ȯ

	void PrintData1() const;

	string GetName() override; //iointerface �������̵�
};

#endif