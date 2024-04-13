#include <iostream>
using namespace std;

class Point
{
	friend ostream& operator<<(ostream& a, Point& p);
private:
	int x;
	int y;
public:
	//생성자 구현
	//Point(int=0, int=0);
	Point(); // 디폴트 생성자 =기본생성자
	Point(int); //변환 생성자 int=>Point
	//explicit Point(int); //변환 생성자 int=>Point
	//Point(double);  double=> Point
	Point(int, int);
	operator int(); // 형 변환 연산자
	//explicit operator int(); // 형 변환 연산자
	Point operator+(const Point&);
	bool operator==(const Point&);
	bool operator!=(const Point&);
	int operator[](int);  //<===
	void Print() const;
};
Point::Point()
	: x(0), y(0)
{
}
Point::Point(int a)
	: x(a), y(0)
{
}
Point::Point(int a, int b)
	: x(a),y(b)
{
}
void Point::Print() const
{
	cout << "x:" << x << " y:" << y << endl;
}

Point Point::operator+(const Point& p)
{
	Point a;
	a.x = this->x + p.x;
	a.y = this->y + p.y;
	return a;
}
bool Point::operator==(const Point& p)
{
	if (this->x == p.x && this->y == p.y)
		return true;
	else
		return false;
}
bool Point::operator!=(const Point& p)
{
	return !(*this == p);
}
//Point => int
Point::operator int()
{ //?
	return x;
}


int Point::operator[](int n)
{
	if (n == 0)
		return x;
	else if (n == 1)
		return y;
	else
		return -1;//?
}
//반드시 전역함수로 -friend로 선언
ostream& operator<<(ostream& a, Point& p)
{
	a << "x:" << p.x << " y:" << p.y << endl;
	return a;
}
int main()
{
	string sa[3];
	sa[0] = "aaa";

	string s = "hello";
	s[0] = 'x';    // s.operator[](0)
	cout << s[0] << endl;

	Point pp(3, 4);
	cout << pp << endl;
	// operator<< (cout, pp) 
	//              cout    << endl;


	cout <<"pp[0]="<< pp[0] << endl;  //pp.operator[](0)   3 x
	cout <<"pp[1]="<< pp[1] << endl;  //pp.operator[](1)    4 y

	int n = 10;
	Point p(1,1);
	n = p; //n =(int) p;  // Point=> int
	p = n; // p= (Point)n;  p= Point(n);

	

	Point p1;  //x=0 y =0   //디폴트 생성자
	Point p2(2, 4); //x=2 y=4
	Point p3(5);// x=5 y=0  // 변환 생성자

	p1 = p2 + p3;   // p1 = p2.operator+(p3)
	p1.Print(); // x:7 y:4

	Point p4(2, 4);
	if (p2 == p4)  //if(p2.operator==(p4) )   ==  !=
		cout << "같다" << endl;  //같다 
	else
		cout << "다르다" << endl;

}
// 실행결과
//x:7 y:4
//같다
