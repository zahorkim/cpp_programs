#include "Person.h"
#include <iostream>
using namespace std;
Person::Person()
{
	//cout << "Person ����Ʈ ������" << endl;
}

void Person::Set(string name, string tel)
{
	this->name = name;
	this->tel = tel;
}
string Person::GetName()
{
	return name;
}
string Person::GetTel()
{
	return tel;
}