#include "precompile.h"

bool checkForAccount()
{
	int userInput = 0;
	while (userInput != 121 && userInput != 110)
	{
		userInput = _getch();
	}

	if (userInput == 121)
	{
		return true;
	}

	return false;
}

bool accessAccount(std::ifstream& database)
{
	system("cls");	//DELETE THIS after completing "displayLoginPage()" function!

	int countFailedAttempts = 0;
	std::string* username = new std::string(), *password = new std::string();
	std::string* checkCredentials = new std::string();

	//Entering while-loop for credentials check
	while (*checkCredentials != (*username + " " + *password))
	{
		//displayLoginPage();	put this function whereever you like, as long as it works it's alright

		//Temporary output... ALWAYS USE the getline() function to prevent bugs
		std::cout << "Username: ";
		std::getline(std::cin, *username);
		std::cout << "Password: ";
		std::getline(std::cin, *password);

		//Check if the database contains the username and password
		while (database)
		{
			std::getline(database, *checkCredentials);
			if (*checkCredentials == (*username + " " + *password))
			{
				return true;
			}
		}

		if (countFailedAttempts >= 5)
		{
			return false;
		}
		countFailedAttempts++;
		system("cls");	//DELETE THIS after completing "displayLoginPage()" function!
	}

	return true;
	database.close();
}

void mainPage()
{
	displayMainPage();

}