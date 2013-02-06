#include "std_lib_facilities.h"

#ifndef RECORD_H
#define RECORD_H


class Record {
	
private:
	  list<string> Tuple;

public:
	//Empty Constructor
	Record();
	/*  //RETURN VALUE FOR THE Record() FUNCTION:
	    no return value since it is a constructor

		//FUNCTIONALITY 
	    Initializes an empty Record

		//PARAMETERS 
		 Does not take any parameter
	*/

	//An accessor that allows access to individual entry in the record
	string Access(string Column_Name);

	//A routine to modify an entry in the record
	void Modify (string Column_Name);

};


#endif