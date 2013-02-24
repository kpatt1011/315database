//! maintest.cpp


/*
GROUP# 36
Mitchell Taylor 
Jose Manriquez
Elliott Fawcett 
*/

#define BOOST_TEST_MAIN

#include "boost/unit_test.hpp"
#include "std_lib_facilities.h"
#include <map>

#include "Database.h"

BOOST_AUTO_TEST_CASE(SimpleTestInMainTestingModule)
{
	vector<String> testVec1, testVec2;
	testVec1.push_back("CSNET");
	testVec1.push_back("Terrible");
	testVec1.push_back("Hate");
	testVec1.push_back("Failure");
	testVec1.push_back("Disgrace");
	testVec1.push_back("Weak");
	testVec1.push_back("Inconsistant");
	testVec1.push_back("Unavailable");
	testVec1.push_back("WorseThanTheWorstGoogleProduct");
	testVec1.push_back("EvenWorseThanTheWorstMicrosoftProduct");
	testVec1.push_back("WorseThanYahoosWhitespaceUsage");
	Record testRecordFull = Record(testVec1);
	Record testRecordEmpty = Record(testVec2);
	BOOST_CHECK(testRecordFull.get_size == 11);
	BOOST_CHECK(testRecordEmpty.get_size == 0);
	BOOST_CHECK(testRecordFull.get_entry(0) == "CSNET");
	BOOST_CHECK(testRecordFull.get_entry(1) == "Terrible");
	BOOST_CHECK(testRecordFull.get_entry(2) == "Hate");
	BOOST_CHECK(testRecordFull.get_entry(3) == "Failure");
	BOOST_CHECK(testRecordFull.get_entry(4) == "Disgrace");
	BOOST_CHECK(testRecordFull.get_entry(5) == "Weak");
	BOOST_CHECK(testRecordFull.get_entry(6) == "Inconsistant");
	BOOST_CHECK(testRecordFull.get_entry(7) == "Unavailable");
	BOOST_CHECK(testRecordFull.get_entry(8) == "WorseThanTheWorstGoogleProduct");
	BOOST_CHECK(testRecordFull.get_entry(9) == "EvenWorseThanTheWorstMicrosoftProduct");
	BOOST_CHECK(testRecordFull.get_entry(10) == "WorseThanYahoosWhitespaceUsage");
	testRecordFull.replace_entry(1, "Awful");
	BOOST_CHECK(testRecordFull.get_entry(1) == "Awful");
	BOOST_CHECK(testRecordFull.get_size == 11);



	/*

	This constuctor will not allow attributes of different types in one table! 
	Though, templating is used, it will result in something like Map<String, int>, or Map<String, Time>
	This would mean every attribute in a table would have to be of type time. 
	We've assumed changing the expected type input to string, so a table can handle multiple types in one table

	*/

	
	map<String, String> testMap;
	testMap["1"] = "Integer";
	testMap["Tabby"] = "String";
	testMap["3"] = "Integer";
	testMap["1.2"] = "Float";
	testMap["2013/02/15"] = "Date";
	testMap["15:34:59"] = "Time";
	Table testTable2(testMap);
	


	Table testTable1;
	testTable1.add_column("1", "Integer");
	testTable1.add_column("Tabby", "String");
	testTable1.add_column("3", "Integer");
	testTable1.add_column("1.2", "Float");
	testTable1.add_column("2013/02/15", "Date");
	testTable1.add_column("15:34:59", "Time");
	
	map<String, String> testTable1columns = testTable1.get_columns();
	map<String, String> testTable2columns = testTable2.get_columns();
	BOOST_CHECK(testTable1columns == testTable2columns);
	testTable1.delete_column("1");
	testTable1columns = testTable1.get_columns();
	BOOST_CHECK(testTable1columns != testTable2columns);
	testTable2.delete_column("1");
	BOOST_CHECK(testTable1columns == testTable2columns);
	testTable1.rename_column("3", "2");
	BOOST_CHECK(testTable1columns != testTable2columns);
	testTable2.rename_column("3", "2");
	BOOST_CHECK(testTable1columns == testTable2columns);


	//testRecordFull 
	//testRecordEmpty

	//	Tabby (String)	|	2 (Integer)	|	1.2 (Float)	|	2013/02/15 (Date)	|	15:34:59 (Time)

	vector<String> testRecVec1, testRecVec2;
	testVec1.push_back("Hello");
	testVec1.push_back("23");
	testVec1.push_back("1.2");
	testVec1.push_back("2013/02/15");
	testVec1.push_back("15:34:59");
	Record testRecord1 = Record(testRecVec1);

	testVec1.push_back("Bye");
	testVec1.push_back("11");
	testVec1.push_back("2.2");
	testVec1.push_back("2011/02/15");
	testVec1.push_back("15:32:59");
	Record testRecord2 = Record(testRecVec2);
	
	testTable1.insert_row(testRecord1);
	testTable1.insert_row(testRecord2);
	
	testTable2.insert_row(testRecord1);
	testTable2.insert_row(testRecord2);
	Record r1 = testTable1.get_record_at(0);	
	BOOST_CHECK(r1.get_entry(0) == testRecord1.get_entry(0));
	BOOST_CHECK(r1.get_entry(1) == testRecord1.get_entry(1));
	BOOST_CHECK(r1.get_entry(2) == testRecord1.get_entry(2));
	BOOST_CHECK(r1.get_entry(3) == testRecord1.get_entry(3));
	BOOST_CHECK(r1.get_entry(4) == testRecord1.get_entry(4));
	Record r2 = testTable1.get_record_at(1);
	BOOST_CHECK(r2.get_entry(0) == testRecord2.get_entry(0));
	BOOST_CHECK(r2.get_entry(1) == testRecord2.get_entry(1));
	BOOST_CHECK(r2.get_entry(2) == testRecord2.get_entry(2));
	BOOST_CHECK(r2.get_entry(3) == testRecord2.get_entry(3));
	BOOST_CHECK(r2.get_entry(4) == testRecord2.get_entry(4));
	BOOST_CHECK(testTable1.entry_sum("2") == 34);
	BOOST_CHECK(testTable1.entry_sum("1.2") == 3.4);
	BOOST_CHECK(testTable2.entry_sum("2") == 34);
	BOOST_CHECK(testTable2.entry_sum("1.2") == 3.4);
	BOOST_CHECK(testTable1.entry_count("1.2") == 2);
	BOOST_CHECK(testTable1.entry_count("2") == 2);
	BOOST_CHECK(testTable2.entry_count("1.2") == 2);
	BOOST_CHECK(testTable2.entry_count("2") == 2);
	
	//we're assuming when the database is implemented, these errors will dissapear 
	BOOST_CHECK( testTable1.entry_max("2") == testTable2.entry_max("2"));
	BOOST_CHECK(testTable1.entry_max("2") == "23");
	BOOST_CHECK(testTable1.entry_min("2") == testTable2.entry_min("2"));
	BOOST_CHECK(testTable1.entry_min("2") == "11");
	
	map<String,String> testMap = testTable1.get_columns();
	
	BOOST_CHECK(testMap.size() == 5);
	testTable1.delete_column("2");
	testMap = testTable1.get_columns();
	BOOST_CHECK(testMap.size() == 4);


	//	Tabby (String)	| 1.2 (Float)	|	2013/02/15 (Date)	|	15:34:59 (Time)
	//  crossjoined:
	//	Tabby (String)	| 1.2 (Float)	|	2013/02/15 (Date)	|	15:34:59 (Time)	|	Tabby (String)	| 1.2 (Float)	|	2013/02/15 (Date)	|	15:34:59 (Time)
		
	Table testTable4;
	testTable4.add_column("c1", "Integer");
	testTable4.add_column("c2", "String");
	vector<String> vectorstring1, vectorstring2, vectorstring3;
	vectorstring1.push_back("12");
	vectorstring1.push_back("hi");
	vectorstring2.push_back("15");
	vectorstring2.push_back("jo");
	
	Record testRecord3(vectorstring1);
	Record testRecord4(vectorstring2);
	Record testRecord5(vectorstring3);
	testTable4.insert_row(testRecord3);
	testTable4.insert_row(testRecord4);
	testTable4.insert_row(testRecord5);

	Table testTable3 = testTable4.cross_join(testTable4, testTable2);
	map<String, String> testMap2 = testTable3.get_columns();


	BOOST_CHECK(testTable3.entry_count == 6);
	BOOST_CHECK(testMap2.size == 6);

	Database testDB;
	list<String> testList1 = testDB.list_table_names();
	list<Table> testList2 = testDB.get_tables();
	BOOST_CHECK(testList1.empty == true);
	BOOST_CHECK(testList2.empty == true);
	Table testTable;
	testDB.add_table(testTable, "TestTable");
	testList1 = testDB.list_table_names();
	testList2 = testDB.get_tables();
	BOOST_CHECK(testList1.size == 1);
	BOOST_CHECK(testList2.size == 1);
	testDB.drop_table(testTable);
	testDB.add_table(testTable1, "tt1");
	testDB.add_table(testTable2, "tt2");
	testDB.add_table(testTable3, "tt3");
	testDB.add_table(testTable4, "tt4");
	testDB.erase;
	Database testDB2;

	testList1 = testDB2.list_table_names();
	testList2 = testDB2.get_tables();
BOOST_CHECK(testList1.size == 0);
BOOST_CHECK(testList2.size == 0);
	Table testTable1; //adds two more tables 
	Table testTable2;
	testDB2.add_table(testTable1, "TestTable1");
	testDB2.add_table(testTable2, "TestTable2");
	testList1 = testDB2.list_table_names();
	testList2 = testDB2.get_tables();
	BOOST_CHECK(testList1.size == 2);
	BOOST_CHECK(testList2.size == 2);
	BOOST_CHECK(testList1.begin == "TestTable1")// Checks if table2 is named correctly
	


}