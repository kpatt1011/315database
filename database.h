#include "std_lib_facilities.h"
#include "Record.h"
#include "Table.h"

#ifndef DATABASE_H
#define DATABASE_H





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
