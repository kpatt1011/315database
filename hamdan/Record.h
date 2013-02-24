
//! Record Class
/*!
	- Records are used to implement tuples (rows) in a table. 
	- Records contain all of the entries in a vector as Strings, regardless of their actual type.
	- An entry in the record is located using its index location in the vector
	- It is possible to traverse all the entries in the record using get_size() in conjunction with a standard loop
	- Records are not aware of the table they are being stored in.
	- Records are not aware of the actual type of each of their entries
*/

#include <iostream>
#include <vector>
#include <string>
#include "std_lib_facilities.h"

#ifndef RECORD_H
#define RECORD_H

class Record {
	
private:
	  vector<string> Tupel;

public:


	/*! 
	
	   ### Description                                                                                                                                  
	   ____ 
		Create a record (tuple) where each from a list of String types, where each String is an entry. This constructor allows for an arbitary amount of entries.
	
	   ### Return Value
	   ____
	   None

	   ### Parameters
	   ____
	   _entries_
		- List of entries to be in tuple

	*/
	Record(vector<string> Single_Tuple);


	/*! 
	    
	   ### Description 
	   ____ 
		Returns a String of the entry at the given index location.
	
	   ### Return Value
	   ____
		_String_
			- The value of the entry at the given location [index]

	   ### Parameters
	   ____
	   _index_
		- The index of the desired entry to obtain
	*/
	string get_entry(int index);

	/*! 
	
	   ### Description 
	   ____ 
		Replaces the entry at the designated index with the specified replacment String
	
	   ### Return Value
	   ____
		None

	   ### Parameters
	   ____

	   _index_
		- The index of the desired entry to replace
	   
	   _replacement_
		- The String value to replace the current entry at index
	*/
	void replace_entry(int index, string replacement);

	/*! 
	
	   ### Description 
	   ____ 
		Returns the number of entries in this Record.
	
	   ### Return Value
	   ____
		_int_
			- Number of entries in the record

	   ### Parameters
	   ____
		None
	*/
	int get_size();

	/*! 
	
	   ### Description 
	   ____ 
		Deconstructor
	
	   ### Return Value
	   ____
		None

	   ### Parameters
	   ____
		None
	*/
	~Record();


};

#endif


