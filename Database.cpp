#include "Database.h";

Database::Database() {
}

void Database::add_table(Table insert, String name) {
}

void Database::drop_table(String name) {
}

list<string> Database::list_table_names() {
}

list<Table> Database::get_tables() {
}

Table Database::query (list< String > SELECT, String FROM, String WHERE) {
}

void Database::erase(list< String > SELECT, String DELETE, String WHERE) {
}

Database::~Database(){
}

