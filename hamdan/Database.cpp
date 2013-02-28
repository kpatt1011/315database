#include "Database.h";

/*Helper compare funtions. Compares two values of the same type. Taking a third String parameter as the logical operation to perform */
bool compare_strings(String a, String b, String c) {

	if(c == "=" || c== "==") {
		return (a == b);
	}

		if(c == "!=") {
			return (a!=b);
		}

			if(c == ">") {
				return (a>b);
			}

				if(c == "<") {
					return (a<b);
				}

					if(c == ">=") {
						return(a>=b);
					}

						if(c == "<=") {
							return (a<=b);
						}

							else {
								cout << "INVALID OPERAND " << c << "\n";
							  return false;
							}
}

bool compare_dates(String a, String b, String c) {

	
	if(c == "=" || c== "==") {
		return (a == b);
	}

		if(c == "!=") {
			return (a!=b);
		}

			if(c == ">") {
				return (a>b);
			}

				if(c == "<") {
					return (a<b);
				}

					if(c == ">=") {
						return(a>=b);
					}

						if(c == "<=") {
							return (a<=b);
						}

							else {
								cout << "INVALID OPERAND " << c << "\n";
							  return false;
							}
}

bool compare_integers(int a, int b, String c) {

	
	if(c == "=" || c== "==") {
		return (a == b);
	}

		if(c == "!=") {
			return (a!=b);
		}

			if(c == ">") {
				return (a>b);
			}

				if(c == "<") {
					return (a<b);
				}

					if(c == ">=") {
						return(a>=b);
					}

						if(c == "<=") {
							return (a<=b);
						}

							else {
								cout << "INVALID OPERAND " << c << "\n";
							  return false;
							}
}

bool compare_floats(double a, double b, String c) {
	
	if(c == "=" || c== "==") {
		return (a == b);
	}

		if(c == "!=") {
			return (a!=b);
		}

			if(c == ">") {
				return (a>b);
			}

				if(c == "<") {
					return (a<b);
				}

					if(c == ">=") {
						return(a>=b);
					}

						if(c == "<=") {
							return (a<=b);
						}

							else {
								cout << "INVALID OPERAND " << c << "\n";
							  return false;
							}

}


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

		
		// Parse the WHERE String using stringstream
		istringstream where_stream(WHERE);

		vector<bool> expressions; // Stores the true false results of expressions
		vector<bool> conditions; // Stores the relationships between the expressions (and/or/end)
		

		while (!where_stream.eof()) {
			String current;
			getline(where_stream, current, ' ');

			
			bool column=false;
			int index_of_column; // The index of the column in the table specified in the WHERE condition

			// Check to see if the current String is an attribute from SELECT
			for(int i =0; i < attribute_names.size(); i++) {
				if(attribute_names[i] == current || attribute_names[i] == (current+")")) {
					column=true;
					index_of_column=i;
				}

			}

			// If the current string is the name of a column from SELECT then this if statement is entered
			if(column) {

				String column_name=attribute_names[index_of_column];
				String column_type=attribute_types[index_of_column];

				// Stores the next word in the wherestream, should be the operand
				String operand;
				getline(where_stream, operand, ' ');

				// Stores the next word after the operand, should be a literal value
				String liter;
				getline(where_stream, liter, ' ');

				// Check to see if liter is of the same type as column_type
				if(column_type == "integer" || column_type == "Integer" || column_type == "int" || column_type == "INTEGER") {

					// Casts strings to ints
					int numb;
					istringstream ( liter ) >> numb;

					/*Search through all of the records in the FROM table to find the data you need from the SELECT columns*/
					for(int i=0; i < from_table.get_size(); i++) {

						Record record_to_test = from_table.get_record_at(i);
						String entry = record_to_test.get_entry(index_of_column);

						/*Cast String entry to an integer*/
						int entry_value;
						istringstream ( entry ) >> entry_value;

						// Call helper function to the result of the conditional expression
						bool allowed_in_table = compare_integers(entry_value,numb,operand);

						if(allowed_in_table) {
							
								vector<String> tuple_to_add;
								Record a = from_table.get_record_at(i);

								for(int j=0; j < column_indexes.size(); j++) {
									tuple_to_add.push_back(a.get_entry(column_indexes[j]));
								}

								Record add (tuple_to_add);

								response.insert_row(add);
						}

					}

				}
						/*Not an integer. So check if its a float */
						else if(column_type == "FLOAT" || column_type == "float" || column_type == "double" || column_type == "DOUBLE" ) {

							// Casts strings to floats
							double numb;
							istringstream ( liter ) >> numb;

							for(int i=0; i < from_table.get_size(); i++) {

								Record record_to_test = from_table.get_record_at(i);
								String entry = record_to_test.get_entry(index_of_column);
								double entry_value;
								istringstream ( entry ) >> entry_value;

								bool allowed_in_table = compare_floats(entry_value,numb,operand);

								if(allowed_in_table) {
							
										vector<String> tuple_to_add;
										Record a = from_table.get_record_at(i);

										for(int j=0; j < column_indexes.size(); j++) {
											tuple_to_add.push_back(a.get_entry(column_indexes[j]));
										}

										Record add (tuple_to_add);

										response.insert_row(add);
								}

							}
						}
								
									/*Not an integer, or a float. So check if its a String */
								else if(column_type == "String" || column_type == "STRING" || column_type == "string" || column_type == "str" || column_type== "STR" ) {
					
									/*Iterates through every record in the FROM table, and determines if it meets the WHERE conditions*/
									for(int i=0; i < from_table.get_size(); i++) {

										Record record_to_test = from_table.get_record_at(i); 
										String entry = record_to_test.get_entry(index_of_column);

										bool allowed_in_table = compare_strings(entry,liter,operand);

										if(allowed_in_table) {
							
												vector<String> tuple_to_add;
												Record a = from_table.get_record_at(i);

												for(int j=0; j < column_indexes.size(); j++) {
													tuple_to_add.push_back(a.get_entry(column_indexes[j]));
												}

												Record add (tuple_to_add);

												response.insert_row(add);
										}

									}
								}


										/*Not an integer, float, or a String. So check if its a date */
									else if(column_type == "DATE" || column_type == "date" || column_type == "Date") {

										/*Iterates through every record in the FROM table, and determines if it meets the WHERE conditions*/
										for(int i=0; i < from_table.get_size(); i++) {

											Record record_to_test = from_table.get_record_at(i); 
											String entry = record_to_test.get_entry(index_of_column);

											bool allowed_in_table = compare_strings(entry,liter,operand);

						
											if(allowed_in_table) {
							
													vector<String> tuple_to_add;
													Record a = from_table.get_record_at(i);

													for(int j=0; j < column_indexes.size(); j++) {
														tuple_to_add.push_back(a.get_entry(column_indexes[j]));
													}

													Record add (tuple_to_add);

													response.insert_row(add);
											}

										}
									}

												/*Not an integer, float, String, or date. So the type must be invalide */
												else {
													cout << "Invalid type in WHERE expression";
													return response;
												}
			}

			else if(current== "AND" || current == "and" || current == "&&" || current == "And") {
				// NEED TO MAKE AND WORK
			}

			else if(current == "OR" || current == "or" || current == "||" || current == "Or") {
				// NEED TO MAKE OR WORK
			}

			else if (current == "\0") {
				// Nothing happens
			}
			else {
				cout << "\nINVALID SYTAX IN WHERE EXPRESSION\n";
				return response;
			}
		








	// Implement SELECT 
	//  - A list of which attribute names to keep.
	//  - Passing a NULL list of attributes indicates all attributes will be kept

	// Implement FROM

	// Implement WHERE

	// Need AND, OR, NOT
	// Needs parenthesis

	/* First get the Table you need using that function you wrote to get the index in the database */

//int location = get_index_in_database(this, FROM); /* If this doesn't exists than right it */


//map<String,String> attributes= locFrom.get_columns(); /* Gets the needed columns from the database */

/* You than need to create a list of all attributes that are in the map, and in the list*/

/*You than need to validate the WHERE condition */

/* You than need to iterate through that list, and find all of the elements that match the WHERE condition*/
	
}


			return response;
}

void Database::erase(list<String> SELECT, String DELETE, String WHERE) {
}

Database::~Database(){
}



