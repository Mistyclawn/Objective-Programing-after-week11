#include <string>
#include <iostream>
#include "Subject.h"
#include "IOInterface.h"

#ifndef STUDENT_H
#define STUDENT_H

class Subject;

class Student : public IOInterface{
protected:
	int _Hakbun; // �й�
	int _SubNum; // �����
	Subject* _Sub; // ���� Ŭ����
	float _AveGPA;// ��� ����

public:
	Student();
	~Student();
	void InputData(); // ������� �� �Է�
	void PrintData() const; // ������� �� ���
	void CalcAveGPA(); // ��� ���� ���
	Subject* SubSearch(); // 10���� �߰�
	void Modify();

	string GetName() override; //iointerface �������̵�
};


#endif