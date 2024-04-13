#include "student.h"
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;


// sNo : 학번
Student::Student(int sNo)	
{
	// 학번 대입
	this->sNo	= sNo;

	// 나머지 멤버 초기화
	kor = eng = math = 0;
	ave = 0.0f;
}

// 소멸자
Student::~Student()
{
}

// 개인 정보를 입력받는다.
void Student::Input()
{
	// 해당 학생의 이름, 국영수 점수를 입력받는다.
	cout << "이름(공백없이) 국어, 영어, 수학 점수를 입력하세요 : \n";
	cin >> name >> kor >> eng >> math;

	// 개인 평균을 계산한다.
	ave = float(kor + eng + math) / 3.0f;
}

// 개인 정보를 화면에 출력한다.
void Student::Show(ostream& out) 
{
	out << setw(7) << sNo << setw(7) << name;
	out << setw(5) << kor <<"\t"<< eng;
	out << "\t" << math << "\t";
	out << ave << "\n";
}


float	Student::GetAverage() 
{ 
	return ave;
}
string Student::GetName()
{
	return name;
}
void Student::Update()
{
	int subject;
	int score;
	cout << "수정할 과목을 입력?(국어(1),영어(2),수학(3))";
	cin >>subject;

	switch(subject)
	{
	case 1: //국어
		cout << "점수 입력?";
		cin >> score;
		this->kor = score;
		break;
	case 2://영어
		cout << "점수 입력?";
		cin >> score;
		this->eng = score;
		break;
	case 3: //수학
		cout << "점수 입력?";
		cin >> score;
		this->math = score;
		break;
	default:
		cout << "잘못 입력하셨습니다" << endl;
		break;
	}
	this->ave = (this->kor + eng + math ) /3.0f;
}

bool Student::ReadData(char line[]) // 
{
	char ch;
	stringstream ss(line);//#include <sstream>
	ss >> this->sNo ;
	ss >> this->name ;
	ss >> this->kor;
	ss>> this->eng ;
	ss>> this->math ;
	ss>>  ch; // -
	ss>> this->ave;
	return true;
}