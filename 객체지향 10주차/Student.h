#include <string>
#include <iostream>
#include "Subject.h"
#include "IOInterface.h"

#ifndef STUDENT_H
#define STUDENT_H

class Subject;

class Student : public IOInterface{
protected:
	int _Hakbun; // 학번
	int _SubNum; // 과목수
	Subject* _Sub; // 과목 클래스
	float _AveGPA;// 평균 평점

public:
	Student();
	~Student();
	void InputData(); // 멤버변수 값 입력
	void PrintData() const; // 멤버변수 값 출력
	void CalcAveGPA(); // 평균 평점 계산
	Subject* SubSearch(); // 10주차 추가
	void Modify();

	string GetName() override; //iointerface 오버라이드
};


#endif