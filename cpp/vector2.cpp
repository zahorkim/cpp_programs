//������ ���� ������ ������� �ڵ带 �ۼ��Ͻÿ�.
//1) ũ�Ⱑ 3x2�� ����(int)�� �����ϴ� 2���� vector�� ����(m1),
//(m1�� ��Ҵ�[0][0]����[2][1]���� ����� �� �ִ� ����)
//2) m1�� ��ҿ�[0, 99]�� ������ ���� ����,
//3) std::vector<std::vector<int>> m2 = Transpose(m1); �� �ڵ�� m2��[i][k]�� ��Ұ� m1��[k][i]��ҷ� ����� �� �ִ� Transpose �Լ� ����
//4) m1�� m2�� ȭ�鿡 ���

#include <iostream>
#include <vector> 
#include<cstdlib>
#include<ctime> 
using namespace std;

void print(vector<vector<int>> v) 
{
	for (int i = 0; i < v.size(); i++) 
	{ 
		for (int j = 0; j < v[i].size(); j++) 
		{ 
			cout << v[i][j] << ","; 
		}
		cout << endl;
	}
}

vector<vector<int>> Transpose(vector<vector<int>>v)
{ 
	vector<vector<int>>r(v[0].size(), vector<int>(v.size())); /*������ ���� r�� �����ϰ�
 �Ű������� ���� ������ �ε����� �ΰ��� ������ �ٲ� ���� ������ �����̹Ƿ� ������� ���� �ٲ㼭 �������ش�.
 ���� v�� 0��° �ε����� ����� ������ �����ϰ� ���� v�� ����� ����������� �����Ѵ�.*/
	for (int i = 0; i < v.size(); i++)
	{ 
	
		for (int k = 0; k < v[i].size(); k++)
		{
			int t = v[i][k]; //������ ���� t�� �����ϰ� v�� i��° �ε����� �ִ� ����� k��° �ε����� ��Ҹ� �����Ѵ�.
			r[k][i] = t; //v�� ������ ��������� t�� ���� �����Ѵ�. �� r�� k�ε����� ����� i�ε��� �ڸ��� t�� �����Ѵ�.
		}
	}
	return r; //������ ���� r�� �����Ѵ�.
}


int main() 
{
	vector<vector<int>>m1(2, (vector<int>(3))); //ũ�Ⱑ 3*2�� ������ �����ϴ� 2���� ���� m1�� �����Ѵ�.
	vector<vector<int>>m2; //������ ���� m2�� �����Ͽ� empty�� ������ش�. 
	srand(static_cast<unsigned>(time(0))); //�õ带 ����ð����� �������ش�.

	for (int i = 0; i < m1.size(); i++) 
	{ 
		for (int j = 0; j < m1[i].size(); j++) 
		{
			int r = rand() % 100; //������ ���� r�� �����ϰ� 100������ ������ ������ �����Ѵ�.
			m1[i][j] = r; //m1�� i�ε��� ����� j�ε��� �ڸ��� r�� �����Ѵ�.
		}
	}
	print(m1); //print �Լ��� ȣ���� m1�� �μ��� �����Ѵ�.
	m2 = Transpose(m1); //Transpose�Լ��� ȣ���� m1�� �μ��� �����Ͽ� �� ���ϰ��� m2�� �����Ѵ�.
	cout << endl; //�ٹٲ����ش�. 
	print(m2); //print �Լ��� ȣ���� m2�� �μ��� �����Ѵ�.
}

//���:
//27, 93, 50,
//99, 34, 29,
//
//27, 99,
//93, 34,
//50, 29,
