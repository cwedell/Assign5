#include "Person.h"
#include <iostream>

using namespace std;

class Student: public Person {
private:
  double gpa;
  int advisor;
  friend class TreeNodestudents;
  friend class BSTstudents;
  friend class Serializer;
  friend class File;

public:
  Student();
  Student(int i, string n, string l, string a, double g, int ad);
  Student(const Student& s);
  ~Student();

  double getGPA() const;
  void setGPA(double g);
  int getAdvisor() const;
  void setAdvisor(int ad);

  Student& operator = (const Student& s);
};
