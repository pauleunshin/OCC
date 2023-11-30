/*
	Shin, Robin

	Project: Grade Report
	CS A250
	Fall 2023

	StudentList Source-Code File
*/

#include "Student.h"
#include "Course.h"
#include "StudentList.h"
#include <iostream>

using namespace std;

//Default Constructor
StudentList::StudentList() : count(0), first(nullptr), last(nullptr) {}

//Add a student to the linked list 
void StudentList::addStudent(const Student& newStudent)
{
	Node* newS = new Node(newStudent, nullptr);

	if (first == nullptr)
	{
		first = newS;
		last = newS;
	}
	else
	{
		last->setNext(newS);
		last = newS;
	}
	count++;
}

//Return how many students are in the list
int StudentList::getNoOfStudents() const
{
	return count; 
}


//Prints the info of a student in the list
void StudentList::printStudentByID(int searchID, double tuitionrate) const
{
	Node* current = first;
	bool found = false;

	while (current != nullptr && !found)
	{
		if (searchID == current->getStudent().getID())
		{
			current->getStudent().printStudentInfo(tuitionrate);
			found = true;
		}
		current = current->getNext();
	}

	if (!found)
	{
		cerr << "No students with ID " << searchID << " found in the list.\n";
	}
}

//Prints the info of a student by their name
void StudentList::printStudentByName(const string& searchLastName) const
{
	Node* current = first;
	bool found = false;

	while (current != nullptr)
	{
		if (searchLastName == current->getStudent().getLastName())
		{
			current->getStudent().printStudent();
			found = true;
		}
		current = current->getNext();
	}

	if (!found)
	{
		cerr << "No student with last name " << searchLastName << " is on the list.\n";
	}

}

//Prints the info of students enrolled in a course
void StudentList::printStudentsByCourse(const string& searchCourse, int searchCourseNum) const
{
	Node* current = first;
	bool found = false;

	while (current != nullptr)
	{
		if (current->getStudent().isCourseCompleted(searchCourse, searchCourseNum))
		{
			current->getStudent().printStudent();
			found = true;
		}
		current = current->getNext();
	}

	if (!found)
	{
		cerr << "No students enrolled in " << searchCourse << " " << searchCourseNum << endl;
	}
}


//Prints the info of all students in linked list
void StudentList::printAllStudents(double tuitionRate) const
{
	Node* current = first;

	while (current != nullptr)
	{
		current->getStudent().printStudentInfo(tuitionRate);
		current = current->getNext();
	}
}


//Removes all students in the list
void StudentList::clearStudentList()
{

	Node* current = first;
	Node* temp;

	while (current != nullptr)
	{
		temp = current;
		current = current->getNext();
		delete temp;
	}

	first = nullptr;
	last = nullptr;
	count = 0;
}

StudentList::~StudentList()
{
	clearStudentList();
}