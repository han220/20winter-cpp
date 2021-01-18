/*

1. 시간의 합을 구하는 함수를 정의한다.
-operator overloading을 활용한다.
*주의: sec의 합이 60 이상이면 min의 값이 1 증가하여야
한다.
min-sec operator+ (min-sec & op1, min-sec &op2)

2. 시간의 차를 구하는 함수를 정의한다. -function overloadin을 활용한다.
int diff(min-sec op1, min-sec op2) int diff(int sec1, min-sec op2)

3. min-sec type을 출력하는 함수를 정의 한다.
  방법1)operator overloading을 활용한다.
  friend ostream & operator<<(ostream & os, min-sec & c)
  방법2)member fuction 을 활용한다.
  void showInfo()
4. 스스로 구현하기
bool operator< (min_sec op1, min_sec op2) bool operator> (min_sec op1, min_sec
op2) min-sec operator< (min-sec op1, min-sec op2)

*/

#include <iostream>

using namespace std;

struct MinSec {
  int min, sec;
};

// 1. 시간의 합을 구하는 함수
MinSec operator+(MinSec &minsec1, MinSec &minsec2) {
  MinSec tmp;
  tmp.min = minsec1.min + minsec2.min;
  tmp.sec = minsec1.sec + minsec2.sec;

  tmp.min += tmp.sec / 60;
  tmp.sec %= 60;
  return tmp;
}

// 2. 시간의 차를 구하는 함수
int diff(MinSec minsec2, MinSec minsec1) {
  return (minsec1.min * 60 + minsec1.sec) - (minsec2.min * 60 + minsec2.sec);
}
int diff(int sec2, MinSec minsec1) {
  return (minsec1.min * 60 + minsec1.sec) - sec2;
}
// int operator-(MinSec &minsec1, MinSec &minsec2) {
//   return (minsec1.min * 60 + minsec1.sec) - minsec2.min * 60 + minsec2.sec;
// }

// 3. min-sec type을 출력하는 함수를 정의 한다.
// 이게 뭔 소리냐면 cout 에 형식에 맞춰서 나오게 한다.
// 예) cout << time; // -> 5 min 59 sec 이렇게 나오게
ostream &operator<<(ostream &os, MinSec &c) {
  return os << c.min << "분 " << c.sec << "초";
}
// 4a. < 만들기
bool operator<(MinSec minsec1, MinSec minsec2) {
  return diff(minsec2, minsec1) < 0 ? true : false;
}
// 4b. > 만들기
bool operator>(MinSec minsec1, MinSec minsec2) {
  return diff(minsec2, minsec1) > 0 ? true : false;
}

int main(void) {
  MinSec time1, time2;

  float x;
  x = 2.3f;

  time1.min = 10;
  time1.sec = 30;

  time2.min = 10;
  time2.sec = 00;

  // 문제 1번
  MinSec time3 = time1 + time2;

  // 문제 2번
  cout << time3.min << " : " << time3.sec << endl;
  cout << diff(time2, time1) << endl;

  // 문제 3번
  cout << time1 << endl;

  // 문제 4번
  cout << "(a<b)";
  if (time1 < time2)
    cout << "ture" << endl;
  else
    cout << "false" << endl;
  cout << "(a>b)";
  if (time1 > time2)
    cout << "ture" << endl;
  else
    cout << "false" << endl;

  return 0;
}