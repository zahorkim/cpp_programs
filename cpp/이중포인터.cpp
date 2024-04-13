#include <iostream>

int main() 
{
	int x1 = 10;
	int* p1 = &x1;//정수형 포인터 변수 p1을 선언하고 x1의 주소값을 저장
	int** pp1 = &p1;//선언하고 p1의 주소값을 저장

	**pp1 = 11;//**연산자를 이용해서 pp1의 실제 값에 접근하여 x의 값 10을 11로 바꾸고 출력한다
	std::cout << x1 << std::endl;//11
	*p1 = 12;//*을 이용해 p2의 실제 값에 접근하여 12로 바꿈
	std::cout << x1 << std::endl;//12

	int x2, *p2, ** pp2;
	x2 = 10;
	p2 = &x2;//p2는 x2의 주소값
	pp2 = &p2;//pp2는 p2의 주소값으로 초기화한다

	**pp2 = 11;//**을 이용해서 p2에 실제값인 10을 11로 바꿈
	std::cout << x2 << std::endl;//11
	*p2 = 12;//*으로 p2의 실제 값에 접근하여 12로 바꿈
	std::cout << x2 << std::endl;//12
}
