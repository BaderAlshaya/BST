
#include "BST.h"

//default constructor - initilizes local data members
BST::BST() : root(NULL)
{
}

//copy constructor - calls the copy function
BST::BST(BST &original)
{
    copy(original);
}

//destructor - calls the remove function
BST::~BST()
{
    remove_all();
}

//copy function - creates a deep copy of the passed Node object into this Node object
int BST::copy(BST &original)
{
    return copy(this->root, original.root);
} //helper function
int BST::copy(Node *&this_node, Node *&copy_node)
{
    if (!copy_node)
        return 0;
    this_node->copy(copy_node);
    return copy(this_node->get_left(), copy_node->get_left()) + copy(this_node->get_right(), copy_node->get_right()) + 1;
}

//adding function - adds new string inputs to the BST in alphabatical order
int BST::insert(string &input)
{
    return insert(this->root, input);
} //helper function
int BST::insert(Node *&this_node, string &input)
{
    if (!this_node)
    {
        this_node = new Node;
        return this_node->set_data(input);
    }
    return (this_node->compare(input)) ? insert(this_node->get_left(), input) : insert(this_node->get_right(), input);
}

//retrieve function - inserts all the matches of a string input into the passed BST
int BST::retrieve(string &input, BST &matches)
{
    return retrieve(this->root, input, matches);
}
int BST::retrieve(Node *&this_node, string &input, BST &matches)
{
    if (!this_node)
        return 0;
    if (this_node->compare(input) == 0)
        matches.insert(this_node->get_data());
    return retrieve(this_node->get_left(), input, matches) + retrieve(this_node->get_right(), input, matches);
}

//display function - prints out all matching contents within the BST
int BST::display(string &input)
{
    return 0;
}

//display function - prints out the entire contents of the BST
int BST::display_all()
{
    return display_all(this->root);
} //helper function
int BST::display_all(Node *&this_node)
{
    if (!this_node)
        return 0;
    return display_all(this_node->get_left()) + this_node->display() + display_all(this_node->get_right());
}

//remove function - removes all matching contents from the BST
int BST::remove(string &input)
{
    return 0;
}

//remove function - removes and clear out the entire contents of the BST
int BST::remove_all()
{
    return remove_all(this->root);
} //helper function
int BST::remove_all(Node *&this_node)
{
    if (!this_node)
        return 0;
    remove_all(this_node->get_left());
    remove_all(this_node->get_right());
    delete this_node;
    this_node = NULL;
    return 1;
}

//end