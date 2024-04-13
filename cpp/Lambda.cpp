#include <iostream>
#include <algorithm> // STL Algorithm
#include <vector>
using namespace std;

void Print(int n)
{
	cout << n << " ";
}
void AddOne(int n)
{
	cout << n + 1 << " ";
}
//int Add(int a, int b); // 선언
//double Add(double a, double b);
int Add(int a, int b)
{
	return a + b;
}


int Square(int a)
{
	return a * a;
}
int main()
{
	vector<int>  v = { 1,2,3,4 };
	for_each(v.begin(),v.end(), Print);   //for_each()
	cout << endl;

	for_each(v.begin(), v.end(), [](int n){cout << n << " "; });
	cout << endl;

	//for (auto it = v.begin(); it != v.end(); it++)
	//	   Print(*it);
	//cout << endl;
	auto it = v.begin();
	for_each(++it, v.end(), AddOne); // 3 4 5
	cout << endl;



	//double d = Add(1.1, 2.2);

	int r = Add(10, 20);
	//Anonymous 함수   Lambda Expression 람다식
	[](int a, int b)->int {return a + b; }(10, 20); //람다식으로 함수를 정의하고 실행
	[](int a, int b) {return a + b; }(10, 20); //람다식으로 함수를 정의하고 실행

	auto add = [](int a, int b) {return a + b; }; //람다식으로 함수를 정의
	r = add(10, 30);

	//람다식으로 함수를 정의
	auto square = [](int a) { return  a * a; };
	//실행
	cout << square(5) << endl;

	double pi = 3.14;
	int temp = 3;
	int test = 10;

	auto calc = [pi](int r) { return pi * r*r; };  //캡처 :람다식밖에 선언되어있는 변수,pi를 람다식안에서 사용
	cout << calc(5) << endl;
	auto calc2 = [pi, temp](int r) {cout << temp << endl;  return pi * r*r; };  // pi, temp
	auto calc3 = [=](int r) {cout << temp << endl;  return pi * r*r; }; //모든 변수

	auto increment = [&temp](int n) { return temp = temp + n; }; //참조형 캡처 -람다식안에서 temp변수를 변경하겠다
	cout << increment(5) << endl;  // temp+5 = 8




}
