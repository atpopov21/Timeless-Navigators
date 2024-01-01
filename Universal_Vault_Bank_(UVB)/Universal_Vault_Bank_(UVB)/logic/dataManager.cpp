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
	// Declaring and initializing different variables
	int countFailedAttempts = 0;
	std::string* username = new std::string(), *password = new std::string();
	std::string* checkCredentials = new std::string();
	std::string* accountNotFound = new std::string("Account not found. Please try again."), *instructions = new std::string("Press \"Enter\" to continue...");

	// Entering while-loop for credentials check
	while (*checkCredentials != (*username + " " + *password))
	{
		displayAccountPage(*username, *password, false);

		// Check if the database contains the username and password
		while (database)
		{
			std::getline(database, *checkCredentials);
			if (*checkCredentials == (*username + " " + *password))
			{
				database.close();
				return true;
			}
		}

		// Check for entry violation
		if (countFailedAttempts >= 5)
		{
			database.close();
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
	}

	// Closing database
	database.close();
	return true;
}

bool makeAccount()
{
	system("cls");

	// Loading read/write databases
	std::ifstream databaseREAD("../data/userData.txt");
	std::ofstream databaseWRITE("../data/userData.txt");

	// Declaring and initializing variables
	int accountCount = 0;
	std::string* getAccountCount = new std::string();
	std::string* reWriteInfo = new std::string("");
	std::string* username = new std::string(), * password = new std::string();
	std::string* checkForAccountDuplicate = new std::string("");
	std::string* errorStatement1 = new std::string("Please enter valid username... (starting symbol should be from the alphabet)"), * instructions = new std::string("Press \"Enter\" to continue...");
	std::string* errorStatement2 = new std::string("Username already exist. Please try a different one");

	// Extracting the account count from database
	databaseREAD >> *getAccountCount;
	accountCount = std::stoi(*getAccountCount);

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

	// Checking username for invalid actions
	if (!((std::stoi(username[0]) >= 65 && std::stoi(username[0]) <= 90) && (std::stoi(username[0]) >= 97 && std::stoi(username[0]) <= 122)))
	{
		std::cout << std::setw(63 + (errorStatement1->length() / 2)) << *errorStatement1 << '\n' << std::setw(63 + instructions->length() / 2) << *instructions;

		int userInput = 0;
		while (userInput != 13)
		{
			userInput = _getch();
		}

		makeAccount();
	}
	else
	{
		// Rewriting database
		for (int i = 0; i < accountCount; i++)
		{
			if (i == 0)
			{
				databaseWRITE << ++accountCount;
			}
			std::getline(databaseREAD, *reWriteInfo);
			databaseWRITE << *reWriteInfo << '\n';
		}

		databaseWRITE << *username << " ";
		databaseWRITE << *password;
	}

	// Closing database
	databaseWRITE.close();
	databaseREAD.close();
	return true;
}

void mainPage()
{
	displayMainPage();

}