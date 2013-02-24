#include "Table.h"

Table::Table() {
}

void Table::insert_row(Record row) {
}

void Table::delete_column (String name) {
}


int Table::get_size(){
	return 0;
}

Record Table::get_record_at(int index) {
	vector<string> a;
	a.push_back("Test");

	Record ret (a);
	return ret;
}

void Table::rename_column (String name1, String name2) {
}

Table Table::cross_join(Table a, Table b) {
	Table test;
	return test;
}

int Table::entry_sum(String column_name) {
	return 0;
}

int Table::entry_count(String column_name) {
	return 0;
}

map<String,String> Table::get_columns() {
	map<String,String> testMap;
	return testMap;
}

Table::~Table(){

}



