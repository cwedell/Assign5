#ifndef __PERSON_H_INCLUDED__
#define __PERSON_H_INCLUDED__

#include <iostream>

using namespace std;

class Person {
private:
  int id;
  string name;
  string level;
  string area; // major/department
  friend class TreeNodestudents;
  friend class BSTstudents;
  friend class TreeNodefaculty;
  friend class BSTfaculty;
  friend class Serializer;
  friend class Student;
  friend class Faculty;
  friend class File;

public:
  Person();
  Person(int i, string n, string l, string a);
  ~Person();

  int getID() const;
  void setID(int i);
  string getName() const;
  void setName(string n);
  string getLevel() const;
  void setLevel(string l);
  string getArea() const;
  void setArea(string a);

  bool operator == (const Person &p);
  bool operator != (const Person &p);
  bool operator < (const Person &p);
  bool operator > (const Person &p);
  bool operator <= (const Person &p);
  bool operator >= (const Person &p);
};

#endif
