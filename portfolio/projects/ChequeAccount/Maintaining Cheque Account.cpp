//Maintains a cheque account
#include <iostream>
using namespace std;
int main( )
{
float balance, transac;
cout << "What is the balance of the account now? R";
cin >> balance;
cout << endl << "Give a sequence of transactions. Press <Enter> after each."
<< endl << "Give positive values for deposits and "
<< "negative values for cheques written."
<< endl << "Enter 0 to end." << endl << endl;
cin >> transac;
balance += transac;
cout.setf(ios::fixed);
cout.precision(2);
while (transac != 0)
{
cout << "Now the balance of the account is R" << balance << endl;
cin >> transac;
balance += transac;
}
return 0;
}

