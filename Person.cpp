#include "Person.h"
#include <iostream>

using namespace std;

Person::Person() {
  id = -1;
  name = "";
  level = "";
  area = "";
}

Person::Person(int i, string n, string l, string a) {
  id = i;
  name = n;
  level = l;
  area = a;
}

Person::~Person() {
}

int Person::getID() const {
  return id;
}

void Person::setID(int i) {
  id = i;
}

string Person::getName() const {
  return name;
}

void Person::setName(string n) {
  name = n;
}

string Person::getLevel() const {
  return level;
}

void Person::setLevel(string l) {
  level = l;
}

string Person::getArea() const {
  return area;
}

void Person::setArea(string a) {
  area = a;
}

bool Person::operator == (const Person &p) {
  return (id == p.id);
}

bool Person::operator != (const Person &p) {
  return (id != p.id);
}

bool Person::operator < (const Person &p) {
  return (id < p.id);
}

bool Person::operator > (const Person &p) {
  return (id > p.id);
}

bool Person::operator <= (const Person &p) {
  return (id <= p.id);
}

bool Person::operator >= (const Person &p) {
  return (id >= p.id);
}
