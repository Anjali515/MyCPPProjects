#include<iostream>
#include<cstring>

using namespace std;

const int MAX_VALID_YR = 9999; 
const int MIN_VALID_YR = 1800; 


bool isLeapYear(int year) 
{ 
// Return true if year  
// is a multiple of 4 and 
// not multiple of 100. 
// OR year is multiple of 400. 
return (((year % 4 == 0) &&  
         (year % 100 != 0)) || 
         (year % 400 == 0)); 
} 


bool isValidDate(int month, int day, int year)
{
  //Check Year
  if(year < MIN_VALID_YR && year > MAX_VALID_YR)
      return false;
  else if((month < 1) && (month > 12)) // Check Month
	  {
		return false;
	  }
	  else if((day >= 1) && (day <= 31)) // Check Day
			{
			  if(month == 2) // Feburary Check
			  {
				if(isLeapYear(year))  // Leap Year Check
				 {
					if(day != 29)
					  return false;
				 }
				else if(day != 28)
						return false;
			  }
			  else if((month == 1) ||(month == 3) ||(month == 5) || (month == 7) 
			  || (month == 8) || (month == 10) || (month == 12))
			  {
				if(day != 31)
				  return false;
			  }
			  else if((month == 4) ||(month == 6) ||(month == 9) || (month == 11))
			  {
				if(day != 30)
				  return false;
			  }
			}
			else return false;

  return true;
}


char* NextDate(int month, int day, int year)
{
  char* ndate;
  ndate = new char[11];
  
  if(month < 12)
  {
    month = month + 1;
  }
  else if(month == 12)
  {
    month = 1;
	if(year == MAX_VALID_YR)
		year = 0;
	else year = year + 1;
  }
  
  if ( (day == 31) || 
  ((day == 30) && ((month == 4) ||(month == 6) ||(month == 9) || (month == 11))) || 
  ((month == 2) && (day == 28) && (!isLeapYear(year))) || 
  ((month == 2) && (day == 29)) )
  {
    day = 1;
  }
  else if( ((day >= 1) && (day <= 27)) || 
		(((day == 28) ||(day == 29)) && (month != 2)) || 
		((day == 28) && (month == 2) && (isLeapYear(year)) ) || 
		((day == 30) && ((month == 1) ||(month == 3) ||(month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12))) )
  {
      day = day + 1;
  }
  
  return ndate;
}



int main() {

  int month;
  int day;
  int year;
  cout << "Enter a Date: \n";
  cout<< "Enter Month: ";
  cin >> month;
  cout<< "Enter Day: ";
  cin >> day;
  cout<< "Enter year: ";
  cin >> year;
  
  if(isValidDate(month,day,year))
    cout<<"\n The next date will be: " << NextDate(month, day, year) << endl;
  else 
    cout<< "\n Invalid input date !" << endl;

  return 0;
}
