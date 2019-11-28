#include "File.h"
#include <iostream>

using namespace std;

int main(int c, char** argv) {
  File f;
  bool userFinished = false;
  while(!userFinished) {
    f.printMenu();
    cout << "Please enter your choice." << endl;
    int menuChoice;
    while(true) {
      try {
        cin >> menuChoice;
        if(menuChoice < 1 || menuChoice > 15) {
          throw new exception;
        }
        break;
      } catch(exception& e) {
        cout << "Invalid choice. Please enter your choice." << endl;
      }
    }
    int tryid4;
    int tryid5;
    int tryid6;
    int tryid7;
    int tryid8;
    string tryname8;
    string trylevel8;
    string tryarea8;
    double trygpa8;
    int tryadvisor8;
    int tryid9;
    string tryname9;
    string trylevel9;
    string tryarea9;
    int tryadvisee9;
    int tryid10;
    int tryid11;
    int tryid12;
    int tryadvisor12;
    int tryid13;
    int tryadvisee13;
    switch (menuChoice) {
      case 1: f.printAll();
        break;
      case 2: f.printTable(true);
        break;
      case 3: f.printTable(false);
        break;
      case 4: cout << "Enter the ID." << endl;
        while(true) {
          try {
            cin >> tryid4;
            break;
          } catch(exception& e) {
            cout << "Not a number. Enter the ID." << endl;
          }
        }
        f.printPerson(true, tryid4);
        break;
      case 5: cout << "Enter the ID." << endl;
        while(true) {
          try {
            cin >> tryid5;
            break;
          } catch(exception& e) {
            cout << "Not a number. Enter the ID." << endl;
          }
        }
        f.printPerson(false, tryid5);
        break;
      case 6: cout << "Enter the ID." << endl;
        while(true) {
          try {
            cin >> tryid6;
            break;
          } catch(exception& e) {
            cout << "Not a number. Enter the ID." << endl;
          }
        }
        f.printAdvising(true, tryid6);
        break;
      case 7: cout << "Enter the ID." << endl;
        while(true) {
          try {
            cin >> tryid7;
            break;
          } catch(exception& e) {
            cout << "Not a number. Enter the ID." << endl;
          }
        }
        f.printAdvising(true, tryid7);
        break;
      case 8: cout << "Enter the ID." << endl;
        while(true) {
          try {
            cin >> tryid8;
            break;
          } catch(exception& e) {
            cout << "Not a number. Enter the ID." << endl;
          }
        }
        cout << "Enter the name." << endl;
        cin >> tryname8;
        cout << "Enter the class." << endl;
        cin >> trylevel8;
        cout << "Enter the major." << endl;
        cin >> tryarea8;
        while(true) {
          try {
            cin >> trygpa8;
            break;
          } catch(exception& e) {
            cout << "Not a number. Enter the GPA." << endl;
          }
        }
        cout << "Enter the advisor ID." << endl;
        while(true) {
          try {
            cin >> tryadvisor8;
            break;
          } catch(exception& e) {
            cout << "Not a number. Enter the advisor ID." << endl;
          }
        }
        f.addStudent(tryid8, tryname8, trylevel8, tryarea8, trygpa8, tryadvisor8);
        break;
      case 9: cout << "Enter the ID." << endl;
        while(true) {
          try {
            cin >> tryid9;
            break;
          } catch(exception& e) {
            cout << "Not a number. Enter the ID." << endl;
          }
        }
        cout << "Enter the name." << endl;
        cin >> tryname9;
        cout << "Enter the class." << endl;
        cin >> trylevel9;
        cout << "Enter the major." << endl;
        cin >> tryarea9;
        cout << "Enter the advisee ID." << endl;
        while(true) {
          try {
            cin >> tryadvisee9;
            break;
          } catch(exception& e) {
            cout << "Not a number. Enter the advisee ID." << endl;
          }
        }
        f.addFaculty(tryid9, tryname9, trylevel9, tryarea9, tryadvisee9);
        break;
      case 10: cout << "Enter the ID." << endl;
        while(true) {
          try {
            cin >> tryid10;
            break;
          } catch(exception& e) {
            cout << "Not a number. Enter the ID." << endl;
          }
        }
        f.deletePerson(true, tryid10);
        break;
      case 11: cout << "Enter the ID." << endl;
        while(true) {
          try {
            cin >> tryid11;
            break;
          } catch(exception& e) {
            cout << "Not a number. Enter the ID." << endl;
          }
        }
        f.deletePerson(false, tryid11);
        break;
      case 12: cout << "Enter the ID." << endl;
        while(true) {
          try {
            cin >> tryid12;
            break;
          } catch(exception& e) {
            cout << "Not a number. Enter the ID." << endl;
          }
        }
        cout << "Enter the advisor ID." << endl;
        while(true) {
          try {
            cin >> tryadvisor12;
            break;
          } catch(exception& e) {
            cout << "Not a number. Enter the advisor ID." << endl;
          }
        }
        f.changeAdvising(true, tryid12, tryadvisor12);
        break;
      case 13: cout << "Enter the ID." << endl;
        while(true) {
          try {
            cin >> tryid13;
            break;
          } catch(exception& e) {
            cout << "Not a number. Enter the ID." << endl;
          }
        }
        cout << "Enter the advisee ID." << endl;
        while(true) {
          try {
            cin >> tryadvisee13;
            break;
          } catch(exception& e) {
            cout << "Not a number. Enter the advisee ID." << endl;
          }
        }
        f.changeAdvising(false, tryid13, tryadvisee13);
        break;
      case 14: if(f.rollbackPeople.isEmpty()) {
          cout << "Nothing to undo." << endl;
        } else {
          if(f.rollbackType.peek() == -1) {
            f.rollback();
            cout << "Undo complete. Record deleted." << endl;
          } else if(f.rollbackType.peek() == 0) {
            f.rollback();
            cout << "Undo complete. Record modified." << endl;
          } else {
            f.rollback();
            cout << "Undo complete. Record added." << endl;
          }
        }
        break;
      default: cout << "Goodbye!" << endl;
        userFinished = true;
        goto EXIT;
        break;
    }
  }
  EXIT:
  return 0;
}
