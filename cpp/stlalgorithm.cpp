#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>
#include <functional>
#include <exception>
#include <stdexcept>

template <class iterator>
void Print(iterator begin, iterator end) 
{
	for (iterator iter = begin; iter != end; iter++)
		std::cout << *iter << ", ";
	std::cout << std::endl;
}

int main()
{
	std::vector<int> v1{ 1, 2, 3, 4, 5 }; 
	Print(v1.begin(), v1.end()); 

	
	//삭제 조건을 람다 함수로 전달 , 짝수만 삭제
	v1.erase(std::remove_if(v1.begin(), v1.end(), [](auto x) {return !(x % 2); }), v1.end());
	//1, 2, 3, 4, 5,


	//accumulate함수는 첫번째 파라메타부터 두번째 파라메타에 저장된 주소의 -1까지의 요소를 
	//세번째 파라메타로 초기화 된 값에 누적하여 더하여 그 값을 리턴하는 것이다.
	int sum = std::accumulate(v1.begin(), v1.end(), 0);
	std::cout << sum << std::endl; //9

	sum = std::accumulate(v1.begin(), v1.end() - 2, 0);
	std::cout << sum << std::endl; //1


	std::vector<int> v2{ 10, 0, 30, 0, 50 };
	//remove함수의 리턴 값은 수정된 범위의 새로운 끝의 위치에 주소를 지정하는 iterator이다. 
	//첫번째 파라메타는 시작 주소이고 두번째 파라메타는 끝나는 지점, 세번째 파라메타는 삭제할 값이다. 
	//v2의 처음부터 끝까지 0을 삭제한다. 0을 삭제해도 begin과 end가 변경되지 않기 때문에 다른 요소가 중복을 저장되어 있을 수 있다. 
	auto remove_start = std::remove(v2.begin(), v2.end(), 0);
	Print(v2.begin(), v2.end());//10, 30, 50, 0, 50,

	// 파라메타로 첫번째는 remove_start, 두번째로는 멤버함수 end()을 이용해서 v2의 마지막 요소의 주소 더하기 정수 1의 값을 전달한다. 
	//그러므로 remove_start에 저장된 주소 값부터 끝까지의 값을 삭제한다. 뒤의 두 개의 요소 0과 50을 삭제한다.*/
	v2.erase(remove_start, v2.end());//10, 30, 50,
	Print(v2.begin(), v2.end());

	std::cout << std::endl;

}

