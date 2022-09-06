//
//  roster.cpp
//  C867_Task1
//
//  Created by Meenan on 7/27/22.
//

#include "roster.hpp"

//Default constructor
Roster::Roster() {
    //Loop through classRosterArray to free memory allocated using new
    for (i = 0; i < numStudents; ++i) {
        if (classRosterArray[i] != nullptr) {
            delete classRosterArray[i];
        }
    }
}

Roster::Roster(int numStudent){
    this->numStudent = numStudent;
    this->index = 0;
    
    //Loop to create student objects for each instance of classRosterArray pointer
    for (i = 0; i < numStudent; ++i) {
    classRosterArray[i] = new Student();
    }
}

//Destructor
Roster::~Roster() {}

 //Add informtaion to Student object
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2,int daysInCourse3, DegreeProgram degreeprogram) {
    
     //Creates temporary array for days in course 1, 2, 3
    int daysInCourse[] {daysInCourse1, daysInCourse2, daysInCourse3};
    
    //classRosterArray[index] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeprogram);
     classRosterArray[index]->setStudentID(studentID);
     classRosterArray[index]->setStudentFirstName(firstName);
     classRosterArray[index]->setStudentLastName(lastName);
     classRosterArray[index]->setStudentEmail(emailAddress);
     classRosterArray[index]->setStudentAge(age);
     classRosterArray[index]->setStudentDays(daysInCourse);
     classRosterArray[index]->setStudentDeg(degreeprogram);
}


// Parse Data from StudentTable
void Roster::parse(const string studentInfo) {
           //If Statement to ensure parse only runs if object is available
    if (this->index < this->numStudent) {
        
            //Student ID
    size_t rhs = studentInfo.find(",");
    string studentID = studentInfo.substr(0, rhs);
    
        
    size_t lhs = rhs + 1;
           //Student First Name
    rhs = studentInfo.find(",", lhs);
    string firstName = studentInfo.substr(lhs, rhs - lhs);
   
        
    lhs = rhs + 1;
           //Student Last Name
    rhs = studentInfo.find(",", lhs);
    string lastName = studentInfo.substr(lhs, rhs - lhs);
    
        
    lhs = rhs + 1;
          //Student Email
    rhs = studentInfo.find(",", lhs);
    string emailAddress = studentInfo.substr(lhs, rhs - lhs);
    
        
    lhs = rhs + 1;
          //Student age
    rhs = studentInfo.find(",", lhs);
    int age = stoi(studentInfo.substr(lhs, rhs - lhs));
    
       
    lhs = rhs + 1;
         //Student Days in course 1
    rhs = studentInfo.find(",", lhs);
    int daysInCourse1 = stoi(studentInfo.substr(lhs, rhs - lhs));
    
    
    lhs = rhs + 1;
        //Student Days in course 2
    rhs = studentInfo.find(",", lhs);
    int daysInCourse2 = stoi(studentInfo.substr(lhs, rhs - lhs));
    
    
    lhs = rhs + 1;
        //Student Days in course 3
    rhs = studentInfo.find(",", lhs);
    int daysInCourse3 = stoi(studentInfo.substr(lhs, rhs - lhs));
    
    
    lhs = rhs + 1;
        //Student Degree Program
    rhs = studentInfo.find(",", lhs);
    string strdegree = studentInfo.substr(lhs, rhs - lhs);
        
        //Convert string to enum value
        DegreeProgram tempDeg = SOFTWARE;
        if (strdegree == "NETWORK") {
            tempDeg = NETWORK;
        }
        if (strdegree == "SECURITY") {
            tempDeg = SECURITY;
        }
        // Call Roster::add to pass parsed information to Student Object
        Roster::add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, tempDeg);
}
    ++index;
}




//Remove student based on ID, if student ID does not exist outputs error message
void Roster::remove(string ID){
    for (int i = 0; i < numStudents; ++i) {
        if (classRosterArray[i] == nullptr) {
            cout << "Student with ID: " << ID << " was not found" << endl;
        }
        else if (classRosterArray[i]->getStudentID() == ID) {
            classRosterArray[i] = nullptr;
            cout << "Student with ID: " << ID << " removed" << endl;
            }
        }
}

//Calculate and Print average day in a course for student ID
void Roster::printAverageDaysInCourse(string studentID){
    for (i = 0; i < numStudents; ++i) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
    int daysAvg = (classRosterArray[i]->getStudentDays()[0] + classRosterArray[i]->getStudentDays()[1] + classRosterArray[i]->getStudentDays()[2]) / 3;
    cout << "Average days in course for Student ID: " << studentID << " is " << daysAvg << endl;
        }
      }
}


//Print all invalid emails, must contain @ and ., should not contain space
void Roster::printInvalidEmails(){
    char validEmail;
    for ( i = 0; i < numStudents; ++i) {
        if (classRosterArray[i] != nullptr) {
    validEmail = classRosterArray[i]->getStudentEmail().find('@');
    if (validEmail == string::npos){
        cout << classRosterArray[i]->getStudentEmail() <<" is not a valid email, no @ symbol found" << endl;
    };
    validEmail = classRosterArray[i]->getStudentEmail().find(' ');
    if (validEmail != string::npos){
        cout << classRosterArray[i]->getStudentEmail() <<" is not a valid email, space found" << endl;
    };
    validEmail = classRosterArray[i]->getStudentEmail().find('.');
    if (validEmail == string::npos){
        cout << classRosterArray[i]->getStudentEmail() <<" is not a valid email, no . provided" << endl;
    };
        }
    }
};

//Print all students matching degree type
void Roster::printByDegreeProgram(DegreeProgram degree){
    for (i = 0; i < numStudents; ++i) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentDeg() == degree) {
            cout << classRosterArray[i]->getStudentID() << "\t" << classRosterArray[i]->getStudentFirstName() << "\t" << classRosterArray[i]->getStudentLastName() << "\t" << "\t" << classRosterArray[i]->getStudentAge() << "\t" << classRosterArray[i]->getStudentDays()[0]  << "\t" << classRosterArray[i]->getStudentDays()[1] << "\t" << classRosterArray[i]->getStudentDays()[2] << "\t" << DegreeProgramstr[classRosterArray[i]->getStudentDeg()] << endl;
        }
    }
}

//Print all student information
void Roster::PrintAll() {
    for (i = 0; i < numStudents; ++i) {
        if (classRosterArray[i] != nullptr) {
        classRosterArray[i]->printStudent();
        }
    }
}



















