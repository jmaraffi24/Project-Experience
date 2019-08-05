#include "Vector.h"

int main() {
  Vector v(3);

  cout << "V:" << v << endl;
  v.at(0) = 10;
  cout << "V:" << v << endl;

  Vector b(v);
  cout << "B:" << b << endl;

  v.at(1) = 20;
  cout << "V:" << v << endl;

  cout << "B:" << b << endl;

  Vector c {11, 21, 31};

  cout << "C:" << c << endl;

  Vector d = c.add(5);
  cout << "D:" << d << endl;

  Vector e = c.add(b);
  cout << "E:" << e << endl;
  
  // while(1){;}
}
