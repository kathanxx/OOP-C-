#include <iostream>
using namespace std;
// class
class Bank 
{
private:
long acc_no;
char name[30];
long balance;

public:
void OpenAccount()
{
cout << "Enter Account Number: ";
cin >> acc_no;
cout << "Enter Name: ";
cin >> name;
cout<<"NOTE : Minimum balance should be more than 200"<<endl;
cout << "Enter  Balance: ";
do
{
cin >> balance;
} while (balance<200);
}
void ShowAccount()
{
cout << "Account Number: " << acc_no << endl;
cout << "Name: " << name << endl;
cout << "Balance: " << balance << endl;
}
void Deposit()
{
long amount;
cout << "Enter Amount to be deposited : ";
cin >> amount;
balance = balance + amount;
cout<<endl<<"Updated Balance = "<<balance;
}
void Withdrawal()
{
long amount;
back:
cout << "Enter Amount to be withdrawn : ";
cin >> amount;
if (amount < balance)
{
balance = balance - amount;
cout<<endl<<"Updated Balance = "<<balance<<endl;
}
if(balance<=200)
{
cout<<"delete your account from the nearest branch!!"<<endl<<"Or update the balance with minimum 200"<<endl;
amount=balance+amount;
goto back;
}
}
long Search(long);
};
long Bank::Search(long a)
{
if (acc_no == a) 
{
ShowAccount();
return(1);
}
return (0);
}

// main code
int main()
{
int x;
cout<<"Enter number of accounts to be created :";
cin>>x;
Bank C[x];
int found = 0,b;
long a;
for (int i = 0; i < x; i++) 
{
C[i].OpenAccount();
}
do 
{
// display options
cout<<endl<<endl;
cout<<"MAIN MENU : "<< endl;
cout << "1:Display All" << endl;
cout << "2:Search Account" << endl;
cout << "3:Deposit" << endl;
cout << "4:Withdraw" << endl;
cout << "5:Exit" << endl;
// user input
cout << endl << "Please input function number from the above listed : ";
cin >> b;
cout<<endl;
switch (b) 
{

case 1: // displaying account info
for (int i = 0; i < x; i++) 
{
C[i].ShowAccount();
}
break;

case 2: // searching the record
cout << "Enter Account Number : ";
cin >> a;
for (int i = 0; i < x; i++) 
{
found = C[i].Search(a);
if (found)
break;
}
if (!found)
cout << "Record Not Found" << endl;
break;

case 3: // deposit operation
cout << "Enter Account Number : ";
cin >> a;
for (int i = 0; i < x; i++) 
{
found = C[i].Search(a);
if (found) 
{
C[i].Deposit();
break;
}
}
if (!found)
cout << "Record Not Found" << endl;
break;

case 4: // withdraw operation
cout << "Enter Account Number : ";
cin >> a;
for (int i = 0; i < x; i++) 
{
found = C[i].Search(a);
if (found) 
{
C[i].Withdrawal();
break;
}
}
if (!found)
{
cout << "Record Not Found" << endl;
break;
}

case 5: // exit program
cout << "Have a nice day 👍️" << endl;
break;
default:
cout << "Invalid Input!" << endl;
break;
}
} while (b != 5);
return 0;
}
