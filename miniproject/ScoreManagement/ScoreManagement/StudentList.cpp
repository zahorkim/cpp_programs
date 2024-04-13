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
	// �迭�� �����ϴ� ���,�ִ�� üũ
	//if (numberOfStudents  == MAX)
	//           return false;


	Student s(numberOfStudents + 1);//sNo �й�, ��ü ����f
	s.Input(); // �Է¹޾Ƽ�
	//sArray[numberOfStudents] = s;//�迭�� ����
	sList.push_back(s); //list�� �߰�


	numberOfStudents++;
	totalAve = CalTotalAve();//<===��ü ��ձ��ؼ� ���� 
	return true;
}
void StudentList::ShowAll(FORMAT fmt)
{
	//ostream& out=cout;
	ostream  *temp=NULL;
	//���Ϸ� ����
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
		temp = &cout;//����Ʈ�� ȭ��
	}
	ostream& out = *temp;

	out.precision(2);//�Ҽ������� ��°�ڸ�����
	out << fixed;



	out << "\n		<��ü ���� ����>		" << endl;
	out << "�й�\t�̸�\t����\t����\t����\t���" << endl;

	//for(int i =0; i< numberOfStudents ;i++)
	// 	sArray[i].Show ();//�迭

	list<Student>::iterator it;
	for (it = sList.begin(); it != sList.end(); it++)
		(*it).Show(out);//?

	out << endl;
	out << "��ü ��� =" << CalTotalAve() << endl;
}
void StudentList::ShowAll(ostream& out)
{

	out.precision(2);//�Ҽ������� ��°�ڸ�����
	out << fixed;


	out << "\n		<��ü ���� ����>		" << endl;
	out << "�й�\t�̸�\t����\t����\t����\t���" << endl;

	//for(int i =0; i< numberOfStudents ;i++)
	// 	sArray[i].Show ();//�迭

	list<Student>::iterator it;
	for (it = sList.begin(); it != sList.end(); it++)
		(*it).Show(out);//?

	out << endl;
	out << "��ü ��� =" << CalTotalAve() << endl;
}

void StudentList::ShowAll(FORMAT fmt, bool bReport)
{
	//ostream& out=cout;
	ostream  *temp=NULL;
	//���Ϸ� ����
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
		temp = &cout;//����Ʈ�� ȭ��
	}
	ostream& out = *temp;
		out.precision(2);//�Ҽ������� ��°�ڸ�����
		out << fixed;

		if (bReport)
		{
			out << "\n		<��ü ���� ����>		" << endl;
			out << "�й�\t�̸�\t����\t����\t����\t���" << endl;
		}
		//for(int i =0; i< numberOfStudents ;i++)
		// 	sArray[i].Show ();//�迭

		list<Student>::iterator it;
		for (it = sList.begin(); it != sList.end(); it++)
			(*it).Show(out);//?

		if (bReport)
		{
			out << endl;
			out << "��ü ��� =";
		}
		cout << CalTotalAve() << endl;
	}

float StudentList::CalTotalAve()
{
	float sum = 0;
	//for(int i =0; i<numberOfStudents;i++)
	//	sum = sum + sArray[i].GetAverage (); //�迭
	list<Student>::iterator it;
	for (it = sList.begin(); it != sList.end(); it++)
		sum = sum + (*it).GetAverage();  // list���
	return sum / numberOfStudents;
}
bool StudentList::UpdateStudent()
{
	string name;
	cout << "������ �л��� �̸��� �Է�?";
	cin >> name;

	list<Student>::iterator it;
	for (it = sList.begin(); it != sList.end(); it++)
	{
		if ((*it).GetName() == name)  //<==Student::GetName()
			break;
	}

	if (it == sList.end())  // �ش� �л��� ����
	{
		return false;
	}
	else //�ش� �л��� ã��
	{
		it->Update();   //(*it).Update(); //<====Student::Update()
		return true;
	}
}
bool StudentList::DeleteStudent()
{
	string name;
	cout << "������ �л��� �̸��� �Է�?";
	cin >> name;

	list<Student>::iterator it;
	for (it = sList.begin(); it != sList.end(); it++)
	{
		if ((*it).GetName() == name)  //<==Student::GetName()
			break;
	}

	if (it == sList.end())  // �ش� �л��� ����
	{
		return false;
	}
	else //�ش� �л��� ã��
	{
		sList.erase(it);//<== ����
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

	//infile >> numberOfStudents;  >> �ٹٲ޹��ڸ�����
	//infile.getline(line,100);  // \n

	infile.getline(line, 100);
	numberOfStudents = atoi(line);  //char[] => int

	for (int i = 0; i < numberOfStudents; i++)
	{
		infile.getline(line, 100); //���Ͽ��� �� �� �о���� : Student Data
		Student s;
		if (s.ReadData(line))	  //Student::ReadData()�߰�
			sList.push_back(s);//Student�� list�� �߰�
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
	outfile << sList.size() << endl; // List ũ��  <=== ? 

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