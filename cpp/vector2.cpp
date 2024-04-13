//다음과 같은 동작을 수행햐는 코드를 작성하시오.
//1) 크기가 3x2인 정수(int)를 저장하는 2차원 vector를 선언(m1),
//(m1의 요소는[0][0]에서[2][1]까지 사용할 수 있는 형식)
//2) m1의 요소에[0, 99]의 임의의 값을 저장,
//3) std::vector<std::vector<int>> m2 = Transpose(m1); 의 코드로 m2의[i][k]의 요소가 m1의[k][i]요소로 저장될 수 있는 Transpose 함수 정의
//4) m1과 m2를 화면에 출력

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
	vector<vector<int>>r(v[0].size(), vector<int>(v.size())); /*이차원 벡터 r을 선언하고
 매개변수로 받은 벡터의 인덱스의 두개를 교차로 바꾼 값을 저장할 벡터이므로 저장공간 역시 바꿔서 지정해준다.
 먼저 v의 0번째 인덱스의 사이즈를 행으로 저장하고 열에 v의 사이즈를 저장공간으로 저장한다.*/
	for (int i = 0; i < v.size(); i++)
	{ 
	
		for (int k = 0; k < v[i].size(); k++)
		{
			int t = v[i][k]; //정수형 변수 t를 선언하고 v의 i번째 인덱스에 있는 요소의 k번째 인덱스의 요소를 저장한다.
			r[k][i] = t; //v와 교차한 저장공간에 t의 값을 저장한다. 즉 r의 k인덱스의 요소의 i인덱스 자리에 t를 저장한다.
		}
	}
	return r; //이차원 벡터 r를 리턴한다.
}


int main() 
{
	vector<vector<int>>m1(2, (vector<int>(3))); //크기가 3*2인 정수를 저장하는 2차원 벡터 m1을 선언한다.
	vector<vector<int>>m2; //이차원 벡터 m2를 선언하여 empty로 만들어준다. 
	srand(static_cast<unsigned>(time(0))); //시드를 현재시간으로 지정해준다.

	for (int i = 0; i < m1.size(); i++) 
	{ 
		for (int j = 0; j < m1[i].size(); j++) 
		{
			int r = rand() % 100; //정수형 변수 r를 선언하고 100까지의 임의의 정수를 저장한다.
			m1[i][j] = r; //m1의 i인덱스 요소의 j인덱스 자리에 r를 저장한다.
		}
	}
	print(m1); //print 함수를 호출해 m1을 인수로 전달한다.
	m2 = Transpose(m1); //Transpose함수를 호출해 m1을 인수로 전달하여 그 리턴값을 m2에 저장한다.
	cout << endl; //줄바꿈해준다. 
	print(m2); //print 함수를 호출해 m2을 인수로 전달한다.
}

//출력:
//27, 93, 50,
//99, 34, 29,
//
//27, 99,
//93, 34,
//50, 29,
