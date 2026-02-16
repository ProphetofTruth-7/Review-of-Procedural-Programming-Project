// Grade Book Branch

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

const int TOTAL_SCORES = 5;
const int MAX_STUDENTS = 35;


int studentDataRetrieval(ifstream& x, string student[], double scores[MAX_STUDENTS][TOTAL_SCORES]) {
    int counter = 0, i = 0;

    while (counter < MAX_STUDENTS && x >> student[counter]) {
        for (int i = 0; i < TOTAL_SCORES; i++) {
            x >> scores[counter][i];
        }
        ++counter;
    }
    return counter;
}
void calcArrayAverage(double scores[MAX_STUDENTS][TOTAL_SCORES], double average[MAX_STUDENTS], int size) {
    int counter = 0, counter2 = 0;

    do {
        double sum = 0;
        do {
            sum += scores[counter][counter2++];
        } while (counter2 < TOTAL_SCORES);
        average[counter] = sum/TOTAL_SCORES;
        ++counter;
        counter2 = 0;
    } while (counter < size);
}
char gradeCalc(double average[MAX_STUDENTS], int current) {
        if (average[current] > 89.9) {
            return 'A';
        }
        else if (average[current] > 79.9) {
            return 'B';
        }
        else if (average[current] > 69.9) {
            return 'C';
        }
        else if (average[current] > 59.9) {
            return 'D';
        }
        else {
            return 'F';
        }
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
    double TestScoresArray[MAX_STUDENTS][TOTAL_SCORES]; //Filled Array. 5 Rows for 5 Students, TOTALSCORES Columns for number of TestScores
    double AverageScoreArray[MAX_STUDENTS]; //Filled Array. Empty for now, 5 spots for 5 students.
    int currentSize = studentDataRetrieval(GRADEFILE, StudentNameArray, TestScoresArray);

    calcArrayAverage(TestScoresArray, AverageScoreArray, currentSize);

    int currentStudent = 0;

    cout << "Student Name" << setw(15) << "Average Score" << setw(15) << "Letter Grade" << endl;

    for (int currentStudent = 0; currentStudent < currentSize; currentStudent++) {
        cout << StudentNameArray[currentStudent] << setw(15) << AverageScoreArray[currentStudent] << setw(15) << gradeCalc(AverageScoreArray, currentStudent) << endl;
    }

    return 0;
}


