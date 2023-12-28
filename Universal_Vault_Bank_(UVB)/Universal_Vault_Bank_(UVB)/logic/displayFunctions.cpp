#include "precompile.h"

void displayAccountCheckPage()
{
	//Display borders and question
	std::string accountCheckQuestion = "Do you have an account in UVB?", answer = "Y|N...";
	std::cout << accountCheckQuestion << '\n' << std::setw(accountCheckQuestion.length() / 2 + answer.length() / 2) << answer;
}

void displayLoginPage()
{
	system("cls");

}

void displayMainPage()
{
	system("cls");
	//Temporary output...
	std::cout << "Congrats! You're in!";
}

void entryVoilation()
{
	system("cls");
	std::cout << "Too many attempts!" << '\n' << "Application stopped...";
}