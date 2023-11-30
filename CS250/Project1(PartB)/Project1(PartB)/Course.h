/*
	Shin, Robin

	Project: Grade Report
	CS A250
	Fall 2023

	Course Header File
*/

#ifndef COURSE_H
#define COURSE_H

#include <iostream>

class Course
{

public:
	//Default Constructor
	Course();

	//Initializer List Constructor
	Course(const std::string& prefix, int number, int units);

	//Sets values for member variables of Course
	void setCourseInfo(std::string prefix, int number, int units);

	//Returns member variable coursePrefix 
	std::string getCoursePrefix() const;

	//Returns member variable courseNumber
	int getCourseNumber() const;

	//Returns member variable courseUnits
	int getCourseUnits() const;

	//MysteryFunction
	//Its the < operator
	bool operator<(const Course& othercourse) const;

	//Destructor
	~Course() {}


private:
	std::string coursePrefix;
	int courseNumber;
	int courseUnits;

};

#endif