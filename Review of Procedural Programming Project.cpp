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
    int loopIncrement = 0;

    string StudentNameArray[10]; //Partially Filled Array for Student Names. 10 is Arbitary
    int currentSize; // Used for the size of other Arrays. Depends on how filled the StudentNameArray is
    int TestScoresArray[currentSize][TOTALSCORES]; //Filled Array. 5 Rows for 5 Students, TOTALSCORES Columns for number of TestScores
    double AverageScoreArray[currentSize]; //Filled Array. Empty for now, 5 spots for 5 students.



    getline(inFile, testy, ' '); //Ensure each value on attached file ends with a space. Failure to do so will cause errors
    cout << testy << " ";

    do {
        getline(inFile, testy, ' ');
        cout << testy << " ";
        ++loopIncrement;
    } while (loopIncrement < (TOTALSCORES));

    return 0;
}
