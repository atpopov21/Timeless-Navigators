#include "logic/precompile.h"

int main()
{
	displayAccountCheckPage();
	
	if (checkForAccount())
	{
		if (accessAccount())
		{
			displayMainPage();
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
}