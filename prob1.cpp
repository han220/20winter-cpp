#include <iostream>

using namespace std;

namespace fl {
float boxVolume(float length, float width, float height = 2.0) {
  return length * width * height;
}
}  // namespace fl
int boxVolume(int length, int width, int height = 2) {
  return length * width * height;
}

int main(void) {
  cout << "Example 1" << endl;
  cout << boxVolume(3, 5, 5) << endl;
  cout << boxVolume(3, 2) << endl;
  cout << "Example 2" << endl;
  cout << boxVolume(3, 5, 5) << endl;
  cout << fl::boxVolume(3.1, 3.5) << endl;
  return 0;
}