//
//  roster.hpp
//  C867_Task1
//
//  Created by Meenan on 7/27/22.
//

#ifndef roster_hpp
#define roster_hpp
#include "Student.hpp"


//Creating Roster class
class Roster {
public:
    int index;
    int numStudent;
    int i;
    
    
    
    //Declare Constructors
    Roster();
    Roster(int numStudent);
    
    //Declare Destructor
    ~Roster();
    
    //Declare Mutators of Roster Class
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysIncourse2, int daysInCourse3, DegreeProgram degreeprogram);
    void parse(string studentInfo);
    void remove(string ID);
    
    //Declare Accessor or Roster Class
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreestr);
    void PrintAll();
    int* GetTest();
    
    //Create Pointer Array for Student Class
    Student* classRosterArray[numStudents];
    
};

#endif
