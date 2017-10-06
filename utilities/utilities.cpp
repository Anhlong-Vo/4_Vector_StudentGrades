#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <stdlib.h>

#include "../includes/constants.h"
#include "../includes/utilities.h"

using namespace std;

vector<studentData> 								allstudentData;
vector<studentData> 								failstudentData;

bool readFileIntoVector(ifstream &file) {
	bool retValue = true;	//assume best

	std::string line;
	std::string token;
	studentData myStudentData;
	stringstream ss;
	const char CHAR_TO_SEARCH_FOR = ' ';

	while (!file.eof()) {
		getline(file, line); //get a line from the file Name, Midterm,Final
		ss.str(line);

		//get rid of the old values
		myStudentData.clear();

		//!!!!!! NO ERROR CHECK HERE DONT ASSUMME PERFECT DATA 		!!!!!!
		//!!!!!! if any of the following fail retValue should		!!!!!!
		//!!!!!! be set to false, break out of loop, then return;	!!!!!!

		//get the name
		getline(ss, myStudentData.name, CHAR_TO_SEARCH_FOR);

		//get midterm
		getline(ss, token, CHAR_TO_SEARCH_FOR);
		myStudentData.midterm = stringToInt(token.c_str());

		//get final
		getline(ss, token, CHAR_TO_SEARCH_FOR);
		myStudentData.final = stringToInt(token.c_str());

		//finally add to array
		allstudentData.push_back(myStudentData);

		//clear stream so it will work for next read
		ss.clear();
	}
	return retValue;
}


void calculateFinalGrade() {
//	//using the [] way
//	for (int var = 0; var < allstudentData.size(); ++var) {
//		allstudentData[var].classgrade = 0.4 * allstudentData[var].midterm 	+ 0.6 * allstudentData[var].final;
//	}

	//iterator for list
	std::vector<studentData>::iterator itr;

	//using the iterator way
	//vector
	for ( itr = allstudentData.begin(); itr != allstudentData.end(); ++itr ){
		(*itr).classgrade = 0.4 * (*itr).midterm 	+ 0.6 * (*itr).final;
	}
}

  //void extractFailingStudents(vector<studentData> &allstudentData, list<studentData> &failstudentData){
  void extractFailingStudents(){
	const double FAILGRADE = 60.0;

	//iterate over allstudentData
    //std::list<studentData>::iterator 	itr = allstudentData.begin();	//list
    std::vector<studentData>::iterator 	itr = allstudentData.begin();	//vector

	while (itr != allstudentData.end()){
		if ((*itr).classgrade<FAILGRADE){
			failstudentData.push_back(*itr);
			itr = allstudentData.erase(itr);	//erase returns updated iter pointing to next element
		}
		else
			++itr;
	}
}

  //forward declaration
bool writeDataToFile(const std::string outfilename,std::vector<studentData> data);
bool writeDataToFile(ranking r,const string& outfilename){
	switch (r){
	case FAIL:
		return writeDataToFile(outfilename,failstudentData );

	case PASS:
		return writeDataToFile(outfilename,allstudentData);
	}
}
bool writeDataToFile(const std::string outfilename,std::vector<studentData> data) {
	ofstream myfile;
	myfile.open(outfilename.c_str());
	if (!myfile.is_open())
		return false;

//	TODO: sortArray();

	string mydata;
	for (int var = 0; var < data.size(); ++var) {
		mydata = data[var].name + "  " +
				DoubleToString(data[var].midterm) + "  " +
				DoubleToString(data[var].final) + "  " +
				DoubleToString(data[var].classgrade);
		myfile<<mydata<<std::endl;
	}

	if (myfile.is_open())
		myfile.close();

	return true;
}

//if you are debugging the file must be in the project parent directory
//in this case Project2 with the .project and .cProject files
std::string DoubleToString ( double Number ){
     std::ostringstream ss;
     ss << Number;
     return ss.str();
  }

//if myString does not contain a string rep of number returns o
//if int not large enough has undefined behaviour, very fragile
int stringToInt(const char *myString) {
	return atoi(myString);
}
