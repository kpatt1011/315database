#include "Database.h";

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
	// Implement SELECT
	//  - A list of which attribute names to keep.
	//  - Passing a NULL list of attributes indicates all attributes will be kept

	// Implement FROM

	// Implement WHERE

	// =, !=, >, < >=. <=
	
	map<String,String> test;
	Table temp (test);
	return temp;
}

void Database::erase(list< String > SELECT, String DELETE, String WHERE) {
}

Database::~Database(){
}

