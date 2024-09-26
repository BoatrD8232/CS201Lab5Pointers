#include "functions.h"

bool isDigits(string str) {
	return (str.find_first_not_of("0123456789") == string::npos);
}
 
bool isValidAnswer(string str) {
	return str.find_first_not_of("ABCDE ") == str.npos;
}

void setStudentInfo(vector<studentInfo*>& vec, int tot[], float& classAvg) {
    ifstream infile;
    ofstream outfile;
    string line, key, idStr, ans, out;
    int id, scoreTot;
    float perc, classScore = 0;
    char grade;
    infile.open("student.txt");
    outfile.open("error.txt");
    if (infile.is_open()) {
        getline(infile, line);
        key = line;
        while (getline(infile, line)) {
            //cout << line.substr(0, 6) << " ";
            //cout << line.substr(7, 20) << endl;
            try {
                idStr = line.substr(0, 6);
                if (!isDigits(idStr)) {
                    throw runtime_error("Student ID");
                }
                ans = line.substr(7, 20);
                if (!isValidAnswer(ans)) {
                    throw runtime_error("Answer");
                }
            }
            catch (runtime_error& err) {
                if (outfile.is_open()) {
                    out = "";
                    out += "Error in ";
                    out += err.what();
                    out += ":";
                    outfile << setw(25) << left << out << line << '\n';
                    //outfile << "Error in "  << err.what() << setw(6) << left << ": "  << setw(30) << right <<  line << '\n';
                }
                else {
                    cout << "Error opening error file." << endl;
                }
                continue;
            }
            scoreTot = 0;
            studentInfo* temp = new studentInfo;
            temp->studentID = stoi(idStr);
            temp->answers = ans;
            // Scores the student.
            for (int i = 0; i < ans.size(); ++i) {
                if (key[i] == ans[i]) {
                    scoreTot += 2;
                }
                else if (!isspace(ans[i])) {
                    scoreTot++;
                }
            }
            temp->score = scoreTot;
            perc = (float)scoreTot / 40 * 100;
            temp->percent = perc;
            classScore += perc;
            // Chooses the student's letter grade and also increments the corresponding part of the grade array.
            if (perc >= 90) {
                temp->grade = 'A';
                tot[0] += 1;
            }
            else if (perc >= 80) {
                temp->grade = 'B';
                tot[1] += 1;
            }
            else if (perc >= 70) {
                temp->grade = 'C';
                tot[2] += 1;
            }
            else if (perc >= 60) {
                temp->grade = 'D';
                tot[3] += 1;
            }
            else {
                temp->grade = 'F';
                tot[4] += 1;
            }
            vec.push_back(temp);
        }
    }
    infile.close();
    outfile.close();
    classAvg = classScore / vec.size();
}
void printVector(const vector<studentInfo*>& vec, int tot[], float classAvg) {
    string grades = "ABCDF";
    ofstream outfile;
    outfile.open("report.txt");
    if (outfile.is_open()) {
        outfile << left << setw(10) << "STUD ID" << setw(30) << "Student Answers" << setw(15) << "Score/40" << setw(10) << "PERCENT" << setw(10) << "GRADE" << endl;
        for (int i = 0; i < vec.size(); ++i) {
            outfile << left << setw(10) << vec.at(i)->studentID << setw(30) << vec.at(i)->answers << setw(15) << vec.at(i)->score << setw(10) << vec.at(i)->percent << setw(10) << vec.at(i)->grade << endl;
        }
        outfile << "\nCLASS AVERAGE = " << fixed << setprecision(2) << classAvg << '\n' << endl;
        outfile << "Grade Totals: " << endl;
        for (int i = 0; i < 5; ++i) {
            outfile << grades[i] << setw(10) << right << tot[i] << endl;
        }
    }
    else {
        cout << "Counldn't open report file.";
    }
    outfile.close();
}