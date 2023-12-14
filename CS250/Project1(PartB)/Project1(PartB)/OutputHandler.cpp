#include "OutputHandler.h"

#include "Course.h"
/*
	Shin, Robin

	Project: Grade Report
	CS A250
	Fall 2023

	Output Handler Source-Code File
*/
#include "Student.h"
#include "StudentList.h"

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

void printAllStudentsToFile(
	const StudentList& studentList, double tuitionRate)
{
	//Declare stream object
	std::ofstream outfile;

	//Ask user how to name the file to write to
	std::string nameOfFile;
	std::cout << "Enter a name for a new file to write on "
		<< "(include extension.txt) : \n";
	std::cin >> nameOfFile;

	outfile.open(nameOfFile);

	if (outfile.fail())
	{
		std::cerr << "Output file opening failed.\n";
		//system("Pause");
		//exit(1);
	}
	else
	{
		outfile
			<< "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n"
			<< "            UNOFFICIAL TRANSCRIPTS\n"
			<< "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n\n";
		studentList.printStudentsToFile(outfile, tuitionRate);
	}
}