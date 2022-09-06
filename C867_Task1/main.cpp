//
//  main.cpp
//  C867_Task1
//
//  Created by Meenan on 7/20/22.
//

#include "roster.hpp"





int main() {
    int i = 0;
    
    
    
       //Create Student Data Table
    const string studentData[numStudents] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Matthew,Meenan,mmeenan@wgu.edu,39,31,21,28,SOFTWARE"};
    
    
    
    cout << "C867 - Scripting and Programming" << endl << "Language: C++" << endl << "Student ID: 001251968" << endl << "Student Name: Matthew Meenan" << endl << endl;
    
    
   //Declaring classRoster
    Roster classRoster(numStudents);
    
    //classRoster.parseAdd(studentData[0]);
    for( i = 0; i < numStudents; ++i){
        classRoster.parse(studentData[i]);
    }
    

    
    cout << "Displaying all student data" << endl;
   classRoster.PrintAll();
    cout << endl;
    
    cout << "Displaying Invalid email addresss from student data" << endl;
    classRoster.printInvalidEmails();
    cout << endl;
    
    cout << "Displaying Average days in course for all students" << endl;
    //For loop to obtain days in course inforation from each student based on ID
    for (i = 0; i < numStudents; ++i) {
    classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
    }
    cout << endl;
    
    cout << "Displaying all students in software degree program" << endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << endl;
    
    cout << "Removing student with ID: A3" << endl;
    classRoster.remove("A3");
    cout << endl;
    cout << "Displaying all student data after removing student with ID: A3" << endl;
    classRoster.PrintAll();
    cout << endl;
    cout << "Attempting to remove student with ID: A3 again" << endl;
    classRoster.remove("A3");
    cout << endl;
  
   
    return 0;
}
