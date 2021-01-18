/*
1. Rectangle class를 제작한다.
- 앞서 구현했던 Point class를 사용하여 왼쪽 상단의 좌표와, 오른쪽 하단 의 좌표를
입력 받는 함수를 구현해야한다.
- 이때 입력 받은 좌표로 직사각형이 만들어지지 않으면 오류 메세지를 출력해야한다.
(좌표 값 비교가 필요함)
- 직사각형 좌측 상단의 좌표와, 우측 하단의 좌표를 출력하는 함수를 구현해야한다.

예시)
class Rectangle{ private:
Point upLeft;
Point lowRight; public:
void InitMembers(Point &ul, Point &lr);
void ShowRecInfo(); };
*/

#include <cstdio>
#include <iostream>

using namespace std;

class Point {
 private:
  int intx;  // x좌표
  int inty;  // y좌표
 public:
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
};

class Rectangle {
 private:
  Point upLeft;
  Point lowRight;

 public:
  void InitMembers(Point &ul, Point &lr) {
    if (ul.GetX() < lr.GetX() && ul.GetY() < lr.GetY()) {
      printf("%d", lr.GetX());
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
};

int main(void) {
  // Write Here
  Point p1, p2;
  p1.InitMembers();
  p2.InitMembers(2, 2);

  Rectangle rect;
  rect.InitMembers(p1, p2);
  rect.ShowRecInfo();

  return 0;
}