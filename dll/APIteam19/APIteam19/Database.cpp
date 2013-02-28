#include "Database.h";
#include "stdafx.h"

/*Helper function. Checks to see if the name exists in the database*/
bool name_exists_in_database(Database* a, String name) {
	// name_exists becomes true if the Database already contains a table with the given name
	bool name_exists = false; 

	// For loop checks to see if a table already exists with the given name in the database
	for (int i=0; i < a->num_tables; i++) {

		if(a->table_names[i] == name) {
			name_exists = true;
		}
	}

	return name_exists;
}

/*Helper function find the index of a name in the database 
	Assumes name is actually in the database. Otherwise it returns -1...
*/
int index_in_database(Database* a, String name) {

	int index=0;
	for(int i=0; i < a->num_tables; i++) {
		if(a->table_names[i] == name) {
			return i;
		}
	}

	return -1; // Shouldn't be reached. Unless somebody didn't check if value was in database first..
	
}

// Removes a table from the database using the index
void remove_table_from_database(Database* a, int index) {
	
	a->num_tables = a->num_tables-1; // Decrease the number of tables

	// Move the elements in the vector after the index over one space to the left
	// Thereby erasing the table from the database
	for(int i=index; i < a->num_tables; i++) {
		a->table_names[i] = a->table_names[i+1];
		a->tables[i] = a->tables[i+1];
	}

}

Database::Database() {
	num_tables=0;
}


void Database::add_table(Table insert, String name) {
	
	// If the name already exists in the database then output an error.  
	if( name_exists_in_database(this,name) ) {
		cout<<"\nA table with this name already exists in the database";
	}
	// Else add the table to the database.
	else {
		num_tables++; 
		table_names.push_back(name);
		tables.push_back(insert);
	}
}

void Database::drop_table(String name) {
	// Drop is valid if name_exists_in_database returns false
	bool valid_drop = !(name_exists_in_database(this,name));
	
	// If the drop is valid then locate and call function to erase table from database 
	if(valid_drop) {
		for(int i=0; i < num_tables; i++) {
			if(table_names[i] == name) {
				remove_table_from_database(this,i);
			}
		}
	}

	else {
		cout<< "\nUnable to drop this table. NAME DOES NOT EXIST IN DATABASE";
	}
		
}

list<String> Database::list_table_names() {
	list<String> names;
	
	// Traverse table_names and add it to names
	for(int i=0; i < num_tables; i++) {
		names.push_back(table_names[i]);
	}

	return names;
}

list<Table> Database::get_tables() {
	list<Table> table_list;

	// Traverse tables vector and add each element to table_list
	for(int i=0; i < num_tables; i++) {
		table_list.push_back(tables[i]);
	}

	return table_list;

}

Table Database::query (list<String> SELECT, String FROM, String WHERE) {

	Table response;
	Table from_table;
	vector<int> column_indexes; // The indexes of each of the columns to be checked with the WHERE condition

	// Checks if FROM exists in database
	if(name_exists_in_database(this,FROM)) { 

		// Intialize the response database
		int from_database_index = index_in_database(this,FROM); // Get it's index in table_names vector
		from_table = tables[from_database_index];

	}

	else {
		cout<< "\nSpecified FROM entry does not exist in database";
		return response;
	}

	// Get all the possible attributes to choose from
	String attr = from_table.Get_Column_Attributes(); 

	// Stores the names of all the possible attributes and the types in vectors where the index of each element corresponds
	vector<String> attribute_names;
	vector<String> attribute_types;

	istringstream ss( attr );

		String y;
		getline(ss,y,'(');
		while (!ss.eof()) {

		  String x;               // here's a nice, empty string
		  getline( ss, x, ',' );  // try to read the next field into it

	

				
					istringstream second_ss( x );
					String a="";

					while(!second_ss.eof()) {
						String temp;
						getline(second_ss, temp, ' ');

						if(a=="") {
							a=temp;
							attribute_types.push_back(temp);
						}
							else {
								attribute_names.push_back(temp);
							}
					}

		}


		/*this code block check if each element from select is a possible attribute, and adds them to the response table */
		list<String>::const_iterator iterator;

		for (iterator = SELECT.begin(); iterator != SELECT.end(); ++iterator) {
			bool exist = false;

			String column_name = *iterator;
			String temp= (column_name+")");

			for(int i=0; i < attribute_names.size(); i++) {
				if(column_name == attribute_names[i] || attribute_names[i] == temp ) {
					response.add_column(column_name, attribute_types[i]);
					column_indexes.push_back(i);
					exist=true;
				}
			}

			// Prints out an error if the column_name does not exist
			if(!exist) {
				cout << "\n" << column_name << " is an invalid attribute, and is not included in the results of the query";
			}
			
		}

		/*Search through all of the records in the FROM table to find the data you need from the SELECT columns*/

		for(int i=0; i < from_table.get_size(); i++) {

			vector<String> tuple_to_add;
			Record a = from_table.get_record_at(i);

			for(int j=0; j < column_indexes.size(); j++) {
				tuple_to_add.push_back(a.get_entry(column_indexes[j]));
			}

			Record add (tuple_to_add);

			response.insert_row(add);
		}









	// Implement SELECT 
	//  - A list of which attribute names to keep.
	//  - Passing a NULL list of attributes indicates all attributes will be kept

	// Implement FROM

	// Implement WHERE

	// =, !=, >, < >=. <=
	// Need AND, OR, NOT
	// Needs parenthesis

	/* First get the Table you need using that function you wrote to get the index in the database */

//int location = get_index_in_database(this, FROM); /* If this doesn't exists than right it */


//map<String,String> attributes= locFrom.get_columns(); /* Gets the needed columns from the database */

/* You than need to create a list of all attributes that are in the map, and in the list*/

/*You than need to validate the WHERE condition */

/* You than need to iterate through that list, and find all of the elements that match the WHERE condition*/
	
	return response;
}

void Database::erase(list<String> SELECT, String DELETE, String WHERE) {
}

Database::~Database(){
}

