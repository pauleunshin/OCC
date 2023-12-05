/*
	Shin, Robin

	Project: Grade Report
	CS A250
	Fall 2023

	Course Source-Code File
*/

#include "Course.h"
#include <iostream>
using namespace std;

//Mutators
//Sets values for member variables of Course
void Course::setCourseInfo(const string& cPrefix, int cNumber, int cUnits)
{
	coursePrefix = cPrefix;
	courseNumber = cNumber;
	courseUnits = cUnits;
}

//Accessors
//Returns member variable coursePrefix
string Course::getCoursePrefix() const
{
	return coursePrefix;
}

//Returns member variable courseNumber
int Course::getCourseNumber() const
{
	return courseNumber;
}

//Returns member variable courseUnits
int Course::getCourseUnits() const
{
	return courseUnits;
}

//Operators
bool Course::operator<(const Course& othercourse) const
{
	if (coursePrefix == othercourse.coursePrefix)
	{
		return courseNumber < othercourse.courseNumber;
	}
	else
	{
		return (coursePrefix < othercourse.coursePrefix);
	}
}
