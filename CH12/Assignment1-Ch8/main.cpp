//Assignment 2 - Chapter 13 Programming Excercise 20
//Code borrowed from Assignment 1 - Chapter 8 Programming Excercise 13
//Written by Luis Torres

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int NUM_OF_STUDENTS = 10;
const int NUM_OF_TESTS = 5;

void sortData(string list[], int length, double tests[][NUM_OF_TESTS]);
//function to sort students' names and data.

void gatherData(ifstream& inFile);
//function to read and store data into two arrays

void calculateAverage(double testScores[], double *average);
//function to calculate the average test score

void calculateGrade(int score, char grade);
//function to calculate the letter grade

void outputResult(ofstream& outFile);
//function to output the results

string names[NUM_OF_STUDENTS];
double scores[NUM_OF_STUDENTS][NUM_OF_TESTS];
char grades[NUM_OF_STUDENTS];

int main() {
  ifstream studentsData; //declaring an input file stream variable
  ofstream studentsGrades; //declaring an output fies stream variable

  cout << "Opening file...\n";
  studentsData.open("Chp8_Ex13Data"); //opens the input file

  if (!studentsData) {
    cout << "Cannot open the inuput file... Exiting program" << endl;
    return 1;
  }

  cout << "Gathering storing Data...\n";
  gatherData(studentsData);

  cout << "Opening the output file...\n";
  studentsGrades.open("Chp8_Ex13Data.out"); //opens the output file

  cout << "Calculating grades...\n";
  outputResult(studentsGrades);

  cout << "Writing to output file...\nDone.\n";
  studentsData.close();
  studentsGrades.close();

  return 0;
}

//This function parses through the input file and adds each student
//to the string array. It also adds each students' scores to the
//two-dimensional array.
void gatherData(ifstream& inFile) {
  string name;
  double test;
  //Format of text file must be 'name' 'test1' 'test2' 'test3' ...
  for (size_t n = 0; n < NUM_OF_STUDENTS; n++) {
    inFile >> name;
    names[n] = name;
    for (size_t t = 0; t < NUM_OF_TESTS; t++) {
      inFile >> test;
      scores[n][t] = test;
    }
  }
}

//This function calculates the average by looking through each students scores
//from the double array and then assigning the calculated score to the
//pointer called average.
void calculateAverage(double testScores[], double *average) {
  double sum = 0.0;
  for (size_t i = 0; i < NUM_OF_TESTS; i++) {
    sum += testScores[i];
  }
  double avg = sum / NUM_OF_TESTS;
  *average = avg;
}

//This function calculates the grade of an individual student by taking in
//the average score and then going through a switch case to determine which
//grade to assign the student. It then assigns the grade to a pointer char
//called grade.
void calculateGrade(int avgScore, char *grade) {
  switch (avgScore / 10) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      *grade = 'F';
      break;
    case 6:
      *grade = 'D';
      break;
    case 7:
      *grade = 'C';
      break;
    case 8:
      *grade = 'B';
      break;
    case 9:
    case 10:
      *grade = 'A';
      break;
    default:
      cout << "Invalid test score." << endl;
  }
}

//This function takes in the output file and writes the student's names,
//each score, their average, their grade, and the class average.
void outputResult(ofstream& outFile) {
  double avgScore;
  char grade;
  double classAverage = 0;

  outFile << fixed << showpoint << setprecision(2);

  outFile << "This file contains each students grades, their exam scores and the class average.\n\n";

  outFile << left << setw(12) << "Name ";
  for (size_t i = 0; i < NUM_OF_TESTS; i++) {
    outFile << setw(9) << "Test " + to_string(i + 1);
  }

  outFile << setw(8) << "Average ";
  outFile << setw(8) << "Grade " << endl;

  //sort the data
  sortData(names, NUM_OF_STUDENTS, scores);

  for (size_t n = 0; n < NUM_OF_STUDENTS; n++) {
    outFile << left << setw(12) << names[n] << " ";
    for (size_t t = 0; t < NUM_OF_TESTS; t++) {
      outFile << setw(8) << scores[n][t] << " ";
    }

    calculateAverage(scores[n], &avgScore);
    outFile << setw(8) << avgScore << " ";
    calculateGrade(avgScore, &grade);
    outFile << setw(8) << grade << " ";
    grades[n] = grade; //adds the student's grade to the char array.
    outFile << endl;

    classAverage += avgScore;
  }

  outFile << "\n\n";
  outFile << "Class average: " << classAverage / NUM_OF_STUDENTS << endl;
}

void sortData(string list[], int length, double tests[][NUM_OF_TESTS]) {
  //bubble sort implementation
  string temp;
  double tmp[NUM_OF_TESTS];
  for (size_t i = 1; i < length; i++) {
    for (size_t index = 0; index < length - i; index++) {
      if (list[index] > list[index + 1]) {
        temp = list[index];
        list[index] = list[index + 1];
        list[index + 1] = temp;

        //This will sort the students' test into the correct order
        for (size_t t = 0; t < NUM_OF_TESTS; t++) {
          tmp[t] = tests[index][t];
          tests[index][t] = tests[index + 1][t];
          tests[index + 1][t] = tmp[t];
        }

      }
    }
  }
}
