#include "Serializer.h"
#include <iostream>
#include <fstream>

using namespace std;

Serializer::Serializer() {
}

Serializer::~Serializer() {
}

void Serializer::serialize(BSTstudents& BSTs, BSTfaculty& BSTf, string sfile, string ffile) {
  ofstream fileout;
  fileout.open(sfile);
  BSTs.preorderTraversal(fileout);
  fileout.close();
  fileout.open(ffile);
  BSTf.preorderTraversal(fileout);
  fileout.close();
}

void Serializer::deserialize(BSTstudents& BSTs, BSTfaculty& BSTf, string sfile, string ffile) {
  ifstream filein;
  filein.open(sfile);
  string line;
  int linecount = 0;
  int s_id;
  string s_name;
  string s_level;
  string s_area;
  double s_gpa;
  int s_advisor;
  while(getline(filein, line)) {
    switch (linecount % 6) {
      case 0: s_id = stoi(line);
        break;
      case 1: s_name = line;
        break;
      case 2: s_level = line;
        break;
      case 3: s_area = line;
        break;
      case 4: s_gpa = stod(line);
        break;
      default: s_advisor = stoi(line);
        BSTs.insert(Student(s_id, s_name, s_level, s_area, s_gpa, s_advisor));
        break;
    }
    ++linecount;
  }
  filein.close();
  linecount = 0;
  filein.open(ffile);
  int f_id;
  string f_name;
  string f_level;
  string f_area;
  int f_advisee;
  while(getline(filein, line)) {
    switch (linecount % 5) {
      case 0: f_id = stoi(line);
        break;
      case 1: f_name = line;
        break;
      case 2: f_level = line;
        break;
      case 3: f_area = line;
        break;
      default: f_advisee = stoi(line);
        BSTf.insert(Faculty(f_id, f_name, f_level, f_area, f_advisee));
        break;
    }
    ++linecount;
  }
  filein.close();
}
