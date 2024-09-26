#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

/*
	Struct studentInfo: stores a students data, such as the ID.
*/
struct studentInfo {
	int studentID;
	string answers;
	int score; //calculate score based on requirements (see above)
	float percent; //calculate the percent out of 40
	char grade; //calculate the students grade (A-F)
};
/*
	setStudentInfo: reads in student data from a file, places it into a vector and outputs errors to a sepereate file.
	param vec: a vector of student info to be filled.
	param tot: an array containing the number of each A, B, etc.
	param classAvg: the average score of the whole class, to be calculated in this function.
*/
void setStudentInfo(vector<studentInfo*>& vec, int tot[], float& classAvg);
/*
	printVector: outpus the contents of the student info vector.
	param vec: The vector of student info.
	param tot: an array containing the number of each A, B, etc.
	param classAvg: the average of the whole class to be displayed.
*/
void printVector(const vector<studentInfo*>& vec, int tot[], float classAvg);
