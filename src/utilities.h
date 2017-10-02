/*
 * utilities.h
 *
 *  Created on: Sep 17, 2013
 *      Author: lynn
 */

#ifndef UTILITIES_H_
#define UTILITIES_H_

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

const double UNINITIALIZED = -1.0;
struct studentData{
	std::string name;
	double midterm,final;
	double classgrade;
	void clear(){name.clear();midterm=final=classgrade=UNINITIALIZED;}
};

bool readFileIntoVector(std::ifstream &file, std::vector<studentData> &myData);
void calculateFinalGrade(std::vector<studentData> &myData);
void extractFailingStudents(std::vector<studentData> &allstudentData, std::vector<studentData> &failstudentData);
bool writeDataToFile(const std::string& myfilename, std::vector<studentData>& studentData);

//if myString does not contain a string rep of number returns o
//if int not large enough has undefined behaviour, very fragile
int stringToInt(const char *myString);
std::string DoubleToString ( double Number );

#endif /* UTILITIES_H_ */
