//Stephen Chan


#include <iostream>
#include <string>
#pragma
using namespace std;

//Class Password that allows for encryption and comparisons.
class Password{
	char password[64];
	string encrypted_pass;
	string user_password;
	char key = 'x';	//Key is used to hash the value in order to encrypt the user's password
public:
	Password();
	void encryptPassword();
	bool comparePasswords(Password a,Password b);
	void assignPassword(string pass);
	~Password();
};

//Constructor
Password::Password()
{
	string encrypted_pass = "";		//Password that is encypted
	string user_encrypt_pass = "";
	string user_password = "";
}
//Destructor
Password::~Password() {}

//Assign password to class variable
void Password::assignPassword(string pass)
{
	user_password = pass;
}

//Encrypt the password using a key
void Password::encryptPassword() {
	//Hashes the value of the password using the key
	for (int i = 0; i < user_password.size(); i++)
	{
		encrypted_pass += user_password[i] ^ (int(key) + i) % 20;
		encrypted_pass += user_password[i] ^ (int(key) + i) % 15;
		encrypted_pass += user_password[i] ^ (int(key) + i) % 5;
		password[i] = user_password[i];
	}
}

//Performs comparison of passwords
bool Password::comparePasswords(Password a, Password b)
{
	//Assigning characters to the array in order to be checked.

	// First Check to see if passwords are same size
	if (a.user_password.size() != b.user_password.size())
	{
		return false;
	}
	
	//2nd check for Comparison
	for (int i = 0; i < a.encrypted_pass.size(); i++)
	{
		if ((a.encrypted_pass[i] != b.encrypted_pass[i]))
		{
			return false;
		}
	}
	return true;
}
