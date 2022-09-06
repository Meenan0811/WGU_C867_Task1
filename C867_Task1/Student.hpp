//
//  Student.hpp
//  C867_Task1
//
//  Created by Meenan on 7/20/22.
//

#ifndef Student_hpp
#define Student_hpp
#include "degree.hpp"
#include <iostream>


//Declaring Global Variable for Number of students
const int numStudents = 5;

//Create Student Class
class Student {
public:
    //Declare Constructor
    Student(string studentID, string firstName, string lastName, string emailAdd, int studentAge,int daysToDegree[], DegreeProgram degree);
    
    //Default Constructor
    Student();
    
    //Destructor
    ~Student();
    
    //Declare Mutators
    void setStudentID (string ID);
    void setStudentFirstName(string firstName);
    void setStudentLastName(string lastName);
    void setStudentEmail(string email);
    void setStudentAge(int age);
    void setStudentDays(int daysToDegree[]);
    void setStudentDeg(DegreeProgram degree);
    
    //Declare Accessors
    string getStudentID() const;
    string getStudentFirstName() const;
    string getStudentLastName() const;
    string getStudentEmail() const;
    int getStudentAge() const;
    int* getStudentDays() const;
    DegreeProgram getStudentDeg() const;
    
    
    void printStudent() const;
    
private:
    string firstName;
    string lastName;
    string emailAddress;
    string studentID;
    string degreestr;
    DegreeProgram degree;
    int studentAge;
    int* daysToDegreePtr;
    
};

#endif /* Student_hpp */
