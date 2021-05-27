#include <iostream>
#include <string>
#include "IOInterface.h"

#ifndef SUBJECT_H
#define SUBJECT_H

class Subject : public IOInterface {
protected:
	std::string SubName;			// 과목이름
	int Hakjum;						// 과목학점 
	std::string Grade;				// 과목등급
	float GPA;						// 과목 평점

public:
	Subject();
	void InputData();									// 멤버변수 값 입력
	void PrintData() const;								// 멤버변수 값 출력
	void CalcGPA();										// 평점 계산
	void Modify();										// 10주차 과제 추가사항
	float GetGPA();										// 평점 반환
	std::string GetSubName();	// 10주차 추가사항
	void PrintData1() const;
};

#endif