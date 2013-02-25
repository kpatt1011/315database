#include "Record.h"
#include <list>
#include <iostream>
#include <map>


using namespace std;


class Table {

private:
	map<string, string> Data;
	list<Record> Row; 
	std::string Key;
	std::string Column_Attributes;
	

	//Private Cross Join Function
	Table Cross(Table a, Table b);
	
	


public:
	// Need constructors for rows and columns. And empty constructor
	Table();

	void Print();
	
	// Constructor to take a list of attribute names and types
	Table (map< string, string > attributes);

	// Add function that takes in a single attribute name and type 
	// and adds a column to the end of the table with that new 
	// attribute. Any entries currently in the table should get NULL
	// for that entry
	void add_column (string name, string t);

	// A delete function that takes an attribute name and deletes it from the table
	void 	delete_column (string name);

	// An insert command that takes a record and adds it to the table
	void 	insert_row (Record row);
	
	// A get attributes command that returns a list of the attributes and types for that table

	// A get size command that returns the number of records in the table
	int 	get_size ();

	// An iterator of some sort that can be used to return individual records from the table
	Record 	get_record_at(int index);

	// A rename attribute command that takes two names, and replaces the name for the attribute given by the first name with the second name
	void 	rename_column (string name1, string name2);

	// A cross join command that takes two tables as input and produces one table as output
	Table 	cross_join (Table a, Table b);
	// Routines that take a single attribute name as input, and compute the following 
	// sum, count (counts non-null entries only), Min, MAx
	int 	entry_count (string column_name);
	
	int 	entry_sum (string column_name);

	string 	entry_min (string column_name);

   double 	entry_max (string column_name);

   int Column_size();
};
