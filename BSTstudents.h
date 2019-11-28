#include "TreeNodestudents.h"
#include <iostream>
#include <fstream>

using namespace std;

class BSTstudents {
private:
  TreeNodestudents *root = new TreeNodestudents();
  friend class Serializer;
  friend class File;
public:
  BSTstudents();
  ~BSTstudents();

  bool search(Student s);
  TreeNodestudents* peek(Student s);
  void insert(Student s);
  TreeNodestudents* remove(Student s);
  TreeNodestudents* getSuccessor(TreeNodestudents *d);

  bool isEmpty();
  TreeNodestudents* getMin();
  TreeNodestudents* getMax();

  void preorderTraversal(ofstream& file);
  void inorderTraversal(ofstream& file);
  void postorderTraversal(ofstream& file);
  void recTraversal(TreeNodestudents *node, int i, ofstream& file);

  void preorderPrint();
  void inorderPrint();
  void postorderPrint();
  void recPrint(TreeNodestudents *node, int i);
};

BSTstudents::BSTstudents() {
  root = NULL;
}

BSTstudents::~BSTstudents() {
  delete root;
}

bool BSTstudents::search(Student s) {
  if(root == NULL) {
    return false;
  }
  TreeNodestudents *current = root;
  while(current->key.id != s.id) {
    if(s.id < current->key.id) {
      cout << s.id << endl;
      cout << current->key.id << endl;
      current = current->left;
    } else {
      current = current->right;
    }
    if(current == NULL) { // value not in tree
      return false;
    }
  }
  return true;
}

TreeNodestudents* BSTstudents::peek(Student s) {
  if(root == NULL) {
    return NULL;
  }
  TreeNodestudents *current = root;
  while(current->key.id != s.id) {
    if(s.id < current->key.id) {
      cout << s.id << endl;
      cout << current->key.id << endl;
      current = current->left;
    } else {
      current = current->right;
    }
    if(current == NULL) { // value not in tree
      return NULL;
    }
  }
  return current;
}

void BSTstudents::insert(Student s) {
  if(search(s)) {
    return;
  }
  TreeNodestudents *node = new TreeNodestudents(s);
  if(root == NULL) { // empty tree
    root = node;
  } else { // tree not empty, find insertion point
    TreeNodestudents *current = root;
    TreeNodestudents *parent = NULL;
    while(true) {
      parent = current;
      if(s.id < current->key.id) { // go left
        current = current->left;
        if(current == NULL) {
          parent->left = node;
          return;
        }
      } else { // go right
        current = current->right;
        if(current == NULL) {
          parent->right = node;
          return;
        }
      }
    }
  }
}

TreeNodestudents* BSTstudents::remove(Student s) {
  if(root == NULL) {
    return NULL;
  }
  TreeNodestudents *parent = root;
  TreeNodestudents *current = root;
  bool isLeft = true;
  while(current->key.id != s.id) {
    parent = current;
    if(s.id < current->key.id) {
      isLeft = true;
      current = parent->left;
    } else {
      isLeft = false;
      current = parent->right;
    }
    if(current == NULL) {
      return NULL;
    }
  }
  if(current->left == NULL && current->right == NULL) { // node is a leaf
    if(current == root) {
      root = NULL;
    } else if(isLeft) {
      parent->left = NULL;
    } else {
      parent->right = NULL;
    }
  }
  else if(current->right == NULL) { // node has one child, on the left
    if(current == root) {
      root = current->left;
    } else if(isLeft) {
      parent->left = current->left;
    } else {
      parent->right = current->left;
    }
  }
  else if(current->left == NULL) { // node has one child, on the right
    if(current == root) {
      root = current->right;
    } else if(isLeft) {
      parent->left = current->right;
    } else {
      parent->right = current->right;
    }
  } else { // node has two children
    TreeNodestudents *successor = getSuccessor(current);
    if(current == root) {
      root = successor;
    } else if(isLeft) {
      parent->left = successor;
    } else {
      parent->right = successor;
    }
    successor->left = current->left;
  }
  return current;
}

TreeNodestudents* BSTstudents::getSuccessor(TreeNodestudents *d) { // d is the node to be deleted
  TreeNodestudents *current = d->right;
  TreeNodestudents *sp = d; // successor's parent
  TreeNodestudents *successor = d;
  while(current != NULL) {
    sp = successor;
    successor = current;
    current = current->left;
  }
  if(successor != d->right) { // successor is not first node checked
    sp->left = successor->right;
    successor->right = d->right;
  }
  return successor;
}

bool BSTstudents::isEmpty() {
  if(root == NULL) {
    return true;
  }
  return false;
}

TreeNodestudents* BSTstudents::getMin() {
  TreeNodestudents *current = root;
  if(root == NULL) {
    return NULL;
  } else {
    while(current->left != NULL) {
      current = current->left; // keep going down to the left
    }
    return current;
  }
}

TreeNodestudents* BSTstudents::getMax() {
  TreeNodestudents *current = root;
  if(root == NULL) {
    return NULL;
  } else {
    while(current->right != NULL) {
      current = current->right; // keep going down to the right
    }
    return current;
  }
}

void BSTstudents::preorderTraversal(ofstream& file) {
  recTraversal(root, 0, file);
}

void BSTstudents::inorderTraversal(ofstream& file) {
  recTraversal(root, 1, file);
}

void BSTstudents::postorderTraversal(ofstream& file) {
  recTraversal(root, 2, file);
}

void BSTstudents::recTraversal(TreeNodestudents *node, int i, ofstream& file) {
  if(node == NULL) {
    return;
  }
  if(i == 0) {
    file << node->key.id << endl;
    file << node->key.name << endl;
    file << node->key.level << endl;
    file << node->key.area << endl;
    file << node->key.gpa << endl;
    file << node->key.advisor << endl;
    recTraversal(node->left, 0, file);
    recTraversal(node->right, 0, file);
  } else if(i == 1) {
    recTraversal(node->left, 1, file);
    file << node->key.id << endl;
    file << node->key.name << endl;
    file << node->key.level << endl;
    file << node->key.area << endl;
    file << node->key.gpa << endl;
    file << node->key.advisor << endl;
    recTraversal(node->right, 1, file);
  } else {
    recTraversal(node->left, 2, file);
    recTraversal(node->right, 2, file);
    file << node->key.id << endl;
    file << node->key.name << endl;
    file << node->key.level << endl;
    file << node->key.area << endl;
    file << node->key.gpa << endl;
    file << node->key.advisor << endl;
  }
}

void BSTstudents::preorderPrint() {
  recPrint(root, 0);
}

void BSTstudents::inorderPrint() {
  recPrint(root, 1);
}

void BSTstudents::postorderPrint() {
  recPrint(root, 2);
}

void BSTstudents::recPrint(TreeNodestudents *node, int i) {
  if(node == NULL) {
    return;
  }
  if(i == 0) {
    cout << "ID: " << node->key.id << endl;
    cout << "Name: " << node->key.name << endl;
    cout << "Class: " << node->key.level << endl;
    cout << "Major: " << node->key.area << endl;
    cout << "GPA: " << node->key.gpa << endl;
    cout << "Advisor ID: " << node->key.advisor << endl;
    cout << "--------------------" << endl;
    recPrint(node->left, 0);
    recPrint(node->right, 0);
  } else if(i == 1) {
    recPrint(node->left, 1);
    cout << "ID: " << node->key.id << endl;
    cout << "Name: " << node->key.name << endl;
    cout << "Class: " << node->key.level << endl;
    cout << "Major: " << node->key.area << endl;
    cout << "GPA: " << node->key.gpa << endl;
    cout << "Advisor ID: " << node->key.advisor << endl;
    cout << "--------------------" << endl;
    recPrint(node->right, 1);
  } else {
    recPrint(node->left, 2);
    recPrint(node->right, 2);
    cout << "ID: " << node->key.id << endl;
    cout << "Name: " << node->key.name << endl;
    cout << "Class: " << node->key.level << endl;
    cout << "Major: " << node->key.area << endl;
    cout << "GPA: " << node->key.gpa << endl;
    cout << "Advisor ID: " << node->key.advisor << endl;
    cout << "--------------------" << endl;
  }
}
