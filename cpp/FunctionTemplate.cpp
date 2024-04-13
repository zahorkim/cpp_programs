
#include <iostream>
using namespace std;

//template<typename T>
template<class T>
void myswap(T& a,T& b)  //매개변수,반환값
{
	T tmp; //지역변수
	tmp = a;
	a = b;
	b = tmp;
}
//void myswap(double& a, double& b)
//{
//	double tmp;
//	tmp = a;
//	a = b;
//	b = tmp;
//}

class Circle
{
	int radius;
public:
	Circle(int r = 0)
		:radius(r)
	{
	}
};
template<typename T>
T bigger( T a,  T b)  //const T&
{
	return (a > b) ? a : b;   // ? : 
}
char* bigger(char* a, char* b)  //주소
{
	//return (a > b) ? a : b; //주소
	if (strcmp(a, b) > 0)
		return a;
	else
		return b;
}

//double bigger(const double& a, const double& b)
//{
//	return (a > b) ? a : b;   // ? : 
//}

template <class T1, class T2>
void mcopy(T1 *s, T2* d, int size) //void mcopy(T1 s[], T2 d[], int size)
{
	for (int i=0; i < size; i++)
		d[i] = (T2)s[i];  //double = int 
}
int main()
{    
	int a[] = { 1,2,3 };
	double b[] = { 4.1,5.2,6.3 };
	mcopy(a, b, 3);  // a-> b    b(1 2 3)  // T1- int T2-double

	char s1[10] = "hello";
	char s2[10] = "world";
	cout << bigger(s1, s2) << endl;  //

	Circle c1, c2(5);
	myswap(c1, c2);// T = Circle

	int x = 3, y = 5;
	cout << "큰 수는 " << bigger(x, y) << endl;
	cout << "x=" << x << " y=" << y << endl;
	myswap(x, y); //myswap<int>(x, y);    //T=int
	cout << "x=" << x << " y=" << y << endl;

	double dx = 3.3, dy = 5.5;
	cout << "큰 수는 " << bigger(dx,dy) << endl;//<=====
	cout << "dx=" << dx << " dy=" <<dy << endl;
	myswap(dx, dy);//myswap<double>(dx, dy); // int& a=dx, int&b = dy :error
	cout << "dx=" << dx << " dy=" << dy << endl;


}

