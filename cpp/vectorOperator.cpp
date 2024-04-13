#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Vector
{
public:
	vector<T>v1;
	Vector(T a, T b) 
	{ 
		v1.push_back(a);
		v1.push_back(b);
	}
};	

/*operator<<을 오버로딩한다.*/
template <typename T>
ostream& operator<< (ostream& os, Vector<T> a)
{
	for (int i = 0; i < a.v1.size(); i++)
	{ 
		os << a.v1[i] << ","; 
	}
	return os;
}
template <> /*specialize를 하기 위해 <>을 비워놓고 아래 파라메타에서 char로 타입을 정해준다.*/
ostream& operator<<(ostream& os, Vector<char>a) 
{ 


	for (int i = 0; i < a.v1.size(); i++) {
		os << int(a.v1[i]) << ",";
	}
	return os;
}

int main() {
	Vector<int> v1(1234, 32644);
	Vector<char> v2(121, 22);
	Vector<double> v3(1.32, 2.234);
	std::cout << v1 << std::endl; // 1234, 32644 출력 /*template T를 사용한 operator<<가 호출되어 출력된다.*/
	std::cout << v2 << std::endl; // 121, 22 출력 /*타입이 char이기 때문에 char로 지정하여 오버로딩한 operator<<가 호출되어 출력된다.*/
	std::cout << v3 << std::endl; // 1.32, 2.234 출력
}
