#include "std_lib_facilities.h"

#ifndef TABLE_H
#define TABLE_H

//! Table Class
/*!
	Used to implement a table within a database
*/

class Table {

public:
		
	/*! 
	
	   ### Description
	   ____
	   Creates an empty table with no attributes

	   ### Return Value
	   ____
	   None 
	
	   ### Parameters 
	   ____
	   None
		
	*/
	Table();

	/*! 
	
	   ### Description 
	   ____
	   Constructor that takes a map of attribute names and their associated types
	
	   ### Return Value
	   ____
	   None 
	   
	   ### Parameters
	   ____
	   Attributes
	   + String is attribute name
	   + Type is the attribute type (Integer, String, Float, Date, Time)
		
	*/
	template <typename Type>
	Table( map<String,Type> attributes  );

	// Add function that takes in a single attribute name and type 
	// and adds a column to the end of the table with that new 
	// attribute. Any entries currently in the table should get NULL
	// for that entry
	/*! 
	
	   ### Description 
	   ____
	   Takes in a single attribute name and type. Adds a column to the end of the table
	   with that new attribute. Any entries currently in the table get NULL for that entry
	
	   ### Return Value
	   ____
	   None 
	   
	   ### Parameters
	   ____
	   + name is attribute name
	   + Type is the attribute type (Integer, String, Float, Date, Time)
		
	*/
	template <typename Type>
	void addAttribute(String name, Type t);

	// An insert command that takes a record and adds it to the table
	// A delete function that takes an attribute name and deletes it from the table


	// A get attributes command that returns a list of the attributes and types for that table

	// A get size command that returns the number of records in the table

	// An iterator of some sort that can be used to return individual records from the table

	// A rename attribute command that takes two names, and replaces the name for the attribute given by the first name with the second name

	// A cross join command that takes two tables as input and produces one table as output

	// Routines that take a single attribute name as input, and compute the following 
	// sum, count (counts non-null entries only), Min, MAx

	/*! 
	
	   ### Description
	   ____
	   Table Destructor

	   ### Return Value
	   ____
	   None 
	
	   ### Parameters 
	   ____
	   None
		
	*/
	~Table()

	
};

#endif