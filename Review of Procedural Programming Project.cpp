// Grade Book Branch

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string filename = "StudentGrades.txt"; //File Initialization bits
    ifstream inFile(filename);
    if (!inFile) {
            cout << "Error opening file!" << endl;
        return 1;
    }


    const int TOTALSCORES = 5;

    string testy;

    getline(inFile, testy);   //How do I split the Name from the Test Scores? This reads the entire line no matter what
    cout << testy << endl;

    return 0;
}
