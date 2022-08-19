//Luggage management at ABC AIRLINES
#include <iostream>
#include <string>
using namespace std;
const int TAG_WIDTH = 70; // related to tag size
struct TagInfo
{
string name, flight, destination;
float mass;
char choice;
string address[4];
};
// a dummy function (get information from ticketing and weighting system)
void getPassengerInfo(TagInfo & t)
{
t.name = "Josephine van der Merwe";
t.flight = "ABC123";
t.destination = "JHB - Johannesburg International";
t.mass = 20.0;
}
// display information from ticketing and weighting system
void displayPassengerInfo(TagInfo t)
{
cout << "ABC Airlines" << endl;
cout << "============" << endl;
cout << "Passenger: " << t.name << endl;
cout << "Flight: " << t.flight << endl;
cout << "Destination: " << t.destination << endl;
cout << "Mass of luggage: " << t.mass << " kg" << endl;
cout << "============" << endl;
}
// users dialogue concerning luggage void
getDeliveryInfo(TagInfo & t)
{
// the information was correct: proceed
cout << "============" << endl;
cout << "We provide a FREE delivery service - up to 100 km from airport."
<< endl << "Would you like your luggage delivered (Y/N)? ";
cin >> t.choice;
if (toupper(t.choice) == 'Y')
{
// luggage has to be delivered
cin.get( ); // necessary between cin >> and getline
cout << "Enter the address of your final destination (four lines):"
<< endl;
for (int i = 0; i < 4; i++)
getline(cin, t.address[i], '\n');
cout << "Thank you!" << endl
<< "Your luggage will be delivered within 3 hours of arrival."
<< endl << "============" << endl << endl;
}
}
// display a row of the same characters void
displayChars(char c, int i)
{
for (int j = 0; j < i; j++)
cout << c;
}
// display one line: start with *, then the information,
// then the correct number of blanks, followed by *,
// and move to next line
void displayOneLine(string info)
{
cout << "* " << info;
displayChars(' ', TAG_WIDTH - 4 - info.size( ));
cout << "*" << endl;
}
// display information to be printed on tag void
displayTag(TagInfo t)
{
displayChars('*', TAG_WIDTH);
cout << endl;
displayOneLine("Name: " + t.name);
displayOneLine("Flight: " + t.flight);
displayOneLine("Destination: " + t.destination);
//Can't use displayOneLine to display mass cout <<
"* Mass: "; cout.setf(ios::fixed);
cout.precision(1);
cout.width(6); //See comment before code
cout << t.mass << " kg"; displayChars(' ',
TAG_WIDTH - 24); cout << "*" << endl;
if (toupper(t.choice) != 'Y')
displayOneLine("*** PICK UP AT AIRPORT ***");
else
{
displayOneLine("BAGGAGE TO BE DELIVERED TO:");
for (int i = 0; i < 4; i++)
displayOneLine(" " + t.address[i]);
}
displayChars('*', TAG_WIDTH);
cout << endl;
}
int main( )
{
TagInfo passenger; char correct;
getPassengerInfo(passenger);
displayPassengerInfo(passenger);
// check if the above is correct
cout << "Is all the above information correct (Y/N)? ";
cin >> correct;
if (toupper(correct) != 'Y')
cout << endl << "PLEASE INFORM THE CHECK-IN STAFF." << endl
<< "============" << endl << endl;
else // information was correct
{
getDeliveryInfo(passenger);
displayTag(passenger);
}
return 0;
}

