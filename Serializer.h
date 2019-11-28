#include "BSTfaculty.h"
#include "BSTstudents.h"
#include <iostream>
#include <fstream>

using namespace std;

class Serializer {
private:
  friend class File;
public:
  Serializer();
  ~Serializer();

  void serialize(BSTstudents& BSTs, BSTfaculty& BSTf, string sfile, string ffile);
  void deserialize(BSTstudents& BSTs, BSTfaculty& BSTf, string sfile, string ffile);
};
