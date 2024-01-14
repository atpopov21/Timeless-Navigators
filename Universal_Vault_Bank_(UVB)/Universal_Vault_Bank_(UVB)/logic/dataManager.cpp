#include "precompile.h"

int countWriteTime = 0;
std::string* usernameLogged = new std::string(), *userID = new std::string(), *userMoney = new std::string();

void waitForKey()
{
	// Check if the "Enter" key is pressed
	int userInput = 0;
	while (userInput != 13)
	{
		userInput = _getch();
	}
}

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

	if (!database.is_open())
	{
		std::cout << "FATAL ERORR => Database failed to open.";
	}

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

				//*usernameLogged = *username;


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

		waitForKey();
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
	// Loading databases
	std::ifstream userDataREAD("data/userData.txt");
	std::ofstream userDataWRITE("data/userData.txt", std::ios::app);  // Open the file in append mode
	
	int checkForSpace = 0;
	std::string* username = new std::string(), *password = new std::string(), *checkForAccountDuplicate = new std::string("");

	displayAccountPage(*username, *password, true);

	if (userDataWRITE.is_open() && userDataREAD.is_open())
	{
		// Check if username already exists
		while (userDataREAD >> *checkForAccountDuplicate)
		{
			if (*checkForAccountDuplicate == *username)
			{
				std::cout << "Username already exists...";

				waitForKey();
				makeAccount();
			}
		}

		if ((*username)[0] == 0 || (*username)[0] == 32)
		{
			std::cout << "Invalid username...";

			waitForKey();
			makeAccount();
		}

		for (size_t i = 0; i < username->length(); i++)
		{
			if (i == 0)
			{
				// Check if the first symbol is in uppercase
				if (!((*username)[0] >= 65 && (*username)[0] <= 90))
				{
					std::cout << "First letter should be in uppercase...";

					waitForKey();
					makeAccount();
				}
			}

			if ((*username)[i - checkForSpace] == 32)
			{
				if (checkForSpace <= 2)
				{
					checkForSpace++;
					if (checkForSpace == 2)
					{
						// Check if the symbol is in uppercase
						if (!((*username)[i] >= 65 && (*username)[i] <= 90))
						{
							std::cout << "Surname letter should be in uppercase...";

							waitForKey();
							makeAccount();
						}
					}
				}
			}

			if (checkForSpace == 0 || checkForSpace == 3)
			{
				// Check if symbols are in lowercase
				if (i != 0)
				{
					if (!((*username)[i] >= 97 && (*username)[i] <= 122))
					{
						std::cout << "Invalid username LOWERCASE SYMBOLS CHECK...";

						waitForKey();
						makeAccount();
					}
				}
			}

			// Check if symbols are from the alphabet
			if (!(((*username)[i] >= 65 && (*username)[i] <= 90) || ((*username)[i] >= 97 && (*username)[i] <= 122) || (*username)[i] == 32))
			{
				std::cout << "Use symbols only from the alphabet...";

				waitForKey();
				makeAccount();
			}

			if ((*password)[0] == 0 || (*password)[0] == 32)
			{
				std::cout << "Invalid password...";

				waitForKey();
				makeAccount();
			}
			else
			{
				break;
			}
		}

		if (countWriteTime == 0)
		{
			userDataWRITE << *username << " " << *password << '\n';
			std::cout << "Registration successful!\n";
			countWriteTime++;
		}
	}
	else 
	{
		std::cerr << "Error opening the user database file.\n";
	}

	// Closing databases and releasing memory
	userDataWRITE.close();
	userDataREAD.close();
	delete(username);
	delete(password);
	delete(checkForAccountDuplicate);
	return true;
}

void mainPage()
{
	displayMainPage();
	


	// Closing database and releasing memory
	delete (usernameLogged);
	delete (userID);
	delete (userMoney);
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