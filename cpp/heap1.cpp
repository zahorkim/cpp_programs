#include <iostream>
using namespace std;

int main()
{
	cout << "입력할 정수의 개수는?";
	int n;
	cin >> n;

	int *p = new int[n];// Heap n*4 bytes
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << "번째 정수를 입력:";
		cin >> p[i]; // cin  >> *(p+i)
	}
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum = sum + p[i];
	cout << "평균 :" << (double)sum / n << endl;
	delete[] p;
//	delete p;//예외발생
	p = NULL; // 메모리 해제되었다고 표시

}
