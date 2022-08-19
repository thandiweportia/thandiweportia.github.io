//Stock totals
#include <iostream>
#include <string>
using namespace std;
//Input stock numbers of all the items
void inputData(const string namesP[], const float pricesP[], int stockP[], int n)
{
for (int i = 0; i < n; i++)
{
cout << namesP[i] << ": R" << pricesP[i] << endl;
cout << "Stock: ";
cin >> stockP[i];
}
}
//Calculate the stock value of each item and the total
//stock value, and output a table
void calcAndOutput(const string namesP[], const float pricesP[], const int stockP[], int n)
{
float stockVal;
float stockTotal = 0;
cout << "Item name\tPrice\tStock\tStock value" << endl;
cout << "---------\t-----\t-----\t-----------" << endl;
for (int i = 0; i < n; i++)
{
stockVal = pricesP[i] * stockP[i];
cout << namesP[i] << "\tR" << pricesP[i] << "\t" << stockP[i] << "\tR" << stockVal
<< endl;
stockTotal += stockVal;
}
cout << "Total stock value: R" << stockTotal << endl;
}
int main( )
{
const int NUM_ITEMS = 7; //must be correspond with the //number of names and prices
string names[] = {"Plain candles", "Scented candles", "Dream-catchers", "Bead place mats",
"Bead coasters", "Incense holders", "Hand-painted Ms"};
float prices[] = {8.00, 10.00, 19.00, 11.50, 5.00, 6.40, 23.50};
int stock[NUM_ITEMS];
inputData(names, prices, stock, NUM_ITEMS);
calcAndOutput(names, prices, stock, NUM_ITEMS);
return 0;
}
