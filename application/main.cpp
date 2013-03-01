#include "database.h"
#include "record.h"
#include "table.h"
#include "exception.h"
#include "std_lib_facilities.h"


Table* read_from_geoplaces2() {


  
  ifstream myfile ("geoplaces2.csv");
  if (myfile.is_open())
  {

	Table::ColumnList columns;

	String placeID;
	getline( myfile, placeID, ',' );
    columns.push_back(make_pair(placeID, Table::integer));

	String latitude;
	getline( myfile, latitude, ',' );
	columns.push_back(make_pair(latitude, Table::floating));

	String longitude;
	getline( myfile, longitude, ',' );
	columns.push_back(make_pair(longitude, Table::floating));

	String the_geom_meter;
	getline( myfile, the_geom_meter, ',' );
	columns.push_back(make_pair(the_geom_meter, Table::varchar));

	String name;
	getline( myfile, name, ',' );
    columns.push_back(make_pair(name, Table::varchar));

	String address;
	getline( myfile, address, ',' );
    columns.push_back(make_pair(address, Table::varchar));

	String city;
	getline( myfile, city, ',' );
    columns.push_back(make_pair(city, Table::varchar));

	String state;
	getline( myfile, state, ',' );
    columns.push_back(make_pair(state, Table::varchar));

	String country;
	getline( myfile, country, ',' );
    columns.push_back(make_pair(country, Table::varchar));

	String fax;
	getline( myfile, fax, ',' );
    columns.push_back(make_pair(fax, Table::varchar));

	String zip;
	getline( myfile, zip, ',' );
    columns.push_back(make_pair(zip, Table::varchar));

	String alcohol;
	getline( myfile, alcohol, ',' );
    columns.push_back(make_pair(alcohol, Table::varchar));

	String smoking_area;
	getline( myfile, smoking_area, ',' );
    columns.push_back(make_pair(smoking_area, Table::varchar));

	String dress_code;
	getline( myfile, dress_code, ',' );
    columns.push_back(make_pair(dress_code, Table::varchar));

	String accessibility;
	getline( myfile, accessibility, ',' );
    columns.push_back(make_pair(accessibility, Table::varchar));

	String price;
	getline( myfile, price, ',' );
    columns.push_back(make_pair(price, Table::varchar));

	String url;
	getline( myfile, url, ',' );
    columns.push_back(make_pair(url, Table::varchar));

	String Rambience;
	getline( myfile, Rambience, ',' );
    columns.push_back(make_pair(Rambience, Table::varchar));

	String franchise;
	getline( myfile, franchise, ',' );
    columns.push_back(make_pair(franchise, Table::varchar));

	String area;
	getline( myfile, area, ',' );
    columns.push_back(make_pair(area, Table::varchar));

	String other_services;
	getline( myfile, other_services, '\n' );
    columns.push_back(make_pair(other_services, Table::varchar));

	

	Table* geo = new Table(columns); // Create geo using the defined columns
	


    while ( myfile.good() )
    {
	  vector<pair<string, string> > entries; // Entries for the record to be placed in the table
	  
	  string placeID;
	  getline( myfile, placeID, ',' );
	  pair <string,string> pair0  ("placeID",placeID);   // value init
	  entries.push_back(pair0);

	  string latitude;
	  getline( myfile, latitude, ',' );
	  pair <string,string> pair1  ("latitude",latitude);   // value init
	  entries.push_back(pair1);

	  string longitude;
	  getline( myfile, longitude, ',' );
	  pair <string,string> pair2  ("longitude",longitude);   // value init
	  entries.push_back(pair2);

	  string the_geom_meter;
	  getline( myfile, the_geom_meter, ',' );
	  pair <string,string> pair3  ("the_geom_meter",the_geom_meter);   // value init
	  entries.push_back(pair3);

	  string name;
	  getline( myfile, name, ',' );
	  pair <string,string> pair4  ("name",name);   // value init
	  entries.push_back(pair4);

	  string address;
	  getline( myfile, address, ',' );
	  pair <string,string> pair5  ("address",address);   // value init
	  entries.push_back(pair5);

	  string city;
	  getline( myfile, city, ',' );
	  pair <string,string> pair6  ("city",city);   // value init
	  entries.push_back(pair6);

	  string state;
	  getline( myfile, state, ',' );
	  pair <string,string> pair7  ("state",state);   // value init
	  entries.push_back(pair7);

	  string country;
	  getline( myfile, country, ',' );
	  pair <string,string> pair8  ("country",country);   // value init
	  entries.push_back(pair8);

	  string fax;
	  getline( myfile, fax, ',' );
	  pair <string,string> pair9  ("fax",fax);   // value init
	  entries.push_back(pair9);

	  string zip;
	  getline( myfile, zip, ',' );
	  pair <string,string> pair10  ("zip",zip);   // value init
	  entries.push_back(pair10);

	  string alcohol;
	  getline( myfile, alcohol, ',' );
	  pair <string,string> pair11  ("alcohol",alcohol);   // value init
	  entries.push_back(pair11);

	  string smoking_area;
	  getline( myfile, smoking_area, ',' );
	  pair <string,string> pair12  ("smoking_area",smoking_area);   // value init
	  entries.push_back(pair12);

	  string dress_code;
	  getline( myfile, dress_code, ',' );
	  pair <string,string> pair13  ("dress_code",dress_code);   // value init
	  entries.push_back(pair13);

	  string accessibility;
	  getline( myfile, accessibility, ',' );
	  pair <string,string> pair14  ("accessibility",accessibility);   // value init
	  entries.push_back(pair14);

	  string price;
	  getline( myfile, price, ',' );
	  pair <string,string> pair15 ("price",price);   // value init
	  entries.push_back(pair15);

	  string url;
	  getline( myfile, url, ',' );
	  pair <string,string> pair16  ("url",url);   // value init
	  entries.push_back(pair16);

	  string Rambience;
	  getline( myfile, Rambience, ',' );
	  pair <string,string> pair17  ("Rambience",Rambience);   // value init
	  entries.push_back(pair17);

	  string franchise;
	  getline( myfile, franchise, ',' );
	  pair <string,string> pair18  ("franchise",franchise);   // value init
	  entries.push_back(pair18);

	  string area;
	  getline( myfile, area, ',' );
	  pair <string,string> pair19  ("area",area);   // value init
	  entries.push_back(pair19);

	  string other_services;
	  getline( myfile, other_services, '\n' );
	  pair <string,string> pair20  ("other_services",other_services);   // value init
	  entries.push_back(pair20);

	  Record add(entries); // Create record to add to table

	  geo->insert(add);  // Insert add record into geo
	  
	}
    
	myfile.close();
	return geo;

  }

}

Table* read_from_rating_final() {

  ifstream myfile ("rating_final.csv");
  if (myfile.is_open())
  {

	Table::ColumnList columns;

	String placeID;
	getline( myfile, placeID, ',' );
    columns.push_back(make_pair(placeID, Table::varchar));

	String latitude;
	getline( myfile, latitude, ',' );
	columns.push_back(make_pair(latitude, Table::integer));

	String longitude;
	getline( myfile, longitude, ',' );
	columns.push_back(make_pair(longitude, Table::integer));

	String the_geom_meter;
	getline( myfile, the_geom_meter, ',' );
	columns.push_back(make_pair(the_geom_meter, Table::integer));

	String name;
	getline( myfile, name, '\n' );
    columns.push_back(make_pair(name, Table::integer));


	Table* geo = new Table(columns); // Create geo using the defined columns
	


    while ( myfile.good() )
    {
	  vector<pair<string, string> > entries; // Entries for the record to be placed in the table
	  
	  string placeID;
	  getline( myfile, placeID, ',' );
	  pair <string,string> pair0  ("userID",placeID);   // value init
	  entries.push_back(pair0);

	  string latitude;
	  getline( myfile, latitude, ',' );
	  pair <string,string> pair1  ("placeID",latitude);   // value init
	  entries.push_back(pair1);

	  string longitude;
	  getline( myfile, longitude, ',' );
	  pair <string,string> pair2  ("rating",longitude);   // value init
	  entries.push_back(pair2);

	  string the_geom_meter;
	  getline( myfile, the_geom_meter, ',' );
	  pair <string,string> pair3  ("food_rating",the_geom_meter);   // value init
	  entries.push_back(pair3);

	  string name;
	  getline( myfile, name, '\n' );
	  pair <string,string> pair4  ("service_rating",name);   // value init
	  entries.push_back(pair4);


	  Record add(entries); // Create record to add to table

	  geo->insert(add); // Insert add record into geo
	  
	}
    myfile.close();
	return geo;
  }
}



int main() {
	
	Database mainDB;

	

	Table* rating_final = read_from_rating_final();
	Table* geoplaces2 = read_from_geoplaces2();

	mainDB.add_table("rating_final",rating_final);
	mainDB.add_table("geoplaces2", geoplaces2);


	/* This for loop prints the table, but not from the database. 
	This should be deleted. It's just for demonstration
	*/
	for( int i=0; i < rating_final->size(); i++ ) {

		Record print = rating_final->at(i);

		cout << print.get<string>("userID")<< ", ";
		cout << print.get<int>("placeID")<< ", ";
		cout << print.get<int>("rating")<< ", ";
		cout << print.get<int>("food_rating")<< ", ";
		cout << print.get<int>("service_rating");
		cout<<"\n\n";

	}

	
	keep_window_open();

}