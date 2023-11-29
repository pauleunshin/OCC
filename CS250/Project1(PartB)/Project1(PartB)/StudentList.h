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
#include "Course.h"
#include "Student.h"


class Node 
{
public:
	Student student;
	Node* next;

	Node(const Student& newStudent, Node* newNode = nullptr) : 
		student(newStudent), next(newNode) {}
};

class StudentList
{
public:
	//Default Constructor
	StudentList();

	//Add a student to the linked list 
	void addStudent(const Student& newStudent); 

	//Return how many students are in the list
	int getNoOfStudents() const;

	//Prints the info of a student in the list
	void printStudentInfo(int searchID, double tuitionRate) const;

	//Prints the info of a student by their name
	void printStudentsByName(std::string searchLastName) const;

	//Prints the info of students enrolled in a course
	void printStudentByCourse(std::string searchCourse, int searchCourseNum) const;

	//Prints the info of all students in linked list
	void printAllStudents(double tuitionRate) const;

	//Removes all students in the list
	void clearStudentList();

	//Destructor
	~StudentList();

private:
	int count; 
	Node* first;
	Node* last; 
	
};

#endif