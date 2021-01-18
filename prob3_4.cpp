/*
문제 4: Rectangle 클래스 추가 함수
1. 이전 문제의 Rectangle Class 의 전용 생성자를 두가지로 overloading 가 능하도록
만들어라.
- 1) 인자가 없는 생성자
- 2) 두개의 점이 인자로 주어지는 생성자

2. Rectangle 객체와 Point객체의 정보를 출력하는 연산자 <<를 정의하라 friend
함수를 이용하여 Point 멤버를 직접 접근하라.
3. Point 객체 두개를 더하는 연산함수를 friend 함수로 정의하라.

main() {
Rectangle a (Point(10,20), Point (30, 50)); Rectangle b ; // 모든 꼭지점이
(0,0)으로 초기화 Point pt1(100,200), pt2 (180, 300); b.initMembers(pt1, pt2);
a.showRectInfo();
b.showRectInfo();
cout << a <<b;
cout << Add_point(pt1, pt2);
}
*/

#include <iostream>

using namespace std;

class Rectangle;

class Point {
 private:
  int intx;  // x좌표
  int inty;  // y좌표
 public:
  Point(){};
  Point(int x, int y) {
    intx = x;
    inty = y;
  };
  void InitMembers(int xpos = 0, int ypos = 0) {
    intx = xpos;
    inty = ypos;
  };                            // x좌표와 y좌표 값 입력 받는 함수
  int GetX() { return intx; };  // x좌표 반환
  int GetY() { return inty; };  // y좌표 반환
  bool SetX(int xpos) {         // x값 변경 (음수 체크 필요)
    if (xpos >= 0) {
      intx = xpos;
      return true;
    }
    return false;
  };
  bool SetY(int ypos) {  // y값 변경 (음수 체크 필요)
    if (ypos >= 0) {
      inty = ypos;
      return true;
    }
    return false;
  };
  // #2 - 객체 정보 프린트 하는 함수
  friend ostream &operator<<(ostream &os, Point &p);
  friend ostream &operator<<(ostream &os, Rectangle &rect);

  //#3 - Point 객체 두개를 더하는 연산함수를 friend 함수로 정의하라.
  friend Point operator+(Point &p1, Point &p2);
  friend Point Add_point(Point &p1, Point &p2);
};

//#3 - Point 객체 두개를 더하는 연산함수를 friend 함수로 정의하라.
Point operator+(Point &p1, Point &p2) {
  Point temp;
  temp.intx = p1.intx + p2.intx;
  temp.inty = p1.inty + p2.inty;
  return temp;
}
Point Add_point(Point &p1, Point &p2) {
  Point temp(p1.intx + p2.intx, p1.inty + p2.inty);
  return temp;
}

// #2 - 객체 정보 프린트 하는 함수
ostream &operator<<(ostream &os, Point &p) {
  return os << "X좌표: " << p.intx << "Y좌표: " << p.inty;
}

class Rectangle {
 private:
  Point upLeft;
  Point lowRight;

 public:
  // #1a - 인자가 없는 생성자
  Rectangle() {  // 모든 꼭지점이 0,0 으로 초기화
    upLeft = Point(0, 0);
    lowRight = Point(0, 0);
  };  // #1b - 두개의 점이 인자로 주어진 생성자.
  Rectangle(Point ul, Point lr) {
    upLeft = ul;
    lowRight = lr;
  };
  Rectangle(Point &ul, Point &lr) {
    upLeft = ul;
    lowRight = lr;
  };
  void InitMembers(Point &ul, Point &lr) {
    if (ul.GetX() < lr.GetX() && ul.GetY() < lr.GetY()) {
      upLeft = ul;
      lowRight = lr;
    } else {
      cout << "사각형이 만들어 지지 않습니다. 잘못된 인풋.\n";
    }
  };
  void ShowRecInfo() {
    printf("좌측 포인트 %d %d, 우측 포인트 %d %d\n", upLeft.GetX(),
           upLeft.GetY(), lowRight.GetX(), lowRight.GetY());
  };
  // #2 - 객체 정보 프린트 하는 함수
  friend ostream &operator<<(ostream &os, Rectangle &rect);
};
// #2 - 객체 정보 프린트 하는 함수
ostream &operator<<(ostream &os, Rectangle &rect) {
  return os << "사각형1"
            << "X좌표: " << rect.upLeft.intx << "Y좌표: " << rect.upLeft.inty
            << endl
            << "사각형2"
            << "X좌표: " << rect.lowRight.intx
            << "Y좌표: " << rect.lowRight.inty;
}

int main(void) {
  Rectangle a(Point(10, 20), Point(30, 50));
  Rectangle b;  // 모든 꼭지점이 (0,0)으로 초기화
  Point pt1(100, 200), pt2(180, 300);
  b.InitMembers(pt1, pt2);
  a.ShowRecInfo();
  b.ShowRecInfo();
  cout << a << endl << endl << b << endl;
  Add_point(pt1, pt2);
  // cout << Add_point(pt1, pt2);
  return 0;
}