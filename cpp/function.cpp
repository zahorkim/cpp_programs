//�Ʒ��� ���� ������ ������ �Ǻ���ġ ����(Fibonacci series)�� ���
// 0, 1, 1, 2, 3, 5, ..., 34
//����� ���� �Լ�(int Fibonacci(int n))�� �̿�
// (Recursive function�� ������� ����)

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
		result = fib1(i); //fib1�Լ��� i���� �Ű������� �����ϰ� �� ������� result�� �����Ѵ�. 
		cout << result << ", "; //result�� ����ϰ� ","�� ������ ����Ѵ�. 
		i++; //i�� 1�� ������Ų��. 
	}
}

