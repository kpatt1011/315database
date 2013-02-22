#include "Record.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

Record::Record(vector<string> tuple)
{      
	// Intialize the Record with Tuple
	for (int i =0 ;i<tuple.size(); i++)

		{
			Tupel.push_back(tuple[i]);
		}
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
       
	// Throw Out of Bounds Exception 
	if (index >= Tupel.size())
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


