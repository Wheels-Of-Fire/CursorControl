
#include<iostream>
#include<wchar.h>
#include<windows.h>
#include<conio.h>

using namespace std;

int main()
{

	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	if (hOut == INVALID_HANDLE_VALUE)
	{
		return false;
	}

	HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);

	if (hIn == INVALID_HANDLE_VALUE)
	{
		return false;
	}

	DWORD dwOriginalOutMode = 0;
	DWORD dwOriginalInMode = 0;

	if (!GetConsoleMode(hOut, &dwOriginalOutMode))
	{
		return false;
	}

	if (!GetConsoleMode(hIn, &dwOriginalInMode))
	{
		return false;
	}

	DWORD dwRequestedOutModes = ENABLE_VIRTUAL_TERMINAL_PROCESSING | DISABLE_NEWLINE_AUTO_RETURN;
	DWORD dwRequestedInModes = ENABLE_VIRTUAL_TERMINAL_INPUT;

	DWORD dwOutMode = dwOriginalOutMode | dwRequestedOutModes;

	if (!SetConsoleMode(hOut, dwOutMode))
	{
		return -1;
	}

	DWORD dwInMode = dwOriginalInMode | ENABLE_VIRTUAL_TERMINAL_INPUT;

	if (!SetConsoleMode(hIn, dwInMode))
	{
		return -1;
	}



	int x = 20, y = 10;

	char z = 0;

	cout << "\x1b[?25l"; //Hide cursor

	cout << "\x1b[7m";

	cout << "\x1b" << "[" << y << ";" << x << "fWord";

	while (z = _getch())
	{
		cout << "\x1b[27m"; //Inverse video

		cout << "\x1b" << "[" << y << ";" << x << "f    "; // Control code for  cursor position, clear Word

		switch (z) {
		case 'a': 
			x--;
			break;
		case 'd':
			x++;
			break;
		case 'w':
			y--;
            break;
		case 's':
			y++;
				break;
		case 'q': return 0;

		}
		if (x > 90)
			x--;

		if (x < 1)
			x ++ ;

		if (y > 30)
			y--;

		if (y < 1)
			y++;

		cout << "\x1b[7m"; //Normal video

		cout << "\x1b" << "[" << y << ";" << x << "fWord";
	}
}