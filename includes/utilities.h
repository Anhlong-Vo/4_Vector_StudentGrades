/*
 * utilities.h
 *
 *  Created on: Sep 17, 2013
 *      Author: lynn
 */

#ifndef UTILITIES_H_
#define UTILITIES_H_

#include <string>
#include "../includes/constants.h"

const double UNINITIALIZED = -1.0;
struct studentData{
	std::string name;
	double midterm,final;
	double classgrade;
	void clear(){name.clear();midterm=final=classgrade=UNINITIALIZED;}
};

enum ranking {PASS,FAIL};
enum SORT_TYPE{NAME,FINAL_GRADE};

bool readFileIntoVector(std::ifstream &file, char char_to_search_for=CHAR_TO_SEARCH_FOR);
void calculateFinalGrade();
void extractFailingStudents(double failgrade = FAILGRADE);

bool writeDataToFile(ranking r, const std::string &filename);

//sorts studentdata based on SORT_TYPE
bool sortArray(SORT_TYPE st);

//if myString does not contain a string rep of number returns o
//if int not large enough has undefined behaviour, very fragile
int stringToInt(const char *myString);
std::string DoubleToString ( double Number );

#endif /* UTILITIES_H_ */
