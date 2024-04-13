
#include<iostream> 
#include <cmath>
using namespace std;

//�߻� Ŭ����
class Shape 
{ 
public:
	static double pi;
	virtual double getArea() = 0; //���� �����Լ�
	virtual void printArea() = 0;//���� �����Լ�
};


//�߻� Ŭ����
class TwoDimensional : public Shape 
{ 
public:
	virtual double getRound() = 0; //���� �����Լ�
	virtual void printRound() = 0;//���� �����Լ�
};

//�߻� Ŭ����
class ThreeDimensional :public Shape 
{ 
public:
	virtual double getVolume() = 0;  //���� �����Լ�
	virtual void printVolume() = 0; //���� �����Լ�
};

//-------
class Triangle :public TwoDimensional 
{ 
	int t1, t2, t3;/*�� ���� ���̸� ������ ����� �����Ѵ�.*/
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
	s = (t1 + t2 + t3) / 2; /*t1,t2,t3�� ���ϰ� 2�� ���� ���� s�� �����Ѵ�.*/
	return sqrt(s * (s - t1) * (s - t2) * (s - t3)); /*���̸� ���Ͽ� �����Ѵ�.*/
}
double Triangle::getRound() 
{ 
	return t1 + t2 + t3; /*������ ���Ͽ� �ѷ� ���� �����Ѵ�.*/
}
void Triangle::printArea()
{ 
	cout << "Triangle Area:" << this->getArea() << endl;/*getArea�Լ��� �̿��Ͽ� �� ���� ����Ѵ�.*/
}
void Triangle::printRound() { /* TwoDimensional�� ���� �����Լ��� ������ �Ѵ�.*/
	cout << "Triangle Round:" << this->getRound() << endl; /*getRound�Լ��� �̿��Ͽ� �� ���� ����Ѵ�.*/
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
	int r; //������
public:
	Circle(int r) :r(r) {}
	double getArea();
	double getRound();
	void printArea();
	void printRound();
};
double Circle::getArea() 
{
	return r * r * pi; /*���� ������ �����Ѵ�.*/
}
double Circle::getRound() 
{
	return 2 * r * pi; /*���� �ѷ��� �����Ѵ�.*/
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
	int width, height, length; /*����, ����, ���̸� ������ ����� �����Ѵ�. */
public:
	Cube(int x, int y, int z) :width(x), height(y), length(z) {} 
	double getArea(); 
	void printArea();
	double getVolume();
	void printVolume();
};

double Cube::getArea() 
{ 
	/*����ü�� ������ ���Ͽ� �� ���� �����Ѵ�.*/
	return 2 * (length * width) + 2 * (length * height) + 2 * (width * height);
}
void Cube::printArea() 
{ 
	cout << "Cube Area:" << this->getArea() << endl; 
}
double Cube::getVolume() 
{ 
	return width * height * length; /*����ü�� ���Ǹ� ����Ͽ� �����Ѵ�.*/
}
void Cube::printVolume() 
{ 
	cout << "Cube Volume:" << this->getVolume() << endl; 
}
//-----------------
class Sphere :public ThreeDimensional
{
	int r; /*�������� ������ ��� r�� �����Ѵ�.*/
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
	return (double(3) / 4) * pow(r, 3) * pi; /*���� ���Ǹ� ����Ͽ� �����Ѵ�.*/
}
void Sphere::printVolume() 
{ 
	cout << "Sphere Volume:" << this->getVolume() << endl; 
}


// static data�� �ݵ�� �������� ����
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
