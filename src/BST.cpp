
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

//destructor - calls the recursive remove function
BST::~BST()
{
    remove_all();
}

//copy function - creates a deep copy of the given Node object into this Node object
int BST::copy(BST &original)
{
    return copy(this->root, original.root);
} //recursion function
int BST::copy(Node *&this_node, Node *&copy_node)
{
    if (!copy_node)
        return 0;
    this_node->copy(copy_node); //call Node class copy function
    return copy(this_node->get_left(), copy_node->get_left()) + copy(this_node->get_right(), copy_node->get_right()) + 1;
}

//retrieve function - inserts all the matches of a key input into the given BST
int BST::retrieve(BST &matches, string &input)
{
    return retrieve(this->root, input, matches);
} //recursion function
int BST::retrieve(Node *&this_node, string &input, BST &matches)
{
    if (!this_node)
        return 0;
    if (this_node->compare(input) == 0) //found a match
        matches.insert(this_node->get_data());
    return retrieve(this_node->get_left(), input, matches) + retrieve(this_node->get_right(), input, matches);
}

//insert function - insert new string inputs to the BST in alphabatical order
int BST::insert(string &input)
{
    return insert(this->root, input);
} //recursion function
int BST::insert(Node *&this_node, string &input)
{
    if (!this_node)
    {
        this_node = new Node;
        return this_node->set_data(input);
    }
    if (this_node->compare(input) == -1)
        return insert(this_node->get_left(), input); //go to left child (lower value)
    return insert(this_node->get_right(), input);    //go to right child (equal/larger value)
}

//display function - prints out all matching instances within the BST
int BST::display(string &input)
{
    return display(this->root, input);
} //recursion function
int BST::display(Node *&this_node, string &input)
{
    if (!this_node)
        return 0;
    int value = this_node->compare(input);
    int match = 0;

    if (value == 0)
    {
        this_node->display(); //print match
        match = 1;            //count match
    }
    if (value == -1)
        return display(this_node->get_left(), input) + match; //input has a lower value than this_node (go to left child)
    return display(this_node->get_right(), input) + match;    //input has a larger/equal value than this_node (go to right child)
}

//display function - prints out the entire contents of the BST
int BST::display_all()
{
    return display_all(this->root);
} //recursion function
int BST::display_all(Node *&this_node)
{
    if (!this_node)
        return 0;
    return display_all(this_node->get_left()) + this_node->display() + display_all(this_node->get_right());
}

//remove function - removes and clear out the entire contents of the BST
int BST::remove_all()
{
    return remove_all(this->root);
} //recursion function
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

//remove function - removes all matching instances from the BST
int BST::remove(string &input)
{
    return remove(this->root, input);
} //recursion function
int BST::remove(Node *&this_node, string &input)
{
    if (!this_node)
        return 0;
    int value = this_node->compare(input);
    int match = 0;

    if (value == 0)
    {
        get_successor(this_node); //find the right successor
        match = remove(this_node, input) + 1; //keep looking for other matches and count
    }
    else if (value == -1) //no match, keep following the alphabetical order
        match = remove(this_node->get_left(), input);
    else if (value == 1) //no match, keep following the alphabetical order
        match = remove(this_node->get_right(), input);
    return match;
} //helper function - removes the target Node and replace it with a right successor
int BST::get_successor(Node *&t_node)
{
    Node *temp = t_node; //hold target Node to be removed
    Node *s_node = t_node->get_right(); //hold successor Node to be replaced with the target Node

    if (s_node) //check if the target node have a right child successor
    {
        get_successor(s_node, t_node->get_right());
        s_node->set_left(t_node->get_left());
        s_node->set_right(t_node->get_right());
        t_node = s_node;
        delete temp;
        temp = NULL;
    }
    else
    {
        t_node = t_node->get_left();
        delete temp;
        temp = NULL;
    }
    return 1;
} //recursion function - find and return the right child successor of the target Node
int BST::get_successor(Node *&s_node, Node *&this_node)
{
    if (!this_node->get_left()) //checks if the right child successor is reached
    {
        s_node = this_node;
        this_node = this_node->get_right();
    }
    else
        get_successor(s_node, this_node->get_left());
    return 1;
}

//end