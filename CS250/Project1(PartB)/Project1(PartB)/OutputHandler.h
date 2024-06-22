/*
	Shin, Robin

	Project: Grade Report
	CS A250
	Fall 2023

	Output Handler Header File
*/
#ifndef OUTPUTHANDLER_H
#define OUTPUTHANDLER_H

#include "StudentList.h"

void printAllStudentsToFile(
	const StudentList& studentList, double tuitionRate);

#endif