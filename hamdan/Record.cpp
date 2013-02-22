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
      

	if (index >= Tupel.size())
	 {
	   cout<<" INDEX OUT OF BOUND"<<endl;        
	 }

	else
	{       
	     return Tupel[index];
	}
}

int main() 
{ vector<string> str;

str.push_back("A");
str.push_back("B");
str.push_back("CDE");
   
Record R(str);
	cout<<R.get_entry(2)<<endl;
 system("pause");
}