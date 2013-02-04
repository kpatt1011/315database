#include "std_lib_facilities.h"

#ifndef TABLE_H
#define TABLE_H


class Table {

public:
	// Need constructors for rows and columns. And empty constructor
	Table();

	// Constructor to take a list of attribute names and types
	
	// Add function that takes in a single attribute name and type 
	// and adds a column to the end of the table with that new 
	// attribute. Any entries currently in the table should get NULL
	// for that entry

	// A delete function that takes an attribute name and deletes it from the table

	// An insert command that takes a record and adds it to the table

	// A get attributes command that returns a list of the attributes and types for that table

	// A get size command that returns the number of records in the table

	// An iterator of some sort that can be used to return individual records from the table

	// A rename attribute command that takes two names, and replaces the name for the attribute given by the first name with the second name

	// A cross join command that takes two tables as input and produces one table as output

	// Routines that take a single attribute name as input, and compute the following 
	// sum, count (counts non-null entries only), Min, MAx

	
};

#endif