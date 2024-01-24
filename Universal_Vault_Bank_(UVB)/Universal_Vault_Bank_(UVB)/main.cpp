#include "services/precompile.h"

int main()
{
	system("MODE CON COLS=126 LINES=50");	// Set CMD's resolution without resize lock
	
	// setting CMD's resolution(cols, lines) to 126x50 and locking resizing; 
	/*HWND console = GetConsoleWindow();

	SMALL_RECT rect = { 0, 0, 126, 50 }; // Adjust the values as needed
	SetConsoleWindowInfo(console, TRUE, &rect);
	SetWindowLong(console, GWL_STYLE, GetWindowLong(console, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);*/

	// Reading database
	std::ifstream database("database/userData.txt");

	displayAccountCheckPage();
	
	if (checkForAccount())
	{
		if (accessAccount(database))
		{
			mainPage(true);
		}
		else
		{
			entryVoilation();
		}
	}
	else
	{
		if (makeAccount())
		{
			mainPage(false);
		}
	}
}