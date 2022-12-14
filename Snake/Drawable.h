#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "Helpers.H"
#include "Vector2.h"

class Drawable
{
private:
	Vector2 m_pos;
	char m_char;

protected:

public:
	Drawable();

	//-------------------------------------------------------
	//	Function	:	render
	//	Purpose		:	Draws the object using current position and char variables
	//	Parameters  :	none
	//	Returns		:	void
	//-------------------------------------------------------
	void render();

	//-------------------------------------------------------
	//	Function	:	derender
	//	Purpose		:	Derenders the object using a space char and it's current position
	//	Parameters  :	none
	//	Returns		:	void
	//-------------------------------------------------------
	void derender();

	//-------------------------------------------------------
	//	Function	:	getXPos
	//	Purpose		:	Returns the X position of the object
	//	Parameters  :	none
	//	Returns		:	int
	//-------------------------------------------------------
	int getXPos();

	//-------------------------------------------------------
	//	Function	:	setXPos
	//	Purpose		:	Sets the X position of the object by the paramater
	//	Parameters  :	const int& x
	//	Returns		:	void
	//-------------------------------------------------------
	void setXPos( const int x );

	//-------------------------------------------------------
	//	Function	:	getYPos
	//	Purpose		:	Returns the Y position of the object
	//	Parameters  :	none
	//	Returns		:	int
	//-------------------------------------------------------
	int getYPos();

	//-------------------------------------------------------
	//	Function	:	setYPos
	//	Purpose		:	Sets the Y position of the object by the parameter
	//	Parameters  :	const int& y
	//	Returns		:	void
	//-------------------------------------------------------
	void setYPos( const int y );

	//-------------------------------------------------------
	//	Function	:	getPos
	//	Purpose		:	Returns the position of the object by a Vector2
	//	Parameters  :	none
	//	Returns		:	Vector2
	//-------------------------------------------------------
	Vector2& getPos();

	//-------------------------------------------------------
	//	Function	:	setPos
	//	Purpose		:	Sets the position of the object by a Vector2 paramater
	//	Parameters  :	const Vector2& position
	//	Returns		:	void
	//-------------------------------------------------------
	void setPos( const Vector2& position );

	//-------------------------------------------------------
	//	Function	:	setPosByInt
	//	Purpose		:	Sets the position of the object by int paramaters,
	//					Useful when there isn't an existing Vector2 to reference
	//	Parameters  :	const int& x, const int& y
	//	Returns		:	void
	//-------------------------------------------------------
	void setPosByInt( const int x, const int y);

	//-------------------------------------------------------
	//	Function	:	setChar
	//	Purpose		:	Sets the char variable of the object which is what is displayed when using render()
	//	Parameters  :	const char& character
	//	Returns		:	void
	//-------------------------------------------------------
	void setChar( const char character );
};

#endif // End of '#ifndef DRAWABLE_H'
