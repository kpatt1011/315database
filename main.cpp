#include "Database.h"
#include <map>
#include <stack>

int main() {

	
	// Create records to add to tables
	vector<String> test;
	vector<String> test2;

	test.push_back("Apple");
	test.push_back("Tuesday");
	test.push_back("No");
	test.push_back("85");

	test2.push_back("Oranges");
	test2.push_back("Wednesday");
	test2.push_back("Yes"); 
	test2.push_back("6");

	Record a (test);
	Record b (test2);


	// Create a table to add records too, and then add to the database
	Table testTable;

	testTable.add_column("Stock","String");
	testTable.add_column("Time","Date");
	testTable.add_column("Sucks","String");
	testTable.add_column("Price","Integer");
	testTable.insert_row(a);
	testTable.insert_row(b);
	String output=testTable.Get_Column_Attributes();


	// Create a test database

	Database testDatabase;
	testDatabase.add_table(testTable, "Test Table");

	list<String> SEL;
	SEL.push_back("Stock");
	SEL.push_back("Time");
	SEL.push_back("Sucks");
	SEL.push_back("Price");

	// Test Database Functionality
	Table queryResponse= testDatabase.query(SEL,"Test Table", "Price < 9");
	queryResponse.Print();

	map<String,String> testMap = queryResponse.get_columns();



	cout<<"\n\n";

	keep_window_open();

}