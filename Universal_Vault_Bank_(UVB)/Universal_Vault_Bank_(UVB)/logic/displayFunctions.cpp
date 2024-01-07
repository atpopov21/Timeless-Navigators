#include "precompile.h"

void displayAccountCheckPage()
{
	// Display borders and question
	/*std::string accountCheckQuestion = "Do you have an account in UVB?", answer = "Y|N...";
	std::cout << accountCheckQuestion << '\n' << std::setw(accountCheckQuestion.length() / 2 + answer.length() / 2) << answer;*/

	int input;
	std::cout << "\t\t\t_________________________________________________\n\n\n";
	std::cout << "                                     Universal Vault Bank " << '\m';
	std::cout << '\n';
	std::cout << "                                               MENU                                " << '\n';
	std::cout << '\n';
	std::cout << "\t|  Press 1 to log in  |" << '\n';
	std::cout << "\t|  Press 2 to register  |" << '\n';
	std::cout << "\t|  Press 3 if you forgot the password  |" << '\n';
	std::cout << "\t|  Press 4 to EXIT  |" << '\n';
	std::cout << "\t\t\t_________________________________________________\n\n\n";
	std::cin >> input;
	std::cout << '\n';
}

void displayAccountPage(std::string& username, std::string& password, bool makeAccount)
{
	system("cls");

	if (!makeAccount)
	{
		// Output: Login
		
		// Temporary output... ALWAYS USE the getline() function to prevent bugs; P.S DO NOT DELETE the rows with comments: "*"
		std::cout << "Username: ";
		std::getline(std::cin, username);		//*
		std::cout << "Password: ";
		std::getline(std::cin, password);		//*
	}
	else
	{
		// Output: Create Account

		// Temporary output... ALWAYS USE the getline() function to prevent bugs; P.S DO NOT DELETE the rows with comments: "*"
		std::cout << "Username: ";
		std::getline(std::cin, username);		//*
		std::cout << "Password: ";
		std::getline(std::cin, password);		//*
	}
}

void displayMainPage()
{
	system("cls");
	// Temporary output...
	std::cout << "Congrats! You're in!";
}

void entryVoilation()
{
	system("cls");
	std::cout << "Too many attempts!" << '\n' << "Application stopped...";
}