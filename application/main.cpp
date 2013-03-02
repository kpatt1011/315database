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

Table* read_from_userprofile() {
	ifstream myfile ("userprofile.csv");
  if (myfile.is_open())
  {

	Table::ColumnList columns;

	String userID;
	getline( myfile, userID, ',' );
    columns.push_back(make_pair(userID, Table::varchar));

	String latitude;
	getline( myfile, latitude, ',' );
	columns.push_back(make_pair(latitude, Table::floating));

	String longitude;
	getline( myfile, longitude, ',' );
	columns.push_back(make_pair(longitude, Table::integer));

	String smoker;
	getline( myfile, smoker, ',');
    columns.push_back(make_pair(smoker, Table::varchar));

	String drink_level;
	getline( myfile, drink_level, ',');
    columns.push_back(make_pair(drink_level, Table::varchar));

	String dress_preference;
	getline( myfile, dress_preference, ',' );
    columns.push_back(make_pair(dress_preference, Table::varchar));

	String ambience;
	getline( myfile, ambience, ',' );
    columns.push_back(make_pair(ambience, Table::varchar));

	String transport;
	getline( myfile, transport, ',' );
    columns.push_back(make_pair(transport, Table::varchar));

	String marital_status;
	getline( myfile, marital_status, ',' );
    columns.push_back(make_pair(marital_status, Table::varchar));

	String hijos;
	getline( myfile, hijos, ',');
    columns.push_back(make_pair(hijos, Table::varchar));

	String birth_year;
	getline( myfile, birth_year, ',' );
    columns.push_back(make_pair(birth_year, Table::integer));

		String interest;
	getline( myfile, interest, ',' );
    columns.push_back(make_pair(interest, Table::varchar));

		String personality;
	getline( myfile, personality, ',' );
    columns.push_back(make_pair(personality, Table::varchar));

		String religion;
	getline( myfile, religion, ',' );
    columns.push_back(make_pair(religion, Table::varchar));

		String activity;
	getline( myfile, activity, ',' );
    columns.push_back(make_pair(activity, Table::varchar));

		String color;
	getline( myfile, color, ',' );
    columns.push_back(make_pair(color, Table::varchar));

		String weight;
	getline( myfile, weight, ',' );
    columns.push_back(make_pair(weight, Table::integer));

		String budget;
	getline( myfile, budget, ',' );
    columns.push_back(make_pair(budget, Table::varchar));

		String height;
	getline( myfile, height, '\n' );
	columns.push_back(make_pair(height, Table::floating));


	Table* geo = new Table(columns); // Create geo using the defined columns
	


    while ( myfile.good() )
    {

	  vector<pair<string, string> > entries; // Entries for the record to be placed in the table
	  
	  string userID;
	  getline( myfile, userID, ',' );
	  pair <string,string> pair0  ("userID",userID);   // value init
	  entries.push_back(pair0);

	  string latitude;
	  getline( myfile, latitude, ',' );
	  pair <string,string> pair1  ("latitude",latitude);   // value init
	  entries.push_back(pair1);

	  string longitude;
	  getline( myfile, longitude, ',' );
	  pair <string,string> pair2  ("longitude",longitude);   // value init
	  entries.push_back(pair2);

	  string smoker;
	  getline( myfile, smoker, ',' );
	  pair <string,string> pair3  ("smoker",smoker);   // value init
	  entries.push_back(pair3);

	  string drink_level;
	  getline( myfile, drink_level, ',' );
	  pair <string,string> pair4  ("drink_level",drink_level);   // value init
	  entries.push_back(pair4);

	  string dress_preference;
	  getline( myfile, dress_preference, ',' );
	  pair <string,string> pair5  ("dress_preference",dress_preference);   // value init
	  entries.push_back(pair5);

	  string ambience;
	  getline( myfile, ambience, ',' );
	  pair <string,string> pair6  ("ambience",ambience);   // value init
	  entries.push_back(pair6);

	  string transport;
	  getline( myfile, transport, ',' );
	  pair <string,string> pair7  ("transport",transport);   // value init
	  entries.push_back(pair7);

	  string marital_status;
	  getline( myfile, marital_status, ',' );
	  pair <string,string> pair8  ("marital_status",marital_status);   // value init
	  entries.push_back(pair8);

	  string hijos;
	  getline( myfile, hijos, ',' );
	  pair <string,string> pair9  ("hijos",hijos);   // value init
	  entries.push_back(pair9);

	  string birth_year;
	  getline( myfile, birth_year, ',' );
	  pair <string,string> pair10  ("birth_year",birth_year);   // value init
	  entries.push_back(pair10);

	  string interest;
	  getline( myfile, interest, ',' );
	  pair <string,string> pair11  ("interest",interest);   // value init
	  entries.push_back(pair11);

	  string personality;
	  getline( myfile, personality, ',' );
	  pair <string,string> pair12  ("personality",personality);   // value init
	  entries.push_back(pair12);

	  string religion;
	  getline( myfile, religion, ',' );
	  pair <string,string> pair13  ("religion",religion);   // value init
	  entries.push_back(pair13);

	  string activity;
	  getline( myfile, activity, ',' );
	  pair <string,string> pair14  ("activity",activity);   // value init
	  entries.push_back(pair14);

	  string color;
	  getline( myfile, color, ',' );
	  pair <string,string> pair15 ("color",color);   // value init
	  entries.push_back(pair15);

	  string weight;
	  getline( myfile, weight, ',' );
	  pair <string,string> pair16  ("weight",weight);   // value init
	  entries.push_back(pair16);

	  string budget;
	  getline( myfile, budget, ',' );
	  pair <string,string> pair17  ("budget",budget);   // value init
	  entries.push_back(pair17);

	  string height;
	  getline( myfile, height, '\n' );
	  pair <string,string> pair18  ("height",height);   // value init
	  entries.push_back(pair18);



	  Record add(entries); // Create record to add to table

	  geo->insert(add); // Insert add record into geo
	  
	}
    myfile.close();
	return geo;
  }
}

Table* read_from_chefmozaccepts() {
	 ifstream myfile ("chefmozaccepts.csv");
  if (myfile.is_open())
  {

	Table::ColumnList columns;

	String placeID;
	getline( myfile, placeID, ',' );
    columns.push_back(make_pair(placeID, Table::integer));

	String Rpayment;
	getline( myfile, Rpayment, '\n' );
	columns.push_back(make_pair(Rpayment, Table::varchar));


	Table* geo = new Table(columns); // Create geo using the defined columns
	


    while ( myfile.good() )
    {
	  vector<pair<string, string> > entries; // Entries for the record to be placed in the table
	  
	  string placeID;
	  getline( myfile, placeID, ',' );
	  pair <string,string> pair0  ("placeID",placeID);   // value init
	  entries.push_back(pair0);

	  string Rpayment;
	  getline( myfile, Rpayment, '\n' );
	  pair <string,string> pair1  ("Rpayment",Rpayment);   // value init
	  entries.push_back(pair1);


	  Record add(entries); // Create record to add to table

	  geo->insert(add); // Insert add record into geo
	  
	}
    myfile.close();
	return geo;
  }
} 

Table* read_from_chefmozcuisine() {
	 ifstream myfile ("chefmozcuisine.csv");
  if (myfile.is_open())
  {

	Table::ColumnList columns;

	String placeID;
	getline( myfile, placeID, ',' );
    columns.push_back(make_pair(placeID, Table::integer));

	String Rcuisine;
	getline( myfile, Rcuisine, '\n' );
	columns.push_back(make_pair(Rcuisine, Table::varchar));


	Table* geo = new Table(columns); // Create geo using the defined columns
	


    while ( myfile.good() )
    {
	  vector<pair<string, string> > entries; // Entries for the record to be placed in the table
	  
	  string placeID;
	  getline( myfile, placeID, ',' );
	  pair <string,string> pair0  ("placeID",placeID);   // value init
	  entries.push_back(pair0);

	  string Rcuisine;
	  getline( myfile, Rcuisine, '\n' );
	  pair <string,string> pair1  ("Rcuisine",Rcuisine);   // value init
	  entries.push_back(pair1);


	  Record add(entries); // Create record to add to table

	  geo->insert(add); // Insert add record into geo
	  
	}
    myfile.close();
	return geo;
  }
}

Table* read_from_chefmozparking() {
	
	ifstream myfile ("chefmozparking.csv");

  if (myfile.is_open())
  {

	Table::ColumnList columns;

	String placeID;
	getline( myfile, placeID, ',' );
    columns.push_back(make_pair(placeID, Table::integer));

	String parking_lot;
	getline( myfile, parking_lot, '\n' );
	columns.push_back(make_pair(parking_lot, Table::varchar));


	Table* geo = new Table(columns); // Create geo using the defined columns
	


    while ( myfile.good() )
    {
	  vector<pair<string, string> > entries; // Entries for the record to be placed in the table
	  
	  string placeID;
	  getline( myfile, placeID, ',' );
	  pair <string,string> pair0  ("placeID",placeID);   // value init
	  entries.push_back(pair0);

	  string parking_lot;
	  getline( myfile, parking_lot, '\n' );
	  pair <string,string> pair1  ("parking_lot",parking_lot);   // value init
	  entries.push_back(pair1);


	  Record add(entries); // Create record to add to table

	  geo->insert(add); // Insert add record into geo
	  
	}
    myfile.close();
	return geo;
  }
}

Table* read_from_userpayment() {
	
	ifstream myfile ("userpayment.csv");

  if (myfile.is_open())
  {

	Table::ColumnList columns;

	String userID;
	getline( myfile, userID, ',' );
    columns.push_back(make_pair(userID, Table::varchar));

	String Upayment;
	getline( myfile, Upayment, '\n' );
	columns.push_back(make_pair(Upayment, Table::varchar));


	Table* geo = new Table(columns); // Create geo using the defined columns
	


    while ( myfile.good() )
    {
	  vector<pair<string, string> > entries; // Entries for the record to be placed in the table
	  
	  string userID;
	  getline( myfile, userID, ',' );
	  pair <string,string> pair0  ("userID",userID);   // value init
	  entries.push_back(pair0);

	  string Upayment;
	  getline( myfile, Upayment, '\n' );
	  pair <string,string> pair1  ("Upayment",Upayment);   // value init
	  entries.push_back(pair1);


	  Record add(entries); // Create record to add to table

	  geo->insert(add); // Insert add record into geo
	  
	}
    myfile.close();
	return geo;
  }
}

Table* read_from_usercuisine() {
	
	ifstream myfile ("usercuisine.csv");

  if (myfile.is_open())
  {

	Table::ColumnList columns;

	String userID;
	getline( myfile, userID, ',' );
    columns.push_back(make_pair(userID, Table::varchar));

	String Rcuisine;
	getline( myfile, Rcuisine, '\n' );
	columns.push_back(make_pair(Rcuisine, Table::varchar));


	Table* geo = new Table(columns); // Create geo using the defined columns
	


    while ( myfile.good() )
    {
	  vector<pair<string, string> > entries; // Entries for the record to be placed in the table
	  
	  string userID;
	  getline( myfile, userID, ',' );
	  pair <string,string> pair0  ("userID",userID);   // value init
	  entries.push_back(pair0);

	  string Rcuisine;
	  getline( myfile, Rcuisine, '\n' );
	  pair <string,string> pair1  ("Rcuisine",Rcuisine);   // value init
	  entries.push_back(pair1);


	  Record add(entries); // Create record to add to table

	  geo->insert(add); // Insert add record into geo
	  
	}
    myfile.close();
	return geo;
  }
}

Table* read_from_chefmozhours4() {

	ifstream myfile ("chefmozhours4.csv");

  if (myfile.is_open())
  {

	Table::ColumnList columns;

	String placeID;
	getline( myfile, placeID, ',' );
    columns.push_back(make_pair(placeID, Table::varchar));

	String hours;
	getline( myfile, hours, ',' );
	columns.push_back(make_pair(hours, Table::varchar));

	String days;
	getline( myfile, days, '\n' );
	columns.push_back(make_pair(days, Table::varchar));


	Table* geo = new Table(columns); // Create geo using the defined columns
	


    while ( myfile.good() )
    {
	  vector<pair<string, string> > entries; // Entries for the record to be placed in the table
	  
	  string placeID;
	  getline( myfile, placeID, ',' );
	  pair <string,string> pair0  ("placeID",placeID);   // value init
	  entries.push_back(pair0);

	  string hours;
	  getline( myfile, hours, ',' );
	  pair <string,string> pair1  ("hours",hours);   // value init
	  entries.push_back(pair1);

	  string days;
	  getline( myfile, days, '\n' );
	  pair <string,string> pair2  ("days",days);   // value init
	  entries.push_back(pair2);


	  Record add(entries); // Create record to add to table

	  geo->insert(add); // Insert add record into geo
	  
	}
    myfile.close();
	return geo;
  }
}


int main() {
	
	Database mainDB;

	
	/* Create new Tables from all the input csv file */
	Table* rating_final = read_from_rating_final();
	Table* geoplaces2 = read_from_geoplaces2();
	Table* userprofile = read_from_userprofile();
	Table* chefmozaccepts = read_from_chefmozaccepts();
	Table* chefmozcuisine = read_from_chefmozcuisine();
	Table* chefmozparking = read_from_chefmozparking();
	Table* userpayment = read_from_userpayment();
	Table* usercuisine = read_from_usercuisine();
	Table* chefmozhours4 = read_from_chefmozhours4();

	/* Add the newly created Tables to a database */
	mainDB.add_table("rating_final",rating_final);
	mainDB.add_table("geoplaces2", geoplaces2);
	mainDB.add_table("userprofile", userprofile);
	mainDB.add_table("chefmozaccepts", chefmozaccepts);
	mainDB.add_table("chefmozcuisine", chefmozcuisine);
	mainDB.add_table("chefmozparking", chefmozparking);
	mainDB.add_table("userpayment", userpayment);
	mainDB.add_table("usercuisine", usercuisine);
	mainDB.add_table("chefmozhours4", chefmozhours4);


	while (true)
	{

	
	string choice;
	cout<<"\t\t MENU"<<endl;
	cout<<"PRESS 1 TO GET LIST OF ALL NON-ALCOHOLIC RESTAURANTS"<<endl;
	cout<<"PRESS 2 GET ALL RESTAURANTS IN A COUNTRY"<<endl;
	cout<<"PRESS 3 TO GET INFORMATION ABOUT A USER"<<endl;
	cout<<"PRESS 4 TO GET USERS WHO ARE 1.7 FEET OR TALLER"<<endl;
	cout<<"PRESS 5 TO GET USERS WEIGHING MORE THAN 70 POUNDS"<<endl;
	cout<<"PRESS 6 TO GET CUSINE PREFERRED BY A USER"<<endl;
	cout<<"PRESS 7 TO GET USERS WHO ARE SENIOR CITIZENS"<<endl;
	cout<<"PRESS 8 TO GET USERS WHO PAY WITH CASH"<<endl;
	cout<<"PRESS 9 TO GET A USER'S MODE OF PAYMENT"<<endl;
	cout<<"PRESS 10 TO GET PROFESSION OF USER WITH HIGH BUDGET"<<endl;
	cout<<"PRESS 11 TO GET INFO. ABOUT SINGLE USERS"<<endl;
	cout<<"PRESS 12 TO GET RESTUARANTS WITH VALET PARKING"<<endl;
	cout<<"PRESS 13 TO GET RESTUARANTS WITH HIGHEST FOOD RATING"<<endl;
	cout<<"PRESS 14 TO PRINT RESTAURANTS THAT ACCEPTS VISA CREDIT CARD"<<endl;
	cout<<"PRESS 15 TO PRINT RESTAURANTS THAT ARE OPEN ON SUNDAY"<<endl;
	cout<<"PRESS Q TO QUIT"<<endl;
	cin>>choice;
	if (choice == "1") {
						    Table *query = mainDB.query("name","geoplaces2", "alcohol = 'No_Alcohol_Served'");  
	     	  
							cout<<"RESTAURANT NAME"<<endl<<endl;
							 for( int i=0; i < query->size(); i++ ) 
							 {
							 cout<<i+1<< " )";
							Record print = query->at(i);
		
							cout << print.get<string>("name")<< endl;
							 }
						}
    if (choice == "2") {			string CountryForRestaurant, Temp;
	                                cout<<"Enter Country Name Please"<<endl;
									cin>>CountryForRestaurant;
									cout<<endl;
									Temp = "country = '";
									Temp += CountryForRestaurant +"'";
									Table *query = mainDB.query("*","geoplaces2", Temp );  
	     
	  
									cout<<"NAME\t\tADRESS\t\tCITY\t\tSTATE"<<endl<<endl;
									for( int i=0; i < query->size(); i++ ) 
						{
									cout<<i+1<< " )";
									Record print = query->at(i);
		                            cout << print.get<string>("name");
									cout <<"\t"<< print.get<string>("address");
									cout <<"\t"<< print.get<string>("city");
								
									cout <<"\t"<< print.get<string>("state")<<endl;
									

						}
	
	}
	
	if (choice == "Q") {break;}
	
	if (choice == "3") {            string UserID, Temp;
	                                cout<<"Enter UserID Please"<<endl;
									cin>>UserID;
									cout<<endl;
									Temp = "userID = '";
									Temp += UserID +"'";
	
								Table *query = mainDB.query("*","userprofile", Temp );  

								cout<<"SMOKER\t DRINK_LEVEL\tDRESS\tAMBIENCE\tTRANSPORT\tSTATUS\tRELIGION"<<endl<<endl;
									for( int i=0; i < query->size(); i++ ) 
						{            
							        cout<<i+1<< " )";
									Record print = query->at(i);
									cout << print.get<string>("smoker");
									cout <<"\t"<< print.get<string>("drink_level");
									cout <<"\t"<< print.get<string>("dress_preference");
									cout <<"\t"<< print.get<string>("ambience");
									cout <<"\t"<< print.get<string>("transport");
									cout <<"\t"<< print.get<string>("marital_status");
									cout <<"\t"<< print.get<string>("religion")<<endl;
	                            
						}
	}
	
	 if (choice == "4") {           
	
								Table *query = mainDB.query("*","userprofile", "height >= 1.7" );  

								cout<<"USERID\tSMOKER\tDRESS\tAMBIENCE\tTRANSPORT\tSTATUS\tRELIGION"<<endl<<endl;
									for( int i=0; i < query->size(); i++ ) 
						{            
							        cout<<i+1<< " )";
									Record print = query->at(i);
									cout << print.get<string>("userID");
									cout <<"  "<< print.get<string>("smoker");
									
									cout <<"\t"<< print.get<string>("dress_preference");
									cout <<"\t"<< print.get<string>("ambience");
									cout <<"\t"<< print.get<string>("transport");
									cout <<"\t"<< print.get<string>("marital_status");
									cout <<"\t"<< print.get<string>("religion")<<endl;
	                            
						}
	}

	 if (choice == "5") {           
	
								Table *query = mainDB.query("*","userprofile", " weight > 70" );  

								cout<<"USERID\tSMOKER\tDRESS\tAMBIENCE\tTRANSPORT\tSTATUS\tRELIGION"<<endl<<endl;
									for( int i=0; i < query->size(); i++ ) 
						{            
							        cout<<i+1<< " )";
									Record print = query->at(i);
									cout << print.get<string>("userID");
									cout <<"  "<< print.get<string>("smoker");
									
									cout <<"\t"<< print.get<string>("dress_preference");
									cout <<"\t"<< print.get<string>("ambience");
									cout <<"\t"<< print.get<string>("transport");
									cout <<"\t"<< print.get<string>("marital_status");
									cout <<"\t"<< print.get<string>("religion")<<endl;
	                            
						}
	}

	 if (choice == "6") {            string UserID, Temp;
	                                cout<<"Enter UserID Please"<<endl;
									cin>>UserID;
									cout<<endl;
									Temp = "userID = '";
									Temp += UserID +"'";
	
								Table *query = mainDB.query("*","usercuisine", Temp );  

								cout<<"\t\tCUISINE"<<endl<<endl;
									for( int i=0; i < query->size(); i++ ) 
						{            
							        cout<<i+1<< " )";
									Record print = query->at(i);
									
									cout <<"\t"<< print.get<string>("Rcuisine")<<endl;
									
	                            
						}
	}

	 if (choice == "7") {           
	
								Table *query = mainDB.query("*","userprofile", " birth_year < 1950" );  

								cout<<"USERID\tSMOKER\tDRESS\tAMBIENCE\tTRANSPORT\tSTATUS\tRELIGION"<<endl<<endl;
									for( int i=0; i < query->size(); i++ ) 
						{            
							        cout<<i+1<< " )";
									Record print = query->at(i);
									cout << print.get<string>("userID");
									cout <<"  "<< print.get<string>("smoker");
									
									cout <<"\t"<< print.get<string>("dress_preference");
									cout <<"\t"<< print.get<string>("ambience");
									cout <<"\t"<< print.get<string>("transport");
									cout <<"\t"<< print.get<string>("marital_status");
									cout <<"\t"<< print.get<string>("religion")<<endl;
	                            
						}
	}

	 if (choice == "8") {           
	
								Table *query = mainDB.query("*","userpayment", " Upayment = 'cash'" );  

								cout<<"\t\tUSERID"<<endl<<endl;
									for( int i=0; i < query->size(); i++ ) 
						{            
							        cout<<i+1<< " )";
									Record print = query->at(i);
									cout <<"\t\t"<< print.get<string>("userID")<<endl;
									
	                            
						}
	}

	  if (choice == "9") {            string UserID, Temp;
	                                cout<<"Enter UserID Please"<<endl;
									cin>>UserID;
									cout<<endl;
									Temp = "userID = '";
									Temp += UserID +"'";
	
								Table *query = mainDB.query("*","userpayment", Temp );  

								cout<<"\t\tMODE OF PAYMENT"<<endl<<endl;
									for( int i=0; i < query->size(); i++ ) 
						{            
							        cout<<i+1<< " )";
									Record print = query->at(i);
									
									cout <<"\t"<< print.get<string>("Upayment")<<endl;
									
	                            
						}
	}

   if (choice == "10") {           
	
								Table *query = mainDB.query("*","userprofile", " budget = 'high'" );  

								cout<<"USERID\t\tPROFESSION"<<endl<<endl;
									for( int i=0; i < query->size(); i++ ) 
						{            
							        cout<<i+1<< " )";
									Record print = query->at(i);
									cout << print.get<string>("userID");
									cout <<"  "<< print.get<string>("activity")<<endl;
									
									
	                            
						}
	}

   if (choice == "11") {           
	
								Table *query = mainDB.query("*","userprofile", " marital_status = 'single'" );  

								cout<<"USERID\tWEIGHT\tHEIGHT\tPROFESSION\tINTEREST\tRELIGION"<<endl<<endl;
									for( int i=0; i < query->size(); i++ ) 
						{            
							        cout<<i+1<< " )";
									Record print = query->at(i);
									cout << print.get<string>("userID");
									cout <<"  "<< print.get<string>("weight");
									
									cout <<"\t"<< print.get<string>("height");
									cout <<"\t"<< print.get<string>("activity");
									cout <<"\t\t"<< print.get<string>("interest");
									
									cout <<"\t\t"<< print.get<string>("religion")<<endl;
	                            
						}
	}

    if (choice == "12") {           
	                            
							 
								Table *q2 = mainDB.query("*","chefmozparking", " parking_lot = 'valet parking'" );
							
								cout<<"NAME\tADDRESS\tCITY\tSTATE\tCOUNTRY"<<endl;	
								for( int i=0; i < q2->size(); i++ ) 
						{               Record print = q2->at(i);
									string ID;
								    ID = "placeID = '";
									ID += print.get<string>("placeID")+"'";
							      
									Table *q1 = mainDB.query("*","geoplaces2",ID); 
								     for (int j =0 ;j<q1->size(); j++)
									 { Record p1 = q1->at(j);
									   cout<<j+1<<" )"<<endl;
									   cout<< p1.get<string>("name");
									   cout<<"\t"<< p1.get<string>("address");
									   cout<<"\t"<< p1.get<string>("city");
									   cout<<"\t"<< p1.get<string>("state");
									   cout<<"\t"<< p1.get<string>("country")<<endl;
									 }
							  
						}
	}

	 if (choice == "13") {           
	                            
							 
								Table *q2 = mainDB.query("placeID","rating_final", " food_rating = '2'" );
							    int counter=0;
								cout<<"NAME\tADDRESS\tCITY\tSTATE\tCOUNTRY"<<endl;	
								for( int i=0; i < q2->size(); i++ ) 
						{               Record print = q2->at(i);
									string ID;
								    ID = "placeID = '";
									ID += print.get<string>("placeID")+"'";
							      
									Table *q1 = mainDB.query("*","geoplaces2",ID); 
								     for (int j =0 ;j<q1->size();counter++, j++)
									 { Record p1 = q1->at(j);
									   cout<<counter<<" )"<<endl;
									   cout<< p1.get<string>("name");
									   cout<<"\t"<< p1.get<string>("address");
									   cout<<"\t"<< p1.get<string>("city");
									   cout<<"\t"<< p1.get<string>("state");
									   cout<<"\t"<< p1.get<string>("country")<<endl;
									 }
							  
						}
	}

	 if (choice == "14") {           
	                            
							 
							 
								Table *q2 = mainDB.query("placeID","chefmozaccepts", " Rpayment = 'VISA'" );
							   int counter= 0;
								cout<<"NAME\tADDRESS\tCITY\tSTATE\tCOUNTRY"<<endl;	
								for( int i=0; i < q2->size(); i++ ) 
						{               Record print = q2->at(i);
									string ID;
								    ID = "placeID = '";
									ID += print.get<string>("placeID")+"'";
							      
									Table *q1 = mainDB.query("*","geoplaces2",ID); 
								     for (int j =0 ;j<q1->size();++counter, j++)
									 { Record p1 = q1->at(j);
									   cout<<counter<<" )"<<endl;
									   cout<< p1.get<string>("name");
									   cout<<"\t"<< p1.get<string>("address");
									   cout<<"\t"<< p1.get<string>("city");
									   cout<<"\t"<< p1.get<string>("state");
									   cout<<"\t"<< p1.get<string>("country")<<endl;
									 }
							  
						}
								
								

						                                  	
						
	}

	 if (choice == "15") {           
	                            
							 
							 
								Table *q2 = mainDB.query("placeID","chefmozhours4", " days = 'Sun;'" );
							   int counter= 0;
								cout<<"NAME\tADDRESS\tCITY\tSTATE\tCOUNTRY"<<endl;	
								for( int i=0; i < q2->size(); i++ ) 
						{               Record print = q2->at(i);
									string ID;
								    ID = "placeID = '";
									ID += print.get<string>("placeID")+"'";
							      
									Table *q1 = mainDB.query("*","geoplaces2",ID); 
								     for (int j =0 ;j<q1->size();++counter, j++)
									 { Record p1 = q1->at(j);
									   cout<<counter<<" )"<<endl;
									   cout<< p1.get<string>("name");
									   cout<<"\t"<< p1.get<string>("address");
									   cout<<"\t"<< p1.get<string>("city");
									   cout<<"\t"<< p1.get<string>("state");
									   cout<<"\t"<< p1.get<string>("country")<<endl;
									 }
							  
						}
								
								

						                                  	
						
	}


	}	


	
	keep_window_open();

}