#include "Serializer.h"
#include "GenStack.h"
#include <iostream>
#include <fstream>

using namespace std;

class File {
private:
  string studentFile;
  string facultyFile;
  BSTstudents studentTable = BSTstudents();
  BSTfaculty facultyTable = BSTfaculty();
  GenStack<Person> rollbackPeople = GenStack<Person>(5);
  GenStack<int> rollbackType = GenStack<int>(5); // -1 = would be deleted, 0 = would be modified, 1 = would be added
  Serializer serial;
  friend int main(int argc, char** argv);

public:
  File();
  File(string s, string f);
  ~File();

  string getStudentFile();
  void setStudentFile(string s);
  string getFacultyFile();
  void setFacultyFile(string f);
  BSTstudents getStudentTable(); // no mutators for these since we don't want to allow replacement of the whole DS
  BSTfaculty getFacultyTable();
  GenStack<Person> getRollbackPeople();
  GenStack<int> getRollbackType();

  void printAll();
  void printTable(bool b); // in each method that takes a bool argument, true = student and false = faculty
  void printPerson(bool b, int id);
  void printAdvising(bool b, int id);
  void addStudent(int i, string n, string l, string a, double g, int ad);
  void addFaculty(int i, string n, string l, string a, int ad);
  void deletePerson(bool b, int id);
  void changeAdvising(bool b, int id, int ad);
  void rollback();

  void serialize();
  void deserialize();

  void printMenu();
};
