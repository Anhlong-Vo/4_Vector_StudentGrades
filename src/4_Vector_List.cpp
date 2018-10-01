//============================================================================
// Name        : 4_Vector_List.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include "../includes/constants.h"
#include "../includes/utilities.h"
using namespace std;

int process_Data(const std::string &infile, const std::string &Passfile, const std::string &Failfile) {
	ifstream myInFile;

	//open file
	myInFile.open(infile.c_str());
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
	
	//practice some sorting
	sortArray(NAME);
	
	//why might this one be especially useful?
	sortArray(FINAL_GRADE);

	//strip out failing students and add to fail.txt
	extractFailingStudents();

	//save failing students to other file
	if (!writeDataToFile(PASS,Passfile))
		return COULD_NOT_WRITE_VECTOR_TO_FILE;

	if (!writeDataToFile(FAIL,Failfile))
		return COULD_NOT_WRITE_VECTOR_TO_FILE;

	return SUCCESS;
}

int main() {
	string infile = ALL_FILE;
    string Passfile = PASS_FILE;
    string Failfile = FAIL_FILE;

    return process_Data(infile,Passfile, Failfile);
}

//ALTERNATIVE- pass the files as arguments
//const int FAIL_WRONG_NUMBER_ARGS = -5;
//const int EXPECTED_NUMBER_ARGUMENTS =4;
//const string WRONG_NUMB_ARGS = "This program expects 3 arguments, infile passfile failfile";

//int main( int argc, char *argv[] )  {
//	//argc = how many arguments passed in (including this program)
//	//char *argv[] char array of those arguments
//
//	//expect progname infile passfile failfile   //program and 3 arguments, argc=4
//   if( argc != EXPECTED_NUMBER_ARGUMENTS ) {
//	   cout<< WRONG_NUMB_ARGS <<endl;
//	   return FAIL_WRONG_NUMBER_ARGS;
//   }
//   string infile = argv[1];
//   string Passfile = argv[2];
//   string Failfile = argv[3];
//
//   return process_Data(infile,Passfile, Failfile);
//}



