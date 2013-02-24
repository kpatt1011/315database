#include "std_lib_facilities.h"
#include "Record.h"
#include <map>

#ifndef TABLE_H
#define TABLE_H

//! Table Class
/*!
	Used to implement a table (rows, columns) within a database. 
*/
using namespace std;
class Table {

public:
		
	/*! 
	
	   ### Description
	   ____
	   Creates an empty table with no rows or columns

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
	    _ Attributes_
		       - map<name,attribute_type> 
			   - name is the name of each attribute. Each one must be unique
			   - attribute_type is the the type of the associated attribute (Integer, String, Float, Date, Time)
		
	*/

	Table( map<String,String> attributes  ){};

	/*! 
	
	   ### Description 
	   ____
	   Takes in a single attribute (column) name and type. Add new column to end of table.
	   Any entries currently in the table get NULL for that entry
	
	   ### Return Value
	   ____
	   None 
	   
	   ### Parameters
	   ____
			_name_
		       - The name of the new column

			_t_
		       - Type of new column (Integer, String, Float, Date, Time)

		
	*/
	template <typename Type>
	void add_column(String name, Type t) {};

	
		/*! 
	
	   ### Description 
	   ____
	   Insert a new record (a.k.a. row) into the table.
	
	   ### Return Value
	   ____
	   None 
	   
	   ### Parameters
	   ____
			_row_
		       - A record (tuple) to be inserted as a new row in the database
	*/
	void insert_row (Record row);

	/*! 
	
	   ### Description 
	   ____
	   Takes an attribute (column) name and deletes it from the table
	
	   ### Return Value
	   ____
	   None 
	   
	   ### Parameters
	   ____
			_name_
		       - The name of the attribute (column) to be deleted
	*/
	void delete_column (String name); 

	/*! 
	
	   ### Description 
	   ____ 
	   Returns a map of all the columns (name and associated type) in the database. 
	
	   ### Return Value
	   ____
	   _map<name,type>_
		       - A map of all the columns in the database. Organized with column names as the key values, pointing to their respective types
	   
	   ### Parameters
	   ____
	   None
	*/
	std::map<String,String> get_columns();

	/*! 
	
	   ### Description 
	   ____ 
	   Returns the number of records in the table
	
	   ### Return Value
	   ____
	   _Size_
		       - Number of records in the table. Returned as an int
	   
	   ### Parameters
	   ____
	   None
	*/
	int get_size();

	/*! 
	
	   ### Description 
	   ____ 
	   Returns the record at the given row number in the database. Used with get_size and a for loop it is possible to iterate all of the records in the database. 
	   
	
	   ### Return Value
	   ____
	   _Record_
		       - The record stored at the given indexed row
	   
	   ### Parameters
	   ____
	   _index_
		- The int row index of the record to be retrived.
	*/
	Record get_record_at(int index);

	/*! 
	
	   ### Description 
	   ____ 
		Changes the name of a current attribute (column) in the database.	   
	
	   ### Return Value
	   ____
		None
	   
	   ### Parameters
	   ____
	   _name1_
		- The original name of the column

	   _name2_
		- The new name of the column
	*/
	void rename_column(String name1, String name2);


	/*! 
	
	   ### Description 
	   ____ 
		Cross join two tables.	   
	
	   ### Return Value
	   ____
		_Table_
			- New Table resulting from the cross join of table a and b
	   
	   ### Parameters
	   ____
	   _a_
		- Table to be cross joined

	   _b_
		- Table to be cross joined
	*/
	Table cross_join(Table a, Table b);

	/*! 
	
	   ### Description 
	   ____ 
		Returns the sum of all the entries in a given column
	
	   ### Return Value
	   ____
		_int_
			- Sum of all column entries

	   ### Parameters
	   ____
	   _ column_name _
		- Name of column to sum entries from
	*/
	int entry_sum(String column_name);

	/*! 
	
	   ### Description 
	   ____ 
		Counts the total number of entries in the column. (non-null entries only)   
	
	   ### Return Value
	   ____
		_int_
			- Number of non-null entries in the column

	   ### Parameters
	   ____
	   _ column_name _
		- Name of column to count entries from
	*/
	int entry_count(String column_name);

	/*! 
	
	   ### Description 
	   ____ 
		Returns the minimum entry in the column.   
	
	   ### Return Value
	   ____
		_Type_
			- Value of the minimum entry in the column.

	   ### Parameters
	   ____
	   _ column_name _
		- Name of column to find minimum entry from
	*/
	template <typename Type>
	Type entry_min(String column_name){};

	/*! 
	
	   ### Description 
	   ____ 
		Returns the maximum entry in the column. 
	
	   ### Return Value
	   ____
		_Type_
			- The value of the maximum entry in the column

	   ### Parameters
	   ____
	   _ column_name _
		- Name of column to find maximum entry from
	*/
	template <typename Type>
	Type entry_max(String column_name){};

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
	~Table();

	
};

#endif