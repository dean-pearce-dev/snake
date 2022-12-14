#include <iostream>
#include <random>
#include <Windows.h>

#include "Helpers.h"

// Some messy Win32 stuff is nicely only in this file, so hidden from the rest of the code

namespace Rendering
{
	void gotoXY( const int x, const int y )
	{
		HANDLE hStdout = GetStdHandle( STD_OUTPUT_HANDLE );
		COORD position = { ( SHORT )x, ( SHORT )y };

		SetConsoleCursorPosition( hStdout, position );
	}

	void drawChar( const char c, const int x, const int y )
	{
		gotoXY( x, y );
		std::cout << c;
	}

	void resizeWindow( const int width, const int height )
	{
		//Code to resize console window
		//Found here https://www.daniweb.com/programming/software-development/threads/308396/setting-the-console-window-size
		HWND console = GetConsoleWindow();
		RECT ConsoleRect;
		GetWindowRect( console, &ConsoleRect );

		MoveWindow( console, ConsoleRect.left, ConsoleRect.top, height, width, TRUE );
		//End of cited code
	}

	void showConsoleCursor( const bool showFlag )
	{
		//Code to hide blinking cursor
		//Found here https://stackoverflow.com/questions/18028808/remove-blinking-underscore-on-console-cmd-prompt
		HANDLE out = GetStdHandle( STD_OUTPUT_HANDLE );

		CONSOLE_CURSOR_INFO     cursorInfo;

		GetConsoleCursorInfo( out, &cursorInfo );
		cursorInfo.bVisible = showFlag; // set the cursor visibility
		SetConsoleCursorInfo( out, &cursorInfo );
	}

	void centerString( const int stringLength, const int borderWidth, const int lineNum )
	{
		//Finds the horizontal center by halving the border width
		int horizontalCenter = borderWidth >> 1;

		//Calculating the offset by halving the string length
		int stringOffset = stringLength >> 1;

		//Gives the correct position to start the string by subtracting the stringOffset from the horizontalCenter
		int xPosToStart = horizontalCenter - stringOffset;

		//Sends the cursor to the position calculated above
		gotoXY( xPosToStart, lineNum );
	}
}

namespace Input
{
	bool checkButton( int virtualKey )
	{
		virtualKey = toupper( virtualKey );
		bool buttonPressed = ( bool )( GetAsyncKeyState( virtualKey ) & 0x8000 );
		return buttonPressed;
	}
}

namespace Math
{
	int randomiseNum( const int min, const int max )
	{
		//Code from https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c
		std::random_device dev;
		std::mt19937 rng( dev() );
		std::uniform_int_distribution<std::mt19937::result_type> dist6( min, max );

		return dist6( rng );
	}
}