#include "precompile.h"

bool checkForAccount()
{
	int userInput = 0;
	while (userInput != 108 && userInput != 114)
	{
		userInput = _getch();
	}

	if (userInput == 108)
	{
		return true;
	}

	return false;
}

bool accessAccount(std::ifstream& database)
{
	// Declaring and initializing different variables
	int countFailedAttempts = 0;
	std::string* username = new std::string(), *password = new std::string();
	std::string* checkCredentials = new std::string();
	std::string* accountNotFound = new std::string("Account not found. Please try again."), *instructions = new std::string("Press \"Enter\" to continue...");

	// Entering do-while-loop for credentials check
	do
	{
		displayAccountPage(*username, *password, false);

		// Check if the database contains the username and password
		while (database)
		{
			std::getline(database, *checkCredentials);
			if (*checkCredentials == (*username + " " + *password))
			{
				// Closing database and releasing memory
				database.close();
				delete (username);
				delete (password);
				delete (checkCredentials);
				delete (accountNotFound);
				delete (instructions);
				return true;
			}
		}

		if (*checkCredentials == (*username + " " + *password))
		{
			// Closing database and releasing memory
			database.close();
			delete (username);
			delete (password);
			delete (checkCredentials);
			delete (accountNotFound);
			delete (instructions);
			return true;
		}

		// Check for entry violation
		if (countFailedAttempts >= 5)
		{
			// Closing database and releasing memory
			database.close();
			delete (username);
			delete (password);
			delete (checkCredentials);
			delete (accountNotFound);
			delete (instructions);
			return false;
		}

		countFailedAttempts++;
		std::cout << std::setw(63 + (accountNotFound->length() / 2))<< *accountNotFound << '\n' << std::setw(72) << "Retries remaining: " << 6 - countFailedAttempts << '\n' << std::setw(63 + instructions->length() / 2) << *instructions;

		// Check if the "Enter" key is pressed
		int userInput = 0;
		while (userInput != 13)
		{
			userInput = _getch();
		}
	} while (*checkCredentials != (*username + " " + *password));

	// Closing database and releasing memory
	database.close();
	delete (username);
	delete (password);
	delete (checkCredentials);
	delete (accountNotFound);
	delete (instructions);
	return true;
}

bool makeAccount()
{
	system("cls");

	return true;	// DELETE THIS after completing the registration code
	// Loading read/write databases
	std::ifstream databaseREAD("../data/userData.txt");
	std::ofstream databaseWRITE("../data/userData.txt");

	// Declaring and initializing variables
	int accountCount = 1, checkForSpace = 0;
	std::string* getAccountCount = new std::string();
	std::string* reWriteInfo = new std::string("");
	std::string* username = new std::string(""), * password = new std::string("");
	std::string* checkForAccountDuplicate = new std::string("");
	std::string* errorStatement1 = new std::string("Please enter valid username... (only symbols from the alphabet|space between the first and last name)"), * instructions = new std::string("Press \"Enter\" to continue...");
	std::string* errorStatement2 = new std::string("Username already exist. Please try a different one");

	// Extracting the account count from database
	/*databaseREAD >> *getAccountCount;
	std::cout << *getAccountCount;
	accountCount = std::stoi(*getAccountCount);*/

	displayAccountPage(*username, *password, true);

	// Check if username already exists
	while (databaseREAD >> *checkForAccountDuplicate)
	{
		if (*checkForAccountDuplicate == *username)
		{
			std::cout << std::setw(63 + (errorStatement2->length() / 2)) << '\n' << std::setw(18 + instructions->length() / 2) << *instructions;
			
			int userInput = 0;
			while (userInput != 13)
			{
				userInput = _getch();
			}

			makeAccount();
		}
	}

	// Closing database and releasing memory
	databaseWRITE.close();
	databaseREAD.close();
	delete(getAccountCount);
	delete(reWriteInfo);
	delete(username);
	delete(password);
	delete(checkForAccountDuplicate);
	delete(errorStatement1);
	delete(instructions);
	delete(errorStatement2);
	return true;
}

void mainPage()
{
	displayMainPage();

}

long int generateUserBankNumber()
{
	long int userBankNumber = 0;
	std::random_device rd;
	std::uniform_int_distribution<int> range(0, 9);

	for (int i = 0; i < 10; i++)
	{
		userBankNumber *= 10;
		userBankNumber += range(rd);
	}

	return abs(userBankNumber);
}

int generateUserMoney()
{
	int userMoney = 0;
	std::random_device rd;
	std::uniform_int_distribution<int> range(0, 9);

	for (int i = 0; i < range(rd); i++)
	{
		userMoney *= 10;
		userMoney += range(rd);
	}

	return abs(userMoney);
}