#include <iostream>
using namespace std;
#include <iomanip>   //조작자

int main()
{
	int n = 123;
	double pi = 31.4592;
	cout << n << pi << endl;
	//멤버함수
	//ostream cout;
	cout.width(10);
	cout.fill('*');
	cout << n;
	cout.width(10);
	cout.fill(' ');
	cout << pi << endl;	

	//조작자 Manipulator  #include <iomanip>   //조작자
	cout << setw(10) << setfill('*') << n << setw(10) << setfill(' ') << pi << endl;

	//멤버함수
	cout.unsetf(ios::dec);
	cout.setf(ios::hex);
	cout << n ;
	cout.unsetf(ios::hex);
	cout << 100 << endl;
	//Manipulator
	cout << hex << n << dec << 100 << endl;

	cout << setprecision(5) << pi << endl;
	cout << setiosflags(ios::scientific) << pi << endl;

	cout << resetiosflags(ios::scientific) <<  pi << endl;


	cout.precision(6);
	cout << pi << endl;
	cout.setf(ios::scientific);
	cout << pi << endl;
	cout.unsetf(ios::scientific);
	cout << pi << endl;

}