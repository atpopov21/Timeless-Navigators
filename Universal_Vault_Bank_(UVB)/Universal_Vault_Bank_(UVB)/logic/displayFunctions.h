#pragma once

void displayADMINpage();
void displayAccountCheckPage();
void displayAccountPage(std::string& username, std::string& password, std::string& securityQuestion, bool makeAccount);
bool displayMainPage(std::string& username, std::string& userID, std::string& money);
void displayDigitalWill();
bool displayForgotPasswordCheck();
bool displayQuestionCheck();
void entryVoilation();