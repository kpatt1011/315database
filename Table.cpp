#include "Table.h"

Table::Table() {
}

template<typename Type >
void Table::add_column(String name, Type t){
}

void Table::insert_row(Record row) {
}

void Table::delete_column (String name) {
}

template<typename Type >
map<String, Type> Table::get_columns() {
}

int Table::get_size() {
}

Record Table::get_record_at(int index) {
}

void Table::rename_column (String name1, String name2) {
}

Table Table::cross_join(Table a, Table b) {
}

int Table::entry_sum(String column_name) {
}

int Table::entry_count(String column_name) {
}

template<typename Type>
Type Table::entry_min (String column_name) {
}

template<typename Type>
Type Table::entry_max (String column_name) {
}




