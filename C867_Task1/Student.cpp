//
//  Student.cpp
//  C867_Task1
//
//  Created by Meenan on 7/20/22.
//
//#include <iostream>
#include "Student.hpp"

//using namespace std;



// Define student Class Constructor

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int daysToDegree[], DegreeProgram degree){}

Student::Student(){
    studentID = "none";
    firstName = "none";
    lastName = "none";
    emailAddress = "none";
    studentAge = -1;
    daysToDegreePtr = new int[3];
    for (int i = 0; i < 3; ++i){ daysToDegreePtr[i] = i; } //Creating default daysToDegreePtr array
    degree = SOFTWARE;
    
}

//Destructor
Student::~Student() {}
   



//Define Mutators
void Student::setStudentID(string studentID){
    this->studentID = studentID;
}

void Student::setStudentFirstName(string firstName){
    this->firstName = firstName;
}

void Student::setStudentLastName(string lastName){
    this->lastName = lastName;
}

void Student::setStudentEmail(string emailAddress){
    this->emailAddress = emailAddress;
}

void Student::setStudentAge(int studentAge){
    this->studentAge = studentAge;
}

void Student::setStudentDays(int daysToDeg[]){
    //Decalring new daysToDegreePtr array
    this->daysToDegreePtr = new int[3];
    //loop to point array to data
    for (int i = 0; i < 3; ++i){
      this->daysToDegreePtr[i] = daysToDeg[i];
    }
}

void Student::setStudentDeg(DegreeProgram degree){
    this->degree = degree;
}


//Define Accessors
string Student::getStudentID() const{
    return studentID;
}

string Student::getStudentFirstName() const{
    return firstName;
}

string Student::getStudentLastName() const{
    return lastName;
}

string Student::getStudentEmail() const{
    return emailAddress;
    }

int Student::getStudentAge() const{
    return studentAge;
}

int* Student::getStudentDays() const{
    return  daysToDegreePtr;
}

DegreeProgram Student::getStudentDeg() const{
    return degree;
}

//Print all student information
void Student::printStudent() const{
    cout << getStudentID() << "\tFirst Name: " << getStudentFirstName() << "\tLast Name: " <<  getStudentLastName() << "\tAge: " << getStudentAge() << "\t daysInCourse: " << getStudentDays()[0]  << "\t" << getStudentDays()[1] << "\t" << getStudentDays()[2] << "\tDegree Program: " << DegreeProgramstr[getStudentDeg()] << endl;
    
}


    




