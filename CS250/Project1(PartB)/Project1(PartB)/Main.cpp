/*
	Shin, Robin

	Project: Grade Report
	CS A250
	Fall 2023

	Main File
*/


#include "Student.h"
#include "Course.h"
#include "StudentList.h"
#include <iostream>

using namespace std;

int main()
{
	//Course Testing
	Course calc1;
	calc1.setCourseInfo("CALC", 100, 3);

	Course calc2("CALC", 200, 4);

	Course mech1("ENGI", 150, 2);
	Course mech2("ENGI", 251, 4);
	Course arts1("ARTS", 100, 3);

	cout << "Calculuas1 course prefix: " << calc1.getCoursePrefix() << endl;
	cout << "Calculus2 course number: " << calc2.getCourseNumber() << endl;
	cout << "Calculus1 unit count: " << calc1.getCourseUnits() << endl;
	cout << endl; 

	//Student Testing
	
	Student student1;
	student1.setStudentInfo(101456, "Scotty", "Scott", true, { {calc1, 'A'},
		{calc2, 'C'} });
	Student student2;
	//Now Student2 is Scotty
	student2.setStudent(student1);
	student1.setStudentInfo(145699, "John", "Rodriguez", true, { {calc1, 'B'},
		{ calc2, 'B' }});
	Student student3;
	student3.setStudentInfo(777777, "Lily", "Kim" , true, { {mech1, 'B'},
		{ mech2, 'C' } });
	Student student4; 
	student4.setStudentInfo(111111, "Sheldon", "Cooper", false, { {calc1, 'A'},
		{ calc2, 'A' } , {mech1, 'B'}, { mech2, 'A' } });
	/*
	* Student 1 should be John
	* Student 2 should be Scotty
	* Student 3 should be Lily
	* Student 4 should be Sheldon
	*/
	
	cout << "Has Lily finished Calc100?: " << student3.isCourseCompleted("CALC", 100) <<endl;
	cout << "Has Sheldon paid Tuition?: " << student4.isTuitionPaid() << endl;
	cout << "How much would Sheldon pay for his tuition?: " << student4.billingAmount(400.0) << endl;
	cout << "How many units has John taken?: " << student1.getNumberOfUnits() << endl;
	cout << "How many courses has Scotty finished?: " << student2.getNumberOfCourses() << endl;
	cout << endl; 

	//StudentList Testing

	StudentList newStudents; 
	newStudents.addStudent(student1);
	newStudents.addStudent(student2);
	newStudents.addStudent(student3);
	newStudents.addStudent(student4);

	cout << "How many new Students?: " << newStudents.getNoOfStudents() << endl;
	cout << endl;
	
	cout << "Testing printStudentInfo: \n";
	newStudents.printStudentInfo(777777, 400.0);
	cout << endl;

	cout << "Printing Students by Name: \n";
	newStudents.printStudentsByName("Cooper");
	cout << endl;

	cout << "Printing Students by Course: \n";
	newStudents.printStudentByCourse("CALC", 100);
	newStudents.printStudentByCourse("ARTS", 100);
	cout << endl;

	cout << "Printing all students: \n";
	newStudents.printAllStudents(400.0);
	cout << endl;

	//Clearing StudentList; 
	newStudents.clearStudentList();
	cout << newStudents.getNoOfStudents() << endl; 

	return 0;
}
	
