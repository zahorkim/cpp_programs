#include <iostream>
using namespace std;


class MyStack
{
private:
	int data[10];
	int tos;//Top Of Stack
public:
	MyStack():tos(-1)
	{
	}
	void Push(int n)
	{
		if (tos == 10 - 1)
		{
			cout << "Stack Overflow!";
			return;
		}
		data[++tos] = n;
	}
	int Pop()
	{
		if (tos < 0)
		{
			cout << "Stack Underflow!";
			return 0;
		}
		return data[tos--];
	}
};

class Circle
{

};

template<class T>
class MyClass
{

};

template <class T>
class Test
{

};

int main()
{
	MyStack<MyClass<Test<int>>,6> s6;

	MyStack<MyClass<int>,5> s4; //T=MyClass<> 

	MyStack<Circle> s3;

	MyStack<> s5;   // T=int size=10

	try
	{
		MyStack<int> s1; //T=int size=10
		s1.Push(10);
		s1.Push(20);
		s1.Push(30);

		cout << s1.Pop() << endl;  //30
		cout << s1.Pop() << endl;  //20
		cout << s1.Pop() << endl;  //10
		cout << s1.Pop() << endl;  // Stack Underflow

	}
	catch (const char* s)
	{
		cout << s << endl;
	}
	catch (...)
	{
		cout << "예외 " << endl;
	}
	MyStack<double,5> s2; //T=double size=5
	s2.Push(1.1);
	s2.Push(2.3);
	s2.Push(3.4);
	cout << s2.Pop() << endl;  //3.4
	cout << s2.Pop() << endl;  //2.3
	cout << s2.Pop() << endl;  //1.1


}

