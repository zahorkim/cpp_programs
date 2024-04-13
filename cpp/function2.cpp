//두 개의 정수를 매개변수(parameter, n, r)로 받아서 순열(permutation, nPr)을 계산하여 반환하는 함수를 작성

#include <iostream>
using namespace std;

int nPr(int n, int r) 
{ 

	int per = 1;

	for (int i = 0; i < r; i++) 
	{ 

		per = per * (n - i); //per에 per 곱하기 n빼기 i값을 누적하여 곱해준다.
	}
	return per; //per을 리턴해준다. 
}
int main() 
{ 

	int permut = nPr(6, 3); //함수 호출
	cout << permut << endl; //120
}
