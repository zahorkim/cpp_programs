
#include<iostream> 
#include <cmath>
using namespace std;

//추상 클래스
class Shape 
{ 
public:
	static double pi;
	virtual double getArea() = 0; //순수 가상함수
	virtual void printArea() = 0;//순수 가상함수
};


//추상 클래스
class TwoDimensional : public Shape 
{ 
public:
	virtual double getRound() = 0; //순수 가상함수
	virtual void printRound() = 0;//순수 가상함수
};

//추상 클래스
class ThreeDimensional :public Shape 
{ 
public:
	virtual double getVolume() = 0;  //순수 가상함수
	virtual void printVolume() = 0; //순수 가상함수
};

//-------
class Triangle :public TwoDimensional 
{ 
	int t1, t2, t3;/*세 변의 길이를 저장할 멤버를 선언한다.*/
public:
	Triangle(int x, int y, int z) :t1(x), t2(y), t3(z) {}
	double getArea();
	double getRound();
	void printArea();
	void printRound();
};
double Triangle::getArea() 
{
	double s;
	s = (t1 + t2 + t3) / 2; /*t1,t2,t3를 더하고 2로 나눈 값을 s에 저장한다.*/
	return sqrt(s * (s - t1) * (s - t2) * (s - t3)); /*넓이를 구하여 리턴한다.*/
}
double Triangle::getRound() 
{ 
	return t1 + t2 + t3; /*세변을 더하여 둘레 값을 리턴한다.*/
}
void Triangle::printArea()
{ 
	cout << "Triangle Area:" << this->getArea() << endl;/*getArea함수를 이용하여 그 값을 출력한다.*/
}
void Triangle::printRound() { /* TwoDimensional의 순수 가상함수를 재정의 한다.*/
	cout << "Triangle Round:" << this->getRound() << endl; /*getRound함수를 이용하여 그 값을 출력한다.*/
}

//------------
class Rectangle :public TwoDimensional 
{ 
	int width, height;
public:
	Rectangle(int x, int y) :width(x), height(y) {} 
	double getArea(); 
	double getRound();
	void printArea();
	void printRound();
};
double Rectangle::getArea() 
{ 
	return double(width) * height; 
}
double Rectangle::getRound() 
{
	return (double)width * 2 + (double)height * 2;
}
void Rectangle::printArea()
{
	cout << "Rectangle Area:" << this->getArea() << endl;
}
void Rectangle::printRound() 
{
	cout << "Rectangle Round:" << this->getRound() << endl; 
}

//------
class Circle :public TwoDimensional
{ 
	int r; //반지름
public:
	Circle(int r) :r(r) {}
	double getArea();
	double getRound();
	void printArea();
	void printRound();
};
double Circle::getArea() 
{
	return r * r * pi; /*원의 면적을 리턴한다.*/
}
double Circle::getRound() 
{
	return 2 * r * pi; /*원의 둘레를 리턴한다.*/
}
void Circle::printArea() 
{ 
	cout << "Circle Area:" << this->getArea() << endl;
}
void Circle::printRound() 
{ 
	cout << "Circle Round:" << this->getRound() << endl; 
}


class Cube :public ThreeDimensional
{ 
	int width, height, length; /*가로, 세로, 높이를 저장할 멤버를 선언한다. */
public:
	Cube(int x, int y, int z) :width(x), height(y), length(z) {} 
	double getArea(); 
	void printArea();
	double getVolume();
	void printVolume();
};

double Cube::getArea() 
{ 
	/*육면체의 면적을 구하여 그 값을 리턴한다.*/
	return 2 * (length * width) + 2 * (length * height) + 2 * (width * height);
}
void Cube::printArea() 
{ 
	cout << "Cube Area:" << this->getArea() << endl; 
}
double Cube::getVolume() 
{ 
	return width * height * length; /*육면체의 부피를 계산하여 리턴한다.*/
}
void Cube::printVolume() 
{ 
	cout << "Cube Volume:" << this->getVolume() << endl; 
}
//-----------------
class Sphere :public ThreeDimensional
{
	int r; /*반지름을 저장할 멤버 r를 선언한다.*/
public:
	Sphere(int r) :r(r) {} 
	double getArea(); 
	void printArea();
	double getVolume();
	void printVolume();
};
double Sphere::getArea() 
{ 
	return 4 * pi * pow(r, 2); 
}
void Sphere::printArea()
{
	cout << "Sphere Area:" << this->getArea() << endl;
}
double Sphere::getVolume() 
{ 
	return (double(3) / 4) * pow(r, 3) * pi; /*구의 부피를 계산하여 리턴한다.*/
}
void Sphere::printVolume() 
{ 
	cout << "Sphere Volume:" << this->getVolume() << endl; 
}


// static data는 반드시 전역으로 선언
double Shape::pi = 3.14159;

int main() 
{
	Triangle t1(5, 6, 9); 
	t1.printArea();
	t1.printRound(); 

	Rectangle r1(3, 4); 
	r1.printArea(); 
	r1.printRound(); 

	Circle c1(5); 
	c1.printArea(); 
	c1.printRound();

	Cube cu1(5, 4, 3); 
	cu1.printArea(); 
	cu1.printVolume(); 

	Sphere s1(7); 
	s1.printArea(); 
	s1.printVolume(); 
}
