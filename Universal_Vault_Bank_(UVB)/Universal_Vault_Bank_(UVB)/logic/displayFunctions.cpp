#include "precompile.h"

void displayADMINpage()
{
	// Declaring databases
	std::ofstream userDataWRITE("data/userData.txt", std::ios::app);	// Open the file in append mode
	std::ofstream userSecurityDataWRITE("data/userSecurityData.txt", std::ios::app);	// Open the file in append mode
	std::ofstream userBankDataWRITE("data/userBankData.txt", std::ios::app);	// Open the file in append mode

	// Declaring and initializing variables
	std::string* action1 = new std::string("Delete all user data"), * action2 = new std::string("Delete Security Data");
	std::string* action3 = new std::string("Delete Bank Data"), *action4 = new std::string("EXIT");
	std::string* goodbyeADMIN = new std::string("Goodbye Admin!");
	
	int ADMINchoice = 0;
	while (ADMINchoice != 52)
	{
		system("cls");

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 126; j++)
			{
				std::cout << "-";
			}
		}

		std::cout << '|' << std::setw(125) << '|' << '\n';
		std::cout << "  |" << std::setw(58 - (action1->length() / 2)) << "~~" << *action1 << "~~" << std::setw(60 - (action1->length() / 2)) << '|' << '\n';
		std::cout << '|' << std::setw(125) << '|' << '\n';
		std::cout << "  |" << std::setw(58 - (action2->length() / 2)) << "~~" << *action2 << "~~" << std::setw(60 - (action2->length() / 2)) << '|' << '\n';
		std::cout << '|' << std::setw(125) << '|' << '\n';
		std::cout << "  |" << std::setw(58 - (action3->length() / 2)) << "~~" << *action3 << "~~" << std::setw(60 - (action3->length() / 2)) << '|' << '\n';
		std::cout << '|' << std::setw(125) << '|' << '\n';
		std::cout << "  |" << std::setw(58 - (action4->length() / 2)) << "~~" << *action4 << "~~" << std::setw(60 - (action4->length() / 2)) << '|' << '\n';
		std::cout << '|' << std::setw(125) << '|' << '\n';

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 126; j++)
			{
				std::cout << "-";
			}
		}

		int userInput = 0;
		while (userInput != 49 && userInput != 50 && userInput != 51 && userInput != 52)
		{
			userInput = _getch();
		}
		
		switch (userInput)
		{
			case 1:	system("del data/userData.txt"); std::cout << "Deleted user data..." << '\n'; system("pause"); break;
			case 2: system("del data/userSecurityData.txt"); std::cout << "Deleted user security data..." << '\n'; system("pause"); break;
			case 3: system("del data/userBankData.txt"); std::cout << "Deleted user bank data..." << '\n'; system("pause"); break;
			default:;
		}

		userInput = _getch();
	}
	
	system("cls");

	std::cout << '\\';
	for (int i = 0; i < 124; i++)
	{
		std::cout << '_';
	}
	std::cout << '/' << '\n';

	std::cout << std::setw(34) << '\\';
	for (int i = 0; i < 90; i++)
	{
		std::cout << '_';
	}
	std::cout << '/' << '\n';

	std::cout << std::setw(50) << '\\';
	for (int i = 0; i < 40; i++)
	{
		std::cout << '_';
	}
	std::cout << '/' << '\n';

	std::cout << std::setw(80) << '\\';
	for (int i = 0; i < 20; i++)
	{
		std::cout << '_';
	}
	std::cout << '/' << '\n';

	std::cout << std::setw(63 + (goodbyeADMIN->length() / 2)) << *goodbyeADMIN;

	delete(action1);
	delete(action2);
	delete(action3);
	delete(action4);
	delete(goodbyeADMIN);
	userDataWRITE.close();
	userSecurityDataWRITE.close();
	userBankDataWRITE.close();
}

void displayAccountCheckPage()
{
	HANDLE colour = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(colour, 3);
	std::cout << "\\\\\\\\\\\\\\" << std::setw(85) << "\\||||||||||||||||||||||||||||||||||||||||||||||||||||||||/" << std::setw(34) << "//////" << '\n';
	std::cout << "\\\\\\\\\\\\\\\\\\\\\\" << std::setw(78) << "\\||||||||||||||||||||||||||||||||||||||||||||||||||/" << std::setw(37) << "//////////" << '\n';
	std::cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << std::setw(70) << "\\||||||||||||||||||||||||||||||||||||||||||||/" << std::setw(40) << "///////////////" << '\n';
	std::cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << std::setw(63) << "\\||||||||||||||||||||||||||||||||||||||/" << std::setw(43) << "///////////////////" << '\n';
	std::cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << std::setw(55) << "\\||||||||||||||||||||||||||||||||/" << std::setw(46) << "////////////////////////" << '\n';
	std::cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << std::setw(46) << "\\||||||||||||||||||||||||||/" << std::setw(49) << "//////////////////////////////" << '\n';
	std::cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << std::setw(38) << "\\||||||||||||||||||||/" << std::setw(52) << "///////////////////////////////////" << '\n';

	SetConsoleTextAttribute(colour, 6);
	std::cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\----" << "UNIVERSAL VAULT BANK" << "----/////////////////////////////////////////////////";
	SetConsoleTextAttribute(colour, 3);

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 126; j++)
		{
			std::cout << '=';
		}
	}
	std::cout << '\n' << '\n';

	std::cout << std::setw(26);
	for (int i = 0; i < 74; i++)
	{
		std::cout << '-';
	}
	std::cout << std::endl;

	// Display question and answer
	std::string accountCheckQuestion = "Press \"L\" to Login and \"R\" to Register", answer = "Login or Register...";
	std::cout << std::setw(63 + (accountCheckQuestion.length() / 2)) << accountCheckQuestion << '\n' << std::setw(63 + (answer.length() / 2)) << answer << '\n';

	std::cout << std::setw(26);
	for (int i = 0; i < 74; i++)
	{
		std::cout << '-';
	}
	std::cout << '\n' << '\n';

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 126; j++)
		{
			std::cout << '=';
		}
	}
	std::cout << '\n' << '\n';
}

void displayAccountPage(std::string& username, std::string& password, std::string& securityQuestion,bool makeAccount)
{
	system("cls");
	HANDLE colour = GetStdHandle(STD_OUTPUT_HANDLE);

	if (!makeAccount)
	{
		// Output: Login

		SetConsoleTextAttribute(colour, 3);
		std::cout << "\\\\\\\\\\\\\\" << std::setw(80) << "*          *****       *****        ***   *     *" << std::setw(39) << "//////" << '\n';
		std::cout << "\\\\\\\\\\\\\\\\\\\\\\" << std::setw(76) << "*         *     *     *     *        *    **    *" << std::setw(39) << "//////////" << '\n';
		std::cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << std::setw(71) << "*        *       *   *               *    * *   *" << std::setw(39) << "///////////////" << '\n';
		std::cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << std::setw(67) << "*        *       *   *   ****        *    *  *  *" << std::setw(39) << "///////////////////" << '\n';
		std::cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << std::setw(62) << "*        *       *   *       *       *    *   * *" << std::setw(39) << "////////////////////////" << '\n';
		std::cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << std::setw(56) << "*         *     *     *     *        *    *    **" << std::setw(39) << "//////////////////////////////" << '\n';
		std::cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << std::setw(51) << "*******    *****       *****        ***   *     *" << std::setw(39) << "///////////////////////////////////" << '\n';

		SetConsoleTextAttribute(colour, 6);
		std::cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\----" << "UNIVERSAL VAULT BANK" << "----/////////////////////////////////////////////////";
		SetConsoleTextAttribute(colour, 3);

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 126; j++)
			{
				std::cout << '=';
			}
		}
		std::cout << '\n' << '\n';

		std::cout << std::setw(69) << "CREDENTIALS" << std::endl;

		std::cout << std::setw(26);
		for (int i = 0; i < 74; i++)
		{
			std::cout << '-';
		}
		std::cout << std::endl;
		
		std::cout << std::setw(64) << "Username: ";
		std::getline(std::cin, username);
		std::cout << std::setw(64) << "Password: ";
		std::getline(std::cin, password);

		std::cout << std::setw(26);
		for (int i = 0; i < 74; i++)
		{
			std::cout << '-';
		}
		std::cout << '\n' << '\n';

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 126; j++)
			{
				std::cout << '=';
			}
		}
		std::cout << '\n' << '\n';
	}
	else
	{
		// Output: Create Account/Register

		SetConsoleTextAttribute(colour, 3);
		std::cout << "\\\\\\\\\\\\\\" << std::setw(85) << "\\||||||||||||||||||||||||||||||||||||||||||||||||||||||||/" << std::setw(34) << "//////" << '\n';
		std::cout << "\\\\\\\\\\\\\\\\\\\\\\" << std::setw(78) << "\\||||||||||||||||||||||||||||||||||||||||||||||||||/" << std::setw(37) << "//////////" << '\n';
		std::cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << std::setw(70) << "\\||||||||||||||||||||||||||||||||||||||||||||/" << std::setw(40) << "///////////////" << '\n';
		std::cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << std::setw(63) << "\\||||||||||||||||||||||||||||||||||||||/" << std::setw(43) << "///////////////////" << '\n';
		std::cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << std::setw(55) << "\\||||||||||||||||||||||||||||||||/" << std::setw(46) << "////////////////////////" << '\n';
		std::cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << std::setw(46) << "\\||||||||||||||||||||||||||/" << std::setw(49) << "//////////////////////////////" << '\n';
		std::cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << std::setw(38) << "\\||||||||||||||||||||/" << std::setw(52) << "///////////////////////////////////" << '\n';

		SetConsoleTextAttribute(colour, 6);
		std::cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\----" << "UNIVERSAL VAULT BANK" << "----/////////////////////////////////////////////////";
		SetConsoleTextAttribute(colour, 3);

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 126; j++)
			{
				std::cout << '=';
			}
		}
		std::cout << '\n' << '\n';

		std::cout << std::setw(69) << "CREDENTIALS" << std::endl;

		std::cout << std::setw(26);
		for (int i = 0; i < 74; i++)
		{
			std::cout << '-';
		}
		std::cout << std::endl;

		std::cout << std::setw(64) << "Username: ";
		std::getline(std::cin, username);
		std::cout << std::setw(64) << "Password: ";
		std::getline(std::cin, password);
		std::cout << std::setw(64) << "Favourite food: ";
		std::getline(std::cin, securityQuestion);

		std::cout << std::setw(26);
		for (int i = 0; i < 74; i++)
		{
			std::cout << '-';
		}
		std::cout << '\n' << '\n';

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 126; j++)
			{
				std::cout << '=';
			}
		}
		std::cout << '\n' << '\n';
	}
}

bool displayMainPage(std::string& username, std::string& userID, std::string& money)
{
	system("cls");

	HANDLE colour = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(colour, 3);

	// Place Post MENU visuals here
	std::cout << "\\\\\\\\" << std::setw(74) << "*****     *    *     *  *   *" << std::setw(48) << "////" << std::endl;
	std::cout << "\\\\\\\\\\\\\\\\" << std::setw(70) << "*    *   * *   **    *  *  * " << std::setw(48) << "////////" << std::endl;
	std::cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << std::setw(64) << "*    *  *   *  * *   *  * *  " << std::setw(48) << "//////////////" << std::endl;
	std::cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << std::setw(57) << "****** ******* *  *  *  **   " << std::setw(48) << "////////////////////" << std::endl;
	std::cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << std::setw(50) << "*    * *     * *   * *  * *  " << std::setw(48) << "///////////////////////////" << std::endl;
	std::cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << std::setw(44) << "*    * *     * *    **  *  * " << std::setw(48) << "/////////////////////////////////" << std::endl;
	std::cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << std::setw(38) << "*****  *     * *     *  *   *" << std::setw(48) << "///////////////////////////////////////" << std::endl;
	
	SetConsoleTextAttribute(colour, 6);
	std::cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\----" << "UNIVERSAL VAULT BANK" << "----////////////////////////////////////////////////" << std::endl;
	SetConsoleTextAttribute(colour, 3);

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 126; j++)
		{
			std::cout << '=';
		}
	}
	std::cout << '\n';
	std::cout << "    First and last name: " << username << "  |  User ID: " << userID << std::setw(54) << "Money: " << money << '\n' << '\n';

	std::cout << std::setw(66) << "MENU" << std::endl;

	std::cout << std::setw(26);
	for (int i = 0; i < 74; i++)
	{
		std::cout << '-';
	}
	std::cout << std::endl;

	std::cout << std::setw(26) << '|' << std::setw(55) << "Press \"D\" to make your digital will" << std::setw(18) << '|' << std::endl;

	std::cout << std::setw(26);
	for (int i = 0; i < 74; i++)
	{
		std::cout << '-';
	}
	std::cout << '\n' << '\n';

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 126; j++)
		{
			std::cout << '=';
		}
	}
	std::cout << '\n' << '\n';

	int userInput = 0;
	while (userInput != 100)
	{
		userInput = _getch();
	}

	return true;
}

void displayDigitalWill()
{
	system("cls");

	std::ofstream digitalWillREAD("data/digitalWill.txt", std::ios::app);	// Open the file in append mode

	HANDLE colour = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(colour, 3);

	std::string username, region, address, familyMembers, money;

	std::cout << std::setw(78) << " /$$   /$$ /$$    /$$ /$$$$$$$" << '\n'
		<< std::setw(78) << "| $$  | $$| $$   | $$| $$__  $$" << '\n'
		<< std::setw(78) << "| $$  | $$| $$   | $$| $$  \\ $$" << '\n'
		<< std::setw(78) << "| $$  | $$|  $$ / $$/| $$$$$$$/" << '\n'
		<< std::setw(78) << "| $$  | $$ \\  $$ $$/ | $$__  $$" << '\n'
		<< std::setw(78) << "| $$  | $$  \\  $$$/  | $$  \\ $$" << '\n'
		<< std::setw(78) << "|  $$$$$$/   \\  $/   | $$$$$$$/" << '\n'
		<< std::setw(78) << " \\______/     \\_/    |_______/ " << '\n';

	SetConsoleTextAttribute(colour, 6);
	std::cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\----" << "UNIVERSAL VAULT BANK" << "----//////////////////////////////////////////////////" << std::endl;
	SetConsoleTextAttribute(colour, 3);
	
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 126; j++)
		{
			std::cout << '=';
		}
	}
	std::cout << '\n' << '\n';

	std::cout << std::setw(76) << "DIGITAL WILL - CREDENTIALS" << std::endl;

	std::cout << std::setw(26);
	for (int i = 0; i < 74; i++)
	{
		std::cout << '-';
	}
	std::cout << std::endl;

	std::cout << std::setw(26);
	for (int i = 0; i < 74; i++)
	{
		std::cout << '-';
	}
	std::cout << std::endl;

	std::cout << std::setw(60) << "Enter your first and last name: ";
	std::getline(std::cin, username);

	std::cout << std::setw(60) << "Enter your region: ";
	std::getline(std::cin, region);

	std::cout << std::setw(60) << "Enter your address: ";
	std::getline(std::cin, address);

	std::cout << std::setw(60) << "Enter your family members(separating them with \"Space\"): ";
	std::getline(std::cin, familyMembers);

	std::cout << std::setw(60) << "Enter the amount of money you want to leave them with: $";
	std::getline(std::cin, money);

	digitalWillREAD << username << " " << region << " " << address << " " << familyMembers << " " << money << '\n';

	std::cout << std::setw(26);
	for (int i = 0; i < 74; i++)
	{
		std::cout << '-';
	}
	std::cout << '\n' << '\n';

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 126; j++)
		{
			std::cout << '=';
		}
	}
	std::cout << '\n' << '\n';

	SetConsoleTextAttribute(colour, 2);
	std::cout << std::setw(81) << "Successful Creation of Digital Will!" << '\n';
	std::cout << std::setw(80) << "Press \"Enter\" to stop program ..." << '\n';

	waitForKey();
}

bool displayForgotPasswordCheck()
{
	system("cls");

	std::cout << std::setw(78) << "Did you forgot your password?" << '\n' << std::setw(66) << "Y|N...";
	
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

bool displayQuestionCheck()
{
	system("cls");
	HANDLE colour = GetStdHandle(STD_OUTPUT_HANDLE);
	
	// Loading database
	std::ifstream userDataREAD("data/userData.txt");
	std::ifstream userSecurityDataREAD("data/userSecurityData.txt");
	
	// Declaring and initializing variables
	int countUser = 0, localUserCounter = 0, checkSpace = 0, i;
	bool userReal = false;
	std::string data, username = "", food = "", checkCredentials = "";

	SetConsoleTextAttribute(colour, 3);
	std::cout << "\\\\\\\\\\\\\\" << std::setw(85) << "\\||||||||||||||||||||||||||||||||||||||||||||||||||||||||/" << std::setw(34) << "//////" << '\n';
	std::cout << "\\\\\\\\\\\\\\\\\\\\\\" << std::setw(78) << "\\||||||||||||||||||||||||||||||||||||||||||||||||||/" << std::setw(37) << "//////////" << '\n';
	std::cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << std::setw(70) << "\\||||||||||||||||||||||||||||||||||||||||||||/" << std::setw(40) << "///////////////" << '\n';
	std::cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << std::setw(63) << "\\||||||||||||||||||||||||||||||||||||||/" << std::setw(43) << "///////////////////" << '\n';
	std::cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << std::setw(55) << "\\||||||||||||||||||||||||||||||||/" << std::setw(46) << "////////////////////////" << '\n';
	std::cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << std::setw(46) << "\\||||||||||||||||||||||||||/" << std::setw(49) << "//////////////////////////////" << '\n';
	std::cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << std::setw(38) << "\\||||||||||||||||||||/" << std::setw(52) << "///////////////////////////////////" << '\n';

	SetConsoleTextAttribute(colour, 6);
	std::cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\----" << "UNIVERSAL VAULT BANK" << "----/////////////////////////////////////////////////";
	SetConsoleTextAttribute(colour, 3);

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 126; j++)
		{
			std::cout << '=';
		}
	}
	std::cout << '\n' << '\n';

	std::cout << std::setw(26);
	for (int i = 0; i < 74; i++)
	{
		std::cout << '-';
	}
	std::cout << std::endl;

	// Display question
	std::cout << std::setw(60) << "Please type your username: ";

	std::getline(std::cin, username);

	// Check if the database contains the username
	while (userDataREAD)
	{
		std::getline(userDataREAD, checkCredentials);

		for (i = 0; i < checkCredentials.length(); i++)
		{
			if (checkCredentials[i] == 32)
			{
				if (checkSpace < 2)
				{
					checkSpace++;
				}	
			}
		}

		if (checkSpace == 2)
		{
			checkCredentials = checkCredentials.substr(0, (i - 1));
			if (checkCredentials == username)
			{
				userReal = true;
				break;
			}
		}
		countUser++;
	}

	if (userReal)
	{
		std::cout << std::setw(60) << "What is your favourite food: ";

		std::getline(std::cin, food);

		// Check if database contains the food
		std::string foodData = "";
		while (userSecurityDataREAD >> foodData)
		{
			if (localUserCounter == countUser)
			{
				if (foodData == food)
				{
					std::cout << "Found me";
					system("pause");
					return true;
				}
			}
		}
	}
	else
	{
		std::cout << std::setw(26);
		for (int i = 0; i < 74; i++)
		{
			std::cout << '-';
		}
		std::cout << '\n' << '\n';

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 126; j++)
			{
				std::cout << '=';
			}
		}
		std::cout << '\n' << '\n';
		SetConsoleTextAttribute(colour, 4);
		std::cout << std::setw(73) << "Invalid username..." << '\n';
		waitForKey();
		displayQuestionCheck();
	}


	std::cout << std::setw(26);
	for (int i = 0; i < 74; i++)
	{
		std::cout << '-';
	}
	std::cout << '\n' << '\n';

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 126; j++)
		{
			std::cout << '=';
		}
	}
	std::cout << '\n' << '\n';

	userDataREAD.close();
	userSecurityDataREAD.close();
	return false;
}

void entryVoilation()
{
	system("cls");

	HANDLE colour = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(colour, 4);
	std::cout << "Too many attempts!" << '\n' << "Application stopped...";
}