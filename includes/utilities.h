/*
 * utilities.h
 *
 *  Created on: Sep 17, 2013
 *      Author: lynn
 */

#ifndef UTILITIES_H_
#define UTILITIES_H_

#include <string>

const double UNINITIALIZED = -1.0;
struct studentData{
	std::string name;
	double midterm,final;
	double classgrade;
	void clear(){name.clear();midterm=final=classgrade=UNINITIALIZED;}
};

enum ranking {PASS,FAIL};

bool readFileIntoVector(std::ifstream &file );
void calculateFinalGrade();
void extractFailingStudents(double failgrade = FAILGRADE);

bool writeDataToFile(ranking r, const std::string &filename);

//if myString does not contain a string rep of number returns o
//if int not large enough has undefined behaviour, very fragile
int stringToInt(const char *myString);
std::string DoubleToString ( double Number );

#endif /* UTILITIES_H_ */
