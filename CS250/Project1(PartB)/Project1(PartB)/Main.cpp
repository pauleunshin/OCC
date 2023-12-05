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
#include "InputHandler.h"
#include "OutputHandler.h"

#include <iostream>
#include <fstream>

using namespace std;
const string studentData ("student_data.txt");

int main()
{
	StudentList newStudents;
	double tuitionRate = 25.0;
	readStudentData(studentData, newStudents, tuitionRate);
	//newStudents.printAllStudents(tuitionRate);
	printAllStudentsToFile(newStudents, tuitionRate);
	//fix the tuition before turning in
	return 0;
}
	
