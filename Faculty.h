#include "Person.h"
#include <iostream>

using namespace std;

class Faculty: public Person {
private:
  int advisee;
  friend class TreeNodefaculty;
  friend class BSTfaculty;
  friend class Serializer;
  friend class File;

public:
  Faculty();
  Faculty(int i, string n, string l, string a, int ad);
  Faculty(const Faculty& f);
  ~Faculty();

  int getAdvisee() const;
  void setAdvisee(int ad);

  Faculty& operator = (const Faculty& f);
};
