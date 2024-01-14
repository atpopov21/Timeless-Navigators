#pragma once

bool checkForAccount();
bool accessAccount(std::ifstream& database);
bool makeAccount();
void mainPage();
long int generateUserBankNumber();
int generateUserMoney();