#include "Faculty.h"
#include <iostream>

using namespace std;

class TreeNodefaculty{
public:
  TreeNodefaculty();
  TreeNodefaculty(Faculty f);
  virtual ~TreeNodefaculty();

  Faculty key;
  TreeNodefaculty *left;
  TreeNodefaculty *right;
};

TreeNodefaculty::TreeNodefaculty() {
  left = NULL;
  right = NULL;
}

TreeNodefaculty::TreeNodefaculty(Faculty f) {
  left = NULL;
  right = NULL;
  key = f;
}

TreeNodefaculty::~TreeNodefaculty() {
  if(left != NULL) {
    delete left;
  }
  if(right != NULL) {
    delete right;
  }
}
