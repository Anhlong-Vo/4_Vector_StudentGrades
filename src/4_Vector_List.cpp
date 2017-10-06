//============================================================================
// Name        : 4_Vector_List.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//#include <iostream>
#include <fstream>
#include "../includes/constants.h"
#include "../includes/utilities.h"

using namespace std;

int main() {
	ifstream myInFile;

	//open file
	myInFile.open(ALL_FILE.c_str());
	if (!myInFile.is_open())
		return COULD_NOT_OPEN_FILE;

	//read file into vector, calculate final grade
	if (!readFileIntoVector(myInFile))
		return COULD_NOT_READ_FILE_INTO_VECTOR;

	//close file
	if (myInFile.is_open())
		myInFile.close();

	//calculate final grade
	calculateFinalGrade();

	//strip out failing students and add to fail.txt
	extractFailingStudents();

	//save failing students to other file
	if (!writeDataToFile(PASS,PASS_FILE))
		return COULD_NOT_WRITE_VECTOR_TO_FILE;

	if (!writeDataToFile(FAIL,FAIL_FILE))
		return COULD_NOT_WRITE_VECTOR_TO_FILE;

	return SUCCESS;
}


