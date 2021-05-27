#include <iostream>
#include <string>
#include "IOInterface.h"

#ifndef SUBJECT_H
#define SUBJECT_H

class Subject : public IOInterface {
protected:
	std::string SubName;			// �����̸�
	int Hakjum;						// �������� 
	std::string Grade;				// ������
	float GPA;						// ���� ����

public:
	Subject();
	void InputData();									// ������� �� �Է�
	void PrintData() const;								// ������� �� ���
	void CalcGPA();										// ���� ���
	void Modify();										// 10���� ���� �߰�����
	float GetGPA();										// ���� ��ȯ
	std::string GetSubName();	// 10���� �߰�����
	void PrintData1() const;
};

#endif