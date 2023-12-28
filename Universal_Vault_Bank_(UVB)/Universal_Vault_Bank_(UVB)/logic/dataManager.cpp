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

bool accessAccount()
{
	system("cls");
	//Reading database (from .txt file)
	std::ifstream database("userData.txt");

	int countFailedAttempts = 0;
	std::string* username = new std::string(), *password = new std::string();
	std::string* checkCredentials = new std::string();

	//Entering while-loop for credentials check
	while (*checkCredentials != (*username + *password))
	{


		if (countFailedAttempts >= 5)
		{
			return false;
		}
		countFailedAttempts++;
	}

	return true;
	database.close();
}

void mainPage()
{

}