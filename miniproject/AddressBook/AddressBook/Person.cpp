#include "Person.h"
#include <iostream>
using namespace std;
Person::Person()
{
	//cout << "Person 디폴트 생성자" << endl;
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