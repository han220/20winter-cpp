#include <iostream>

using namespace std;

/*
출력:
- Constructor called with (10,20) (ID=1)
- Constructor called with (30,40) (ID=2)
- Constructor called with (10,20) , (30,40) (ID=3)
- Copy Constructor called with (10,20), (30,40) (ID=4)
- Rectangle (10,20), (30,40) (ID=3)
- Rectangle (10,20), (30,40) (ID=4)
- Destructor called (ID=4)
- Destructor called (ID=3)
- Destructor called (ID=2)
- Destructor called (ID=1)
*/

int lastId = 0;

class Rectangle;

class Point {
 private:
  int intx;  // x좌표
  int inty;  // y좌표
  int id;    // ID
 public:
  Point() { cout << "TEST" << endl; };
  Point(int x, int y) {
    intx = x;
    inty = y;
    id = ++lastId;
    cout << "Constructor called with (" << x << "," << y << ") (ID=" << id
         << ")" << endl;
  };
  // Default Copy Constructor
  // Point(const Point &point) {
  //   intx = point.intx;
  //   inty = point.inty;
  // }
  ~Point() { cout << "Destructor called (ID=" << id << ")" << endl; }
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
  friend ostream &operator<<(ostream &os, Point p);
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
ostream &operator<<(ostream &os, Point p) {
  return os << "X좌표: " << p.intx << " Y좌표: " << p.inty;
}

class Rectangle {
 private:
  int id;
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
    id = ++lastId;
    cout << "Constructor called with (" << upLeft.GetX() << "," << upLeft.GetY()
         << "), (" << lowRight.GetX() << "," << upLeft.GetY() << ") (ID=" << id
         << ")" << endl;
  };
  Rectangle(const Rectangle &rect) {
    upLeft = Point(rect.upLeft);
    lowRight = Point(rect.lowRight);
    id = ++lastId;
    cout << "Copy Constructor called with (" << upLeft.GetX() << ","
         << upLeft.GetY() << "), (" << lowRight.GetX() << "," << upLeft.GetY()
         << ") (ID=" << id << ")" << endl;
  }
  // Deconstructor
  ~Rectangle() { cout << "Destructor called (ID=" << id << ")" << endl; }
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
  return os << "Rectangle (" << rect.upLeft.GetX() << "," << rect.upLeft.GetY()
            << "), (" << rect.lowRight.GetX() << "," << rect.upLeft.GetY()
            << ") (ID=" << rect.id << ")" << endl;
}

int main(void) {
  // Write Here
  Point pt1(10, 20);
  Rectangle a(pt1, Point(30, 40));
  Rectangle b(a);
  cout << a;
  cout << b;
  return 0;
}