#include<iostream>
#include<fstream>
#include<ctype.h>
#include<iomanip>
#include "./headers/Students.h"
using namespace std;

// fuction prototypes
void createStudent();
void displayStudentRecord(int id);
void displayAll();
void deleteStudent(int id);
void changeStudent(int id);


// == Main ====================================================================================================================================================
int main() 
{
   //variables
   char ch;
   cout<<setprecision(2); 
   do
   {
      char ch;
      int num;
      system("cls");
      cout<<"\n\tMENU";
      cout<<"\n\t1. Create student record";
      cout<<"\n\t2. Search student record";
      cout<<"\n\t3. Display all students records ";
      cout<<"\n\t4. Delete student record";
      cout<<"\n\t5. Modify student record";
      cout<<"\n\t6. Exit";
      cout<<"\n\tPlease select option by number: ";
      cin>>ch;
      system("cls");
      switch(ch)
      {
      case '1': 
         createStudent();
         break;
      case '2': 
         cout<<"\n\n\tEnter student id: "; 
         cin>>num;
         displayStudentRecord(num); 
         break;
      case '3': 
         displayAll(); 
         break;
      case '4': 
         cout<<"\n\n\tEnter student id: "; 
         cin>>num;
         deleteStudent(num);
         break;
      case '5': 
         cout<<"\n\n\tEnter student id: "; cin>>num;
         changeStudent(num);
         break;
      case '6': 
         cout<<"Exiting, Thank you!";exit(0);
      }
   } while(ch!='6');

return 0;
}

// == end of main =============================================================================================================================================


// == createStudent ===========================================================================================================================================

void createStudent() {
   // variables
   CStudent stud;
   ofstream oFile;

   oFile.open("./studentData/students.dat",ios::binary|ios::app);
   stud.setStudentData();
   oFile.write(reinterpret_cast<char *> (&stud), sizeof(CStudent));
   oFile.close();
      cout<<"\n\nStudent record has been created, enter any key to continue ";
   cin.ignore();
   cin.get();
}

// == end of createStudent ====================================================================================================================================


// == displayStudentRecord ====================================================================================================================================

void displayStudentRecord(int id)
{
   // variable
   CStudent stud;
   ifstream iFile;
   bool flag = false;

   iFile.open("./studentData/students.dat",ios::binary);
   if (!iFile) {
      cout<<"File could not be opened... Press any Key to exit";
      cin.ignore();
      cin.get();
      return;
   }

   while(iFile.read(reinterpret_cast<char *> (&stud), sizeof(CStudent))) {
      if (stud.getStudent_id()==id) {
         stud.showData();
         cout << "\n\tEnter any key to continue";
         flag = true;
      }
   }

   iFile.close();
   if(flag == false)
      cout<<"\n\nrecord does not exist";
   cin.ignore();
   cin.get();
}

// == end of displayStudentRecord =============================================================================================================================


// == displayAll ==============================================================================================================================================

void displayAll() 
{
   CStudent student;
   ifstream inFile;
   inFile.open("./studentData/students.dat",ios::binary);
   if (!inFile) {
      cout<<"File could not be opened !! Press any Key to exit";
      cin.ignore();
      cin.get();
      return;
   }

   cout<<"\n\n\n\t\tDISPLAYING ALL RECORDS\n\n";
   while(inFile.read(reinterpret_cast<char *> (&student), sizeof(CStudent))) {
      student.showData();
      cout << endl;
   }
   cout<<"\n ============= Enter any key to continue =============";
   inFile.close();
   cin.ignore();
   cin.get();
}

// == end of displayAll =======================================================================================================================================


// == deleteStudent ===========================================================================================================================================

void deleteStudent(int id) 
{
   CStudent student;
   ifstream iFile;
   ofstream oFile;

   iFile.open("./studentData/students.dat",ios::binary);
   if (!iFile) {
      cout<<"File could not be opened... Press any Key to exit...";
      cin.ignore();
      cin.get();
      return;
   }

   oFile.open("./studentData/temp.dat",ios::out);
   iFile.seekg(0,ios::beg);
   while(iFile.read(reinterpret_cast<char *> (&student), sizeof(CStudent))) {
      if(student.getStudent_id() != id)
         oFile.write(reinterpret_cast<char *> (&student), sizeof(CStudent));
   }

   oFile.close();
   iFile.close();
   remove("./studentData/students.dat");
   rename("./studentData/temp.dat","./studentData/students.dat");
   cout<<"\n\n\tRecord Deleted... Please enter any key";
   cin.ignore();
   cin.get();
}

// == end of deleteStudent ====================================================================================================================================


// == changeStudent ===========================================================================================================================================

void changeStudent(int id)
{
   bool found=false;
   CStudent student;
   fstream file;
   file.open("./studentData/students.dat",ios::binary|ios::in|ios::out);
   if (!file) {
      cout<<"File could not be opened. Press any Key to exit...";
      cin.ignore();
      cin.get();
      return;
   }
   while (!file.eof() && found==false) {
      file.read(reinterpret_cast<char *> (&student), sizeof(CStudent));

      if (student.getStudent_id() == id) {
         student.showData();
         cout<<"\n\Enter new student details: "<<endl;

         student.setStudentData();

         int pos = (-1)*static_cast<int>(sizeof(student));
         file.seekp(pos,ios::cur);
         file.write(reinterpret_cast<char *> (&student), sizeof(student));
         cout<<"\n\n\t Record Updated";
         found=true;
      }
   }
}

// == end of changeStudent ====================================================================================================================================