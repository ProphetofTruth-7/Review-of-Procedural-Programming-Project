// Grade Book Branch

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int TOTAL_SCORES = 5;
const int MAX_STUDENTS = 35;


int studentDataRetrieval(ifstream& x, string student[], string scores[MAX_STUDENTS][TOTAL_SCORES], string y, double a) {
    int counter = 0, gradeIncrement = 0;

    while (counter < MAX_STUDENTS && x >> student[counter]) {
        gradeIncrement = 0;
        getline(x, y, ' ');
        student[counter] = y;    // It's no longer storing the names!!!
        do {
            getline(x, y, ' ');
            scores[counter][gradeIncrement] = y;      //The scores Array (aka the TestScores Array) refuses to be assigned unless its a string
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

    string StudentNameArray[MAX_STUDENTS]; //Partially Filled Array for Student Names
    string TestScoresArray[MAX_STUDENTS][TOTAL_SCORES]; //Filled Array. 5 Rows for 5 Students, TOTALSCORES Columns for number of TestScores
    double AverageScoreArray[MAX_STUDENTS]; //Filled Array. Empty for now, 5 spots for 5 students.

    string fileIndexVar;
    double fileIndexVar2 = 0;

    cout << "The Current Size is: " << studentDataRetrieval(GRADEFILE, StudentNameArray, TestScoresArray, fileIndexVar, fileIndexVar2) << endl;

    cout << "The First Student is: " << StudentNameArray[0] << endl;
    cout << TestScoresArray[0][0] << " " << TestScoresArray[0][1] << " " << " " << TestScoresArray[0][2] << " " << " " << TestScoresArray[0][3] << " " << " " << TestScoresArray[0][4] << endl;
    cout << TestScoresArray[5][0] << " " << TestScoresArray[5][1] << " " << " " << TestScoresArray[5][2] << " " << " " << TestScoresArray[5][3] << " " << " " << TestScoresArray[5][4] << endl;


    return 0;
}


