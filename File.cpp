#include "File.h"
#include <iostream>
#include <fstream>
#include <typeinfo>

using namespace std;

File::File() {
  studentFile = "";
  facultyFile = "";
}

File::File(string s, string f) {
  studentFile = s;
  facultyFile = f;
}

File::~File() {
  deserialize(); // save tables on program exit
}

string File::getStudentFile() {
  return studentFile;
}

void File::setStudentFile(string s) {
  studentFile = s;
}

string File::getFacultyFile() {
  return facultyFile;
}

void File::setFacultyFile(string f) {
  facultyFile = f;
}

BSTstudents File::getStudentTable() {
  return studentTable;
}

BSTfaculty File::getFacultyTable() {
  return facultyTable;
}

GenStack<Person> File::getRollbackPeople() {
  return rollbackPeople;
}

GenStack<int> File::getRollbackType() {
  return rollbackType;
}

void File::printAll() {
  printTable(true);
  printTable(false);
}

void File::printTable(bool b) {
  if(b) {
    cout << "Printing all student records" << endl;
    studentTable.inorderPrint();
  } else {
    cout << "Printing all faculty records" << endl;
    facultyTable.inorderPrint();
  }
}

void File::printPerson(bool b, int id) {
  if(b) {
    Student ssearch;
    ssearch.setID(id);
    if(studentTable.search(ssearch)) {
      cout << "Record found." << endl;
      TreeNodestudents* slookup = studentTable.peek(ssearch);
      cout << "ID: " << slookup->key.id << endl;
      cout << "Name: " << slookup->key.name << endl;
      cout << "Class: " << slookup->key.level << endl;
      cout << "Major: " << slookup->key.area << endl;
      cout << "GPA: " << slookup->key.gpa << endl;
      cout << "Advisor ID: " << slookup->key.advisor << endl;
      cout << "--------------------" << endl;
    } else {
      cout << "No record found for that ID." << endl;
    }
  } else {
    Faculty fsearch;
    fsearch.setID(id);
    if(facultyTable.search(fsearch)) {
      cout << "Record found." << endl;
      TreeNodefaculty* flookup = facultyTable.peek(fsearch);
      cout << "ID: " << flookup->key.id << endl;
      cout << "Name: " << flookup->key.name << endl;
      cout << "Level: " << flookup->key.level << endl;
      cout << "Department: " << flookup->key.area << endl;
      cout << "Advisee ID: " << flookup->key.advisee << endl;
      cout << "--------------------" << endl;
    } else {
      cout << "No record found for that ID." << endl;
    }
  }
}

void File::printAdvising(bool b, int id) {
  if(b) {
    Student ssearch;
    ssearch.setID(id);
    if(studentTable.search(ssearch)) {
      cout << "Record found." << endl;
      TreeNodestudents* slookup = studentTable.peek(ssearch);
      Faculty fsearch;
      fsearch.setID(slookup->key.advisor);
      if(facultyTable.search(fsearch)) {
        TreeNodefaculty* flookup = facultyTable.peek(fsearch);
        cout << "Advisor is:" << endl;
        cout << "ID: " << flookup->key.id << endl;
        cout << "Name: " << flookup->key.name << endl;
        cout << "Level: " << flookup->key.level << endl;
        cout << "Department: " << flookup->key.area << endl;
        cout << "Advisee ID: " << flookup->key.advisee << endl;
        cout << "--------------------" << endl;
      } else {
        cout << "No advisor found." << endl;
      }
    } else {
      cout << "No record found for that ID." << endl;
    }
  } else {
    Faculty fsearch;
    fsearch.setID(id);
    if(facultyTable.search(fsearch)) {
      cout << "Record found." << endl;
      TreeNodefaculty* flookup = facultyTable.peek(fsearch);
      Student ssearch;
      ssearch.setID(flookup->key.advisee);
      if(studentTable.search(ssearch)) {
        TreeNodestudents* slookup = studentTable.peek(ssearch);
        cout << "Advisee is:" << endl;
        cout << "ID: " << slookup->key.id << endl;
        cout << "Name: " << slookup->key.name << endl;
        cout << "Class: " << slookup->key.level << endl;
        cout << "Major: " << slookup->key.area << endl;
        cout << "GPA: " << slookup->key.gpa << endl;
        cout << "Advisor ID: " << slookup->key.advisor << endl;
        cout << "--------------------" << endl;
      } else {
        cout << "No advisee found." << endl;
      }
    } else {
      cout << "No record found for that ID." << endl;
    }
  }
}

void File::addStudent(int i, string n, string l, string a, double g, int ad) {
  studentTable.insert(Student(i, n, l, a, g, ad));
  rollbackPeople.push(Student(i, n, l, a, g, ad));
  rollbackType.push(-1); // would be deleted
}

void File::addFaculty(int i, string n, string l, string a, int ad) {
  facultyTable.insert(Faculty(i, n, l, a, ad));
  rollbackPeople.push(Faculty(i, n, l, a, ad));
  rollbackType.push(-1); // would be deleted
}

void File::deletePerson(bool b, int id) {
  if(b) {
    Student ssearch;
    ssearch.setID(id);
    if(studentTable.search(ssearch)) {
      cout << "Record found." << endl;
      TreeNodestudents* sdelete = studentTable.remove(ssearch);
      studentTable.insert(Student(sdelete->key.id, sdelete->key.name, sdelete->key.level, sdelete->key.area, sdelete->key.gpa, sdelete->key.advisor));
      rollbackPeople.push(Student(sdelete->key.id, sdelete->key.name, sdelete->key.level, sdelete->key.area, sdelete->key.gpa, sdelete->key.advisor));
      rollbackType.push(1); // would be added
    } else {
      cout << "No record found for that ID." << endl;
    }
  } else {
    Faculty fsearch;
    fsearch.setID(id);
    if(facultyTable.search(fsearch)) {
      cout << "Record found." << endl;
      TreeNodefaculty* fdelete = facultyTable.remove(fsearch);
      facultyTable.insert(Faculty(fdelete->key.id, fdelete->key.name, fdelete->key.level, fdelete->key.area, fdelete->key.advisee));
      rollbackPeople.push(Faculty(fdelete->key.id, fdelete->key.name, fdelete->key.level, fdelete->key.area, fdelete->key.advisee));
      rollbackType.push(1); // would be added
    } else {
      cout << "No record found for that ID." << endl;
    }
  }
}

void File::changeAdvising(bool b, int id, int ad) {
  if(b) {
    Student ssearch;
    ssearch.setID(id);
    if(studentTable.search(ssearch)) {
      TreeNodestudents* slookup = studentTable.peek(ssearch);
      rollbackPeople.push(Student(slookup->key.id, slookup->key.name, slookup->key.level, slookup->key.area, slookup->key.gpa, slookup->key.advisor));
      rollbackType.push(0); // would be modified
      slookup->setAdvisor(ad);
    } else {
      cout << "No record found for that ID." << endl;
    }
  } else {
    Faculty fsearch;
    fsearch.setID(id);
    if(facultyTable.search(fsearch)) {
      TreeNodefaculty* flookup = facultyTable.peek(fsearch);
      rollbackPeople.push(Faculty(flookup->key.id, flookup->key.name, flookup->key.level, flookup->key.area, flookup->key.advisee));
      rollbackType.push(0); // would be modified
      flookup->setAdvisee(ad);
    } else {
      cout << "No record found for that ID." << endl;
    }
  }
}

void File::rollback() {
  Person personchange = rollbackPeople.pop();
  string personclass = typeid(personchange).name();
  string personcomp = typeid(Student()).name();
  int typechange = rollbackType.pop();
  if(typechange == -1) { // delete person
    if(personclass == personcomp) { // student
      deletePerson(true, personchange.getID());
    } else { // faculty
      deletePerson(false, personchange.getID());
    }
  } else if(typechange == 0) { // modify person
    if(personclass == personcomp) { // student
      TreeNodestudents* slookup = studentTable.peek(Student(personchange.getID(), personchange.getName(), personchange.getLevel(), personchange.getArea(), personchange.getGPA(), personchange.getAdvisor()));
      slookup->setAdvisor(personchange.getAdvisor());
    } else { // faculty
      TreeNodefaculty* flookup = facultyTable.peek(Student(personchange.getID(), personchange.getName(), personchange.getLevel(), personchange.getArea(), personchange.getGPA(), personchange.getAdvisor()));
      flookup->setAdvisee(personchange.getAdvisee());
    }
  } else { // add person
    if(personclass == personcomp) { // student
      addStudent(personchange.getID(), personchange.getName(), personchange.getLevel(), personchange.getArea(), personchange.getGPA(), personchange.getAdvisor());
    } else { // faculty
      addFaculty(personchange.getID(), personchange.getName(), personchange.getLevel(), personchange.getArea(), personchange.getAdvisee());
    }
  }
}

void File::serialize() {
  serial.serialize(studentTable, facultyTable, "studentTable.bst", "facultyTable.bst");
}

void File::deserialize() {
  serial.deserialize(studentTable, facultyTable, "studentTable.bst", "facultyTable.bst");
}

void File::printMenu() {
  cout << "1. View all people" << endl;
  cout << "2. View all students" << endl;
  cout << "3. View all faculty members" << endl;
  cout << "4. View a student" << endl;
  cout << "5. View a faculty member" << endl;
  cout << "6. View the advisor of a student" << endl;
  cout << "7. View the advisee of a faculty member" << endl;
  cout << "8. Add a student" << endl;
  cout << "9. Add a faculty member" << endl;
  cout << "10. Delete a student" << endl;
  cout << "11. Delete a faculty member" << endl;
  cout << "12. Change the advisor of a student" << endl;
  cout << "13. Change the advisee of a faculty member" << endl;
  cout << "14. Undo the previous action" << endl;
  cout << "15. Exit" << endl;
}
