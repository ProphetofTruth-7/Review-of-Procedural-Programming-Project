// Grade Book Branch

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string firstName(ifstream& x, string y) {
    getline(x, y, ' ');
    return y;
}
void storeNames(ifstream& x, string y, string array[], int z) {
    int increment = 0, gradeIncrement = 0;

    do {
        gradeIncrement = 0;
        getline(x, y, ' ');
        array[increment++] = y;
        do {
            getline(x, y, ' ');
            gradeIncrement++;
        } while (gradeIncrement < z);
    } while (increment < 6);         //Figure out how to make this variable
}

int main()
{
    
    
    string filename = "StudentGrades.txt"; //File Initialization bits
    ifstream GRADEFILE(filename);
    if (!GRADEFILE) {
            cout << "Error opening file!" << endl;
        return 1;
    }


    const int TOTALSCORES = 5;
    string testy;
    int loopIncrement = 0;

    string StudentNameArray[10]; //Partially Filled Array for Student Names. 10 is Arbitary
    int currentSize; // Used for the size of other Arrays. Depends on how filled the StudentNameArray is
    int TestScoresArray[5][TOTALSCORES]; //Filled Array. 5 Rows for 5 Students, TOTALSCORES Columns for number of TestScores
    double AverageScoreArray[5]; //Filled Array. Empty for now, 5 spots for 5 students.

    storeNames(GRADEFILE, testy, StudentNameArray, TOTALSCORES);
    cout << StudentNameArray[0] << endl;
    cout << StudentNameArray[1] << endl;
    cout << StudentNameArray[5] << endl;

    return 0;
}


