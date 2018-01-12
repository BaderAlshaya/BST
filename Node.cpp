
#include "Node.h"

//default constructor - initilizes local data members
Node::Node() : left(NULL), right(NULL)
{
}

//copy constructor - calls the copy function
Node::Node(Node *&original)
{
    copy(original);
}

//destructor - sets the deleted Nodes to NULL
Node::~Node()
{
    left = NULL;
    right = NULL;
}

//copy function - creates a deep copy of the passed Node object into this Node object
int Node::copy(Node *&original)
{
    if (original == NULL)
        return 0;
    this->data = original->data;   //deep copy of data
    this->left = original->left;   //deep copy of left
    this->right = original->right; //deep copy of right
    return 1;
}

//compare function - compares the current data string with the one being passed
int Node::compare(string &input)
{
    if (this->data < input)
        return -1;
    if (this->data == input)
        return 0;
    return 1;
}

//set function - sets this data string to match the one being passed
int Node::set_data(string &input)
{
    this->data = input;
    return 0;
}

//set function - sets the left node to match the one being passed
int Node::set_left(Node *&left)
{
    this->left = left;
    return 1;
}

//set function - sets the right node to match the one being passed
int Node::set_right(Node *&right)
{
    this->right = right;
    return 0;
}

//get function - returns a copy of the data
string &Node::get_data()
{
    return this->data;
}

//get function - returns a pointer of this left Node
Node *&Node::get_left()
{
    return this->left;
}

//get function - returns a pointer of this right Node
Node *&Node::get_right()
{
    return this->right;
}

//display function - prints out the content of this node
int Node::display()
{
    if (!this->data.length())
        cout << "- EMPTY STRING IN THE NODE" << endl;
    cout << "- " << data << endl;
    return 1;
}

//endl
