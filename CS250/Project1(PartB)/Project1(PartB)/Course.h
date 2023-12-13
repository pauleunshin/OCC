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
	//Constructors
	//Default Constructor
	Course() : coursePrefix("N/A"),
		courseNumber(0), courseUnits(0) {}
	//Overloaded Constructor
	Course(std::string prefix, int number, int units) :
		coursePrefix(prefix), courseNumber(number), courseUnits(units) {}

	//Mutators
	//Sets values for member variables of Course
	void setCourseInfo(const std::string& prefix, int number, int units);

	//Accessors
	//Returns member variable coursePrefix 
	std::string getCoursePrefix() const;
	//Returns member variable courseNumber
	int getCourseNumber() const;
	//Returns member variable courseUnits
	int getCourseUnits() const;

	//Operators
	bool operator<(const Course& othercourse) const;

	//Destructor
	~Course() {}

private:
	std::string coursePrefix;
	int courseNumber;
	int courseUnits;

};

#endif