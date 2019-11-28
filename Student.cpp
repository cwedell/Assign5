#include "Student.h"
#include <iostream>

using namespace std;

Student::Student() {
  gpa = -1.0;
  advisor = -1;
}

Student::Student(int i, string n, string l, string a, double g, int ad) {
  setID(i);
  setName(n);
  setLevel(l);
  setArea(a);
  gpa = g;
  advisor = ad;
};

Student::Student(const Student& s) {
  setID(s.getID());
  setName(s.getName());
  setLevel(s.getLevel());
  setArea(s.getArea());
  setGPA(s.getGPA());
  setAdvisor(s.getAdvisor());
}

Student::~Student() {
}

double Student::getGPA() const {
  return gpa;
}

void Student::setGPA(double g) {
  gpa = g;
}

int Student::getAdvisor() const {
  return advisor;
}

void Student::setAdvisor(int ad) {
  advisor = ad;
}

Student& Student::operator = (const Student& s) {
  if(this != &s) {
    setID(s.getID());
    setName(s.getName());
    setLevel(s.getLevel());
    setArea(s.getArea());
    setGPA(s.getGPA());
    setAdvisor(s.getAdvisor());
  }
  return *this;
}
