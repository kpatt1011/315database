#include "Record.h"
#include "std_lib_facilities.h"


int main() {

	vector<string> test;

	test.push_back("TEST");


	Record a (test);

	cout << a.get_size() << endl;

	cout << "\n" << a.get_entry(0);

	keep_window_open();

}