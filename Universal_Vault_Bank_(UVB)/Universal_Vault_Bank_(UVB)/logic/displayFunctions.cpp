#include "precompile.h"

void displayAccountCheckPage()
{
	// Display borders and question
	std::string accountCheckQuestion = "Do you have an account in UVB?", answer = "Y|N...";
	std::cout << accountCheckQuestion << '\n' << std::setw(accountCheckQuestion.length() / 2 + answer.length() / 2) << answer;
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