#include <iostream>

using namespace std;

class Circle {
  int radius;

 public:                       // 원의 반지름 값 public:
  void setRadius(int radius);  // 반지름을 설정한다.
  double getArea();            // 면적을 반환한다.
};

void Circle::setRadius(int radius) { this->radius = radius; }

double Circle::getArea() { return 3.14 * radius * radius; }

int main(void) {
  int count;
  cout << "원의 갯수 : ";
  cin >> count;

  Circle *circles;

  int rad;
  for (int i = 0; i < count; i++) {
    circles[i] = *(new Circle());
    cout << "원 " << i + 1 << "의 반지름 : ";
    cin >> rad;
    circles[i].setRadius(rad);
  }
  // 출력
  int big = 0;
  for (int i = 0; i < count; i++) {
    if (circles[i].getArea() >= 100) big++;
  }
  cout << "면적이 100보다 큰 원은 " << big << "개입니다." << endl;
  return 0;
}