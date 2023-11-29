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
	Node* newS = new Node(newStudent);

	if (first == nullptr)
	{
		first = newS;
		last = newS;
	}
	else
	{
		last->next = newS;
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
void StudentList::printStudentInfo(int searchID, double tuitionrate) const
{
	Node* current = first;
	bool found = false; 

	while (current != nullptr && !found)
	{
		if (searchID == current->student.getID())
		{
			current->student.printStudent();
			found = true;
		}
		current = current->next;
	}
}

//Prints the info of a student by their name
void StudentList::printStudentsByName(string searchLastName) const
{
	Node* current = first;
	bool found = false;

	while (current != nullptr && !found)
	{
		if (searchLastName == current->student.getLastName())
		{
			current->student.printStudent();
			found = true;
		}
		current = current->next;
	}
}

//Prints the info of students enrolled in a course
void StudentList::printStudentByCourse(string searchCourse, int searchCourseNum) const
{
	Node* current = first;
	bool found = false;

	cout << "Students enrolled in: " << searchCourse << searchCourseNum << ": \n";
	while (current != nullptr)
	{
		if (current->student.isCourseCompleted(searchCourse, searchCourseNum))
		{
			current->student.printStudent();
			found = true; 
		}
		current = current->next;
	}

	if (!found)
	{
		cout << "No students enrolled in " << searchCourse << " " << searchCourseNum << endl;
	}
	cout << endl;
}

//Prints the info of all students in linked list
void StudentList::printAllStudents(double tuitionRate) const
{
	Node* current = first;
	
	while (current != nullptr)
	{
		current->student.printStudentInfo(tuitionRate);
		current = current->next;
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
		current = current->next;
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