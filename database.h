#include "std_lib_facilities.h"

#ifndef DATABASE_H
#define DATABASE_H


class Database {
	
public: 
	// Constructor function with no arguments. Creates Empty database
	Database(); 
	/*  //RETURN VALUE FOR THE Database() FUNCTION:
	    no return value since it is a constructor

		//FUNCTIONALITY 
	    Initializes an empty Database

		//PARAMETERS 
		 Does not take any parameter
	
	*/
	// Add table function that takes a single table and a name, and adds that table to the database
	void add_table( string Table, String Attribute);
	
	/*  //RETURN VALUE FOR THE Database() FUNCTION:
	    no return value 

		//FUNCTIONALITY 
	    Add the attribute "Attribute" to the database "Table"

		//PARAMETERS 
		 Takes a string "Table" which is the name of a Database. 
		 Takes a string "Attribute" and adds that attritube to the database "Table"  
	
	*/
	

	// Drop function that takes a table name and deletes it from the database
	void drop_table(String Table);

	/*  //RETURN VALUE FOR THE Database() FUNCTION:
	    no return value 

		//FUNCTIONALITY 
	    Deletes the "Table" from the Database

		//PARAMETERS 
		 Takes a string "Table" which is the name of a Database instance 
		   
	
	*/
	

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
