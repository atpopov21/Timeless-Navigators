#include "logic/precompile.h"

int main()
{
	//Reading database (from .txt file)
	std::ifstream database("data/userData.txt");

	displayAccountCheckPage();
	
	if (checkForAccount())
	{
		if (accessAccount(database))
		{
			mainPage();
		}
		else
		{
			entryVoilation();
		}
	}
	else
	{

	}

	database.close();
}