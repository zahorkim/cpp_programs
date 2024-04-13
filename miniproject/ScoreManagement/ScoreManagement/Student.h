#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "StudentList.h" 
using namespace std;



class Student
{

protected: //학번 이름 국어 수학 영어 평균 (p750-751)
	int sNo;
	string name;	
	int kor;
	int eng;
	int math;
	float ave; //평균

public:
	//생성자
	Student(int n=0);
	//소멸자
	virtual ~Student();
	float GetAverage(); //<=====
	virtual void Input(); //키보드 입력 
	virtual void Show(ostream&); //출력
	string GetName();
	void Update(); // 
	bool ReadData(char line[]);
};
#endif