#include "precompile.h"

void displayAccountCheckPage()
{
	// Display borders and question
	std::string accountCheckQuestion = "Press \"L\" to Login and \"R\" to Register", answer = "Login or Register...";
	std::cout << accountCheckQuestion << '\n' << std::setw(accountCheckQuestion.length() / 2 + answer.length() / 2) << answer;

	// Place MAIN MENU visuals here
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
		// Output: Create Account/Register

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

	// Place Post MENU visuals here
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