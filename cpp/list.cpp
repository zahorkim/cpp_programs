#include <iostream>
#include <list>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector<string> v= { "kiwi","apple","banana" };
	sort(v.begin(), v.end());  //sort algorithm  오름차순 less<>조건자
	for (auto s : v)
		cout << s << endl;
	cout << "----------" << endl;

	sort(v.begin(), v.end() , greater<string>() );  //sort algorithm  오름차순 less<>조건자 -함수로 구현
	for (auto s : v)
		cout << s << endl;
	cout << "----------" << endl;

	list<string> slist = {"kiwi","apple","banana"};
	//sort(slist.begin(), slist.end());
	slist.sort();
	for (auto str : slist)
		cout << str << endl;

	list<Circle>  clist;

	list<int>  il;
	il.push_back(10);
	il.push_back(20);
	il.push_back(30);
	
	for (int a : il)
		cout << a << endl;  
	cout << "-----------" << endl;

	auto it = il.begin();
	//list<int>::iterator it = il.begin();
	for (; it != il.end(); it++)
		cout << *it << endl;  // 10 20 30
	cout << "-----------" << endl;

	it = il.begin();
	it++;
	it++;
	il.insert(it, 99);  // 10 20 99 30

	for (int a : il)
		cout << a << endl;
	cout << "-----------" << endl;
	il.remove(20);  // 10 99 30

	for (int a : il)
		cout << a << endl;
	cout << "-----------" << endl;


}
