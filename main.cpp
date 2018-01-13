
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
        BST obj1, obj2;                    //one tree to store all the data, another to retrieve some data
        string key = "Isaac Newton"; //a key string to use for "display/remove/retrieve matches" functions

        while (!file.eof()) //insert the data of the file to the BST
        {
            string name;
            getline(file, name);
            obj1.insert(name);
        }

        cout << "---------------------------------------------------------------------\n";
        cout << "TEST BST FUNCTIONS\n";
        cout << "---------------------------------------------------------------------\n";
        cout << "ORIGINAL LIST:\n"; //display the content of the entire BST object after inserting
        cout << obj1.display_all() << " item(s) in the tree\n";
        cout << "---------------------------------------------------------------------\n";
        cout << "Looking for matches to RETRIEVE:\n";
        obj1.retrieve(obj2, key); //retrieves all instances of a key string
        cout << obj2.display_all() << " item(s) retrieved!\n";
        cout << "---------------------------------------------------------------------\n";
        cout << "Looking for matches to DISPLAY:\n"; //display all instances of a key string
        cout << obj1.display(key) << " matche(s) displayed!\n";
        cout << "---------------------------------------------------------------------\n";
        cout << "Looking for matches to REMOVE:\n"; //remove all instances of a key string
        cout << obj1.remove(key) << " matche(s) removed!\n";
        cout << "---------------------------------------------------------------------\n";
        cout << "MODIFIED LIST:\n"; ////display the content of the entire BST object after removing
        cout << obj1.display_all() << " item(s) in the tree\n";
        cout << "---------------------------------------------------------------------\n";
    }
    file.close();
    file.clear();
    return 1;
}

//end