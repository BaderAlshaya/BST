
#include <fstream>
#include "BST.h"

int main()
{
    BST obj1;
    BST obj2;
    ifstream file;
    string key = "Archimedes"; //a key string to test "display/remove matches" functions

    file.open("input.txt");
    if (!file.is_open())
        cout << "Unable to find/open the input file!";
    else if (file.peek() == -1)
        cout << "ERROR! THE FILE IS EMPTY!\n";
    else
    {
        int count1;
        string input;

        while (!file.eof())
        {
            string name;
            getline(file, name);
            obj1.insert(name);
        }
        cout << "---------------------------------------------------------------------\n";
        cout << "ORIGINAL LIST:\n\n";
        count1 = obj1.display_all();
        cout << "This tree has " << count1 << " nodes!" << endl;
        obj1.retrieve(input, obj2);
        cout << "---------------------------------------------------------------------\n";
        cout << "Looking for matches to DISPLAY:\n";
        cout << obj1.display(key) << " matche(s) displayed!\n";
        cout << "---------------------------------------------------------------------\n";
        cout << "Looking for matches to REMOVE:\n";
        cout << obj1.remove(key) << " matche(s) removed!\n";
        cout << "---------------------------------------------------------------------\n";
        cout << "MODIFIED LIST:\n\n";
        count1 = obj1.display_all();
        cout << "This tree has " << count1 << " node(s)!" << endl;
        cout << "---------------------------------------------------------------------\n";
    }
    file.close();
    file.clear();
    return 0;
}

//end