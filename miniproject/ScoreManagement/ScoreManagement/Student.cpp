#include "student.h"
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;


// sNo : �й�
Student::Student(int sNo)	
{
	// �й� ����
	this->sNo	= sNo;

	// ������ ��� �ʱ�ȭ
	kor = eng = math = 0;
	ave = 0.0f;
}

// �Ҹ���
Student::~Student()
{
}

// ���� ������ �Է¹޴´�.
void Student::Input()
{
	// �ش� �л��� �̸�, ������ ������ �Է¹޴´�.
	cout << "�̸�(�������) ����, ����, ���� ������ �Է��ϼ��� : \n";
	cin >> name >> kor >> eng >> math;

	// ���� ����� ����Ѵ�.
	ave = float(kor + eng + math) / 3.0f;
}

// ���� ������ ȭ�鿡 ����Ѵ�.
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
	cout << "������ ������ �Է�?(����(1),����(2),����(3))";
	cin >>subject;

	switch(subject)
	{
	case 1: //����
		cout << "���� �Է�?";
		cin >> score;
		this->kor = score;
		break;
	case 2://����
		cout << "���� �Է�?";
		cin >> score;
		this->eng = score;
		break;
	case 3: //����
		cout << "���� �Է�?";
		cin >> score;
		this->math = score;
		break;
	default:
		cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
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