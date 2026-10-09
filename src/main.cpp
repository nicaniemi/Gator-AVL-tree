#include <iostream>
#include "AVL_header.h"
using namespace std;

int main()
{
    AVL tree;
    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        string line;
        getline(cin, line);

        // Pull command from input

        unsigned int const commandSpace = line.find(' ');
        string command = line.substr(0, commandSpace);

        // Define behavior based on input

        if (command == "insert")
        {
            unsigned int const beginName = line.find('"');
            unsigned int const endName = line.find('"', beginName + 1);
            string const name = line.substr(beginName + 1, endName - beginName - 1);

            string id = line.substr(endName + 2, line.size() - endName - 1);

            cout << tree.insert(name, id) << endl;
        }

        else if (command == "remove")
        {
            string id = line.substr(commandSpace + 1);

            cout << tree.removeByID(id) << endl;
        }

        else if (command == "search")
        {
            size_t quotePosition = line.find('"');

            if (quotePosition != string::npos)
            {
                unsigned int const beginName = line.find('"');
                unsigned int const endName = line.find('"', beginName + 1);
                string const name = line.substr(beginName + 1, endName - beginName - 1);
                cout << tree.searchByName(name) << endl;
            }

            else
            {
                string id = line.substr(commandSpace + 1);
                cout << tree.searchByID(id) << endl;
            }
        }

        else if (command == "printInorder")
            cout << tree.printInOrder() << endl;

        else if (command == "printPreorder")
            cout << tree.printPreOrder() << endl;

        else if (command == "printPostorder")
            cout << tree.printPostOrder() << endl;

        else if (command == "printLevelCount")
            cout << tree.printLevelCount() << endl;

        else if (command == "removeInorder")
        {
            string numNode = line.substr(commandSpace + 1);
            cout << tree.removeInOrder(stoi(numNode)) << endl;
        }
    }
}
