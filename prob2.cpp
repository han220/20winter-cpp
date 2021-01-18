#include <iomanip>
#include <iostream>

using namespace std;

void swap(char *a, char *b) {
  char tmp = *a;
  *a = *b;
  *b = tmp;
}
void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}
void swap(float *a, float *b) {
  float tmp = *a;
  *a = *b;
  *b = tmp;
}

int main(void) {
  cout.setf(ios::left);

  int a = 30, b = 20;
  cout << a << " " << setw(6) << b << "->";
  swap(a, b);
  cout << " " << a << " " << b << endl;

  char c = 'Z', d = 'A';
  cout << c << " " << setw(6) << d << "->";
  swap(c, d);
  cout << " " << c << " " << d << endl;

  float e = 5.555, f = 1.111;
  cout << e << " " << setw(6) << f << "->";
  swap(e, f);
  cout << " " << e << " " << f << endl;

  return 0;
}