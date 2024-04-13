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

/*operator<<�� �����ε��Ѵ�.*/
template <typename T>
ostream& operator<< (ostream& os, Vector<T> a)
{
	for (int i = 0; i < a.v1.size(); i++)
	{ 
		os << a.v1[i] << ","; 
	}
	return os;
}
template <> /*specialize�� �ϱ� ���� <>�� ������� �Ʒ� �Ķ��Ÿ���� char�� Ÿ���� �����ش�.*/
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
	std::cout << v1 << std::endl; // 1234, 32644 ��� /*template T�� ����� operator<<�� ȣ��Ǿ� ��µȴ�.*/
	std::cout << v2 << std::endl; // 121, 22 ��� /*Ÿ���� char�̱� ������ char�� �����Ͽ� �����ε��� operator<<�� ȣ��Ǿ� ��µȴ�.*/
	std::cout << v3 << std::endl; // 1.32, 2.234 ���
}
