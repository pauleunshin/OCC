/*
	Shin, Robin

	Project: Grade Report
	CS A250
	Fall 2023

	StudentListCopy Functions Source-Code File
*/


#include <iostream>
#include "StudentList.h"
using namespace std;

//Copy Constructor
StudentList::StudentList(const StudentList& otherList) : StudentList()
{
	count = otherList.count;
	first = otherList.first;
	last = otherList.last; 
}

//Copy Assignment Operator
StudentList& StudentList::operator=(const StudentList& otherList)
{
	if (this == &otherList)
	{
		cout << "Attempted assignment to self.\n";
	}
	else
	{
		if (otherList.count == 0) clearStudentList();
		else if (count == 0) 
		{
			copyCallingObjIsEmpty(otherList);
		}
	}
	return *this;
}

//Creates nodes to copy Parameter Object of larger size
StudentList& copyCallingObjIsEmpty(const StudentList& otherList);

//Copies Paramater Object of same size
StudentList& copyObjectsSameLength(const StudentList& otherList);

//Creates nodes to copy Parameter Object of larger size
StudentList& copyCallingObjLonger(const StudentList& otherList);

//Deletes nodes to copy Parameter Object of smaller size
StudentList& copyCallingObjShorter(const StudentList& otherList);

