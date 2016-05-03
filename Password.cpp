//Stephen Chan
//Compare 2 passwords using classes.

#include <iostream>
#include <string>
#include "Password.h"
using namespace std;

int main()
{
	bool user_decision=true;
	char user_key;
	string user_pass, user_compare;
	Password password1, password2;
	bool comparison = true;
	
	while(user_decision)
	{
		cout << "Please enter a personal password: \n";
		getline(cin, user_pass);
		password1.assignPassword(user_pass);

		cout << endl;
		cout << "Please enter a password to compare: \n";
		getline(cin, user_compare);
		password2.assignPassword(user_compare);

		cout << endl;

		//Encrypt the passwords
		password1.encryptPassword();
		password2.encryptPassword();

		//performs the comparison
		comparison=password1.comparePasswords(password1, password2);

		if (comparison == false)
			cout << "Passwords are different\n";
		else
			cout << "Passwords are the same\n";

		cout << "Press q or Q to quit or any key to repeat. \n";
		cin >> user_key;

		//Makes sure to clear the new line when loop executes again
		cin.ignore();	

		//Prompt user to quit or loop back.
		if (user_key == 'q' || user_key == 'Q')
			break;
	}

	system("pause");
	return 0;
}