#include "Vector.h"

/* constructor */
Vector::Vector(int len) {
  length = len;
  values = new double[length];
}

/* initializer list constructor */
Vector::Vector(initializer_list<double> vals) {
  length = vals.size();
  values = new double[length];
  int i = 0; 
  for(double v : vals) {
    values[i] = v;
    i++;
  }
}

// Vector::Vector(const Vector & vec) = default;

/* copy constructor */
Vector::Vector(const Vector & vec) {
  length = vec.getLength();
  values = new double[length];
  for(int i = 0; i < length; i++) {
    values[i] = vec.at(i);
  }
}

/* destructor */
Vector::~Vector() {
  delete values;
}

Vector Vector::add(double s) const {
  Vector temp(length);
  for(int i = 0; i < length; i++) {
    temp.at(i) = at(i) + s;
  }
  return temp;
}

Vector Vector::add(const Vector & v) const {
  Vector temp(length);
  for(int i = 0; i < length; i++) {
    temp.at(i) = at(i) + v.at(i);
  }
  return temp;
}

/* getLength */
const int Vector::getLength() const {
  return length;
}

/* get value at */
double & Vector::at(int idx) {
  return values[idx];
}

/* get value at */
const double & Vector::at(int idx) const {
  return values[idx];
}

/* overload stream insertion operator */
ostream& operator<<(ostream& out, Vector & v) {
  for(int i = 0; i < v.getLength(); i++) {
    out << v.at(i) << " ";
  }
  return out;
}
