
#include <fstream>
#include "BST.h"

int main()
{
    ifstream file;

    file.open("input.txt");
    if (!file.is_open())
        cout << "Unable to find/open the input file!";
    else if (file.peek() == -1)
        cout << "ERROR! THE FILE IS EMPTY!\n";
    else
    {
        BST obj1, obj2, obj3;        //one tree to store all the data, another to retrieve some data
        string key = "Isaac Newton"; //a key string to use for "display/remove/retrieve matches" functions

        while (!file.eof()) //insert the data of the file to the BST
        {
            string name;
            getline(file, name);
            obj1 += name;
        }

        cout << "---------------------------------------------------------------------\n";
        cout << "TEST BST FUNCTIONS\n";
        cout << "---------------------------------------------------------------------\n";

        cout << "ORIGINAL LIST:\n"; //display the content of the entire BST object after inserting
        cout << obj1 << " item(s) in the tree\n";
        cout << "---------------------------------------------------------------------\n";

        obj3 = obj1; //make a deep copy of the assigned BST

        cout << "Looking for matches to RETRIEVE:\n";
        obj1.retrieve(obj2, key); //retrieves all instances of a key string
        cout << obj2 << " item(s) retrieved!\n";
        cout << "---------------------------------------------------------------------\n";

        cout << "Looking for matches to DISPLAY:\n"; //display all instances of a key string
        cout << obj1.display(key) << " matche(s) displayed!\n";
        cout << "---------------------------------------------------------------------\n";

        cout << "Looking for matches to REMOVE:\n"; //remove all instances of a key string
        cout << obj1.remove(key) << " matche(s) removed!\n";
        cout << "---------------------------------------------------------------------\n";

        cout << "MODIFIED LIST:\n"; //display the content of the entire BST object after removing
        cout << obj1 << " item(s) in the tree\n";
        cout << "---------------------------------------------------------------------\n";

        cout << "COPIED (ORIGINAL) LIST:\n"; //display the list that has been copied using the = operator
        cout << obj3 << " item(s) in the tree\n";
        cout << "---------------------------------------------------------------------\n";
    }
    file.close();
    file.clear();
    return 1;
}

//end