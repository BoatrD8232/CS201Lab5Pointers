// CS201L-Lab5-Pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "functions.h"

int main()
{
    int gradeTotals[5] = {0};
    float classAvg = 0;
    cout << "CS201l-LAB5: GRADING PROGRAM USING POINTERS\n";
    vector<studentInfo*> students;
    setStudentInfo(students, gradeTotals, classAvg);
    printVector(students, gradeTotals, classAvg);
}
 
