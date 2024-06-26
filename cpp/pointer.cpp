#include <iostream>
int main() 
{
	int a1[3] = { 10, 20, 30 }; 
	double a2[3] = { 1, 2, 3 }; 
	std::cout << a1 << ", " << a1 + 1 << std::endl; 
	//배열 a1의 시작 주소 값 즉 첫번째 요소의 주소 값을 출력한다. a1+1은 a1[0]의 다음 요소인 a1[1]의 주소와 같다.
	std::cout << a2 << ", " << a2 + 1 << std::endl; 

	int *p1 = a1; //정수형 포인터를 선언하여 배열 a1의 시작 주소를 저장한다.
	std::cout << p1 << ", " << p1 + 1 << std::endl; 
	//변수 p1에 할당된 주소 즉 a1 배열의 첫번째 요소의 주소 값을 출력한다. a1[0]의 다음 요소인 a1[1]의 주소를 출력한다. 
	std::cout << (*p1)++ << std::endl; //괄호와 간접연산자를 이용해 p1에 저장된 값을 먼저 접근한다. 
									   //그리고 그 값에 postfix 연산자로 1이 증가된다.  a1[0]의 값10이 먼저 출력되고, a1[0]는 11이 된다.
	std::cout << *p1 << std::endl; /*앞에서 *p1인 a1[0]의 값이 1 증가 되었으므로 11이 출력된다*/
	std::cout << *p1++ << std::endl; //위와 같이 괄호가 없으므로, *p1을 출력하고 p1++을 실행한다. 
	std::cout << *p1 << std::endl; /*앞서 증가된 p1의 값, 즉 두번째 요소의 값 a1[1]의 값, 20이 출력된다.*/
}

//00C4FEB4, 00C4FEB8
//00C4FE94, 00C4FE9C
//00C4FEB4, 00C4FEB8
//10
//11
//11
//20

