/*
	Shin, Robin

	Project: Grade Report
	CS A250
	Fall 2023

	StudentList Source-Code File
*/

#include "Course.h"
#include "Student.h"
#include "StudentList.h"

#include <iostream>
#include <fstream>

using namespace std;

//Mutators
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

//Accessors
//Return how many students are in the list
int StudentList::getNoOfStudents() const
{
	return count; 
}


//Print Statements
//Prints the info of a student in the list
void StudentList::printStudentByID(int searchID, double tuitionRate) const
{
	Node* current = first;
	bool found = false;

	while (current != nullptr && !found)
	{
		if (searchID == current->getStudent().getID())
		{
			current->getStudent().printStudentInfo(tuitionRate);
			found = true;
		}
		current = current->getNext();
	}

	if (!found)
	{
		cout << "No students with ID " << searchID << " found in the list.\n";
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
		cout << "No student with last name " << searchLastName << " is on the list.\n";
	}
	cout << endl; 
}
//Prints the info of students enrolled in a course
void StudentList::printStudentsByCourse(const string& searchCourse, 
	int searchCourseNum) const
{
	Node* current = first;
	bool found = false;
	while (current != nullptr)
	{
		if (current->getStudent().isCourseCompleted(searchCourse,
			searchCourseNum))
		{
			current->getStudent().printStudent();
			found = true;
		}
		current = current->getNext();
	}

	if (!found)
	{
		cout << "No students enrolled in " << searchCourse << " " 
			<< searchCourseNum << endl;
	}
	cout << endl;
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
//Prints to specified teext file with tuitionRate
void StudentList::printStudentsToFile(ostream& outputFile, double tuitionRate) const
{
	Node* current = first;

	while (current != nullptr)
	{
		Student studentData = current->getStudent();
		outputFile << "Student Name: " << studentData.getLastName() 
			<< ", " << studentData.getFirstName() << endl;
		outputFile << "Student ID: " << studentData.getID() << endl;
		outputFile << "Number of Courses completed: " 
			<< studentData.getNumberOfCourses() << endl;
		outputFile << endl;
		outputFile << "CourseNo  Units  Grade\n";

		for (auto iter : studentData.getCoursesCompleted())
		{
			outputFile << iter.first.getCoursePrefix() << " "
				<< iter.first.getCourseNumber() << "    "
				<< iter.first.getCourseUnits() << "     " << iter.second 
				<< endl;
		}

		outputFile << endl;
		outputFile << "Total number of credit hours: " 
			<< studentData.getUnitsCompleted() << endl;

		if (studentData.isTuitionPaid())
		{
			outputFile.precision(2);
			outputFile << "Current Term GPA: " << fixed
				<< studentData.calculateGPA() << endl;
		}
		else
		{
			outputFile.precision(2);
			outputFile << "*** Grades are being held for not paying the tuition. ***\n";
			outputFile << "Amount Due: $" << fixed << studentData.billingAmount(tuitionRate);
			outputFile << endl;
		}

		outputFile << endl;

		for (int i = 0; i < 24; i++)
		{
			outputFile << "-*";
		}

		outputFile << "-" << endl;
		outputFile << endl;
		current = current->getNext();
	}
}
//Print students on Hold
void StudentList::printStudentsOnHold(double tuitionRate) const
{
	Node* current = first;
	bool found = false;
	
	while (current != nullptr)
	{
		Student studentData = current->getStudent();
		if (!studentData.isTuitionPaid())
		{
			studentData.printStudent();
			cout.precision(2);
			cout << "    Amount Due: $" << fixed << tuitionRate * studentData.getUnitsCompleted();
			cout << endl;
			found = true;
		}
		current = current->getNext();
	}

	if (!found)
	{
		cout << "There are no students on hold.\n";
	}
	cout << endl;
}

//Boolean Statements
//Checks if student is in current studentlist
bool StudentList::searchID(Node* finder) const
{
	finder = first;
	bool found = false;
	int studentID;
	string fName;
	string lName;

	cout << "Please enter the six digit student ID: ";
	cin >> studentID;

	while (finder != nullptr && !found)
	{
		if (studentID == finder->getStudent().getID())
		{
			cout << "Please enter the last name: ";
			cin >> lName;
			cout << "Please enter the first anem: ";
			cin >> fName;
			if (lName == finder->getStudent().getLastName() &&
				fName == finder->getStudent().getFirstName())
			{
				return true;
			}
			else
			{
				cout << "Incorrect name. Please try again";
				return false;
			}
		}
		finder = finder->getNext();
	}
	if (!found)
	{
		cout << "No students with ID " << studentID << " found in the list.\n";
		return false;
	}
}

//Removes all students in the list
void StudentList::clearStudentList()
{
	Node* current = first;
	while (current != nullptr)
	{
		Node* temp = current;
		current = current->getNext();
		delete temp;
	}

	first = nullptr;
	last = nullptr;
	count = 0;
}

//Destructor call
StudentList::~StudentList()
{
	clearStudentList();
}
