/*
문제 2: 점 만들기
1. Point class를 제작한다.
- 사용자로부터 x, y의 좌표를 입력 받는 함수를 구현해야한다.
- 이때 입력 받은 좌표가 음수라면 오류 메세지를 출력해야한다.
- 이미 저장된 x, y 값을 바꾸는 함수는 bool형으로 선언한다.
- 이때 사용자가 입력한 값이 음수라면 오류메세지와 함께 false를 리턴, 아니라면
true를 리턴하여야 한다.

예시)
class Point{ private:
intx; //x좌표
inty; //y좌표 public:
void InitMembers(int xpos, int ypos); // x좌표와 y좌표 값 입력 받는 함수 int
GetX(); // x좌표 반환 int GetY(); // y좌표 반환 bool SetX(int xpos); // x값 변경
(음수 체크 필요) bool SetY(int ypos); // y값 변경 (음수 체크 필요) };
*/

#include <iostream>

using namespace std;

class Point {
 private:
  int intx;  // x좌표
  int inty;  // y좌표
 public:
  void InitMembers(int xpos = 0, int ypos = 0) {
    intx = 0;
    inty = 0;
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

/*
  Point class를 제작한다.
  - 사용자로부터 x, y의 좌표를 입력 받는 함수를 구현해야한다.
  - 이때 입력 받은 좌표가 음수라면 오류 메세지를 출력해야한다.
  - 이미 저장된 x, y 값을 바꾸는 함수는 bool형으로 선언한다.
  - 이때 사용자가 입력한 값이 음수라면 오류메세지와 함께 false를 리턴,
  아니라면 true를 리턴하여야 한다.
*/

int main(void) {
  // Write Here
  Point p;
  p.InitMembers();
  int x, y;
  cin >> x >> y;
  if (!(p.SetX(x) && p.SetY(y))) {
    cout << "음수입니다." << endl;
  }
  cout << p.GetX() << " " << p.GetY() << endl;

  return 0;
}