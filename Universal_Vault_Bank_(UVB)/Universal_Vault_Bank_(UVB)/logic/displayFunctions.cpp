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
			for (int i = 0; i < 126; i++)
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
			for (int i = 0; i < 126; i++)
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
	// Display borders and question
	std::string accountCheckQuestion = "Press \"L\" to Login and \"R\" to Register", answer = "Login or Register...";
	std::cout << accountCheckQuestion << '\n' << std::setw(accountCheckQuestion.length() / 2 + answer.length() / 2) << answer;

	// Place MAIN MENU visuals here
}

void displayAccountPage(std::string& username, std::string& password, std::string& securityQuestion,bool makeAccount)
{
	system("cls");

	if (!makeAccount)
	{
		// Output: Login
		std::cout << "*          *****       *****        ***   *     * \n";
		std::cout << "*         *     *     *     *        *    **    * \n";
		std::cout << "*        *       *   *               *    * *   *  \n";
		std::cout << "*        *       *   *   ****        *    *  *  *   \n";
		std::cout << "*        *       *   *       *       *    *   * *   \n";
		std::cout << "*         *     *     *     *        *    *    **   \n";
		std::cout << "*******    *****       *****        ***   *     *   \n";

		std::cout << "----------------------------------------------------" << std::endl;
		std::cout << "----------------------------------------------------" << std::endl;

		std::cout << "----------------------------------------------------" << std::endl;
		std::cout << "----------------------------------------------------" << std::endl;
		
		// Temporary output... ALWAYS USE the getline() function to prevent bugs; P.S DO NOT DELETE the rows with comments: "*"
		std::cout << "Username: ";
		std::getline(std::cin, username);		//*
		std::cout << "Password: ";
		std::getline(std::cin, password);		//*
	}
	else
	{
		// Output: Create Account/Register

		// Temporary output... ALWAYS USE the getline() function to prevent bugs; P.S DO NOT DELETE the rows with comments: "*"
		std::cout << "Username: ";
		std::getline(std::cin, username);		//*
		std::cout << "Password: ";
		std::getline(std::cin, password);		//*
		std::cout << "Favourite food: ";
		std::getline(std::cin, securityQuestion);
	}
}

void displayMainPage(std::string& username, std::string& password, std::string& money)
{
	system("cls");
	// Temporary output...
	std::cout << "Congrats! You're in!";

	// Place Post MENU visuals here
	std::cout << std::setw(104) << "*****     *    *     *  *   *            " << std::endl;
	std::cout << std::setw(104) << "*    *   * *   **    *  *  *             " << std::endl;
	std::cout << std::setw(104) << "*    *  *   *  * *   *  * *              " << std::endl;
	std::cout << std::setw(104) << "****** ******* *  *  *  **               " << std::endl;
	std::cout << std::setw(104) << " *    * *     * *   * *  * *              " << std::endl;
	std::cout << std::setw(104) << "*    * *     * *    **  *  *             " << std::endl;
	std::cout << std::setw(104) << "*****  *     * *     *  *   *            " << std::endl;


	HANDLE k = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(k, 9);


	std::cout << std::setw(110) << "-------------------------------------------------------------" << std::endl;
	std::cout << std::setw(110) << "-------------------------------------------------------------" << std::endl;

	std::cout << std::setw(90) << "UNIVERSAL VAULT BANK" << std::endl;

	std::cout << std::setw(110) << "-------------------------------------------------------------" << std::endl;
	std::cout << std::setw(110) << "-------------------------------------------------------------" << std::endl;


	std::cout << std::setw(82) << "MENU" << std::endl;

	std::cout << std::setw(85) << "----------------" << std::endl;
	std::cout << std::setw(85) << "Press \"D\" to make your digital will" << std::endl;
	std::cout << std::setw(78) << "Press 2 to view cripto...." << std::endl;
	std::cout << std::setw(85) << "----------------" << std::endl;


	std::cout << std::setw(110) << "-------------------------------------------------------------" << std::endl;
	std::cout << std::setw(110) << "-------------------------------------------------------------" << std::endl;
}

void displayDigitalWill()
{

}

void entryVoilation()	// DONE
{
	system("cls");
	std::cout << "Too many attempts!" << '\n' << "Application stopped...";
}

void successfulRegistration()
{
	system("cls");
	std::cout << "Successful Registration!" << '\n';
	system("pause");
}