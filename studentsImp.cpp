#include<iostream>
#include<fstream>
#include<iomanip>
#include "./headers/Students.h"
using namespace std;

void CStudent::setStudentData() {
   cout << "student ID: ";
   cin >> student_id;
   cout << "student name: ";
   cin.ignore();
   cin.getline(name, 50);

   cout << "\nAll marks should be out of 100";
   cout << "\nEnter marks in English: ";
   cin >> engGrade;

   cout << "\nEnter marks in Math:  ";
   cin >> mathGrade;

   cout << "\nEnter marks in Science:  ";
   cin >> sciGrade;

   cout << "\nEnter marks in 2nd language:  ";
   cin >> lang2Grade;

   cout << "\nEnter marks in Computer science:  ";
   cin >> csGrade;

   calcGrade();
}

void CStudent::calcGrade() {
   average = (engGrade + mathGrade + sciGrade + lang2Grade + csGrade) / 5.0;
   if (average >= 90)
      grade = 'A';
   else if (average >= 80)
      grade = 'B';
   else if (average >= 70)
      grade = 'C';
   else if (average >= 60)
      grade = 'D';
   else
      grade = 'F';
}

int CStudent::getStudent_id() const {
   return student_id;
}

void CStudent::showData() const {
   cout << "\nRoll number of student : " << student_id;
   cout << "\nName of student : " << name;
   cout << "\nEnglish : " << engGrade;
   cout << "\nMaths : " << mathGrade;
   cout << "\nScience : " << sciGrade;
   cout << "\nLanguage2 : " << lang2Grade;
   cout << "\nComputer Science : " << csGrade;
   cout << "\nAverage Marks :" << average;
   cout << "\nGrade of student is :" << grade;
}