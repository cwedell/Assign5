#include "Student.h"
#include <iostream>

using namespace std;

class TreeNodestudents{
public:
  TreeNodestudents();
  TreeNodestudents(Student s);
  virtual ~TreeNodestudents();

  Student key;
  TreeNodestudents *left;
  TreeNodestudents *right;
};

TreeNodestudents::TreeNodestudents() {
  left = NULL;
  right = NULL;
}

TreeNodestudents::TreeNodestudents(Student s) {
  left = NULL;
  right = NULL;
  key = s;
}

TreeNodestudents::~TreeNodestudents() {
  if(left != NULL) {
    delete left;
  }
  if(right != NULL) {
    delete right;
  }
}
