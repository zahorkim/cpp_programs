#pragma once

#include <string>
using namespace std;

class Person
{
	string name;
	string tel;
public:
	Person(); 
	string GetName();
	string GetTel();
	void Set(string name, string tel);
};