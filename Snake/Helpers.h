#ifndef HELPERS_H
#define HELPERS_H

namespace Rendering
{ 
//-------------------------------------------------------
//	Function	:	gotoXY
//	Purpose		:	Moves the cursor to a specified position
//	Parameters  :	const int& x, const int& y
//	Returns		:	void
//-------------------------------------------------------
void gotoXY( const int x, const int y );

//-------------------------------------------------------
//	Function	:	drawChar
//	Purpose		:	Draws a character given by the paramater at a specified position
//	Parameters  :	const char& c, const int& x, const int& y
//	Returns		:	void
//-------------------------------------------------------
void drawChar(const char c, const int x, const int y);

//-------------------------------------------------------
//	Function	:	resizeWindow
//	Purpose		:	Resizes the console window to allow for a bigger playable area without the user
//					needing to do it manually
//	Parameters  :	const int& height, const int& width
//	Returns		:	void
//-------------------------------------------------------
void resizeWindow( const int height, const int width );

//-------------------------------------------------------
//	Function	:	showConsoleCursor
//	Purpose		:	Determines whether or not to display the blinking cursor via a bool paramater
//	Parameters  :	const bool& showFlag
//	Returns		:	void
//-------------------------------------------------------
void showConsoleCursor( const bool showFlag );

//-------------------------------------------------------
//	Function	:	centerString
//	Purpose		:	Calculates where to place the string so that it can be displayed in a centered format
//	Parameters  :	const int& stringLength, const int& borderWidth, const int& lineNum
//	Returns		:	void
//-------------------------------------------------------
void centerString( const int stringLength, const int borderWidth, const int lineNum );
}

namespace Input
{
	//-------------------------------------------------------
	//	Function	:	checkButton
	//	Purpose		:	Checks if the button specified by the parameter is currently being pressed and returns the result
	//	Parameters  :	int virtualKey
	//	Returns		:	bool
	//-------------------------------------------------------
	bool checkButton( int virtualKey );
}

namespace Math
{	
	//-------------------------------------------------------
	//	Function	:	randomiseNum
	//	Purpose		:	Returns a random number within a specified range
	//	Parameters  :	const int& min, const int& max
	//	Returns		:	int
	//-------------------------------------------------------
	int randomiseNum( const int min, const int max );
}

#endif // End of '#ifndef HELPERS_H'