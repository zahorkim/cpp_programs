#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include <list>   // STL list
#include "Student.h"

#define MAX 100 //Manifest Constant  ��ó����

using namespace std; //<==

class Student ; //���� ����
	

class  StudentList
{
private://
	//Student sArray[MAX];// �迭
	list<Student> sList;//<==  
	int numberOfStudents; 
	float totalAve; //��ü ���
public:
	enum FORMAT {CONSOLE,TEXTFILE,HTMLFILE};

	StudentList();
	~StudentList();
	bool AddStudent();  //Student
	bool UpdateStudent();  //<===
	bool DeleteStudent();   //<===
	void ShowAll(FORMAT); 
	void ShowAll(FORMAT,bool); 
	void ShowAll(ostream& out);
	float CalTotalAve();//��ü ��� ���ϱ�
	bool ReadData(string filename);
	bool SaveData(string filename);

};

#endif
