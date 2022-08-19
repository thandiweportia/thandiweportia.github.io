//Theatre reservations
#include <iostream>
using namespace std;
const int NUM_ROWS = 5;
const int NUM_SEATS = 9;
const char ROW_CHAR[] = {'A', 'B', 'C', 'D', 'E'};
// mark 'num' seats in row 'r' with character 'marker', starting at seat 's'
void markSeats(char planP[][NUM_SEATS], char marker, int r, int s, int num)
{
for (int i = s-1; i < s-1 + num; i++)
planP[r][i] = marker;
}
// display the current theatre plan
void displayPlan(const char planP[][NUM_SEATS])
{
// display heading at the top of plan
cout << endl << endl;
for (int i = 1; i <= NUM_SEATS; i++)
cout << '\t' << i << ' ';
cout << endl;
// display the plan itself
for (int i = 0; i < NUM_ROWS; i++)
{
cout << ROW_CHAR[i] << ": ";
for (int j = 0; j < NUM_SEATS; j++)
cout << '\t' << planP[i][j] << ' ';
cout << endl;
}
// display SCREEN at the bottom of the plan
cout << "\t\tS\tC\tR\tE\tE\tN" << endl;
}
// find numerical index of row
int charToNumber(char c)
{
return toupper(c) - 'A'; // 0, 1, 2, 3, or 4 will be returned
}
// test whether there are 'num' unreserved seats in row r starting at seat s
// (seat index as on plan)
// and display a message if an error occurs
void checkIfValid(const char planP[][NUM_SEATS], int r, int s, int num,
bool & valid)
{
int lastNumber; // number of last ticket
char rowChar;
valid = true;
lastNumber = s + num - 1; //index as on plan
// Are too many tickets required?
if (lastNumber > NUM_SEATS)
{
cout << "PROBLEM: There are not " << num << " seats available here";
cout << endl;
valid = false;
}
// Is one of the required seats already reserved?
else
for (int i = s - 1; i < lastNumber; i++)
if (planP[r][i] == 'R')
{
cout << "PROBLEM: " << ROW_CHAR[r] << i+1 << " is already reserved";
cout << endl;
valid = false;
}
}
int main( )
{
char plan[NUM_ROWS][NUM_SEATS];
char row;
int numberOfTickets, seatNumber, rowNumber;
bool validBooking;
// headings
cout << "Theatre reservations: Rows A to E and seats 1 to 9"
<< endl << "To stop, type Q for row" << endl << endl;
// initially all seats should contain the character '-'
for (int i = 0; i < NUM_ROWS; i++)
markSeats(plan, '-', i, 1, NUM_SEATS);
displayPlan(plan);
// first reservation
cout << endl << "In which row do you want seats? ";
cin >> row; // index as on plan
// loop over all reservations
while (toupper(row) != 'Q')
{
rowNumber = charToNumber(row);
cout << "How many seats? ";
cin >> numberOfTickets;
cout << "Starting at which number? ";
cin >> seatNumber; // index as on plan
// test if booking is valid, and if valid, make the reservation:
checkIfValid(plan, rowNumber, seatNumber, numberOfTickets, validBooking);
if (validBooking)
{
markSeats(plan, 'R', rowNumber, seatNumber, numberOfTickets);
cout << numberOfTickets << " seats reserved in row " << row << endl;
}
// next reservation
displayPlan(plan);
cout << endl << "In which row do you want seats? ";
cin >> row;
}
return 0;
}
