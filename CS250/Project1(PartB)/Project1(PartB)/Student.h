/*
	Shin, Robin

	Project: Grade Report
	CS A250
	Fall 2023

	Student Header File
*/

#ifndef STUDENT_H
#define STUDENT_H

#include "Course.h"

#include <string>
#include <map>

class Student
{
public:
	//Constructors
	//Default Constructor
	Student() : studentID(0), firstName("N/A"), lastName("N/A"),
		numberOfCourses(0), tuitionWasPaid(false) {}

	//Mutators
	//Copies Student Data from Paramter object
	void setStudent(const Student& otherStudent);
	//Sets values for member variables of Student Object
	void setStudentInfo(int newID, const std::string& newFirst, 
		const std::string& newLast,	bool paidtuition, 
		const std::multimap<Course, char>& coursesTaken);
	//Adds a course to the student
	void addCourse(const Course& newCourse, const char& newGrade);

	//Accessors
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
	int getUnitsCompleted() const;
	//Returns a multimap of all courses 
	//the student has completed with letter grades
	std::multimap<Course,char> getCoursesCompleted();

	//Booleans
	//Returns True/False whether the student has paid their tuition
	bool isTuitionPaid() const;
	//Checks if a student has taken/completed 
	//the paramter course and returns true/false
	bool isCourseCompleted(const std::string& prefix, int cNumber) const;

	//Calculations
	//Returns Student GPA
	double calculateGPA() const;
	//Returns cost of tuition for Student
	double billingAmount(double tuitionRate) const;

	//Print Statements
	//Prints the student's ID and Name
	void printStudent() const;
	//Prints the student's ID, name, # of completed courses,
	//courses taken w/grades, GPA and hours
	void printStudentInfo(double tuitionRate) const;

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