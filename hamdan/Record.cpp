#include "Record.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

Record::Record(vector<string> tuple)
{      
          Tupel = tuple;	
}

string Record::get_entry(int index)
{
      
	// Throw Out of Bounds Exception 
	if (index >= Tupel.size())
	 {
	   cout<<" INDEX OUT OF BOUND"<<endl;        
	 }

	else
	{       
	     return Tupel[index];
	}
}

void Record::replace_entry(int index, string replacement)
{
	//IF JUST WANTS TO ADD NULL IN NEW COLUMN
    if ( index - Tupel.size() == 0)
	{
	   Tupel.push_back(replacement);
	}

	// Throw Out of Bounds Exception 
   else	if (index > Tupel.size())
	 {
	   cout<<" INDEX OUT OF BOUND"<<endl;        
	 }

	//Change the value of attribute at index position 
	else
	{       
	      Tupel[index] = replacement;
	}      

}

// Size of the Tuple
int Record::get_size()
{
   return Tupel.size();
}

//Empty Destructor
Record::~Record()
{}


void Record::Copy(Record R)

{    int length = R.get_size() -1 ;
	 string s;
	for (int i=0 ; i<length ; i++)
	{
	   s = R.get_entry(i);
	}
 
}

Record& Record::operator=( const Record & rhs)
{
	// CASE: SELF ASSIGNMENT
   if (this == &rhs)
   {return *this;}

   else
   {
        Tupel = rhs.Tupel;
   }
}

