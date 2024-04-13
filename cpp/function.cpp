//아래와 같은 순서를 가지는 피보나치 수열(Fibonacci series)을 출력
// 0, 1, 1, 2, 3, 5, ..., 34
//사용자 정의 함수(int Fibonacci(int n))를 이용
// (Recursive function을 사용하지 않음)

#include <iostream>
using namespace std;

int fib1(int n) 
{ 
	if (n == 0) return 0; 
	if (n == 1) return 1; 
	int num1 = 0, num2 = 1, temp; 

	for (int i = 1; i < n; i++) 
	{
		temp = num2; 
		num2 = num1 + num2;
		num1 = temp; 
	}
	return num2; 
}
int main() 
{
	int result = 0; 

	int i = 0; 

	while (result < 34) 
	{ 
		result = fib1(i); //fib1함수에 i값을 매개변수로 전달하고 그 결과값을 result에 저장한다. 
		cout << result << ", "; //result를 출력하고 ","와 공백을 출력한다. 
		i++; //i를 1씩 증가시킨다. 
	}
}

