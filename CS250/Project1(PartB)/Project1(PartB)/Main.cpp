/*
	Shin, Robin

	Project: Grade Report
	CS A250
	Fall 2023

	Main File
*/

#include "StudentList.h"
#include "InputHandler.h"
#include "OutputHandler.h"

#include <iostream>
#include <fstream>
#include <limits>

using namespace std;
const string STUDENTDATA ("student_data.txt");

void displayMenu();
void processChoice(StudentList& newList, const double tuitionRate);

int main()
{
	StudentList newStudents;
	double tuitionRate = 0.0;
	readStudentData(STUDENTDATA, newStudents, tuitionRate);
	processChoice(newStudents, tuitionRate);
	return 0;
}

void displayMenu() 
{
	cout << "*** MAIN MENU ***\n\n";
	cout << "Select one of the following: \n\n";
	cout << "    1: Print all students\n";
	cout << "    2: Print student information\n";
	cout << "    3: Search student by last name\n";
	cout << "    4: Print students by course\n";
	cout << "    5: Print students on hold\n";
	cout << "    6: Print students to file\n";
	cout << "    7: Add new course to student\n";
	cout << "    8: To exit\n\n";
}

void processChoice(StudentList& newList, const double tuitionRate)
{
	bool shutdown = false;
	while (!shutdown)
	{
		int choice;
		bool failure;
		failure = false;
		displayMenu();

		cout << "Enter your choice: ";
		cin >> choice;
		cout << endl;
		switch (choice)
			{
			case 1:
			{
				newList.printAllStudents(tuitionRate);
				system("Pause");
				break;
			}
			case 2:
			{
				int searchID;

				cout << "Please enter student's ID: ";
				cin >> searchID;
				while (cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Only numerical ID's accepted\n";
					failure = true;
				}
				cout << endl;

				if (!failure) newList.printStudentByID(searchID, tuitionRate);
				system("Pause");
				break;
			}
			case 3:
			{
				string lastName;
				cout << "Please enter the student's last name: ";
				cin >> lastName;
				cout << endl;
				newList.printStudentByName(lastName);
				system("Pause");
				break;
			}
			case 4:
			{
				string cPrefix;
				int cNumber;

				cout << "Please enter the course prefix: ";
				cin >> cPrefix;
				cout << "Please enter the course number: ";
				cin >> cNumber;
				while (cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Please enter a number for the course number.\n";
					failure = true;
				}
				cout << endl;

				if (!failure) newList.printStudentsByCourse(cPrefix, cNumber);
				system("Pause");
				break;
			}
			case 5:
			{
				newList.printStudentsOnHold(tuitionRate);
				system("Pause");
				break;
			}
			case 6:
			{
				printAllStudentsToFile(newList, tuitionRate);
				cout << endl;
				system("Pause");
				break;
			}
			case 7:
			{
				int studentID;

				cout << "Please enter a six digit student ID: ";
				cin >> studentID;
				while (cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Only numerical ID's accepted.\n\n";
					failure = true; 
				}

				if (!failure)
				{
					Node* studentNode;
					studentNode = newList.getStudent(studentID);

					if (studentNode != nullptr)
					{
						newList.addCourseToStudent(studentNode, tuitionRate);
					}
				}
				system("Pause");
				break;
			}
			case 8:
			{
				cout << "Thank you for using the OCC Gradebook. Good-Bye!\n\n";
				shutdown = true;
				system("Pause");
				exit(1);
			}
			default:
			{
				while (cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Please enter a number between 1 and 8.\n";
				}
				cout << "Sorry. That is not a selection.\n\n";
				cin.clear();
				system("Pause");
			}
		}
	}
}
	
