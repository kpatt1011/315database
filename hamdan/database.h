#include "std_lib_facilities.h"
#include "Record.h"
#include "Table.h"

#ifndef DATABASE_H
#define DATABASE_H

//! Database Class
/*!
	Application Programming Interface (API) for Database System Implementation by team 19.

	Any questions/concerns regarding API usage, documentation clarity, or grading should be directed to keith.pattison.tamu@gmail.com

	##### Team 19 Members
	- Keith Pattison (keith.pattison.tamu@gmail.com)
	- Hamdan Siddiqui (hamdansiddiqui@hotmail.com)
	- David Holdren (djholdren@tamu.edu)

*/

class Database {
	
	
public: 
	int num_tables;
	vector<String> table_names;
	vector<Table> tables;

	/*! 
	
	   ### Description
	   ____
	   Creates an empty database

	   ### Return Value
	   ____
	   None 
	
	   ### Parameters 
	   ____
	   None
		
	*/
	Database(); 
  

	/*! 
	
		   ### Description
		   ____
		   Add a table to the database

		   ### Return Value
		   ____
		   None 
	
		   ### Parameters 
		   ____
		   _insert_
		       - Table to insert into database 

		   _name_
		       - Name of table within database
		
	*/
	void add_table(Table insert, String name);
	  

	/*! 
	
		   ### Description
		   ____
		   Takes a table name and deletes it from the database

		   ### Return Value
		   ____
		   None 
	
		   ### Parameters 
		   ____
		   _name_
		       - Name of table to delete within database
		
	*/
	void drop_table(String name);

    /*! 
	
		   ### Description
		   ____
		   Returns a list of all the table names in the database

		   ### Return Value
		   ____
		   _list<String>_
		       - List of all the table names database
	
		   ### Parameters 
		   ____
		   None
		
	*/
	list<String>  list_table_names();
	
	 /*! 
	
		   ### Description
		   ____
		   Returns a list of all the tables in the database

		   ### Return Value
		   ____
		   _list<Table>_
		       - All of the tables in the database
	
		   ### Parameters 
		   ____
		   None
		
	*/
	list<Table>  get_tables();

	 /*! 
	
		   ### Description
		   ____
		   Locate tuples within the database

		   ### Return Value
		   ____
		   None
	
		     ### Parameters 
		   ____
		   _SELECT_
		       - A list of which attribute names to keep.
			   - Passing a NULL list of attributes indicates all attributes will be kept

		   _FROM_
		       - Name of table within database

		   _WHERE_
			   - Conditions that should be present in the attributes.
			   - Limited to comparisons using =, !=, >, < >=. <= of attributes that have the same type
		
	*/

	Table query(list<String> SELECT, String FROM, String WHERE);
	

	/*! 
	
		   ### Description
		   ____
		   Erase tuples from the database

		   ### Return Value
		   ____
		   None
	
		     ### Parameters 
		   ____
		   _SELECT_
		       - A list of which attribute names to keep.
			   - Passing a NULL list of attributes indicates all attributes will be kept

		   _DELETE_
		       - Name of table containing tuples to be deleted within database

		   _WHERE_
			   - Conditions that should be present in the attributes.
			   - Limited to comparisons using =, !=, >, < >=. <= of attributes that have the same type
		
	*/
	void erase(list<String> SELECT, String DELETE, String WHERE);

	/*! 
	
		   ### Description
		   ____
		   Deconstructor for Database

		   ### Return Value
		   ____
		   None
	
		     ### Parameters 
		   ____
		   None
		
	*/
	~Database();

};

#endif
