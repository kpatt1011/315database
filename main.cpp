#include "Database.h"
#include <map>
#include <stack>

/*
bool solve_expression(String current) {
	
}
*/

int main() {

	
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
	//cout << a.get_size() << endl;

	//cout << "\n" << a.get_entry(0);

	
	Table testTable;

	testTable.add_column("Stock","String");
	testTable.add_column("Time","Date");
	testTable.add_column("Sucks","String");
	testTable.add_column("Price","Integer");
	testTable.insert_row(a);
	testTable.insert_row(b);
	String output=testTable.Get_Column_Attributes();

	//cout << output << "\n";

	Database testDatabase;
	testDatabase.add_table(testTable, "Test Table");

	list<String> SEL;
	SEL.push_back("Stock");
	SEL.push_back("Time");
	SEL.push_back("Sucks");
	SEL.push_back("Price");

	// Test Database Function
	Table queryResponse= testDatabase.query(SEL,"Test Table", "( ((Price > 6) AND (Price < 7)) OR ((Price < 8) AND (Price != 9))  )");
	queryResponse.Print();

	map<String,String> testMap = queryResponse.get_columns();

	/*
	map<String,String>::const_iterator iterator;
	for (iterator = testMap.begin(); iterator != testMap.end(); ++iterator) {
		
	}*/

	/*for (auto& x: testMap) {
    cout << x.first << ": " << x.second << '\n';
  }*/

	/*
		for(int i=0; i < queryResponse.get_size(); i++) {
			cout<<"\n";
			Record a = queryResponse.get_record_at(i);

			for(int j=0; j < a.get_size(); j++) {
				cout<< j << ": " << a.get_entry(j) << "   ";
			}
			
		}
		*/



	cout<<"\n\n";

/*
	String broken = "(Price < 9)";
	vector<String> expressions;
	String expr_to_add;

	bool keep_going=true;
	int length=0;

	while(length < broken.size() && keep_going) {
			if(broken[length] == '(') {
				length++;
				bool end_paren_found= false;
				while(length < broken.size() && !end_paren_found) {
					
					if(broken[length] == ')') {
						break;
					}
					else {
						expr_to_add+=broken[length];
					}
					length++;
				}
			}

		length++;
	}

	*/

	

	keep_window_open();

}