// Grade Book Branch

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string firstName(ifstream& x, string y) {
    getline(x, y, ' ');
    return y;
}
void storeNames(ifstream& x, string y, string array[], int z, int& a) {    //Not sure how to properly use a Partially Filled Array
    int nameIncrement = 0, gradeIncrement = 0;

    do {
        gradeIncrement = 0;
        getline(x, y, ' ');  //Grabs the name and the name only
        array[nameIncrement++] = y; //Puts said name into the StudentNameArray at its proper index
        do {
            getline(x, y, ' '); //"Grabs" the numbers and ignores them
            gradeIncrement++;
        } while (gradeIncrement < z); //Continues until all numbers are ignored(according to the TOTALSCORES constant)
    } while (nameIncrement < 10);  //This is where I mess up. I can't make this final check fluid. I either make it rigid(6) and perfectly fit the student number
    //Or make it wide(10), which is just an array with extra steps(and I can't use currentSize
    //Mainly, I just want to know whats the better way to do this. The Partially Filled examples
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


