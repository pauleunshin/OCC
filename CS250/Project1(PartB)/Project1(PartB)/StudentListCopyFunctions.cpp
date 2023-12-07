/*
	Shin, Robin

	Project: Grade Report
	CS A250
	Fall 2023

	StudentListCopy Functions Source-Code File
*/

#include "StudentList.h"

#include <iostream>

using namespace std;

//Copy Constructor
StudentList::StudentList(const StudentList& otherList) : StudentList()
{
	count = otherList.count;
	first = otherList.first;
	last = otherList.last; 
}

//Copy assignment operator
StudentList& StudentList::operator=(const StudentList& otherList)
{
	if (this == &otherList)
	{
		cerr << "Attempted assignment to itself.\n";
	}
	else
	{
		if (otherList.count == 0) clearStudentList();
		else if (count == 0)
			copyCallingObjIsEmpty(otherList);
		else if (count = otherList.count)
			copyObjectsSameLength(otherList);
		else if (count > otherList.count)
			copyCallingObjLonger(otherList);
		else if (count < otherList.count)
			copyCallingObjShorter(otherList);
	}
	return *this;
}

//Creates nodes to copy Parameter Object of larger size
void StudentList::copyCallingObjIsEmpty(const StudentList& otherList)
{
	count = otherList.count;
	Node* current = otherList.first;
	while (current != nullptr)
	{
		addStudent(current->getStudent());
		current = current->getNext();
	}
}

//Copies Paramater Object of same size
void StudentList::copyObjectsSameLength(const StudentList& otherList)
{
	Node* current = otherList.first;
	Node* temp = first;
	while (current != nullptr)
	{
		temp->setStudent(current->getStudent());
		temp = temp->getNext();
		current = current->getNext();
	}
}

//Creates nodes to copy Parameter Object of larger size
void StudentList::copyCallingObjLonger(const StudentList& otherList)
{
	count = otherList.count;
	Node* current = otherList.first;
	Node* temp = first;
	while (current->getNext() != nullptr)
	{
		temp->setStudent(current->getStudent());
		temp = temp->getNext();
		current = current->getNext();
	}
	temp->setStudent(current->getStudent());
	last = temp;
	temp = temp->getNext();
	last->setNext(nullptr);
	while (temp != nullptr)
	{
		Node* tempDel = temp->getNext();
		delete temp;
		temp = tempDel;
	}
}

//Deletes nodes to copy Parameter Object of smaller size
void StudentList::copyCallingObjShorter(const StudentList& otherList)
{
	count = otherList.count;
	Node* current = otherList.first;
	Node* temp = first;
	while (temp != nullptr)
	{
		temp->setStudent(current->getStudent());
		temp = temp->getNext();
		current = current->getNext();
	}
	while (current != nullptr)
	{
		addStudent(current->getStudent());
		current = current->getNext();
	}
}

