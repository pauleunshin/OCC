/*
	Shin, Robin

	Project: Grade Report
	CS A250
	Fall 2023

	StudentList Header File
*/

#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include "Course.h"
#include "Student.h"

class Node
{
public:
	Node() : student(), next(nullptr) {}
	Node(Student newStudent, Node* newNext)
		: student(newStudent), next(newNext) {}
	Node* getNext() const { return next; }
	Student getStudent() const { return student; }
	void setStudent(Student newStudent) { student = newStudent; }
	void setNext(Node* newNext) { next = newNext; }
	~Node() {}

	Node* next;
	Student student;
};

class StudentList
{
public:
	//Constructors
	//Default Constructor
	StudentList() : count(0), first(nullptr), last(nullptr) {}

	//Copy Constructor
	StudentList(const StudentList& otherList); 

	////Copy Assignment Operator
	StudentList& operator=(const StudentList& otherList);

	//Mutators
	//Add a student to the linked list 
	void addStudent(const Student& newStudent); 

	//Accessors
	//Return how many students are in the list
	int getNoOfStudents() const;

	//Print Statements
	//Prints the info of a student in the list
	void printStudentByID(int searchID, double tuitionRate) const;

	//Prints the info of a student by their name
	void printStudentByName(const std::string& searchLastName) const;

	//Prints the info of students enrolled in a course
	void printStudentsByCourse(const std::string& searchCourse,
		int searchCourseNum) const;

	//Prints the info of all students in linked list
	void printAllStudents(double tuitionRate) const;

	//Prints students to file
	void printStudentsToFile(std::ostream& outputFile, double tuitionRate) const;

	//Print students on Hold
	void printStudentsOnHold(double tuitionRate) const;

	//Removes all students in the list
	void clearStudentList();

	//Destructor
	~StudentList();

private:
	int count; 
	Node* first;
	Node* last;

	//Creates nodes to copy Parameter Object of larger size
	void copyCallingObjIsEmpty(const StudentList& otherList);

	//Copies Paramater Object of same size
	void copyObjectsSameLength(const StudentList& otherList);

	//Creates nodes to copy Parameter Object of larger size
	void copyCallingObjLonger(const StudentList& otherList);

	//Deletes nodes to copy Parameter Object of smaller size
	void copyCallingObjShorter(const StudentList& otherList);

};

#endif