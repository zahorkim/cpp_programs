//�� ���� ������ �Ű�����(parameter, n, r)�� �޾Ƽ� ����(permutation, nPr)�� ����Ͽ� ��ȯ�ϴ� �Լ��� �ۼ�

#include <iostream>
using namespace std;

int nPr(int n, int r) 
{ 

	int per = 1;

	for (int i = 0; i < r; i++) 
	{ 

		per = per * (n - i); //per�� per ���ϱ� n���� i���� �����Ͽ� �����ش�.
	}
	return per; //per�� �������ش�. 
}
int main() 
{ 

	int permut = nPr(6, 3); //�Լ� ȣ��
	cout << permut << endl; //120
}
