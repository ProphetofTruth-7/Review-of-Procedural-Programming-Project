// Grade Book Branch

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string firstName(ifstream& x, string y) {
    getline(x, y, ' ');
    return y;
}
void storeNames(ifstream& x, string y, string array[], int z, int& a) {
    int nameIncrement = 0, gradeIncrement = 0;

    do {
        gradeIncrement = 0;
        getline(x, y, ' ');
        array[nameIncrement++] = y;
        do {
            getline(x, y, ' ');
            gradeIncrement++;
        } while (gradeIncrement < z);
    } while (nameIncrement < 10);         //Arbitary 10
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
    string fileIndexVar;

    string StudentNameArray[10]; //Partially Filled Array for Student Names. 10 is Arbitary
    int currentSize = 0; // Used for the size of other Arrays. Depends on how filled the StudentNameArray is
    int TestScoresArray[5][TOTALSCORES]; //Filled Array. 5 Rows for 5 Students, TOTALSCORES Columns for number of TestScores
    double AverageScoreArray[5]; //Filled Array. Empty for now, 5 spots for 5 students.

    storeNames(GRADEFILE, fileIndexVar, StudentNameArray, TOTALSCORES, currentSize);
    cout << StudentNameArray[0] << endl;
    cout << StudentNameArray[1] << endl;
    cout << StudentNameArray[5] << endl;
    cout << StudentNameArray[9] << endl;
    cout << "Current Size: " << currentSize << endl;


    return 0;
}


