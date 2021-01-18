#include <iostream>

using namespace std;

char& find(char a[], char needle, bool& success) {
  for (int i = 0; a[i] != '\n'; i++) {
    if (*(a + i) == needle) {
      success = true;
      return *(a + i);
    }
  }
  success = false;
  return *a;
}

int main(void) {
  // Write Here
  char s[] = "apple";
  bool b = false;
  char& loc = find(s, 'a', b);
  if (b == false) {
    cout << "a를 발견할 수 없습니다." << endl;
    return 0;
  }
  loc = 'A';          // ' a ' 위치에 ‘A' 기록
  cout << s << endl;  // "apple" 출력
  return 0;
}