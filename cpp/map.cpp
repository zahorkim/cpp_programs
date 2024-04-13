
#include <iostream>
using namespace std;
#include <map>
#include <string>


int main()
{
//	map<string, string,greater<string>> dic;  key내림차순
	map<string, string> dic; // less<> 조건자  key 오름차순
	    //key      value
	dic.insert(make_pair("banana", "바나나"));
	dic.insert(pair<string, string>("apple", "사과"));
	dic["kiwi"] = "키위";  // dic[key]=value 없으면 추가, 있으면 수정

	//map<string, string>::iterator it = dic.begin();
	auto it = dic.begin();
	for (; it != dic.end(); it++)
		cout << (*it).first << "\t" << it->second << endl;
	                //key                         value
	//검색
	if (dic.find("melon") == dic.end())
		cout << "없다" << endl;
	else
		cout << "있다" << endl;


}

