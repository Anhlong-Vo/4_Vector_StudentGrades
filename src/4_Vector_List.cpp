//============================================================================
// Name        : 4_Vector_List.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "utilities.h"

using namespace std;
const int 			USER_CHOSE_TO_EXIT 				= -1;
const int 			COULD_NOT_OPEN_FILE				= -2;
const int 			COULD_NOT_READ_FILE_INTO_VECTOR = -3;
const int 			SUCCESS			 				=  0;
const std::string 	ALL_FILE 						= "TestData.txt";
const std::string 	PASS_FILE 						= "Pass.txt";
const std::string 	FAIL_FILE 						= "Fail.txt";

ifstream 											myInFile;

vector<studentData> 								allstudentData;
vector<studentData> 								failstudentData;

int main() {

	//open file
	myInFile.open(ALL_FILE.c_str());
	if (!myInFile.is_open())
		return COULD_NOT_OPEN_FILE;

	//read file into vector, calculate final grade
	if (!readFileIntoVector(myInFile,allstudentData))
		return COULD_NOT_READ_FILE_INTO_VECTOR;

	//close file
	if (myInFile.is_open())
		myInFile.close();

	//calculate final grade
	calculateFinalGrade(allstudentData);

	//strip out failing students and add to fail.txt
	extractFailingStudents(allstudentData, failstudentData);

	//save failing students to other file
	writeDataToFile(PASS_FILE,allstudentData);
	writeDataToFile(FAIL_FILE,failstudentData);

}


