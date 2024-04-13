#include <iostream>
#include <string> 

using namespace std;
template <typename T> 
T Average(T a, T b) 
{ 
	T average = (a + b) / 2;
	return average;
}
string Average(string a, string b) 
{ 
	int len = (a.length() + b.length()) / 2; 
	string c = a + " " + b; 

	string d; 
	for (int i = 0; i < len; i++) {
		/*len�� ������ ���� ������ �����ϸ� c�� i ���� d�� �ϳ��� �߰��Ѵ�.*/
		d.push_back(c[i]);
	}
	return d;
}

int main() {
	std::cout << Average(2.5, 3.3) << std::endl; 
	// 2.9 ��� /*Average�Լ��� 2.5�� 3.3�� �����ϰ� ��ȯ �� 2.9�� ��µȴ�.*/
	std::cout << Average(2, 3) << std::endl;
	// 2 ��� /*Average�Լ��� ���� 2,3�� ���� �ǰ� 2�� ��ȯ �Ǹ� ��µȴ�.*/
	std::cout << Average(std::string("C++"), std::string("Programming")) << std::endl; 
	// C++ Pro��� ("C++" + " " + "Programming"�� ���� 1/2 ���ڿ�(�Ҽ��� ���� ����) 
}
