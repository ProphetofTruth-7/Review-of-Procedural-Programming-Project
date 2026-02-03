// Grade Book Branch

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int TOTAL_SCORES = 5;
const int MAX_STUDENTS = 35;


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

int studentDataRetrieval(ifstream& x, string student[], double scores[MAX_STUDENTS][TOTAL_SCORES], string y, int a) {
    int counter = 0, gradeIncrement = 0;

    while (counter < MAX_STUDENTS && x >> student[counter]) {
        gradeIncrement = 0;
        getline(x, y, ' ');
        student[counter] = y;
        do {
            getline(x, y, ' ');
            scores[counter][gradeIncrement] = a;
            gradeIncrement++;
        } while (gradeIncrement < TOTAL_SCORES);
        ++counter;
    }
    return counter;
}

int main()
{
    string filename = "StudentGrades.txt"; //File Initialization bits
    ifstream GRADEFILE(filename);
    if (!GRADEFILE) {
            cout << "Error opening file!" << endl;
        return 1;
    }





    string fileIndexVar;
    int fileIndexVar2;

    string StudentNameArray[MAX_STUDENTS]; //Partially Filled Array for Student Names. 10 is Arbitary
    int currentSize = 0; // Used for the size of other Arrays. Depends on how filled the StudentNameArray is
    double TestScoresArray[MAX_STUDENTS][TOTAL_SCORES]; //Filled Array. 5 Rows for 5 Students, TOTALSCORES Columns for number of TestScores
    double AverageScoreArray[5]; //Filled Array. Empty for now, 5 spots for 5 students.

    cout << studentDataRetrieval(GRADEFILE, StudentNameArray, TestScoresArray[MAX_STUDENTS][TOTAL_SCORES], fileIndexVar, fileIndexVar2) << endl;

    storeNames(GRADEFILE, fileIndexVar, StudentNameArray, TOTAL_SCORES, currentSize);
    cout << StudentNameArray[0] << endl;
    cout << StudentNameArray[1] << endl;
    cout << StudentNameArray[5] << endl;
    cout << StudentNameArray[9] << endl;
    cout << "Current Size: " << currentSize << endl;

    return 0;
}


