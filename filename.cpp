#include <cstdio>
#include <iostream>

using namespace std;

// double add(double a, double b) { return a + b; }
// int add(int a, int b, int c) { return a + b + c; }

inline int sqr(int x) { return x * x; }
// #define sqr(x) (x * x)

namespace jungsub {
int sum = 0;
}
namespace choi {
int sum = 5;
}
using namespace choi;
using namespace jungsub;

int x = 0;

int main(void) {
  bool b = false;
  // scanf("%d %d", &x, &y)
  // cin >> x >> y;
  // printf("Hello World\n");
  cout << "Sum is " << x << endl;
  return 0;
}