
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
  int insert(string &);
  int retrieve(string &, BST &);
  int display(string &);
  int display_all();
  int remove(string &);
  int remove_all();

private:
  Node *root;

  int copy(Node *&, Node *&);
  int insert(Node *&, string &);
  int retrieve(Node *&, string &, BST &);
  int display(Node *&, string &);
  int display_all(Node *&);
  int remove(Node *&, string &);
  int remove(Node *&);
  Node *&get_successor(Node *&);
  int remove_all(Node *&);
};

#endif