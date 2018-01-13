
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

//copy function - creates a deep copy of the given Node
int Node::copy(Node *&original)
{
    if (original != NULL)
    {
        this->data = original->data;   //copy the content of the given string
        this->left = original->left;   //copy the left pointer of the given Node
        this->right = original->right; //copy the right pointer of the given Node
    }
    return 1;
}

//compare function - compares the order value of the given data with the data of this object
int Node::compare(string &input)
{
    if (this->data > input) //the given input has a lower value than this object (go to left-child)
        return -1;
    if (this->data < input) //the given input has a larger value than this object (go to right-child)
        return 1;
    return 0; //the given input has an eqaual value with this object (go to right-child)
}

//set function - set the content of this data string to match the given string
int Node::set_data(string &input)
{
    this->data = input;
    return 1;
}

//set function - set the pointer of this left Node to match the given Node pointer
int Node::set_left(Node *&ptr)
{
    this->left = ptr;
    return 1;
}

//set function - set the pointer of this right Node to match the given Node pointer
int Node::set_right(Node *&ptr)
{
    this->right = ptr;
    return 1;
}

//get function - reference the data of this object
string &Node::get_data()
{
    return this->data;
}

//get function - reference the pointer of the left node of this object
Node *&Node::get_left()
{
    return this->left;
}

//get function - reference the pointer of the right node of this object
Node *&Node::get_right()
{
    return this->right;
}

//display function - print out the data content of this node
int Node::display()
{
    (this->data.length()) ? cout << "- " << data << "\n" : cout << "- EMPTY STRING IN THE NODE\n";
    return 1;
}

//endl
