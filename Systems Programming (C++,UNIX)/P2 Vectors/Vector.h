#include <initializer_list>
#include <iostream>

using std::cout;
using std::endl;
using std::initializer_list;
using std::ostream;

class Vector {
 public:
  Vector(int len);
  Vector(initializer_list<double>);
  Vector(const Vector & vec);
  ~Vector();
  Vector add(double) const;
  Vector add(const Vector & v) const;
  const int getLength() const;
  double & at(int);
  const double & at(int) const;
 private:
  int length;
  double* values;
};

ostream& operator<<(ostream& out, Vector & v);


