// Grade Book Branch

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string filename = "StudentGrades.txt";

    ifstream inFile(filename);
    if (!inFile) {
            cout << "Error opening file!" << endl;
        return 1;
    }

    int fileVariable = 0;
    string fileString = "L";
    int numberOfGrades = 0;

    cout << "How many grades were each of these students assigned?" << endl;




    cout << "This is the Grade Book Subproject\n";
    return 0;
}
