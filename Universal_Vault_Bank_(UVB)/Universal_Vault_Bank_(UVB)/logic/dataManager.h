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
void forgotPassword();