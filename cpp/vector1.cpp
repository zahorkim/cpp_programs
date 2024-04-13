#include <iostream>
#include <vector>
#include<string>
using namespace std;

class BigUnsigned 
{
	vector<unsigned int > a;
public:
	BigUnsigned() 
	{ 
		a.push_back(0);
	}
	BigUnsigned(unsigned int c)
	{
		string s = to_string(c); /*string의 객체 s를 선언하고 파라메타로 받은 c를 to_string 함수로 string으로 변환하여 저장한다.*/
		ToVector(s);/*ToVector함수로 s를 전달한다. string s를 vector a에 저장해주는 함수이다.*/

	}
	BigUnsigned(string s) 
	{
		ToVector(s); /*파라메타로 받은 s를 ToVector함수로 전달한다. string s를 vector a에 저장해주는 함수이다*/
	}
	BigUnsigned operator+(BigUnsigned a1) 
	{
		unsigned int n1, n2; /*unsigned int n1,n2를 선언하다.*/
		n1 = this->ToInt(); /*연산자를 호출한 객체의 맴버로 ToInt 함수를 호출하고 그 결과값을 n1에 저장한다.*/
		n2 = a1.ToInt();/*파라메타로 받은 a1로 ToInt함수를 호출하여 결과값을 n2에 저장한다.*/
		unsigned int temp = n1 + n2; /*unsigned int temp에 n1과 n2를 더한 값을 저장한다.*/
		BigUnsigned a2(temp); /*unsigned int를 파라메타로 받는 생성자를 호출하여 a2를 생성한다.*/
		return a2; /*a2를 리턴한다. */
	}

	/* vector a에 저장되어 있는 값을 unsigned int로 변환하는 함수*/
	/* 예 a[2]=1,a[1]=2,a[0]=3을  123으로 변환 */
	unsigned int ToInt()
	{
		unsigned int n = 0; /*n을 선언하고 0을 초기화한다. */
		for (int i = a.size() - 1; i >= 0; i--)/*i를 a의 size-1로 설정한다. 즉 마지막 인덱스 요소부터 먼저 접근한다.*/
		{
			n *= 10;/*더 높은 인덱스 값이 더 높은 자릿수 이므로 누적하여 10을 곱해줌으로 더 높은 자릿수로 만들어준다.*/
			n = n + a[i]; /*n에 a의 i인덱스의 요소를 더해준다. */
		}
		return n; /*n를 리턴한다.*/
	}
	/*string s의 값을 vector a에 저장해주는 함수  */
	/*예 "123"을  a[2]=1 a[1]=2 a[0]=3 을 변환*/
	void ToVector(string s) /*string을 파라메타로 받는 ToVector함수 정의.*/
	{
		int len = s.length(); /*정수형 변수 len에 s의 길이를 저장한다.*/
		int temp; /*정수형 변수 temp를 선언한다.*/
		for (int i = 0; i < len; i++) /*int i가 0부터 len보다 작을때까지 실행한다.*/
		{
			temp = s[len - i - 1] - 48;/*temp에 len에 i를 빼고 1을 뺀 값, 즉 s의 제일 마지막 인덱스의 요소 부터 접근한다.
									   아스키 코드로 저장되기 때문에 숫자 0의 아스키 코드 값(48)을 빼준 값을 저장한다.*/
			a.push_back(temp); /*private 멤버 벡터 a에 temp를 하나씩 저장한다. 일의 자리수를 0인덱스 부터 순서대로 저장한다.*/
		}
	}
	friend ostream& operator<<(ostream& os, const BigUnsigned a); /*operator<<를 오버로딩 하는 함수를 friend 선언해준다.*/
};

ostream& operator<<(ostream& os, const BigUnsigned big) 
{ 
	for (int i = big.a.size() - 1; i >= 0; i--) 
	{ 
		os << big.a[i];  /*마지막 인덱스의 요소부터 0번 인덱스의 요소까지 전달한다.*/
	}
	return os;
}
int main() 
{
	string str = "13524"; /*string의 객체 str을 "13524"로 초기화한다.*/
	BigUnsigned u1; /*파라메타가 없는 생성자를 호출하여 u1을 생성한다.*/
	BigUnsigned u2(56); /*파라메타가 unsigned int인 생성자를 호출하여 u2을 생성한다.*/
	BigUnsigned u3(str); /*파라메타가 string인 생성자를 호출하여 u3을 생성한다.*/
	BigUnsigned u4(678); /*파라메타가 unsigned int인 생성자를 호출하여 u4을 생성한다.*/
	cout << u1 << endl; /*u1을 출력한다.*/
	cout << u2 << endl;/*u2을 출력한다.*/
	cout << u3 << endl;/*u3을 출력한다.*/
	cout << u4 << endl;/*u4을 출력한다.*/
	u1 = u2 + u3; /*u1에 u2와 u3을 더한 값을 저장한다.*/
	cout << u1 << endl; /*u1을 출력한다.*/
}
//출력:
//0
//56
//13524
//678
//13580

