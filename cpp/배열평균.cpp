
//1차원 정수 5개 배열 선언하고 5개 입력 받아 배열 저장 후 평균 구하기
#include <iostream>
using namespace std;

double average(int*a,int size)
{
	int sum=0;
	for (int i = 0; i < size; i++)
		sum += a[i];
	double ave = (double)sum / size;

	return ave;
} 
int main()
{
	int a[5];
	int b;
	for (int i = 0; i < 5; i++)
	{
		cout << "점수를 입력하세요:";
		cin >> b;	
		a[i]=b;
	}
	double sum = average(a, 5);
	cout << "평균은" <<sum << "입니다.";
	return 0;

}
