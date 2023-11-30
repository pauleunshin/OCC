/*
	Shin, Robin

	Project: Grade Report
	CS A250
	Fall 2023

	Student Source-Code File
*/

#include "Student.h"
#include "Course.h"
#include <iostream>

using namespace std; 

//Default Constructor
Student::Student() : studentID(0), firstName("N/A"), lastName("N/A"),
	numberOfCourses(0), tuitionWasPaid(false) {}

Student::Student(int ID, string fName, string lName, int coursesTaken,
	bool tuition) :
		studentID(ID), firstName(fName), lastName(lName), 
		numberOfCourses(coursesTaken), tuitionWasPaid(tuition) {}

//Copies Student Data from Paramter object
void Student::setStudent(const Student& otherStudent)
{
	studentID = otherStudent.studentID;
	firstName = otherStudent.firstName;
	lastName = otherStudent.lastName;
	numberOfCourses = otherStudent.numberOfCourses;
	tuitionWasPaid = otherStudent.tuitionWasPaid;
	coursesCompleted = otherStudent.coursesCompleted;
}

//Sets values for member variables of Student Object
void Student::setStudentInfo(int newID, string newFirst, string newLast, 
	bool paidtuition, multimap<Course, char> coursesTaken)
{
	studentID = newID;
	firstName = newFirst;
	lastName = newLast;
	tuitionWasPaid = paidtuition;
	numberOfCourses = static_cast<int>(coursesTaken.size());
	coursesCompleted = coursesTaken;
}

//Returns student ID
int Student::getID() const
{
	return studentID;
}

//Returns student's first name
string Student::getFirstName() const
{
	return firstName;
}

//Returns student's last name
string Student::getLastName() const
{
	return lastName;
}

//Returns student's full name
void Student::getName(string& newFirst, string& newLast) const
{
	newFirst = firstName;
	newLast = lastName;
}

//Returns how many courses the student completed
int Student::getNumberOfCourses() const
{
	return numberOfCourses;
}

//Returns how many units the student completed
int Student::getNumberOfUnits() const
{
	int totalunits = 0;
	for (auto iter : coursesCompleted)
	{
		totalunits += iter.first.getCourseUnits();
	}
	return totalunits; 
}

//Returns a multimap of all courses the student has completed with letter grades
multimap<Course, char> Student::getCoursesCompleted() const
{
	return coursesCompleted;
}

//Returns True/False whether the student has paid their tuition
bool Student::isTuitionPaid() const
{
	return tuitionWasPaid;
}

//Checks if a student has taken/completed the paramter course and returns true/false
bool Student::isCourseCompleted(string prefix, int cnumber) const
{
	if (coursesCompleted.empty())
	{
		return false;
	}
	else
	{
		for (auto iter : coursesCompleted)
		{
			if (iter.first.getCoursePrefix() == prefix && static_cast<int>(iter.first.getCourseNumber()) == cnumber)
				return true;
		}
	}
	return false; 
}

//Calculates the current GPA of the student and returns it as a double
double Student::calculateGPA() const
{
	double points = 0.0;
	int totalunits = 0;

	for (const auto& iter : coursesCompleted)
	{
		int units = iter.first.getCourseUnits();
		totalunits += units;

		char grade = iter.second;
		switch (grade)
		{
		case 'A':
			points += 4.0 * units;
			break;
		case 'B':
			points += 3.0 * units;
			break;
		case 'C':
			points += 2.0 * units;
			break;
		case 'D':
			points += 1.0 * units;
			break;
		}

	}

	return (totalunits > 0) ? (points / totalunits) : 0.0;
}

//Calculates how much the total cost of all courses taken would be
double Student::billingAmount(double tuitionrate)
{
	return tuitionrate * static_cast<double>(coursesCompleted.size());
}

//Prints the student's ID and Name
void Student::printStudent() const
{
	cout << studentID << " - " << lastName << ", " << firstName << endl;
}

//Prints the student's ID, name, # of completed courses, courses taken w/grades, GPA and hours
void Student::printStudentInfo(double tuitionrate) const
{
	cout << "Student Name: " << lastName << ", " << firstName << endl;
	cout << "Student ID: " << studentID << endl;
	cout << "Number of Courses completed: " << numberOfCourses << endl;
	cout << endl;
	cout << "CourseNo  Units  Grade\n";
	for (auto iter : coursesCompleted)
	{
		cout << iter.first.getCoursePrefix() << " " << iter.first.getCourseNumber() << "    "
			<< iter.first.getCourseUnits() << "     " << iter.second << endl;
	}
	cout << endl;
	cout << "Total number of credit hours: " << getNumberOfUnits() << endl;
	//Add GPA HERE IDFGI IT WORKS IDRGW
	cout << "Current Term GPA: " << calculateGPA() << endl;
	for (int i = 0; i < 24; i++)
	{
		cout << "_*";
	}
	cout << "_" << endl;
	cout << endl; 
}