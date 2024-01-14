#pragma once

void waitForKey();
void retrieveDataFromFile();
void retrieveLoginDataFromFile(int userRow);
bool checkForAccount();
bool accessAccount(std::ifstream& database);
bool makeAccount();
void mainPage(bool checkForLogin);
long int generateUserBankNumber();
int generateUserMoney();
void forgotPassword()
{
/*
#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Check if the username is the same as in the file
    std::ifstream userFile("user_file.txt");

    // Read the username from the file
    std::string storedUsername;
    if (std::getline(userFile, storedUsername)) {
        // Get the username from the user
        std::cout << "Enter username: ";
        std::string enteredUsername;
        std::getline(std::cin, enteredUsername);

        // Compare the usernames
        if (enteredUsername != storedUsername) {
            std::cout << "Username does not match the one in the file." << std::endl;
            return 0;
        }
    }

    // Close the username file
    userFile.close();

    // Check if two word are the same
    std::ifstream stringFile("name.txt");

    // Read a word from the file
    std::string storedWord;
    if (stringFile >> storedWord) {
        // Get a word from the user
        std::cout << "Âhat is your favourite food:";
        std::string enteredString;
        std::cin >> enteredString;

        // Compare the word
        if (enteredString != storedWord) {
            std::cout << "The words are different." << std::endl;
            return 0;
        }
    }

    // Close the word file
    stringFile.close();


    // Enter and save a password to a file
    std::ofstream passwordFile("password.txt");


    std::cout << "Enter a new password: ";
    std::string newPassword;
    std::cin >> newPassword;
    passwordFile << newPassword << std::endl;

    passwordFile.close();

    // Compare two passwords
    std::cout << "Enter the password again for comparison: ";
    std::string enteredPassword;
    std::cin >> enteredPassword;

    std::ifstream passwordReadFile("password.txt");

    std::string storedPassword;
    if (passwordReadFile >> storedPassword) {
        if (enteredPassword == storedPassword) {
            std::cout << "Passwords match." << std::endl;
        }
        else {
            std::cout << "Passwords do not match." << std::endl;
        }
    }

    passwordReadFile.close();

    return 0;
}

*/
};