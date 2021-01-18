/*

<실행 결과>
3.2 + 2.4 = 5.6
3.5 / 1.7 = 2.05882
2.2 – 1.5 = 0.7
4.9 / 1.2 = 4.08333
덧셈: 1 뺄셈: 1 곱셈: 0 나눗셈: 2

*/

#include <iostream>

using namespace std;

class Calculator {
  int add, div, mul, min;

 public:
  void Init() {
    add = 0;
    div = 0;
    mul = 0;
    min = 0;
  }
  double Add(double x1, double x2) {
    add++;
    return x1 + x2;
  }
  double Div(double x1, double x2) {
    div++;
    return x1 / x2;
  }
  double Mul(double x1, double x2) {
    mul++;
    return x1 * x2;
  }
  double Min(double x1, double x2) {
    min++;
    return x1 - x2;
  }
  void ShowOpCount() {
    cout << "덧셈: " << add << " 뺄셈: " << min << " 곱셈: " << mul
         << " 나눗셈: " << div << endl;
  }
};

int main(void) {
  // Write Here
  Calculator cal;
  cal.Init();  // 초기화
  cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
  cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
  cout << "2.2 – 1.5 = " << cal.Min(2.2, 1.5) << endl;
  cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;
  cal.ShowOpCount();
  return 0;
}