#include "precompile.h"

int countWriteTime = 0;
std::string* usernameLogged = new std::string(), * userID = new std::string(), * userMoney = new std::string();

void retrieveLoginDataFromFile(int userRow)
{
	std::ifstream userBankDataREAD("database/userBankData.txt");

	int localUserCounter = 0;
	std::vector<std::string> dataList;
	std::string data = "";

	// Read every element from the file
	while (localUserCounter != userRow)
	{
		localUserCounter++;
		userBankDataREAD >> data;
		if (localUserCounter == userRow)
		{
			dataList.push_back(data);
			userBankDataREAD >> data;
			dataList.push_back(data);
		}
		userBankDataREAD >> data;
	}

	*userID = dataList[0];
	*userMoney = dataList[1];
}

void retrieveDataFromFile()
{
	std::ifstream userBankDataREAD("database/userBankData.txt");

	std::vector<std::string> dataList;
	std::string data;

	// Read every element from the file
	while (userBankDataREAD >> data)
	{
		dataList.push_back(data);
	}

	// Check if there are at least two elements in the dataList
	if (dataList.size() >= 2)
	{
		*userID = dataList[dataList.size() - 2];
		*userMoney = dataList[dataList.size() - 1];
	}
	else
	{
		// Handle the case where there are not enough elements in the file
		std::cout << "Error: Not enough data in the file." << std::endl;
	}
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
	HANDLE colour = GetStdHandle(STD_OUTPUT_HANDLE);

	// Declaring and initializing different variables
	int countFailedAttempts = 0, countUser = 0;
	bool userForgotPassword = false;
	std::string* username = new std::string(), *password = new std::string();
	std::string* checkCredentials = new std::string();
	std::string* accountNotFound = new std::string("Account not found. Please try again."), *instructions = new std::string("Press \"Enter\" to continue...");

	if (!database.is_open())
	{
		SetConsoleTextAttribute(colour, 4);
		std::cout << "FATAL ERORR => Database failed to open.";
	}

	// Entering do-while-loop for credentials check
	do
	{
		displayAccountPage(*username, *password, *password, false);
		
		if (*username == "ADMIN" && *password == "admin14-1-24-20:44")
		{
			*usernameLogged = *username;

			// Closing database and releasing memory
			database.close();
			delete (username);
			delete (password);
			delete (checkCredentials);
			delete (accountNotFound);
			delete (instructions);

			return true;
		}

		// Check if the database contains the username and password
		while (database)
		{
			std::getline(database, *checkCredentials);
			if (*checkCredentials == (*username + " " + *password))
			{
				*usernameLogged = *username;

				// Closing database and releasing memory
				database.close();
				delete (username);
				delete (password);
				delete (checkCredentials);
				delete (accountNotFound);
				delete (instructions);

				retrieveLoginDataFromFile(countUser);

				return true;
			}
			countUser++;
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

		if (countFailedAttempts == 4)
		{
			if (displayForgotPasswordCheck())
			{
				userForgotPassword = true;
			}
		}

		if (userForgotPassword)
		{
			break;
		}

		SetConsoleTextAttribute(colour, 4);
		countFailedAttempts++;
		std::cout << std::setw(63 + (accountNotFound->length() / 2))<< *accountNotFound << '\n' << std::setw(72) << "Retries remaining: " << 6 - countFailedAttempts << '\n' << std::setw(63 + instructions->length() / 2) << *instructions;

		if (userForgotPassword)
		{
			if (displayQuestionCheck())
			{

			}
		}

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
	HANDLE colour = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");
	// Loading databases
	std::ifstream userDataREAD("database/userData.txt");
	std::ifstream userBankDataREAD("database/userBankData.txt");
	std::ifstream userSecurityDataREAD("database/userSecurityData.txt");

	std::ofstream userDataWRITE("database/userData.txt", std::ios::app);  // Open the file in append mode
	std::ofstream userBankDataWRITE("database/userBankData.txt", std::ios::app);  // Open the file in append mode
	std::ofstream userSecurityDataWRITE("database/userSecurityData.txt", std::ios::app);  // Open the file in append mode
	
	int checkForSpace = 0;
	std::string* username = new std::string(), *password = new std::string(), *checkForAccountDuplicate = new std::string("");
	std::string* securityQuestion = new std::string();

	displayAccountPage(*username, *password, *securityQuestion, true);

	if (userDataWRITE.is_open() && userDataREAD.is_open())
	{
		if (*username == "ADMIN" && *password == "admin14-1-24-20:44")
		{
			// Accessing ADMIN settings
			displayADMINpage();

			// Closing databases and releasing memory
			userDataWRITE.close();
			userDataREAD.close();
			delete(username);
			delete(password);
			delete(checkForAccountDuplicate);
			return false;
		}

		// Check for empty username holder
		if ((*username)[0] == 0 || (*username)[0] == 32)
		{
			SetConsoleTextAttribute(colour, 4);
			std::cout << std::setw(73) << "Invalid username...";

			waitForKey();
			makeAccount();
		}

		std::string surname = "";
		// Check if username already exists
		while (userDataREAD >> *checkForAccountDuplicate)
		{
			userDataREAD >> surname;
			*checkForAccountDuplicate += " " + surname;
			if (*checkForAccountDuplicate == *username)
			{
				SetConsoleTextAttribute(colour, 4);
				std::cout << std::setw(76) << "Username already exists...";

				waitForKey();
				makeAccount();
			}
		}

		for (size_t i = 0; i < username->length(); i++)
		{
			// Check if symbols are from the alphabet
			if (!(((*username)[i] >= 65 && (*username)[i] <= 90) || ((*username)[i] >= 97 && (*username)[i] <= 122) || (*username)[i] == 32))
			{
				SetConsoleTextAttribute(colour, 4);
				std::cout << std::setw(82) << "Use symbols only from the alphabet...";

				waitForKey();
				makeAccount();
			}
		}

		// Check if the first symbol is in uppercase
		if (!((*username)[0] >= 65 && (*username)[0] <= 90))
		{
			SetConsoleTextAttribute(colour, 4);
			std::cout << std::setw(82) << "First letter should be in uppercase...";

			waitForKey();
			makeAccount();
		}

		for (size_t i = 0; i < username->length(); i++)
		{
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
							SetConsoleTextAttribute(colour, 4);
							std::cout << std::setw(83) << "Surname letter should be in uppercase...";

							waitForKey();
							makeAccount();
						}
					}
				}
			}

			if (checkForSpace == 0 || checkForSpace == 3)
			{
				// Check if other symbols are in lowercase
				if (i != 0)
				{
					if (!((*username)[i] >= 97 && (*username)[i] <= 122))
					{
						SetConsoleTextAttribute(colour, 4);
						std::cout << std::setw(73) << "Invalid username...";

						waitForKey();
						makeAccount();
					}
				}
			}
		}

		// Check for empty password holder
		if ((*password)[0] == 0 || (*password)[0] == 32)
		{
			SetConsoleTextAttribute(colour, 4);
			std::cout << std::setw(73) << "Invalid password...";

			waitForKey();
			makeAccount();
		}

		// Check for existing surname
		if (checkForSpace == 0)
		{
			SetConsoleTextAttribute(colour, 4);
			std::cout << std::setw(73) << "Invalid username...";

			waitForKey();
			makeAccount();
		}

		if (countWriteTime == 0)
		{
			// Write new data in database
			userDataWRITE << *username << " " << *password << '\n';
			userBankDataWRITE << generateUserBankNumber() << " " << generateUserMoney() << '\n';
			userSecurityDataWRITE << *securityQuestion << '\n';

			*usernameLogged = *username;

			SetConsoleTextAttribute(colour, 2);
			std::cout << std::setw(75) << "Successful Registration!" << '\n';
			std::cout << std::setw(77) << "Press \"Enter\" to continue..." << '\n';
			
			waitForKey();
			countWriteTime++;
		}
	}
	else 
	{
		SetConsoleTextAttribute(colour, 4);
		std::cout << std::setw(82) << "Error opening the user database file.\n";
	}

	// Closing databases and releasing memory
	userDataWRITE.close();
	userBankDataWRITE.close();
	userSecurityDataWRITE.close();
	userDataREAD.close();
	delete(username);
	delete(password);
	delete(checkForAccountDuplicate);
	return true;
}

void mainPage(bool checkForLogin)
{
	// Get data from database
	if (!checkForLogin)
	{
		retrieveDataFromFile();
	}

	if (*usernameLogged == "ADMIN")
	{
		displayADMINpage();
	}
	else
	{
		if (displayMainPage(*usernameLogged, *userID, *userMoney))
		{
			displayDigitalWill(*usernameLogged, *userID, *userMoney);
		}
	}

	// Closing database and releasing memory
	delete (usernameLogged);
	delete (userID);
	delete (userMoney);
}