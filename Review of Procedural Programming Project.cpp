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

    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }




    cout << "This is the Grade Book Subproject\n";
    return 0;
}
