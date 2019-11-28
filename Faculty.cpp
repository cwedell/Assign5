#include "Faculty.h"
#include <iostream>

using namespace std;

Faculty::Faculty() {
  advisee = -1;
}

Faculty::Faculty(int i, string n, string l, string a, int ad) {
  setID(i);
  setName(n);
  setLevel(l);
  setArea(a);
  advisee = ad;
}

Faculty::Faculty(const Faculty& f) {
  setID(f.getID());
  setName(f.getName());
  setLevel(f.getLevel());
  setArea(f.getArea());
  setAdvisee(f.getAdvisee());
}

Faculty::~Faculty() {
}

int Faculty::getAdvisee() const {
  return advisee;
}

void Faculty::setAdvisee(int ad) {
  advisee = ad;
}

Faculty& Faculty::operator = (const Faculty& f) {
  if(this != &f) {
    setID(f.getID());
    setName(f.getName());
    setLevel(f.getLevel());
    setArea(f.getArea());
    setAdvisee(f.getAdvisee());
  }
  return *this;
}
