#include<windows.h>
//for cout etc
#include<iostream>
//for writing in files
#include<fstream>
#include<conio.h>
#include<string>

using namespace std;

//for selecting numbers in the menu
int choice, choice3;
string choice2;
//for reading the money of the accounts
double money, withdraw;
//unsigned for positive integers
unsigned int deposit;
//for signup choice 
string signuser, signpass;
//for login choice
string loguser, logpass;
//for checking
//the following variables are for storing the usernames and passwords from the txt file that the accounts are stored 
string user, pass;



//here are the function prototypes

//this function is for displaying the date and time
int date();



//this function is to add account
int addusr(string signuser, string signpass);



//this function is used to check if the login crenedials are right and the next lines of the programm  
int check(string user, string pass, string loguser, string logpass, double money);



//this function is for displaying the account balance
int seebalance(string user, string pass, double money);



//this function is for withdrawing money
int wthdraw(string user, string pass, double money, double withdraw);



//this function is for depositing money
int dpst(string user, string pass, double money, double deposit);



//this function allows you to overdraft money to your account
int ovrdrft();



int main()
{	
	//the following colors the terminal
	system("color 0B");
	cout << "<========== Atm euronet ==========>" << endl;
	cout << date();
	cout << endl;
mn:	cout << endl << "Menu" << endl;
	cout << "==========" << endl;
	cout << "1. Login" << endl;
	cout << "2. Sign up" << endl;
	cout << "3. Exit";
	cout << endl << endl;
	cout << "Select: ";
	cin >> choice;
	cout << endl;
	//when the user want to login
	if(choice == 1)
	{
		cout << "Enter your account name: ";
		cin >> loguser;
		cout << endl;
		cout << "Enter your account pass: ";
		cin >> logpass;
		cout << endl;
		check(user, pass, loguser, logpass, money);
mn2:	cout << endl << "1. Balance inquiry";
		cout << endl << "2. Cash withdraw";
		cout << endl << "3. Cash deposit";
		cout << endl << "4. Cash overdraft";
		cout << endl << "5. Exit" << endl << endl;
		cout << "Select: ";
		cin >> choice3;
		switch(choice3)
		{
			//case 1 is for seeing the account balance
			case 1:
				seebalance(user, pass, money);
				goto mn2;
				break;
			//case 2 is for withdrawing money
			case 2:
				wthdraw(user, pass, money, withdraw);
				goto mn2;
				break;
			//case 3 is for depositing money
			case 3:
				dpst(user, pass, money, deposit);
				goto mn2;
				break;
			//case 4 is for overdrafting money
			case 4:
				ovrdrft();
				goto mn2;
			//case 5 is for exiting
			case 5:
				cout << endl << "Thanks for coming";
				Sleep(2000);
				exit(1);
				break;
			//default is when the user does not select one of the above
			default:
				cout << endl << "Sorry.. This choice isn't available" << endl;
				goto mn2;
				exit(1);
				break;
		}
	}
	// when the user want to sign up
	else if(choice == 2) 
	{
		cout << "Enter a username: ";
		cin >> signuser;
		cout << endl;
		cout << "Enter a password: ";
		cin >> signpass;
		cout << endl;
		cout << "Creating your account ";
		for(int i = 0; i < 3; i++)
		{
			cout << ".";
			Sleep(1000);
		}
		cout << endl;
		date();
		cout << endl << "Your account has been successfully created!!" << endl;
		addusr(signuser, signpass);
		goto mn;
	}
	//when the user want to exit
	else if(choice == 3)
	{
		cout << "Thanks for coming" << endl;
		Sleep(2000);
		exit(1);
	}
	//when the user don't select one of the above
	else
	{
		cout << "This choice isn't available" << endl << endl;
		cout << "Press 1 for going to menu, 404 to exit: ";
		cin >> choice2;
		if(choice2 == "1")
		{
			goto mn; 
		}
		else if(choice2 == "404")
		{
			exit(1);
		}
	}
	return 0;
}

//here are the function definitions

//this function is for displaying the date and time
int date()
{
	SYSTEMTIME a;
	GetLocalTime(&a);
	cout << endl << "---------------" << endl;
	cout << "Date: " << a.wDay << "/";
	cout << a.wMonth << "/";
	cout << a.wYear << endl;
	cout << "Time: " << a.wHour << ":";
	cout << a.wMinute;
	cout << endl << "---------------" << endl;
}



//this function is to add account
int addusr(string signuser, string signpass)
{
	//the variable money will be the standar money that the will be added when the user sign up
	int money = 0;
	//this opens the file
	ofstream fout("acc.txt", ios::app | ios::out);
	//the signuser is the parameter for the username, signpass is the parameter for the password and money the variable for the money
	fout << signuser << " " << signpass << " " << money << " \n";	
	//this close the file
	fout.close();
}



//this function is used to check if the login crenedials are right and the next lines of the programm  
int check(string user, string pass, string loguser, string logpass, double money)
{
	//this opens the file
	ifstream infile("acc.txt");
	if(infile.is_open())
	{
		while(infile >> user >> pass >> money)
		{
		}
		cout << endl << "Trying to confirm your id ";
			
		for(int n = 0; n < 3; n++)
		{
			cout << ".";
			Sleep(1000);
		}
		cout << endl;
	
		if(user == loguser && pass == logpass)
		{
			cout << endl << "You have successfully signed in to your account!!!" << endl << endl;
			//this closes the file
			infile.close();
		}
		else
		{
			cout << endl << "Sorry but, your id is incorrect" << endl;
			Sleep(3000);
			exit(1);
		}
	}
}



//this function is for displaying the account balance
int seebalance(string user, string pass, double money)
{
	//this opens the file
	ifstream infile("acc.txt");
	if(infile.is_open())
	{
		while(infile >> user >> pass >> money)
		{
		}
		cout << endl << "Your account has $" << money << endl;
	}
	//this closes the file
	infile.close();
}



//this function is for withdrawing money
int wthdraw(string user, string pass, double money, double withdraw)
{
	ifstream infile("acc.txt");
	if(infile.is_open())
	{
		while(infile >> user >> pass >> money)
		{
		}
		if(money <= 0)
		{
			cout << endl;
			cout << "You have to overdraft" << endl;
		}
		else
		{
			cout << endl << "How much money do you want to withdraw: ";
			cin >> withdraw;
			cout << endl;
			if(money < withdraw)
			{
				cout << endl << "Your account does not have enough money" << endl;
			}
			else if(money >= withdraw && money != 0)
			{
			cout << "Withdrawing money from your account ";	
			for(int i = 0; i < 3; i++)
			{	
				cout << ".";
				Sleep(1000);
			}	
			cout << endl;
			date();
			money = (money - withdraw);
			cout << endl << "You just have withdrawed $" << withdraw << endl;
			}	
			infile.close();
		}
	}
	ofstream outfile;
	outfile.open("acc.txt");
	//the following will update the amount of money in the users account
	outfile << user << " " << pass << " " << money << " ";
	outfile.close();
}



//this function is for depositing money
int dpst(string user, string pass, double money, double deposit)
{
	//this opens the file
	ifstream infile("acc.txt");
	if(infile.is_open())
	{
		//this reads the lines of the txt file and set the words next to the spaces as the following variables
		while(infile >> user >> pass >> money)
		{
		}
		
		cout << endl << "How much money do you want to deposit: ";
		cin >> deposit;
		cout << endl;
		if(deposit < 0.00)
		{
			cout << endl << "Your number is below zero" << endl;
		}
		else if(deposit > 0.00)
		{
			cout << "Depositing money to your account ";
			for(int i = 0; i < 3; i++)
			{
				cout << ".";
				Sleep(1000);
			}
			cout << endl;	
			date();
			money = (money + deposit);
			cout << endl << "You just have deposited $" << deposit << " to your account" << endl;
			//this closes the file
			infile.close();
		}
	}
	ofstream outfile;
	outfile.open("acc.txt");
	//the following will update the amount of money in the users account
	outfile << user << " " << pass << " " << money << " ";
	outfile.close();
}



//this function allows you to overdraft money to your account
int ovrdrft()
{
	string overdraft, more;
	double amount, prstprn;
	//this opens the file
	ifstream infile("acc.txt");
	if(infile.is_open())
	{
		//this reads the lines of the txt file and set the words next to the spaces as the following variables
		while(infile >> user >> pass >> money)
		{
		}
		if(money > 0.00)
		{
			cout << endl << "You already have money in your account" << endl;
		}
		if(money == 0.00 or money < 0.00)
		{
			if(money <= -1000.00)
			{
				cout << endl << "You have reached to the highest overdraft amount" << endl;
			}
			else if(money > -1000.00)
			{
				cout << "You can overdraft from $1 to $1000"<< endl << endl;
				cout << "Enter how much you want: ";
				cin >> amount;
				cout << endl;
				if(amount < 1.00 or amount > 1000.00)
				{
					cout << "That's not within the budget" << endl;
				}
				else if(amount >= 1.00 and amount <= 1000.00)
				{
					if(money - amount < -1000.00)
					{
						cout << endl << "The amount is overpassing the highest overdraft money" << endl;
					}
					else if(money - amount >= -1000.00 )
					{
						cout << "Giving overdraft ";
						for(int i = 0; i < 3; i++)
						{
							cout << ".";
							Sleep(1000);
						}
						cout << endl;
						money = (money - amount);
						ofstream outfile;
						outfile.open("acc.txt");
						outfile << user << " " << pass << " " << money << " "; 
						outfile.close();
						date();
						cout << endl;
						cout << "You just have overdrafted " << "$" << amount << endl << endl;
						prstprn = (1000 - (money - money - money));
						cout << "$" << prstprn << " reamining to overdraft" << endl << endl;
						cout << "You have 30 days to return the money" << endl;
						if(prstprn == 0)
						{
							cout << endl << "You have reached to the highest overdraft amount" << endl;
						}
					}
				}
			}
		}
	}
	infile.close();
}
