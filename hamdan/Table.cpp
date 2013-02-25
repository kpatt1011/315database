

#include "Table.h"
//#include "Record.h"
#include <iostream>
#include <String>
#include <vector>
#include <list>
#include <map>
#include <sstream>  
#include "std_lib_facilities.h"

using namespace std;

//Non- parameter constructor
Table::Table()
{    
	Key = "NULL";
	Row;
	Column_Attributes ="NULL";
   
}

//Constructor with parameters
Table::Table (map< String, String > attributes)
{
	
	Key = "NULL";
	Row;
	int count = 0;
	if (attributes.size() == 0)	{Column_Attributes = "NULL";}
	else 
	{   Column_Attributes = "(";
	 for(map<String, String>::iterator it = attributes.begin(); it != attributes.end(); ++it) 
	 {      
             Column_Attributes += it->second; 
		     Column_Attributes +=" ";
			 Column_Attributes += it->first;
             
			 
		     count++;
			 if (count !=attributes.size()) {Column_Attributes +="," ;}                            
	}
	         Column_Attributes +=")"; 
	}
   
}

void Table::insert_row (Record row)
{
	// IF Table is empty i. e No columns than no tuple can be stored. 
	// Columns have to be made first in order to fill them with values
	if (Column_Attributes == "NULL")
	{ cout<<"ERROR - FIRST UPDATE COLUMNS THAN TUPLES"<<endl;
	}
	
	// Throw Error in case users tries to input value containing incorrect dimensions 
	// AT all times, Table will have Square Dimensions
	else if (row.get_size() != Column_size() )
	{cout<<"ERROR - INCORRECT DIMENSIONS"<<endl;}

	else 
	{
	  Row.push_back(row);
	}
}


void Table::add_column (String name, String t)
	{
	    //CASE 1 = if table is empty . So inserting First column
		 if (Column_Attributes == "NULL") 
		 {
		    Column_Attributes = "(" + t + " " + name + ")";
		 // If column is empty then append the column with the type and name of the First Attribute

		 }
	
	 // CASE 2 = THERE are already Existing Columns 
		 else
		 {           //CASE 2 (A) = NO TUPLES ARE PRESENT IN THE DATABASE
		          int Temp = Column_Attributes.length() - 1; // Temp to store last character of the column
				   	
					if (Row.size() == 0)
				  {
				     if (Column_Attributes[Temp] == ')')
					 {  
					   Column_Attributes[Temp] = ',';
					   Column_Attributes += t + ' ' + name + ')';
					 }
				  }
		 
		      //CASE 2(B) - IF THERE ARE TUPLES AS WELL THEN WE NEED TO PUT NULL IN EVERY TUPLE ENTRY FOR THE NEW COLUMN
					else if (Row.size() > 0)
					{
					   //APPEND COLUMN 
					 if (Column_Attributes[Temp] == ')')
					 {  
					   Column_Attributes[Temp] = ',';
					   Column_Attributes += t + ' ' + name + ')';
					 } 
					
					 int RowLength = Row.size();
					vector<String> s;
					for (int i=0; i < RowLength;i++)
					 {   //Temporary recrod to hold and modify tuple from the list
					     
						 Record R_Temp(s); R_Temp= Row.front();
						 Row.pop_front();
					     int R_Temp_Size = R_Temp.get_size(); 
						 R_Temp.replace_entry(R_Temp_Size, "NULL");	  
					     Row.push_back(R_Temp);
					}

					}
		 
		 }
	
	}


int Table::Column_size()
{   //Columns will be of the format (Attribute 1, Attribute 2, Attribute 3 , ... , Attribut n) 
	//Comma's will separate one attribute from the other

	int size = 0;
	//Function that Calculates the total Number of Columns
	
	//Return zero in case Table is Empty
	if (Column_Attributes == "NULL") 
	{  return size ;
	} 

	//Count Total Columns
	else 
	{        size = 1;
	 	//Intialize size to 1 as there is atleast one attribute in the column
		for (int i=0 ; i<Column_Attributes.length(); i++)
		{   //Comma is an attribute separator. Hence for every ',' encountered increase the attribute size

			if (Column_Attributes[i]== ',') {size++;}
		}
	}

    return size;

}

int Table::get_size ()
{
	return Row.size();
}

Record Table::get_record_at(int index)
{   // Dealing with NEGATIVE INDEX OR OUT OF BOUND INDEX
	if ((index < 0) || (index >= Row.size())) 
	{  cout<<"INDEX OUT OF BOUND" <<endl;
	}

	else
	{    vector<String> vTemp;
		Record Iterator(vTemp), TargetValue(vTemp);
		for (int i=0; i<Row.size() ; i++)
		{
		     Iterator = Row.front();
			 Row.pop_front();
			 if (i == index) TargetValue = Iterator;
			 Row.push_back(Iterator);
		}
		return TargetValue;
	}

}

void Table::rename_column (String name1, String name2)
{
     int Name1Postion;   
	 //Position of attribute name to be replaced;
	 Name1Postion = Column_Attributes.find(name1);
	 
	 int LengthofName1= name1.length();
	 //Total length of attribute to be replaced
	 int RemainderStringPosition = Name1Postion + LengthofName1;
     // Total length of attribute name1
	 
     
	 String BeforeName1, AfterName1;
	 AfterName1 = Column_Attributes.substr(RemainderStringPosition);
	 //Column after name 1
	 
	 for (int i = 0 ; i < Name1Postion ; i++)
	 {BeforeName1 += Column_Attributes[i];}
       // Getting Column Before Name1   
	 Column_Attributes = BeforeName1 + name2 + AfterName1;
       //Make new column by Joining Previous Column before the name1 String with new attribute name2
	   // and previously remainder of the String after name1
}

void 	Table::delete_column (String name)
{
	/*   ALGORITHM :
	    1- GET COLUMN POSITION
		2- MODIFY THE ATTRIBUTES TO REMOVE THE COLUMN
		3- MODIFY THE ROWS TO REMOVE ENTRIES AT THAT POSITION
	   */
        int NamePostion;   
	 //Position of attribute name to be deleted
	 NamePostion =	Column_Attributes.find(name);
	 
	 int LengthofName= name.length();
	 //Total length of attribute to be deleted
	 int RemainderStringPosition = NamePostion + LengthofName;
     // Total length of attribute name
	 
     
	 String BeforeName, AfterName;
	 int start = 0;
	 for (int i = NamePostion; i>=0 ; i--)
	 {
	    if ((Column_Attributes[i] == ',') || (Column_Attributes[i] == '('))
		{  start = i;
		   break;
		}
	 }

	 for (int i =0 ; i<=start ; i++)
	 {
	   BeforeName += Column_Attributes[i]; 
	 }
	 
	 
	 AfterName = Column_Attributes.substr(RemainderStringPosition+1);
    
	 int ColumnNumber = 0;
	 for (int i =0 ; i<=start; i++)
	 {
	     if (Column_Attributes[i] == ',')  ColumnNumber++;
	 }

	
	 vector<String>s;
	 Record Temp(s);
	 //Deleting the Column
	 //Deleting the value in rows of that particular column
	 for (int i =0; i<Row.size() ; i++)
	 {
	     Temp = Row.front();
		 Row.pop_front();
		 Temp.DELETE(ColumnNumber);
		 Row.push_back(Temp);
	 }
	 
	Column_Attributes = BeforeName + AfterName;
}


void Table::Print()
{   
	vector<String> t;
	cout<<Column_Attributes<<endl;
    Record Temp(t);
	for (int i=0; i<Row.size() ; i++)
	{
	     Temp = Row.front();
		 cout<<"( ";
		 for (int j=0; j<Temp.get_size(); j++)
		 {
		  cout<<Temp.get_entry(j);
		  if (j!= Temp.get_size()-1) cout<<" ,";
		 }
		 cout<<" ) " <<endl;
		 Row.pop_front();
		 Row.push_back(Temp);
	}
}

//Wrapper Cross Join Function
Table Table::cross_join (Table a, Table b)
{
	if (a.get_size() < b.get_size())
	 return Cross(b,a);
	else return Cross(a,b);
}

Table Table::Cross(Table a, Table b)
{     //Initialize Table c;
	  map<String, String> m;
      Table c(m);
	  //Adding all of Table A columns in Table C
       for (int i = 0 ; i<a.Column_size(); i++)
	   { 
		   // c.add_column(a.getcolumn());
	     
	   }

	    //Adding all of Table B columns in Table C
       for (int i = 0 ; i<a.Column_size(); i++)
	   { 
		   // c.add_column(b.getcolumn());
	     
	   }


	   return c;
}

int Table::entry_sum (String column_name)
{
       double sum = 0.00;
		// Position of attribute to sum
        int Postion =	Column_Attributes.find(column_name);

		// Finding the number of appropriate column
		int ColumnNumber = 0;
		for (int i = 0 ; i<=Postion; i++)
		{
		  if (Column_Attributes[i] == ',') ColumnNumber++;
		}
     
		// Traversing through the rows
		vector<String> v;
		Record Temp(v);
		String convert;
		for (int i = 0; i<Row.size() ; i++)
		{   
		   Temp = Row.front();
		   if (Temp.get_entry(ColumnNumber) != "NULL") {convert =(Temp.get_entry(ColumnNumber)); sum += atof(convert.c_str());}
		   Row.pop_front();
		   Row.push_back(Temp);
		}
		return sum;
}


int Table::entry_count (String column_name)
{
	    int count = 0;
		// Position of attribute to count
        int Postion =	Column_Attributes.find(column_name);

		// Finding the number of appropriate column
		int ColumnNumber = 0;
		for (int i = 0 ; i<=Postion; i++)
		{
		  if (Column_Attributes[i] == ',') ColumnNumber++;
		}
     
		// Traversing through the rows
		vector<String> v;
		Record Temp(v);
		
		for (int i = 0; i<Row.size() ; i++)
		{   
		   Temp = Row.front();
		   if (Temp.get_entry(ColumnNumber) != "NULL") {count++;}
		   Row.pop_front();
		   Row.push_back(Temp);
		}
		return count;
}


String 	Table::entry_min (String column_name)
{
	double Min = 9999.9999; // Sentinel Value
	bool  Min_Exist = false; //In case if all entries are NULL
		// Position of attribute to find min of
        int Postion =	Column_Attributes.find(column_name);

		// Finding the number of appropriate column
		int ColumnNumber = 0;
		for (int i = 0 ; i<=Postion; i++)
		{
		  if (Column_Attributes[i] == ',') ColumnNumber++;
		}
     
		// Traversing through the rows
		vector<String> v;
		Record Temp(v);
		String convert;
		for (int i = 0; i<Row.size() ; i++)
		{   
		   Temp = Row.front();
		   if (Temp.get_entry(ColumnNumber) != "NULL") 
		   {
		   Min_Exist = true;
		   convert =(Temp.get_entry(ColumnNumber)); 
		  if (Min > atof(convert.c_str())) Min =  atof(convert.c_str());
		   }
		   
		   Row.pop_front();
		   Row.push_back(Temp);
		}
		
		if (Min_Exist == true)	 {stringstream s; s<< Min; return s.str();}
	else cout<<"NO MINIMUM EXIST"<<endl;
}

String 	Table::entry_max (String column_name)
{
	double Max = -999999.9999; // Sentinel Value
	bool  Max_Exist = false; //In case if all entries are NULL
		// Position of attribute to find max of
        int Postion =	Column_Attributes.find(column_name);

		// Finding the number of appropriate column
		int ColumnNumber = 0;
		for (int i = 0 ; i<=Postion; i++)
		{
		  if (Column_Attributes[i] == ',') ColumnNumber++;
		}
     
		// Traversing through the rows
		vector<String> v;
		Record Temp(v);
		String convert;
		for (int i = 0; i<Row.size() ; i++)
		{   
		   Temp = Row.front();
		   if (Temp.get_entry(ColumnNumber) != "NULL") 
		   {
		   Max_Exist = true;
		   convert =(Temp.get_entry(ColumnNumber)); 
		  if (Max < atof(convert.c_str())) Max =  atof(convert.c_str());
		   }
		   
		   Row.pop_front();
		   Row.push_back(Temp);
		}
		
	if (Max_Exist == true)	 {stringstream s; s<< Max; return s.str();}
	else cout<<"NO MINIMUM EXIST"<<endl;
}