
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
} //recursion function
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
} //recursion function
int BST::insert(Node *&this_node, string &input)
{
    if (!this_node)
    {
        this_node = new Node;
        return this_node->set_data(input);
    }
    if (this_node->compare(input) == 1) //this_node comes after input
        return insert(this_node->get_left(), input);
    return insert(this_node->get_right(), input);
}

//retrieve function - inserts all the matches of a string input into the passed BST
int BST::retrieve(string &input, BST &matches)
{
    return retrieve(this->root, input, matches);
} //recursion function
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
    return display(this->root, input);
} //recursion function
int BST::display(Node *&this_node, string &input)
{
    if (!this_node)
        return 0;
    int temp = this_node->compare(input);
    int matches = 0;

    if (temp == 0)
    {
        this_node->display(); //print matches if any
        ++matches;            //count matches
    }

    //keep looking for the next ordered match if any
    if (temp == 1)
        return display(this_node->get_left(), input) + matches; //input is less that this_node go to left child
    return display(this_node->get_right(), input) + matches;    //input is larger that this_node go to right child
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

//remove function - removes all matching contents from the BST
int BST::remove(string &input)
{
    return remove(this->root, input);
} //recursion function
int BST::remove(Node *&this_node, string &input)
{
    if (!this_node)
        return 0;
    int temp = this_node->compare(input);
    int matches = 0;

    if (temp == 0) //a match is found
    {
        matches = remove(this_node);
        matches += remove(this_node, input);
    }
    else if (temp == 1) //no match, keep following the alphabetical order
        remove(this_node->get_left(), input);
    else if (temp == -1) //no match, keep following the alphabetical order
        remove(this_node->get_right(), input);
    return matches;
} //helper function
int BST::remove(Node *&t_node)
{
    Node *temp = t_node;
    Node *s_node = t_node->get_right();

    if (s_node) //check if the target node have a right child successor
    {
        s_node = get_successor(t_node->get_right());
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
} //returns the successor of the BST
Node *&BST::get_successor(Node *&this_node)
{
    if (!this_node->get_left())
    {
        Node *s_node = this_node;
        this_node = this_node->get_right();
        return s_node;
    }
    return get_successor(this_node->get_left());
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

//end