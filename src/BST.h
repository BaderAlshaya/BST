
#ifndef BST_H
#define BST_H
#include "Node.h"

class BST : public Node
{
public:
  BST();
  BST(BST &);
  ~BST();
  int copy(BST &);
  int retrieve(BST &, string &);
  int insert(string &);
  int display(string &);
  int display_all();
  int remove_all();
  int remove(string &);
  BST operator=(BST &);
  BST operator+=(string &);
  friend ostream &operator<<(ostream &, BST &);

private:
  Node *root;

  int copy(Node *&, Node *&);
  int retrieve(Node *&, string &, BST &);
  int insert(Node *&, string &);
  int display(Node *&, string &);
  int display_all(Node *&);
  int remove_all(Node *&);
  int remove(Node *&, string &);
  int get_successor(Node *&);
  int get_successor(Node *&, Node *&);
};

#endif