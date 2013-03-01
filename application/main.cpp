#include "database.h"
#include "record.h"
#include "table.h"
#include "exception.h"
#include "std_lib_facilities.h"


Table read_from_geoplaces2() {


  
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

    columns.push_back(make_pair("placeID", Table::integer));
    columns.push_back(make_pair("latitude", Table::floating));
    columns.push_back(make_pair("longitude", Table::floating));
    columns.push_back(make_pair("the_geom_meter", Table::varchar));
    columns.push_back(make_pair("name", Table::varchar));
    columns.push_back(make_pair("address", Table::varchar));
    columns.push_back(make_pair("city", Table::varchar));
	columns.push_back(make_pair("state", Table::varchar));
	columns.push_back(make_pair("country", Table::varchar));
	columns.push_back(make_pair("fax", Table::varchar));
	columns.push_back(make_pair("zip", Table::varchar));
	columns.push_back(make_pair("alcohol", Table::varchar));
	columns.push_back(make_pair("smoking_area", Table::varchar));
	columns.push_back(make_pair("dress_code", Table::varchar));
	columns.push_back(make_pair("accessibility", Table::varchar));
	columns.push_back(make_pair("price", Table::varchar));
	columns.push_back(make_pair("url", Table::varchar));
    columns.push_back(make_pair("Rambience", Table::varchar));
	columns.push_back(make_pair("franchise", Table::varchar));
	columns.push_back(make_pair("area", Table::varchar));
	columns.push_back(make_pair("other_services", Table::varchar));

	Table geo (columns); // Create geo using the defined columns
	


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

	  geo.insert(add); // Insert add record into geo
	  
	}
    myfile.close();
	return geo;
  }

 

}



int main() {
	
	Database a ();
	Table test = read_from_geoplaces2();

	for(int i=0; i <test.size(); i++) {
		Record print = test.at(i);
		cout << print.get<int>("placeID")<< ", ";
		cout << print.get<double>("latitude")<< ", ";
		cout << print.get<double>("longitude")<< ", ";
		cout << print.get<string>("the_geom_meter")<< ", ";
		cout << print.get<string>("name")<< ", ";
		cout << print.get<string>("address")<< ", ";
		cout << print.get<string>("city")<< ", ";
		cout << print.get<string>("state")<< ", ";
		cout << print.get<string>("country")<< ", ";
		cout << print.get<string>("fax")<< ", ";
		cout << print.get<string>("zip")<< ", ";
		cout << print.get<string>("alcohol")<< ", ";
		cout << print.get<string>("smoking_area")<< ", ";
		cout << print.get<string>("dress_code")<< ", ";
		cout << print.get<string>("accessibility")<< ", ";
		cout << print.get<string>("price")<< ", ";
		cout << print.get<string>("url")<< ", ";
		cout << print.get<string>("Rambience")<< ", ";
		cout << print.get<string>("franchise")<< ", ";
		cout << print.get<string>("area")<< ", ";
		cout << print.get<string>("other_services")<< ", ";
	}
	
	
	keep_window_open();
}