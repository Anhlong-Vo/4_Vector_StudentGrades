/*
 * constants.h
 *
 *  Created on: Oct 5, 2017
 *      Author: keith
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_
#include <string>


const int 			USER_CHOSE_TO_EXIT 				= -1;
const int 			COULD_NOT_OPEN_FILE				= -2;
const int 			COULD_NOT_READ_FILE_INTO_VECTOR = -3;
const int 			COULD_NOT_WRITE_VECTOR_TO_FILE  = -4;
const int 			SUCCESS			 				=  0;
const std::string 	ALL_FILE 						= "TestData.txt";
const std::string 	PASS_FILE 						= "Pass.txt";
const std::string 	FAIL_FILE 						= "Fail.txt";

const double 		FAILGRADE 						= 60.0;



#endif /* CONSTANTS_H_ */
