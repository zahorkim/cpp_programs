#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include <list>   // STL list
#include "Student.h"

#define MAX 100 //Manifest Constant  전처리기

using namespace std; //<==

class Student ; //전방 참조
	

class  StudentList
{
private://
	//Student sArray[MAX];// 배열
	list<Student> sList;//<==  
	int numberOfStudents; 
	float totalAve; //전체 평균
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
	float CalTotalAve();//전체 평균 구하기
	bool ReadData(string filename);
	bool SaveData(string filename);

};

#endif
