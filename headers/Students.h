#ifndef STUDENTS_H
#define STUDENTS_H

class CStudent {
   private:
      int student_id;
      char name[50];
      int engGrade, mathGrade, sciGrade, lang2Grade, csGrade;
      double average;
      char grade;

   public:
      CStudent() {
         engGrade = mathGrade = sciGrade = lang2Grade = csGrade = average = 0;
         grade = 'F';
      }
      void setStudentData();
      int getStudent_id() const;
      void showData() const;
      void calcGrade();
};

#endif