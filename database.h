#include "std_lib_facilities.h"

#ifndef DATABASE_H
#define DATABASE_H

class Record {
	Record();
};

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

class Database {
	
public: 
	// Constructor function with no arguments. Creates Empty database
	Database(); 

	// Add table function that takes a single table and a name, and adds that table to the database
	void add_table(String name);

	// Drop function that takes a table name and deletes it from the database
	void drop_table(String name);

	// List table function that returns a list of all table names in the database

	// Get tables function that returns all the tables in the database

	// Query Function

	// Delete command. Should follow that of the query command, except that instead of returning a table, 
	// the table in the FROM portion has the apporopriate tuples deleted

	// Update command. Takes a table name, a WHERE clause (as in the query command), and SET clause 
	// Set clause should be able to reference attributes of the table, and set them to values that are either a constant or 
	// (in the case integers and floats) a computed function on attributed values (from that table)/ The operations +,-,*, and / should be supported

private: 


};

#endif
