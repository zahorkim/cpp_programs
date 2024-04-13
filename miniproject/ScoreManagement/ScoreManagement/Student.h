#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "StudentList.h" 
using namespace std;



class Student
{

protected: //�й� �̸� ���� ���� ���� ��� (p750-751)
	int sNo;
	string name;	
	int kor;
	int eng;
	int math;
	float ave; //���

public:
	//������
	Student(int n=0);
	//�Ҹ���
	virtual ~Student();
	float GetAverage(); //<=====
	virtual void Input(); //Ű���� �Է� 
	virtual void Show(ostream&); //���
	string GetName();
	void Update(); // 
	bool ReadData(char line[]);
};
#endif