//명품 C++ 프로그래밍 4장 9번 실습문제를 변경함
//입력받을 사람의 수를 먼저 입력받음(동적 메모리 사용)
//키보드로 이름과  전화번호를 입력받아 출력하고 검색하는 프로그램


#include <iostream>
using namespace std;
#include "Person.h"

int main()
{

		cout << "입력받을 사람  수를 입력하세요: ";
		int size;
		cin >> size;  //<==동적값이 변함
		cout << "이름과 전화번호를 입력해주세요." << endl;

		Person* a = new Person[size];// Heap<-------

		string tempName, tempTel;
		for (int i = 0; i < size; i++)
		{
			cout << "사람 " << i + 1 << ">>";
			cin >> tempName >> tempTel;
			a[i].Set(tempName, tempTel);//parameter 매개변수
		}
		cout << "모든 사람의 이름은 ";
		for (int i = 0; i < size; i++)
		{
			cout << a[i].GetName() << " ";
		}
		cout << endl;

		bool bFind = false;//<===Flag
		while (true)
		{
			cout << "전화번호 검색합니다. 이름을 입력하세요(Quit(q))>>";
			cin >> tempName;
			if (tempName == "q")
				break;
			for (int i = 0; i < size; i++)
			{
				if (a[i].GetName() == tempName)
				{
					cout << "전화번호는 " << a[i].GetTel();
					bFind = true;//<== Flag
					break;
				}
			}
			if (!bFind) //if(bFind == false)
				cout << "해당하는 이름이 없습니다" << endl;
			bFind = false;//<====
		}
		if (a != NULL)
		{
			delete[] a;
			a = NULL;
		}
	}
