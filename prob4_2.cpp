#include <cstring>
#include <iostream>

using namespace std;

/*

다음과 같은 멤버 변수를 가지는 Person 클래스를 정의하고 멤버 함수들을 만들어라.
(인자가 name만 있는 것과 전부 있는 두종류의 생성자, 복사 생성자, 소멸자
포함해서)

*/

class Person {
  char* name;
  int height;
  int weight;

 public:
  // 생성자 (모든 정보 받기)
  Person(char* name, int height, int weight) {
    // 이름 복사
    this->name = new char[strlen(name)];
    strcpy(this->name, name);

    // 나머지는 그냥 복사
    this->height = height;
    this->weight = weight;
  }

  // 이름만 받기
  Person(char* name) {
    // 이름 복사
    this->name = new char[strlen(name)];
    strcpy(this->name, name);
  }

  // 복사 생성자
  Person(const Person& person) {
    // 이름 복사
    this->name = new char[strlen(person.name)];
    strcpy(this->name, person.name);

    // 나머지는 그냥 복사
    this->height = person.height;
    this->weight = person.weight;
  }

  // 소멸자 - 스트링 메모리 삭제하기
  ~Person() { delete this->name; }

  void setName(char* name) {
    delete this->name;
    this->name = new char[strlen(name)];
    strcpy(this->name, name);
  }

  // = Deep Copy 함수
  void operator=(Person& other) {
    // 복사 생성자 내용과 동일.
    setName(other.name);
    height = other.height;
    weight = other.weight;
  }
  friend ostream& operator<<(ostream& os, Person& person);
};

// 출력
ostream& operator<<(ostream& os, Person& person) {
  return os << person.name << " (" << person.height << "cm, " << person.weight
            << "kg)" << endl;
}

int main(void) {
  // Write Here
  Person p1((char*)"James", 150, 50);
  Person p2((char*)"Trump");
  Person p3 = p1;
  p3 = p2;
  cout << p1 << p2 << p3;
  return 0;
}