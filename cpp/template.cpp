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
		/*len의 값보다 작을 때까지 실행하며 c의 i 값을 d에 하나씩 추가한다.*/
		d.push_back(c[i]);
	}
	return d;
}

int main() {
	std::cout << Average(2.5, 3.3) << std::endl; 
	// 2.9 출력 /*Average함수에 2.5와 3.3을 전달하고 반환 값 2.9가 출력된다.*/
	std::cout << Average(2, 3) << std::endl;
	// 2 출력 /*Average함수에 정수 2,3이 전달 되고 2가 반환 되며 출력된다.*/
	std::cout << Average(std::string("C++"), std::string("Programming")) << std::endl; 
	// C++ Pro출력 ("C++" + " " + "Programming"의 앞의 1/2 문자열(소수점 이하 버림) 
}
