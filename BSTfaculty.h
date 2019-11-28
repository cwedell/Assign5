#include "TreeNodefaculty.h"
#include <iostream>
#include <fstream>

using namespace std;

class BSTfaculty {
private:
  TreeNodefaculty *root = new TreeNodefaculty();
  friend class Serializer;
  friend class File;
public:
  BSTfaculty();
  ~BSTfaculty();

  bool search(Faculty f);
  TreeNodefaculty* peek(Faculty f);
  void insert(Faculty f);
  TreeNodefaculty* remove(Faculty f);
  TreeNodefaculty* getSuccessor(TreeNodefaculty *d);

  bool isEmpty();
  TreeNodefaculty* getMin();
  TreeNodefaculty* getMax();

  void preorderTraversal(ofstream& file);
  void inorderTraversal(ofstream& file);
  void postorderTraversal(ofstream& file);
  void recTraversal(TreeNodefaculty *node, int i, ofstream& file);

  void preorderPrint();
  void inorderPrint();
  void postorderPrint();
  void recPrint(TreeNodefaculty *node, int i);
};

BSTfaculty::BSTfaculty() {
  root = NULL;
}

BSTfaculty::~BSTfaculty() {
  delete root;
}

bool BSTfaculty::search(Faculty f) {
  if(root == NULL) {
    return false;
  }
  TreeNodefaculty *current = root;
  while(current->key.id != f.id) {
    if(f.id < current->key.id) {
      cout << f.id << endl;
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

TreeNodefaculty* BSTfaculty::peek(Faculty f) {
  if(root == NULL) {
    return NULL;
  }
  TreeNodefaculty *current = root;
  while(current->key.id != f.id) {
    if(f.id < current->key.id) {
      cout << f.id << endl;
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

void BSTfaculty::insert(Faculty f) {
  if(search(f)) {
    return;
  }
  TreeNodefaculty *node = new TreeNodefaculty(f);
  if(root == NULL) { // empty tree
    root = node;
  } else { // tree not empty, find insertion point
    TreeNodefaculty *current = root;
    TreeNodefaculty *parent = NULL;
    while(true) {
      parent = current;
      if(f.id < current->key.id) { // go left
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

TreeNodefaculty* BSTfaculty::remove(Faculty f) {
  if(root == NULL) {
    return NULL;
  }
  TreeNodefaculty *parent = root;
  TreeNodefaculty *current = root;
  bool isLeft = true;
  while(current->key.id != f.id) {
    parent = current;
    if(f.id < current->key.id) {
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
    TreeNodefaculty *successor = getSuccessor(current);
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

TreeNodefaculty* BSTfaculty::getSuccessor(TreeNodefaculty *d) { // d is the node to be deleted
  TreeNodefaculty *current = d->right;
  TreeNodefaculty *sp = d; // successor's parent
  TreeNodefaculty *successor = d;
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

bool BSTfaculty::isEmpty() {
  if(root == NULL) {
    return true;
  }
  return false;
}

TreeNodefaculty* BSTfaculty::getMin() {
  TreeNodefaculty *current = root;
  if(root == NULL) {
    return NULL;
  } else {
    while(current->left != NULL) {
      current = current->left; // keep going down to the left
    }
    return current;
  }
}

TreeNodefaculty* BSTfaculty::getMax() {
  TreeNodefaculty *current = root;
  if(root == NULL) {
    return NULL;
  } else {
    while(current->right != NULL) {
      current = current->right; // keep going down to the right
    }
    return current;
  }
}

void BSTfaculty::preorderTraversal(ofstream& file) {
  recTraversal(root, 0, file);
}

void BSTfaculty::inorderTraversal(ofstream& file) {
  recTraversal(root, 1, file);
}

void BSTfaculty::postorderTraversal(ofstream& file) {
  recTraversal(root, 2, file);
}

void BSTfaculty::recTraversal(TreeNodefaculty *node, int i, ofstream& file) {
  if(node == NULL) {
    return;
  }
  if(i == 0) {
    file << node->key.id << endl;
    file << node->key.name << endl;
    file << node->key.level << endl;
    file << node->key.area << endl;
    file << node->key.advisee << endl;
    recTraversal(node->left, 0, file);
    recTraversal(node->right, 0, file);
  } else if(i == 1) {
    recTraversal(node->left, 1, file);
    file << node->key.id << endl;
    file << node->key.name << endl;
    file << node->key.level << endl;
    file << node->key.area << endl;
    file << node->key.advisee << endl;
    recTraversal(node->right, 1, file);
  } else {
    recTraversal(node->left, 2, file);
    recTraversal(node->right, 2, file);
    file << node->key.id << endl;
    file << node->key.name << endl;
    file << node->key.level << endl;
    file << node->key.area << endl;
    file << node->key.advisee << endl;
  }
}

void BSTfaculty::preorderPrint() {
  recPrint(root, 0);
}

void BSTfaculty::inorderPrint() {
  recPrint(root, 1);
}

void BSTfaculty::postorderPrint() {
  recPrint(root, 2);
}

void BSTfaculty::recPrint(TreeNodefaculty *node, int i) {
  if(node == NULL) {
    return;
  }
  if(i == 0) {
    cout << "ID: " << node->key.id << endl;
    cout << "Name: " << node->key.name << endl;
    cout << "Level: " << node->key.level << endl;
    cout << "Department: " << node->key.area << endl;
    cout << "Advisee ID: " << node->key.advisee << endl;
    cout << "--------------------" << endl;
    recPrint(node->left, 0);
    recPrint(node->right, 0);
  } else if(i == 1) {
    recPrint(node->left, 1);
    cout << "ID: " << node->key.id << endl;
    cout << "Name: " << node->key.name << endl;
    cout << "Level: " << node->key.level << endl;
    cout << "Department: " << node->key.area << endl;
    cout << "Advisee ID: " << node->key.advisee << endl;
    cout << "--------------------" << endl;
    recPrint(node->right, 1);
  } else {
    recPrint(node->left, 2);
    recPrint(node->right, 2);
    cout << "ID: " << node->key.id << endl;
    cout << "Name: " << node->key.name << endl;
    cout << "Level: " << node->key.level << endl;
    cout << "Department: " << node->key.area << endl;
    cout << "Advisee ID: " << node->key.advisee << endl;
    cout << "--------------------" << endl;
  }
}
