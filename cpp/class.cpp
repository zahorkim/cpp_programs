//IntPoint는 2차원 평면상의 점을 표현하는 클래스이며 x, y는 평면상의 좌표를 저장하는 멤버이며, 
//Rectangle은 회전되지 않은 직사각형 표현하는 클래스로 왼쪽 - 코너점을 corner로, 
//폭과 높이를 각각 width와 height로 저장한다.

#include <iostream>
#include <vector>
#include <string>


class IntPoint 
{
public:
	int x; // x 좌표
	int y; // y 좌표
	IntPoint(int x, int y) : x(x), y(y) {}
};

class Rectangle 
{
	IntPoint corner; // 직사각형의 왼쪽-아래 코너점
	int width; // 직사각형의 폭
	int height; // 직시각형의 높이
public:
	Rectangle(IntPoint pt, int w, int h) : corner(pt),
		width((w < 0) ? 0 : w), height((h < 0) ? 0 : h) {}
	int perimeter() {
		return 2 * width + 2 * height;
	}
	int area() {
		return width * height;
	}
	int get_width() {
		return width;
	}
	int get_height() {
		return height;
	}
	// 현재 인스턴스 사각형과 r이 겹쳐있다면 true, 그렇지 않으며 false
	bool intersect(Rectangle r) {
		//// 코드 작성
		IntPoint rightdown(corner.x + width, corner.y),
			leftup(corner.x, corner.y + height), 
			rightup(corner.x + width, corner.y + height);

		if (rightdown.x<r.corner.x  ||
			corner.x > r.corner.x + r.width || 
			leftup.y<r.corner.y || 
			rightdown.y>r.corner.y + r.height) {
			return false;
		}
		else
			return true;
	}
	// 대각선의 길이(int 형)를 반환
	int diagonal() 
	{
		// 코드 작성
		return 0;
	}
	// 사각형의 중심점의 좌표를 IntPoint 형으로 반환
	IntPoint center()
	{
		// 코드 작성
		int tx = corner.x + width/ 2;
		int ty = corner.y + height / 2;
		return IntPoint(tx, ty);
	}
	// 현재 인스턴스 사각형의 내부(경계포함)에 pt가 있으면 true,
	// 그렇지 않으면 false
	bool is_inside(IntPoint pt) 
	{
		// 코드 작성
		return true;
	}
};

int main() 
{
	IntPoint p1(100, 100), p2(150, 150);
	Rectangle r1(p1, 100, 100), r2(p2, 100, 100);
	IntPoint c = r1.center();


	if (r1.intersect(r2))
		std::cout << "intersect "<<std::endl;
	else
		std::cout << "no intersect " << std::endl;

	IntPoint pp1(100, 100), pp2(250, 250);
	Rectangle rr1(pp1, 100, 100), rr2(pp2, 100, 100);

	if (rr1.intersect(rr2))
		std::cout << "intersect " << std::endl;
	else
		std::cout << "no intersect " << std::endl;

	return 0;
		 
}

