#include <iostream>
#include <fstream> // ofstream
#include "StudentList.h"

using namespace std;

StudentList::StudentList()
	: numberOfStudents(0), totalAve(0)
{
}
StudentList::~StudentList()
{
}

bool StudentList::AddStudent()
{
	// 배열로 저장하는 경우,최대수 체크
	//if (numberOfStudents  == MAX)
	//           return false;


	Student s(numberOfStudents + 1);//sNo 학번, 객체 생성f
	s.Input(); // 입력받아서
	//sArray[numberOfStudents] = s;//배열에 복사
	sList.push_back(s); //list에 추가


	numberOfStudents++;
	totalAve = CalTotalAve();//<===전체 평균구해서 저장 
	return true;
}
void StudentList::ShowAll(FORMAT fmt)
{
	//ostream& out=cout;
	ostream  *temp=NULL;
	//파일로 저장
	ofstream outfile;
	if (fmt == CONSOLE)
	{
		temp = &cout;
	}
	else if (fmt == TEXTFILE)
	{
		outfile.open("report.txt");
		if (outfile.is_open() == false)
			throw "File Open Error";
		temp = &outfile;
	}
	else if (fmt == HTMLFILE)
	{
		temp = &cout;//디폴트는 화면
	}
	ostream& out = *temp;

	out.precision(2);//소수점이하 둘째자리까지
	out << fixed;



	out << "\n		<전체 성적 보기>		" << endl;
	out << "학번\t이름\t국어\t영어\t수학\t평균" << endl;

	//for(int i =0; i< numberOfStudents ;i++)
	// 	sArray[i].Show ();//배열

	list<Student>::iterator it;
	for (it = sList.begin(); it != sList.end(); it++)
		(*it).Show(out);//?

	out << endl;
	out << "전체 평균 =" << CalTotalAve() << endl;
}
void StudentList::ShowAll(ostream& out)
{

	out.precision(2);//소수점이하 둘째자리까지
	out << fixed;


	out << "\n		<전체 성적 보기>		" << endl;
	out << "학번\t이름\t국어\t영어\t수학\t평균" << endl;

	//for(int i =0; i< numberOfStudents ;i++)
	// 	sArray[i].Show ();//배열

	list<Student>::iterator it;
	for (it = sList.begin(); it != sList.end(); it++)
		(*it).Show(out);//?

	out << endl;
	out << "전체 평균 =" << CalTotalAve() << endl;
}

void StudentList::ShowAll(FORMAT fmt, bool bReport)
{
	//ostream& out=cout;
	ostream  *temp=NULL;
	//파일로 저장
	ofstream outfile;
	if (fmt == CONSOLE)
	{
		temp = &cout;
	}
	else if (fmt == TEXTFILE)
	{
		if (bReport)
		{
			outfile.open("report.txt");
		}
		else
		{
			outfile.open("data.txt");
		}
		if (outfile.is_open() == false)
			throw "File Open Error";
		temp = &outfile;
	}
	else if (fmt == HTMLFILE)
	{
		temp = &cout;//디폴트는 화면
	}
	ostream& out = *temp;
		out.precision(2);//소수점이하 둘째자리까지
		out << fixed;

		if (bReport)
		{
			out << "\n		<전체 성적 보기>		" << endl;
			out << "학번\t이름\t국어\t영어\t수학\t평균" << endl;
		}
		//for(int i =0; i< numberOfStudents ;i++)
		// 	sArray[i].Show ();//배열

		list<Student>::iterator it;
		for (it = sList.begin(); it != sList.end(); it++)
			(*it).Show(out);//?

		if (bReport)
		{
			out << endl;
			out << "전체 평균 =";
		}
		cout << CalTotalAve() << endl;
	}

float StudentList::CalTotalAve()
{
	float sum = 0;
	//for(int i =0; i<numberOfStudents;i++)
	//	sum = sum + sArray[i].GetAverage (); //배열
	list<Student>::iterator it;
	for (it = sList.begin(); it != sList.end(); it++)
		sum = sum + (*it).GetAverage();  // list사용
	return sum / numberOfStudents;
}
bool StudentList::UpdateStudent()
{
	string name;
	cout << "수정할 학생의 이름을 입력?";
	cin >> name;

	list<Student>::iterator it;
	for (it = sList.begin(); it != sList.end(); it++)
	{
		if ((*it).GetName() == name)  //<==Student::GetName()
			break;
	}

	if (it == sList.end())  // 해당 학생이 없음
	{
		return false;
	}
	else //해당 학생을 찾음
	{
		it->Update();   //(*it).Update(); //<====Student::Update()
		return true;
	}
}
bool StudentList::DeleteStudent()
{
	string name;
	cout << "수정할 학생의 이름을 입력?";
	cin >> name;

	list<Student>::iterator it;
	for (it = sList.begin(); it != sList.end(); it++)
	{
		if ((*it).GetName() == name)  //<==Student::GetName()
			break;
	}

	if (it == sList.end())  // 해당 학생이 없음
	{
		return false;
	}
	else //해당 학생을 찾음
	{
		sList.erase(it);//<== 삭제
		numberOfStudents--;
		return true;
	}
}

bool StudentList::ReadData(string filename)
{
	ifstream infile(filename);
	if (!infile)
	{
		cout << "File open error" << endl;
		return false;
	}
	char line[100];

	//infile >> numberOfStudents;  >> 줄바꿈문자못읽음
	//infile.getline(line,100);  // \n

	infile.getline(line, 100);
	numberOfStudents = atoi(line);  //char[] => int

	for (int i = 0; i < numberOfStudents; i++)
	{
		infile.getline(line, 100); //파일에서 한 줄 읽어오기 : Student Data
		Student s;
		if (s.ReadData(line))	  //Student::ReadData()추가
			sList.push_back(s);//Student를 list에 추가
	}
	infile.close();
	this->totalAve = this->CalTotalAve();//<====

	return true;
}
bool StudentList::SaveData(string filename)
{
	ofstream outfile(filename);
	if (!outfile)
	{
		cout << "File open error" << endl;
		return false;
	}
	outfile << sList.size() << endl; // List 크기  <=== ? 

	list<Student>::iterator it;
	for (it = sList.begin(); it != sList.end(); it++)
	{
		it->Show(outfile); //Student::Show();
	//	outfile << it->GetNo() <<" " << it->GetName ()  <<endl;
	}

	//outfile << this->totalAve << endl;
	outfile.close();
	return true;
}