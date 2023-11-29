/*
	Shin, Robin

	Project: Grade Report
	CS A250
	Fall 2023

	Student Header File
*/

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <map>
#include "Course.h"

class Student
{
public:
	//Default Constructor
	Student();

	//Initializer List Constructor
	Student(int ID, std::string fName, std::string lName, int coursesTaken,	bool tuition);

	//Copies Student Data from Paramter object
	void setStudent(const Student& otherStudent);

	//Sets values for member variables of Student Object
	void setStudentInfo(int newID, std::string newFirst, std::string newLast,
		bool paidtuition, std::multimap<Course, char> coursesTaken);

	//Returns student ID
	int getID() const;

	//Returns student's first name
	std::string getFirstName() const;

	//Returns student's last name
	std::string getLastName() const;

	//Returns student's full name
	void getName(std::string& newFirst, std::string& newLast) const;

	//Returns how many courses the student completed
	int getNumberOfCourses() const;

	//Returns how many units the student completed
	int getNumberOfUnits() const;

	//Returns a multimap of all courses the student has completed with letter grades
	std::multimap<Course,char> getCoursesCompleted() const;

	//Returns True/False whether the student has paid their tuition
	bool isTuitionPaid() const;

	//Checks if a student has taken/completed the paramter course and returns true/false
	bool isCourseCompleted(std::string prefix, int cnumber) const;

	//Calculates the current GPA of the student and returns it as a double
	double calculateGPA() const;

	//Calculates how much the total cost of all courses taken would be
	double billingAmount(double tuitionrate);

	//Prints the student's ID and Name
	void printStudent() const;

	//Prints the student's ID, name, # of completed courses, courses taken w/grades, GPA and hours
	void printStudentInfo(double tuitionrate) const;

	//Destructor
	~Student() {}


private:
	int studentID;
	std::string firstName;
	std::string lastName;
	int numberOfCourses;
	bool tuitionWasPaid;
	std::multimap<Course, char> coursesCompleted;

};

#endif